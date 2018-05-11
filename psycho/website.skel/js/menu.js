function validate(action) 
{
    alert("localStorage.eMail: " + localStorage.eMail);

    if (action == 0)
        return true;

    addHidden("email",  localStorage.eMail);
    addHidden("state",  action);
    addHidden("type",   "psych");

    document.getElementsByName('form')[0].submit();
} 

