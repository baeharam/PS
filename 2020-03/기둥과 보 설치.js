// https://programmers.co.kr/learn/courses/30/lessons/60061

const isb = (x,y,t) => {
  if(t[x+1][y] === 0 || t[x+1][y+1] === 0) return true;
  if(t[x][y-1] === 1 && t[x][y+1] === 1) return true;
  return false;
};

const isc = (x,y,t) => {
  if(t[x][y-1] === 1) return true;
  if(y === 0 || t[x+1][y] === 0) return true;
  return false;
};

const solution = (n, bf) => {
  const t = Array(100).fill(null).map(_ => Array(100).fill(Infinity));
  for(let info of bf){
    const x = info[0], y = info[1], type = info[2], oper = info[3];
    if(type === 0){
      if(oper === 0){
        t[x][y] = Infinity;
        if((t[x-1][y] === 1 && !isb(x-1,y,t)) ||
        (t[x-1][y] === 0 && !isc(x-1,y,t))) {
          t[x][y] = type;
          continue;
        }
      } else if(isc(x,y,t)){
        t[x][y] = type;
      }
    } else {
      if(oper === 0){
        t[x][y] = Infinity;
        if(t[x][y+1] === 0){
          t[x][y] = type;
          continue;
        } else if(
          (t[x][y-1] === 1 && t[x][y+1] === 0 && !isb(x,y-1,t)) ||
          (t[x][y+1] === 1 && t[x][y-1] === 0 && !isb(x,y+1,t)) ||
          (t[x][y-1] === 1 && t[x][y+1] === 1 && !isb(x,y-1,t) && !isb(x,y+1,t))){
          t[x][y] = type;
          continue;
        }
      } else if(isb(x,y,t)){
        t[x][y] = type;
      }
    }
  }
  const ans = [];
  t.forEach((r,ri) => r.forEach((c,ci) => { if(c !== Infinity) ans.push([ri,ci,c]); }));
  console.log(ans);
  return ans.sort((a,b) => a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]);
}

solution(5, [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]);