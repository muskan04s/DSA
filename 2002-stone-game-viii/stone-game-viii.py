from itertools import accumulate

class Solution:
    def stoneGameVIII(self, stones: list[int]) -> int:
        # Compute prefix sums
        pref = list(accumulate(stones))
        
        # Base case: last possible pick (taking all stones)
        max_diff = pref[-1]
        
        # Iterate backwards from second-to-last index down to index 1
        for i in range(len(stones) - 2, 0, -1):
            max_diff = max(max_diff, pref[i] - max_diff)
            
        return max_diff