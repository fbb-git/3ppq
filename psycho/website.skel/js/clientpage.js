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
 
function fixGender()
{
    document.getElementById('gender1').disabled = true;
    document.getElementById('gender2').disabled = true;
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

function setValues()
{
    var form = document.forms["form"];

    form.reset();

//      0       1       2     3           4           5         6
//      ID    sex  active                                     rapport
//      [1,     0,      0,    "Name", "lastname",   "email",    1]

    hideTime();

     if (clients.length > 0)
     {
         var idx = form['show'].value;
 
        if (idx >= clients.length)
            form['selectID'].value = "";
        else
        {
            form['ident'].value =          clients[idx][0];

            form['gender'].value = clients[idx][1] ? 'M' : 'F';
            fixGender();        

            if (clients[idx][2] != 0)
            {
                document.getElementById("dateText").innerHTML = 
                                            showDate(clients[idx][2]);
                showTime();
            }

            form['name'].value =        clients[idx][3];
            form['lastName'].value =    clients[idx][4];
            form['clEmail'].value =     clients[idx][5];

            document.getElementById("selectID").
                        getElementsByTagName('option')[idx].selected = true;
         }
     }
}
 
function submitRequest(request)
{
    addHidden("request",   request);
    addHidden("state",     "clientPage");
    addHidden("type",      "psych");
    document.getElementsByName('form')[0].submit();
} 

function resetFields()
{
    submitRequest("");
}

function selectIDvalue()
{
    return document.forms["form"]["selectID"].value;
}

function process(action)
{
    addHidden("clientIdx", selectIDvalue());
    submitRequest(action);
}

function validate(action)           // actions from the menu
{
    if (action == 0)
        return true;

    addHidden("email",  localStorage.eMail);
    addHidden("state",  action);
    addHidden("type",   "psych");
    document.getElementsByName('form')[0].submit();
} 

function report(idx)           // show the report of this client
{
    if (idx  < 0 || idx >= clients.length || clients[idx][6] != 1)
        return home();

    var form = document.forms["form"];

    localStorage.idx = idx;
    localStorage.email = form["email"].value;
} 
