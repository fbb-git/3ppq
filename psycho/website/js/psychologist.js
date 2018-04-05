var nr = 0;

function validate() 
{
    var nip = document.forms["form"]["nip"].value;

    alert(" nr = " + nr);

    switch (nr)
    {
        case 0:
            addHidden('state', 'registration');
        break;

        case 1:
            if (nip == "") 
            {
                alert("Uw NIP-nummer moet worden vermeld");
                return false;
            }
            addHidden('state', 'noPwd');
        break;

        case 2:     // inloggen: UN/PW vereist
            if (nip == "" || 
                document.forms['form']['pwd'].value == ""
            )
            {
                alert("NIP-nummer en password moeten worden vermeld");
                return false;
            }
            addHidden('state', 'login');
        break;
    }
    addHidden('type', 'psychologist');
    return true;
} 








