#!/usr/bin/php
<?php
include ('php/bd.php');

// connection a mysql et crée la table rush00
    $conn = mysqli_connect("127.0.0.1", "root", "123456");
    if (!$conn)
    die("Une erreur c'est produite\n");
    $db_query = "CREATE DATABASE rush00";
    if (mysqli_query($conn, $db_query))
    echo "BD crée avec succés 👍 \n";
    else
    echo "Une erreur c'est produite\n";
    mysqli_close($conn);
    
    // connection a la base crée et crée les tables et insert les values
    $conn = co_bd();
    $passwd = hash("SHA512", '123456');
    $all_query = file_get_contents('create_tab.sql');
    $all_query .= file_get_contents('insert_db.sql');
    $all_query .= "INSERT INTO users (id_usr, login, firstname, lastname, passwd, email, phone, birth)
    VALUES (1, 'owalid', 'othmane', 'ayadi', '$passwd', 'othmane@othmane.fr', '060606060', '12/06/05');\n";
    $all_query .= "INSERT INTO admin (id_usr, login, firstname, lastname, passwd, email, phone, birth)
    VALUES (1, 'owalid', 'othmane', 'ayadi', '$passwd', 'othmane@othmane.fr', '060606060', '12/06/05');";
    if (mysqli_multi_query($conn, $all_query))
        echo "tables crée avec succés 👍 \n";
    else
        echo "Une erreur c'est produite\n";

// insert root user
    mysqli_close($conn);
?>