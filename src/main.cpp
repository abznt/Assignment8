// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "FileUtil.h"
#include "Statistic.h"

/**
 * @brief Main entry point for the program
 */
int main()
{
    std::string dataFile{ "../distribution_data.csv" };
    std::cout << "Data file: " << dataFile << std::endl;
    std::vector<double> data = FileUtil::readCsv(dataFile);
    statistics::Statistic stat{ data };
    double mean = stat.mean();
    double stdev = stat.standardDeviation();
    std::cout << "Mean = " << mean << std::endl;
    std::cout << "Standard deviation = " << stdev << std::endl;
    return 0;
}
