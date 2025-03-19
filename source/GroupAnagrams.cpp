//
// Created by Vlad on 3/19/2025.
//
#include <gtest/gtest.h>
#include <string>

namespace group_anagrams
{
    class Solution
    {
    public:
        [[nodiscard]]
        static std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs)
        {
            std::unordered_map<std::string, std::vector<std::string>> groups;

            for (const auto& str: strs)
            {
                auto sorted_str = str;
                std::ranges::sort(sorted_str);

                groups[sorted_str].emplace_back(str);
            }

            std::vector<std::vector<std::string>> out;


            for (auto& group : groups | std::views::values)
                out.emplace_back(std::move(group));

            return out;
        }
    };
} // namespace group_anagrams

[[nodiscard]]
bool CompareUnorderedVectors(std::vector<std::vector<std::string>> a, std::vector<std::vector<std::string>> b)
{
    for (auto& vec : a) std::ranges::sort(vec);
    for (auto& vec : b) std::ranges::sort(vec);
    std::ranges::sort(a);
    std::ranges::sort(b);
    return a == b;
}

TEST(GroupAnagrams, Test1)
{
    const std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    const std::vector<std::vector<std::string>> expected = {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
    EXPECT_TRUE(CompareUnorderedVectors(group_anagrams::Solution::groupAnagrams(input), expected));
}

TEST(GroupAnagrams, Test2)
{
    const std::vector<std::string> input = {""};
    const std::vector<std::vector<std::string>> expected = {{""}};
    EXPECT_TRUE(CompareUnorderedVectors(group_anagrams::Solution::groupAnagrams(input), expected));
}

TEST(GroupAnagrams, Test3)
{
    const std::vector<std::string> input = {"a"};
    const std::vector<std::vector<std::string>> expected = {{"a"}};
    EXPECT_TRUE(CompareUnorderedVectors(group_anagrams::Solution::groupAnagrams(input), expected));
}