var clientID;

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

    form['request'].value = "update";
    form['activate'].value = document.getElementById('active').value;

//        document.getElementById('check').style.display = 'initial';

//        document.getElementById('check2').style.display = 'table-cell';
//        document.getElementById('check1').style.display = 'table-cell';
//
//        document.getElementById('check3').style.display = 'none';
//        document.getElementById('check4').style.display = 'none';

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

    form['request'].value = "add";
    form['activate'].value = 0;

    document.getElementById('check').style.display = 'none';
    return false;
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
