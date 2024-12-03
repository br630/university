#include "Manage_Profile.h"

namespace university {
    void Manage_Profile::LoadUserData() {
        try {
            dbManager->ConnectToDatabase();
            String^ query = "SELECT u.firstName, u.lastName, s.dateOfBirth, s.enrollmentDate, s.major, s.picture "
                "FROM users u "
                "JOIN students s ON u.userID = s.userID "
                "WHERE u.userID = @userID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, dbManager->GetConnection());
            cmd->Parameters->AddWithValue("@userID", currentUserID);


            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                // Set name
                String^ fullName = reader->GetString("firstName") + " " + reader->GetString("lastName");
                txt_name->Text = fullName;

                // Calculate and set age
                String^ dob = reader->GetString("dateOfBirth");
                label1->Text = CalculateAge(dob).ToString();

                // Set enrollment year
                String^ enrollmentDate = reader->GetString("enrollmentDate");
                txt_year->Text = enrollmentDate->Substring(0, 4);
            }

            reader->Close();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show("Error loading user data: " + ex->Message);
        }
        finally {
            dbManager->CloseConnection();
        }
    }

    int Manage_Profile::CalculateAge(String^ dateOfBirth) {
        DateTime birthDate = DateTime::Parse(dateOfBirth);
        DateTime today = DateTime::Now;
        int age = today.Year - birthDate.Year;
        if (birthDate > today.AddYears(-age)) age--;
        return age;
    }

    System::Void Manage_Profile::button1_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
        openFileDialog1->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
        openFileDialog1->Title = "Select a Profile Picture";

        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            try {
                currentImagePath = openFileDialog1->FileName;
                pictureBox1->Image = Image::FromFile(currentImagePath);
                pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

                // Convert image to bytes
                MemoryStream^ ms = gcnew MemoryStream();
                pictureBox1->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
                array<Byte>^ imageBytes = ms->ToArray();

                // Update database
                dbManager->ConnectToDatabase();
                String^ query = "UPDATE students SET picture = @picture WHERE userID = @userID";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, dbManager->GetConnection());

                cmd->Parameters->AddWithValue("@picture", imageBytes);
                cmd->Parameters->AddWithValue("@userID", currentUserID);

                if (cmd->ExecuteNonQuery() > 0) {
                    MessageBox::Show("Profile picture updated successfully!");
                }
                else {
                    MessageBox::Show("Failed to update profile picture");
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error updating profile picture: " + ex->Message);
            }
            finally {
                dbManager->CloseConnection();
            }
        }
    }

    System::Void Manage_Profile::Manage_Profile_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadUserData();
    }
    void Manage_Profile::UpdateProfilePicture() {
        try {
            if (currentImagePath == nullptr || currentImagePath->Length == 0) {
                return;
            }

            // Convert image to bytes
            array<Byte>^ imageBytes = File::ReadAllBytes(currentImagePath);

            // Update database
            dbManager->ConnectToDatabase();
            String^ query = "UPDATE students SET picture = @picture WHERE userID = @userID";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, dbManager->GetConnection());

            cmd->Parameters->AddWithValue("@picture", imageBytes);
            cmd->Parameters->AddWithValue("@userID", currentUserID);

            if (cmd->ExecuteNonQuery() > 0) {
                MessageBox::Show("Profile picture updated successfully!");
            }
            else {
                MessageBox::Show("Failed to update profile picture");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating profile picture: " + ex->Message);
        }
        finally {
            dbManager->CloseConnection();
        }
    }

    void Manage_Profile::SaveBioToDatabase() {
        try {
            String^ bio = richTextBox1->Text;

            dbManager->ConnectToDatabase();
            String^ query = "UPDATE students SET bio = @bio WHERE userID = @userID";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, dbManager->GetConnection());

            cmd->Parameters->AddWithValue("@bio", bio);
            cmd->Parameters->AddWithValue("@userID", currentUserID);

            if (cmd->ExecuteNonQuery() > 0) {
                MessageBox::Show("Bio updated successfully!");
            }
            else {
                MessageBox::Show("Failed to update bio");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating bio: " + ex->Message);
        }
        finally {
            dbManager->CloseConnection();
        }
    }
}