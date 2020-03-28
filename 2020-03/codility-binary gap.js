function solution(N) {
  let q = N, r = -1, one = false, z = 0, ans = 0;
  while (q > 1) {
      r = q % 2;
      q = ~~(q / 2);
      if (one) {
          if(!r) ++z;
          else {
              ans = Math.max(ans, z);
              z = 0;
          }
      } else if(r) {
          one = true;
      }
  }
  ans = Math.max(ans, z);
  return ans;
}