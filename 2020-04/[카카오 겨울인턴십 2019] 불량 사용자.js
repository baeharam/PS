const log = console.log;

function solution(user_id, banned_id) {
  const users = Object.values(user_id);
  const exp = banned_id.map((id) => new RegExp(`^${id.replace(/\*/g, ".")}$`));
  let ans = 0;

  const arr = [];
  for (let e of exp) {
    const t = [];
    for (let u of users) {
      if (e.test(u)) t.push(u);
    }
    arr.push(t);
  }
  const tc = {},
    cc = {};

  const dfs = (idx, till) => {
    if (idx === arr.length) {
      const s = [...till].sort().join("");
      if (cc[s]) return;
      cc[s] = true;
      ++ans;
      return;
    }
    for (let a of arr[idx]) {
      if (tc[a]) continue;
      tc[a] = true;
      till.push(a);
      dfs(idx + 1, till);
      tc[a] = false;
      till.pop();
    }
  };
  dfs(0, []);

  return ans;
}

log(
  solution(
    ["frodo", "fradi", "crodo", "abc123", "frodoc"],
    ["fr*d*", "*rodo", "******", "******"]
  )
);
