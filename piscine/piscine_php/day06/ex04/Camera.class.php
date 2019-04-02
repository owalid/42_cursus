<?php

class Camera {

    public static $verbose = FALSE;
    
    
    public fucntion __construct()
    {
        if (self::$verbose === TRUE)
        {
          
        }
    }
    
    public function __destruct()
    {
        if (self::$verbose === TRUE)
        {
           
        }
    }

    public static function	doc ()
	{
		readfile('Camera.doc.txt');
	}
}