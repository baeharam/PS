function solution(name) {
  const vi = Array(name.length).fill(false);
  let idx = 0,
    ans = 0,
    m = 0;
  while (m !== 2e9) {
    vi[idx] = true;
    const code = name[idx].charCodeAt(0);
    const u = code - 65;
    const d = 90 - code + 1;
    ans += Math.min(u, d);

    m = 2e9;
    let aidx = -1;
    for (let i = 0; i < name.length; ++i) {
      if (i === idx || name[i] === "A") continue;
      if (vi[i]) continue;
      const l = idx - i < 0 ? idx + 1 + (name.length - 1 - i) : idx - i;
      const r = i - idx < 0 ? 2e9 : i - idx;
      if (m > Math.min(l, r)) {
        m = Math.min(l, r);
        aidx = i;
      }
    }
    if (m < 2e9) {
      ans += m;
      idx = aidx;
    }
  }
  return ans;
}
