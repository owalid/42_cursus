<?php
require_once 'Vertex.class.php';
class Vector
{
    private $_x = 1.0;
    private $_y = 1.0;
    private $_z = 1.0;
    private $_w = 0.0;
    public static $verbose = False;

    public function	__construct(array $elmts)
    {
        if (is_a($elmts['dest'], Vertex))
        {
            if (is_a($elmts['orig'], Vertex))
            {
                $this->_x = $elmts['dest']->getX() - $elmts['orig']->getX();
                $this->_y = $elmts['dest']->getY() - $elmts['orig']->getY();
                $this->_z = $elmts['dest']->getZ() - $elmts['orig']->getZ();
                $this->_w = $elmts['dest']->getW() - $elmts['orig']->getW();
            }
            else
            {
                $default_vertex = new Vertex(['x' => 0, 'y' => 0, 'z' => 0]);
                $this->_x = $elmts['dest']->getX() - $default_vertex->getX();
                $this->_y = $elmts['dest']->getY() - $default_vertex->getY();
                $this->_z = $elmts['dest']->getZ() - $default_vertex->getZ();
                $this->_w = $elmts['dest']->getW() - $default_vertex->getW();
            }
            if (self::$verbose === TRUE)
                printf("Vector( x: %.2f, y: %.2f, z: %.2f, w: %.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
        }
    }

    public function __destruct() {
		if (self::$verbose === TRUE)
            printf("Vector( x: %.2f, y: %.2f, z: %.2f, w: %.2f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
	}

    public function __toString()
    {
        $return =  sprintf("Vector( x: %.2f, y: %.2f, z: %.2f, w: %.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
        return $return;
    }
    
    public static function	doc() {
        $file = file_get_contents('Vertex.doc.txt');
        return ($file);
    }
    
    /** retourne la longueur (ou "norme") du vecteur */
    public  function magnitude() {
        return (sqrt(
			$this->_x * $this->_x + 
			$this->_y * $this->_y + 
			$this->_z * $this->_z
		));
    }
    
    /** retourne le vecteur normalisé. Si le vecteur est déja nor-malisé, retourne une copie fraiche du vecteu */
    public function normalize() {
        $magnitude = abs($this->magnitude());
        return (new Vector([
			'dest' => new Vertex([
			'x' => $this->_x / $magnitude,
			'y' => $this->_y / $magnitude,
			'z' => $this->_z / $magnitude,
			])
		]));
    }

    /** retourne le vecteur somme des deux vecteurs. */
    public function add(Vector $rhs) {
        return (new Vector([
			'dest' => new Vertex([
				'x' => $this->_x + $rhs->_x,
				'y' => $this->_y + $rhs->_y,
				'z' => $this->_z + $rhs->_z,
			])
		]));
    }

    /** retourne le vecteur difference des deux vecteurs. */
    public function sub(Vector $rhs) {
        return (new Vector([
            'dest' => new Vertex([
                'x' => $this->_x - $rhs->_x,
				'y' => $this->_y - $rhs->_y,
				'z' => $this->_z - $rhs->_z,
            ])
        ]));
    }

    /** retourne le vecteur opposé. */
    public function opposite() {
        return (new Vector([
            'dest' => new Vertex([
                'x' => $this->_x * -1,
				'y' => $this->_y * -1,
				'z' => $this->_z * -1,
            ])
        ]));
    }

    /** retourne le produit du vecteur avec un scalaire. */
    public function scalarProduct($k) {
        $k = intval($k);
        return (new Vector([
			'dest' => new Vertex([
				'x' => $this->_x * $k,
				'y' => $this->_y * $k,
				'z' => $this->_z * $k,
			])
		]));
    }

    /** retourne le produit scalaire de deux vecteurs */
    public function dotProduct(Vector $rhs) {
        return  (float) $this->_x * $rhs->_x + $this->_y * $rhs->_y + $this->_z * $rhs->_z;
    }

    /** retourne le cosinus de l’angle entre deux vecteurs. */
    public function cos(Vector $rhs) {
        return (
            (float) ($this->_x * $rhs->_x + $this->_y * $rhs->_y + $this->_z * $rhs->_z) 
            / sqrt(($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z) * ($rhs->_x * $rhs->_x + $rhs->_y * $rhs->_y + $rhs->_z * $rhs->_z))
        );
    }

    /** retourne le produit en croix de deux vecteurs (repère main droite !) */
    public function crossProduct(Vector $rhs) {
        return (new Vector(
            ['dest' => new Vertex([
                'x' => $this->_y * $rhs->_z - $this->_z * $rhs->_y,
                'y' =>	$this->_z * $rhs->_x - $this->_x * $rhs->_z,
                'z' => 	$this->_x * $rhs->_y - $this->_y * $rhs->_x,
            ])
        ]));
    }

/** accessor */
    public function getX() {
        return ($this->_x);
    }
    public function getY() {
        return ($this->_y);
    }
    public function getZ() {
        return ($this->_z);
    }
    public function getW() {
        return ($this->_w);
    }
}