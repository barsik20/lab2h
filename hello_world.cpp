#include <iostream>
#include <string>

// Main function
int main() {
    // user's name
    std::string name;
    std::cout << "Enter your name: ";
    // entering your name
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
