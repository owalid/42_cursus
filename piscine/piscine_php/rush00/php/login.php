<?php

include 'query.php';
session_start();
if ($_POST['login'] != '' && $_POST['passwd'] != '')
{
	if (connection($_POST['login'], $_POST['passwd']) === TRUE)
	{
		$_SESSION['loggued_on_user'] = $_POST['login'];
		header('Location: ../html/choice.php');
	}
	else
		header('Location: ../html/badpwd.html');
}
else
{
	$_SESSION['loggued_on_user'] = "";
	echo "ERROR\n";
}
?>