function validate() 
{
    var form = document.forms["form"];
//

//    var one =      form["one"].value;

//    var nr1 = document.forms["form"]["nr1"].value;
//    var nr2 = document.forms["form"]["nr2"].value;
//
//    if (nr1 == "" || nr2 == "")
//    {
//        alert("Vermeld beide inlogcodes s.v.p");
//        return false;
//    }

    addHidden('type', 'client');
    addHidden('state', 'verify');

    alert('client validation' + nr1 + ' ' + nr2);


    return false;
} 








