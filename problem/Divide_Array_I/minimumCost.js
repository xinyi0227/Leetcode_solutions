/**
 * @param {number[]} nums
 * @return {number}
 */
const minimumCost = A => {
    let α = 51, β = 51;

    for (let i = 1; i < A.length; i++) {
        β = Math.min(β, A[i]);
        if (β < α) [α, β] = [β, α];
        if (α === 1 && β === 1) return A[0] + 2;
    }

    return A[0] + α + β;
};