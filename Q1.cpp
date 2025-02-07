#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class MemoryCalculate {
private:
// Student ID & Name
    T id;
    std::string name;

public:
    MemoryCalculate(T id, std::string name) : id(id), name(name) {}
    
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }
    // Getter for ID
        T getId() const {
        return id;
    }
};

class StudentManagement {
private:
    std::vector<MemoryCalculate<int>> students;

public:
    void addStudent(int id, std::string name) {
        students.push_back(MemoryCalculate<int>(id, name));
    }
    
    void displayStudents() const {
        if (students.empty()) {
            std::cout << "No students in the list." << std::endl;
            return;
        }
        for (const auto &student : students) {
            student.display();
        }
    }
    
    void removeStudent(int id) {
        auto it = std::remove_if(students.begin(), students.end(), [id](const MemoryCalculate<int> &student) {
            return student.getId() == id;
        });
        
        if (it != students.end()) {
            students.erase(it, students.end());
            std::cout << "Student with ID " << id << " removed successfully." << std::endl;
        } else {
            std::cout << "Student with ID " << id << " not found." << std::endl;
        }
    }
    
    void searchStudent(int id) const {
        for (const auto &student : students) {
            if (student.getId() == id) {
                std::cout << "Student found: ";
                student.display();
                return;
            }
        }
        std::cout << "Student with ID " << id << " not found." << std::endl;
    }
};

int main() {
    StudentManagement sm;
    int choice, id;
    std::string name;
    
    do {
        std::cout << "\nStudent Management System" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Display All Students" << std::endl;
        std::cout << "3. Remove Student by ID" << std::endl;
        std::cout << "4. Search Student by ID" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                sm.addStudent(id, name);
                break;
            case 2:
                sm.displayStudents();
                break;
            case 3:
                std::cout << "Enter ID to remove: ";
                std::cin >> id;
                sm.removeStudent(id);
                break;
            case 4:
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                sm.searchStudent(id);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Try again." << std::endl;
        }
    } while (choice != 5);
    
    return 0;
}
