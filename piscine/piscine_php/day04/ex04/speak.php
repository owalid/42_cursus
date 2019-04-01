<?php
$file = '../private/';

if ($_GET['msg'] !== NULL && $_SESSION['loggued_on_user'] !== NULL)
{
    $msg = $_GET['msg'];
    if (!file_exist('../private'))
        mkdir('../private');
    if (!file_exists($file))
        file_put_contents($file, '');
    $date = date('Y/m/d H:i:s');
    $tab = array(serialize($login, $date, $msg));
    file_put_contents($file, $tab, FILE_APPEND | LOCK_EX);
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Speak</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script langage="javascript">top.frames['chat'].location ='chat.php';</script>
</head>
<body>
    <form action="speak.php" method="POST">
        <input type="text" name="msg">
        <input type="submit" name="submit" value="OK">
    </form>
</body>
</html>