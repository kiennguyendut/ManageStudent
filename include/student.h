#ifndef STUDENT_H
#define STUDENT_H

#include <string>

typedef enum
{
    BY_NAME,
    BY_ID,
    BY_GPA
} SortType;

typedef enum
{
    MALE,
    FEMALE
} SexType;

typedef enum
{
    EXCELLENT,
    GOOD,
    MIDDLE,
    POOR
} AcademicType;

class Student
{
private:
    std::string name;
    std::string id;
    float gpa;
    SexType sex;
    AcademicType academic;
    float mathScore;
    float physicsScore;
    float chemistryScore;

public:
    Student(std::string id, std::string name, float score, SexType sex, float mathScore, float physicsScore, float chemistryScore);
    std::string getID() const;
    std::string getName() const;
    float getGPA() const;
    SexType getSex() const;
    AcademicType getAcademic() const;
    float getMathScore() const;
    float getPhysicsScore() const;
    float getChemistryScore() const;
    void setMathScore(float score);
    void setPhysicsScore(float score);
    void setChemistryScore(float score);
};

#endif // SINHVIEN_H