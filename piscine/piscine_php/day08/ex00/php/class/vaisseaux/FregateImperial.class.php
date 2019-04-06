<?php 
define('INC_PATH', 'php/class/');

require_once(INC_PATH . 'Vaisseaux.class.php');
require_once(INC_PATH . 'armes/LanceNaval.class.php');

Class FregateImperial extends Vaisseaux {
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        parent::__construct($argv);
        $this->_armes = new LanceNaval(["charge" => 1, 
                                            "portcourte" => 30,
                                            "zoneeffet" => 1]);
        $this->_type = "FregateImperial";
    }

    public function getType()
    {
        return ($this->_type);
    }
}