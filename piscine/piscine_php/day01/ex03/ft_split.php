<?php

function ft_split($arv)
{
    $separator = ' ';
    $elmts = explode(' ', $arv);
    sort($elmts);
    print_r($elmts);
}