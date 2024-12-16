#include "Dictionary.h"

// Constructor
Dictionary::Dictionary() {
    loadFromFile("dictionary.dat"); // Load existing words from file
}

// Add a new word to the dictionary
void Dictionary::addWord(const std::string& german, const std::string& english) {
    words.push_back(std::make_pair(german, english));
    std::cout << "Added: " << german << " -> " << english << std::endl;
}

// Delete a word from the dictionary
void Dictionary::deleteWord(const std::string& german) {
    auto it = std::remove_if(words.begin(), words.end(),
        [&german](const std::pair<std::string, std::string>& word) {
            return word.first == german;
        });
    if (it != words.end()) {
        words.erase(it, words.end());
        std::cout << "Deleted: " << german << std::endl;
    }
    else {
        std::cout << "Word not found: " << german << std::endl;
    }
}

// Lookup a word in the dictionary
std::string Dictionary::lookupWord(const std::string& german) {
    for (const auto& word : words) {
        if (word.first == german) {
            return word.second;
        }
    }
    return "Word not found.";
}

// List all words in the dictionary
void Dictionary::listWords() {
    std::cout << "German - English Dictionary:\n";
    for (const auto& word : words) {
        std::cout << word.first << " -> " << word.second << std::endl;
    }
}

// Save the dictionary to a binary file
void Dictionary::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    for (const auto& word : words) {
        size_t germanSize = word.first.size();
        size_t englishSize = word.second.size();
        outFile.write(reinterpret_cast<const char*>(&germanSize), sizeof(germanSize));
        outFile.write(word.first.c_str(), germanSize);
        outFile.write(reinterpret_cast<const char*>(&englishSize), sizeof(englishSize));
        outFile.write(word.second.c_str(), englishSize);
    }
    outFile.close();
}

// Load the dictionary from a binary file
void Dictionary::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) return; // If file doesn't exist, return

    while (inFile) {
        size_t germanSize, englishSize;
        inFile.read(reinterpret_cast<char*>(&germanSize), sizeof(germanSize));
        if (inFile.eof()) break; // Check for end of file
        std::string german(germanSize, ' ');
        inFile.read(&german[0], germanSize);
        inFile.read(reinterpret_cast<char*>(&englishSize), sizeof(englishSize));
        std::string english(englishSize, ' ');
        inFile.read(&english[0], englishSize);
        words.push_back(std::make_pair(german, english));
    }
    inFile.close();
}