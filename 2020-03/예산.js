const solution = (budgets, M) => {
  let l = 1, r = M, ans = 0, max = 0;
  const sum = budgets.reduce((a,b)=> {
    if(max < b) max = b;
    return a+b;
  },0);
  if(sum < M) return max;
  while(l <= r){
    let m = ~~((l + r) / 2);
    const s = budgets.reduce((a,c) => a + (c < m ? c : m), 0);
    if (s > M) r = m - 1;
    else {
      ans = m;
      l = m + 1;
    }
  }
  return ans;
};

const t = Array(100000).fill(100000);

console.log(solution(t, 1000000000));

console.log(Math.max(1,2,3));