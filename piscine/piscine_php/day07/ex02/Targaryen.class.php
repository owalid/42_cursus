<?php
class Targaryen {
    
    public function getBurned() {
        if (get_class($this) === "Viserys")
            return ("burns alive");
        if (get_class($this) === "Daenerys")
            return ("emerges naked but unharmed");
    }
}