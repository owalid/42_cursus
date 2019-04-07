<?php
include('query.php');
session_start();
if ($_SESSION['loggued_on_user'] != NULL)
{
        $id = get_id_login($_SESSION['loggued_on_user'], 1);
        $my_commands = get_all_command($id);
        ?>
        <h1 style="text-align:center; font-size:3em; color:white;"><a id="name-site" href="../php/checklogin.php">ChaudSet</a></h1>
    <h2>Mes commandes</h2>
    <table>
        <thead>
            <tr>
                <th>Article</th>
                <th>Quantité</th>
                <th>Prix</th>
            </tr>
        </thead>
        <tbody>
<?php
    if ($my_commands !== NULL)
    {
        foreach($my_commands as $command)
        {
?>
        <tr>
            <td><?= $command['label']?></td>
            <td>1</td>
            <td><?= $command['price']?>$</td>
        </tr>
    </tbody>
    </table>
<?php
    }
}
else
{
?>
    <tr>
        <td>Aucune commande</td>
    </tr>
</tbody>
</table>
<?php
}
}
else
    echo "<p>Veuillez vous connectez</p>";
?>
