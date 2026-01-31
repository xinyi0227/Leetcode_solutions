/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var subtreeWithAllDeepest = function(root) {
    if (!root) return null;

    let parent = new Map();
    let queue = [root];
    parent.set(root, null);
    let lastLevel = [];

    while (queue.length > 0) {
        let size = queue.length;
        lastLevel = [...queue];
        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            if (node.left) {
                parent.set(node.left, node);
                queue.push(node.left);
            }
            if (node.right) {
                parent.set(node.right, node);
                queue.push(node.right);
            }
        }
    }

    let deepest = new Set(lastLevel);
    while (deepest.size > 1) {
        let next = new Set();
        for (let node of deepest) {
            next.add(parent.get(node));
        }
        deepest = next;
    }

    return Array.from(deepest)[0];
};