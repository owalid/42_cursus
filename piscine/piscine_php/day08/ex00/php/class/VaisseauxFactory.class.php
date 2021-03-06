<?php
define('INC_PATH', 'php/class/');

require_once(INC_PATH . 'Vaisseaux.class.php');
require_once(INC_PATH . 'vaisseaux/CuirasseImperial.class.php');
require_once(INC_PATH . 'vaisseaux/VessoAttackRavajeur.class.php');
require_once(INC_PATH . 'vaisseaux/FregateImperial.class.php');

Class VaisseauxFactory {
    private $_vaisseauxJ1 = [];
    private $_vaisseauxJ2 = [];
    
    public function absorb($pseudo_vaisseaux, $joueur) {
        if ($pseudo_vaisseaux instanceof Vaisseaux)
        {
            if (!(array_key_exists($pseudo_vaisseaux->getType(), $this->_vaisseauxJ1)) && $joueur === 1) 
                $this->_vaisseauxJ1[$pseudo_vaisseaux->getType()] = $pseudo_vaisseaux;

            if (!(array_key_exists($pseudo_vaisseaux->getType(), $this->_vaisseauxJ2)) && $joueur === 2) 
                $this->_vaisseauxJ2[$pseudo_vaisseaux->getType()] = $pseudo_vaisseaux;
        }
    }

    public function fabricateJ1($vaisseaux, $preset) {
        if (array_key_exists($vaisseaux, $this->_vaisseauxJ1))
        {
            // var_dump($preset);die();
            return new $this->_vaisseauxJ1[$vaisseaux]($preset);
        }
    }

    public function fabricateJ2($vaisseaux, $preset) {
        if (array_key_exists($vaisseaux, $this->_vaisseauxJ2))
            return new $this->_vaisseauxJ2[$vaisseaux]($preset);
    }
}