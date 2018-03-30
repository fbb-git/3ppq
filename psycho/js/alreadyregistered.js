var nr = 0;

function validate() 
{
    if (nr == 1)
    {
        addHidden("type",   "psychologist");
        addHidden("state",  "register");
        return true;
    }

    window.open("/", "_self");
    return false;
} 

