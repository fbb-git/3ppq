    <script src="/js/preamble.js"></script>
    <script src="/js/reqemail.js"></script>
</head>

<body class="full"> 
<div class="container">

<img src="/images/3ppqUL.jpg" class=logo>

<header class='title'>
          Persoonlijkheid in perspectief
</header>

<form name="form" action="/bin/form" onsubmit="return validate()" 
      method="post">

Uw psycholoog heeft u gevraagd drie anderen te benaderen om de vragenlijst
over u in te vullen. Om deze drie anderen een uitnodiging hiervoor te kunnen
sturen, dient u hieronder hun e-mailadressen in te vullen. Zorgt u er
alstublieft voor de e-mailadressen correct in te vullen.

<div class="lightgrey">

<table style="border-collapse: collapse;">

<tr class=darkrow>
    <td class=right>E-mail adres eerste ander: </td> 
    <td ><input class=margin type=email name=e0 size=50></td>
</tr>

<tr>
    <td class=right>E-mail adres tweede ander: </td> 
    <td ><input class=margin type=email name=e1 size=50></td>
</tr>

<tr class=darkrow>
    <td class=right>E-mail adres derde ander: </td> 
    <td ><input class=margin type=email name=e2 size=50></td>
</tr>

</table>

<p>
</div>

<input type=submit value=Verstuur>


