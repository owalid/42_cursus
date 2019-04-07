<?php

include('query.php');
session_start();
if ($_SESSION['loggued_on_user'] != '')
{
	if ($_POST['submit'] == 'Update User')
	{
		update_user($_SESSION['loggued_on_user'], $_POST['login'], $_POST['firstname'], $_POST['lastname'], $_POST['email'], $_POST['phone'], $_POST['birth']);
		$_SESSION['loggued_on_user'] = $_POST['login'];
		header('Location: checklogin.php');
	}
}
else 
	header('Location: ../html/login.html');

?>
