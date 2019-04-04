<?php

require_once('Vaisseaux.class.php');

abstract Class Arme extends Vaisseaux{

    protected $_charge;
    protected $_portcourte;
    protected $_zoneeffet;
    
    abstract protected function tirer($orien);

    public function __construct($argv)
    {
        $this->$_charge = $argv['charge'];
        $this->$_portcourte = $argv['portcourte'];
        $this->_zoneeffet = $argv['zoneeffet'];
    }

    public function getPortCourte()
    {
        return ($this->_portcourte);
    }
}