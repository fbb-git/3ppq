    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening      = "$0";     // is deze persoon; bent u
        sessionStorage.himHer       = "$1";
        sessionStorage.hisHer       = "$2";
        sessionStorage.heShe        = "$3";
        sessionStorage.closing      = "$4";
        sessionStorage.thanks       = "$5";
        sessionStorage.nQuestions   = "$6";
    </script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>
<form name="form" action="/bin/form" 
        onsubmit="return validate('/selfinstructions.html')" 
      method="post">
<div class="container">

<b>Algemene instructie</b><p>

Het navolgende onderzoek bestaat uit drie delen, die elk eindigen met de optie
`verstuur'. U kunt niet verder gaan met een volgend deel voordat u `verstuur'
hebt aangeklikt. Hiermee worden uw antwoorden opgeslagen. Wanneer u
tussentijds het onderzoek afbreekt worden antwoorden die nog niet verstuurd
zijn niet opgeslagen. U wordt verzocht om het gehele onderzoek in een keer te
doorlopen.  Het totale onderzoek duurt ongeveer 20 minuten.  Klik op `start
deel 1' om een eerste serie van 42 vragen te beantwoorden.

<p>

<input type="submit" value="Start deel 1">






