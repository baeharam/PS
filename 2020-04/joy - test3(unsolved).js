function solution(s) {
  const r = s.split("").reverse().join("");
  const len = s.length;
  if (s === r) return len;
  let sidx = ~~(len / 2),
    ans = len;
  while (sidx < len) {
    let lidx = sidx - 1,
      ridx = sidx + 1;
    while (ridx < len && s[lidx] === s[ridx]) {
      --lidx;
      ++ridx;
    }
    if (ridx >= len) {
      ans += lidx + 1;
      break;
    }
    ++sidx;
  }

  let sidx1 = ~~(len / 2),
    sidx2 = sidx1 + 1;

  while (sidx1 < len - 1 && sidx2 < len && s[sidx1] === s[sidx2]) {
    let lidx = sidx1 - 1,
      ridx = sidx2 + 1;
    while (ridx < len && s[lidx] === s[ridx]) {
      --lidx;
      ++ridx;
    }
    if (ridx >= len) {
      ans = Math.min(ans, len + lidx + 1);
      break;
    }
    ++sidx1;
    ++sidx2;
  }

  return ans;
}

const ss = "accbcba";
console.log(solution(ss));
