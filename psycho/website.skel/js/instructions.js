function validate(next) 
{
    var form = document.forms["form"];

    sessionStorage.pid = form['pid'].value;
    sessionStorage.cid = form['cid'].value;

    sessionStorage.other = form['other'].value;
    sessionStorage.ratingType = form['ratingType'].value;

    sessionStorage.idx = 0;

    sessionStorage.questions = questions.join('|') + '|';

    var answers = Array(questions.length);
    answers.fill(0);

    sessionStorage.ratings = answers.join('');

    sessionStorage.nQuestions = questions.length;

    window.open(next, '_self');

    return false;
} 








