function solution(record) {
  const state = {};
  for (let a of record) {
    const s = a.split(" ");
    const b = s[0],
      id = s[1],
      name = s[2];
    switch (b) {
      case "Enter":
      case "Change":
        state[id] = name;
        break;
      default:
        break;
    }
  }
  const ans = [];
  for (let a of record) {
    const s = a.split(" ");
    const b = s[0],
      id = s[1],
      name = s[2];
    switch (b) {
      case "Enter":
        ans.push(`${state[id]}님이 들어왔습니다.`);
        break;
      case "Leave":
        ans.push(`${state[id]}님이 나갔습니다.`);
        break;
      default:
        break;
    }
  }
  return ans;
}
