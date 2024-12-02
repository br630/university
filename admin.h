#pragma once
#pragma once
#using <System.dll>

using namespace System;

ref class Administrator {
private:
    // Will be retrived from the user schema
    int userID;
    String^ firstName;
    String^ lastName;
    String^ email;
    String^ role;

    // Will be retrived from the admin schema
    int adminID;

    // Singleton pattern
    static Administrator^ instance = nullptr;

    Administrator() {}

public:
    
    static Administrator^ GetInstance() {
        if (instance == nullptr) {
            instance = gcnew Administrator();
        }
        return instance;
    }

    // Setters
    void SetUserID(int id) { userID = id; }
    void SetFirstName(String^ name) { firstName = name; }
    void SetLastName(String^ name) { lastName = name; }
    void SetEmail(String^ mail) { email = mail; }
    void SetRole(String^ r) { role = r; }
    void SetAdminID(int id) { adminID = id; }

    // Getters
    int GetUserID() { return userID; }
    String^ GetFirstName() { return firstName; }
    String^ GetLastName() { return lastName; }
    String^ GetEmail() { return email; }
    String^ GetRole() { return role; }
    int GetAdminID() { return adminID; }

    // Helper methods
    String^ GetFullName() {
        return firstName + " " + lastName;
    }

    // Reset admin attributes when loggin out
    void ClearData() {
        userID = 0;
        firstName = "";
        lastName = "";
        email = "";
        role = "";
        adminID = 0;
    }
};