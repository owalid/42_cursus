#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
    $sortab = $tab;
    $revsortab = $tab;
    sort($sortab);
    rsort($revsortab);
    if (!(array_diff_assoc($tab, $sortab) || !(array_diff_assoc($tab, $revsortab))))
        return (1);
    return (0);
}
?>