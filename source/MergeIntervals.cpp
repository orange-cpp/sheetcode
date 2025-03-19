//
// Created by Vlad on 3/9/2025.
//
#include <gtest/gtest.h>

#include <algorithm>
#include <map>
#include <vector>

// LeetCode: https://leetcode.com/problems/merge-intervals/
namespace merge_intervals
{
    class Solution final
    {
    public:
        [[nodiscard]]
        static std::vector<std::vector<int>> merge(std::vector<std::vector<int>> intervals)
        {
            if (intervals.empty())
                return {};

            std::ranges::sort(intervals, [](auto& a, auto& b) {return a[0] < b[0];});

            std::vector<std::vector<int>> result {intervals.front()};

            int prev = 0;

            for (int cur = 1; cur < intervals.size(); ++cur)
            {
                if (CanBeMerged(result[prev], intervals[cur]))
                    result.back() = MergeIntervals(result[prev], intervals[cur]);
                else
                {
                    result.emplace_back(intervals[cur]);
                    ++prev;
                }
            }
            return result;
        }
    private:
        [[nodiscard]]
        static bool CanBeMerged(const std::vector<int> &first, const std::vector<int> &second)
        {
            return first.at(1) >= second.at(0);
        }

        [[nodiscard]]
        static std::vector<int> MergeIntervals(const std::vector<int> &first, const std::vector<int> &second)
        {
            return {std::min(first.at(0), second.at(0)), std::max(first.at(1), second.at(1))};
        }
    };
}
TEST(MergeIntervals, Tes1)
{
    const std::vector<std::vector<int>> correctAnswer = {{1, 5}};
    EXPECT_EQ(merge_intervals::Solution::merge({{1, 4}, {4, 5}}), correctAnswer);
}
TEST(MergeIntervals, Tes2)
{
    const std::vector<std::vector<int>> correctAnswer = {{1, 6}, {8, 10}, {15, 18}};
    EXPECT_EQ(merge_intervals::Solution::merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}}), correctAnswer);
}
TEST(MergeIntervals, Tes3)
{
    const std::vector<std::vector<int>> correctAnswer = {{1, 3}, {4, 7}};
    EXPECT_EQ(merge_intervals::Solution::merge({{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}}), correctAnswer);
}