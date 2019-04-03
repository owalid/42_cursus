<?php

require_once('Vertex.class.php');
require_once('Vector.class.php');

class Matrix {
    const TRANSLATION =     "TRANSLATION";
    const PROJECTION =      "PROJECTION";
    const IDENTITY =        "IDENTITY";
    const SCALE =           "SCALE";
    const RX =              "RX";
    const RY =              "RY";
    const RZ =              "RZ";
    private $_vtcX; //vertex
    private $_vtcY; //vertex
    private $_vtcZ; //vertex
    private $_vtcW; //vertex
    public static $verbose = FALSE;

    public function __construct(array $vtcs)
    {
        if ($vtcs['preset'] === self::SCALE && array_key_exists('scale', $vtcs))
        {
            $this->scaling($vtcs['scale']);
            if (self::$verbose === TRUE)
                print("Matrix SCALE preset instance constructed\n");
        }
        else if ($vtcs['preset'] === self::TRANSLATION && array_key_exists('vtc', $vtcs))
        {
            $this->translation($vtcs['vtc']);
            if (self::$verbose === TRUE)
                print("Matrix TRANSLATION preset instance constructed\n");
        }
        else if ($vtcs['preset'] === self::PROJECTION && array_key_exists('fov', $vtcs) && array_key_exists('ratio', $vtcs) && array_key_exists('near', $vtcs) && array_key_exists('far', $vtcs))
        {
            $this->projection($vtcs['fov'], $vtcs['ratio'], $vtcs['far'], $vtcs['near']);
            if (self::$verbose === TRUE)
                print("Matrix PROJECTION preset instance constructed\n");
        }
        else if ($vtcs['preset'] === self::IDENTITY)
            $this->identity();
        else if ($vtcs['preset'] === self::RX || $vtcs['preset'] === self::RY || $vtcs['preset'] === self::RZ)
        {
            if ($vtcs['preset'] === self::RX)
            {
                $this->rotate_X($vtcs['angle']);
                if (self::$verbose === TRUE)
                    print("Matrix Ox ROTATION preset instance constructed\n");
            }
            else if ($vtcs['preset'] === self::RY)
            {
                $this->rotate_Y($vtcs['angle']);
                if (self::$verbose === TRUE)
                    print("Matrix Oy ROTATION preset instance constructed\n");
            }
            else
            {
                $this->rotate_Z($vtcs['angle']);
                if (self::$verbose === TRUE)
                    print("Matrix Oz ROTATION preset instance constructed\n");
            }
        }
        //create vertex
        else {
            if (isset($vtcs['x']) && is_a($vtcs['x'], Vertex))
            $this->_vtcX = $vtcs['x'];
			else
            $this->_vtcX = new Vertex(['x' => 0, 'y' => 0, 'z' => 0, 'w' => 0]);
			if (isset($vtcs['y']) && is_a($vtcs['y'], Vertex))
            $this->_vtcY = $vtcs['y'];
			else
            $this->_vtcY = new Vertex(['x' => 0, 'y' => 0, 'z' => 0, 'w' => 0]);
			if (isset($vtcs['z']) && is_a($vtcs['z'], Vertex))
            $this->_vtcZ = $vtcs['z'];
			else
            $this->_vtcZ = new Vertex(['x' => 0, 'y' => 0, 'z' => 0, 'w' => 0]);
			if (isset($vtcs['w']) && is_a($vtcs['w'], Vertex))
            $this->_vtcW = $vtcs['w'];
			else
            $this->_vtcW = new Vertex(['x' => 0, 'y' => 0, 'z' => 0, 'w' => 0]);
        }
    }

    public function __destruct()
    {
        print ("Matrix instance destructed\n");
    }

    public function  __toString()
    {
        $result = sprintf("M | vtcX | vtcY | vtcZ | vtx0\n");
        $result .= sprintf("---------------------------\n");
        $result .= sprintf("x | %.2f | %.2f | %.2f | %.2f\n",
                            $this->_vtcX->getX(), $this->_vtcY->getX(), $this->_vtcZ->getX(), $this->_vtcW->getX() . "\n");
        $result .= sprintf("y | %.2f | %.2f | %.2f | %.2f\n",
                            $this->_vtcX->getY(), $this->_vtcY->getY(), $this->_vtcZ->getY(), $this->_vtcW->getY() . "\n");
        $result .= sprintf("z | %.2f | %.2f | %.2f | %.2f\n",
                            $this->_vtcX->getZ(), $this->_vtcY->getZ(), $this->_vtcZ->getZ(), $this->_vtcW->getZ() . "\n");
        $result .= sprintf("w | %.2f | %.2f | %.2f | %.2f\n",
                            $this->_vtcX->getW(), $this->_vtcY->getW(), $this->_vtcZ->getW(), $this->_vtcW->getW() . "\n");

        return ($result);
    }
    public static function	doc() {
        $file = file_get_contents('Matrix.doc.txt');
        return ($file);
    }

