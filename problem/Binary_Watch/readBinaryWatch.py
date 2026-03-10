class Solution:
    def readBinaryWatch(self, turnedOn):
        result = []
        for h in range(12):
            for m in range(60):
                if (bin(h).count('1') + bin(m).count('1')) == turnedOn:
                    result.append("{}:{:02d}".format(h, m))
        return result