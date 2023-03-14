#include "learner.h"
#include <iostream>
#include <string>
#include <fstream>

void Learner::respond(const std::string phrase){
    std::fstream memory;
    memory.open("memory.txt", std::ios::in);      // открыть файл памяти
    if (memory.fail()) {                          // создать файл если его не существует
        memory.open("memory.txt", std::ios::out);
        memory.close();
    }
    
    while( !memory.eof() ) {          // Поиск до конца файла
        std::string identifier;
        getline(memory,identifier);   // Получение следующей фразы
        
        if (identifier == phrase) {   // Если это та фраза, которую мы ищем
            std::string response;
            getline(memory,response);                       
            return answer(response);     // Получаем ответ      
        }
    }
    memory.close();                              // Фраза не найдена в памяти. Закрыть файл
    
    memory.open("memory.txt",
                std::ios::out | std::ios::app);  // Открыть файл и добавить в конец файла
    memory << phrase << std::endl;               // Записать полученную фразу в память

    answer(phrase);                                 // Повторить фразу, введенную пользователем
    std::string userResponse;
    getline(std::cin, userResponse);             // Получить подходящий ответ
    memory << userResponse << std::endl;         // Записать подходящий ответ в память
    memory.close();                              // Закрыть файл
}

void Learner::answer(const std::string phrase) {    // Вывод ответа Learner
    std::cout << "- " << phrase << std::endl;
}
