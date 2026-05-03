#include <iostream>
#include <string>

// Главная функция
int main(){
   // имя пользователя
    std::string name;
    //Ввод имени
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
