<?php
$file = '../private/passwd';
if ($_POST["login"] !== "" && $_POST['newpw'] && $_POST['oldpw'] !== "" && $_POST['submit'] == 'OK')
{
    $old = hash("SHA512", $_POST['oldpw']);
    $new = hash("SHA512", $_POST['newpw']);
    $login = $_POST["login"];
    if (!file_exists($file))
    {
        echo "ERROR\n";
        return;
    }
    $raw_file = unserialize(file_get_contents($file));
    if ($raw_file)
    {
        foreach ($raw_file as $key => $value)
        {
            if ($value['login'] === $login && $value['passwd'] === $old)
            {
                $raw_file[$key]['passwd'] = $new;
                file_put_contents($file, serialize($raw_file));
                echo "OK\n";
                return;
            }
        }
    }
    echo "ERROR\n";
}
else
    echo "ERROR\n";