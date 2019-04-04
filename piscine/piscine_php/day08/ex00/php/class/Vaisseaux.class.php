<?php

require_once('Arme.class.php');

Class Vaisseaux {
    private $_positionX;
    private $_isactive = false;
    private $_positionY;
    private $_orientation;
    private $_nom;
    private $_taille;
    private $_sprite;
    private $_pointcoque;
    private $_puissancemot;
    private $_vitesse;
    private $_manoeuvre;
    private $_bouclier;
    private $_armes;
    private $_type;

    public function __construct($argv)
    {
        if (isset($argv['positionX']) && isset($argv['positionY']) && isset($argv['nom']) 
            && isset($argv['taille']) && isset($argv['sprite']) 
            && isset($argv['pointcoque']) && isset($argv['puissancemot'])
            && isset($argv['vitesse']) && isset($argv['manoeuvre'])
            && isset($argv['bouclier']) && isset($argv['armes'])
            && is_a($argv['armes'], Arme) && isset($argv['orientation']))
        {
            $this->$_positionX = $argv['positionX'];
            $this->$_positionY = $argv['positionY'];
            $this->$_orientation = $argv['orientation'];
            $this->$_nom = $argv['nom'];
            $this->$_taille = $argv['taille'];
            $this->$_sprite = $argv['_prite'];
            $this->$_pointcoque = $argv['pointcoque'];
            $this->$_puissancemot = $argv['puissancemot'];
            $this->$_vitesse = $argv['vitesse'];
            $this->$_bouclier = $argv['bouclier'];
            $this->$_armes = $argv['armes'];
        }
    }

    public function active()
    {
        $this->$_isactive = true;
    }

    

    public function tirer(ZonedeJeux $zone)
    {   
        for ($i = 0; $i < 120; $i++)
        {
            for ($j = 0; $j < 100; $j++)
            {
                if ($j == $this->$_postionY)
                {
                    for ($j; $j < $this->_armes->getPortCourte(); $j++)
                    {
                        $zone->setZone('|', $i, $j);
                        sleep(1);
                    }
                }
            }
        }
    }

    public function ordre($ordre, $result_des)
    {
        if ($ordre === "vitesse")
            $this->_vitesse = $result_des;
        else if ($ordre === "bouclier")
            $this->$bouclier += 1;
        else if ($ordre ===  "tirer")
            $this->tirer();
    }

/* Mouvement */
    public function mouvement($deplacement, $vitesse)
    {
        /* Gauche */
        if ($deplacement === "GA")
        {
            if ($this->_oritentation === 4)
                $this->_orientation = 1;
            else
                $this->_orientation += 1;
            return true;
        }
        /* Droite */
        else if ($deplacement === "DR")
        {
            if ($this->_oritentation === 1)
                $this->_orientation = 4;
            else
                $this->_orientation -= 1;
            return true;
        }
        /* Avancer */
        else if ($deplacement === "AV")
        {
            if ($this->_orientation === 1)
            {
                if ($this->_positionY === 0)
                    return false;
                else
                    $this->_positionY += $vitesse;
            }
            if ($this->_orientation === 2)
            {
                if ($this->_positionX === 120)
                    return false;
                else
                    $this->_positionX += $vitesse;
            }
            if ($this->_orientation === 3)
            {
                if ($this->_positionY === 100)
                    return false;
                else
                    $this->_positionY -= $vitesse;
            }
            if ($this->_orientation === 4)
            {
                if ($this->_positionY === 0)
                    return false;
                else
                    $this->_positionX -= $vitesse;
            }
            return true;
        }
        /* Reculer */
        else if ($deplacement === "AV")
        {
            if ($this->_orientation === 1)
            {
                if ($this->_positionY === 0)
                    return false;
                else
                    $this->_positionY -= $vitesse;
            }
            if ($this->_orientation === 2)
            {
                if ($this->_positionX === 120)
                    return false;
                else
                    $this->_positionX -= $vitesse;
            }
            if ($this->_orientation === 3)
            {
                if ($this->_positionY === 100)
                    return false;
                else
                    $this->_positionY += $vitesse;
            }
            if ($this->_orientation === 4)
            {
                if ($this->_positionY === 0)
                    return false;
                else
                    $this->_positionX += $vitesse;
            }
            return true;
        }
    }
}