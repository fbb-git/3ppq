function pwdCheck(pwd)
{
//    alert(pwd.length + ' ' + pwd + ' ' +
//            /\d/.test(pwd) + ' ' + /[a-zA-Z]/.test(pwd) + ' ' +
//            /[-.\\/#!$%^&*;:{}=`~()]/.test(pwd));

    if 
    (
        pwd.length >= 5 && 
        /\d/.test(pwd) && /[a-zA-Z]/.test(pwd) &&
        /[-.\\/#!$%^&*;:{}=`~()]/.test(pwd)
    )
        return true;

    alert("wachtwoord te kort of incompleet");
    return false;
}

        
