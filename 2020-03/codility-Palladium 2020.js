function solution(H) {
  const len = H.length;
  if(len === 1) return H[0];
  const a = [], b = [];
  let maxA = 0, maxB = 0;
  for(let i=0; i<len; ++i){
    maxA = Math.max(maxA, H[i]);
    a[i] = (i + 1) * maxA;
  }
  for(let i=len-1; i>=0; --i){
    maxB = Math.max(maxB, H[i]);
    b[i] = (len - i) * maxB;
  }
  let ans = Infinity;
  for(let i=0; i<len-1; ++i){
    const area = a[i] + b[i+1];
    ans = Math.min(ans, area);
  }
  return ans;
}

solution([1]);