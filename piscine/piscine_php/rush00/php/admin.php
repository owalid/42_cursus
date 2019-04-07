<?php
include 'query.php';
session_start();
if ($_POST['login'] != '' && $_POST['passwd'] != '')
{
	if (is_adm($_POST['login'], $_POST['passwd']) === TRUE)
	{	
		$_SESSION['loggued_on_admin'] = $_POST['login'];
		header('Location: ../php/dashboard_admin.php');
	}
	else
		header('Location: ../html/login_adm.html');
}
else
{
	$_SESSION['loggued_on_admin'] = "";
	echo "ERROR\n";
}