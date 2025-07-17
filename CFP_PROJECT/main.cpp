#include <iostream>
#include "functions.h"
#include <string>
using namespace std;

int main() {
    string Username, rollnumber, password, username ,admin_choice , course_a;
    int ums_options;

    welcome_portal();
    cin >> ums_options;

    switch (ums_options) {
        case 1: { // ADMIN LOGIN PAGE
            admin_login(Username, password);

            if (Username == "Admin123" && password == "123") {
                cout << "Logged in successfully..." << endl;



                do {
                    admin_options();
                    cin >> admin_choice;

                    if (admin_choice == "1") {
                        // GRADE A STUDENT
                        cout << "[--GRADING--]" << endl;
                        cout << "Enter the student roll number: ";
                        cin >> rollnumber;
                         student_grade(rollnumber);
                        cout << "----------------------" << endl;

                    } else if (admin_choice == "2") {
                        // MARK ATTENDANCE
                        cout << "[--ATTENDANCE--]" << endl;
                        cout <<"Please Enter student's rollNumber."<< endl;
                        cin >> rollnumber;
                        cout << "Please Enter the Course." << endl;
                        cin >> course_a;
                        student_attendance(rollnumber , course_a);
                    } else if (admin_choice == "3") {
                        // ADD COURSE
                        add_course();
                    } else if (admin_choice == "4") {
                        // DROP COURSE
                        if (drop_course()) {
                            cout << "Course dropped successfully." << endl;
                        } else {
                            cout << "Failed to drop course." << endl;
                        }
                    } else if (admin_choice == "5") {
                        // EXIT TO MAIN PORTAL
                        cout << "Exiting to UMS main portal..." << endl;
                        main();
                        return 0; // Prevent stack overflow from recursion
                    } else {
                        cout << "Please enter a valid choice..." << endl;
                    }
                } while (admin_choice != "*");

            } else {
                for (int i = 1; i < 3; i++) {
                    cout << "Please enter your username or password correctly..." << endl;
                    admin_login(Username, password);

                    if (Username == "Admin123" && password == "123") {
                        cout << "Logged in successfully..." << endl;
                       cout << "For Security Reasons Please Log into the system again." << endl;
                        main();
                        break; // Exit loop on successful login
                    }

                    if (i == 2) {
                        cout << "Sorry, you have failed the login. Please try again later..." << endl;
                        main();
                    }
                }
            }
            break;
        }

        case 2: { // STUDENT PORTAL
            string student_choice;
            cout << "[--Student Portal--]" << endl;
            cout << "1) Sign Up" << endl;
            cout << "2) Log In" << endl;
            cout << "0) Exit to main welcome portal." << endl;
            cout << "---------------------" << endl;
            cout << "Please Enter a Choice: " << endl;
            cin >> student_choice;
            if (student_choice == "1") {
                if (student_count < MAX_LIMIT) {
                    signUp(rollnumber, password);
                    main();
                    return 0;
                }else {

                    cout << "Sorry, maximum student limit reached. Please try again later!" << endl;
                }
            } else if (student_choice == "2") {
                int attempt = 3;
                while (attempt > 0) {
                    if (logIn(rollnumber, password)) {
                       student_options();
                       char log_choice;
                        cout << "Please Enter your option from 1 to 4 only" << endl;
                        cin >> log_choice;
                        if(log_choice == '1') {
                            check_grades();
                            cout << "---------------" << endl;
                            cout << endl;
                            main();
                            return 0;
                        }
                        else if(log_choice == '2') {
                            check_attendance();
                            cout << "---------------" << endl;
                            cout << endl;
                            main();
                            return 0;
                        }
                         else if(log_choice == '3') {
                             display_courses();
                             cout << "---------------" << endl;
                             cout << endl;
                             main();
                             return 0;
                         }
                         else if(log_choice == '4') {
                             drop_course_student();
                             cout << "---------------" << endl;
                             cout << endl;
                             main();
                             return 0;
                         }
                        else if(log_choice == '5') {
                            cout << "[-- REPORT --]" << endl;
                            cout <<"Enter your username: "<< endl;
                            cin >> username;

                            show_report(username);
                            cout << "---------------" << endl;
                            main();
                            return 0;
                        }
                        else if(log_choice == '6') {
                            cout << "Exiting to UMS..." << endl;
                            main();
                            return 0;
                        }
                        else {
                            cout << "Please enter a valid choice" << endl;
                            cin >> log_choice;
                       }
                        break;
                    } else {
                        cout << "Incorrect roll number or password. Try again." << endl;
                        attempt--;
                    }
                }
                if (attempt == 0) {
                    cout << "Failed login attempts exceeded. Returning to main menu." << endl;
                    main();
                    return 0;
                }
            }else if (student_choice == "0") {
                main();
                return 0;
            } else {
                cout << "Invalid choice. Returning to main menu." << endl;
                main();
            }
            break;
        }

        default: {
            cout << "Thank you for using the UMS." << endl;
            break;
        }
    }

    return 0;
}