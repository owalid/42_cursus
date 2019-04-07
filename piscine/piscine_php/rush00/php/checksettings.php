<?php
session_start();
if ($_SESSION['loggued_on_user'] != "")
	header('Location: ../html/settings.html');
else
	header('Location: ../html/login.html');
?>
