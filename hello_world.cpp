#include <iostream>
#include <string>

int main(){
    // Переменная для хранения
    std::string name;
    // Ввод имени
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
