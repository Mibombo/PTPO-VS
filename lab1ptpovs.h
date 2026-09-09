#ifndef LAB1PTPOVS_H
#define LAB1PTPOVS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <cmath>

/// <summary>
/// Counts unique words in the text. Word comparison is case-insensitive and ignores punctuation.
/// </summary>
/// <param name="text">Input text to analyze.</param>
/// <returns>Map where key is word and value is its frequency.</returns>
std::map<std::string, int> count_Unique_Words(const std::string& text);

/// <summary>
/// Indexes positions of each word in the text. Positions are zero-based word indices.
/// </summary>
/// <param name="text">Input text to analyze.</param>
/// <returns>Map where key is word and value is vector of positions where it occurs.</returns>
std::map<std::string, std::vector<int>> index_Word_Positions(const std::string& text);

/// <summary>
/// Squares every prime element of the vector. Non-primes stay unchanged.
/// Uses std::sqrt from the cmath library.
/// </summary>
/// <param name="vec">Vector that is updated in place.</param>
void square_Primes(std::vector<int>& vec);

/// <summary>
/// Sorts vector so odd numbers appear first in ascending order, followed by even numbers in descending order.
/// </summary>
/// <param name="vec">Vector that is updated in place.</param>
void sort_Odd_Even(std::vector<int>& vec);

/// <summary>
/// Finds unique numbers from the vector that fall within the specified range [min, max].
/// </summary>
/// <param name="vec">Vector to search.</param>
/// <param name="min">Lower bound of the range (inclusive).</param>
/// <param name="max">Upper bound of the range (inclusive).</param>
/// <returns>Vector of unique numbers that are in the specified range.</returns>
std::vector<int> find_Unique_In_Range(const std::vector<int>& vec, int min, int max);

#endif