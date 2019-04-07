<?php
include 'query.php';
session_start();
?>
<h1> Administration </h1>
<h2>Produits</h2>
<?php
if ($_SESSION['loggued_on_admin'] != NULL)
{
    $product = all_products();
    $commands = all_command();
    foreach ($product as $pr) {
        ?>
        <a href="update_product.php?id_product=<?= $pr['id_prod']?>&form=yes"> Modifier <?= $pr['label']?> </a>
        <br />
        <a href="approvision.php?id_product=<?= $pr['id_prod']?>&form=yes"> Approvisionnez</a>
        <br />
        <br />
        <?php
    }
    ?>
    <hr />
    <h2> Commandes </h2>
    <?php
    if ($commands != NULL)
    {

        foreach ($commands as $cmd)
        { 
            ?>
        <p> Commande de: <?= get_login($cmd[0]['id_usr']) ?> </p>
        <p> Quantité : <?= $cmd['qte'] ?> </p>
        <p> Produit: <?= $cmd['label'] ?> </p> 
        <?php
        }
    }
    else
    {
?>
        <p> Pas de commandes </p>
<?php
    }
}
else
    header('Location: ../html/login_adm.html');