var psychMenu = 
    [ 
        "/index.html",          // 0
        "/client.html",         // 1
        "/profile.html",        // 2
        "/data.html",           // 3
        "/contact.html"         // 4
    ];

function psychAction(action)
{
    if (action < 1 || action > 4)
        action = 0;

    window.open(psychMenu[action], '_self');
}
