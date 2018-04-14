function validate() 
{
    var form = document.forms["form"];

    var name =      form["name"].value;
    var lastName =  form["lastName"].value;
    var gender =    form["gender"].value;
    var email =     form["email"].value;
    var pwd =       form["pwd"].value;
    var pwd2 =      form["pwd2"].value;
    var field =     form["field"].value;

    if (name == "" || lastName == "" || email == "" || gender == "" ||
        pwd == "" || pwd2 == "")
    {
        alert("Alle velden moeten zijn ingevuld");
        return false;
    }

    if (pwd != pwd2)
    {
        alert("De passwords verschillen: ze moeten gelijk zijn");
        return false;
    }

    addHidden("type",   "psych");
    addHidden("state",  "addPsych");

    return true;
} 

