//
// Created by Vlad on 3/9/2025.
//
#include <gtest/gtest.h>
#include <ranges>
#include <unordered_map>
#include <vector>

// LeetCode: https://leetcode.com/problems/merge-intervals/
namespace two_sum
{
    class Solution
    {
    public:
        [[nodiscard]] static std::vector<int> twoSum(std::vector<int> &nums, int target)
        std::vector<int> twoSum(const std::vector<int>& nums,const  int target)
        {
            std::unordered_map<int, int> map;

            for (int i = 0; i < nums.size(); i++)
            {
                auto needed = target - nums[i];

                if (map.contains(needed))
                    return {i, map[needed]};

                map[nums[i]] = i;
            }
            return {};
        }
    };
} // namespace two_sum
