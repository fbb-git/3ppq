    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening  = "$0";     // is deze persoon; bent u
        sessionStorage.himHer   = "$1";
        sessionStorage.hisHer   = "$2";
        sessionStorage.heShe    = "$3";
        sessionStorage.closing  = "$4";
        sessionStorage.thanks   = "$5";
    </script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>

<div class="container">

<form name="form" action="/bin/form" onsubmit="return validate()" 
      method="post">

<b>Toelichting en invulinstructie</b><p>

Deze vragenlijst gaat over hoe u bent. Bijvoorbeeld:
<p>

<div class=center-text>

    $0 iemand die        <!-- is deze persoon / bent u -->
        gemakkelijk vrienden maakt?
    <p>

</div>

<table class=center-table>
<tr>
    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>

    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>

    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>

    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>

    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>

    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>

    <td><input type="radio" name="answer" disabled></td>
    <td> &nbsp;&nbsp;</td>
</tr>
<tr>
    <td class=center-text>&lt;</td>
    <td></td>

    <td class=center-text>nee!</td>
    <td></td>

    <td class=center-text>nee</td>
        <td></td>

    <td class=center-text>?</td>
    <td></td>

    <td class=center-text>ja</td>
    <td></td>

    <td class=center-text>ja!</td>
    <td></td>

    <td class=center-text>&gt;</td>
</tr>

</table>
<p>

Kies het meest passende antwoord.
<p>

Na beantwoording van een vraag gaat u automatisch naar de volgende vraag. Via
<tt>&lt;</tt> kunt u terug naar de vorige vraag, en via <tt>&gt;</tt> naar de
volgende vraag<br>

U kunt uw antwoorden nog veranderen voor u de vragenlijst verstuurt. 
<p>

Dit onderdeel van de lijst bevat 42 vragen. Als u in een rustig tempo
werkt, kost het een minuut of tien.

<p>

<input type="submit" value="Start de vragenlijst">






