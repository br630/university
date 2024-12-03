#pragma once

// Add these namespace references at the top
using namespace System::Windows::Forms::DataVisualization;
using namespace System::Windows::Forms::DataVisualization::Charting;

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class View_Grade : public System::Windows::Forms::Form {
    public:
        View_Grade(void)
        {
            InitializeComponent();
        }

    protected:
        ~View_Grade()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::GroupBox^ groupBoxGradeStats;
        System::Windows::Forms::Label^ lblCurrentGPA;
        System::Windows::Forms::Label^ lblTotalCredits;
        System::Windows::Forms::DataGridView^ gridDetailedGrades;
        System::Windows::Forms::ComboBox^ comboGradeSemester;
        System::Windows::Forms::Button^ btnExportGrades;
        System::Windows::Forms::DataVisualization::Charting::Chart^ chartGradeProgress;
        System::Windows::Forms::Panel^ panelGradeBreakdown;
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ homeToolStripMenuItem;


        void InitializeComponent(void)
        {
            System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
                3.5));
            System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
                3.7));
            System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
                3.8));
            System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
                3.75));
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(View_Grade::typeid));
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->homeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->groupBoxGradeStats = (gcnew System::Windows::Forms::GroupBox());
            this->lblCurrentGPA = (gcnew System::Windows::Forms::Label());
            this->lblTotalCredits = (gcnew System::Windows::Forms::Label());
            this->comboGradeSemester = (gcnew System::Windows::Forms::ComboBox());
            this->chartGradeProgress = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->gridDetailedGrades = (gcnew System::Windows::Forms::DataGridView());
            this->btnExportGrades = (gcnew System::Windows::Forms::Button());
            this->menuStrip1->SuspendLayout();
            this->groupBoxGradeStats->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartGradeProgress))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDetailedGrades))->BeginInit();
            this->SuspendLayout();
            // 
            // menuStrip1
            // 
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->homeToolStripMenuItem });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Padding = System::Windows::Forms::Padding(6, 2, 0, 2);
            this->menuStrip1->Size = System::Drawing::Size(873, 28);
            this->menuStrip1->TabIndex = 0;
            // 
            // homeToolStripMenuItem
            // 
            this->homeToolStripMenuItem->Name = L"homeToolStripMenuItem";
            this->homeToolStripMenuItem->Size = System::Drawing::Size(64, 24);
            this->homeToolStripMenuItem->Text = L"Home";
            // 
            // groupBoxGradeStats
            // 
            this->groupBoxGradeStats->Controls->Add(this->lblCurrentGPA);
            this->groupBoxGradeStats->Controls->Add(this->lblTotalCredits);
            this->groupBoxGradeStats->Location = System::Drawing::Point(20, 52);
            this->groupBoxGradeStats->Name = L"groupBoxGradeStats";
            this->groupBoxGradeStats->Size = System::Drawing::Size(304, 114);
            this->groupBoxGradeStats->TabIndex = 2;
            this->groupBoxGradeStats->TabStop = false;
            this->groupBoxGradeStats->Text = L"Academic Statistics";
            // 
            // lblCurrentGPA
            // 
            this->lblCurrentGPA->Location = System::Drawing::Point(10, 30);
            this->lblCurrentGPA->Name = L"lblCurrentGPA";
            this->lblCurrentGPA->Size = System::Drawing::Size(200, 20);
            this->lblCurrentGPA->TabIndex = 0;
            this->lblCurrentGPA->Text = L"Current GPA: 0.00";
            // 
            // lblTotalCredits
            // 
            this->lblTotalCredits->Location = System::Drawing::Point(10, 60);
            this->lblTotalCredits->Name = L"lblTotalCredits";
            this->lblTotalCredits->Size = System::Drawing::Size(200, 20);
            this->lblTotalCredits->TabIndex = 1;
            this->lblTotalCredits->Text = L"Total Credits: 0";
            // 
            // comboGradeSemester
            // 
            this->comboGradeSemester->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
                L"Fall 2024", L"Spring 2024", L"Fall 2023",
                    L"Spring 2023"
            });
            this->comboGradeSemester->Location = System::Drawing::Point(20, 247);
            this->comboGradeSemester->Name = L"comboGradeSemester";
            this->comboGradeSemester->Size = System::Drawing::Size(200, 24);
            this->comboGradeSemester->TabIndex = 3;
            this->comboGradeSemester->SelectedIndexChanged += gcnew System::EventHandler(this, &View_Grade::comboGradeSemester_SelectedIndexChanged);
            // 
            // chartGradeProgress
            // 
            chartArea1->Name = L"ChartArea1";
            this->chartGradeProgress->ChartAreas->Add(chartArea1);
            this->chartGradeProgress->Location = System::Drawing::Point(360, 52);
            this->chartGradeProgress->Name = L"chartGradeProgress";
            series1->ChartArea = L"ChartArea1";
            series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
            series1->Name = L"GPA Trend";
            dataPoint1->AxisLabel = L"Sem 1";
            dataPoint2->AxisLabel = L"Sem 2";
            dataPoint3->AxisLabel = L"Sem 3";
            dataPoint4->AxisLabel = L"Sem 4";
            series1->Points->Add(dataPoint1);
            series1->Points->Add(dataPoint2);
            series1->Points->Add(dataPoint3);
            series1->Points->Add(dataPoint4);
            this->chartGradeProgress->Series->Add(series1);
            this->chartGradeProgress->Size = System::Drawing::Size(460, 185);
            this->chartGradeProgress->TabIndex = 4;
            this->chartGradeProgress->Click += gcnew System::EventHandler(this, &View_Grade::chartGradeProgress_Click);
            // 
            // gridDetailedGrades
            // 
            this->gridDetailedGrades->AllowUserToAddRows = false;
            this->gridDetailedGrades->ColumnHeadersHeight = 34;
            this->gridDetailedGrades->Location = System::Drawing::Point(20, 298);
            this->gridDetailedGrades->Name = L"gridDetailedGrades";
            this->gridDetailedGrades->ReadOnly = true;
            this->gridDetailedGrades->RowHeadersWidth = 62;
            this->gridDetailedGrades->Size = System::Drawing::Size(800, 182);
            this->gridDetailedGrades->TabIndex = 5;
            // 
            // btnExportGrades
            // 
            this->btnExportGrades->Location = System::Drawing::Point(700, 243);
            this->btnExportGrades->Name = L"btnExportGrades";
            this->btnExportGrades->Size = System::Drawing::Size(120, 30);
            this->btnExportGrades->TabIndex = 6;
            this->btnExportGrades->Text = L"Export Grades";
            this->btnExportGrades->Click += gcnew System::EventHandler(this, &View_Grade::btnExportGrades_Click);
            // 
            // View_Grade
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(873, 500);
            this->Controls->Add(this->menuStrip1);
            this->Controls->Add(this->groupBoxGradeStats);
            this->Controls->Add(this->comboGradeSemester);
            this->Controls->Add(this->chartGradeProgress);
            this->Controls->Add(this->gridDetailedGrades);
            this->Controls->Add(this->btnExportGrades);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MainMenuStrip = this->menuStrip1;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->MinimumSize = System::Drawing::Size(860, 538);
            this->Name = L"View_Grade";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"View Grades";
            this->Load += gcnew System::EventHandler(this, &View_Grade::View_Grade_Load);
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->groupBoxGradeStats->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartGradeProgress))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDetailedGrades))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // Rest of the methods remain the same...
        void SetupGradesGrid(void) {
            this->gridDetailedGrades->ColumnCount = 6;
            array<String^>^ columnNames = {
                "Course Code",
                "Course Name",
                "Credits",
                "Midterm Grade",
                "Final Grade",
                "Overall Grade"
            };

            for (int i = 0; i < columnNames->Length; i++) {
                this->gridDetailedGrades->Columns[i]->Name = columnNames[i];
                this->gridDetailedGrades->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            }

            LoadGradeData();
        }

        void LoadGradeData(void) {
            try {
                this->gridDetailedGrades->Rows->Clear();
                this->gridDetailedGrades->Rows->Add("CS101", "Programming Fundamentals", "3", "A", "A", "A");
                this->gridDetailedGrades->Rows->Add("CS102", "Data Structures", "3", "A-", "A", "A-");
                this->gridDetailedGrades->Rows->Add("MATH101", "Calculus I", "3", "B+", "A-", "B+");
                this->gridDetailedGrades->Rows->Add("PHY101", "Physics I", "4", "B", "B+", "B+");
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading grade data: " + ex->Message);
            }
        }

        System::Void View_Grade_Load(System::Object^ sender, System::EventArgs^ e) {
            LoadGradeData();
        }

        System::Void comboGradeSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            LoadGradeData();
        }

        System::Void btnExportGrades_Click(System::Object^ sender, System::EventArgs^ e) {
            SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
            saveFileDialog1->Filter = "PDF Files (*.pdf)|*.pdf|Excel Files (*.xlsx)|*.xlsx";
            saveFileDialog1->FilterIndex = 1;
            saveFileDialog1->RestoreDirectory = true;

            if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                try {
                    MessageBox::Show("Exporting grades to: " + saveFileDialog1->FileName);
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error exporting grades: " + ex->Message);
                }
            }
        }
private: System::Void chartGradeProgress_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}