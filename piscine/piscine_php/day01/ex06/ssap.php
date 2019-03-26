#!/usr/bin/php
<?php
if ($argc == 1)
    exit();
$new = array();
foreach ($argv as $e) {
    if ($e != $argv[0])
    {
        $split = preg_split("/[\s]+/", trim($e));
        $new = array_merge($new, $split);
    }
}
sort($new);
foreach ($new as $n)
    echo $n . "\n";