const io = c => c === '[' || c === '{' || c === '(';
function isParenthesesBalanced(input) {
  if(!io(input[0])) return false;
  const s = [input[0]];
  let i = 1;
  while(i < input.length){
    const c = input[i];
    if(io(c)) s.push(c);
    else {
      if(!s.length) return false;
      const l = s[s.length-1];
      if((l === '(' && (c === ']' || c === '}'))
      || (l === '[' && (c === ')' || c === '}'))
      || (l === '{' && (c === ']' || c === ')'))) return false;
      s.pop();
    }
    ++i;
  }
  return s.length === 0;
}
console.log(isParenthesesBalanced("[(])[{}]"));