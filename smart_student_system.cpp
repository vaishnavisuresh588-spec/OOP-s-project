#include <iostream>
#include <string>
using namespace std;

// Base Class
class Student {
protected:
    string name;
    int rollNo;
    int attendance; // percentage

public:
    void getStudentDetails() {
        cin.ignore();
        cout << "\nEnter Student Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        do {
            cout << "Enter Attendance %: ";
            cin >> attendance;
        } while (attendance < 0 || attendance > 100);
    }

    void displayStudentDetails() {
        cout << "\n------------------------------";
        cout << "\nName        : " << name;
        cout << "\nRoll Number : " << rollNo;
        cout << "\nAttendance  : " << attendance << "%";
    }

    // Pure virtual function
    virtual void calculateResult() = 0;
};

// Regular Student
class RegularStudent : public Student {
private:
    int marks[3];
    int total;
    float percentage;
    char grade;

public:
    void getMarks() {
        cout << "\nEnter marks:\n";
        for (int i = 0; i < 3; i++) {
            do {
                cout << "Subject " << i + 1 << ": ";
                cin >> marks[i];
            } while (marks[i] < 0 || marks[i] > 100);
        }
    }

    void calculateResult() override {
        total = 0;
        for (int i = 0; i < 3; i++)
            total += marks[i];

        percentage = total / 3.0;

        // Grade calculation
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 60) grade = 'C';
        else grade = 'F';

        displayStudentDetails();
        cout << "\nTotal       : " << total;
        cout << "\nPercentage  : " << percentage << "%";
        cout << "\nGrade       : " << grade;

        // Pass / Fail
        if (percentage < 40)
            cout << "\nStatus      : FAIL";
        else
            cout << "\nStatus      : PASS";

        // Attendance check
        if (attendance < 75)
            cout << "\nWarning     : Low Attendance";

        // Scholarship check
        if (percentage >= 90 && attendance >= 85)
            cout << "\nScholarship : Eligible";
        else
            cout << "\nScholarship : Not Eligible";

        // Remarks
        cout << "\nRemarks     : ";
        if (grade == 'A') cout << "Excellent";
        else if (grade == 'B') cout << "Very Good";
        else if (grade == 'C') cout << "Good";
        else cout << "Needs Improvement";
    }
};

// Sports Student
class SportsStudent : public Student {
private:
    int sportsMarks;

public:
    void getSportsMarks() {
        do {
            cout << "\nEnter Sports Marks: ";
            cin >> sportsMarks;
        } while (sportsMarks < 0 || sportsMarks > 100);
    }

    void calculateResult() override {
        displayStudentDetails();
        cout << "\nSports Marks: " << sportsMarks;

        if (sportsMarks >= 80)
            cout << "\nGrade: A";
        else if (sportsMarks >= 60)
            cout << "\nGrade: B";
        else if (sportsMarks >= 40)
            cout << "\nGrade: C";
        else
            cout << "\nGrade: F";

        if (sportsMarks >= 40)
            cout << "\nStatus: PASS";
        else
            cout << "\nStatus: FAIL";

        if (sportsMarks >= 85)
            cout << "\nAchievement: District Level Player";
    }
};

// Main Function
int main() {
    int choice;
    char cont;

    do {
        cout << "\n\n===== SMART STUDENT SYSTEM =====";
        cout << "\n1. Regular Student";
        cout << "\n2. Sports Student";
        cout << "\nChoice: ";
        cin >> choice;

        Student* s;

        if (choice == 1) {
            RegularStudent rs;
            s = &rs;

            rs.getStudentDetails();
            rs.getMarks();
            s->calculateResult();
        }
        else if (choice == 2) {
            SportsStudent ss;
            s = &ss;

            ss.getStudentDetails();
            ss.getSportsMarks();
            s->calculateResult();
        }
        else {
            cout << "\nInvalid Choice!";
        }

        cout << "\n\nContinue? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "\nSystem Closed Successfully";
    return 0;
}
