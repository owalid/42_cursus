
imgj1_haut = new Image();
imgj1_bas = new Image();
imgj1_gauche = new Image();
imgj1_droite = new Image();

imgj1_haut.src = "../sprite/J1/spriteJ1_haut.png";
imgj1_bas.src = "../sprite/J1/spriteJ1_bas.png";
imgj1_gauche.src = "../sprite/J1/spriteJ1_gauche.png";
imgj1_droite.src = "../sprite/J1/spriteJ1_droite.png";

imgj2_bas = new Image();
imgj2_haut = new Image();
imgj2_droite = new Image();
imgj2_gauche = new Image();

imgj2_bas.src = "../sprite/J2/spriteJ2_bas.png";
imgj2_haut.src = "../sprite/J2/spriteJ2_haut.png";
imgj2_droite.src = "../sprite/J2/spriteJ2_droite.png";
imgj2_gauche.src = "../sprite/J2/spriteJ2_gauche.png";

rock = new Image();
rock.src = "../sprite/rock.png";
window.onload = function () {
    var canvas = document.getElementById("zone_jeux");
    var ctx = canvas.getContext("2d");
ctx.canvas.width  = 1500;
ctx.canvas.height = 1500;
for (var h = canvas.height / 100; h <= canvas.height; h += canvas.height / 100) {
    ctx.moveTo(0, h);
    ctx.lineTo(canvas.width, h);
}
for (var w = canvas.width / 150; w <= canvas.width; w += canvas.width / 150) {
    ctx.moveTo(w, 0);
    ctx.lineTo(w, canvas.height);
}
ctx.stroke();
for (var i = 0; i < 150; i++)
{
    for (var j = 0; j < 100; j++)
    {
        if (zone[i][j] == 1)
        {
            console.log('coucou')
            ctx.drawImage(imgj1_bas, i * (canvas.width / 150), j * (canvas.height / 100), canvas.height / 10, canvas.width / 10);
        }
        else if (zone[i][j] == 2)
        {
            ctx.drawImage(imgj2_haut,  i * (canvas.width / 150), j * (canvas.height / 100), canvas.height / 10, canvas.width / 10);
        }
        else if (zone[i][j] === 3)
        {
            ctx.drawImage(rock, i * (canvas.width / 150), j * (canvas.height / 100), canvas.height / 10, canvas.width / 10);
        }
    }
}
}