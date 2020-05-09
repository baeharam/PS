function solution(files) {
  const ans = [];
  for(let i=0; i<files.length; ++i) {
    const file = files[i];
    let idx = 0, h, n;
    while(!/[0-9]/.test(file[idx])) ++idx;
    h = (file.slice(0, idx)).toUpperCase();
    const sidx = idx;
    while(/[0-9]/.test(file[idx]) && idx-sidx < 5) ++idx;
    n = parseInt(file.slice(sidx, idx), 10);
    ans.push({h,n,i});
  }
  ans.sort((a,b) => {
    if(a.h !== b.h) return (a.h).localeCompare(b.h);
    if(a.n !== b.n) return a.n - b.n;
    return a.i - b.i;
  });
  return ans.map(a => files[a.i]);
}

solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])