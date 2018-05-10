    <script src="/js/preamble.js"></script>
    <script src="/js/requestack.js"></script>
</head>

<body class="full"> 
    <img src="/images/profile.jpg" class=logo>

<div class="container">

<form name="form" action="/bin/form" 
      onsubmit="return validate()" method="post">

<h1>3PPQ Aanmeldingsverificatie</h1>

Beste $0 $1,<p>

U heeft per e-mail een verificatienummer ontvangen.<br>
U kunt het ontvangen nummer hieronder invullen. Druk vervolgens op de
<tt>Enter</tt> toets: 

<div class=lightgrey>
<table>
<tr>
    <td>
        Verificatienummer:
    </td>
    <td>
        <input type="text" name="ack" size="5">
    </td>
</tr>
</table>
</div>
