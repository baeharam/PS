function checkCondition(s, m, e, A){
  if(A[s] < A[m] && A[m] > A[e]) return true;
  if(A[s] > A[m] && A[m] < A[e]) return true;
  return false;
}

function solution(A) {
  let bi = A[0] <= A[1], eq = A[0] === A[1], len = A.length;
  let c = 0, s = -1, e = -1;
  for(let i=2; i<len; i++){
    if(eq && A[i-1] === A[i]) return -1;
    let ci = A[i-1] <= A[i];
    if((bi && ci) || (!bi && !ci)){
      ++c;
      s = i - 2;
      e = i;
    }
    bi = ci;
    eq = A[i-1] === A[i];
  }
  if(c > 1) return -1;
  if(!c) return 0;
  let ans = 1;
  if((s-1 < 0 && A[s+1] != A[e]) || (s-1 >= 0 && checkCondition(s-1,s+1,e,A))) ++ans;
  if((e+1 >= len && A[s] != A[s+1]) || (s+1 <= len-1 && checkCondition(s,s+1,e+1,A))) ++ans;
  return ans;
}