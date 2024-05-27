//
// Created by corre on 20/05/2024.
//
#include <iostream>
#include <string>
#include <tuple>
#include "Controller.h"
#include "Utils.h"
#include "DataConsistencyException.h"

Controller::Controller(School& school) : model(school) {}

void Controller::run() {
    int option;
    do {
        option = view.menuSchool();

        switch (option) {
            case 1: runStudents(); break;
            case 2: runInstructors(); break;
            case 3: runSubjects(); break;
            case 4: runEnrolls(); break;
            case 5: runLectures(); break;
            case 0: cout << "Exiting application..." << endl; break;
            default: cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);
}

void Controller::runStudents() {
    int option;
    do {
        option = view.menuStudents();

        switch (option) {
            case 1: { // Add student
                try {
                    Student newStudent = studentView.getStudent();
                    model.getStudentContainer().add(newStudent);
                    cout << "Student added successfully." << endl;
                } catch (const InvalidDataException& e) {
                    cout << "Error: " << e.what() << endl;
                } catch (const DuplicatedDataException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                // ... (catch other potential exceptions)
                break;
            }
            case 2: { // List students
                studentView.printStudents(model.getStudentContainer().getAll());
                break;
            }
            case 3: { // Update student
                try {
                    int studentNumber = Utils::getNumber("Enter student number to update: ");
                    Student* studentToUpdate = model.getStudentContainer().get(studentNumber);
                    if (studentToUpdate) {
                        Student updatedStudent = studentView.getStudent();
                        updatedStudent.setNumber(studentNumber); // Keep the original number
                        model.getStudentContainer().update(studentNumber, updatedStudent.getName(), updatedStudent.getBirthday());
                        cout << "Student updated successfully." << endl;
                    } else {
                        cout << "Student not found." << endl;
                    }
                } catch (const InvalidDataException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                // ... (catch other potential exceptions)
                break;
            }
            case 4: { // Remove student
                try {
                    int studentNumber = Utils::getNumber("Enter student number to remove: ");
                    model.getStudentContainer().remove(studentNumber);
                    cout << "Student removed successfully." << endl;
                } catch (const DataConsistencyException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                // ... (catch other potential exceptions)
                break;
            }
            case 0: break;
            default: cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);
}

void Controller::runInstructors() {
    int option;
    do {
        option = view.menuInstructors();

        switch (option) {
            case 1: { // Add Instructor
                try {
                    Instructor newInstructor = instructorView.getInstructor();
                    model.getInstructorContainer().add(newInstructor);
                    cout << "Instructor added successfully." << endl;
                } catch (const InvalidDataException& e) {
                    cout << "Error: " << e.what() << endl;
                } catch (const DuplicatedDataException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                // ... (catch other potential exceptions)
                break;
            }
            case 2: { // List instructors
                instructorView.printInstructors(model.getInstructorContainer().getAll());
                break;
            }
            case 3: { // Update instructor
                try {
                    string instructorInitials = Utils::getString("Enter instructor initials to update: ");
                    Instructor* instructorToUpdate = model.getInstructorContainer().get(instructorInitials);
                    if (instructorToUpdate) {
                        Instructor updatedInstructor = instructorView.getInstructor();
                        updatedInstructor.setInitials(instructorInitials); // Keep original initials
                        model.getInstructorContainer().update(instructorInitials, updatedInstructor.getName());
                        cout << "Instructor updated successfully." << endl;
                    } else {
                        cout << "Instructor not found." << endl;
                    }
                } catch (const InvalidDataException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                // ... (catch other potential exceptions)
                break;
            }
            case 4: { // Remove instructor
                try {
                    string instructorInitials = Utils::getString("Enter instructor initials to remove: ");
                    model.getInstructorContainer().remove(instructorInitials);
                    cout << "Instructor removed successfully." << endl;
                } catch (const DataConsistencyException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                // ... (catch other potential exceptions)
                break;
            }
            case 0: break;
            default: cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);
}

// ... (Implement other run functions: runSubjects(), runEnrolls(), runLectures() in a similar fashion)
