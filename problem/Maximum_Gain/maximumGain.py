class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        stack1=[]
        stack2=[]
        profit=0
        if x>y:
            for c in s:
                stack1.append(c)
                while len(stack1)>=2 and stack1[-2]=="a" and stack1[-1]=="b":
                    stack1.pop()
                    stack1.pop()
                    profit+=x
            for c in stack1:
                stack2.append(c)
                while len(stack2) >= 2:
                    if stack2[-2] == 'b' and stack2[-1] == 'a':
                        stack2.pop()
                        stack2.pop()
                        profit += y
                    else:
                        break
            
        else:
            for c in s:
                stack1.append(c)
                while len(stack1)>=2 and stack1[-2]=="b" and stack1[-1]=="a":
                    stack1.pop()
                    stack1.pop()
                    profit+=y
            
            for c in stack1:
                stack2.append(c)
                while len(stack2) >= 2:
                    if stack2[-2] == 'a' and stack2[-1] == 'b':
                        stack2.pop()
                        stack2.pop()
                        profit += x
                    else:
                        break
        return profit