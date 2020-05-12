function f(m, n, b) {
  let num = 0;
  const c = [];
  for(let i=0; i<m-1; ++i){
    for(let j=0; j<n-1; ++j){
      if(b[i][j] === -1) continue;
      const t = b[i][j];
      if(b[i][j+1]===t && b[i+1][j]===t && b[i+1][j+1]===t){
        num += 4;
        c.push({x: i, y: j});
      }
    }
  }
  for(let t of c){
    for(let i=t.x; i<=t.x+1; ++i){
      for(let j=t.y; j<=t.y+1; ++j){
        if(b[i][j] === -1){
          --num;
          continue;
        }
        b[i][j] = -1;
      }
    }
  }
  return num;
}

function clear(m, n, b) {
  for(let j=0; j<n; ++j){
    let i=m-1;
    while(i>=0 && b[i][j]!==-1) --i;
    let eidx = i;
    if(eidx < 0) continue;
    i=eidx;
    while(i>=0 && b[i][j]===-1) --i;
    let nidx = i;
    if(nidx < 0) continue;
    while(nidx>=0){
      if(b[nidx][j] === -1){
        --nidx;
        continue;
      }
      b[eidx][j] = b[nidx][j];
      b[nidx][j] = -1;
      --eidx; --nidx;
    }
  }
}

function solution(m, n, b) {
  for(let i=0; i<m; ++i) b[i] = b[i].split("");
  let ans = 0;
  while(true){
    const ret = f(m,n,b);
    if(!ret) break;
    ans += ret;
    clear(m,n,b);
  }
  return ans;
}
solution(5,6,[
  "AAAAAA",
  "BBAATB",
  "BBAATB",
  "JJJTAA",
  "JJJTAA"
])