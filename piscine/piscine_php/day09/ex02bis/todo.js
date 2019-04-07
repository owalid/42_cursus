var parentElmt = $('#ft_list');
var newNote = $('#new');

newNote.click(() => {
    let prompt = window.prompt();
    if (prompt != null)
    {
        var newDiv = $("<div>" + prompt + "</div>");
        parentElmt.prepend(newDiv);
        newDiv.click( () => {
            if (confirm("T sur ?!") == true) newDiv.remove();
        });
    }
})