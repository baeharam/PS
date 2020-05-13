function solution(h) {
  const mh = h.map((_h, idx) => ({ idx: idx + 1, h: _h }));
  const s = [];
  for (let i = mh.length - 1; i >= 0; --i) {
    let j = i - 1;
    while (j >= 0 && mh[j].h <= mh[i].h) --j;
    s.unshift(j < 0 ? 0 : mh[j].idx);
  }
  return s;
}
