<?php

require_once('Joueur.class.php');

Class ZonedeJeux {
    private $_joueur1;
    private $_joueur2;
    private $_zone = [[]];
    public static $verbose = FALSE;

    public function __construct($argv)
    {
        if (isset($argv['joueur1']) && is_a($argv['joueur1'], Joueur) && isset($argv['joueur2']) && is_a($argv['joueur2'], Joueur))
        {
            $this->_joueur1 = $argv['joueur1'];
            $this->_joueur2 = $argv['joueur2'];
            for ($i = 0; $i < 120 ; $i++)
            {
                for ($j = 0; $j < 100; $j++)
                {
                    if (($j === 5 && $i === 10) || ($j === 50 && $i === 15) || ($j === 90 && $i === 55))
                        $this->$zone[$i][$j] = 1;
                    else
                        $this->$_zone[$i][$j] = 0;
                }
            }
            if (self::$verbose == TRUE)
                print("Zone de Jeux construite ");
        }  
        else
        {
            echo "<script>alert('pas de joueur :(')</script>";
        }
    }

    public function getJoueur1()
    {
        return ($this->_joueur1);
    }

    public function getJoueur2()
    {
        return ($this->_joueur2);
    }

    public function getZone()
    {
        return (json_encode($this->$_zone));
    }

    public function setZone($char, $i, $j)
    {
        $this->$_zone[$i][$j] = $char;
    }
}