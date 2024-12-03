#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			txtPassword->PasswordChar = '*';
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnLogin;
	protected:

	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::TextBox^ txtuserName;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::LinkLabel^ btn_Signup;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private:
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		MySqlDataReader^ sqlRd;
		String^ connectionString;

		System::ComponentModel::Container^ components;

		void InitializeComponent(void);
#pragma endregion
	private:
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Username_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}