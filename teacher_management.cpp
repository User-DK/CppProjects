#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Teacher {
    public:
    std::string name;
    int ID;
    std::string subject;
    double salary;

    using MyPair = std::pair<std::pair<std::string, int>, std::pair<std::string, double>>;
    std::vector<MyPair> teacherInfo;

    void Add(int id, const std::string& name, const std::string& subject, double salary) {
        MyPair pair1 = std::make_pair(std::make_pair(name, ID), std::make_pair(subject, salary));
        teacherInfo.push_back(pair1);
    }

    void Remove(int id) {
        for (auto it = teacherInfo.begin(); it != teacherInfo.end(); ++it) {
            if (it->first.second == id) {
                teacherInfo.erase(it);
                break;
            }
        }
    }

    void Update(int id, const std::string& newSubject, double newSalary) {
        for (auto& element : teacherInfo) {
            if (element.first.second == id) {
                element.first.first = name;
                element.second.first = newSubject;
                element.second.second = newSalary;
                break;
            }
        }
    }

    void Fetch(int id) {
        for (const auto& element : teacherInfo) {
            if (element.first.second == id) {
                std::cout << "\nName: " << element.first.first
                          << "\tID: " << element.first.second
                          << "\tSubject: " << element.second.first
                          << "\tSalary: " << element.second.second << std::endl;
                break;
            }
        }
    }
};

int main() {
    Teacher teacherManager;

    while (true) {
        std::cout << "Teacher Management:\n";
        std::cout << "1. Add Teacher\n";
        std::cout << "2. Remove Teacher\n";
        std::cout << "3. Update Teacher\n";
        std::cout << "4. Fetch Teacher Details\n";
        std::cout << "5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                std::string subject;
                double salary;

                std::cout << "Enter Teacher ID: ";
                std::cin >> id;

                std::cout << "Enter Teacher Name: ";
                std::cin >> name;

                std::cout << "Enter Subject: ";
                std::cin >> subject;

                std::cout << "Enter Salary: ";
                std::cin >> salary;

                Teacher newTeacher;
                newTeacher.ID = id;
                newTeacher.name = name;
                newTeacher.subject = subject;
                newTeacher.salary = salary;

                teacherManager.Add(id, name, subject, salary);
                std::cout << "Teacher added successfully.\n";
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Teacher ID to Remove: ";
                std::cin >> id;

                teacherManager.Remove(id);
                std::cout << "Teacher removed successfully.\n";
                break;
            }
            case 3: {
                int id;
                std::string newSubject;
                double newSalary;

                std::cout << "Enter Teacher ID to Update: ";
                std::cin >> id;

                std::cout << "Enter Updated Subject: ";
                std::cin >> newSubject;

                std::cout << "Enter Updated Salary: ";
                std::cin >> newSalary;

                teacherManager.Update(id, newSubject, newSalary);
                std::cout << "Teacher updated successfully.\n";
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter Teacher ID to Fetch Details: ";
                std::cin >> id;

                teacherManager.Fetch(id);
                break;
            }
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }
    
    return 0;
}
