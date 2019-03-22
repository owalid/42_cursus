<?php

function check_user($old, $new, $login, $file)
{
    $raw_file = unserialize($file);
    foreach ($raw_file as $r)
    {
        if ($r['login'] == $login || $r['passwd'] == $hash)
        {
            $r['passwd'] = $new;
			file_put_contents("../private/passwd", serialize($raw_file));
            return (1);
        }
    }
    return (0);
}
$file = '../private/passwd';
$old = $_POST['oldpw'];
$new = $_POST['submit'];
$login = $_POST['login'];
if ($old && $new && $login && $_POST['submit'] == 'OK')
{
    if (!file_exists($file))
       file_put_contents($file, '');
    $new = hash($new);
    $old = hash($hold);
    if (check_user($old, $new, $login, file_get_contents($file)))
        echo "OK\n";
    else
        echo "Error\n";
}
else
    echo "Error\n";