    private function scaling($factor)
    {
        $this->_vtcX = (
            new Vertex([
                'x' => $factor,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => 0,
                'y' => $factor,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => $factor,
                'w' => 0,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ]));
    }

    private function translation(Vector $translation)
    {
        $this->_vtcX = (
            new Vertex([
                'x' => 1,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => 0,
                'y' => 1,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => 1,
                'w' => 0,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => $translation->getX(),
                    'y' => $translation->getY(),
                    'z' => $translation->getZ(),
                    'w' => 1,
                ]));
    }

    private function identity()
    {
        $this->_vtcX = (
            new Vertex([
                'x' => 1,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => 0,
                'y' => 1,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => 1,
                'w' => 0,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ]));
    }

    private function rotate_x($angle)
    {
        $this->_vtcX = (
            new Vertex([
                'x' => 1,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => 0,
                'y' => cos($angle),
                'z' => sin($angle),
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => 0,
                'y' => -sin($angle),
                'z' => cos($angle),
                'w' => 0,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ]));
    }
    private function rotate_y($angle)
    {
        $this->_vtcX = (
            new Vertex([
                'x' => cos($angle),
                'y' => 0,
                'z' => -sin($angle),
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => 0,
                'y' => 1,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => sin($angle),
                'y' => 0,
                'z' => cos($angle),
                'w' => 0,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ]));
    }

    private function rotate_z($angle)
    {
        $this->_vtcX = (
            new Vertex([
                'x' => cos($angle),
                'y' => sin($angle),
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => -sin($angle),
                'y' => cos($angle),
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => 1,
                'w' => 0,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ]));
    }
    
