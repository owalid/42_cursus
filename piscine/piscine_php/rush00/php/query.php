<?php
include ('bd.php');

/* ////////////////////////////////// CRUD USER ///////////////////////////////////////////*/
function inscription($login, $firstname, $lastname, $passwd, $email, $phone, $birth)
{
    $conn = co_bd();
    $passwd = hash("SHA512", mysqli_real_escape_string($conn, $passwd));
    $login = mysqli_real_escape_string($conn, $login);
    $firstname = mysqli_real_escape_string($conn, $firstname);
    $lastname = mysqli_real_escape_string($conn, $lastname);
    $email = mysqli_real_escape_string($conn, $email);
    $phone = mysqli_real_escape_string($conn, $phone);
    $birth = mysqli_real_escape_string($conn, $birth);
    $sql = "INSERT INTO users (login, firstname, lastname, passwd, email, phone, birth)
                VALUES ('$login', '$firstname', '$lastname', '$passwd', '$email', '$phone', '$birth')";
    if (mysqli_query($conn, $sql) === TRUE)
        echo "bienvenu chez nous " . $login . "\n";
    mysqli_close($conn);
}

function connection($login, $passwd)
{
    $conn = co_bd();
    $passwd = hash("SHA512", mysqli_real_escape_string($conn, $passwd));
    $sql = "SELECT login
            FROM users 
            WHERE login = '$login'
            AND passwd = '$passwd'";
    $return = mysqli_query($conn, $sql);
    $value = mysqli_fetch_array($return, MYSQLI_ASSOC);
    mysqli_close($conn);
    if ($value !== NULL)
        return TRUE;
    return FALSE;
}

function delete_user($login)
{
    $conn = co_bd();
    $sql = "DELETE FROM users 
            WHERE login = '$login'";
    if (mysqli_query($conn, $sql) === TRUE)
        echo '<script>alert("l\'\utilisateur' . $login . 'a ete supp avec succes");</script>';
    mysqli_close($conn);
}

function get_id_login($login, $option)
{
    $conn = co_bd();
    $sql = "SELECT id_usr
            FROM USERS
            WHERE login = '$login'";
    $returnvalue = mysqli_query($conn, $sql);
    $row = mysqli_fetch_array($returnvalue, MYSQLI_ASSOC);
    $num = intval($row['id_usr']);
    mysqli_close($conn);
    if ($num !== NULL)
    {
        if ($option === 1)
            return ($num);
        else
            return true;
    }
    else
        return false;
}



function get_all_users()
{
    $conn = co_bd();
    $sql = "SELECT *
            FROM users";
    $result_q = mysqli_query($conn, $sql);
    while ($row = mysqli_fetch_array($result_q, MYSQLI_ASSOC)) 
        $rows[] = $row;
    mysqli_close($conn);
    return ($rows);
}

function update_user($old_login, $login, $firstname, $lastname, $passwd, $email, $phone, $birth)
{
    $conn = co_bd();
    $login = mysqli_real_escape_string($conn, $login);
    $old_login = mysqli_real_escape_string($conn, $old_login);
    $firstname = mysqli_real_escape_string($conn, $firstname);
    $lastname = mysqli_real_escape_string($conn, $lastname);
    $email = mysqli_real_escape_string($conn, $email);
    $phone = mysqli_real_escape_string($conn, $phone);
    $id_login = get_id_login($old_login, 1);
    $sql = "UPDATE users 
            SET login = '$login',
                firstname = '$firstname',
                lastname = '$lastname',
                email = '$email',
                phone = '$phone',
                birth = '$birth'
            WHERE id_usr = '$id_login'";
    mysqli_query($conn, $sql);
    mysqli_close($conn);
}

function update_mdp($login, $old_passwd, $new_passwd)
{
    $co = co_bd();
    $old = hash("SHA512", mysqli_real_escape_string($co, $old_passwd));
    $new = hash("SHA512", mysqli_real_escape_string($co, $new_passwd));
    $sql = "UPDATE users
            SET passwd = '$new'
            WHERE passwd = '$old'
            AND login = '$login'";
    $return = mysqli_query($co, $sql);
    mysqli_close($conn);
    return ($return);
}

/* ///////////////////////////////// ADM ///////////////////////////// */

function is_adm($login, $passwd)
{
    $conn = co_bd();
    $login = mysqli_real_escape_string($conn, $login);
    $passwd = hash("SHA512", mysqli_real_escape_string($conn, $passwd));
    $sql = "SELECT * 
            FROM admin 
            WHERE login = '$login'
            AND passwd = '$passwd'";
    $return = mysqli_query($conn, $sql);
    $value = mysqli_fetch_array($return, MYSQLI_ASSOC);
    mysqli_close($conn);
    if ($value !== NULL)
        return TRUE;
    return FALSE;
}

function get_id_admin($login)
{
    $conn = co_bd();
    $sql = "SELECT id_usr
            FROM Admin
            WHERE login = '$login'";
    $returnvalue = mysqli_query($conn, $sql);
    $row = mysqli_fetch_array($returnvalue, MYSQLI_ASSOC);
    $num = intval($row['id_usr']);
    mysqli_close($conn);
    if ($num !== NULL)
        return ($num);
    return NULL;
}


