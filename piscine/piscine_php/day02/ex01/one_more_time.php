#!/usr/bin/php
<?php
$month = array("Janvier" => 1, "Fevrier" => 2, "Mars" => 3, "Avril" => 4,
                "Mai" => 5, "Juin" => 6, "Juillet" => 7, "Aout" => 8,
                "Septembre" => 9, "Octobre" => 10, "Novembre" => 11, "Decembre" => 12);
$param = preg_split('/\s/', $argv[1]);
$timeref = strtotime("1970-01-01 00:00:00");
if (preg_match("/(^[Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)/", $argv[1], $jour)) && preg_match("/[0-9]|[1]?[0-9]|[2]?[0-9]|[3][0-1])/", ,) &&  preg_match("[Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Aa]out|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre)/", , ) && preg_match("([1][9][7-9][0-9]|[2-9][0-9][0-9][0-9])") && preg_match("[0-2][0-9]):([0-5][0-9]):([0-5][0-9])/", ,)
{
    strtotime($jour, $minutes, $heures, trans_month(strtoupper($mois)), $secondes);
}
else
    echo "Wrong Format\n";
date_default_timezone_set('UTC');