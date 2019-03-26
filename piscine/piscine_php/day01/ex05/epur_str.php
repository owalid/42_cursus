#!/usr/bin/php
<?php
if ($argc == 1)
    exit();
$elmts = preg_split("/[\s]+/", trim($argv[1]));
foreach ($elmts as $e) {
    echo $e;
    if ($e != end($elmts) && $e != $elmts[0])
        echo ' ';
    if ($e == end($elmts))
        echo "\n";
}