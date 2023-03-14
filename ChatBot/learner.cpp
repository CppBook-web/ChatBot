#include "learner.h"
#include <iostream>
#include <string>
#include <fstream>

void Learner::respond(const std::string phrase){
    std::fstream memory;
    memory.open("memory.txt", std::ios::in);      // ������� ���� ������
    if (memory.fail()) {                          // ������� ���� ���� ��� �� ����������
        memory.open("memory.txt", std::ios::out);
        memory.close();
    }
    
    while( !memory.eof() ) {          // ����� �� ����� �����
        std::string identifier;
        getline(memory,identifier);   // ��������� ��������� �����
        
        if (identifier == phrase) {   // ���� ��� �� �����, ������� �� ����
            std::string response;
            getline(memory,response);                       
            return answer(response);     // �������� �����      
        }
    }
    memory.close();                              // ����� �� ������� � ������. ������� ����
    
    memory.open("memory.txt",
                std::ios::out | std::ios::app);  // ������� ���� � �������� � ����� �����
    memory << phrase << std::endl;               // �������� ���������� ����� � ������

    answer(phrase);                                 // ��������� �����, ��������� �������������
    std::string userResponse;
    getline(std::cin, userResponse);             // �������� ���������� �����
    memory << userResponse << std::endl;         // �������� ���������� ����� � ������
    memory.close();                              // ������� ����
}

void Learner::answer(const std::string phrase) {    // ����� ������ Learner
    std::cout << "- " << phrase << std::endl;
}