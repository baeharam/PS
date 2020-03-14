const solution = (jobs) => {
  jobs.sort((a,b) => a[0]===b[0]?a[1]-b[1]:a[0]-b[0]);
  let c = jobs[0][0], e = c + jobs[0][1];
  let s = jobs[0][1], idx = 1, len = jobs.length;
  const pq = [];
  while(c <= e) {
    while(idx < len && c === jobs[idx][0]) pq.push(jobs[idx++]);
    pq.sort((a,b) => a[1]===b[1]?a[0]-b[0]:a[1]-b[1]);
    const wait = pq.length > 0;
    if (c === e && (wait || idx < len)) {
      const f = wait ? pq.shift() : jobs[idx++];
      e = wait ? e + f[1] : f[0] + f[1];
      s += e - f[0];
      if (!wait) c = f[0] - 1;
    }
    c++;
  }
  return Math.floor(s/len);
};