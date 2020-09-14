#pragma once
#include <vector>
#include <initializer_list>

namespace statistics {
    /**
     * @brief A class used to perform statistical analysis on a set of numbers.
     */
	class Statistic
	{
	public:
		/**
		 * @brief Constructs an empty Statistic object.
		*/
		Statistic();

		/**
		 * @brief Constructs a Statistic object with a vector of doubles
		 * @param data Vector assigned to the current dataset
		*/
		explicit Statistic(std::vector<double>  data);

        /**
         * @brief Constructs a Statistic object using an initializer list of doubles
         * @param data Initializer list of doubles assigned to the current dataset
         */
		Statistic(std::initializer_list<double> data);

		/**
		 * @brief Appends a double to the dataset
		 * @param x Value to be appended to the current dataset
		*/
		void add(double x);

		/**
		 * @brief Appends a vector to the current dataset
		 * @param data Vector to be appended to the current dataset
		 */
		void add(std::vector<double> data);

		/**
		 * @brief Clears the current dataset and replaces it
		 * @param data New data
		*/
		void replaceData(const std::vector<double>& data);

		/**
		 * @brief Computes the arithmetic mean of the current dataset
		 * @return The arithmetic mean of the current dataset. NaN if empty.
		*/
		[[nodiscard]] double mean() const;

		/**
		 * @brief Computes the standard deviation of the current dataset
		 * @return The standard deviation of the current dataset. NaN if empty.
		*/
		[[nodiscard]] double standardDeviation() const;

        /**
         * @return The size of the current dataset
         */
		[[nodiscard]] int size() const;

	private:
		std::vector<double> m_data;  // hidden dataset
	};
}

