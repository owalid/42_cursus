<?php
include('auth.php');
session_start();
if ($_GET['login'] !== "" && $_GET['passwd'] !== "" &&  $_GET['submit'] === 'OK')
{
    $login = $_GET['login'];
    $paswd = $_GET['passwd'];
    if (auth($login, $passwd))
    {
        $_SESSION['loggued_on_user'] = $login;
        ?>
        <iframe src="chat.php" 
            width="550px" 
            height="550px">
        </iframe>
        <iframe src="speak.php" 
            width="50px"
            height="50px">
        </iframe>
<?php 
    }
    else
    {
        $_SESSION['loggued_on_user'] = '';
        echo "Error\n";
    }
}
else
    echo "Error\n";