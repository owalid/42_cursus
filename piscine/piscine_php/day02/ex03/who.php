#!/usr/bin/php
<?php
	$fp = fopen("/var/run/utmpx", "r");
	date_default_timezone_set('Europe/Paris');
	$arr = [];
	$i = 0;
	$big = 0;
	while ($file = fread($fp, 628))
	{
		$elem = unpack("a256a/a4b/a32c/id/ie/I2f/a256g/i16h", $file);
		$name =  preg_replace('/[\x00-\x1F\x80-\xFF]/', '', $elem['a']);
		$console = $elem['c'];
		$time = $elem['f1'];
		if ($big < strlen($name))
			$big = strlen($name);
		if ($elem['e'] == 7)
			$arr[$i] = $console . ":" . $name . ":" . $time;
		$i++;
	}
	sort($arr);
    foreach ($arr as $a) {
        $elmt = explode(":", $a);
        if (strlen($elmt[1]) == $big) {
            echo str_pad(substr(trim($elmt[1]), 0, $big), 1, " ") . " ";
        } else {
            echo str_pad(substr(trim($elmt[1]), 0, 10), $big, " ") . " ";
        }
        echo str_pad(substr(trim($elmt[0]), 0, 10), 8, " ") . " ";
        echo date("M", $elmt[2]);
        echo str_pad(date("j", $elmt[2]), 3, " ", STR_PAD_LEFT) . " " . date("H:i", $elmt[2]);
        echo "\n";
    }
?>