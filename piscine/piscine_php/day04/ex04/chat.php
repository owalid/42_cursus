<?php
    $content_file = unserialize(file_get_contents($file,  FILE_APPEND | LOCK_EX));
    if ($content_file)
    {
        foreach ($content_file as $key => $value)
        {
            $date = date("h:m", strtodate($value['date']));
            $msg = $value['msg'];
            $login = $value['login'];
            echo $date . ' <b>' . $login . '</b>:' . $msg . '</br>';
        }
    }
?>
