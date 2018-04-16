function validate(action) 
{
    var state = 
        [ 
            "clientPage", 
            "dataPage", 
            "profilePage", 
            "contactPage" 
        ];

    if (action < 1 || action > 4 )
    {
        window.open('/index.html', '_self'); 
        return false;
    }

    addHidden("state",  state[action - 1]);
    addHidden("type",   "psych");

    document.getElementsByName('form')[0].submit();
} 

