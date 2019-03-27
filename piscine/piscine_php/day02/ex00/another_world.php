#!/usr/bin/php
<?php
    $str = preg_replace("/[\s]+/", ' ', trim($argv[1]));
    echo $str . "\n";