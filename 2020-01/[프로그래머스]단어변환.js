function solution(begin, target, words) {
    const q = [];
    const v = Array(words.length).fill(false);
    q.push({word: begin, change: 0});
    while(q.length) {
        const f = q.shift();
        const w = f.word;
        const c = f.change;
        if(w === target) return c;
        const filtered = words.filter((word, idx) => {
            let diff = 0;
            for(let i=0; i<word.length; i++){
                if(w[i] !== word[i]) ++diff;
                if(diff > 1) return false;
            }
            if(v[idx]) return false;
            v[idx] = true;
            return true;
        });
        filtered.forEach((word) => q.push({word, change: c+1}));
    }
    return 0;
}