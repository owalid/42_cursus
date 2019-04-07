#!/usr/bin/php
<?php
include ('php/bd.php');

$conn = mysqli_connect("127.0.0.1", "root", "123456");
if (!$conn)
    die("Une erreur c'est produite\n");
$sql = "DROP DATABASE rush00";
if (mysqli_query($conn, $sql))
    echo "BD delete avec succés 👍 \n";
else
    echo "Une erreur c'est produite\n";
mysqli_close($conn);