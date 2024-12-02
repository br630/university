#pragma once
#using <System.dll>

using namespace System;

// FOR BRYAN: Created a student class, makes it easier to store the student data when retrieved from the server
// and use accross the app
ref class Student {
private:
    // will be retrieved from the user schema
    int userID;
    String^ firstName;
    String^ lastName;
    String^ email;
    String^ role;

    int studentID;
    DateTime dateOfBirth;
    array<Byte>^ picture;
    String^ major;
    DateTime enrollmentDate;

    static Student^ instance = nullptr;

    Student() {}

public:

    static Student^ GetInstance() {
        if (instance == nullptr) {
            instance = gcnew Student();
        }
        return instance;
    }

    // Setters
    void SetUserID(int id) { userID = id; }
    void SetFirstName(String^ name) { firstName = name; }
    void SetLastName(String^ name) { lastName = name; }
    void SetEmail(String^ mail) { email = mail; }
    void SetRole(String^ r) { role = r; }
    void SetStudentID(int id) { studentID = id; }
    void SetDateOfBirth(DateTime dob) { dateOfBirth = dob; }
    void SetPicture(array<Byte>^ pic) { picture = pic; }
    void SetMajor(String^ m) { major = m; }
    void SetEnrollmentDate(DateTime date) { enrollmentDate = date; }

    // Getters
    int GetUserID() { return userID; }
    String^ GetFirstName() { return firstName; }
    String^ GetLastName() { return lastName; }
    String^ GetEmail() { return email; }
    String^ GetRole() { return role; }
    int GetStudentID() { return studentID; }
    DateTime GetDateOfBirth() { return dateOfBirth; }
    array<Byte>^ GetPicture() { return picture; }
    String^ GetMajor() { return major; }
    DateTime GetEnrollmentDate() { return enrollmentDate; }

    // To easily retrieve the students full name
    String^ GetFullName() {
        return firstName + " " + lastName;
    }

    // Resets students attributes when loging out
    void ClearData() {
        userID = 0;
        firstName = "";
        lastName = "";
        email = "";
        role = "";
        studentID = 0;
        dateOfBirth = DateTime::MinValue;
        picture = nullptr;
        major = "";
        enrollmentDate = DateTime::MinValue;
    }
};
