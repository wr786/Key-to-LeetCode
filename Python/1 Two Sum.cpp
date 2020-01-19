class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mem_cnt = set()
        mem_pos = {}
        for idx, num in enumerate(nums):
            if (target - num) in mem_cnt:
                return [mem_pos.get(target - num), idx]
            mem_cnt.add(num)
            mem_pos[num] = idx
        return []