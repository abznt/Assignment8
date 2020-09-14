#include "FileUtil.h"
#include <fstream>
#include <sstream>


std::vector<double> FileUtil::readCsv(const std::string& fileName)
{
	std::vector<double> data;
	std::ifstream csvFile(fileName);
	if (!csvFile.is_open())
	{
		throw std::runtime_error("Could not open csv file");
	}
	std::string line;
	double val;
	while (std::getline(csvFile, line))
	{
		std::stringstream linestream{ line };
		linestream >> val;
		data.emplace_back(val);
	}
	csvFile.close();
	return data;
}