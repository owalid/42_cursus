<?php
$file = '../private/passwd';

function check_user($hash, $login, $file)
{
    $raw_file = unserialize($file);
    foreach ($raw_file as $r)
    {
        if ($r == $login || $r == $hash)
            return (0)
    }
    return (1);
}
if ($_POST['login'] && $_POST['passwd'])
{
    if (!file_exist('../private'))
        mkdir('../private');
    if (!file_exists($file))
       file_put_contents($file, '');
    $hash_pwd = $_POST['passwd'];
    $login = $_POST['login'];
    if (check_user($hash_pwd, $login, file_get_contents($file)))
    {
        $tab = array(serialize($login, $hash_pwd));
        file_put_contents($file, $tab);
        echo "OK\n"
    } 
    else
        echo "ERROR\n"
}
else
    echo "ERROR\n"