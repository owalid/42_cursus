#!/usr/bin/php
<?php
while (1)
{
    echo 'Entrez un nombre: ';
    $f = fopen( 'php://stdin', 'r' );
    $stdin = trim(fgets(STDIN));
    if ($stdin == NULL)
    {
        echo "\n";
        break;
    }
    $num = substr($stdin, -1);
    if (is_numeric($stdin))
    {
        if ($num % 2 == 0)
            echo 'Le chiffre ' . $stdin . " est Pair\n";
        else
            echo 'Le chiffre ' . $stdin . " est Impair\n";
    }
    else
        echo '\'' . $stdin . '\'' . " n'est pas un chiffre\n";
}