<?php
function auth($login, $passwd)
{
    $file = unserialize(file_get_contents('../private/passwd'));
    if ($file)
    {
        foreach ($file as $key => $value)
        {
            if ($value['login'] === $login && $value['passwd'] === hash("SHA512", $passwd))
                return (true);
        }
    }
    return (false);
}