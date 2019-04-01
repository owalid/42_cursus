<?php
foreach ($_GET as $g_key => $g_value)
{
    if ($g_value !== "")
        echo $g_key . ':' . ' ' . $g_value . "\n";
}