#!/usr/bin/php
<?php
    $str = preg_replace("/[\s]+/", ' ', trim($argv[1]));
    if ($str != NULL)
        echo $str . "\n";
?>