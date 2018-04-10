function validate(nr) 
{
    var nip = document.getElementsByName("nip")[0].value;

    addHidden("type",   "psych");

    switch (nr)
    {
        case 1:
            addHidden("state",  "client");
        break;
    }

    addHidden("nip",    nip);

    return true;
} 

