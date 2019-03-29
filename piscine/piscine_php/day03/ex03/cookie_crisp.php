<?php
$action = $_GET['action'];
$name = $_GET['name'];
$value = $_GET['value'];
$cookie = $_COOKIE[$name];
if ($action == 'set' && $name !== "" && $value !== "")
    setcookie($name, $value);
else if ($action == 'del' && $name !== "")
    setcookie($name, '', -1);
else if ($action == 'get' && $cookie !== "")
    echo $cookie . "\n";