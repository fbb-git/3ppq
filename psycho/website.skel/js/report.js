function validate()
{
    addHidden("show",   localStorage.idx);
    addHidden("email",  localStorage.email);
    addHidden("state",  "report");
    addHidden("type",   "psych");
    document.getElementsByName('form')[0].submit();
}

