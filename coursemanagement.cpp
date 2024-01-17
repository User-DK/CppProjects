#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Course {
private:
    std::string name;
    int ID;
    int assignedTeacherID;
    std::vector<int> studentIDs;

    using MyPair = std::pair<std::pair<std::string, int>, std::pair<int, std::vector<int>>>;
    std::vector<MyPair> courseInfo;

public:
    void Add(const std::string& name, int id, int teacherID, const std::vector<int>& students) {
        MyPair pair1 = std::make_pair(std::make_pair(name, ID), std::make_pair(assignedTeacherID, studentIDs));
        courseInfo.push_back(pair1);
    }

    void Remove(int id) {
        for (auto it = courseInfo.begin(); it != courseInfo.end(); ++it) {
            if (it->first.second == ID) {
                courseInfo.erase(it);
                break;
            }
        }
    }

    void Update(int id, int teacherID, const std::vector<int>& students) {
        for (auto& element : courseInfo) {
            if (element.first.second == ID) {
                element.first.first = name;
                element.second.first = teacherID;
                element.second.second = students;
                break;
            }
        }
    }

    void Fetch(int id) {
        for (const auto& element : courseInfo) {
            if (element.first.second == ID) {
                std::cout << "\nName: " << element.first.first
                          << "\tID: " << element.first.second
                          << "\tAssigned Teacher ID: " << element.second.first
                          << "\tEnrolled Student IDs: ";
                for (int studentID : element.second.second) {
                    std::cout << studentID << " ";
                }
                std::cout << std::endl;
            }
        }
    }


};


int main(){
    
    while (true) {
                    Course courseManager;
                    std::cout << "1. Add Course\n";
                    std::cout << "2. Remove Course\n";
                    std::cout << "3. Update Course\n";
                    std::cout << "4. Fetch Course Details\n";
                    std::cout << "5. Exit\n";
                    int choice;
                    std::cin >> choice;

                    switch (choice) {
                        case 1: {
                            std::string name;
                            int id, teacherID;
                            std::vector<int> studentIDs;

                            std::cout << "Enter Course Name: ";
                            std::cin >> name;

                            std::cout << "Enter Course ID: ";
                            std::cin >> id;

                            std::cout << "Enter Assigned Teacher ID: ";
                            std::cin >> teacherID;

                            int studentCount;
                            std::cout << "Enter number of enrolled students: ";
                            std::cin >> studentCount;
                            studentIDs.resize(studentCount);
                            std::cout << "Enter Student IDs: ";
                            for (int i = 0; i < studentCount; ++i) {
                                std::cin >> studentIDs[i];
                            }

                            courseManager.Add(name, id, teacherID, studentIDs);
                            break;
                        }
                        case 2: {
                            int id;
                            std::cout << "Enter Course ID to Remove: ";
                            std::cin >> id;
                            courseManager.Remove(id);
                            break;
                        }
                        case 3: {
                            int id, teacherID;
                            std::vector<int> studentIDs;

                            std::cout << "Enter Course ID to Update: ";
                            std::cin >> id;

                            std::cout << "Enter Updated Assigned Teacher ID: ";
                            std::cin >> teacherID;

                            int studentCount;
                            std::cout << "Enter updated number of enrolled students: ";
                            std::cin >> studentCount;
                            studentIDs.resize(studentCount);
                            std::cout << "Enter Updated Student IDs: ";
                            for (int i = 0; i < studentCount; ++i) {
                                std::cin >> studentIDs[i];
                            }

                            courseManager.Update(id, teacherID, studentIDs);
                            break;
                        }
                        case 4: {
                            int id;
                            std::cout << "Enter Course ID to Fetch Details: ";
                            std::cin >> id;
                            courseManager.Fetch(id);
                            break;
                        }
                        case 5:
                            return false;
                        default:
                            std::cout << "Invalid choice\n";
                    }
} return 0;}