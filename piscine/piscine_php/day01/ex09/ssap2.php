#!/usr/bin/php
<?php

if ($argc == 1) 
    exit();
$new_char = array();
$new_number = array();
$new_other = array();
$finish = array();
foreach ($argv as $e) 
{
    if ($e != $argv[0]) 
    {
        $split = preg_split("/[\s]+/", trim($e));
        foreach ($split as $s)
        {
            if (is_numeric(substr($s, 0, 1)))
            {
                array_push($new_number, $s);
            }
            else if (ctype_alpha(substr($s, 0, 1)))
                array_push($new_char, $s);
            else 
                array_push($new_other, $s);
        }
    }
}
usort($new_char, "strcasecmp");
usort($new_number, "strcasecmp");
usort($new_other, "strcasecmp");
$finish = array_merge($finish, $new_char, $new_number, $new_other);
foreach ($finish as $n)
    echo $n . "\n";