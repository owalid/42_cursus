<?php
$file = '../img/42.png';
if ($_SERVER['PHP_AUTH_USER'] === "zaz" && $_SERVER["PHP_AUTH_PW"] === "jaimelespetitsponeys")
{?>
<html><body>
    Bonjour Zaz<br />
    <img src="data:image/png;base64,<?=base64_encode(file_get_contents("../img/42.png")) ?>">
</body></html>
<?php 
}
else
{
    header('WWW-Authenticate: Basic realm="Espace membre"');
    header('HTTP/1.1 401 Unauthorized');
    echo $_SERVER['server'];
    ?>
<html><body>Cette zone est accessible uniquement aux membres du site</body></html><?php echo "\n";
}
?>