<?php
require_once('../ex00/Color.class.php');

class Vertex {
    private $_x;
    private $_y;
    private $_z;
    private $_w;
    private $_color;
    public static $verbose = False;

    public function __construct(array $argv)
    {
        if ($argv['x'] !== NULL && $argv['y'] !== NULL && $argv['z'] !== NULL)
        {
            $this->_x = $argv['x'];
            $this->_y = $argv['y'];
            $this->_z = $argv['z'];
            if (array_key_exists('w', $argv))
                $this->_w = $argv['w'];
            else
                $this->_w = 1.00;
            if (is_a($argv['color'], Color))
                $this->_color = $argv['color'];
            else
                $this->_color = new Color(["red" => 255, "green" => 255, "blue" => 255]);
            if (self::$verbose === TRUE)
            {
                echo "Vertex ( x:". $this->_x . ", y: " . $this->_y . ", z: " . $this->_z . ", w: " . $this->_w . ", " . $this->_color->__toString() . " ) constructed\n"; 
            }
        }
    }

    public function __toString() {
        return ( "Vertex ( x:". $this->_x . ", y: " . $this->_y . ", z: " . $this->_z . ", w: " . $this->_w . ", " . $this->_color->__toString() . " )");
    }

    public function __destruct() {
        if (self::$verbose === TRUE)
        {
            echo "Vertex ( x:". $this->_x . ", y: " . $this->_y . ", z: " . $this->_z . ", w: " . $this->_w . ", " . $this->_color->__toString() . " ) constructed\n";
        }
    }

/** accessor */
    public function getX()
    {
        return ($this->_x);
    }

    public function getY()
    {
        return ($this->_y);
    }

    public function getZ()
    {
        return $this->_z;
    }

    public function getW()
    {
        return $this->_w;
    }

    public function getColor()
    {
        return $this->_color;
    }

    public function setX($x_values)
    {
        return $this->_x = $x_values;
    }

    public function setY($y_values)
    {
        return $this->_y = $y_values;
    }

    public function setZ($z_values)
    {
        return $this->_z = $z_values;
    }

    public function setW($w)
    {
        return $this->_w = $w;
    }

    public function setColor($color)
    {
        return $this->_Color = $color;
    }

    public static function	doc()
    {
        $file = file_get_contents('Vertex.doc.txt');
        return ($file);
    }
}