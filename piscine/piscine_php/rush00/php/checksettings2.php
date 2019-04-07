<?php
session_start();
if ($_POST['submit'] == 'Change Password')
{
	if ($_SESSION['loggued_on_user'] != "")
		header('Location: ../html/changepasswd.html');
	else
		header('Location: ../html/login.html');
}
if ($_POST['submit'] == 'Update User')
{
	if ($_SESSION['loggued_on_user'] != "")
		header('Location: ../html/checkpasswd.html');
	else
		header('Location: ../html/login.html');
}
if ($_POST['submit'] == 'Delete User')
{
	if ($_SESSION['loggued_on_user'] != "")
		header('Location: ../html/deluser.html');
	else
		header('Location: ../html/login.html');
}
?>
