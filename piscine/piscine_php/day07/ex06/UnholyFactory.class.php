<?php
class UnholyFactory
{
    public function absorb($fighter) {
        if (is_a($fighter, Fighter))
        {
            $class = get_class($fighter);
            echo ("(Factory absorbed a fighter of type" . $class->type . ")");
        }
        else
            echo ("(Factory can't absorb this, it's not a fighter)\n");
    }

    public function fabricate($fighter) {
        $this->fighter[] = $fighter; 
        return (new $this->figther);
    }
}