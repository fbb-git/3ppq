function validate(action) 
{
    addHidden("email",  localStorage.eMail);
    addHidden("state",  action);
    addHidden("type",   "psych");

    document.getElementsByName('form')[0].submit();
} 

