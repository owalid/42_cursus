<?php
include('query.php');
session_start();
if (isset($_GET['panier']))
{
    $produit = get_one_product($_GET['panier']);
    if ($produit != NULL)
    {
        if ($_SESSION['panier'] === NULL)
            $_SESSION['panier'] = array();
        $_SESSION['panier'][$_GET['panier']] = $produit;
        echo "<script type='text/javascript'>
        alert('Article ajouteé au panier avec succès 🙂');
        window.location='page_produit.php?produit=" . $produit['id_prod'] 
        . "'</script>";
    }
}
else
    header('../html/404.html');