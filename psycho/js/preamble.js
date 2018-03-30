function addHidden(key, value) 
{
    var input = document.createElement('input');
    input.type = 'hidden';
    input.name = key; 
    input.value = value;
    
    document.forms['form'].appendChild(input);
}
