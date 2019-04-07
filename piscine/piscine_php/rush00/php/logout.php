<?php
session_start();
unset($_SESSION['loggued_on_user']);
unset($_SESSION['panier']);
session_unset();
session_destroy();
header('Location: checkindex.php');
?>
