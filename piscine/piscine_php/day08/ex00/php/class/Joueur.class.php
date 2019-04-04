<?php

Class Joueur {

    private $_nom;
    private $_game = false;
    private $_vaisseaux = [];
    private $_pP = 3;

    public function __construct($nom, $vaisseaux)
    {
        $this->$_nom = $nom;
        $this->_vaisseaux[] = $vaisseaux;
    }

    public function lancerDes()
    {
        return (rand(1, 6));
    }

    public function action($name_action, $vaisseaux_name, $options)
    {
        if ($this->_pP > 3)
        {
            if ($name_action === "TIR")
                $_vaisseaux[$vaisseaux_name]->tir();
            else if ($name_action === "ORDRE")
                $_vaisseaux[$vaisseaux_name]->ordre($options['ordre'], $options['resultdes']);
            else if ($name_action === "mouvement")
                $_vaisseaux[$vaisseaux_name]->mouvement($option['deplacement'], $option['vitesse']);
            $this->_pP--;
        }
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
}