/* /////////////////////////////  CRUD product and categorie ////////////////////////*/
function set_product($id_prod, $label, $price, $description, $path_img)
{
    $conn = co_bd();
    $label = mysqli_real_escape_string($conn, $label);
    $price = mysqli_real_escape_string($conn, $price);
    $description = mysqli_real_escape_string($conn, $description);
    $path_img = mysqli_real_escape_string($conn, $path_img);
    $sql = "UPDATE produit
            SET label = '$label',
                price = '$price',
                description = '$description',
                path_img = '$path_img'
            WHERE id_prod = '$id_prod'";
    if (mysqli_query($conn, $sql) === TRUE)
        return true;
    return false;
}

function approvision_product($login_admin, $id_product, $qte_raj)
{
    $conn = co_bd();
    $id_adm = get_id_admin($login_admin);
    $sql = "UPDATE produit
            SET pieces = '$qte_raj'
            WHERE id_prod = '$id_product'";

    $sql2 = "INSERT INTO approvision (id_prod, id_usr, qty_reassort)
                VALUE ('$id_product', '$id_adm', '$qte_raj')";
    if (mysqli_query($conn, $sql) === true)
    {
        if (mysqli_query($conn, $sql2) === true)
        {
            mysqli_close($conn);
            return TRUE;
        }
    }
    return FALSE;
}


function get_all_categories()
{
    $conn = co_bd();
    $sql = "SELECT *
            FROM categorie";
    $result_q = mysqli_query($conn, $sql);
    while ($row = mysqli_fetch_array($result_q, MYSQLI_ASSOC)) 
        $rows[] = $row;
    mysqli_close($conn);
    return ($rows);
}

function all_products()
{
    $conn = co_bd();
    $sql = "SELECT *
            FROM produit";
    $result_q = mysqli_query($conn, $sql);
    while ($row = mysqli_fetch_array($result_q, MYSQLI_ASSOC)) 
        $rows[] = $row;
    mysqli_close($conn);
    return ($rows);
}

function get_all_products($id_cat)
{
    $id_cat = intval($id_cat);
    $conn = co_bd();
    $sql = "SELECT *
            FROM produit
            WHERE produit.id_cat = '$id_cat'";
    $result_q = mysqli_query($conn, $sql);
    while ($row = mysqli_fetch_array($result_q, MYSQLI_ASSOC))
        $rows[] = $row;
    mysqli_close($conn);
    return ($rows);
}

function get_one_product($id_prod)
{
    $id_prod = intval($id_prod);
    $conn = co_bd();
    $sql = "SELECT *
            FROM produit
            WHERE produit.id_prod = '$id_prod'";
    $result_q = mysqli_query($conn, $sql);
    $row = mysqli_fetch_array($result_q, MYSQLI_ASSOC);
    mysqli_close($conn);
    return ($row);
}

/*//////////////////////////// Command //////////////////////// */
function get_cmd($id_usr)
{
    $id_usr = intval($id_usr);
    $conn = co_bd();
    $sql = "SELECT *
            FROM commande produit
            WHERE commande.id_usr = '$id_usr'";
    $result_q = mysqli_query($conn, $sql);
    $result = mysqli_fetch_array($result_q, MYSQLI_NUM);
    mysqli_close($conn);
    return ($result);
}


function add_command($panier, $id_usr)
{
    $co = co_bd();
    foreach ($panier as $pan)
    {
        $id_prod = intval($pan['id_prod']);
        $sql .= "INSERT INTO commande (id_usr, id_prod, qty_order)
                VALUES ($id_usr, $id_prod, 1);\n";
    }
    mysqli_multi_query($co, $sql);
    mysql_close($co);
}

function get_all_command($id_usr)
{
    $co = co_bd();
    $sql = "SELECT *
            FROM commande
            WHERE id_usr = '$id_usr'";
    $result_q = mysqli_query($co, $sql);
    while ($result = mysqli_fetch_array($result_q, MYSQLI_ASSOC))
        $results[] = $result;
    foreach ($results as $res)
    {
        $id_prod = $res['id_prod'];
        $sql2 .= "SELECT *
                FROM produit
                WHERE id_prod = $id_prod;";
    }
    mysqli_multi_query($co, $sql2); 
    $result2 = mysqli_store_result($co);
    while ($row = mysqli_fetch_array($result2, MYSQLI_ASSOC))
    $rows[] = $row;
    return ($rows);
}


function all_command()
{
    $co = co_bd();
    $sql = "SELECT *
            FROM commande";
    $result_q = mysqli_query($co, $sql);
    while ($result = mysqli_fetch_array($result_q, MYSQLI_ASSOC))
        $results[] = $result;
    foreach ($results as $res)
    {
        $id_prod = $res['id_prod'];
        $sql2 .= "SELECT *
                FROM produit
                WHERE id_prod = $id_prod;";
    }
    mysqli_multi_query($co, $sql2); 
    $result2 = mysqli_store_result($co);
    while ($row = mysqli_fetch_array($result2, MYSQLI_ASSOC))
        $rows[] = $row;
    array_push($rows, $results);
    return ($rows);
}

function get_login($id)
{
    $co = co_bd();
    $sql = "SELECT login
                FROM USERS
            WHERE id_usr = '$id'";
    $row = mysqli_fetch_array($returnvalue, MYSQLI_ASSOC);
    return ($row['login']);
}