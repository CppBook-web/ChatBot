#ifndef _LEARNER_H
#define _LEARNER_H

#include <iostream>

class Learner {
public:
    void respond(const std::string phrase);    // Получение фразы или обучение
    void answer(const std::string phrase);     // Вывод фразы
};

#endif
