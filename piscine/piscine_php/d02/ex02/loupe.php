#!/usr/bin/php
<?php
if ($argc > 1)
{
	$file = file_get_contents("$argv[1]");
	$file = preg_replace('/<a .+?<\/a>/sei', 'strtoupper("$0")', $file);
	$file = preg_replace('/<.+?>/sei', 'strtolower("$0")', $file);
	$file = preg_replace('/(?<=title=["\'])[^"^\']+/sei', 'strtoupper("$0")', $file);
	echo($file);
}
?>
