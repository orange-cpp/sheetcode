//
// Created by Vlad on 3/20/2025.
//
#include <vector>


namespace can_place_flowers
{
    class Solution
    {
    public:
        [[nodiscard]]
        static bool canPlaceFlowers(const std::vector<int>& flowerbed, int n)
        {
            int planted = 0;
            for (auto curr = flowerbed.cbegin(); curr != flowerbed.cend(); curr = std::next(curr))
                if (CanPlant(curr, flowerbed))
                {
                    planted++;
                    curr = std::next(curr);

                    if (curr == flowerbed.cend())
                        break;
                }

            return planted >= n;
        }

        static bool CanPlant(const std::vector<int>::const_iterator& place, const std::vector<int>& flowerbed)
        {
            if (*place == 1)
                return false;

            if (place == flowerbed.cbegin())
                return std::next(place) == flowerbed.cend() || *std::next(place) == 0;

            if (place == std::prev(flowerbed.cend()))
                return *std::prev(place) == 0;

            return *std::next(place) == 0 && *std::prev(place) == 0;
        }
    };
} // namespace can_place_flowers
TEST(CanPlaceFlowers, Tes1)
{
    const std::vector<int> correctAnswer = {0,0,1,0,0};
    EXPECT_EQ(can_place_flowers::Solution::canPlaceFlowers(correctAnswer, 1), true);
}
