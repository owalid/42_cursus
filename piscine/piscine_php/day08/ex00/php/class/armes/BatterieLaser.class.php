<?php
define('INC_PATH', 'php/class/');
require_once(INC_PATH . 'Arme.class.php');

Class BaterieLaser extends Arme {
    public function __construct($argv)
    {
        parent::__construct($argv);
    }
}