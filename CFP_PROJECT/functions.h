#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <fstream>
using namespace std;

const int MAX_LIMIT = 100;

// Global Variables
extern string student_data[MAX_LIMIT][2];
extern int student_count;
extern int course_count;

// Struct Definitions
struct StudentData {
    string id;
    string password;
    int attendance[MAX_LIMIT];
    string course;
    string grade[MAX_LIMIT];
};

extern StudentData student[MAX_LIMIT];

struct Course {

    string course_name;
    char course_grade;
    bool course_drop = false;
};

extern Course course[MAX_LIMIT]; // Declare the global course array
void welcome_portal();
void admin_login(string &username, string &password);
void admin_options();
void signUp(string &rollnumber, string &password);
bool logIn(string &rollnumber, string &password);

void add_course();
bool drop_course();
void student_grade(string &rollnumber);
void student_attendance(string &rollnumber , string &course_a);

void student_report(string &rollnumber);

//Student Portal
void check_grades();
void check_attendance();
void display_courses();
void drop_course_student();
void student_options();
void show_report(string &rollnumber);

#endif