<?php
    if (isset($_GET['joueur1']) && isset($_GET['joueur2']))
    {
        $joueur1 = new Joueur($_GET['joueur1']);
        $joueur2 = new Joueur($_GET['joueur2']);
        $zone_de_jeux = new ZonedeJeux(["joueur1" => $joueur1,
                                        "joueur2" => $joueur2]);
        


    //todo preset for create vaisseaux

        /** create vaisseaux */
        $cuirJ1 = new CuirasseImperial();
        $varJ1 = new VessoAttackRavajeur();
        $fimperJ1 = new FregateImperial();
        $vaissaux_factory = new VaisseauxFactory();
        $vaissaux_factory->absorb($cuirJ1, $joueur1);
        $vaissaux_factory->absorb($varJ1, $joueur1);
        $vaissaux_factory->absorb($fimperJ1, $joueur1);


        
        $cuirJ2 = new CuirasseImperial();
        $varJ2 = new VessoAttackRavajeur();
        $fimperJ2 = new FregateImperial();
        $vaissaux_factory->absorb($cuirJ2, $joueur1);
        $vaissaux_factory->absorb($varJ2, $joueur1);
        $vaissaux_factory->absorb($fimperJ2, $joueur1);
        
        $vaissaux_J1 = Array(
            "CuirasseImperial",
            "FregateImperial",
            "VessoAttackRavajeur",
        );

        $vaissaux_J2 = Array(
            "CuirasseImperial",
            "FregateImperial",
            "VessoAttackRavajeur",
        );
        
        $actual_vaissauxJ1 = Array(
        );
        $actual_vaissauxJ2 = Array(
        );
        
        foreach ($vaissaux_J1 as $vJ1) {
            $f = $vaissaux_factory->fabricateJ1($vJ1);
            if ($f != null) {
                array_push($actual_vaissauxJ1, $f);
            }
        foreach ($vaissaux_J2 as $vJ2) {
            $f = $vaissaux_factory->fabricateJ2($vJ2);
            if ($f != null) {
                array_push($actual_vaissauxJ2, $f);
            }
        }
    }
    $tour = 20;
    while ($tour)
    {
        //todo phases

        $random = rand(1, 2);
        if ($random === 1)
            $joueur1->setGame(true);
        else
            $joueur2->setGame(true);
//joueur1
        while ($joueur1->getGame() === true)
        {
            $joueur2->setGame(true);
            $joueur1->setGame(false);
        }
//joueur2
        while ($joueur2->getGame() === true)
        {
            $joueur1->setGame(true);
            $joueur2->setGame(false);
        }
        $tour--;
    }
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Warhammer 42</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
</head>
<body>
    <div id="zone_jeux"></div>
</body>
<script>
    var game = <?= $zone_de_jeux->getZone(); ?>
</script>
</html>