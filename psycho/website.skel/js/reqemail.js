function validate() 
{
    var form = document.forms["form"];

    if (form['e0'] == '' || form['e1'] == "" || form['e2'] == "")
    {
        alert("U hebt nog geen drie e-mail adressen ingevuld");
        return false;
    }

    addHidden('state', 'storeEmail');
    addHidden('type', 'client');
} 








