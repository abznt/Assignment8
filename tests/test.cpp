#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "Statistic.h"

namespace statistics {
    /**
     * @brief Tests the Statistic default constructor
     */
    TEST(StatisticTests, TestDefaultConstructor)
    {
        Statistic stat1;
        EXPECT_EQ(stat1.size(), 0);
    }

    /**
     * @brief Tests the Statistic initializer list constructor
     */
    TEST(StatisticTests, TestInitializerListConstructor)
    {
        Statistic stat1{1, 2, 3, 4};
        EXPECT_EQ(stat1.size(), 4);
        Statistic stat2{1, 2, 3, 4, 5, 6};
        EXPECT_EQ(stat2.size(), 6);
    }

    /**
     * @brief Tests the Statistic vector<double> constructor
     */
    TEST(StatisticTests, TestVectorConstructor)
    {
        std::vector<double> vec1{1, 2, 3};
        Statistic stat1{vec1};
        EXPECT_EQ(stat1.size(), vec1.size());
        std::vector<double> vec2{5, 6, 7, 8, 9};
        stat1.replaceData(vec2);
        EXPECT_EQ(stat1.size(), vec2.size());
    }

	/**
	 * @brief Tests the Statistic::mean() method
	*/
	TEST(StatisticTests, TestMean)
	{
		// Tests the arithmetic mean calculation with equal data, expected value is 3
		std::vector<double> equalNumbersMeanThree{ 3, 3, 3, 3, 3, 3, 3 };
		Statistic stat1{equalNumbersMeanThree};
		EXPECT_EQ(stat1.mean(), 3);
		// Tests the arithmetic mean calculation with varied data, expected value is 5
		std::vector<double> spacedNumbersMeanFive{ 3, 4, 5, 6, 7 };
		stat1.replaceData(spacedNumbersMeanFive);
		EXPECT_EQ(stat1.mean(), 5);
		// Tests the arithmetic mean calculation with no data, expected value is NaN
		Statistic stat2{};
		EXPECT_TRUE(std::isnan(stat2.mean()));
	}

	/**
	 * @brief Tests the Statistic::standardDevation() method 
	*/
	TEST(StatisticTests, TestStandardDeviation)
	{
		// Tests the standard devation calculation with equal data, expected value is 2
		std::vector<double> stdZero{ 2, 2, 2, 2, 2 };
		Statistic stat1{ stdZero };
		EXPECT_EQ(stat1.standardDeviation(), 0);
		// Tests the standard devation calculation with varied data, expected value is sqrt(5/2)
		std::vector<double> stdSqrt5over2{ 1, 2, 3, 4, 5 };
		stat1.replaceData(stdSqrt5over2);
		EXPECT_DOUBLE_EQ(stat1.standardDeviation(), std::sqrt(5.0 / 2.0));
		// Tests the standard devation calculation with no data, expected value is NaN
		Statistic stat2{};
		EXPECT_TRUE(std::isnan(stat2.standardDeviation()));
	}

	/**
	 * @brief Tests the Statistic::add(double x) method
	 */
	TEST(StatisticTests, TestAddDouble)
    {
        // Tests the add() method
        Statistic stat1;
        EXPECT_EQ(stat1.size(), 0);
        stat1.add(1.0);
        EXPECT_EQ(stat1.size(), 1);
        stat1.add(2.0);
        EXPECT_EQ(stat1.size(), 2);
    }

    /**
     * @brief Tests the Statistic::add(std::vector<double> data) method
     */
    TEST(StatisticTests, TestAddVector)
    {
	    // Tests the add() method
	    Statistic stat1;
	    std::vector<double> vec1{1, 2, 3};
	    stat1.add(vec1);
	    EXPECT_EQ(stat1.size(), vec1.size());
	    std::vector<double> vec2{4, 5};
	    stat1.add(vec2);
	    EXPECT_EQ(stat1.size(), vec1.size() + vec2.size());
    }
}