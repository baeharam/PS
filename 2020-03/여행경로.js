let ans = [],
  p = {},
  v = {},
  n = null;
function dfs(f, idx, tr) {
  const t = p[f][idx];
  v[f][idx] = true;
  tr.push(t);
  if (tr.length === n * 2 - (n - 1)) ans.push([...tr]);
  else if (p[t]) {
    for (let i = 0; i < p[t].length; i++) {
      if (v[t][i]) continue;
      dfs(t, i, tr);
    }
  }
  v[f][idx] = false;
  tr.pop();
}

function solution(tickets) {
  n = tickets.length;
  tickets.forEach(t => {
    if (t[0] in p) p[t[0]].push(t[1]);
    else p[t[0]] = [t[1]];
  });
  for (let k in p) v[k] = Array(p[k].length).fill(false);
  for (let i = 0; i < p["ICN"].length; i++) dfs("ICN", i, ["ICN"]);
  return ans.sort((a, b) => a.toString().localeCompare(b.toString()))[0];
}
console.log(
  solution([
    ["ICN", "A"],
    ["ICN", "B"],
    ["ICN", "C"],
    ["A", "ICN"],
    ["B", "ICN"],
    ["C", "ICN"]
  ])
);
