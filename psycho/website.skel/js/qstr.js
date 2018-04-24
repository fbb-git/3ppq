function qStr(idx)
{
    var from = 0;
    while (1)
    {
        var next = sessionStorage.questions.indexOf('|', from);
        if (idx == 0)
            return sessionStorage.questions.substr(from, next - from);
        --idx;
        from = next + 1;
    }
}

