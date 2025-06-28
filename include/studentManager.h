#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <list>
#include "Student.h"

class StudentManager {
private:
    std::list<Student> students;
public:
    // Add a new student
    void addStudent(const Student& student);

    // Remove a student by ID
    void removeStudent(const std::string& id);

    // Find a student by ID
    Student* findStudentByID(const std::string& id);

    // Sort students by a given criteria
    void sortStudents(SortType sortType);

    // Get the list of students
    const std::list<Student>& getStudents() const;

    // Get the number of students
    size_t getStudentCount() const;
};
#endif 