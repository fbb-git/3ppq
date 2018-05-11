function validate(action) 
{
    localStorage.eMail = document.forms["form"]['email'].value;

    addHidden("state",  action);
    addHidden("type",   "psych");

    document.getElementsByName('form')[0].submit();
} 

