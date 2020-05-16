function solution(cs, ct) {
  if (!cs) return ct.length * 5;
  let ans = 0;
  let t = 0;
  const cache = [];
  for (let c of ct) {
    c = c.toUpperCase();
    const tidx = cache.findIndex((cc) => cc.name === c);
    if (tidx === -1) {
      cache.sort((a, b) => a.time - b.time);
      if (cache.length === cs) cache.shift();
      cache.push({ name: c, time: t++ });
      ans += 5;
    } else {
      cache[tidx].time = t++;
      ++ans;
    }
  }
  return ans;
}

solution(2, ["Jeju"]);
