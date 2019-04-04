<?php

include_once('IFighter.class.php');

class NightsWatch implements IFighter {

    private $fighter;
    
    public function fight(){
        foreach ($this->fighter as $key => $value)
            $value->fight();
    }

    public function recruit($people){
        $interfaces = class_implements($people);

        if (isset($interfaces['IFighter']))
            $this->fighter[] = $people; 
    }
}