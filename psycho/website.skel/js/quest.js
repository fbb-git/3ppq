var val = 0;

function validate() 
{
    var answer = document.forms["form"]["answer"].value;

    if (val == 1 && !('1' <= answer && answer <= '5'))
    {
        alert("U heeft de vraag nog niet beantwoord.");
        return false;
    }

    addHidden('type',   'client');
    addHidden('state',  'quest');
    return true;
} 








