function solution(s) {
  const inner = s.slice(1, s.length - 1);
  const parsed = [];
  let temp = [],
    num = "";
  for (let i = 0; i < inner.length; ++i) {
    const c = inner[i];
    if (c === "{") continue;
    if (c === ",") {
      if (inner[i - 1] !== "}") {
        temp.push(Number(num));
        num = "";
      }
      continue;
    }
    if (c === "}") {
      temp.push(Number(num));
      parsed.push(temp);
      temp = [];
      num = "";
      continue;
    }
    num += c;
  }
  parsed.sort((a, b) => a.length - b.length);
  const max = Math.max(...parsed[parsed.length - 1]);
  const ans = [],
    checked = Array(max + 1).fill(false);
  for (let arr of parsed) {
    for (let a of arr) {
      if (checked[a]) continue;
      ans.push(a);
      checked[a] = true;
    }
  }
  return ans;
}

console.log(solution("{{20,111},{111}}"));
