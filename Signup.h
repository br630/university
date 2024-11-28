#pragma once

namespace university {
    ref class MDIForm;  // Forward declaration

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Signup : public System::Windows::Forms::Form
    {
    public:
        Signup(void)
        {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            sqlCmd = gcnew MySqlCommand();
            connectionString = "datasource=localhost;port=3306;username=root;password=;database=university_management;";
            sqlConn->ConnectionString = connectionString;
        }

    protected:
        ~Signup()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        MySqlDataReader^ sqlRd;
        String^ connectionString;

        // Keep all your existing control declarations here
        System::Windows::Forms::Button^ btn_Signup;
        System::Windows::Forms::TextBox^ txt_lname;
        System::Windows::Forms::TextBox^ txt_password;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::TextBox^ txt_Email;
        System::Windows::Forms::TextBox^ txt_TPassword;
        System::Windows::Forms::TextBox^ txt_fname;
        System::Windows::Forms::Label^ label6;

        System::ComponentModel::Container^ components;

        // Keep your InitializeComponent method as is
        void InitializeComponent(void)
        {

        }

    private:
    private:
        void btn_Signup_Click(System::Object^ sender, System::EventArgs^ e);
    };
}