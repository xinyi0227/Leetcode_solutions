class Solution:
    def fractionToDecimal(self, numerator, denominator):
        if numerator == 0:
            return "0"
        
        result = []
        
        if (numerator < 0) ^ (denominator < 0):
            result.append("-")
        
        num = abs(numerator)
        den = abs(denominator)
        
        result.append(str(num // den))
        remainder = num % den
        
        if remainder == 0:
            return "".join(result)
        
        result.append(".")
        seen = {}
        
        while remainder != 0:
            if remainder in seen:
                pos = seen[remainder]
                result.insert(pos, "(")
                result.append(")")
                break
            
            seen[remainder] = len(result)
            remainder *= 10
            digit = remainder // den
            result.append(str(digit))
            remainder = remainder % den
        
        return "".join(result)
