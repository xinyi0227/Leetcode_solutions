class Solution:
    def balanceBST(self, root):
        vals = []
        def inorder(node):
            if not node: return
            inorder(node.left)
            vals.append(node.val)
            inorder(node.right)
            
        def build(l, r):
            if l > r: return None
            mid = (l + r) // 2
            node = TreeNode(vals[mid])
            node.left = build(l, mid - 1)
            node.right = build(mid + 1, r)
            return node
            
        inorder(root)
        return build(0, len(vals) - 1)