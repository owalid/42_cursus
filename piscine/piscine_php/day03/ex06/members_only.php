<?php
$file = '../img/42.png';
if ($_SERVER['PHP_AUTH_USER'] == 'zaz' && $_SERVER["PHP_AUTH_PW"] == 'jaimelespetitsponeys')
{
    echo '<html><body>Bonjour Zaz<br /><img src=\"../img/42.png\" '. base64_encode($file).'></body></html>';
}
else
{
    echo $_SERVER['server'];
    ?>
<html><body>Cette zone est accessible uniquement aux membres du site</body></html>
    <?php
}