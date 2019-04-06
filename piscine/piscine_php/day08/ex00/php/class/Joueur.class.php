<?php

Class Joueur {

    private $_nom;
    private $_game = false;
    private $_vaisseaux = [];
    private $_pP = 3;

    public function __construct($nom, $vaisseaux)
    {
        $this->_nom = $nom;
        $this->_vaisseaux[] = $vaisseaux;
    }

    public function lancerDes()
    {
        return (rand(1, 6));
    }

    public function setpP($newpP)
    {
        $this->_pP = $newpP;
    }

    public function setGame(bool $value)
    {
        $this->_game = $value;
    }

    public function getGame()
    {
        return ($this->_game);
    }

    public function getName()
    {
        return ($this->_nom);
    }

    public function getpP()
    {
        return ($this->_pP);
    }
    public function getVaisseaux()
    {
        return ($this->_vaisseaux);
    }
    public function setVaisseaux($vaisseaux)
    {
        $this->_vaisseaux = $vaisseaux;
    }
}