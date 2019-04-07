<?php
function co_bd()
{
    $conn = mysqli_connect("127.0.0.1", "root", "123456", "rush00");
    if (!$conn) 
        die("Connection BD failed");
    return ($conn);
}