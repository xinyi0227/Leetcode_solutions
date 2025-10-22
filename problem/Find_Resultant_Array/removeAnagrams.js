var removeAnagrams = function(words) {
    let freqs = [];
    for (let i = 0; i < words.length; i++) {
        let freq = {};
        for (let ch of words[i]) {
            freq[ch] = (freq[ch] || 0) + 1;
        }
        freqs.push(freq);
    }
    
    function isEqual(freq1, freq2) {
        let keys1 = Object.keys(freq1);
        let keys2 = Object.keys(freq2);
        if (keys1.length !== keys2.length) return false;
        for (let key of keys1) {
            if (freq1[key] !== freq2[key]) return false;
        }
        return true;
    }
    
    let ans = [words[0]];
    for (let i = 1; i < words.length; i++) {
        if (!isEqual(freqs[i], freqs[i - 1])) {
            ans.push(words[i]);
        }
    }
    return ans;
};