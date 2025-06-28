#include <iostream>
#include "../include/studentManager.h"
#include "../include/student.h"

int main()
{
    StudentManager manager;
    int choice;

    do
    {
        std::cout << "Menu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Find Student by ID\n";
        std::cout << "4. Sort Students\n";
        std::cout << "5. Display Students\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer
        switch (choice)
        {
        case 1:
        {
            std::string id, name;
            float mathScore, physicsScore, chemistryScore;
            SexType sex;
            int sexChoice;

            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cin.ignore(); // Clear the newline character from the input buffer
            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << "Enter Math Score: ";
            std::cin >> mathScore;
            std::cout << "Enter Physics Score: ";
            std::cin >> physicsScore;
            std::cout << "Enter Chemistry Score: ";
            std::cin >> chemistryScore;
            std::cout << "Choice sex (0 - Nam, 1 - Nu): ";
            std::cin >> sexChoice;
            if (sexChoice == 0)
            {
                sex = SexType::MALE;
            }
            else if (sexChoice == 1)
            {
                sex = SexType::FEMALE;
            }
            else
            {
                std::cout << "sexChoice is not valid.\n";
                continue;
            }

            manager.addStudent(Student(id, name, (mathScore + physicsScore + chemistryScore)/3, sex, mathScore, physicsScore, chemistryScore));
            std::cout << "Student added successfully.\n";
            break;
        }
        case 2:
        {
            std::string id;
            std::cout << "Enter ID of the student to remove: ";
            std::cin >> id;
            manager.removeStudent(id);
            std::cout << "Student removed successfully.\n";
            break;
        }
        case 3:
        {
            std::string id;
            std::cout << "Enter ID of the student to find: ";
            std::cin >> id;
            Student *student = manager.findStudentByID(id);
            if (student)
            {
                std::cout << "Found Student: " << student->getName() << ", ID: " << student->getID() << ", GPA: " << student->getGPA() << "\n";
            }
            else
            {
                std::cout << "Student not found.\n";
            }
            break;
        }
        case 4:
        {
            int sortChoice;
            std::cout << "Sort by (0 - Name, 1 - ID, 2 - GPA): ";
            std::cin >> sortChoice;
            SortType sortType;
            switch (sortChoice)
            {
            case 0:
                sortType = BY_NAME;
                break;
            case 1:
                sortType = BY_ID;
                break;
            case 2:
                sortType = BY_GPA;
                break;
            default:
                std::cout << "Invalid choice.\n";
                continue;
            }
            manager.sortStudents(sortType);
            std::cout << "Students sorted successfully.\n";
            break;
        }

        case 5:
        {
            const std::list<Student> &students = manager.getStudents();
            if (students.empty())
            {
                std::cout << "No students available.\n";
            }
            else
            {
                std::cout << "Students List:\n";
                for (const auto &student : students)
                {
                    std::cout << "ID: " << student.getID() << ", Name: " << student.getName() << ", GPA: " << student.getGPA() << "\n";
                }
            }
            break;
        }

        case 0:
            std::cout << "Exiting...\n";
            break;
       
            
        default:
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }
    } while (choice != 0) ;
    return 0;
}    