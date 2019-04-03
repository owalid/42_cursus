<?php
class Tyrion extends Lannister {

    public function __construct() {
        parent::__construct();
        print("My Name is Tyrion" . PHP_EOL);
    }
    public function getSize() {
        return "Short";
    }
}