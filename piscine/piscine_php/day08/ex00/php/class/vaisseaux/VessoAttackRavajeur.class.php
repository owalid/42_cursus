<?php 

require_once('../Vaisseaux.class.php');
require_once('../ZoneDeJeux.class.php');
require_once('../armes/MacroCanon.class.php');

Class VessoAttackRavajeur extends Vaisseaux {
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        parent::__construct($argv);
        $this->_armes = new BaterieLaser(["charge" => 0, 
                                            "portcourte" => 10,
                                            "portlong" => 20,
                                            "zoneeffet" => 50]);
        $this->_type = "VessoAttackRavajeur";
    }

    public function getType()
    {
        return ($this->_type);
    }
}