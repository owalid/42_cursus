#!/usr/bin/php
<?php
if ($argc == 1)
{
    echo "Incorrect Parameters\n";
    exit();
}
$split = preg_replace("/[\s]+/", '', trim($argv[1]));
preg_match("/^[0-9]{1,}/", $split, $first_number);
preg_match("/\d+$/", $split, $second_number);
$sign = preg_replace("/^[0-9]{1,}/", '', $split);
$sign = preg_replace("/\d+$/", '', $sign);
$first_number = $first_number[0];
$second_number = $second_number[0];
if (!is_numeric($first_number) || !is_numeric($second_number))
{
    echo "Syntax Error\n";
    exit();
}
if ($sign == "+")
    echo $first_number + $second_number;
else if ($sign == "-")
    echo $first_number - $second_number;
else if ($sign == "*")
    echo $first_number * $second_number;
else if ($sign == "%")
{
    if ($second_number == 0)
        exit();
    echo $first_number % $second_number;
}
else if ($sign == "/")
{
    if ($second_number == 0)
        exit();
    echo $first_number / $second_number;
}
else
{
    echo "Syntax Error\n";
    exit();
}
echo "\n";
//3*5