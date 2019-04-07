<?php
session_start();
?>
<h1 style="text-align:center; font-size:3em; color:white;"><a id="name-site" href="../php/checklogin.php">ChaudSet</a></h1>
<h2>Votre panier</h2>
<table>
    <thead>
        <tr>
            <th>Nom</th>
            <th>Quantité</th>
            <th>Prix unitaire</th>
            <th>Total HT</th>
        </tr>
    </thead>
    <tbody>
<?php
if ($_SESSION['panier'] != NULL)
{
    $total_price = 0;
    $produits = $_SESSION['panier'];
    foreach($produits as $pr)
        {
            ?>
    <tr>
        <td><?= $pr['label']?></td>
        <td><?= $pr['qte']?></td>
        <td>
            <a href="delete_panier.php?id_prod=<?= $pr['id_prod']?>">Delete</a>
        </td>
        <td><?= $pr['price']?>$</td>
        <?php $total_price += $pr['price']?>
    </tr>
        <?php
        }?>
    <?= '<h1>' . 'Total:' . $total_price . '$</h1>'?>
        </tbody>
    </table>
    <a href="command.php">Commander</a>
<?php
}
else
{?>
        <tr>
            <td>Aucun article dans votre panier</td>
        </tr>
    </tbody>
</table>
    <?php }?>
