#!/usr/bin/php

<?php
sort($argv);
foreach ($argv as $e) {
    if ($e != $argv[0])
    {
        $split = preg_split("/[\s,]+/", $e);
        foreach($split as $s)
        {
            echo $s . "\n";
        }
    }
}