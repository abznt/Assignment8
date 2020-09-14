#include "Statistic.h"

#include <cmath>
#include <utility>


namespace statistics {
	Statistic::Statistic() = default;

	Statistic::Statistic(std::vector<double> data)
		: m_data{std::move(data)} {}

    Statistic::Statistic(std::initializer_list<double> data)
        : m_data{data} {}

	void Statistic::add(double x)
	{
		m_data.emplace_back(x);
	}

	void Statistic::add(std::vector<double> data)
	{
	    m_data.insert(m_data.end(), data.begin(), data.end());
	}

	void Statistic::replaceData(const std::vector<double>& data)
	{
		m_data.clear();
		m_data = data;
	}

	double Statistic::mean() const
	{
		double mean = std::nan("");  // default return value
		// If there is data, compute the arithmetic mean
		if (!m_data.empty())
		{
			double sum = 0;
			for (const auto& value : m_data)
			{
				sum += value;
			}
			// mean = sum(xi) / N
			mean = sum / m_data.size();
		}
		return mean;
	}

	double Statistic::standardDeviation() const
	{
		double standardDeviation = std::nan(""); // default return value
		// If there is the data, compute the standard deviation
		if (!m_data.empty())
		{
			double sumOfSquares = 0;
			double sum = 0;
			for (const auto& value : m_data)
			{
				sumOfSquares += value * value;
				sum += value;
			}
			double numer = sumOfSquares - (sum * sum / m_data.size());
			int denom = m_data.size() - 1;
			// STD = sqrt( (sum(xi^2) - sum(xi)^2 / N) / (N - 1))
			standardDeviation = std::sqrt(numer / denom);
		}
		return standardDeviation;
	}

	int Statistic::size() const
	{
	    return m_data.size();
	}
}