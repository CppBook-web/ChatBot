#include "learner.h"
#include <iostream>
#include <string>
#include <fstream>

/*
Следующая функция будет искать переданную фразу в файле памяти.
Если есть совпадение, будет выведен ответ, сохраненный под начальной фразой.
Если ответ не найден, Learner повторит фразу и предложит
пользователю ввести ответ. Этот ответ будет сохранен в файле памяти
вместе с начальной фазой.
*/

void Learner::respond(const std::string phrase){
    std::fstream memory;
    memory.open("memory.txt", std::ios::in);      // Открыть файл памяти
    if (memory.fail()) {                          // Создать файл если его не существует
        memory.open("memory.txt", std::ios::out);
        memory.close();                           // Закрыть файл
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
    memory.close();                              // Фраза не найдена в памяти
    
    memory.open("memory.txt",
                std::ios::out | std::ios::app);  // Открыть файл и добавить в конец файла
    memory << phrase << std::endl;               // Записать полученную фразу в память

    answer(phrase);                              // Повторить фразу, введенную пользователем
    std::string userResponse;
    getline(std::cin, userResponse);             // Получить подходящий ответ
    memory << userResponse << std::endl;         // Записать подходящий ответ в память
    memory.close();                              
}

void Learner::answer(const std::string phrase) {  // Вывод ответа Learner
    std::cout << "- " << phrase << std::endl;
}
