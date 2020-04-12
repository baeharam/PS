function solution(b) {
  const rlen = b.length,
    clen = b[0].length;
  const d = Array(rlen)
    .fill(null)
    .map((_) => Array(clen).fill(0));
  const r = Array(rlen)
    .fill(null)
    .map((_) => Array(clen).fill(0));
  const c = Array(rlen)
    .fill(null)
    .map((_) => Array(clen).fill(0));

  for (let i = 0; i < rlen; i++) {
    for (let j = 0; j < clen; j++) {
      if (!b[i][j]) continue;
      d[i][j] = (i - 1 >= 0 && j - 1 >= 0 ? d[i - 1][j - 1] : 0) + 1;
      c[i][j] = (j - 1 >= 0 ? c[i][j - 1] : 0) + 1;
      r[i][j] = (i - 1 >= 0 ? r[i - 1][j] : 0) + 1;
    }
  }
  let ans = 0;
  for (let i = 0; i < rlen; i++) {
    for (let j = 0; j < clen; j++) {
      const m = Math.min(d[i][j], c[i][j], r[i][j]);
      ans = Math.max(ans, m ** 2);
    }
  }
  return ans;
}

solution([
  [0, 0, 1, 1],
  [1, 1, 1, 1],
]);
