#pragma once

namespace university {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class Register_Course : public System::Windows::Forms::Form {
	private:
		// Database members
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		String^ connectionString;
		String^ studentId; // To store current student's ID

	public:
		Register_Course(void)
		{
			InitializeComponent();
			InitializeDatabase();
			InitializeAdditionalComponents();
		}

	protected:
		~Register_Course()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::PictureBox^ picturebox2;







	private: System::Windows::Forms::PictureBox^ picture_3;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ icp_btn;
	private: System::Windows::Forms::Button^ algo_btn;
	private: System::Windows::Forms::Button^ web_btn;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register_Course::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->picturebox2 = (gcnew System::Windows::Forms::PictureBox());
			this->picture_3 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->icp_btn = (gcnew System::Windows::Forms::Button());
			this->algo_btn = (gcnew System::Windows::Forms::Button());
			this->web_btn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1008, 1);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(299, 26);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(887, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search Course:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1325, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// picturebox2
			// 
			this->picturebox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picturebox2.Image")));
			this->picturebox2->Location = System::Drawing::Point(613, 152);
			this->picturebox2->Name = L"picturebox2";
			this->picturebox2->Size = System::Drawing::Size(280, 232);
			this->picturebox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picturebox2->TabIndex = 25;
			this->picturebox2->TabStop = false;
			// 
			// picture_3
			// 
			this->picture_3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picture_3.Image")));
			this->picture_3->Location = System::Drawing::Point(996, 152);
			this->picture_3->Name = L"picture_3";
			this->picture_3->Size = System::Drawing::Size(280, 232);
			this->picture_3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_3->TabIndex = 27;
			this->picture_3->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(644, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 20);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Course Registration";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Semester 1(2024/2025)", L"Semester 2(2024/2025)",
					L"Semester 1(2025/2026)", L"Semester 2(2025/2026)"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 50);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(246, 28);
			this->comboBox1->TabIndex = 29;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 20);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Semester";
			// 
			// icp_btn
			// 
			this->icp_btn->Location = System::Drawing::Point(226, 379);
			this->icp_btn->Name = L"icp_btn";
			this->icp_btn->Size = System::Drawing::Size(280, 53);
			this->icp_btn->TabIndex = 32;
			this->icp_btn->Text = L"Intermediate Computer Programming";
			this->icp_btn->UseVisualStyleBackColor = true;
			// 
			// algo_btn
			// 
			this->algo_btn->Location = System::Drawing::Point(613, 379);
			this->algo_btn->Name = L"algo_btn";
			this->algo_btn->Size = System::Drawing::Size(280, 53);
			this->algo_btn->TabIndex = 33;
			this->algo_btn->Text = L"Algorithms Design & Analysis";
			this->algo_btn->UseVisualStyleBackColor = true;
			// 
			// web_btn
			// 
			this->web_btn->Location = System::Drawing::Point(996, 379);
			this->web_btn->Name = L"web_btn";
			this->web_btn->Size = System::Drawing::Size(280, 53);
			this->web_btn->TabIndex = 34;
			this->web_btn->Text = L"Web Technologies";
			this->web_btn->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(226, 152);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 232);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 36;
			this->pictureBox1->TabStop = false;
			// 
			// Register_Course
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1325, 531);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->web_btn);
			this->Controls->Add(this->algo_btn);
			this->Controls->Add(this->icp_btn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->picture_3);
			this->Controls->Add(this->picturebox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Register_Course";
			this->Text = L"Registration";
			this->Load += gcnew System::EventHandler(this, &Register_Course::Register_Course_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private:
	void InitializeDatabase() {
		try {
			connectionString = "datasource=localhost;port=3306;username=root;password=;database=university_management;";
			sqlConn = gcnew MySqlConnection(connectionString);
			sqlCmd = gcnew MySqlCommand();
			sqlCmd->Connection = sqlConn;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Failed to initialize database connection: " + ex->Message);
		}
	}

	void LoadAvailableCourses() {
		if (String::IsNullOrEmpty(comboBox1->Text))
			return;

		try {
			sqlConn->Open();
			String^ sql = "SELECT courseID, courseName, credits FROM courses " +
				"WHERE semester = @semester AND courseID NOT IN " +
				"(SELECT courseID FROM enrollments WHERE studentID = @studentID)";

			sqlCmd->CommandText = sql;
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@semester", comboBox1->Text);
			sqlCmd->Parameters->AddWithValue("@studentID", studentId);

			MySqlDataReader^ reader = sqlCmd->ExecuteReader();

			// Clear existing buttons
			icp_btn->Enabled = false;
			algo_btn->Enabled = false;
			web_btn->Enabled = false;

			while (reader->Read()) {
				String^ courseName = reader["courseName"]->ToString();

				// Enable corresponding button based on course
				if (courseName->Contains("Intermediate Computer Programming"))
					icp_btn->Enabled = true;
				else if (courseName->Contains("Algorithms Design"))
					algo_btn->Enabled = true;
				else if (courseName->Contains("Web Technologies"))
					web_btn->Enabled = true;
			}

			reader->Close();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading courses: " + ex->Message);
		}
	}

	void SearchCourses() {
		String^ searchTerm = textBox1->Text->ToLower();

		icp_btn->Visible = (gcnew String("intermediate computer programming"))->ToLower()->Contains(searchTerm) == true;
		algo_btn->Visible = (gcnew String("algorithms design"))->ToLower()->Contains(searchTerm) == true;
		web_btn->Visible = (gcnew String("web technologies"))->ToLower()->Contains(searchTerm) == true;
	}

	void RegisterForCourse(String^ courseName) {
		if (String::IsNullOrEmpty(comboBox1->Text)) {
			MessageBox::Show("Please select a semester first.");
			return;
		}

		try {
			sqlConn->Open();

			// Get courseID
			sqlCmd->CommandText = "SELECT courseID FROM courses WHERE courseName LIKE @courseName";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@courseName", "%" + courseName + "%");
			Object^ courseId = sqlCmd->ExecuteScalar();

			if (courseId != nullptr) {
				// Check if already enrolled
				sqlCmd->CommandText = "SELECT COUNT(*) FROM enrollments WHERE studentID = @studentID AND courseID = @courseID";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@studentID", studentId);
				sqlCmd->Parameters->AddWithValue("@courseID", courseId->ToString());

				int count = Convert::ToInt32(sqlCmd->ExecuteScalar());

				if (count == 0) {
					// Insert enrollment
					sqlCmd->CommandText = "INSERT INTO enrollments (studentID, courseID, semester, enrollmentDate) " +
						"VALUES (@studentID, @courseID, @semester, NOW())";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@studentID", studentId);
					sqlCmd->Parameters->AddWithValue("@courseID", courseId->ToString());
					sqlCmd->Parameters->AddWithValue("@semester", comboBox1->Text);

					sqlCmd->ExecuteNonQuery();
					MessageBox::Show("Successfully registered for " + courseName);
					LoadAvailableCourses();
				}
				else {
					MessageBox::Show("You are already enrolled in this course.");
				}
			}

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error registering for course: " + ex->Message);
		}
	}

	void InitializeAdditionalComponents() {
		this->textBox1->TextChanged += gcnew System::EventHandler(this, &Register_Course::textBox1_TextChanged);
		this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Register_Course::comboBox1_SelectedIndexChanged);
		this->icp_btn->Click += gcnew System::EventHandler(this, &Register_Course::icp_btn_Click);
		this->algo_btn->Click += gcnew System::EventHandler(this, &Register_Course::algo_btn_Click);
		this->web_btn->Click += gcnew System::EventHandler(this, &Register_Course::web_btn_Click);
	}

	// Event handlers
	System::Void Register_Course_Load(System::Object^ sender, System::EventArgs^ e) {
		studentId = "1"; // Placeholder - replace with actual student ID
		LoadAvailableCourses();
	}

	System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SearchCourses();
	}

	System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		LoadAvailableCourses();
	}

	System::Void icp_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForCourse("Intermediate Computer Programming");
	}

	System::Void algo_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForCourse("Algorithms Design");
	}

	System::Void web_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForCourse("Web Technologies");
	}

	// Your existing InitializeComponent method remains unchanged
	};
}