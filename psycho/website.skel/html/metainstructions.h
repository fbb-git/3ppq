    <script src="/js/preamble.js"></script>
    <script src="/js/questions.js"></script>
    <script src="/js/instructions.js"></script>
    <script>
        sessionStorage.opening      = "$0";     // vinden anderen u
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
        onsubmit="return validate('/question.html')" 
      method="post">

<div class="container">

De volgende 42 vragen gaan over hoe anderen vinden dat u als persoon bent. 
<p>

Bijvoorbeeld:
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
            <td style="text-align:center">ja</td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
        
            <td><input type=radio name=one disabled></td>
            <td><hr class=hr3em></td>
        
            <td><input type=radio name=one disabled></td>
            <td><hr class=hr3em></td>
        
            <td><input type=radio name=one disabled></td>
            <td><hr class=hr3em></td>
        
            <td><input type=radio name=one disabled></td>
            <td><hr class=hr3em></td>
        
            <td><input type=radio name=one disabled></td>

            <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
            <td style="text-align:center">nee</td>
        
        </tr>
        <tr>
            <td><button type=button disabled>Terug</button></td>
            <td></td>

            <td></td>
            <td></td>
        
            <td></td>
            <td></td>
        
            <td></td>
            <td></td>
        
            <td></td>
            <td></td>
        
            <td></td>
        
            <td></td>
            <td><button type=button disabled>verder</button></td>
        </tr>
        </table>
    </td>
</tr>
</table>

Kies het meest passende antwoord.
<p>

Denk bij anderen niet aan een bepaalde persoon, maar aan anderen in
het algemeen.
<p>

<input type="submit" value="Start de vragenlijst">
