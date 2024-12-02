#pragma once
#pragma once
#using <System.dll>

using namespace System;

// FOR BRYAN: Created a faculty class, makes it easier to store the faculty data when retrieved from the server
// and use accross the app
// follows a similar pattern to the student class created.
ref class Faculty {
private:
    // will be retrived from the user schema
    int userID;
    String^ firstName;
    String^ lastName;
    String^ email;
    String^ role;

    // will be retrived from the faculty schema
    int facultyID;
    String^ department;
    DateTime dateOfAppointment;
    static Faculty^ instance = nullptr;


    Faculty() {}

public:
    
    static Faculty^ GetInstance() {
        if (instance == nullptr) {
            instance = gcnew Faculty();
        }
        return instance;
    }

    // Setters
    void SetUserID(int id) { userID = id; }
    void SetFirstName(String^ name) { firstName = name; }
    void SetLastName(String^ name) { lastName = name; }
    void SetEmail(String^ mail) { email = mail; }
    void SetRole(String^ r) { role = r; }
    void SetFacultyID(int id) { facultyID = id; }
    void SetDepartment(String^ dept) { department = dept; }
    void SetDateOfAppointment(DateTime date) { dateOfAppointment = date; }

    // Getters
    int GetUserID() { return userID; }
    String^ GetFirstName() { return firstName; }
    String^ GetLastName() { return lastName; }
    String^ GetEmail() { return email; }
    String^ GetRole() { return role; }
    int GetFacultyID() { return facultyID; }
    String^ GetDepartment() { return department; }
    DateTime GetDateOfAppointment() { return dateOfAppointment; }


    String^ GetFullName() {
        return firstName + " " + lastName;
    }

    // Resets faculty attributes when loging out
    void ClearData() {
        userID = 0;
        firstName = "";
        lastName = "";
        email = "";
        role = "";
        facultyID = 0;
        department = "";
        dateOfAppointment = DateTime::MinValue;
    }
};