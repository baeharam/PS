function solution(s) {
  let idx = -1,
    ans = 0;
  for (let i = 0; i < s.length; i++) {
    console.log(s[i]);
    if (s[i] === "a" || s[i] === "z") {
      if (idx !== -1) {
        if (
          (s[i] === "a" && s[idx] === "z") ||
          (s[i] === "z" && s[idx] === "a")
        )
          ++ans;
      }
      idx = i;
    }
  }
  return ans;
}
