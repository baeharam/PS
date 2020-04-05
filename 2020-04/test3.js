function countPairs(input) {
  const o = {};
  o[input[0][0]] = { [input[0][1]]: true };
  let ans = 0;
  for(let i=1; i<input.length; i++){
    if(o.hasOwnProperty(input[i][1]) && o[input[i][1]][input[i][0]]) ++ans;
    if(!o.hasOwnProperty(input[i][0])) o[input[i][0]] = {};
    o[input[i][0]][input[i][1]] = true;
  }
  return ans;
}

countPairs([[3, 4], [1, 2], [5, 2], [7, 10], [4, 3], [2, 5]]);