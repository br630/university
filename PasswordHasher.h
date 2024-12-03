#pragma once
#using <mscorlib.dll>
#using <System.dll>

namespace university {
    using namespace System;
    using namespace System::Text;
    using namespace System::Security::Cryptography;

    public ref class PasswordHasher {
    public:
        static String^ HashPassword(String^ password) {
            if (String::IsNullOrEmpty(password)) {
                return "";
            }

            array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(password);
            array<Byte>^ hash = MD5::Create()->ComputeHash(bytes);

            StringBuilder^ builder = gcnew StringBuilder();
            for (int i = 0; i < hash->Length; i++) {
                builder->Append(hash[i].ToString("x2"));
            }

            return builder->ToString();
        }
    };
}