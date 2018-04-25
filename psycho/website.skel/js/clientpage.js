var clientID;
var choice = "add";
var xgender = 0;

function hideTime()
{
    document.getElementById('time1').style.display = 'none';
    document.getElementById('time2').style.display = 'none';
}

function showTime()
{
    document.getElementById('time2').style.display = 'table-cell';
    document.getElementById('time1').style.display = 'table-cell';
}

function hideActivate()
{
    document.getElementById('check1').style.display = 'none';
    document.getElementById('check2').style.display = 'none';
}

function showActivate()
{
    document.getElementById('check2').style.display = 'table-cell';
    document.getElementById('check1').style.display = 'table-cell';
}

function setValues()
{
    var form = document.forms["form"];

    form.reset();

    if (clients.length > 0)
        form['selectID'].value = "";

    hideTime();
}

function setGender()
{
    xgender = 0;
    document.getElementById('gender1').disabled = false;
    document.getElementById('gender2').disabled = false;
}

function fixGender()
{
    xgender = document.forms['form']['gender'].value;
    document.getElementById('gender1').disabled = true;
    document.getElementById('gender2').disabled = true;
}

function resetFields()
{
    var form = document.forms["form"];

    form.reset();

    hideTime();
    showActivate();
    setGender();

    document.getElementById("actionText").innerHTML = 
                                        "deze client toevoegen";
    setValues();

    form['action'].value = "Toevoegen";
    choice = "add";

    return false;
}


function update()
{
    var form = document.forms["form"];
    var idx = document.getElementById("selectID").value;

    fixGender();

    clientID = idx;

//      0       1       2     3           4           5
//      ID    sex  active 
//      [1,     0,      0,    "Name", "lastname",   "email"]

    form['ID'].value = clients[idx][0];
    form['gender'].value = clients[idx][1] ? 'M' : 'V';
//      [2] is active time
    form['name'].value = clients[idx][3];
    form['lastName'].value = clients[idx][4];
    form['clEmail'].value = clients[idx][5];

//    document.getElementById("loginCodeText").innerHTML = 
//                    "login code";

    if (clients[idx][2] == 0)                   // active
    {
        showActivate();
        hideTime();
    }
    else
    {
        document.getElementById("dateText").innerHTML = 
                            showDate(clients[idx][2]);
        showTime();
        hideActivate();
    }

    form['action'].value = "Wijzigen";
    document.getElementById("actionText").innerHTML = "gegevens wijzigen";

    choice = "update";

    form['activate'].value = document.getElementById('active').value;
}


function showDate(seconds)
{
    var date = new Date(seconds * 1000);
    var months = 
        ['jan','feb','mar','apr','mei','jun',
         'jul','aug','sep','oct','nov','dec'];
    return date.getDate() + ' ' + months[date.getMonth()] + ' ' +
           date.getFullYear();
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
} 

function remove()
{
    var form = document.forms["form"];
    var idx = document.getElementById("selectID").value;

    clientID = clients[idx][0];

    addHidden("request",    'remove');
    addHidden("ID",          clientID);
    addHidden("state",      'clientPage');
    addHidden("type",       "psych");

    document.getElementsByName('form')[0].submit();
}

function process()
{
    var form = document.forms["form"];

    var name = form['name'].value;
    var lastName = form['lastName'].value;
    var clEmail = form['clEmail'].value;
    var gender = form['gender'].value;


    if (name == "" || lastName == "" || clEmail == "" ||
        (gender != "M" && gender != "V") )
    {
        alert("alle velden moeten zijn ingevuld\n" +
            name + lastName + clEmail + gender);
        return false;
    }

    addHidden("request",    choice);

    addHidden("state",      'clientPage');
    addHidden("type",       "psych");

    if (xgender != 0)
        addHidden("xgender", xgender);

    document.getElementsByName('form')[0].submit();
}


