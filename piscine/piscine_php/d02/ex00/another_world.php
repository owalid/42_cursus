#!/usr/bin/php
<?php
if ($argc > 1)
{
	$temp = $argv[1];
	$out = trim(preg_replace('/\s+/S', " ", $temp));
	echo $out."\n";
}
?>
