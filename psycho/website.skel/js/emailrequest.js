function validate() 
{
    var form = document.forms["form"];

    if (form['e0'].value == '' || form['e1'].value == "" || 
        form['e2'].value == "")
    {
        alert("U hebt nog geen drie e-mail adressen ingevuld");
        return false;
    }

    addHidden('state', 'storeEmail');
    addHidden('type', 'client');
} 








