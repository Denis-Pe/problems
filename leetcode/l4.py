from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged = nums1[:]
        merged.extend(nums2)
        merged = sorted(merged)

        mid = int(len(merged) / 2)
        if len(merged) % 2 == 1:
            return merged[mid]
        else:
            return (merged[mid-1]+merged[mid]) / 2

