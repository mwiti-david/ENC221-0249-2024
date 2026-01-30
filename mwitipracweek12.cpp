#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declarations
class Course;
class Student;

// Course class
class Course {
private:
    string courseCode;
    string courseName;
    int credits;
    vector<Student*> enrolledStudents;
public:
    Course(string code, string name, int cred) {
        courseCode = code;
        courseName = name;
        credits = cred;
    }
    
    string getCourseCode() {
        return courseCode;
    }
    
    string getCourseName() {
        return courseName;
    }
    
    int getCredits() {
        return credits;
    }
    
    void addStudent(Student* student) {
        enrolledStudents.push_back(student);
    }
    
    void displayCourseInfo() {
        cout << "Course: " << courseCode << " - " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Enrolled Students: " << enrolledStudents.size() << endl;
    }
};

// Student class (has association with Course)
class Student {
private:
    string studentID;
    string name;
    vector<Course*> registeredCourses;
public:
    Student(string id, string n) {
        studentID = id;
        name = n;
    }
    
    string getStudentID() {
        return studentID;
    }
    
    string getName() {
        return name;
    }
    
    void registerCourse(Course* course) {
        registeredCourses.push_back(course);
        course->addStudent(this);
        cout << name << " registered for " << course->getCourseName() << endl;
    }
    
    void displayStudentInfo() {
        cout << "\nStudent ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Registered Courses:" << endl;
        for(int i = 0; i < registeredCourses.size(); i++) {
            cout << "  - " << registeredCourses[i]->getCourseCode() 
                 << ": " << registeredCourses[i]->getCourseName() << endl;
        }
    }
    
    int getTotalCredits() {
        int total = 0;
        for(int i = 0; i < registeredCourses.size(); i++) {
            total += registeredCourses[i]->getCredits();
        }
        return total;
    }
};

// Department class (has dependency on Student and Course)
class Department {
private:
    string deptName;
    vector<Student*> students;
    vector<Course*> courses;
public:
    Department(string name) {
        deptName = name;
    }
    
    void addStudent(Student* student) {
        students.push_back(student);
        cout << "Student " << student->getName() << " added to " << deptName << endl;
    }
    
    void addCourse(Course* course) {
        courses.push_back(course);
        cout << "Course " << course->getCourseName() << " added to department" << endl;
    }
    
    void displayDepartmentInfo() {
        cout << "\n========================================" << endl;
        cout << "Department: " << deptName << endl;
        cout << "========================================" << endl;
        cout << "Total Students: " << students.size() << endl;
        cout << "Total Courses: " << courses.size() << endl;
    }
    
    void displayAllStudents() {
        cout << "\nAll Students in " << deptName << ":" << endl;
        for(int i = 0; i < students.size(); i++) {
            students[i]->displayStudentInfo();
        }
    }
    
    void displayAllCourses() {
        cout << "\nAll Courses in " << deptName << ":" << endl;
        for(int i = 0; i < courses.size(); i++) {
            cout << "\n";
            courses[i]->displayCourseInfo();
        }
    }
};

// Registration class (handles registration process - dependency)
class Registration {
public:
    static void processRegistration(Student* student, Course* course) {
        cout << "\nProcessing registration..." << endl;
        student->registerCourse(course);
        cout << "Registration successful!" << endl;
    }
    
    static void generateReport(Student* student) {
        cout << "\n--- Registration Report ---" << endl;
        student->displayStudentInfo();
        cout << "Total Credits: " << student->getTotalCredits() << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    cout << "=== College Registration System ===" << endl << endl;
    
    // Create department
    Department csDept("Computer Science");
    
    // Create courses
    Course* course1 = new Course("CS101", "Programming Basics", 3);
    Course* course2 = new Course("CS201", "Data Structures", 4);
    Course* course3 = new Course("CS301", "Database Systems", 3);
    
    csDept.addCourse(course1);
    csDept.addCourse(course2);
    csDept.addCourse(course3);
    
    cout << endl;
    
    // Create students
    Student* student1 = new Student("S001", "John Doe");
    Student* student2 = new Student("S002", "Jane Smith");
    
    csDept.addStudent(student1);
    csDept.addStudent(student2);
    
    cout << endl;
    
    // Register students for courses
    Registration::processRegistration(student1, course1);
    Registration::processRegistration(student1, course2);
    Registration::processRegistration(student2, course1);
    Registration::processRegistration(student2, course3);
    
    // Display information
    csDept.displayDepartmentInfo();
    csDept.displayAllStudents();
    
    cout << endl;
    Registration::generateReport(student1);
    Registration::generateReport(student2);
    
    // Cleanup
    delete course1;
    delete course2;
    delete course3;
    delete student1;
    delete student2;
    
    return 0;
}
