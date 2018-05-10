    <script src="/js/preamble.js"></script>
    <script src="/js/actions.js"></script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>

<div class="container">

<form name="form" action="/bin/form" method="post">

<nav class="top-menu-markup">                                               
    <ul class="spread">                                                     
        <li class="li-linewise">
            <a href="#" title="Activiteiten m.b.t. cli&euml;nten" 
                onclick="validate(1)" > 
                Cli&euml;nt 
            </a>
        </li>
        <li class="li-linewise">
            <a href="#" title="Download/selecteer verzamelde data"
                onclick="return false; validate(2)" >
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
    </ul>                                                                   
</nav>                                                                      
 
<p>
De in de menubalk vermelde opties zijn mogelijk deels operationeel.<br>
Plaats de muis boven een optie voor een korte beschrijving van hun functie.
<p>

<!-- messages for the psychologist -->
$0

<hr>

Door op de knop <em>3PPQ</em> te klikken keert u terug naar de
3PPQ-homepage. 
<p>

<div class=lightgrey>
<table style="border-collapse: collapse;">
<tr class=darkrow>
<td>
    <input type="submit" value="3PPQ" 
        onclick="window.open('/index.html', '_self'); return false;">
</td>
</table>
</div>
