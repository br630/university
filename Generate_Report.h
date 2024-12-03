#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Generate_Report
	/// </summary>
	public ref class Generate_Report : public System::Windows::Forms::Form
	{
	public:
		Generate_Report(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Generate_Report()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Generate_Report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1042, 569);
			this->Name = L"Generate_Report";
			this->Text = L"Generate_Report";
			this->Load += gcnew System::EventHandler(this, &Generate_Report::Generate_Report_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Generate_Report_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
