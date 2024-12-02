#include <iostream>
#include <sstream>
#include <string>

class Solution {
public:
    int isPrefixOfWord(const std::string& sentence, const std::string& searchWord) {
        std::istringstream stream(sentence); // To break the sentence into words
        std::string word;
        int index = 1; // Word index starts at 1
        
        while (stream >> word) { // Extract each word from the sentence
            // Check if searchWord is a prefix of word
            if (word.find(searchWord) == 0) {
                return index; // Return the 1-based index of the word
            }
            index++;
        }
        
        return -1; // If no word matches
    }
};

int gain() {
    Solution solution;

    // Test case 1
    std::string sentence1 = "i love eating burger";
    std::string searchWord1 = "burg";
    std::cout << solution.isPrefixOfWord(sentence1, searchWord1) << std::endl; // Output: 4

    // Test case 2
    std::string sentence2 = "this problem is an easy problem";
    std::string searchWord2 = "pro";
    std::cout << solution.isPrefixOfWord(sentence2, searchWord2) << std::endl; // Output: 2

    // Test case 3
    std::string sentence3 = "i am tired";
    std::string searchWord3 = "you";
    std::cout << solution.isPrefixOfWord(sentence3, searchWord3) << std::endl; // Output: -1

    return 0;
}
