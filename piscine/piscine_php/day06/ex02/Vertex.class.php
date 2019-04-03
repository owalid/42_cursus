<?php
require_once('Color.class.php');

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
            (float) $this->_x = (float) $argv['x'];
            (float) $this->_y = $argv['y'];
            (float) $this->_z = $argv['z'];
            if (array_key_exists('w', $argv))
                (float) $this->_w = $argv['w'];
            else
                (float) $this->_w = 1.00;
            if (is_a($argv['color'], Color))
                $this->_color = $argv['color'];
            else
                $this->_color = new Color(["red" => 255, "green" => 255, "blue" => 255]);
            if (self::$verbose === TRUE)
            {
                printf("Vertex( x: %.1f, y: %.1f, z: %.1f, w: %.1f, ", $this->_x, $this->_y, $this->_z, $this->_w);
                echo $this->_color->__toString() . " ) constructed\n"; 
            }
        }
    }

    public function __toString() {
        $return = sprintf("Vertex( x: %.1f, y: %.1f, z: %.1f, w: %.1f, ", $this->_x, $this->_y, $this->_z, $this->_w);
        $return .= $this->_color->__toString() . " )"; 
        return ($return);
    }

    public function __destruct() {
        if (self::$verbose === TRUE)
        {
            printf("Vertex( x: %.1f, y: %.1f, z: %.1f, w: %.1f, ", $this->_x, $this->_y, $this->_z, $this->_w);
            echo $this->_color->__toString() . " ) destructed\n"; 
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
        return $this->_x = (float) $x_values;
    }

    public function setY($y_values)
    {
        return $this->_y = (float) $y_values;
    }

    public function setZ($z_values)
    {
        return $this->_z = (float) $z_values;
    }

    public function setW($w)
    {
        return $this->_w = (float) $w;
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