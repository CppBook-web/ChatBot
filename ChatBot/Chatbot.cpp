#include <iostream>
#include <string>
#include <windows.h>
#include "learner.h"

int main() {
    SetConsoleCP(1251);             // Ввод - вывод русского языка в консоли
    SetConsoleOutputCP(1251);

    Learner chatbot = {};           // Создание объекта Learner

    while (true) {
        std::cout << "- ";          // Ввод пользователя
        std::string phrase;
        getline(std::cin, phrase);  // Ввода длинной строки в переменную phrase
        if (phrase == "пока") {     // Выход из программы
            std::cout << "- было приятно пообщаться" << std::endl;
            break;
        }
        else {
            chatbot.respond(phrase);  // Вывод ответа learner
        }
    }
}