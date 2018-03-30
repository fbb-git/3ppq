var nr = 0;

function validate() 
{
    var mail = document.forms["form"]["email"].value;

    switch (nr)
    {
        case 0:
            addHidden('state', 'register');
        break;

        case 1:
            if (mail == "") 
            {
                alert("E-mail adress moet worden vermeld");
                return false;
            }
            addHidden('state', 'noPwd');
        break;

        case 2:     // inloggen: UN/PW vereist
            if (mail == "" || 
                document.forms["form"]["pwd"].value == ""
            )
            {
                alert("E-mail en password moeten worden vermeld");
                return false;
            }
            addHidden('state', 'login');
        break;
    }
    return true;
} 








