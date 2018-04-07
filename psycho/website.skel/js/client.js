function validate() 
{
    var ack = document.forms["form"]["ack"].value;

    if (ack == "")
    {
        alert("Vermeld het registratienummer s.v.p");
        return false;
    }
    addHidden('type', 'client');
    addHidden('state', 'verify');
} 








