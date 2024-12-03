#include "Manage_Faculty_Profile.h"

namespace university {
    void Manage_Faculty_Profile::LoadUserData() {
        try {
            dbManager->ConnectToDatabase();
            String^ query = "SELECT u.firstName, u.lastName, f.dateOfAppointment, f.department "
                "FROM users u "
                "JOIN faculty f ON u.userID = f.userID "
                "WHERE u.userID = @userID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, dbManager->GetConnection());
            cmd->Parameters->AddWithValue("@userID", currentUserID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                // Set name
                String^ fullName = reader->GetString("firstName") + " " + reader->GetString("lastName");
                txt_name->Text = fullName;

                // Set department
                txt_department->Text = reader->GetString("department");

                // Set appointment date
                String^ appointmentDate = reader->GetString("dateOfAppointment");
                txt_year->Text = appointmentDate->Substring(0, 4); // Show year of appointment
            }

            reader->Close();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show("Error loading faculty data: " + ex->Message);
        }
        finally {
            dbManager->CloseConnection();
        }
    }

    System::Void Manage_Faculty_Profile::button1_Click(System::Object^ sender, System::EventArgs^ e) {
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
                String^ query = "UPDATE faculty SET picture = @picture WHERE userID = @userID";
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

    System::Void Manage_Faculty_Profile::Manage_Profile_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadUserData();
    }

    void Manage_Faculty_Profile::UpdateProfilePicture() {
        try {
            if (currentImagePath == nullptr || currentImagePath->Length == 0) {
                return;
            }

            array<Byte>^ imageBytes = File::ReadAllBytes(currentImagePath);

            dbManager->ConnectToDatabase();
            String^ query = "UPDATE faculty SET picture = @picture WHERE userID = @userID";
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