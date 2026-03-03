/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var balanceBST = function(root) {
    const vals = [];
    const inorder = (node) => {
        if (!node) return;
        inorder(node.left);
        vals.push(node.val);
        inorder(node.right);
    };

    const build = (l, r) => {
        if (l > r) return null;
        const mid = Math.floor((l + r) / 2);
        const node = new TreeNode(vals[mid]);
        node.left = build(l, mid - 1);
        node.right = build(mid + 1, r);
        return node;
    };

    inorder(root);
    return build(0, vals.length - 1);
};