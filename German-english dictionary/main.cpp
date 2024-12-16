#include "Dictionary.h"

int main() {
    Dictionary dict; // Create a Dictionary object

    int choice;
    do {
        std::cout << "\nGerman-English Dictionary Menu:\n";
        std::cout << "1. Add Word\n";
        std::cout << "2. Delete Word\n";
        std::cout << "3. Lookup Word\n";
        std::cout << "4. List All Words\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string german, english;
        switch (choice) {
        case 1: // Add Word
            std::cout << "Enter German word: ";
            std::cin >> german;
            std::cout << "Enter English translation: ";
            std::cin >> english;
            dict.addWord(german, english);
            break;
        case 2: // Delete Word
            std::cout << "Enter German word to delete: ";
            std::cin >> german;
            dict.deleteWord(german);
            break;
        case 3: // Lookup Word
            std::cout << "Enter German word to lookup: ";
            std::cin >> german;
            std::cout << "Translation: " << dict.lookupWord(german) << std::endl;
            break;
        case 4: // List All Words
            dict.listWords();
            break;
        case 5: // Exit
            dict.saveToFile("dictionary.dat"); // Save dictionary to file
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}