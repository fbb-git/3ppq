function qStr(idx)
{
    var from = 0;
    while (1)
    {
        var next = sessionStorage.questions.indexOf('|', from);
        if (idx == 0)
        {
            var quest = sessionStorage.questions.substr(from, next - from);

            if (/_/.test(quest))      // question w. replaceable text
            {
                quest = quest.replace('_himHer_', sessionStorage.himHer);
                quest = quest.replace('_hisHer_', sessionStorage.hisHer);
                quest = quest.replace('_heShe_',  sessionStorage.heShe);
            }

            return quest;
        }

        --idx;
        from = next + 1;
    }
}

