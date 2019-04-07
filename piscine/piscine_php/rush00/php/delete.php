<?php

include 'query.php';
session_start();
if ($_POST['submit'] == 'Delete User')
{
	if (connection($_SESSION['loggued_on_user'], $_POST['passwd']) === TRUE)
	{
		delete_user($_SESSION['loggued_on_user']);
		$_SESSION['loggued_on_user'] = '';
		header('Location: ../index.php');
	}
	else
		header('Location: ../html/deluser.html');
}
else
{
	echo "ERROR\n";
}
?>
