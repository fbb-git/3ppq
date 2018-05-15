    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening  = "$0";     // vinden anderen u
        sessionStorage.himHer   = "$1";
        sessionStorage.hisHer   = "$2";
        sessionStorage.heShe    = "$3";
        sessionStorage.closing  = "$4";
        sessionStorage.thanks   = "$5";
    </script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>

<form name="form" action="/bin/form" onsubmit="return validate()" 
      method="post">

<div class="container">

<b>Toelichting en invulinstructie</b><p>

In het vorige onderdeel hebt u de vragenlijst ingevuld over uzelf. In dit 
tweede en laatste onderdeel van de vragenlijst is de vraag hoe anderen vinden 
dat u bent. Bijvoorbeeld:

<p>

<table class=center-table>
<tr>
    <td colspan=2>
     $0 iemand die...
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
<p>

Kies het meest passende antwoord.
<p>

Denk bij <em>anderen</em> niet aan een bepaalde persoon, maar aan anderen in
het algemeen.
<p>

Zulke vragen zijn vaak lastiger te beantwoorden, maar meestal heeft u wel een 
idee.
<p>

<input type="submit" value="Start de vragenlijst">
