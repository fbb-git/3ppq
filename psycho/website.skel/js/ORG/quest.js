function validate() 
{
    document.forms["form"]["nr"].value -= 2;

//    if (val == 1 && !('1' <= answer && answer <= '5'))
//    {
//        alert("U heeft de vraag nog niet beantwoord.");
//        return false;
//    }

    addHidden('type',   'client');
    addHidden('state',  'quest');
    return true;
} 


function answered() 
{
    addHidden('type',   'client');
    addHidden('state',  'quest');

    document.form.submit();
} 








