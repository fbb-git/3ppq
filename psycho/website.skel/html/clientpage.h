    <script>
        var clients = [
$0    
        ];
$1
    </script>

    <script src="/js/preamble.js"></script>
    <script src="/js/clientpage.js"></script>
</head>

<body class="full">
<div class="container">
<header class='title'>
    Persoonlijkheid in perspectief
</header>
<img src="/images/client.jpg" class=logo>


<form name="form" action="/bin/form" onsubmit='return false' method="post">

<nav class="top-menu-markup">                                               
    <ul class="spread">                                                     
        <li class="li-linewise">
            <a href="" title="Activiteiten m.b.t. clienten" 
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
 

<h1>Client-configuratie</h1>

$2

<h3>Cli&euml;nt:</h3>

<table class=lightgrey style="border-collapse: collapse;">
<tr>
    <td><div style='margin-left:5em'></div></td>
</tr>
<tr>
    <td></td>
    <td>
        <table style="border-collapse: collapse;">
            <tr>
                <td ><input type=submit value="Velden wissen"
                            onclick='resetFields()'></td>
            </tr>
            <tr>
                <td class=right>ID: </td> 
                <td ><input class=margin type=text name=ID readonly size=5>
                </td>
            </tr>
            <tr class=darkrow>
                <td class=right>Naam: </td> 
                <td ><input class=margin type=text name=name size=50></td>
            </tr>
            <tr >
                <td class=right>Achternaam: </td> 
                <td ><input class=margin type=text name=lastName size=50></td>
            </tr>
            <tr class=darkrow>
                <td class=right> Geslacht: </td>
                <td> 
                    <input id=gender1 type=radio name=gender value=M> M<br>
                    <input id=gender2 type=radio name=gender value=V> V
                </td>
            </tr>
            <tr>
                <td class=right>E-mail adres: </td> 
                <td ><input class=margin type=email name=clEmail size=50></td>
            </tr>
            <tr class=darkrow>
                <td class=right>login code: </td> 
                <td ><input id=login0 class=margin type=text name=login0
                            size=5></td>
            </tr>
            <tr>
                <td id=time1 class=right> Actief sinds:</td>
                <td id=time2> <span id=dateText></span></td>
            </tr>
            <tr>
                <td id=check1 class=right> Activeren:</td>
                <td id=check2> <input type=checkbox name=active value=1></td>
            </tr>
            <tr class=darkrow>
                <td>
                <input type=submit name='action' value=Toevoegen
                    onclick='process()'>
                </td>
                <td>(<span id=actionText>deze client toevoegen</span>)</td>
            </tr>
        </table>
    </td>
</tr>
</table>
<script> window.onload=setValues(); </script>
<p>

Door op de knop <em>3PPQ</em> te klikken keert u terug naar de 3PPQ-homepage. 
<p>

<table style="border-collapse: collapse;">
<tr>
    <td>
        <input type=submit value=3PPQ onclick="return home()">
    </td>
</tr>
</table>




