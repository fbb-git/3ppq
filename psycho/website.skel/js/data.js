function getData() 
{
    addHidden("email",  localStorage.eMail);
    addHidden("state",  'getData');
    addHidden("type",   "psych");

    document.getElementsByName('form')[0].submit();
} 

