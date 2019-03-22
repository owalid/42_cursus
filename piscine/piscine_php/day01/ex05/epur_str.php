#!/usr/bin/php
<?php
$elmt = $argv[1];
$elmts = preg_split("/[\s,]+/", $elmt);
foreach ($elmts as $e) {
    echo $e;
    if ($e != end($elmts))
        echo ' ';
}
echo "\n";