class Solution:
    def numSubmat(self, mat):
        r, c = len(mat), len(mat[0])
        ans = 0
        h = [0] * c
        
        for i in range(r):
            for j in range(c):
                h[j] = h[j] + 1 if mat[i][j] else 0
            
            sum_arr = [0] * c
            st = []
            
            for j in range(c):
                while st and h[st[-1]] >= h[j]:
                    st.pop()
                
                if st:
                    p = st[-1]
                    sum_arr[j] = sum_arr[p] + h[j] * (j - p)
                else:
                    sum_arr[j] = h[j] * (j + 1)
                
                st.append(j)
                ans += sum_arr[j]
        
        return ans
