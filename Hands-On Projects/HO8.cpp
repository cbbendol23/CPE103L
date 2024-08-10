#include <iostream>
#include <string>

using namespace std;

const int maxSubjects = 10;

class Person {
public:
    string studentName;
    string schoolAddress;

    Person(const string& name = "", const string& email = "") : studentName(name), schoolAddress(email) {}
};

class Subject {
public:
    string subjectName;
    double grade;

    Subject(const string& name = "", double grade = 0.0) : subjectName(name), grade(grade) {}
};

class Student : public Person {
public:
    int schoolID;
    int subjectCount;
    Subject subjects[maxSubjects];

    Student(const string& name = "", int id = 0, const string& email = "")
        : Person(name, email), schoolID(id), subjectCount(0) {}

    void showDetails() {
        cout << "Full Name: " << studentName << endl;
        cout << "Student ID: " << schoolID << endl;
        cout << "Email Address (school): " << schoolAddress << endl;
        cout << "Subjects and the grades: " << endl;
        for (int i = 0; i < subjectCount; ++i) {
            cout << "    " << subjects[i].subjectName << ": " << subjects[i].grade << endl;
        }
    }

    double getAverageGrade() {
        double total = 0.0;
        for (int i = 0; i < subjectCount; ++i) {
            total += subjects[i].grade;
        }
        return (subjectCount > 0) ? (total / subjectCount) : 0.0;
    }

    void addSubject(const string& subjectName, double grade) {
        if (subjectCount < maxSubjects) {
            subjects[subjectCount++] = Subject(subjectName, grade);
        }
    }
};

class Student_Details {
private:
    Student students[maxSubjects];
    int studentCount;

public:
    Student_Details() : studentCount(0) {
        students[0] = Student("Cherry Ben Jr. R. Bendol", 2023102617, "cbjrbendol@mymail.mapua.edu.ph");
        students[0].addSubject("Differential Equations", 99.9);
        students[0].addSubject("Physics 2", 95.0);
        students[0].addSubject("Object Oriented Programming", 98.5);
        students[0].addSubject("Physical Education", 94.3);

        students[1] = Student("Jose Julian L. Acot", 2021135961, "jjlacot@mymail.mapua.edu.ph");
        students[1].addSubject("Differential Equations", 75.0);
        students[1].addSubject("Physics 2", 79.0);
        students[1].addSubject("Object Oriented Programming", 68.0);

        students[2] = Student("Kristian Emmanuel T. Padilla", 2011649230, "ketpadilla@mymail.mapua.edu.ph");
        students[2].addSubject("Differential Equations", 80.3);
        students[2].addSubject("Physics 2", 75.5);
        students[2].addSubject("Object Oriented Programming", 99.9);
        students[2].addSubject("Understanding the Self", 79.3);
        students[2].addSubject("History", 84.8);

        studentCount = 3;
    }

    void showAllDetails() {
        for (int i = 0; i < studentCount; ++i) {
            students[i].showDetails();
            cout << endl;
        }
    }

    void showTotalSubjects() {
        for (int i = 0; i < studentCount; ++i) {
            cout << students[i].studentName << " - " << students[i].subjectCount << " subjects" << endl;
        }
    }

    void showGeneralAverage() {
        for (int i = 0; i < studentCount; ++i) {
            cout << students[i].studentName << " - " << students[i].getAverageGrade() << "%"<< endl;
        }
    }
};

int main() {
    Student_Details studentInformations;

    cout << "Details of all students: " << endl;
    studentInformations.showAllDetails();

    cout << "\n";

    cout << "Total subjects per students: " << endl;
    studentInformations.showTotalSubjects();

    cout << "\n";

    cout << "General Average per students: " << endl;
    studentInformations.showGeneralAverage();

    return 0;
}
