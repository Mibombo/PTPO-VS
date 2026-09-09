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

std::map<std::string, int> countUniqueWords(const std::string& text);
std::map<std::string, std::vector<int>> indexWordPositions(const std::string& text);
void squarePrimes(std::vector<int>& vec);
void sortOddEven(std::vector<int>& vec);

std::vector<int> findUniqueInRange(const std::vector<int>& vec, int min, int max);

#endif