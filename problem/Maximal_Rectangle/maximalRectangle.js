/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    if (matrix.length === 0) return 0;
    const m = matrix.length;
    const n = matrix[0].length;
    const hist = new Array(n).fill(0);
    let ans = 0;

    const getArea = (heights) => {
        let st = [];
        let maxArea = 0;
        for (let i = 0; i <= heights.length; i++) {
            let h = (i === heights.length) ? 0 : heights[i];
            while (st.length > 0 && h < heights[st[st.length - 1]]) {
                let height = heights[st.pop()];
                let width = st.length === 0 ? i : i - st[st.length - 1] - 1;
                maxArea = Math.max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    };

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            hist[j] = matrix[i][j] === '1' ? hist[j] + 1 : 0;
        }
        ans = Math.max(ans, getArea(hist));
    }
    return ans;
};