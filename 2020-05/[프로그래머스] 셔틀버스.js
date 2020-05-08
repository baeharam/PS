function solution(n, t, m, timetable) {
  let ct = timetable.map(t => {
    const hm = t.split(":");
    return Number(hm[0])*60 + Number(hm[1]);
  });
  ct.sort((a,b) => a-b);
  let time = 540, cur = null, ans = -1;
  for(let i=0; i<n; ++i) {
    cur = ct.filter(a => a <= time);
    if(i < n - 1) {
      if(cur.length >= m){
        ct = ct.slice(m);
      } else
        ct = ct.filter(a => a > time);
    } else {
      if(cur.length >= m){
        ans = cur[m - 1] - 1;
      } else 
        ans = 540 + t*n - t;
    }
    time += t;
  }
  let _h = ~~(ans/60), _m = ans % 60;
  if(~~(_h/10) === 0) _h = `0${_h}`;
  if(~~(_m/10) === 0) _m = `0${_m}`;
  return _h+":"+_m;
}

solution(1,1,5,["08:00", "08:01", "08:02", "08:03"])