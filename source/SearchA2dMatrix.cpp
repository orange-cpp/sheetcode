//
// Created by Vlad on 3/20/2025.
//
#include <gtest/gtest.h>
#include <queue>
#include <vector>


namespace search_2d_matrix
{
    class Solution
    {
    public:
        [[nodiscard]]
        static bool searchMatrix(const std::vector<std::vector<int>>& matrix, const int target)
        {
            const auto length = matrix.size()* matrix.front().size();

            int low = 0;
            int high = length-1;

            while (low <= high)
            {
                const int mid = low + (high - low) / 2;

                if (At(mid, matrix) == target)
                    return true;

                if (At(mid, matrix) < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            return false;
        }
        [[nodiscard]]
        static const int& At(const std::size_t index, const std::vector<std::vector<int>>& matrix)
        {
            const auto rows = matrix.size();
            const auto cols = matrix.front().size();

            const auto rowIndex = index / cols;
            const auto colIndex = index % cols;


            return matrix.at(rowIndex).at(colIndex);
        }
    };
} // namespace search_2d_matrix
TEST(SearchA2dMatrix, Tes1)
{
    const std::vector<std::vector<int>> correctAnswer = {{1,3}};
    EXPECT_EQ(search_2d_matrix::Solution::searchMatrix(correctAnswer, 3), true);
}