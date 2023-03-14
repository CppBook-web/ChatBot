#ifndef _LEARNER_H
#define _LEARNER_H

#include <iostream>

class Learner {
public:
    void respond(const std::string phrase);    // Used to get, or teach a response
    void answer(const std::string phrase);        // Used to textually phrase
};

#endif
