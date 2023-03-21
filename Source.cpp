#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    double gpa;
    Student* next;

    Student(int id, string name, double gpa) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->next = NULL;
    }
};

class List {

private:
    Student* head;

public:

    List() {
        head = NULL;
    }

    bool searchStudentByID(int id) {

        Student* currentNode = head;

        while (currentNode != NULL) {
            if (currentNode->id == id) {
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }

    void insertNewStudent(Student* newStudent) {

        // Check if a student with the same ID already exists in the list
        if (searchStudentByID(newStudent->id)) {

            return;
        }

        if (head == NULL || newStudent->name > head->name) {
            newStudent->next = head;
            head = newStudent;
        }
        else {
            Student* currentNode = head;
            while (currentNode->next != NULL &&
                (currentNode->next->name > newStudent->name ||
                    (currentNode->next->name == newStudent->name &&
                        currentNode->next->id < newStudent->id))) {
                currentNode = currentNode->next;
            }
            newStudent->next = currentNode->next;
            currentNode->next = newStudent;
        }
    }

    void removeStudentByID(int id) {

        if (head == NULL) {

            return;
        }
        if (head->id == id) {

            head = head->next;
            return;
        }
        Student* currentNode = head;
        while (currentNode->next != NULL && currentNode->next->id != id) {
            currentNode = currentNode->next;
        }
        if (currentNode->next != NULL) {
            currentNode->next = currentNode->next->next;
        }
    }

    void removeStudentsBelowThreshold(double gpaThreshold) {

        while (head != NULL && head->gpa < gpaThreshold) {
            head = head->next;
        }

        if (head == NULL) {
            return;
        }

        Student* currentNode = head;

        while (currentNode->next != NULL) {

            if (currentNode->next->gpa < gpaThreshold) {
                currentNode->next = currentNode->next->next;
            }
            else {
                currentNode = currentNode->next;
            }
        }
    }

    void displayBestStudents() {

        if (head == NULL) {
            return;
        }
        double maxGPA = head->gpa;
        Student* currentNode = head;
        while (currentNode != NULL) {
            if (currentNode->gpa > maxGPA) {
                maxGPA = currentNode->gpa;
            }
            currentNode = currentNode->next;
        }
        currentNode = head;
        while (currentNode != NULL) {
            if (currentNode->gpa == maxGPA) {
                cout << "(" << currentNode->id << ", " << currentNode->name << ", " << currentNode->gpa << ") ";
            }
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void display() {

        Student* currentNode = head;

        while (currentNode != NULL) {
            cout << "(" << currentNode->id << ", " << currentNode->name << ", " << currentNode->gpa << ")" << endl;
            currentNode = currentNode->next;
        }
    }
};

int main() {

    List list;

    // Add students

    Student* student1 = new Student(15, "Rima", 90.4);
    Student* student2 = new Student(12, "Zein", 75.5);
    Student* student3 = new Student(17, "Adam", 83.1);
    Student* student4 = new Student(8, "Rima", 73);
    Student* student5 = new Student(90, "Rima", 67.3);
    Student* student6 = new Student(65, "Mazen", 90.4);
    Student* student7 = new Student(18, "Ziad", 83.2);
    Student* student8 = new Student(13, "Abed", 80);
    Student* student9 = new Student(65, "Lara", 85.2);


    // Insert students into the list

    list.insertNewStudent(student1);
    list.insertNewStudent(student2);
    list.insertNewStudent(student3);
    list.insertNewStudent(student4);
    list.insertNewStudent(student5);
    list.insertNewStudent(student6);
    list.insertNewStudent(student7);
    list.insertNewStudent(student8);
    list.insertNewStudent(student9);


    // Displaying the list

    cout << "Adding some students..." << endl;
    cout << "Printing the list..." << endl;
    list.display();
    cout << endl;

    // Deleting a student number

    int idDelete = 13;
    list.removeStudentByID(idDelete);
    cout << "Deleting student number " << idDelete << "..." << endl;
    cout << "Print the list..." << endl;
    list.display();
    cout << endl;

    // Entering a threshold GPA and removing all students below threshold and printing the list

    double gpaThreshold;
    cout << "Enter a threshold: ";
    cin >> gpaThreshold;
    list.removeStudentsBelowThreshold(gpaThreshold);
    cout << "Removing students below GPA threshold " << gpaThreshold << "..." << endl;

    //Display students after remove

    cout << "Printing the list..." << endl;
    list.display();
    cout << endl;

    // Display the best students
    cout << "Displaying best students..." << endl;
    list.displayBestStudents();
    cout << endl;

    return 0;
}
