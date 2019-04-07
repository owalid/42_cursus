<?php
include('query.php');
if ($_POST["login"] != "" || $_POST["passwd"] != "")
{
	if ($_POST["submit"] == "Sign Up")
	{
		inscription($_POST['login'], $_POST['firstname'], $_POST['lastname'], $_POST['passwd'], $_POST['email'], $_POST['phone'], $_POST['birth']);
		header('Location: checkindex.php');
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";

?>
