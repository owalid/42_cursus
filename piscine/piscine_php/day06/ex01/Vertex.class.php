<?php
require_once('../ex00/Color.class.php');
class Vertex {

    private $_x;
    private $_y;
    private $_z;
    private $_w;
    private $_color;
    public static $verbose = False;

    public function __construct(array $argv )
    {
        $this->_w = 1.00;
        if ($argv['x'] !== NULL && $argv['y'] !== NULL && $argv['z'] !== NULL)
        {
            $this->_x = $argv['x'];
            $this->_y = $argv['y'];
            $this->_z = $argv['z'];
            if (array_key_exists('w', $argv))
                $this->_w = $argv['w'];
            if (array_key_exists('color', $argv))
                $this->_color = $argv['color'];
        }
        else
            $this->_color = $this->setColor(new Color(array( 'red' =>   255, 'green' =>   255, 'blue' => 255 )));
    }

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

}