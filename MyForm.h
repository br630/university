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
		MyForm(void);

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

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->txtuserName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_Signup = (gcnew System::Windows::Forms::LinkLabel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(294, 326);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(232, 58);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"Cancel ";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm::btnCancel_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(63, 326);
			this->btnLogin->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(219, 58);
			this->btnLogin->TabIndex = 1;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Location = System::Drawing::Point(59, 93);
			this->Username->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(83, 20);
			this->Username->TabIndex = 2;
			this->Username->Text = L"Username";
			this->Username->Click += gcnew System::EventHandler(this, &MyForm::Username_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 194);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(397, 278);
			this->linkLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(129, 20);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot Password";
			// 
			// txtuserName
			// 
			this->txtuserName->Location = System::Drawing::Point(63, 138);
			this->txtuserName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtuserName->Name = L"txtuserName";
			this->txtuserName->Size = System::Drawing::Size(463, 26);
			this->txtuserName->TabIndex = 5;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(63, 230);
			this->txtPassword->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(463, 26);
			this->txtPassword->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(270, 36);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Login";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// btn_Signup
			// 
			this->btn_Signup->AutoSize = true;
			this->btn_Signup->Location = System::Drawing::Point(242, 278);
			this->btn_Signup->Name = L"btn_Signup";
			this->btn_Signup->Size = System::Drawing::Size(63, 20);
			this->btn_Signup->TabIndex = 8;
			this->btn_Signup->TabStop = true;
			this->btn_Signup->Text = L"Sign up";
			this->btn_Signup->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel2_LinkClicked);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(59, 278);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(177, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Don\'t have an account\?";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 421);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_Signup);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtuserName);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnCancel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Username_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	};
}