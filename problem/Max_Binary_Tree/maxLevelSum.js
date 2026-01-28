/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxLevelSum = function(root) {
    if (!root) {
        return 0;
    }

    let queue = [root];
    let maxLevel = 1;
    let maxSum = -Infinity;
    let level = 1;

    while (queue.length > 0) {
        let levelSum = 0;
        let levelSize = queue.length;

        for (let i = 0; i < levelSize; i++) {
            let node = queue.shift();
            levelSum += node.val;

            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
            }
        }

        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = level;
        }

        level++;
    }

    return maxLevel;
};