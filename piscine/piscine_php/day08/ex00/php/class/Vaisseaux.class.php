<?php
define('INC_PATH', 'php/class/');

require_once(INC_PATH . 'Arme.class.php');

Class Vaisseaux {
    private $_positionX;
    private $_isactive = false;
    private $_positionY;
    private $_orientation;
    private $_taille;
    private $_sprite;
    private $_pointcoque;
    private $_puissancemot;
    private $_vitesse;
    private $_manoeuvre;
    private $_bouclier;
    private $_type;

    public function __construct($argv)
    {
        if (isset($argv['positionX']) && isset($argv['positionY']) 
        && isset($argv['taille']) && isset($argv['sprite']) 
        && isset($argv['pointcoque']) && isset($argv['puissancemot'])
        && isset($argv['vitesse'])
        && isset($argv['bouclier']) && isset($argv['orientation']))
        {
            $this->_positionX = $argv['positionX'];
            $this->_positionY = $argv['positionY'];
            $this->_orientation = $argv['orientation'];
            $this->_taille = $argv['taille'];
            $this->_sprite = $argv['_prite'];
            $this->_pointcoque = $argv['pointcoque'];
            $this->_puissancemot = $argv['puissancemot'];
            $this->_vitesse = $argv['vitesse'];
            $this->_bouclier = $argv['bouclier'];
        }
    }

    public function active()
    {
        $this->$_isactive = true;
    }

    public function ordre($argv)
    {
        if ($argv['ordre'] === "VITESSE")
            $this->_vitesse = $argv['des'];
        else if ($argv['ordre'] === "BOUCLIER")
            $this->bouclier += 1;
        else if ($argv['ordre'] ===  "TIR")
            $this->tirer($argv['zone']);
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

/* Mouvement */
    public function mouvement($deplacement, $vitesse, $zone, $joueur)
    {
        /* Gauche */
        if ($deplacement === "GAUCHE")
        {
            if ($this->_oritentation === 4)
                $this->_orientation = 1;
            else
                $this->_orientation += 1;
            return true;
        }
        /* Droite */
        else if ($deplacement === "DROITE")
        {
            if ($this->_oritentation === 1)
                $this->_orientation = 4;
            else
                $this->_orientation -= 1;
            return true;
        }
        /* Avancer */
        else if ($deplacement === "AVANCER")
        {
            if ($this->_orientation === 1)
            {
                if ($this->_positionY === 0)
                return false;
                else
                {
                    $zone->setZone($this->_positionX, $this->_positionY, 0);
                    $zone->setZone($this->_positionX, $this->_positionY + $vitesse, $joueur);
                    $this->_positionY += $vitesse;
                }
            }
            if ($this->_orientation === 2)
            {
                if ($this->_positionX === 120)
                return false;
                else
                {
                    $zone->setZone($this->_positionX, $this->_positionY, 0);
                    $zone->setZone($this->_positionX - $vitesse, $this->_positionY, $joueur);
                    $this->_positionX -= $vitesse;
                }
            }
            if ($this->_orientation === 3)
            {
                if ($this->_positionY === 100)
                    return false;
                else
                {
                    $zone->setZone($this->_positionX, $this->_positionY, 0);
                    $zone->setZone($this->_positionX, $this->_positionY + $vitesse, $joueur);
                    $this->_positionY += $vitesse;
                }
            }
            if ($this->_orientation === 4)
            {
                if ($this->_positionY === 0)
                    return false;
                else
                {
                    $zone->setZone($this->_positionX, $this->_positionY, 0);
                    $zone->setZone($this->_positionX + $vitesse, $this->_positionY, $joueur);
                    $this->_positionX += $vitesse;
                }
            }
            return true;
        }
        /* Reculer */
        else if ($deplacement === "RECULER")
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

/* Accessor */
    public function getPositionX()
    {
        return ($this->_positionX);
    }

    public function getPositionY()
    {
        return ($this->_positionY);
    }
}