#pragma once
#include <vector>
#include <string>

class FileUtil
{
public:
	static std::vector<double> readCsv(const std::string& fileName);
};

