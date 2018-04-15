    <script src="/js/preamble.js"></script>
    <script src="/js/actions.js"></script>
</head>

<body class="full"> 
<div class="container">

<header class='title'>
          Persoonlijkheid in perspectief
</header>

<form name="form" action="/bin/form" method="post">

<nav class="top-menu-markup">                                               
    <ul class="spread">                                                     
        <li class="li-linewise">
            <a href="" title="Activiteiten m.b.t. clienten" 
                onclick="action = 1;" > 
                Cli&euml;nt 
            </a>
        </li>
        <li class="li-linewise">
            <a href="/wip.html" title="Download/selecteer verzamelde data"
                onclick="action = 2;" >
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
                onclick="action = 4;" >
                Contact 
            </a>
        </li>                                                               
    </ul>                                                                   
</nav>                                                                      
 
<p>
<img src="/images/3ppqUL.jpg" class=logo>

De in de menubalk vermelde opties zijn nog niet operationeel.<p>

Plaats de muis boven een optie voor een korte beschrijving van hun functie.

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
