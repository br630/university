#pragma once
#include <string>
using namespace System;
using namespace MySql::Data::MySqlClient;

ref class DatabaseManager
{
private:
    static DatabaseManager^ instance; // Singleton instance
    MySqlConnection^ sqlConn;

    // Private constructor to enforce singleton pattern
    DatabaseManager();

public:
    // Destructor to clean up resources
    ~DatabaseManager();

    // Singleton accessor
    static DatabaseManager^ GetInstance();

    // Connect to the database
    void ConnectToDatabase();

    // Get the active database connection
    MySqlConnection^ GetConnection(); // Uncommented and fixed

    // Close the database connection
    void CloseConnection();

    // Execute a non-query (e.g., INSERT, UPDATE, DELETE)
    int ExecuteNonQuery(String^ query, array<MySqlParameter^>^ parameters);

    // Execute a query (e.g., SELECT)
    MySqlDataReader^ ExecuteReader(String^ query, array<MySqlParameter^>^ parameters);
};
