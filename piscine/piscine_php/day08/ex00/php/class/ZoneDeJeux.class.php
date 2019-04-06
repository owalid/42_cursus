<?php
define('INC_PATH', 'php/class/');

require_once(INC_PATH . 'Joueur.class.php');

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

            for ($i = 0; $i < 150 ; $i++)
            {
                for ($j = 0; $j < 100; $j++)
                    $this->_zone[$i][$j] = 0;
            }
            for ($i = 0; $i < 150 ; $i++)
            {
                for ($j = 0; $j < 100; $j++)
                {
                    foreach($argv['joueur1']->getVaisseaux()[0] as $v1)
                    {
                        if (($j === $v1->getPositionY() && $i === $v1->getPositionX()))
                            $this->_zone[$i][$j] = 1;
                    }
                    foreach($argv['joueur2']->getVaisseaux()[0] as $v2)
                    {
                        if (($j === $v2->getPositionY() && $i === $v2->getPositionX()))
                            $this->_zone[$i][$j] = 2;
                    }
                    if (($j === 30 && $i === 30) || ($j === 50 && $i === 50) || ($j === 30 && $i === 90))
                        $this->_zone[$i][$j] = 3;
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
        return (json_encode($this->_zone));
    }

    public function setZone($char, $i, $j)
    {
        $this->_zone[$i][$j] = $char;
    }
}