#include "../include/studentManager.h"
#include <iostream>

void StudentManager::addStudent(const Student &Student)
{
    students.push_back(Student);
}

void StudentManager::removeStudent(const std::string &id)
{
    auto it = students.begin();
    while (it != students.end())
    {
        if (it->getID() == id)
        {
            it = students.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

Student *StudentManager::findStudentByID(const std::string &id)
{
    for (auto &student : students){ 
        if (student.getID() == id)
        {
            return &student;
        }
    }
    return nullptr;
}

void StudentManager::sortStudents(SortType sortType)
{
    students.sort([sortType](const Student &a, const Student &b) {
        switch (sortType)
        {
        case BY_NAME:
            //sort by name in ascending order (a->z)
            return a.getName() < b.getName();
        case BY_ID:
            //sort by ID in ascending order
            return a.getID() < b.getID();
        case BY_GPA:
            return a.getGPA() > b.getGPA(); // Sort by GPA in descending order
        default:
            return false;
        }
    });
}

const std::list<Student> &StudentManager::getStudents() const
{
    return students;
}

size_t StudentManager::getStudentCount() const
{
    return students.size();
}