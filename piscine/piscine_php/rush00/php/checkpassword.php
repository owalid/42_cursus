<?php

include 'query.php';
session_start();
if ($_SESSION['loggued_on_user'] != '')
{
	if (connection($_SESSION['loggued_on_user'], $_POST['passwd']) === TRUE)
		header('Location: ../html/modif.html');
	else
		header('Location: ../html/checkpasswd.html');
}
else
{
	$_SESSION['loggued_on_user'] = "";
	header("../html/login.html");
}
?>
