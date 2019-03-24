<?php
class Color {
    public $red;
    public $green;
    public $blue;
    public $verbose = FALSE;

    public function __construct(array $rgb) {
        if ($argc == 1)
        $this->red = $rgb['red'];
        $this->green = $rgb['green'];
        $this->blue = $rbg['blue'];
    }

    public function __destruct() {
        echo "Destroying " . __CLASS__ . "\n";
    }

    private function add($color) {
        $new_color = new Color(array('red' => $this->red + $color->red, 
                                        'green' => $this->green + $color->green, 
                                            'blue' => $this->blue + $color->blue));
        return ($new_color);
    }

    private function sub($color) {
        $new_color = new Color(array('red' => $this->red - $color->red, 
                                        'green' => $this->green - $color->green, 
                                            'blue' => $this->blue - $color->blue));
        return ($new_color);
    }

    private function mul($color) {
        $new_color = new Color(array('red' => $this->red * $color->red, 
                                        'green' => $this->green * $color->green, 
                                            'blue' => $this->blue * $color->blue));
        return ($new_color);
    }
}