<?php

function ft_split($arv)
{
    $elmts = preg_split("/[\s]+/", trim($arv));
    sort($elmts);
    return($elmts);
}