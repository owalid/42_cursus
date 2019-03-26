#!/usr/bin/php
<?php
if ($argc == 1 || $argc > 5)
{
    echo "Incorrect Parameters\n";
    exit();
}
$new = array();
foreach ($argv as $e)
{
    if ($e != $argv[0])
    {
        $split = preg_split("/[\s]+/", trim($e));
        $new = array_merge($new, $split);
    }
}
print_r($new);
if (!is_numeric($new[0]) || !is_numeric($new[2]))
    exit();
if ($new[1] == "+")
    echo $new[0] + $new[2];
else if ($new[1] == "-")
    echo $new[0] - $new[2];
else if ($new[1] == "*")
    echo $new[0] * $new[2];
else if ($new[1] == "%")
{
    if ($new[2] == 0)
        exit();
    echo $new[0] % $new[2];
}
else if ($new[1] == "/")
{
    if ($new[2] == 0)
        exit();
    echo $new[0] / $new[2];
}
else
    exit();
echo "\n";