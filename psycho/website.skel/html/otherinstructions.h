    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening      = "$0 $1";     // is [name client] 
        sessionStorage.name         = "$1";
        sessionStorage.himHer       = "$2";
        sessionStorage.hisHer       = "$3";
        sessionStorage.heShe        = "$4";
        sessionStorage.closing      = "$5";
        sessionStorage.thanks       = "$6";
        sessionStorage.nQuestions   = "$7";
    </script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>
<form name="form" action="/bin/form" 
        onsubmit="return validate('/otherinstructions.shtml')" 
      method="post">
<div class="container">

<b>Algemene instructie</b><p>


Het navolgende onderzoek bestaat uit 42 vragen en eindigt met de optie
&#x2018;Verstuur&#x2019;.
<p> 

Uw antwoorden worden pas opgeslagen wanneer u &#x2018;Verstuur&#x2019; hebt
aangeklikt. 
<p>

Wanneer u tussentijds het onderzoek afbreekt gaan uw inmiddels gegeven
antwoorden verloren.  U wordt dan ook verzocht om alle vragen in een keer te
doorlopen.  Het beantwoorden van de vragen duurt ongeveer 10 minuten.

<p>
U blijft zelf anoniem in dit onderzoek. Uw antwoorden worden niet aan $1
doorgegeven. Uw antwoorden en die van twee anderen worden gemiddeld.  
Dit gemiddelde en de betekenis ervan zullen met $1 worden
besproken. 
<p>

<input type="submit" value="Verder">
