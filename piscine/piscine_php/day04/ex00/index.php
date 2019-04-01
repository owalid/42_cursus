<?php
session_start();
if ($_GET['login'] != NULL && $_GET['passwd'] != NULL && $_GET['submit'] === "OK")
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
    <title>Index</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <form action="index.php" method="GET">
        Identifiant: <input type="text" name="login" value="">
        <br />
        Mot de passe: <input type="password" name="passwd" value="">
        <input type="submit" name="submit" value="OK">
    </form>
</body>
</html>