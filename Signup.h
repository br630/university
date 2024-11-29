#pragma once

namespace university {

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
		Signup(void);

	protected:
		~Signup()
		{
			if (components)
			{
				delete components;
			}
		}



	protected:

	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ txtuserName;
	private: System::Windows::Forms::TextBox^ txtPassword1;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ account_text;


	private:
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		MySqlDataReader^ sqlRd;
		String^ connectionString;

	private: System::Windows::Forms::LinkLabel^ btn_Login;
	private: System::Windows::Forms::Label^ first;
	private: System::Windows::Forms::TextBox^ txtPassword;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txt_fname;
	private: System::Windows::Forms::TextBox^ txt_lname;


	private: System::Windows::Forms::Label^ last;
	private: System::Windows::Forms::Button^ btnSignup;
	private: System::Windows::Forms::Button^ btnCancel;


		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Signup::Signup_FormClosing);
			this->btnCancel->Click += gcnew System::EventHandler(this, &Signup::btnCancel_Click);
			this->Username = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtuserName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->account_text = (gcnew System::Windows::Forms::Label());
			this->btn_Login = (gcnew System::Windows::Forms::LinkLabel());
			this->first = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txt_fname = (gcnew System::Windows::Forms::TextBox());
			this->txt_lname = (gcnew System::Windows::Forms::TextBox());
			this->last = (gcnew System::Windows::Forms::Label());
			this->btnSignup = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Location = System::Drawing::Point(59, 251);
			this->Username->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(48, 20);
			this->Username->TabIndex = 2;
			this->Username->Text = L"Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 411);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Confirm Password";
			// 
			// txtuserName
			// 
			this->txtuserName->Location = System::Drawing::Point(63, 293);
			this->txtuserName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtuserName->Name = L"txtuserName";
			this->txtuserName->Size = System::Drawing::Size(491, 26);
			this->txtuserName->TabIndex = 5;
			// 
			// txtPassword1
			// 
			this->txtPassword1->Location = System::Drawing::Point(63, 446);
			this->txtPassword1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtPassword1->Name = L"txtPassword1";
			this->txtPassword1->Size = System::Drawing::Size(491, 26);
			this->txtPassword1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(266, 23);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 29);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Sign Up";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 0;
			// 
			// account_text
			// 
			this->account_text->AutoSize = true;
			this->account_text->Location = System::Drawing::Point(313, 503);
			this->account_text->Name = L"account_text";
			this->account_text->Size = System::Drawing::Size(195, 20);
			this->account_text->TabIndex = 9;
			this->account_text->Text = L"Already Have an account\?";
			// 
			// btn_Login
			// 
			this->btn_Login->AutoSize = true;
			this->btn_Login->Location = System::Drawing::Point(527, 503);
			this->btn_Login->Name = L"btn_Login";
			this->btn_Login->Size = System::Drawing::Size(52, 20);
			this->btn_Login->TabIndex = 8;
			this->btn_Login->TabStop = true;
			this->btn_Login->Text = L"Log in";
			this->btn_Login->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Signup::btn_Login_LinkClicked);
			// 
			// first
			// 
			this->first->AutoSize = true;
			this->first->Location = System::Drawing::Point(59, 88);
			this->first->Name = L"first";
			this->first->Size = System::Drawing::Size(86, 20);
			this->first->TabIndex = 10;
			this->first->Text = L"First Name";
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(63, 372);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(491, 26);
			this->txtPassword->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(59, 337);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Enter Password";
			// 
			// txt_fname
			// 
			this->txt_fname->Location = System::Drawing::Point(63, 124);
			this->txt_fname->Name = L"txt_fname";
			this->txt_fname->Size = System::Drawing::Size(491, 26);
			this->txt_fname->TabIndex = 13;
			// 
			// txt_lname
			// 
			this->txt_lname->Location = System::Drawing::Point(63, 209);
			this->txt_lname->Name = L"txt_lname";
			this->txt_lname->Size = System::Drawing::Size(491, 26);
			this->txt_lname->TabIndex = 14;
			// 
			// last
			// 
			this->last->AutoSize = true;
			this->last->Location = System::Drawing::Point(59, 175);
			this->last->Name = L"last";
			this->last->Size = System::Drawing::Size(86, 20);
			this->last->TabIndex = 15;
			this->last->Text = L"Last Name";
			// 
			// btnSignup
			// 
			this->btnSignup->Location = System::Drawing::Point(63, 548);
			this->btnSignup->Name = L"btnSignup";
			this->btnSignup->Size = System::Drawing::Size(209, 58);
			this->btnSignup->TabIndex = 16;
			this->btnSignup->Text = L"Sign Up";
			this->btnSignup->UseVisualStyleBackColor = true;
			this->btnSignup->Click += gcnew System::EventHandler(this, &Signup::btnSignup_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(382, 548);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(197, 58);
			this->btnCancel->TabIndex = 17;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Signup::btnCancel_Click);
			// 
			// Signup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(673, 633);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSignup);
			this->Controls->Add(this->last);
			this->Controls->Add(this->txt_lname);
			this->Controls->Add(this->txt_fname);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->first);
			this->Controls->Add(this->account_text);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_Login);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPassword1);
			this->Controls->Add(this->txtuserName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Username);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Signup";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Signup";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

private: System::Void btnSignup_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_Login_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Signup_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}