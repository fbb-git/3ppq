function validate() 
{
    var form = document.forms["form"];

    sessionStorage.psychID = form['pid'].value;
    sessionStorage.clientID = form['cid'].value;

    sessionStorage.idx = 0;

    var nQuestions = questions.length;

    sessionStorage.questions = questions.join('|') + '|';

    var answers = Array(questions.length);
    answers.fill(0);

    sessionStorage.ratings = answers.join('');

    sessionStorage.nQuestions = questions.length;

    window.open('/question.html', '_self');

    return false;
} 








