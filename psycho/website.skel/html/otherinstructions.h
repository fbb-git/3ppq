    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening      = "$0 $1";     // is [name client] 
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
        onsubmit="return validate('/question.html')" 
      method="post">
<div class="container">

<b>Toelichting en invulinstructie</b><p>

Deze vragenlijst gaat over hoe $1 is. Bijvoorbeeld:
<p>

<table class=center-table>
<tr>
    <td colspan=2>
     Is $1 iemand die...
    </td>
</tr>
<tr>
    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>
</tr>
<tr>
    <td></td>
    <td class=center-text>
        ... gemakkelijk vrienden maakt?
    </td>
</tr>
<tr>
    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>
</tr>
<tr>
    <td></td>
<td>
<table class=center-table>
<tr>
    <td></td>
    <td></td>

    <td><input type=radio name=one disabled></td>
    <td></td>

    <td><input type=radio name=one disabled></td>
    <td></td>

    <td><input type=radio name=one disabled></td>
    <td></td>

    <td><input type=radio name=one disabled></td>
    <td></td>

    <td><input type=radio name=one disabled></td>
    <td></td>

</tr>
<tr>
    <td><button type=button disabled>terug</button></td>
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

    <td><button type=button disabled>verder</button></td>
</tr>
<tr>
    <td></td>
    <td>&nbsp;&nbsp;&nbsp;&nbsp;
       &nbsp;&nbsp;&nbsp;&nbsp;
        &nbsp;&nbsp;&nbsp;&nbsp;</td>

    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>
    <td>&nbsp;&nbsp;</td>

    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>
    <td>&nbsp;&nbsp;</td>

    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>
    <td>&nbsp;&nbsp;</td>

    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>
    <td>&nbsp;&nbsp;</td>

    <td>&nbsp;&nbsp;&nbsp;&nbsp;</td>

    <td>&nbsp;&nbsp;&nbsp;&nbsp;
       &nbsp;&nbsp;&nbsp;&nbsp;
       &nbsp;&nbsp;&nbsp;&nbsp;</td>
    <td></td>
</tr>
</table>
</td>
</tr>
</table>


Kies het meest passende antwoord en klik dan op &#x2018;verder&#x2019; om naar
de volgende vraag te gaan. Door op &#x2018;terug&#x2019; te klikken gaat u
terug naar de vorige vraag.  <p>

De vragenlijst bestaat uit 42 van dergelijke vragen. Als u in een rustig tempo
werkt, kost het een minuut of tien.
<p>

Na beantwoording van een vraag gaat u automatisch naar de volgende vraag. Via
<tt>&lt;</tt> kunt u terug naar de vorige vraag, en via <tt>&gt;</tt> naar de
volgende vraag<br>

U kunt uw antwoorden nog veranderen voor u de vragenlijst verstuurt. 
<p>

U blijft zelf anoniem in dit onderzoek. Uw antwoorden worden niet aan $1
doorgegeven. Uw antwoorden en die van twee anderen worden gemiddeld. Dit
gemiddelde en de betekenis ervan worden vervolgens met $1 besproken.
<p>

<input type="submit" value="Start de vragenlijst">
