<?php
include 'query.php';
session_start();
if ($_SESSION['panier'] != NULL && $_SESSION['loggued_on_user'] != NULL)
{
    $total_price = 0;
    $produits = $_SESSION['panier'];
    $id = get_id_login($_SESSION['loggued_on_user'], 1);
    add_command($produits, $id);
    unset($_SESSION['panier']);
    echo "<script type='text/javascript'>
    alert('Merci " .  $_SESSION['loggued_on_user'] . " pour votre commande à ete pris en compte et seras traité dans les meilleurs delais 🤙');
    window.location='my_commands.php'</script>";
}
else
{
    echo "<script type='text/javascript'>
    alert('Merci de vous connectez avant de passer votre commande 😅');
    window.location='../html/login.html'</script>";
}