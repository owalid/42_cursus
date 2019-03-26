#!/usr/bin/php
<?php
if ($argc == 1)
    exit();
$elmts = preg_split("/[\s]+/", trim($argv[1]));
foreach ($elmts as $e)
{
    if ($e != $elmts[0])
        echo "$e"." ";
}
echo "$elmts[0]"."\n";