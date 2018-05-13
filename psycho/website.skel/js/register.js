function validate(type) 
{
    if (type == 0)
        return true;

    var form = document.forms["form"];

    var name =      form["name"].value;
    var lastName =  form["lastName"].value;
    var email =     form["email"].value;
    var nip =       form["nip"].value;
    var pwd =       form["pwd"].value;
    var pwd2 =      form["pwd2"].value;
    var field =     form["field"].value;

    if (name == "" || lastName == "" || email == "" || nip == 0 ||
        pwd == "" || pwd2 == "")
    {
        alert("Alle velden moeten zijn ingevuld");
        return false;
    }

    if (!pwdCheck(pwd))
        return false;

    if (pwd != pwd2)
    {
        alert("De passwords verschillen: ze moeten gelijk zijn");
        return false;
    }

    addHidden("type",   "psych");
    addHidden("state",  "addPsych");

    return true;
} 



