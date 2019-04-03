<?php

include_once('IFighter.class.php');

class NightsWatch implements IFighter {

    public function fight(){
        echo "";
    }

    public function recruit($people){
        $interfaces = class_implements($people);

        if (isset($interfaces['IFighter']))
            $people->fight(); 
    }
}