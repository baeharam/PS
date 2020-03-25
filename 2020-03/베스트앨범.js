// https://programmers.co.kr/learn/courses/30/lessons/42579

const solution = (g, p) => {
  const o = {};
  g.forEach((gr,i) => {
    if(!(gr in o)) o[gr] = [];
    o[gr].push({ num: i, play: p[i] });
  });
  const arr = [];
  for(let [k,v] of Object.entries(o)){
    v.sort((a,b) => a.play === b.play ? a.num - b.num : b.play - a.play);
    arr.push({ name: k, sum: v.reduce((a,c) => a+c.play, 0)});
  }
  arr.sort((a,b) => b.sum - a.sum);
  const ans = [];
  arr.forEach(a => { ans.push(...o[a.name].map(oo => oo.num).slice(0,2)); });
  return ans;
}

solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]);
