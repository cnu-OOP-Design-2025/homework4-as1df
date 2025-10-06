#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
/* TODO: Initializer list 사용해 초기화 해보기 */
    :midterm(midterm), final(final) {};

float StudentRecord::getTotal() const {
    /* TODO */
    return (midterm + final) / 2.0f;
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this -> midterm = midterm;
    this -> final = final;
}


/* Student */

Student::Student() 
/* TODO: Initializer list 사용해 초기화 해보기 */
    :id(0), record(), name("") {};

Student::Student(const char *name, int id, float midterm, float final)
/* TODO: Initializer list 사용해 초기화 해보기 */
    :id(id), record(midterm, final), name(name) {};

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this -> name = name;
    this -> record.updateScores(midterm, final);
}

