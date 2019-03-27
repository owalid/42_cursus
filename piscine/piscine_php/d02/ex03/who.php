#!/usr/bin/php
<?php
	$fp = fopen("/var/run/utmpx", "r");
	date_default_timezone_set('Europe/Paris');
	while ($file = fread($fp, 628))
	{
		$elem = unpack("a256a/a4b/a32c/id/ie/I2f/a256g/i16h", $file);
		if($elem['e'] == 7)
		{
			echo str_pad(substr(trim($elem['a']), 0, 8), 8, " ")." ";
			echo str_pad(substr(trim($elem['c']), 0, 8), 8, " ")." ";
			echo date("M", $elem["f1"]);
			echo str_pad(date("j", $elem["f1"]), 3, " ", STR_PAD_LEFT)." ".date("H:i", $elem["f1"]);
			echo "\n";
		}
	}
?>