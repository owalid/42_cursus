<?php
include 'query.php';

session_start();
if ($_GET['label'] != NULL && $_GET['price'] != NULL && $_GET['path'] != NULL && $_GET['description'] != NULL && $_GET['id_product'] != NULL && $_GET['submit'] === "update"  && $_SESSION['loggued_on_admin'] != NULL)
{
    if (set_product($_GET['id_product'], $_GET['label'], $_GET['price'], $_GET['description'], $_GET['path']) === TRUE)
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
<form action="update_product.php" method="GET">
    Label: <input type="text" name="label" value="<?= $produit['label']?>"> <br />
    Price: <input type="text" name="price" value="<?= $produit['price']?>"> <br />
    Path img: <input type="text" name="path" value="<?= $produit['path_img']?>"> <br />
    Description: <input type="text" name="description" value="<?= $produit['description']?>"> <br />
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