    private function projection($angle, $ratio, $far, $near)
    {
        $this->_vtcX = (
            new Vertex([
                'x' => atan($angle / 2) / $ratio,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcY = (
            new Vertex([
                'x' => 0,
                'y' => atan($angle / 2),
                'z' => 0,
                'w' => 0,
                ]));
        $this->_vtcZ = (
            new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => -(($far + $near) / ($far - $near)),
                'w' => -1,
                ]));
        $this->_vtcW = (
            new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => ((-2 * $far * $near) / ($far - $near)),
                    'w' => 0,
                ]));
    }

    public function mult(Matrix $rhs)
    {
        return (new Matrix([
			'x' => new Vertex([
                'x' => ($this->_vtcX->getX() * $rhs->getVtcX()->getX() 
                        +   $this->_vtcY->getX() * $rhs->getVtcX()->getY()
                        +   $this->_vtcZ->getX() * $rhs->getVtcX()->getZ()
                        +   $this->_vtcW->getX() * $rhs->getVtcX()->getW()),

                'y' => ($this->_vtcX->getY() * $rhs->getVtcX()->getX()
                        +   $this->_vtcY->getY() * $rhs->getVtcX()->getY()
                        +   $this->_vtcZ->getY() * $rhs->getVtcX()->getZ()
                        +   $this->_vtcW->getY() * $rhs->getVtcX()->getW()),

                'z' => ($this->_vtcX->getZ() * $rhs->getVtcX()->getX() 
                        +   $this->_vtcY->getZ() * $rhs->getVtcX()->getY()
                        +   $this->_vtcZ->getZ() * $rhs->getVtcX()->getZ()
                        +   $this->_vtcW->getZ() * $rhs->getVtcX()->getW()),

                'w' => (($this->_vtcX->getW() * $rhs->getVtcX()->getX()
                        +   $this->_vtcY->getW() * $rhs->getVtcX()->getY()
                        +   $this->_vtcZ->getW() * $rhs->getVtcX()->getZ()
                        +   $this->_vtcW->getW() * $rhs->getVtcX()->getW()))
            ]),

			'y' => new Vertex([
				'x' => ($this->_vtcX->getX() * $rhs->getVtcY()->getX() 
                        +   $this->_vtcY->getX() * $rhs->getVtcY()->getY()
                        +   $this->_vtcZ->getX() * $rhs->getVtcY()->getZ()
                        +   $this->_vtcW->getX() * $rhs->getVtcY()->getW()),

                'y' => ($this->_vtcX->getY() * $rhs->getVtcY()->getX() 
                        +   $this->_vtcY->getY() * $rhs->getVtcY()->getY()
                        +   $this->_vtcZ->getY() * $rhs->getVtcY()->getZ()
                        +   $this->_vtcW->getY() * $rhs->getVtcY()->getW()),

                'z' => ($this->_vtcX->getZ() * $rhs->getVtcY()->getX()
                        +   $this->_vtcY->getZ() * $rhs->getVtcY()->getY()
                        +   $this->_vtcZ->getZ() * $rhs->getVtcY()->getZ()
                        +   $this->_vtcW->getZ() * $rhs->getVtcY()->getW()),

                'w' => (($this->_vtcX->getW() * $rhs->getVtcY()->getX()
                        +   $this->_vtcY->getW() * $rhs->getVtcY()->getY()
                        +   $this->_vtcZ->getW() * $rhs->getVtcY()->getZ()
                        +   $this->_vtcW->getW() * $rhs->getVtcY()->getW()))
            ]),

			'z' => new Vertex([
                'x' => ($this->_vtcX->getX() * $rhs->getVtcZ()->getX() 
                        +   $this->_vtcY->getX() * $rhs->getVtcZ()->getY()
                        +   $this->_vtcZ->getX() * $rhs->getVtcZ()->getZ()
                        +   $this->_vtcW->getX() * $rhs->getVtcZ()->getW()),

                'y' => ($this->_vtcX->getY() * $rhs->getVtcZ()->getX()
                        +   $this->_vtcY->getY() * $rhs->getVtcZ()->getY()
                        +   $this->_vtcZ->getY() * $rhs->getVtcZ()->getZ()
                        +   $this->_vtcW->getY() * $rhs->getVtcZ()->getW()),

                'z' => ($this->_vtcX->getZ() * $rhs->getVtcZ()->getX()
                        +   $this->_vtcY->getZ() * $rhs->getVtcZ()->getY()
                        +   $this->_vtcZ->getZ() * $rhs->getVtcZ()->getZ()
                        +   $this->_vtcW->getZ() * $rhs->getVtcZ()->getW()),

                'w' => (($this->_vtcX->getW() * $rhs->getVtcZ()->getX()
                        +   $this->_vtcY->getW() * $rhs->getVtcZ()->getY()
                        +   $this->_vtcZ->getW() * $rhs->getVtcZ()->getZ()
                        +   $this->_vtcW->getW() * $rhs->getVtcZ()->getW()))
            ]),
        
			'w' => new Vertex([
                'x' => ($this->_vtcX->getX() * $rhs->getVtcW()->getX() 
                        +   $this->_vtcY->getX() * $rhs->getVtcW()->getY()
                        +   $this->_vtcZ->getX() * $rhs->getVtcW()->getZ()
                        +   $this->_vtcW->getX() * $rhs->getVtcW()->getW()),

                'y' => ($this->_vtcX->getY() * $rhs->getVtcW()->getX()
                        +   $this->_vtcY->getY() * $rhs->getVtcW()->getY()
                        +   $this->_vtcZ->getY() * $rhs->getVtcW()->getZ()
                        +   $this->_vtcW->getY() * $rhs->getVtcW()->getW()),

                'z' => ($this->_vtcX->getZ() * $rhs->getVtcW()->getX()
                        +   $this->_vtcY->getZ() * $rhs->getVtcW()->getY()
                        +   $this->_vtcZ->getZ() * $rhs->getVtcW()->getZ()
                        +   $this->_vtcW->getZ() * $rhs->getVtcW()->getW()),

                'w' => (($this->_vtcX->getW() * $rhs->getVtcW()->getX()
                        +   $this->_vtcY->getW() * $rhs->getVtcW()->getY()
                        +   $this->_vtcZ->getW() * $rhs->getVtcW()->getZ()
                        +   $this->_vtcW->getW() * $rhs->getVtcW()->getW()))
			])]));
    } 

    public function transformVertex(Vertex $vertx) {
        return new Vertex([
            'x' => ($this->_vtcX->getX() * $vertx->getX() 
                    + $this->_vtcY->getX() * $vertx->getY() 
                    + $this->_vtcZ->getX() * $vertx->getZ()
                    + $this->_vtcW->getX() * $vertx->getW()),

            'y' => ($this->_vtcX->getY() * $vertx->getX() 
                    + $this->_vtcY->getY() * $vertx->getY() 
                    + $this->_vtcZ->getY() * $vertx->getZ()
                    + $this->_vtcW->getY() * $vertx->getW()),

            'z' => ($this->_vtcX->getZ() * $vertx->getX()
                    + $this->_vtcY->getZ() * $vertx->getY()
                    + $this->_vtcZ->getZ() * $vertx->getZ()
                    + $this->_vtcW->getZ() * $vertx->getW()),

            'w' => ($this->_vtcX->getW() * $vertx->getX()
                    + $this->_vtcY->getW() * $vertx->getY() 
                    + $this->_vtcZ->getW() * $vertx->getZ() 
                    + $this->_vtcW->getW() * $vertx->getW()),
            
        ]);
    }

    public function symetrie_diagonal()
    {
        return (new Matrix([
			'x' => $this->_vtcY,

			'y' => $this->_vtcX,

            'z' => $this->_vtcZ,
            
			'w' => $this->_vtcW,
			]));
    }

/** Accessor */
    public function getVtcX()
    {
        return ($this->_vtcX);
    }

    public function getVtcY()
    {
        return ($this->_vtcY);
    }

    public function getVtcZ()
    {
        return ($this->_vtcZ);
    }

    public function getVtcW()
    {
        return ($this->_vtcW);
    }

}