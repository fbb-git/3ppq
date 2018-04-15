    <script src="/js/preamble.js"></script>
    <script src="/js/confirmnewpwd.js"></script>
</head>

<body class="full"> 
<div class="container">

<header class='title'>
          Persoonlijkheid in perspectief
</header>

<h1>Aanvraag nieuw wachtwoord</h1>

Door op de knop <em>Bevestig Aanvraag Nieuw Wachtwoord</em> te klikken vervalt
de geldigheid van uw huidige 3PPQ wachtwoord. U krijg dan per e-mail uw nieuwe
wachtwoord toegestuurd dat vanaf dat moment kan worden gebruikt om in te
loggen.

<p>
Wanneer u uw huidige wachtwoord <em>niet</em> wilt veranderen, klik dan op de
knop <em>Login</em>, om terug te keren naar de login-pagina.

<p>
<form name="form" action="/bin/form" onsubmit="return validate()" 
      method="post">

<div style="background-color:#dddddd">
<table>
<tr>
    <td ><input type="submit" value="Bevestig Aanvraag Nieuw Wachtwoord"></td>
</tr>
<tr>
    <td>
        <input type="submit" value="Login" 
            onclick="window.open('/psych.html', '_self'); return false;">
    </td>
</tr>
</table>
</div>
