    <script src="/js/preamble.js"></script>
    <script src="/js/ackerror.js"></script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>

<div class="container">

<h1>Aanmeldingsverificatienummer onjuist</h1>

<!-- img src="/images/aanmelden.jpg" class=logo-->

Het door u vermelde verificatienummer is onjuist. 

<p> Klik op de knop <em>Verificatie</em> om het juiste nummer alsnog in te
vullen, of klik op de knop <em>3PPQ</em> om terug te keren naar de
3PPQ-homepage.

<form name="form" action="/bin/form" 
      onsubmit="return validate()" method="post">

<div style="background-color:#dddddd">
<table>
<tr>
    <td>
        <input type="submit" value="Verificatie">
    </td>
    <td>
        <input type="submit" value="3PPQ" 
            onclick="window.open('/index.html', '_self'); return false;">
    </td>
</tr>
</table>
</div>
