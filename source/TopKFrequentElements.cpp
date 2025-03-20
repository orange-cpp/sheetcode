//
// Created by Vlad on 3/9/2025.
//
#include <gtest/gtest.h>
#include <vector>
#include <queue>
namespace top_k_frequent_elements
{
    class Solution final
    {
    public:
        [[nodiscard]]
        static std::vector<int> topKFrequent(const std::vector<int>& nums, const int k)
        {
            std::unordered_map<int, int> counter;

            for (const auto& number : nums)
                counter[number]++;

            using container = std::pair<int, int>;
            auto comp = [](const auto& a, const auto& b) {return a.second < b.second;};

            std::priority_queue<container, std::vector<container>, decltype(comp)> queue(comp);

            for (const auto& pair : counter)
                queue.emplace(pair);

            std::vector<int> out;
            out.reserve(k);

            for (int i = 0; i < k; i++)
            {
                if (queue.empty())
                    break;
                out.emplace_back(queue.top().first);
                queue.pop();
            }

            return out;
        }
    };
}
TEST(TopKFrequentElements, Tes1)
{
    const std::vector<int> correctAnswer = {1, 2};
    EXPECT_EQ(top_k_frequent_elements::Solution::topKFrequent({1,1,1,2,2,3}, 2), correctAnswer);
}