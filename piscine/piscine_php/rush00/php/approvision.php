<?php
include 'query.php';

session_start();
if ($_GET['id_product'] != NULL && $_GET['qte'] != NULL && $_GET['submit'] === "update"  && $_SESSION['loggued_on_admin'] != NULL)
{
    if (approvision_product($_SESSION['loggued_on_admin'], $_GET['id_product'], $_GET['qte']) === TRUE)
    {
        echo "<script type='text/javascript'>
        alert('Produit modifié avec succés 🙂');
        window.location='dashboard_admin.php'</script>";
    }
    else
        echo "<script type='text/javascript'>
        alert('Une erreure c'est produite');
        window.location='dashboard_admin.php'</script>";
}
else if ($_GET['id_product'] != NULL && $_SESSION['loggued_on_admin'] != NULL && $_GET['form'] === "yes")
{
    $produit = get_one_product($_GET['id_product']);
    ?>
<form action="approvision.php" method="GET">
    
    Quantité: <input type="text" name="qte" value="<?= $produit['qte']?>"> <br />
                <input type="text" name="id_product" hidden value="<?=$_GET['id_product']?>">
    <input type="submit" name="submit" value="update">
</form>
<?php
}
else
{
?>
    <p>Le produit n'existe pas </p>
<?php
}
?>