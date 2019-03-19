#!/usr/bin/php

<?php
foreach ($argv as $a)
{
    $elmts += preg_split("/[\s,]+/", $a);
}
sort($argv);
foreach ($argv as $e) {
    if ($e != $argv[0])
        echo $e . "\n";
}