#pragma once
#pragma once
#using <System.dll>

using namespace System;
using namespace MySql::Data::MySqlClient;

ref class DatabaseManager
{
private:
    static DatabaseManager^ instance;
    MySqlConnection^ sqlConn;

    // Private constructor for singleton pattern
    DatabaseManager()
    {
        String^ connString = "datasource=localhost;port=3306;username=root;password=;database=university_management;";
        sqlConn = gcnew MySqlConnection(connString);
    }

public:
    // Get instance method
    static DatabaseManager^ GetInstance()
    {
        if (instance == nullptr)
        {
            instance = gcnew DatabaseManager();
        }
        return instance;
    }

    // Get connection method
    MySqlConnection^ GetConnection()
    {
        return sqlConn;
    }

    // Connect to database
    void ConnectToDatabase()
    {
        try
        {
            if (sqlConn->State == System::Data::ConnectionState::Closed)
            {
                sqlConn->Open();
            }
        }
        catch (MySqlException^ ex)
        {
            throw ex;
        }
    }

    // Close connection
    void CloseConnection()
    {
        try
        {
            if (sqlConn->State == System::Data::ConnectionState::Open)
            {
                sqlConn->Close();
            }
        }
        catch (MySqlException^ ex)
        {
            throw ex;
        }
    }
};
