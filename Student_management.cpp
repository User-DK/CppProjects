#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Student {
public:
    std::string name;
    int ID;
    std::string studentClass;
    char grade;

    using MyPair = std::pair<std::pair<std::string, int>, std::pair<std::string, char>>;
    std::vector<MyPair> studentInfo;

    void Add(int id, const std::string& name, const std::string& studentClass, char grade) {
        MyPair pair1 = std::make_pair(std::make_pair(name, id), std::make_pair(studentClass, grade));
        studentInfo.push_back(pair1);
    }

    void Remove(int id) {
        for (auto it = studentInfo.begin(); it != studentInfo.end(); ++it) {
            if (it->first.second == id) {
                studentInfo.erase(it);
                break;
            }
        }
    }

    void Update(int id, const std::string& newClass, char newGrade) {
        for (auto& element : studentInfo) {
            if (element.first.second == id) {
                element.first.first = name;
                element.second.first = newClass;
                element.second.second = newGrade;
                break;
            }
        }
    }

    void Fetch(int id) {
        for (const auto& element : studentInfo) {
            if (element.first.second == id) {
                std::cout << "\nName: " << element.first.first
                          << "\tID: " << element.first.second
                          << "\tClass: " << element.second.first
                          << "\tGrade: " << element.second.second << std::endl;
                break;
            }
        }
    }
};

int main() {
    Student studentManager;

    while (true) {
        std::cout << "Student Management:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Fetch Student Details\n";
        std::cout << "5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                std::string studentClass;
                char grade;

                std::cout << "Enter Student ID: ";
                std::cin >> id;

                std::cout << "Enter Student Name: ";
                std::cin >> name;

                std::cout << "Enter Class: ";
                std::cin >> studentClass;

                std::cout << "Enter Grade: ";
                std::cin >> grade;

                Student newStudent;
                newStudent.ID = id;
                newStudent.name = name;
                newStudent.studentClass = studentClass;
                newStudent.grade = grade;

                studentManager.Add(id, name, studentClass, grade);
                std::cout << "Student added successfully.\n";
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Student ID to Remove: ";
                std::cin >> id;

                studentManager.Remove(id);
                std::cout << "Student removed successfully.\n";
                break;
            }
            case 3: {
                int id;
                std::string newClass;
                char newGrade;

                std::cout << "Enter Student ID to Update: ";
                std::cin >> id;

                std::cout << "Enter Updated Class: ";
                std::cin >> newClass;

                std::cout << "Enter Updated Grade: ";
                std::cin >> newGrade;

                studentManager.Update(id, newClass, newGrade);
                std::cout << "Student updated successfully.\n";
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter Student ID to Fetch Details: ";
                std::cin >> id;

                studentManager.Fetch(id);
                break;
            }
            case 5:
                return false;
            default:
                std::cout << "Invalid choice\n";
        }
    }
    
    return 0;
}
