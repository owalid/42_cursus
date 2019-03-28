#!/usr/bin/php
<?php
$month = array("Janvier" => 1, "Fevrier" => 2, "Mars" => 3, "Avril" => 4,
                "Mai" => 5, "Juin" => 6, "Juillet" => 7, "Aout" => 8, "Août" => 8,
                "Septembre" => 9, "Octobre" => 10, "Novembre" => 11, "Decembre" => 12);
date_default_timezone_set('Europe/Paris');
$tmp = $argv;
$split = preg_split("/[\s]/", $tmp[1]);
if (count($split) == 5)
{
    if (preg_match("/(^[Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)/", $argv[1], $day_name)
            && preg_match("/([0-9]|[1]?[0-9]|[1]?[0-9]|[3][0-1])/", $split[1][0], $day_num1)
                && preg_match("/([0-9]|[1]?[0-9]|[1]?[0-9]|[3][0-1])/", $split[1][1], $day_num2)
                    && preg_match("/([Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Aa]out|[Aa]oût|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre)/", $argv[1], $month_name) 
                        && preg_match("/([1][9][0-9][0-9]|[0-9][0-9][0-9][0-9])/", $argv[1], $years)
                            && preg_match("/([0-2][0-9]):([0-5][0-9]):([0-5][0-9])/", $argv[1], $hour))
                        {
                            $result = strtotime($years[1] . '-' . $month[$month_name[1]] . '-' . $day_num1[1] . $day_num2[1] .  ' ' . $hour[1] . ':' . $hour[2] . ':' . $hour[3]);
                            echo $result . "\n";
                        }
                        else
                            echo "Wrong Format\n";
                        
}
else
    echo "Wrong Format\n";