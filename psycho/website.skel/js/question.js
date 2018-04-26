//  sessionStorage.pid = form['pid'].value;
//  sessionStorage.cid = form['cid'].value;

//  sessionStorage.idx = 0;
//  sessionStorage.nQuestions = form['nQuestions'].value;
//  sessionStorage.questions = questions array
//  sessionStorage.ratings = Array(questions.length);

var nQuestions = 0;
var idx = 0;

function validate()
{
    addHidden('type',       'client');
    addHidden('state',      'answered');

    addHidden('ratings',    sessionStorage.ratings);
    addHidden('pid',        sessionStorage.pid);
    addHidden('cid',        sessionStorage.cid);
    addHidden('other',      sessionStorage.other);
    addHidden('ratingType', sessionStorage.ratingType);
    
    document.form.submit();
}

function answer(value)
{
    var ratings = sessionStorage.ratings;
//    var idx = Number(sessionStorage.idx);

    sessionStorage.ratings = 
        ratings.substr(0, idx) + value + ratings.substr(idx + 1);

    if ((1 + idx) != nQuestions)
        ++sessionStorage.idx;

    window.location.reload();
}

function forward()
{
    if (idx + 1 == nQuestions)
        submit();
    else
    {
        ++sessionStorage.idx;
        window.location.reload();
    }
}

function back()
{
    --sessionStorage.idx;
    window.location.reload();
}
            
function setArrows()
{
    if ( !(sessionStorage.pid > 0) )
    {
        window.open('/index.html', '_self'); 
        return;
    }

    document.forms["form"].reset();

    idx = Number(sessionStorage.idx);
    nQuestions = Number(sessionStorage.nQuestions);

    var answer = Number(sessionStorage.ratings[idx]);

    var lastDivVisible = 'hidden';

    if (answer >= 1 && answer <= 5)
    {
        if (1 + idx == nQuestions)
            lastDivVisible = 'visible';
        
        document.getElementById("nr" + answer).checked = true;
    }
    document.getElementById('lastDiv').style.visibility = lastDivVisible;


    var backwardVisible = idx == 0 ? 'hidden' : 'visible';
    document.getElementById('backID1').style.visibility = backwardVisible;
    document.getElementById('backID2').style.visibility = backwardVisible;


    var forwardVisible = answer == 0 || idx + 1 == nQuestions ? 
                                'hidden' 
                            : 
                                'visible';

    document.getElementById('forwardID1').style.visibility = forwardVisible;
    document.getElementById('forwardID2').style.visibility = forwardVisible;
}

    





