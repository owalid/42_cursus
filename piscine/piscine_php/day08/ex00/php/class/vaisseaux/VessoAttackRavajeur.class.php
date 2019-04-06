<?php 
define('INC_PATH', 'php/class/');

require_once(INC_PATH . 'Vaisseaux.class.php');
require_once(INC_PATH . 'ZoneDeJeux.class.php');
require_once(INC_PATH . 'armes/MacroCanon.class.php');

Class VessoAttackRavajeur extends Vaisseaux {
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        parent::__construct($argv);
        $this->_armes = new MacroCanon(["charge" => 1, 
                                            "portcourte" => 10,
                                            "zoneeffet" => 50]);
        $this->_type = "VessoAttackRavajeur";
    }

    public function getType()
    {
        return ($this->_type);
    }
}