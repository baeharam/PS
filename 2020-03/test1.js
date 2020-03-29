function solution(A) {
  const count = {};
  for(let a of A){
    if(a > 100000) continue;
    if(!count.hasOwnProperty(a)) {
      count[a] = 1;
    } else {
      count[a]++;
    }
  }
  let ans = 0;
  for(let [k, v] of Object.entries(count)) {
    if(k == v) ans = Math.max(ans, k);
  }
  return ans;
}