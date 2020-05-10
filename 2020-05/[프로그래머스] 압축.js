function solution(msg) {
  const ans = [], dic = {}, len = msg.length;
  for(let i=0; i<26; ++i)
    dic[String.fromCharCode(65+i)] = i+1;
  let sidx = 0, didx = 1, last = 27;
  while(sidx < len) {
    while(didx <= len && msg.slice(sidx,didx) in dic) 
      ++didx;
    --didx;
    ans.push(dic[msg.slice(sidx,didx)]);
    dic[msg.slice(sidx,didx+1)] = last++;
    sidx = didx++;
  }
  return ans;
}

solution("KAKAO");