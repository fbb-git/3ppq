function validate() 
{
    var form = document.forms["form"];

    sessionStorage.psychID = form['psychID'].value;
    sessionStorage.clientID = form['clientID'].value;

    sessionStorage.idx = 0;
    sessionStorage.nr = 1;
    sessionStorage.nQuestions = form['nQuestions'].value;

    sessionStorage.questions = questions;

    sessionStorage.ratings = Array(questions.length);
    sessionStorage.ratings.fil(0);

    window.open('/questions.html', '_self');
    
//    addHidden('type', 'client');
//    addHidden('state', 'quest');
//    addHidden('nr',    '-1');
} 








