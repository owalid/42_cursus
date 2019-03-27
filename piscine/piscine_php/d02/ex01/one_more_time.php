#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Paris');

function get_number($s1)
{
	if($s1 == "janvier" || $s1 == "Janvier")
		return(1);
	if($s1 == "fevrier" || $s1 == "Fevrier" || $s1 == "Février" || $s1 == "février")
		return(2);
	if($s1 == "mars" || $s1 == "Mars")
		return(3);
	if($s1 == "avril" || $s1 == "Avril")
		return(4);
	if($s1 == "mai" || $s1 == "Mai")
		return(5);
	if($s1 == "Juin" || $s1 == "juin")
		return(6);
	if($s1 == "juillet" || $s1 == "Juillet")
		return(7);
	if($s1 == "Aout" || $s1 == "aout" || $s1 == "Août" || $s1 == "août")
		return(8);
	if($s1 == "septembre" || $s1 == "Septembre")
		return(9);
	if($s1 == "octobre" || $s1 == "Octobre")
		return(10);
	if($s1 == "novembre" || $s1 == "Novembre")
		return(11);
	if($s1 == "decembre" || $s1 == "Décembre" || $s1 == "Decembre" || "décembre")
		return(12);
}
if ($argc > 1)
{
	$arg = $argv[1];
	if((preg_match("/(^[L|l]undi|^[M|m]ardi|^[M|m]ercredi|^[J|j]eudi|^[V|v]endredi|^[S|s]amedi|^[D|d]imanche) {1}([0-9]{1,2}) {1}([J|j]anvier|[F|f][e|é]vrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]o[u|û]t|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d][e|é]cembre) {1}[0-9]{4} {1}[0-9]{2}:[0-9]{2}:[0-9]{2}$/", $arg)) == 0)
	{
		echo "Wrong Format\n";
		exit ();
	}
	else
	{
		preg_match("/([0-9]{1,2})/", $arg, $num);
		preg_match("/([J|j]anvier|[F|f][e|é]vrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]o[u|û]t|[S|s]eptembre|[N|n]ovembre|[D|d][e|é]cembre)/", $arg, $month);
		$monthnm = get_number($month[0]);
		preg_match("/[0-9]{4}/", $arg, $year);
		preg_match("/[0-9]{2}:/", $arg, $hour);
		$hour[0] = substr($hour[0], 0, 2);
		preg_match("/:[0-9]{2}:/", $arg, $min);
		$min[0] = substr($min[0], 1);
		$min[0] = substr($min[0], 0, 2);
		preg_match("/:[0-9]{2}$/", $arg, $sec);
		$sec[0] = substr($sec[0], 1);
		echo mktime($hour[0], $min[0], $sec[0], $monthnm, $num[0], $year[0]);
		echo "\n";
	}
}	
?>
