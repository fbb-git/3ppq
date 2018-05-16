    <script>
    // 0: id, 1: gender, 2: active, 3: name, 4: lastname, 5: email, 6: report
        var clients = [
$0    
        ];
    </script>

    <script src="/js/preamble.js"></script>
    <script src="/js/clientpage.js"></script>
    <script src="/js/topage.js"></script>
</head>

<body class="full">
    <img src="/images/3ppqUL.jpg" class=logo>
<form name="form" action="/bin/form" onsubmit='return false' method="post">

$3

<nav class="top-menu-markup">                                               
    <ul class="spread">
        <li class="li-linewise">
            <a href="/home.html" title="3ppq home-page (en uitloggen)" 
                onclick="return toPage('/home.html')" >
                <img border=0 src="/images/home.png" height=16em >
            </a>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                    title="Cli&euml;ntafhandeling" onclick="return false" 
            >
                Cli&euml;nten 
            </button>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                title= "Download verzamelde data"
                onclick= "return toPage('/data.shtml')"
            >
                Data
            </button>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                title="Download documenten"
                onclick="return toPage('/documents.shtml')"
            >
                Documenten
            </button>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                title= "Wijzig uw eigen gegevens"
                onclick="validate('profilePage')"
            >
                Profiel
            </button>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                title= "3ppq contact informatie"
                onclick= "return toPage('/psychcontact.shtml')"
            >
                Contact
            </button>
        </li>
    </ul>                                                                   
</nav>                                                                      

<div class="container">

<h1>Cli&euml;nt-verwerking</h1>

$1

<h3>Details:</h3>

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




