<?php
$action = $_GET['action'];
$name = $_GET['name'];
$value = $_GET['value'];
$cookie = $_COOKIE[$name];
if ($action == 'set' && isset($name) && isset($value))
    setcookie($name, $value);
else if ($action == 'del' && isset($name) && isset($value))
    setcookie($name, '', -1);
else if ($action == 'get')
    echo $cookie . "\n";