var parentElmt = document.getElementById('ft_list');
var newNote = document.getElementById('new');
var del = document.getElementById('del');

newNote.addEventListener("click", () => {
    let prompt = window.prompt();
    if (prompt != null)
        addElement(prompt, parentElmt);
})

function addElement (text, parentElmt) { 
    var newDiv = document.createElement("div");
    newDiv.setAttribute("class", "del");
    newDiv.textContent = text;
    newDiv.addEventListener("click", () => {
        var rep = confirm("T sur ?!");
        if (rep == true) newDiv.remove();
    });
    parentElmt.prepend(newDiv);
}


