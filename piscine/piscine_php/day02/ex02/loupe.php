<?php
if ($argc != 2 && !file_exists($argv[1]))
        exit();
    if (!($fd = fopen($argv[1], 'r')))
        exit();
    while ($fd && !feof($fd))
        $html .= fgets($fd);
    if (!fclose($fd))
        exit();
    $html = preg_replace_callback('/title="(.*?)"/', function ($matches) {
        //return  'title="' . strtoupper($matches[1]) .'"';  
        return (str_replace($matches[1], strtoupper($matches[1]), $matches[0]);
    }, $html);
    $html = preg_replace_callback('/<a [^>]+.*<\/a>/', function ($matches) {
        return preg_replace_callback('/>.*</siU', function ($matches) {
            //return strtoupper($matches[0]);
            return str_replace($matches[1], strtoupper($matches[1]), $matches[0]);
        }, $matches[0]);
    }, $html);
	echo $html;