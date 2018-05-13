var nr;

function validate(type) 
{
    if (type == 0)
        return true;

    var email = document.forms["form"]["email"].value;

    switch (nr)
    {
        case 1:
            if (email == "") 
            {
                alert("Uw e-mail adres moet worden vermeld");
                return false;
            }
            addHidden('mode', 'noPwd');
        break;

        case 2:     // inloggen: UN/PW vereist
            if (email == "" || 
                document.forms['form']['pwd'].value == ""
            )
            {
                alert("e-mail adres en password moeten worden vermeld");
                return false;
            }
            addHidden('mode', 'login');
        break;
    }
    addHidden('state', 'verify');
    addHidden('type', 'psych');
} 








