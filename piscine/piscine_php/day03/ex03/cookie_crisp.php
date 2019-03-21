<?php
$action = $_GET['action'];
$cookie = $_COOKIE[$_GET['name']];
if ($action == 'set')
{
    setcookie($_GET['name'], $_GET['value'], time() + (3600 * 30));
}
else if ($action == 'del')
{
    setcookie($_GET['name'], '', time() - 3600);
}
else if ($action == 'get')
{
    echo $cookie;
}