<?php

include 'query.php';
session_start();
if ($_POST['submit'] == 'Change Password')
{
	if (connection($_SESSION['loggued_on_user'], $_POST['oldpw']) === TRUE)
	{
		update_mdp($_SESSION['loggued_on_user'], $_POST['oldpw'], $_POST['newpw']);
		header('Location: ../html/choice.php');
	}
	else
		header('Location: ../html/changepasswd.html');
}
else
{
	echo "ERROR\n";
}
?>
