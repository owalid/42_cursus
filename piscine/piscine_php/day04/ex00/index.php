<?php
session_start();
if ($_GET['login'] && $_GET['passwd'])
{
    $_SESSION['login'] = $_GET['login'];
    $_SESSION['passwd'] = $_GET['passwd'];
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>index.php</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <form action="index.php" method="GET">
        <input type="text" name="login">
        <input type="password" name="passwd">
        <input type="submit" name="submit" value="OK">
    </form>
</body>
</html>