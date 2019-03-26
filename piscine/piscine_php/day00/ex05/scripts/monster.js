alert("Des monstres debarques tue les !");

var count_down = document.getElementById("countDown");
var terrain = document.getElementById('terrain_de_jeu')
var monstreElement = document.querySelectorAll('.monstre')[0]
var score_elmt = document.getElementById("score-div");
var i = 3;

var timeout = setInterval(function(){
    count_down.innerHTML = i; 
    i -= 1;
    if (i === -1) {
        clearInterval(timeout);
        count_down.innerHTML = "";
        terrain.style.display = "";
        monstreElement.style.display = "";
        score_elmt.style.display = "";
    }
}, 700);
    
    /////////// La "classe" Monstre //////////////
    
    // le constructeur de monstres (équivalent de la classe Monstre)
    function Monstre(){
        // clone monstreElement et le place sur le terrain
        this.element=monstreElement.cloneNode(true);
        terrain.appendChild(this.element);
        
        // valeurs maximales et minimales pour element.style.top et element.style.right
        this.topMax = terrain.offsetHeight-this.element.offsetHeight;
        this.topMin = 0;
        this.leftMax = terrain.offsetWidth-this.element.offsetWidth;
        this.leftMin = 0;
        
        // Place le nouveau monstre aléatoirement				
        this.top=this.distanceAleatoire('top');
        this.left=this.distanceAleatoire('left');
        var style=this.element.style;
        style.top=this.top+'px';
        style.left=this.left+'px';
        
        // toMonstre permet d'obtenir l'objet Monstre lorsqu'on ne connaît que l'élément DOM monstre.
        // On s'en sert dans le gestionnaire du click sur un monstre.
        this.element.toMonstre = this;
        
        // création du compte à rebours
        this.timer = setTimeout(function() {
            fin_du_jeu(this.score.valeur);
        }, 15000);

        this.element.addEventListener('click', function() {
            var monstre = this.toMonstre
            score.ajoute(1);
            clearTimeout(monstre.timer); // Le compte à rebours est annulé
            this.remove();
        });
        
        //On ajoute la prise en compte de l'age
        this.age = setTimeout(function(){style.backgroundColor='red'}, 3500);
    }
    
    // Retourne une distance aléatoire comprise enre les valeurs ci-dessus. 
    // cote :  "top" ou "left"
    Monstre.prototype.distanceAleatoire = function(cote) {
        var max = this[cote+'Max'];
        var min = this[cote+'Min'];
        return Math.floor(Math.random() * (max - min + 1) + min);
    }
    ////////////////// Initialisation du jeu //////////////
                
    // cache le monstre initial en le détachant du DOM
    terrain.removeChild(monstreElement)
    
    // création des monstres
    for (var i = 0 ; i < 5 ; i++){
        var monstre = new Monstre
    }
    
    /////////////////// Gestion du temps ////////////////////
    
    var horloge;	// timer global
    var temps = 0;	// compte le nombre de fois que horloge s'est déclenchée
    var ticTac = 500;	// durée en ms entre chaque déclenchement de l'horloge
    
    // Fonction éxecutée à chaque déclenchement de l'horloge
    function action(){
        temps += 1;
        if (temps %2 == 0) new Monstre;
        // relance horloge. On aurait pu utiliser setInterval.
        horloge = setTimeout(function() { 
            action();
        }, ticTac);
    }
    action();
    
    //////////////// gestion du score ///////////////////////////////
    var score ={
        valeur : 0,
        element : document.getElementById('score'),
        ajoute : function(points){
            this.valeur += points;
            this.element.innerHTML = this.valeur;
        }
    } 

    /////////////// Gestion de la fin du jeu /////////////////////////
    var jeu_fini = false;  
    function fin_du_jeu(score) {
        if (!jeu_fini) {
            if (score >= 10) {
                jeu_fini = true;
                alert('bravo tu es notre grand gagnant');
                clearTimeout(horloge);
                window.location.href = '../pages/win.html';
            }
            else {
                alert('Perdu tu es trop lent :(!!');
                clearTimeout(horloge);
                location.reload(true);
            }
        }
    }
    

