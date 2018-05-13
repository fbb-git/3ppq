#include "tools.ih"

void Tools::textHtml()
{
    cout << 
"Content-type: text/html\r\n\r\n"
R"R(
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html; charset=windows-1252">
    <link rel="stylesheet" type="text/css" href="/css/3ppq.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
)R";

}
