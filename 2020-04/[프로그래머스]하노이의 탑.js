function solution(n) {
  const ans = [];
  hanoi(1, 3, n);

  function hanoi(from, to, num) {
    if (num === 1) {
      ans.push([from, to]);
      return;
    }
    const other = 6 - (from + to);
    hanoi(from, other, num - 1);
    hanoi(from, to, 1);
    hanoi(other, to, num - 1);
  }

  return ans;
}
