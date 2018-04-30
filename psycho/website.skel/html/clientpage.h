    <script>
        // 0: id, 1: gender, 2: active, 3: name, 4: lastname, 5: email
        var clients = [
$0    
        ];
    </script>

    <script src="/js/preamble.js"></script>
    <script src="/js/clientpage.js"></script>
</head>

<body class="full">
<div class="container">
<header class='title'>
    <img src="/images/client.jpg" class=logo>
    Persoonlijkheid in perspectief
</header>

<form name="form" action="/bin/form" onsubmit='return false' method="post">

$3

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

$1

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
                <td class=right>ID: </td> 
                <td ><input class=margin pattern="^[-'\w.:;/]+$"
                            type=text name=ident size=5>
                </td>
            </tr>
            <tr class=darkrow>
                <td class=right>Aanspreeknaam: </td> 
                <td ><input class=margin type=text name=name 
                        pattern="^['\w.\s]+$" size=50></td>
            </tr>
            <tr >
                <td class=right>Achternaam: </td> 
                <td ><input class=margin type=text name=lastName 
                        pattern="^['\w.\s]+$" size=50></td>
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
                <td id=time1 class=right> Verstuurd op:</td>
                <td id=time2> <span id=dateText></span></td>
            </tr>
            <tr>
                <td>&nbsp;</td>
            <tr>
            <!-- submitActions -->
            $2
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




