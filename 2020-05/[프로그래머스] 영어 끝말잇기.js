function solution(n, words) {
  const num = Array(n + 1).fill(0);
  const c = {};
  for (let i = 0; i < words.length; ++i) {
    const o = (i % n) + 1;
    ++num[o];
    if (c[words[i]]) return [o, num[o]];
    if (i && words[i - 1][words[i - 1].length - 1] !== words[i][0])
      return [o, num[o]];
    c[words[i]] = true;
  }
  return [0, 0];
}
