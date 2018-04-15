window.onload = setFields();

function setFields()
{
    if (fields & 1)
        document.getElementById("c1").checked = true;
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

function validate() 
{
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
        pwd == "" || nip == "")
    {
        alert("Naam, NIP-nummer, e-mail en\n" + 
              "huidig wachtwoord moeten zijn ingevuld");
        return false;
    }

    if (newpwd != newpwd2)
    {
        alert("Het nieuwe wachtwoord moet gelijk zijn aan de verificatie");
        return false;
    }

    addHidden("type",   "psych");
    addHidden("state",  "udateProfile");

    return true;
} 

function key(event)
{
    var enter = event.which || event.keyCode;
    if (enter == 13 && validate())
        document.getElementsByName('form')[0].submit();
}
