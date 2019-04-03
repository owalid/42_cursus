<?php
include_once('Lannister.class.php');

class Jaime extends Lannister {

    public function get_print($lani) {
        if (get_class($lani) === "Tyrion")
            $result = "Not even if I'm drunk !\n";
        if (get_class($lani) === "Sansa")
            $result = "Let's do this.\n";
        if (get_class($lani) === "Cersei")
            $result = "With pleasure, but only in a tower in Winterfell, then.\n";
        print($result);
    }
}