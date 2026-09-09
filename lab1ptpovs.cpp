#include "lab1ptpovs.h"
#include <fstream>
#include <iterator>
#include <limits>

/// <summary>
/// Removes non-alphabetic characters and converts all letters to lowercase.
/// </summary>
/// <param name="word">Input word to clean.</param>
/// <returns>Cleaned word containing only alphabetic characters in lowercase.</returns>
static std::string cleanWord(const std::string& word) {
    std::string result;
    for (char ch : word) {
        if (std::isalpha(static_cast<unsigned char>(ch)))
            result.push_back(std::tolower(static_cast<unsigned char>(ch)));
    }
    return result;
}

/// <summary>
/// Checks if a number is prime.
/// </summary>
/// <param name="n">Number to check.</param>
/// <returns>true if number is prime, false otherwise.</returns>
static bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int limit = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= limit; i += 2)
        if (n % i == 0) return false;
    return true;
}

std::map<std::string, int> countUniqueWords(const std::string& text) {
    std::map<std::string, int> wordCount;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) ++wordCount[cleaned];
    }
    return wordCount;
}

std::map<std::string, std::vector<int>> indexWordPositions(const std::string& text) {
    std::map<std::string, std::vector<int>> wordPositions;
    std::istringstream iss(text);
    std::string word;
    int pos = 0;
    while (iss >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) wordPositions[cleaned].push_back(pos);
        ++pos;
    }
    return wordPositions;
}

void squarePrimes(std::vector<int>& vec) {
    for (int& v : vec)
        if (isPrime(v)) v *= v;
}

void sortOddEven(std::vector<int>& vec) {
    std::vector<int> odds, evens;
    for (int v : vec) {
        if (v % 2 == 0) evens.push_back(v);
        else odds.push_back(v);
    }
    std::sort(odds.begin(), odds.end());
    std::sort(evens.begin(), evens.end(), std::greater<int>());
    vec.clear();
    vec.insert(vec.end(), odds.begin(), odds.end());
    vec.insert(vec.end(), evens.begin(), evens.end());
}

std::vector<int> findUniqueInRange(const std::vector<int>& vec, int min, int max) {
    std::set<int> s;
    for (int v : vec)
        if (v >= min && v <= max) s.insert(v);
    return std::vector<int>(s.begin(), s.end());
}

int main() {
    // Load book
    std::ifstream file("C:/Users/admin/source/repos/lab1ptpovs/WarandPeace.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open WarandPeace\n";
        return 1;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string text = buffer.str();

    int choice = 0;
    while (true) {
        std::cout << "\n1. Count unique words\n";
        std::cout << "2. Index word positions\n";
        std::cout << "3. Square prime numbers\n";
        std::cout << "4. Sort odd/even\n";
        std::cout << "5. Find unique in range\n";
        std::cout << "6. Run all tasks\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            auto counts = countUniqueWords(text);
            std::cout << "\nUnique words and their counts:\n";
            for (const auto& [word, cnt] : counts) {
                std::cout << word << " - " << cnt << '\n';
            }
        }
        else if (choice == 2) {
            auto positions = indexWordPositions(text);
            std::cout << "\nWord positions:\n";
            for (const auto& [word, vec] : positions) {
                std::cout << word << " - ";
                for (size_t i = 0; i < vec.size(); ++i) {
                    std::cout << vec[i];
                    if (i + 1 < vec.size()) std::cout << ", ";
                }
                std::cout << '\n';
            }
        }
        else if (choice == 3) {
            std::vector<int> nums = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 17 };
            squarePrimes(nums);
            std::cout << "\nSquares of prime numbers: ";
            for (int x : nums) std::cout << x << ' ';
            std::cout << '\n';
        }
        else if (choice == 4) {
            std::vector<int> nums = { 5, 2, 8, 1, 9, 4, 3, 7, 6 };
            sortOddEven(nums);
            std::cout << "\nSorted (odd ascending, even descending): ";
            for (int x : nums) std::cout << x << ' ';
            std::cout << '\n';
        }
        else if (choice == 5) {
            std::vector<int> nums = { 1, 3, 5, 7, 3, 9, 5, 10, 12, 4, 6, 8 };
            auto uniq = findUniqueInRange(nums, 3, 8);
            std::cout << "\nUnique numbers in range [3,8]: ";
            for (int x : uniq) std::cout << x << ' ';
            std::cout << '\n';
        }
        else if (choice == 6) {
            std::cout << "\n=== Running all tasks ===\n";

            auto counts = countUniqueWords(text);
            std::cout << "\nUnique words and their counts:\n";
            for (const auto& [word, cnt] : counts) {
                std::cout << word << " - " << cnt << '\n';
            }

            auto positions = indexWordPositions(text);
            std::cout << "\nWord positions:\n";
            for (const auto& [word, vec] : positions) {
                std::cout << word << " - ";
                for (size_t i = 0; i < vec.size(); ++i) {
                    std::cout << vec[i];
                    if (i + 1 < vec.size()) std::cout << ", ";
                }
                std::cout << '\n';
            }

            std::vector<int> nums = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 17 };
            squarePrimes(nums);
            std::cout << "\nSquares of prime numbers: ";
            for (int x : nums) std::cout << x << ' ';
            std::cout << '\n';

            nums = { 5, 2, 8, 1, 9, 4, 3, 7, 6 };
            sortOddEven(nums);
            std::cout << "Sorted (odd ascending, even descending): ";
            for (int x : nums) std::cout << x << ' ';
            std::cout << '\n';

            nums = { 1, 3, 5, 7, 3, 9, 5, 10, 12, 4, 6, 8 };
            auto uniq = findUniqueInRange(nums, 3, 8);
            std::cout << "Unique numbers in range [3,8]: ";
            for (int x : uniq) std::cout << x << ' ';
            std::cout << '\n';
        }
        else if (choice == 7) {
            std::cout << "\nBye 0_0\n";
            break;
        }
        else {
            std::cout << "\nInvalid choice\n";
        }
    }

    return 0;
}
