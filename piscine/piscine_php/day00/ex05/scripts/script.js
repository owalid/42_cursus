document.getElementById("avancer").addEventListener("click", myFunction);
var i = 0.1;
var cluster = document.getElementById("cluster");
var win = document.getElementById("win");
document.getElementById("reload").addEventListener("click", reload);
document.getElementById("norminet").addEventListener("click", norminet);

function reload(){
    location.reload(true);
}

function myFunction() {
    if (cluster)
    {

        i += 0.1;
        if (i == 1.0999999999999999)
        {
            alert("Est tu sur de ce que tu fait ???");
            i += 0.1;
        }
        if (i !== 1 && i <= 1.1) {
            cluster.style.transform = "scale(" + i +")";
        }
        else {
            window.location.href = 'pages/game_monster.html';
        } 
    }
    else{
        alert("Laisse les monstres tranquille");
    }
}

function norminet() {
    document.getElementById("miaou").style.display = "";
}

