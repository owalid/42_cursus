<?php
$file = '../private/passwd';
if ($_POST["login"] !== "" && $_POST["passwd"] !== "" && $_POST['submit'] == 'OK')
{
    $hash_pwd = hash("SHA512", $_POST['passwd']);
    $login = $_POST['login'];
    if (!file_exists('../private'))
        mkdir('../private');
    if (!file_exists($file))
        file_put_contents($file, '');
    $raw_file = unserialize(file_get_contents($file));
    if ($raw_file)
    {
        foreach ($raw_file as $key => $value)
        {
            if ($value["login"] === $login)
            {
                echo "ERROR\n";
                return;
            }
        }
    }
    $tab["login"] = $login;
    $tab["passwd"] = $hash_pwd;
    $raw_file[] = $tab;
    file_put_contents($file, serialize($raw_file));
    echo "OK\n";
}
else
    echo "ERROR\n";