function solution(A) {
  A.sort((a,b) => b-a);
  const obj = {};
  for(let a of A) {
    let digitSum = [...String(a)].reduce((a,c) => a + Number(c), 0);
    if(!obj.hasOwnProperty(digitSum)) obj[digitSum] = [];
    obj[digitSum].push(a);
  }
  let ans = -1;
  Object.values(obj)
  .filter(v => v.length >= 2)
  .forEach(v => { ans = Math.max(ans, v[0] + v[1]) });
  return ans;
}

const obj = { a: 1, b: 2 };
console.log(Object.values(obj) instanceof Array);