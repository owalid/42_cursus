<?php
include_once('Lannister.class.php');

class Tyrion extends Lannister {
    
    public function get_print($lani){
        if (get_class($lani) === "Jaime")
            $result = "Not even if I'm drunk !\n";
        if (get_class($lani) === "Sansa")
            $result = "Let's do this.\n";
        if (get_class($lani) === "Cersei")
            $result = "Not even if I'm drunk !\n";
        print($result);
    }

}