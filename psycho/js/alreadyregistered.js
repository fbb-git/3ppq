var nr = 0;

function validate() 
{
    addHidden("type",   "psychologist");

    switch (nr)
    {
        case 1:
            addHidden("state",  "registration");
        return true;

        case 2:
            addHidden("state", "login");
        return true;
    }


    window.open("/", "_self");
    return false;
} 

