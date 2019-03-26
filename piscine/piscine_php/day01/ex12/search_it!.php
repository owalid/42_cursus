#!/usr/bin/php
<?php
if ($argc == 1)
    exit();
$search = $argv[1];
foreach ($argv as $e)
{
    if ($e != $argv[0] && $e != $search)
    {
        $p = explode(':', $e);
        if ($p[0] === $search)
        {
            echo $p[1] . "\n";
            exit();
        }
    }
}