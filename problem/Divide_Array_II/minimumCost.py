from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums, k, dist):
        n = len(nums)
        k -= 1
        
        left_set = SortedList()
        right_set = SortedList()
        current_sum = 0

        for i in range(1, dist + 2):
            left_set.add(nums[i])
            current_sum += nums[i]
        
        while len(left_set) > k:
            element = left_set.pop()
            current_sum -= element
            right_set.add(element)
            
        min_cost = current_sum

        for i in range(dist + 2, n):
            outgoing = nums[i - dist - 1]
            if outgoing in left_set:
                left_set.remove(outgoing)
                current_sum -= outgoing
            else:
                right_set.remove(outgoing)

            incoming = nums[i]
            if left_set and incoming < left_set[-1]:
                left_set.add(incoming)
                current_sum += incoming
            else:
                right_set.add(incoming)

            while len(left_set) < k and right_set:
                element = right_set.pop(0)
                left_set.add(element)
                current_sum += element
            while len(left_set) > k:
                element = left_set.pop()
                current_sum -= element
                right_set.add(element)

            min_cost = min(min_cost, current_sum)

        return nums[0] + min_cost