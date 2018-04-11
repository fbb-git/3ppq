var nr;
var forced = 0;

function inspect(key)
{
    if (key == 13)
        forced = 1;
}


function validate() 
{
    var nip = document.forms["form"]["nip"].value;

    if (forced == 1)
        nr = 2;

    switch (nr)
    {
        case 0:
            addHidden('state', 'signup');
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
            addHidden('state', 'verify');
        break;
    }
    addHidden('type', 'psych');
    return true;
} 








