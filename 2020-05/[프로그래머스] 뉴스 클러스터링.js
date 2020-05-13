function solution(s1, s2) {
  s1 = s1.toUpperCase().split("");
  s2 = s2.toUpperCase().split("");
  const ss1 = [],
    ss2 = [];
  for (let i = 0; i < s1.length - 1; ++i) {
    const slice = s1.slice(i, i + 2).join("");
    if (!/[A-Z][A-Z]/.test(slice)) continue;
    ss1.push(slice);
  }
  for (let i = 0; i < s2.length - 1; ++i) {
    const slice = s2.slice(i, i + 2).join("");
    if (!/[A-Z][A-Z]/.test(slice)) continue;
    ss2.push(slice);
  }
  let fre = {};
  const inSet = [],
    uniSet = [...ss1];
  for (let _s1 of ss1) {
    if (!ss2.includes(_s1)) continue;
    if (fre[_s1]) continue;
    fre[_s1] = true;
    const ts1 = ss1.filter((_) => _ === _s1).length;
    const ts2 = ss2.filter((_) => _ === _s1).length;
    inSet.push(...Array(Math.min(ts1, ts2)).fill(_s1));
  }
  fre = {};
  for (let _s1 of ss1) {
    if (_s1 in fre) ++fre[_s1];
    else fre[_s1] = 1;
  }
  for (let _s2 of ss2) {
    if (fre[_s2]) {
      --fre[_s2];
      continue;
    }
    uniSet.push(_s2);
  }
  if (!uniSet.length) return 65536;
  return Math.floor((inSet.length / uniSet.length) * 65536);
}

solution("aa1+aa2", "AAAA12");
