<?php
define('INC_PATH', 'php/class/');
require_once(INC_PATH . 'vaisseaux/CuirasseImperial.class.php');
require_once(INC_PATH . 'vaisseaux/VessoAttackRavajeur.class.php');
require_once(INC_PATH . 'vaisseaux/FregateImperial.class.php');

require_once(INC_PATH . 'VaisseauxFactory.class.php');
require_once(INC_PATH . 'Joueur.class.php');
// require_once(INC_PATH . 'ZonedeJeux.class.php');
    if (isset($_GET['joueur1']) && isset($_GET['joueur2']))
    {
    //todo preset for create vaisseaux
        
    /* preset J1 for vaisseaux*/
    $presetJ1 = ["positionX" => 10,
                "positionY" => 10,
                "orientation" => 3,
                "taille" => 150,
                "sprite" => "/sprite/spriteJ1.png",
                "puissancemot" => 150,
                "pointcoque" => 100,
                "vitesse" => 30,
                "bouclier" => 20];
    
        /* preset J2 for vaisseaux*/
        $presetJ2 = ["positionX" => 90,
        "positionY" => 90,
        "orientation" => 3,
        "taille" => 150,
        "sprite" => "/sprite/spriteJ2.png",
        "puissancemot" => 150,
        "pointcoque" => 100,
        "vitesse" => 30,
        "bouclier" => 20];
        
        /** create vaisseaux */
        $cuirJ1 = new CuirasseImperial($presetJ1);
        $varJ1 = new VessoAttackRavajeur($presetJ1);
        $fimperJ1 = new FregateImperial($presetJ1);
        $vaissaux_factory = new VaisseauxFactory();
        $vaissaux_factory->absorb($cuirJ1, 1);
        $vaissaux_factory->absorb($varJ1, 1);
        $vaissaux_factory->absorb($fimperJ1, 1);
        
        $cuirJ2 = new CuirasseImperial($presetJ2);
        $varJ2 = new VessoAttackRavajeur($presetJ2);
        $fimperJ2 = new FregateImperial($presetJ2);
        $vaissaux_factory->absorb($cuirJ2, 2);
        $vaissaux_factory->absorb($varJ2, 2);
        $vaissaux_factory->absorb($fimperJ2, 2);
        
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
        
        $actual_vaissauxJ1 = [];
        $actual_vaissauxJ2 = [];
        
        foreach ($vaissaux_J1 as $vJ1) {
            $f1 = $vaissaux_factory->fabricateJ1($vJ1, $presetJ1);
            if ($f1 != null) {
                $actual_vaissauxJ1[$f1->getType()] = $f1;
            }
        }
        // var_dump($actual_vaissauxJ1);die();
        foreach ($vaissaux_J2 as $vJ2) {
            $f2 = $vaissaux_factory->fabricateJ2($vJ2, $presetJ2);
            if ($f2 != null) {
                $actual_vaissauxJ2[$f2->getType()] = $f2;
            }
        }
        
        $joueur1 = new Joueur($_GET['joueur1'], $actual_vaissauxJ1);
        $joueur2 = new Joueur($_GET['joueur2'], $actual_vaissauxJ2);
        $zone_de_jeux = new ZonedeJeux(["joueur1" => $joueur1,
        "joueur2" => $joueur2]);
        
        //set session for the game
        session_start();
        $_SESSION['zone'] = $zone_de_jeux;
        $_SESSION['tour'] = 20;
        $_SESSION['joueur1'] = $joueur1;
        $_SESSION['joueur2'] = $joueur2;
        
        $random = rand(1, 2);
        if ($random === 1)
            $_SESSION['joueur'] = $joueur1;
        else
            $_SESSION['joueur'] = $joueur2;
    }
    if (isset($_POST['name_vaisseaux']) && (isset($_POST['actionO']) || isset($_POST['actionM'])
        && $_POST['submit'] === "Jouer"))
        {
            session_start();
            if ($_SESSION['joueur'] === $_SESSION['joueur1'])
            $joueur = 1;
            if ($_SESSION['joueur'] === $_SESSION['joueur2'])
            $joueur = 2;
            $_SESSION['joueur']->setpP(3);
            if (isset($_POST['actionM']))
                $_SESSION['joueur']->getVaisseaux()[0][$_POST['name_vaisseaux']]->mouvement($_POST['actionM'], 5, $_SESSION['zone'], $joueur);
            if (isset($_POST['actionO']))
                $_SESSION['joueur']->getVaisseaux()[0][$_POST['name_vaisseaux']]->ordre(["ordre" => $_POST['actionO'], "des" => 5, "zone" => $_SESSION['zone']]);
            $_SESSION['tour']--;
            header("Location: index.php?change=true");
        }
    if (isset($_GET['change']))
    {
        session_start();
        //changer de joueur
        if ($_SESSION['joueur'] == $_SESSION['joueur1'])
            $_SESSION['joueur'] = $_SESSION['joueur2'];
        if ($_SESSION['joueur'] == $_SESSION['joueur2'])
            $_SESSION['joueur'] = $_SESSION['joueur1'];
    }
    else
    {

    }
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Warhammer 42</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
    <script>
        console.log("ici");
        var zone = <?= $_SESSION['zone']->getZone(); ?>
</script>
    <script type="text/javascript" src="script/script.js"></script>
</head>
    <body>
        <canvas id="zone_jeux"></canvas>
        <?php
        session_start(); 
        if ($_SESSION['tour'])
        {
    ?>
    <h1> il reste <?= $_SESSION['tour'] ?> tours</h1>
        <form method="POST" action="index.php">
            <p>C'est au tour de <?= $_SESSION['joueur']->getName(); ?></p><br />
            <p>Tu as encore <?= $_SESSION['joueur']->getpP(); ?> Pp </p>
            <p> Tu dois selectionner un vaisseaux </p>
            <select name="name_vaisseaux" size="3" required>
                <?php 
                    session_start();
                    foreach($_SESSION['joueur']->getVaisseaux()[0] as $vaisseaux)
                    {
                        ?> <option><?= $vaisseaux->getType();?></option>
                    <?php
                    } ?>
            </select> <br />
            <p>Selectionner une action</p><br />
            <p>Ordre</p>
            <select id="vaisseauxO" name="actionO" size="3" required>
                <option>VITESSE</option>
                <option>BOUCLIER</option>
                <option>TIR</option>
            </select>
            <p>Mouvement</p>
            <select id="vaisseauxM" name="actionM" size="3" required>
                <option>AVANCER</option>
                <option>GAUCHE</option>
                <option>DROITE</option>
                <option>RECULER</option>
            </select>
            <input type="submit" value="Jouer">
        </form>
    <?php
        }
        else
        { 
    ?>
            <p> La partie est finie </p>
    <?php
        }
    ?> 
   
    </body>
</html>