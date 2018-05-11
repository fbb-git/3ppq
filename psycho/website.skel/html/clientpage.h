    <script>
    // 0: id, 1: gender, 2: active, 3: name, 4: lastname, 5: email, 6: report
        var clients = [
$0    
        ];
    </script>

    <script src="/js/preamble.js"></script>
    <script src="/js/clientpage.js"></script>
</head>

<body class="full">
    <img src="/images/3ppqUL.jpg" class=logo>

<div class="container">

<form name="form" action="/bin/form" onsubmit='return false' method="post">

$3

<nav class="top-menu-markup">                                               
    <ul class="spread">                                                     
        <li class="li-linewise">
            <a href="#" title="Activiteiten m.b.t. cli&euml;nten" 
                onclick="return false;" > 
                Cli&euml;nt 
            </a>
        </li>
        <li class="li-linewise">
            <a href="/data.html" title="Download verzamelde data"
                onclick="validate(0)" >
                Data
            </a>
        </li>
        <li class="li-linewise">
            <a href="/documents.html" title="Download documenten"
                onclick="validate(0)" >
                Documenten
            </a>
        </li>
        <li class=li-linewise>
            <a href="#" title="Wijzig uw eigen gegevens"
                onclick="validate('profilePage')" >
                Profiel
            </a>
        </li>
        <li class=li-linewise>
            <a href="/contact.html" title="3ppq contact informatie"
                onclick="validate(0)" >
                Contact
            </a>
        </li>
    </ul>                                                                   
</nav>                                                                      

<h1>Cli&euml;nt-verwerking</h1>

$1

<h3>Cli&euml;nten:</h3>

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
                $4
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
                    <input id=gender2 type=radio name=gender value=F> V
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




