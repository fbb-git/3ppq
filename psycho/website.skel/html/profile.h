<!--
    $0: name
    $1: lastname
    $2: email
    $3: fields
-->

    <script src="/js/preamble.js"></script>
    <script>var fields=$3;</script>
    <script src="/js/pwdcheck.js"></script>
    <script src="/js/profile.js"></script>
</head>

<body class="full">
    <img src="/images/3ppqUL.jpg" class=logo>
<form name="form" action="/bin/form" method="post">
<nav class="top-menu-markup">                                               
    <ul class="spread">
        <li class="li-linewise">
            <a href="/home.html" title="3ppq home-page (en uitloggen)" >
                <img border=0 src="/images/home.png" height=16em >
            </a>
        </li>
        <li class="li-linewise">
            <a href="#" title="Activiteiten m.b.t. cli&euml;nten" 
               onclick="validate('clientPage')" 
            >
                Cli&euml;nten 
            </a>
        </li>
        <li class="li-linewise">
            <a href="/data.shtml" title="Download verzamelde data"
            >
                Data
            </a>
        </li>
        <li class="li-linewise">
            <a href="/documents.shtml" title="Download documenten"
            >
                Documenten
            </a>
        </li>
        <li class="li-linewise">
            <a href="#" title="Wijzig uw eigen gegevens"
                onclick="return false;"
            >
                Profiel
            </a>
        </li>
        <li class="li-linewise">
            <a href="/psychcontact.shtml" title="3ppq contact informatie"
            >
                Contact
            </a>
        </li>
    </ul>                                                                   
</nav>                                                                      
<div class="container">

<h1>Wijzigen van uw profiel</h1>

Nadat u uw profiel-gegevens hebt gewijzigd dient u uw wachtwoord te vermelden
om de nieuwe gegevens te activeren.
<p>

Wanneer u uw wachtwoord wijzigt is uw nieuwe wachtwoord vereist bij de
volgende keer dat u inlogt.
<p>

Wijzig de hieronder vermelde gegevens. Vermeld dan uw huidige wachtwoord en
druk op de <em>Enter</em> toets. 
<p>

Door op de knop <em>3ppq</em> te klikken keert u terug naar de
3ppq-homepage. 
<p>

<div class="lightgrey">

<table style="border-collapse: collapse;">

<tr class="darkrow">
    <td class=right>Naam: </td> 
    <td ><input class=margin type="text" name="name" value="$0" 
                size="50"></td>
</tr>

<tr >
    <td class=right>Achternaam: </td> 
    <td ><input class=margin type="text" name="lastName" value="$1" 
                size="50"></td>
</tr>

<tr class=darkrow>
    <td class=right>E-mail adres: </td> 
    <td ><input class=margin type="text" name="newemail" value="$2"
                size="50"></td>
</tr>
<tr>
    <td class=right>NIP-nummer: </td> 
    <td ><input class=margin pattern='[0-9]{1,8}' 
                type="text" name="nip" value="$4" size="15" > </td>
</tr>

<tr class=darkrow>
    <td class=right>Werkzaam op het gebied van:</td>

    <td >
        <input type="checkbox" id="c1"  name="field" value="1"> A&amp;O<br> 
        <input type="checkbox" id="c2"  name="field" value="2"> GGZ<br> 
        <input type="checkbox" id="c4"  name="field" value="4"> Onderwijs<br> 
        <input type="checkbox" id="c8"  name="field" value="8"> Onderzoek<br> 
        <input type="checkbox" id="c16" name="field" value="16"> anders<br> 
    </td>
</tr>
<tr>
    <td class=right> Nieuw wachtwoord:</td>
    <td> <input class=margin type="password" name="newpwd" size="20"> 
        (optioneel) </td>
</tr>
<tr>
    <td class=right> Wachtwoord nogmaals:</td>
    <td> <input class=margin type="password" name="newpwd2" size="20">
        (indien u uw wachtwoord wijzigt)
</tr>
</table>
<script> window.onload= setFields(); </script>
<p>
</div>

<table style="border-collapse: collapse;">
<tr class=darkrow>
    <td >Huidig wachtwoord:</td>
    <td> <input class=margin type="password" name="pwd" size="20"
         onkeydown='key(event)'
        > </td>

</tr>
<tr class=darkrow>
    <td colspan="2">
        Vul in en druk op <em>Enter</em> om uw wijzigingen te activeren
    </td>
<tr>
    <td>&nbsp;</td>
</tr>
</table>




