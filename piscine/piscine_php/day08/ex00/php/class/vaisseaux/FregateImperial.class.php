<?php 

require_once('../Vaisseaux.class.php');
require_once('../armes/LanceNaval.class.php');

Class FregateImperial extends Vaisseaux {
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        parent::__construct($argv);
        $this->_armes = new BaterieLaser(["charge" => 0, 
                                            "portcourte" => 30,
                                            "portlong" => 90,
                                            "zoneeffet" => 1]);
        $this->_type = "FregateImperial";
    }

    public function getType()
    {
        return ($this->_type);
    }
}