<?php 

require_once('../Vaisseaux.class.php');
require_once('../armes/BatterieLaser.class.php');

Class CuirasseImperial extends Vaisseaux {
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        parent::__construct($argv);
        $this->_armes = new BaterieLaser(["charge" => 0, 
                                            "portcourte" => 10,
                                            "portlong" => 20,
                                            "zoneeffet" => $argv['taille']]);
        $this->_type = "CuirasseImperial";
    }

    public function getType()
    {
        return ($this->_type);
    }
}