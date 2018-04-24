//  sessionStorage.psychID = form['psychID'].value;
//  sessionStorage.clientID = form['clientID'].value;

//  sessionStorage.idx = 0;
//  sessionStorage.nQuestions = form['nQuestions'].value;
//  sessionStorage.questions = questions array
//  sessionStorage.ratings = Array(questions.length);

function submit()
{
    addHidden('type',   'client');
    addHidden('state',  'answered');
    document.form.submit();
}

function answer(value)
{
    var ratings = sessionStorage.ratings;
    var idx = sessionStorage.idx;

    sessionStorage.ratings = 
        ratings.substr(0, idx) + value + ratings.substr(idx + 1);

    if (++sessionStorage.idx != sessionStorage.nQuestions)
        window.location.reload();
    else
        submit();
}

function forward()
{
    if (sessionStorage.idx + 1 == sessionStorage.nQuestions)
        submit();
//    else if (sessionStorage.ratings[sessionStorage.idx] == 0)
//        alert("U heeft deze vraag nog niet beantwoord...");
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
    if ( !(sessionStorage.psychID > 0) )
    {
        window.open('/index.html', '_self'); 
        return;
    }

    document.forms["form"].reset();

    var answer = sessionStorage.ratings[sessionStorage.idx];

    if (answer >= 1 && answer <= 5)
        document.getElementById("nr" + answer).checked = true;
    
    var backwardVisible = sessionStorage.idx == 0 ? 'hidden' : 'visible';

    document.getElementById('backID1').style.visibility = backwardVisible;
    document.getElementById('backID2').style.visibility = backwardVisible;

    var forwardVisible = answer == 0 ?
                                'hidden'
                            :
                                'visible';

    document.getElementById('forwardID1').style.visibility = forwardVisible;
    document.getElementById('forwardID2').style.visibility = forwardVisible;
}

    





