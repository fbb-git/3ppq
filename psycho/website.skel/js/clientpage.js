var clientID;
var actionDescr = "(deze client toevoegen)";

function showTime()
{
    document.getElementById('time2').style.display = 'table-cell';
    document.getElementById('time1').style.display = 'table-cell';
}

function hideTime()
{
    document.getElementById('time1').style.display = 'none';
    document.getElementById('time2').style.display = 'none';
}

function showActive()
{
    document.getElementById('check2').style.display = 'table-cell';
    document.getElementById('check1').style.display = 'table-cell';
}

function hideActive()
{
    document.getElementById('check1').style.display = 'none';
    document.getElementById('check2').style.display = 'none';
}

function actionText()
{
    document.write(actionDescr);
}

function resetFields()
{
    var form = document.forms["form"];

    form['ID'].value = nClients;           
    form['name'].value = "";
    form['lastName'].value = ""
    form['email'].value = "";
    form['login0'].value = login0;

    form['action'].value = "Toevoegen";
    actionDescr = "(deze client toevoegen)";
    
    form['request'].value = "add";
    form['activate'].value = 0;

    showActive();
    hideTime();
    actionText();

    return false;
}

function update()
{
    var form = document.forms["form"];
    var nr = document.getElementById("selectID").value;

    form['ID'].value = clients[nr][0];
    form['name'].value = clients[nr][3];
    form['lastName'].value = clients[nr][4];
    form['email'].value = clients[nr][5];
    form['login0'].value = clients[nr][2];

    form['action'].value = "Wijzigen";
    actionDescr = "(gegevens wijzigen)";
    actionText();

    form['request'].value = "update";
    form['activate'].value = document.getElementById('active').value;
}

function showDate()
{
    var date = new Date(clients[clientID][1] * 1000);
    var months = 
        ['jan','feb','mar','apr','mei','jun',
         'jul','aug','sep','oct','nov','dec'];
    document.write(date.getDate() + ' ' + months[date.getMonth()] + ' ' +
           date.getFullYear());
}

function home()
{
    window.open('/index.html', '_self'); 
    return false;
}

function validate(action)           // actions from the menu
{
    var state = 
        [ 
            "clientPage", 
            "dataPage", 
            "profilePage", 
            "contactPage" 
        ];

    if (action < 1 || action > 4 )
        return home();

    addHidden("state",  state[action - 1]);
    addHidden("type",   "psych");
    document.getElementsByName('form')[0].submit();
    return false;
} 

function remove()
{
    var clientID = document.getElementById("selectID").value;

    if (clientID < 1 || clientID > nClients)
    {
        alert("Klik op een cli&euml;nt in het linker overzicht\n" +
              "om de te verwijderen client te selecteren");
        return false;
    }

    addHidden("request",    'remove');
    addHidden("clientIdx",  clientID - 1);
    addHidden("state",      'clientPage');
    addHidden("type",       "psych");
    document.getElementsByName('form')[0].submit();
    return false;
}

function process()
{
    var form = document.forms["form"];

    var name = form['name'].value;
    var lastName = form['lastName'].value;
    var email = form['email'].value;
    var gender = form['gender'].value;

    if (name == "" || lastName == "" || email == "" ||
        gender != "M" && gender != "F")
    {
        alert("alle velden moeten zijn ingevuld");
        return false;
    }

    addHidden("state",      'clientPage');
    addHidden("type",       "psych");
    document.getElementsByName('form')[0].submit();
    return false;
}

    
    
