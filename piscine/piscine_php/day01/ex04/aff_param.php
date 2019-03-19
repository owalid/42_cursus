#!/usr/bin/php
<?php

//$stdin = print_r($argv);
foreach ($argv as $arg) {
    if ($arg != "./aff_param.php")
        echo $arg . "\n";
}