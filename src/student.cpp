#include "../include/student.h"

Student::Student(std::string id, std::string name, float score, SexType sex, float mathScore, float physicsScore, float chemistryScore)
    : id(id), name(name), gpa(score), sex(sex), mathScore(mathScore), physicsScore(physicsScore), chemistryScore(chemistryScore) 
{
}

std::string Student::getID() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

float Student::getGPA() const {
    return (mathScore + physicsScore + chemistryScore) / 3.0f;
}

SexType Student::getSex() const{
    return sex;
}

AcademicType Student::getAcademic() const {
    if (gpa >= 8.0) {
        return EXCELLENT;
    } else if (gpa >= 6.5) {
        return GOOD;
    } else if (gpa >= 5.0) {
        return MIDDLE;
    } else {
        return POOR;
    }
}

float Student::getMathScore() const {
    return mathScore;
}

float Student::getPhysicsScore() const {
    return physicsScore;
}

float Student::getChemistryScore() const {
    return chemistryScore;
}

void Student::setMathScore(float score) {
    mathScore = score;
}

void Student::setPhysicsScore(float score) {
    physicsScore = score;
}

void Student::setChemistryScore(float score) {
    chemistryScore = score;
}
