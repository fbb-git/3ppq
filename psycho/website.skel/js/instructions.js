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

    var idx;
    for (idx = 0; idx != questions.length; ++idx)
    answers[idx] = 0;

//    answers.fill(0);          doesn't work on IE 8 or whatever

    sessionStorage.ratings = answers.join('');

    //  sessionStorage.nQuestions = questions.length;
    //  set by bin/form/client/selfratings.cc and -/otherpage.cc

    window.open(next, '_self');

    return false;
} 








