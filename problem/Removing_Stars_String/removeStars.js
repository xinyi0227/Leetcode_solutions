/**
 * @param {string} s
 * @return {string}
 */
var removeStars = function(s) {
    let c = "";
    for(let i = 0; i < s.length; i++){
        if(s[i] === '*'){
            c = c.slice(0, -1);
        }else{
            c += s[i];
        }
    }
    return c;
};