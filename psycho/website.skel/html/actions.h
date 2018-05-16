    <script src="/js/preamble.js"></script>
    <script src="/js/actions.js"></script>
    <script src="/js/topage.js"></script>
</head>

<body class="full"> 
    <img src="/images/3ppqUL.jpg" class=logo>
<form name="form" action="/bin/form" method="post">
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
                    title="Cli&euml;ntafhandeling"
                    onclick="validate('clientPage')" 
            >
                Cli&euml;nten 
            </button>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                title= "Download verzamelde data"
                onclick= "return toPage('/data.shtml)"
            >
                Data
            </button>
        </li>
        <li class="li-linewise">
            <button class=topmenu 
                title= "title="Download documenten"
                onclick="toPage('/documents.shtml')"
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
 
<p>

<!-- messages for the psychologist -->
$0

