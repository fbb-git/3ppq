    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening = "$0";      // is deze persoon; bent u
    </script>
</head>

<body class="full"> 
<div class="container">

<img src="/images/3ppqUL.jpg" class=logo>

<header class='title'>
          Persoonlijkheid in perspectief
</header>

<form name="form" action="/bin/form" onsubmit="return validate()" 
      method="post">

<b>Toelichting en invulinstructie</b><p>

Deze vragenlijst gaat over hoe u bent. Bijvoorbeeld:

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

<ul>
<li>kies ja!  als dat zo is<br>
<li>kies ja als het eerder wel dan niet zo is<br>
<li>kies ? als het neutraal is of als u het niet weet<br>
<li>kies nee als het eerder niet dan wel zo is<br>
<li>kies nee! als het niet zo is
</ul>

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






