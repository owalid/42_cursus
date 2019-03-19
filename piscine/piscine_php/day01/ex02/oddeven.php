<?php

echo 'Entrez un nombre:';
$f = fopen( 'php://stdin', 'r' );
$stdin = trim(fgets(STDIN));
if (is_numeric($stdin))
{
    if ($stdin % 2 == 0)
        echo 'Le chiffre ' . $stdin . ' est Pair';
    else
        echo 'Le chiffre ' . $stdin . ' est Impair';
}
else
    echo '\'' . $stdin . '\'' . ' n\'est pas un chiffre';