<?php
class Color {
    private $red;
    private $green;
    private $blue;
    public static $verbose = FALSE;

    public function __construct(array $rgb) {
        if (isset($rgb['rgb']))
        {
            $this->red = (int) $rgb['rgb'] / 65536 % 256;
            $this->green = (int) $rgb['rgb'] / 256 % 256;
            $this->blue = (int) $rgb['rgb'] % 256;
        }
        else if (isset($rgb['red']) && isset($rgb['green']) && isset($rgb['blue']))
        {
            $this->red = (int) $rgb['red'];
            $this->green = (int) $rgb['green'];
            $this->blue = (int) $rgb['blue'];
        }
        if (self::$verbose === true) 
            echo "Color( red: " . $this->red . ", green: " . $this->green . ", blue: " . $this->blue . " ) constructed.\n";
    }
    
    public function add($color) {
        $new_color = new Color(array('red' => $this->red + $color->red, 
        'green' => $this->green + $color->green, 
        'blue' => $this->blue + $color->blue));
        return ($new_color);
    }
    
    public function sub($color) {
        $new_color = new Color(array('red' => $this->red - $color->red, 
        'green' => $this->green - $color->green, 
        'blue' => $this->blue - $color->blue));
        return ($new_color);
    }
    
    public function mult($color) {
        $new_color = new Color(array('red' => $this->red * $color->red, 
        'green' => $this->green * $color->green, 
        'blue' => $this->blue * $color->blue));
        return ($new_color);
    }
    
    public function __toString() {
        return ("Color( red: " . $this->red . ", green: " . $this->green . ", blue: " . $this->blue . " )");
    }

    public function __destruct() {
        if (self::$verbose === TRUE)
        {
            echo "Color( red: " . $this->red . ", green: " . $this->green . ", blue: " . $this->blue . " ) destructed.\n";
        }
    }

    public static function	doc()
    {
        $file = file_get_contents('Color.doc.txt');
        return ($file);
    }
}