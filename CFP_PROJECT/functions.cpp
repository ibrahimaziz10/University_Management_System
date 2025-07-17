#include <iostream>
using namespace std;
#include <cctype>
#include "functions.h"

string student_data[MAX_LIMIT][2];
int student_count = 0;
int course_count = 0;

StudentData student[MAX_LIMIT];
Course course[MAX_LIMIT];


void welcome_portal() {
    cout << "Welcome to the UMS PORTAL. Please Select the options: " << endl;
    cout << "[--UMS PORTAL--]" << endl;
    cout << "1) Admin Login" << endl;
    cout << "2) Student Sign Up or login" << endl;
    cout << "3) PRESS anything to exit." << endl;
    cout << "----------------------------" << endl;
}

void admin_login(string &username, string &password) {
    cout << "[--LOGIN--]" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "----------------------------" << endl;
}

void admin_options() {
    cout << "[--Welcome Admin--]" << endl;
    cout << "1) Grade A student" << endl;
    cout << "2) Mark Attendance" << endl;
    cout << "3) Add Course " << endl;
    cout << "4) Drop Course " << endl;
    cout << "5) Exit to UMS" << endl;
    cout << "Please Enter a choice from 1 to 5." << endl;
    cout << "------------------------------------" << endl;
}

void signUp(string &rollnumber, string &password) {
    cout << "[--Sign UP--]" << endl;
    cout << "Enter your Roll Number: ";
    cin >> rollnumber;
    cout << "Now Please Enter Your Password: ";
    cin >> password;

    // Store data in the array
    student_data[student_count][0] = rollnumber;
    student_data[student_count][1] = password;
    student_count++;

    cout << "Account successfully created!" << endl;
    cout << "-----------------------------------------" << endl;
}

bool logIn(string &rollnumber, string &password) {
    cout << "[--LOG IN--]" << endl;
    cout << "Please Enter your Roll No.: ";
    cin >> rollnumber;
    cout << "Please Enter your Password: ";
    cin >> password;

    for (int i = 0; i < student_count; i++) {
        if (student_data[i][0] == rollnumber && student_data[i][1] == password) {
            cout << "Successfully Logged in!" << endl;
            return true;
        }
    }

    cout << "Incorrect Roll Number or Password. Please try again." << endl;
    return false;
}

void student_options() {
    cout << "[--STUDENT OPTIONS--]" << endl;
    cout << "1) View Grade" << endl;
    cout << "2) View Attendance " << endl;
    cout << "3) View Courses" << endl;
    cout << "4) Drop Course" << endl;
    cout << "5) Show Report" << endl;
    cout << "6) Exit to UMS" << endl;
    cout << "----------------------------" << endl;
       }

void add_course() {
    if (course_count >= MAX_LIMIT) {
        cout << "Cannot add more courses. Limit reached!" << endl;
        return;
    }

    cout << "[--ADD COURSE--]" << endl;
    cout << "Enter course Name: ";
    cin >> course[course_count].course_name;
    course[course_count].course_drop = false;
    course_count++;
    cout << "Course Added Successfully!" << endl;
    cout << "------------------------" << endl;
}

bool drop_course() {
    string course_name;
    char option;

    cout << "[--REMOVE COURSE--]" << endl;
    cout << "Enter course name: ";
    cin >> course_name;
    cout << "Are you sure you want to remove the course (Y/N)? ";
    cin >> option;
    option = tolower(option);

    if (option == 'y') {
        for (int i = 0; i < course_count; i++) {
            if (course[i].course_name == course_name) {
                course[i].course_drop = true;
                cout << "The course " << course_name << " is dropped!" << endl;
                return true;
            }
        }
        cout << "Course not found!" << endl;
        return false;
    } else if (option == 'n') {
        cout << "Operation canceled. The course is not dropped!" << endl;
        return false;
    }

    cout << "Invalid input. Try again!" << endl;
    return false;
}

void student_grade(string &rollnumber) {
    bool student_found = false; // Track if the student is found

    for (int i = 0; i < student_count; i++) {
        if (student_data[i][0] == rollnumber) {
            student_found = true; // Mark that the student is found

            cout << "Enter the course name: ";
            string course_name;
            cin >> course_name;

            bool course_found = false;
            for (int a = 0; a < course_count; a++) {
                if (course[a].course_name == course_name) {
                    course_found = true;
                    if(!course[a].course_drop) {
                        string grade;
                        cout << "[--Grading student: " << rollnumber << " --]" << endl;
                        cout << "Please Enter the Grade: ";
                        cin >> grade[a];

                        grade[a] = toupper(grade[a]); // Ensure the grade is uppercase
                        student[i].grade[i] = grade[a]; // Assign the grade to the student

                        cout << "The student with the roll number " << rollnumber
                             << " is awarded the grade " << grade[a] << " for the course "
                             << course_name << "." << endl;
                        return;
                    }
                    else{
                        cout << "Sorry the course you entered has been dropped." << endl;
                    }
                }
            }

            if (!course_found) {
                cout << "Course not found!" << endl;
            }

            return;
        }
    }

    if (!student_found){
        cout << "Student not found!" << endl;
    }
}

