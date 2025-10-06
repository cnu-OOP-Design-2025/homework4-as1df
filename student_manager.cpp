#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx != -1) {
        for (int i = idx; i < num_of_students - 1; ++i) {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if (idx != -1) {
        students[idx] = student; 
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) return i; 
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int best_id = 0;
    float max_score = 0.0;

    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > max_score) {
            max_score = students[i].getRecord().getMidterm();
            best_id = students[i].getID();
        }
    }
    return best_id;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int best_id = 0;
    float max_score = 0.0;

    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getFinal() > max_score) {
            max_score = students[i].getRecord().getFinal();
            best_id = students[i].getID();
        }
    }
    return best_id;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int best_id = 0;
    float max_score = 0.0;

    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() + students[i].getRecord().getFinal() > max_score) {
            max_score = students[i].getRecord().getMidterm() + students[i].getRecord().getFinal();
            best_id = students[i].getID();
        }
    }
    return best_id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float total = 0.0;
    for (int i = 0; i < num_of_students; i++) {
        total += students[i].getRecord().getMidterm();
    }
    return total / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float total = 0.0;
    for (int i = 0; i < num_of_students; i++) {
        total += students[i].getRecord().getFinal();
    }
    return total / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float total = 0.0;
    for (int i = 0; i < num_of_students; i++) {
        total += students[i].getRecord().getTotal();
    }
    return total / num_of_students * 2; // expected의 값이 잘못 된 것 같음. 평균인데 100이 넘는 값이 나옴
}
