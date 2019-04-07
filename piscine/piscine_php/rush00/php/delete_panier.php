<?php
session_start();
if ($_GET['id_prod'] != NULL)
{
    unset($_SESSION['panier']['id_prod']);
    echo "<script type='text/javascript'>
    alert('L\'article a bien ete supprimer du panier');
    window.location='panier.php'</script>";
}
else
{
    echo "<script type='text/javascript'>
    alert('Une erreur c\'est produite lors de la suppression du panier');
    window.location='panier.php'</script>";
}