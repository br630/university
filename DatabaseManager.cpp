#include "DatabaseManager.h"



//DatabaseManager^ DatabaseManager::instance = nullptr;

// Constructor
DatabaseManager::DatabaseManager()
{
    sqlConn = gcnew MySqlConnection();
    sqlConn->ConnectionString = "datasource=sql8.freesqldatabase.com; port=3306; username=sql8744026; password=4ussz7Rekc; database=sql8744026";
}

// Destructor
DatabaseManager::~DatabaseManager()
{
    if (sqlConn != nullptr && sqlConn->State == System::Data::ConnectionState::Open)
    {
        sqlConn->Close();
    }
}

// Singleton accessor
DatabaseManager^ DatabaseManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = gcnew DatabaseManager();
    }
    return instance;
}

// Connect to the database
void DatabaseManager::ConnectToDatabase()
{
    if (sqlConn->State != System::Data::ConnectionState::Open)
    {
        sqlConn->Open();
    }
}

// Get the active database connection
MySqlConnection^ DatabaseManager::GetConnection()
{
    return sqlConn;
}

// Close the database connection
void DatabaseManager::CloseConnection()
{
    if (sqlConn->State == System::Data::ConnectionState::Open)
    {
        sqlConn->Close();
    }
}

// Execute a non-query (e.g., INSERT, UPDATE, DELETE)
int DatabaseManager::ExecuteNonQuery(String^ query, array<MySqlParameter^>^ parameters)
{
    MySqlCommand^ sqlCmd = gcnew MySqlCommand(query, sqlConn);
    sqlCmd->Parameters->AddRange(parameters);
    return sqlCmd->ExecuteNonQuery();
}

// Execute a query (e.g., SELECT)
MySqlDataReader^ DatabaseManager::ExecuteReader(String^ query, array<MySqlParameter^>^ parameters)
{
    MySqlCommand^ sqlCmd = gcnew MySqlCommand(query, sqlConn);
    sqlCmd->Parameters->AddRange(parameters);
    return sqlCmd->ExecuteReader();
}
