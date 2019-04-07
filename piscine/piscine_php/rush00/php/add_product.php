<?php
include 'query.php';
if ($_GET['product'] && $_GET['qte'] && $_SESSION['loggued_on_admin'] != NULL)
    approvision_product($_SESSION['loggued_on_admin'], $_GET['product'], $_GET['qte']);
else 
    header('Location: ../html/404.html');