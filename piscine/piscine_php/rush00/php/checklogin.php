<?php
session_start();
if ($_SESSION['loggued_on_user'] != "")
	header('Location: ../html/choice.php');
else
	header('Location: ../index.php');
?>
