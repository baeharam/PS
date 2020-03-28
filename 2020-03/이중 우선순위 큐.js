class DoubleHeap {
  constructor() {
    this.maxHeap = [null];
    this.minHeap = [null];
  }

  insert(item) {
    const maxHeap = this.maxHeap;
    const minHeap = this.minHeap;
    let idx = maxHeap.length;
    while(idx > 1 && maxHeap[~~(idx/2)] < item){
      maxHeap[idx] = maxHeap[~~(idx/2)];
      idx = ~~(idx/2);
    }
    maxHeap[idx] = item;
    idx = minHeap.length;
    while(idx > 1 && minHeap[~~(idx/2)] > item){
      minHeap[idx] = minHeap[~~(idx/2)];
      idx = ~~(idx/2);
    }
    minHeap[idx] = item;
  }

  dmin() {
    if(this.maxHeap.length >= 2) this.maxHeap.pop();
    const minHeap = this.minHeap;
    if(minHeap.length === 1) return;
    if(minHeap.length === 2) return minHeap.pop();
    const last = minHeap.pop();
    let p = 1, child = 2;
    const size = minHeap.length-1;
    while(child <= size) {
      if(child<size && minHeap[child] > minHeap[child+1]) child++;
      if(last < minHeap[child]) break;
      minHeap[p] = minHeap[child];
      p = child;
      child *= 2;
    }
    minHeap[p] = last;
  }

  dmax() {
    if(this.minHeap.length >= 2) this.minHeap.pop();
    const maxHeap = this.maxHeap;
    if(maxHeap.length === 1) return;
    if(maxHeap.length === 2) return maxHeap.pop();
    const last = maxHeap.pop();
    let p = 1, child = 2;
    const size = maxHeap.length-1;
    while(child <= size) {
      if(child<size && maxHeap[child] < maxHeap[child+1]) child++;
      if(last > maxHeap[child]) break;
      maxHeap[p] = maxHeap[child];
      p = child;
      child *= 2;
    }
    maxHeap[p] = last;
  }
}

function solution(operations) {
  const dh = new DoubleHeap();
  operations.forEach(o => {
    o = o.split(' ');
    if(o[0] === 'I') dh.insert(Number(o[1]));
    else if(o[0] === 'D'){
      if(o[1] === '1') dh.dmax();
      else if(o[1] === '-1') dh.dmin();
    }
    console.log(dh.minHeap, dh.maxHeap);
  });
  const max = dh.maxHeap.length < 2 ? 0 : dh.maxHeap[1];
  const min = dh.minHeap.length < 2 ? 0 : dh.minHeap[1];
  return [max,min];
}

solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]);