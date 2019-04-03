<?php
require_once 'Vertex.class.php';
require_once 'Vector.class.php';
require_once 'Matrix.class.php';

class Camera {

    public static $verbose = FALSE;
    private $_result_mult;
    private $_oppo_origin;
    private $_proj;
    private $_tT;
    private $_tR;

    public function __construct($argv)
    {
        if (array_key_exists('origin', $argv) && array_key_exists('orientation', $argv)
                && array_key_exists('fov', $argv) && array_key_exists('near', $argv) && array_key_exists('far', $argv))
        {
            if ( array_key_exists('width', $argv) &&  array_key_exists('height', $argv) 
                && !array_key_exists('ratio', $argv))
            {

                //create tT
                $this->_oppo_origin = new Vector(["dest" => $argv['origin']]);
                $this->_oppo_origin->opposite();
                $this->_tT = new Matrix(["preset" => Matrix::TRANSLATION, 'vtc' => $this->_oppo_origin]);

                //create tR =>
                $this->_tR = $argv['orientation']->symetrie_diagonal();


                //Tr->mult( tT )
                $this->_result_mult = $this->_tR->mult($this->_tT);
                $this->_proj = new Matrix (
                    ['preset' => Matrix::PROJECTION,
                    'fov' => $argv['fov'],
                    'ratio' => $argv['width'] / $argv['height'],
                    'near' => $argv['near'],
                    'far' => $argv['far']
                    ]);
            }
            else if (!array_key_exists('width', $argv) &&  !array_key_exists('height', $argv)
                && array_key_exists('ratio', $argv))
            {
                //create tT
                $this->_oppo_origin = new Vector(["dest" => $argv['origin']]);
                $this->_oppo_origin->opposite();
                $this->_tT = new Matrix(["preset" => Matrix::TRANSLATION, 'vtc' => $this->_oppo_origin]);

                //create tR =>
                $this->_tR = $argv['orientation']->symetrie_diagonal();

                //Tr->mult( _tT )
                $this->_result_mult = $this->_tR->mult($this->_tT);
                $this->_result_mult = new Matrix (
                    ['preset' => Matrix::PROJECTION,
                    'fov' => $argv['fov'],
                    'ratio' => $argv['ratio'],
                    'near' => $argv['near'],
                    'far' => $argv['far']
                    ]);
            }
        }

        if (self::$verbose === TRUE)
        {
            $result .= "Camera instance constructed \n";
        }
    }
    
    public function __destruct()
    {
        if (self::$verbose === TRUE)
            print("Camera instance destructed\n");
    }

    public function __toString()
    {
        $result .= "Camera (\n";
        $result .= "+ Origine : " . $this->_oppo_origin->__toString();
        $result .= "\n+ tT: \n";
        $result .= $this->_tT->__toString();
        $result .= "+ tR: \n";
        $result .= $this->_tR->__toString();
        $result .= "+ tR->mult( tT ):\n";
        $result .= $this->_result_mult->__toString();
        $result .= "+ Proj: \n";
        $result .= $this->_proj->__toString();
        $result .= "\n)\n";
        return($result);
    }
    public static function	doc ()
	{
        $file = file_get_contents('Camera.doc.txt');
        return ($file);
    }

    // private function watchVertex( Vertex $worldVertex )
    // {

    // }
}