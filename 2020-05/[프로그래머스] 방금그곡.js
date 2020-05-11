function map(melody) {
  const ma = [];
  let i = 0;
  while(i < melody.length){
    if(melody[i+1] === "#"){
      const mapped = 
        String.fromCharCode(melody[i].charCodeAt(0)+7);
      ma.push(mapped);
      i += 2;
    } else{
      ma.push(melody[i]);
      ++i;
    }
  }
  return ma;
}

function solution(m, musicinfos) {
  m = map([...m]);
  const ret = [];
  for(let k=0; k<musicinfos.length; ++k) {
    const info = musicinfos[k];
    const infoArr = info.split(",");
    let [st, et, title, melody] = infoArr;
    st = Number(st.split(":")[0])*60 + Number(st.split(":")[1]);
    et = Number(et.split(":")[0])*60 + Number(et.split(":")[1]);
    const interval = et - st;
    const ma = map([...melody]);
    const mlen = ma.length;
    let rm = "";
    if(interval > mlen){
      for(let i=0; i<~~(interval/mlen); ++i) 
        rm += ma.join("");
      rm += ma.slice(0, interval%mlen).join("");
    } else
      rm = ma.slice(0,interval).join("");
    if(rm.includes(m.join("")))
      ret.push({idx:k,interval,title});
  }
  ret.sort((a,b) => {
    if(a.interval !== b.interval) return b.interval-a.interval;
    return a.k - b.k;
  });
  return ret.length ? ret[0].title :"(None)";
}

solution("CC#BCC#BCC#BCC#B",["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"])