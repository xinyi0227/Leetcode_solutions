class Solution:
    def subtreeWithAllDeepest(self, root):
        if not root: return None
        
        parent = {root: None}
        queue = [root]
        last_level = []
        
        while queue:
            last_level = queue[:]
            next_queue = []
            for node in queue:
                if node.left:
                    parent[node.left] = node
                    next_queue.append(node.left)
                if node.right:
                    parent[node.right] = node
                    next_queue.append(node.right)
            queue = next_queue
            
        deepest = set(last_level)
        while len(deepest) > 1:
            next_set = set()
            for node in deepest:
                next_set.add(parent[node])
            deepest = next_set
            
        return list(deepest)[0]