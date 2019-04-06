<?php

abstract Class Arme {

    protected $_charge;
    protected $_portcourte;
    protected $_zoneeffet;

    public function __construct($argv)
    {
        $this->_charge = $argv['charge'];
        $this->_portcourte = $argv['portcourte'];
        $this->_zoneeffet = $argv['zoneeffet'];
    }

    public function getPortCourte()
    {
        return ($this->_portcourte);
    }
}