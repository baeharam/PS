function makePrettyTable(input) {
  const c = {}, l = {};
  input.header.forEach(h => { c[h] = [] });
  for(let b of input.body) {
    for(let i=0; i<b.length; i++){
      c[input.header[i]].push(b[i]);
    }
  }
  for(let [k,v] of Object.entries(c)){
    let ml = k.length;
    for(let vv of v) ml = Math.max(ml, vv.length);
    l[k] = ml;
  }
  let r = "";
  for(let v of Object.values(l)){
    r += "+";
    for(let i=0; i<v+2; i++) r += "-";
  }
  r += "+\n";
  for(let k of Object.keys(c)){
    r += "| ";
    r += k;
    for(let i=0; i<l[k]+1-k.length; i++) r += " ";
  }
  r += "|\n";
  for(let v of Object.values(l)){
    r += "+";
    for(let i=0; i<v+2; i++) r += "-";
  }
  r += "+\n";
  for(let b of input.body){
    for(let i=0; i<b.length; i++){
      const key = input.header[i];
      r += "| ";
      r += b[i];
      for(let j=0; j<l[key]+1-b[i].length; j++) r += " ";
    }
    r += "|\n";
  }
  for(let v of Object.values(l)){
    r += "+";
    for(let i=0; i<v+2; i++) r += "-";
  }
  r += "+";
  return r;
}

makePrettyTable({"header":["Name","Location","People"],"body":[["Gangnam Office","Gangnamdaero 51, 1","14"],["Yangjae Office","Taebongro 114","12"],["Daejeon Office","Munjiro 193","3"]]}
);