<?php
if ($_SESSION['loggued_on_user'] !== "")
{
    session_start();
    $_SESSION['loggued_on_user'] = '';
}