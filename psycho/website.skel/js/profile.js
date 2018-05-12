function setFields()
{
    if (fields & 1)
        document.getElementById("c").checked = true;
    if (fields & 2)
        document.getElementById("c2").checked = true;
    if (fields & 4)
        document.getElementById("c4").checked = true;
    if (fields & 8)
        document.getElementById("c8").checked = true;
    if (fields & 16)
        document.getElementById("c16").checked = true;
}

var goHome = 1;

function home()
{
    if (goHome)
        window.open('/index.html', '_self'); 
    goHome = 1;
    return false;
}

function validate(action) 
{
    if (action == 0)
        return true;

    addHidden("type",   "psych");
    addHidden("email",  localStorage.eMail);

    if (action != 'submit')
    {
        addHidden("state",  action);
        document.getElementsByName('form')[0].submit();
        return;
    }

    goHome = 0;

    var form = document.forms["form"];

    var name =      form["name"].value;
    var lastName =  form["lastName"].value;
    var newemail =  form["newemail"].value;
    var newpwd =    form["newpwd"].value;
    var newpwd2 =   form["newpwd2"].value;
    var field =     form["field"].value;
    var pwd =       form["pwd"].value;
    var nip =       form["nip"].value;

    if (name == "" || lastName == "" || newemail == "" || 
        pwd == "" || nip == 0)
    {
        alert("Naam, NIP-nummer, e-mail en\n" + 
              "huidig wachtwoord moeten zijn ingevuld");
        return false;
    }

    if (newpwd != "" && !pwdCheck(newpwd))
        return false;
        
    if (newpwd != newpwd2)
    {
        alert("Het nieuwe wachtwoord moet gelijk zijn aan de verificatie");
        return false;
    }

    addHidden("state",  "profile");
    document.getElementsByName('form')[0].submit();
} 

function key(event)
{
    var enter = event.which || event.keyCode;
    if (enter == 13 && validate('submit'))
        document.getElementsByName('form')[0].submit();
}


