<?php 
define('INC_PATH', 'php/class/');

require_once(INC_PATH . 'Vaisseaux.class.php');
require_once(INC_PATH . 'armes/BatterieLaser.class.php');
Class CuirasseImperial extends Vaisseaux {
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        // var_dump($argv);die();
        parent::__construct($argv);
        $this->_armes = new BaterieLaser(["charge" => 1, 
                                            "portcourte" => 10,
                                            "zoneeffet" => $argv['taille']]);
        $this->_type = "CuirasseImperial";
    }

    public function getType()
    {
        return ($this->_type);
    }
}