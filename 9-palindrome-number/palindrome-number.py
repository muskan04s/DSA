class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers and numbers ending in 0 (except 0) are not palindromes
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reverted_number = 0
        while x > reverted_number:
            reverted_number = reverted_number * 10 + x % 10
            x //= 10

        # For even lengths: x == reverted_number (e.g., 1221 -> x=12, reverted=12)
        # For odd lengths: x == reverted_number // 10 (e.g., 121 -> x=1, reverted=12)
        return x == reverted_number or x == reverted_number // 10