#!/usr/bin/php
<?php
function download_image($img, $fullpath){
	$ch = curl_init ($img);
	curl_setopt($ch, CURLOPT_HEADER, 0);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_BINARYTRANSFER,1);
	$rawdata=curl_exec($ch);
	curl_close ($ch);
	if(file_exists($fullpath)){
		unlink($fullpath);
	}
	$fp = fopen($fullpath,'x');
	fwrite($fp, $rawdata);
	fclose($fp); 
}
if ($argc > 1)
{
	$curl = curl_init($argv[1]);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
	$return = curl_exec($curl);
	curl_close($curl);
	$splitted = preg_split("/(<img.*>)/", $return, -1, PREG_SPLIT_DELIM_CAPTURE | PREG_SPLIT_NO_EMPTY);
	$i = 0;
	if(empty($splitted))
		exit();
	foreach($splitted as $elem)
	{
		if(strncmp($elem, "<img ", 4) === 0)
		{
			$adress = preg_split("/(src=\"|\")/", $elem);
			$adresses[$i] = $adress[1];
			$i++;
		}
	}
	$domain_get = preg_split("/(http:\/\/|\/)/", $argv[1], -1, PREG_SPLIT_DELIM_CAPTURE | PREG_SPLIT_NO_EMPTY);
	$domain = $domain_get[0].$domain_get[1];
	$sitename = preg_replace("/(https?:\/\/)/", "", $argv[1]);
	if(strcmp(substr($sitename, -1), "/") == 0)
		$sitename = substr($sitename, 0, -1);
	$i = 0;
	if(empty($adresses))
		exit();
	foreach($adresses as $elem)
	{
		if(strncmp($elem, "http", 4) !== 0)
		{
			if(strncmp($elem, "/", 1) !== 0)
				$elem = "/".$elem;
			$adresses[$i] = $domain.$elem;
		}
		$elem = strrev($elem);
		$names[$i] = substr($elem, 0, strpos($elem, "/"));
		$names[$i] = strrev($names[$i]);
		$i++;
	}
	$sitename = str_replace("/", ":", $sitename);
	if(!file_exists($sitename))
		mkdir($sitename, 0700);
	$i = 0;
	if(file_exists($sitename))
	{
		foreach($adresses as $elem)
		{
				download_image($elem, $sitename."/".$names[$i]);
			$i++;
		}
	}
}
?>