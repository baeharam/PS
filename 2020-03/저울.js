function solution(weight) {
  weight.sort((a,b) => a-b);
  if(weight[0] > 1) return 1;
  let sum = [weight[0]];
  weight.forEach((w,i) => { if(i) sum[i] = sum[i-1]+w });
  let ans = weight.reduce((a,c) => a+c,0)+1, i = 0;
  while(weight[i+1] <= sum[i]+1){
    i++;
  }
  if(i < weight.length) ans = sum[i]+1;
  return ans;
}