void student_attendance(string &rollnumber , string &course_a) {
    int index;
    bool student_found = false;
    int lecture_count = 5;
    int present_count = 0;
    int absent_count = 0;
    int attendance_percentage;
    bool elligeble = true;
    char attendance;
    for(int k = 0; k < course_count;k++){
        bool course_found = false;
        if(course[k].course_name == course_a){
            course_found = true;
            if(!course[k].course_drop) {
                for(int i = 0;i < student_count;i++) {
                    if(student_data[i][0] == rollnumber) {
                        student_found = true;
                        index = i;
                        cout << "The student is register! Now Please Carefully mark his attendace for the first 5 lectures" << endl;
                        for(int a = 0; a < lecture_count;a++) {
                            cout << "Lecture " << a + 1 << ": " << endl;
                            cin >> attendance;
                            attendance = toupper(attendance);
                            cout << endl;


                            if(attendance == 'P') {
                                present_count++;
                            }
                            else if(attendance == 'A') {
                                absent_count++;
                            }
                            else {
                               cout << "Please Enter either A or P." << endl;
                                cin >> attendance;
                            }
                        }
                        attendance_percentage = ((present_count *100 )/ lecture_count);
                        cout << "the candidate attendance is at " << attendance_percentage << endl;
                        student[index].attendance[index] = attendance_percentage;


                    }
                    else if (!student_found){
                        cout << "Student not found." << endl;
                    }
                }
            }
            else {
                cout << "Sorry the course is dropped!" << endl;

            }
        }
    }
}

void check_grades() {
    cout << "Enter the course name: ";
    string course_name;
    cin >> course_name;

    bool course_found = false;
    for (int a = 0; a < course_count; a++) {
        if (course[a].course_name == course_name) {
            course_found = true;
            cout << "You are awarded with the grade: " << student[a].grade[a] << endl;

        }

        if (!course_found) {
            cout << "Course not found!" << endl;
            return;
        }



    }
}
void check_attendance() {
    cout << "Enter the course name: ";
    string course_name;
    cin >> course_name;

    bool course_found = false;
    for (int a = 0; a < course_count; a++) {
        if (course[a].course_name == course_name) {
            course_found = true;
            cout << "Your attendance in this course is: " << student[a].attendance[a] << endl;
            int check;
            check = student[a].attendance[a];
            if(check < 75) {
                cout << "You are NOT eligible for the final exam" << endl;
            }else {
                cout <<"You are eligible for the final exams. "<< endl;
            }
        }

        if (course_found = false) {
            cout << "Course not found!" << endl;
            return;
        }



    }
}
void display_courses() {
    cout << "Runningt task 3..." << endl;
    cout <<"[--COURSE DISPLAY--]"<< endl;
    for(int i = 0; i < course_count;i++) {
        cout << course[i].course_name << endl;
    }

}
void drop_course_student() {
    cout << "Running task 4..." << endl;
    cout << "Drop Course Report" << endl;
    cout << "Please enter the course name " << endl;
    string course_name;
    cin >> course_name;
    bool course_found = false;
    for (int a = 0; a < course_count; a++) {
        if (course[a].course_name == course_name) {
            course_found = true;
            course[a].course_drop = false;
           cout << "The course has been dropped." << endl;
        }
    }
    if(!course_found){
        cout << "Course not found!" << endl;
    }

}

int main();

void show_report(string &rollnumber) {
    bool student_found = false;
    for(int i = 0 ; i < course_count;i++) {
        if(student_data[i][0] == rollnumber) {
            cout << "[--COURSE "<< i + 1 <<" --]" << endl;
            student_found = true;
            cout <<"Course Name: "<< course[i].course_name << endl;
            cout <<"Course Attendence: "<< student[i].attendance[i] << endl;
            cout <<"Course Grade Awarded: "<< student[i].grade[i] << endl;
            cout << endl;
        }

    }
    string choice;
    do{cout << "Please Choose the following Choice:-" << endl;
        cout << "1) Save to File" << endl;
        cout << "2) Load from File" << endl;
        cout << "3) Press * to exit to UMS" << endl;
        cout << "--------------------------" << endl;
        cin >> choice;
        if(choice == "1") {
           ofstream outFile("data.txt");
            if(!outFile) {
                cout << "Error in opening the file" << endl;
                return;
            }
            for(int i = 0 ; i < student_count;i++) {
                outFile << "[--COURSE "<< i + 1 <<" --]" << endl;
                outFile <<"Course Name: "<< course[i].course_name << endl;
                outFile <<"Course Attendence: "<< student[i].attendance[i] << endl;
                outFile <<"Course Grade Awarded: "<< student[i].grade[i] << endl;
                outFile << endl;
            }

         cout << "Contents Saved to File" << endl;
        }
        else if(choice == "2") {
            ifstream inFile("data.txt");
            if(!inFile) {
                cout <<"Sorry There was Error opening the file..."<< endl;
                return 1;
            }



        }
        else if(choice == "*") {
            cout << "Exiting to UMS." << endl;
        }
        else {
            cout << "Please Enter a Valid Choice.";

        }
    }while(choice != "*");

    main();
    return;



    if(!student_found) {
        cout << "Student Not found!" << endl;
        return;
    }




}

