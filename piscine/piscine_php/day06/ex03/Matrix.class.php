<?php

require_once('../ex01/Vertex.class.php');
require_once('../ex02/Vector.class.php');

class Matrix {
    const TRANSLATION =     'TRANSLATION';
    const PROJECTION =      'PROJECTION';
    const IDENTITY =        'IDENTITY';
    const SCALE =           'SCALE';
    const RX =              'RX';
    const RY =              'RY';
    const RZ =              'RZ';
    private $_vtcX; //vertex
    private $_vtcY; //vertex
    private $_vtcZ; //vertex
    private $_vtcW; //vertex
    public static $verbose = FALSE;

    public function __construct(array $vtcs)
    {
        if ($vtc['preset'] === 'SCALE' && array_key_exists('scale', $vtcs))
            scaling($vtc['preset']);
        if ($vtcs['preset'] === 'TRANSLATION')
            translation($vtcs['translation']);
        if ($vtcs['preset'] === 'PROJECTION' && array_key_exists('fov', $vtc) && array_key_exists('ratio', $vtcs) && array_key_exists('near', $vtcs) & array_key_exists('far', $vtcs))
            projection($vtcs['fov'], $vtcs['ratio'], $vtcs['far'], $vtcs['near']);
        if ($vtcs['preset'] === 'IDENTITY')
            identity();
        if ($vtcs['preset'] === 'RX' || $vtcs['preset'] === 'RY' || $vtcs['preset'] === 'RZ')
        {
            if ($vtcs['preset'] === "RX")
                rotate_X($vtcs['angle']);
            else if ($vtcs['preset'] === "RY")
                rotate_Y($vtcs['angle']);
            else
                rotate_Z($vtcs['angle']);
        }
        if (self::$verbose === TRUE)
        {
            $affichage  = "M | vtcX | vtcY | vtcZ | vtx0\n";
            $affichage .= "---------------------------\n";
            $affichage .= "X | " . $this->_vtcX->getX() . "|" . $this->_vtcY->getX() . "|" . $this->_vtcZ->getX() . "|" . $this->_vtcW->getX() . "\n"; 
            $affichage .= "Y | " . $this->_vtcX->getY() . "|" . $this->_vtcY->getY() . "|" . $this->_vtcZ->getY() . "|" . $this->_vtcW->getY() . "\n"; 
            $affichage .= "Z | " . $this->_vtcX->getZ() . "|" . $this->_vtcY->getZ() . "|" . $this->_vtcZ->getZ() . "|" . $this->_vtcW->getZ() . "\n"; 
            $affichage .= "W | " . $this->_vtcX->getW() . "|" . $this->_vtcY->getW() . "|" . $this->_vtcZ->getW() . "|" . $this->_vtcW->getW() . "\n"; 
        }
        //create vertex
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

    private function scaling($factor)
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => $factor,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => 0,
                'y' => $factor,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => $factor,
                'w' => 0,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ])
            ]));
    }

    private function translate($translation)
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => 1,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => 0,
                'y' => 1,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => 1,
                'w' => 0,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => $translation->getX(),
                    'y' => $translation->getY(),
                    'z' => $translation->getX(),
                    'w' => 1,
                ])
            ]));
    }

    private function identity()
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => 1,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => 0,
                'y' => 1,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => 1,
                'w' => 0,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ])
            ]));
    }

    private function rotate_x($angle)
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => 1,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => 0,
                'y' => cos($angle),
                'z' => sin($angle),
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => 0,
                'y' => -sin($angle),
                'z' => cos($angle),
                'w' => 0,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ])
            ]));
    }
    private function rotate_y($angle)
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => cos($angle),
                'y' => 0,
                'z' => -sin($angle),
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => 0,
                'y' => 1,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => sin($angle),
                'y' => 0,
                'z' => cos($angle),
                'w' => 0,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ])
            ]));
    }

    private function rotate_z($angle)
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => cos($angle),
                'y' => sin($angle),
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => -sin($angle),
                'y' => cos($angle),
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => 1,
                'w' => 0,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => 0,
                    'w' => 1,
                ])
            ]));
    }
    
    private function projection($angle, $ratio, $far, $near)
    {
        $this->$_vtcX = (new Vector ([
            'dest' => new Vertex([
                'x' => atan($angle / 2) / $ratio,
                'y' => 0,
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcY = (new Vector ([
            'dest' => new Vertex([
                'x' => 0,
                'y' => atan($angle / 2),
                'z' => 0,
                'w' => 0,
                ])
            ]));
        $this->$_vtcZ = (new Vector ([
                'dest' => new Vertex([
                'x' => 0,
                'y' => 0,
                'z' => -(($far + $near) / ($far - $near)),
                'w' => -1,
                ])
            ]));
        $this->$_vtcW = (new Vector ([
                'dest' => new Vertex([
                    'x' => 0,
                    'y' => 0,
                    'z' => ((-2 * $far * $near) / ($far - $near)),
                    'w' => 0,
                ])
            ]));
    }

    public function matrix_mult(Matrix $rhs)
    {
        return (new Matrix([
			'x' => new Vertex([
				'x' => self::dotProduct($this->_x, $rhs->getvtcX()),
				'y' => self::dotProduct($this->_x, $rhs->getvtcY()),
				'z' => self::dotProduct($this->_x, $rhs->getvtcZ()),
				'w' => self::dotProduct($this->_x, $rhs->getvtcW())
			]),
			'y' => new Vertex([
				'x' => self::dotProduct($this->_y, $rhs->getvtcX()),
				'y' => self::dotProduct($this->_y, $rhs->getvtcY()),
				'z' => self::dotProduct($this->_y, $rhs->getvtcZ()),
				'w' => self::dotProduct($this->_y, $rhs->getvtcW())
			]),
			'z' => new Vertex([
				'x' => self::dotProduct($this->_z, $rhs->getvtcX()),
				'y' => self::dotProduct($this->_z, $rhs->getvtcY()),
				'z' => self::dotProduct($this->_z, $rhs->getvtcZ()),
				'w' => self::dotProduct($this->_z, $rhs->getvtcW())
			]),
			'w' => new Vertex([
				'x' => self::dotProduct($this->_w, $rhs->getvtcX()),
				'y' => self::dotProduct($this->_w, $rhs->getvtcY()),
				'z' => self::dotProduct($this->_w, $rhs->getvtcZ()),
				'w' => self::dotProduct($this->_w, $rhs->getvtcW())
			])
		]));
    } 
/** Accessor */
    public function getVtcX()
    {
        return ($this->$_vtcX);
    }

    public function getVtcY()
    {
        return ($this->$_vtcY);
    }

    public function getVtcZ()
    {
        return ($this->$_vtcZ);
    }

    public function getVtcW()
    {
        return ($this->$_vtcW);
    }

}