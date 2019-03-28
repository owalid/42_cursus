#!/usr/bin/php
<?php
function get_name_file($em)
{
	$tmp = strrev($em);
	$em = substr($tmp, 0, strpos($tmp, "/"));
	return (strrev($em));
}

function get_img($img, $fullpath) {
	$ch = curl_init ($img);
	curl_setopt_array($ch, [CURLOPT_HEADER => 0, CURLOPT_RETURNTRANSFER => 1, CURLOPT_BINARYTRANSFER => 1]);
	$rawdata = curl_exec($ch);
	curl_close ($ch);
	if (file_exists($fullpath))
		unlink($fullpath);
	$fp = fopen($fullpath,'x');
	fwrite($fp, $rawdata);
	fclose($fp); 
}

if ($argc > 1)
{
	//get contain html
	$curl = curl_init($argv[1]);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
	$html = curl_exec($curl);
	curl_close($curl);
	//split html to tab contain img
	$splitted = preg_split("/(<img.*>)/", $html, -1, PREG_SPLIT_DELIM_CAPTURE | PREG_SPLIT_NO_EMPTY);
	$i = 0;
	if (empty($splitted))
		exit(); //no image
	$sitename = preg_replace("/(https?:\/\/)/", "", $argv[1]);
	//get all adresses of img and name of img 
	foreach($splitted as $elem)
	{
		if (strncmp($elem, "<img ", 4) === 0)
		{
			$adress = preg_split("/(src=\"|\")/", $elem);
			$adresses[$i] = $adress[1];
			if (strncmp($adress[1], "http", 4) !== 0)
			{
				echo $adress[1];
				if (strncmp($adress[1], "/", 1) !== 0)
					$adress[1] = "/" . $adress[1];
				$adresses[$i] = $adress[1];
			}
			$names[$i] = get_name_file($adress[1]);		
			$i++;
		}
	}
	if (empty($adresses) || empty($names))
		exit();
	if (!file_exists($sitename))
		mkdir($sitename, 0700);
	$i = 0;
	foreach($adresses as $elem)
		get_img($elem, $sitename . $names[$i++]);
}
?>