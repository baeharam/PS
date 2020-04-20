function solution(board, moves) {
  const len = board.length;
  const lastIndexList = Array(len).fill(-1);
  for (let i = 0; i < len; ++i) {
    let j = 0;
    while (j < len && !board[j][i]) ++j;
    if (j < len) lastIndexList[i] = j;
  }
  const box = [];
  let ans = 0;
  for (let move of moves) {
    const moveIndex = move - 1;
    if (lastIndexList[moveIndex] === -1) continue;
    const topElement = board[lastIndexList[moveIndex]][moveIndex];
    ++lastIndexList[moveIndex];
    if (lastIndexList[moveIndex] === len) lastIndexList[moveIndex] = -1;
    if (box.length && box[box.length - 1] === topElement) {
      box.pop();
      ans += 2;
    } else box.push(topElement);
  }
  return ans;
}
