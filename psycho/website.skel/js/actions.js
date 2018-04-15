function validate(action) 
{
    addHidden("action", action); 
    addHidden("state",  "actions");
    addHidden("type",   "psych");

    document.getElementsByName('form')[0].submit();
} 

