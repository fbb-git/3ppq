<!--
    $0: name
    $1: lastname
    $2: email
    $3: fields
-->

    <script src="/js/preamble.js"></script>
    <script src="/js/client.js"></script>
</head>

<body class="full">
    <img src="/images/3ppqUL.jpg" class=logo>

<div class="container">

<header class='title'>
            Persoonlijkheid in perspectief
</header>

<form name="form" action="/bin/form" 
onsubmit="alert('validate'); return false; return validate()" method="post">


<nav class="top-menu-markup">                                               
    <ul class="spread">                                                     
        <li class="li-linewise">
            <a href="" title="Activiteiten m.b.t. cli&euml;nten" 
                onclick="return false" > 
                Cli&euml;nt 
            </a>
        </li>
        <li class="li-linewise">
            <a href="/wip.html" title="Download/selecteer verzamelde data"
                onclick="validate(2)" >
                Data
            </a>
        </li>
        <li class=li-linewise>
            <a href="#" title="Wijzig uw eigen gegevens"
                onclick="validate(3)"
            >
                Profiel
            </a>

        </li>
        <li class="li-linewise">
            <a href="/wip.html" title="Contact opnemen met het 3ppq.nl-team"
                onclick="validate(4)" >
                Contact 
            </a>
        </li>                                                               
    </ul>                                                                   
</nav>                                                                      
 

<h1>Cli&euml;nt-configuratie</h1>


<!-- img src="/images/client.jpg" class=float -->


<script>availableClients()</script>

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
                             type="text" name="nip" size="15"> </td>
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
<tr>
    <td>
    <input type="submit" value="3PPQ"
           onclick="return home()">
    </td>
</tr>

</table>




