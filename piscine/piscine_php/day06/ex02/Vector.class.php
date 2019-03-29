<?php
require_once 'Vertex.class.php';
class Vector
{
    private $_x = 1.0;
    private $_y = 1.0;
    private $_z = 1.0;
    private $_w = 0.0;
    public static $verbose = False;

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
        return ($this->_z);
    }
    public function getW()
    {
        return ($this->_w);
    }
}