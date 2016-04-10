#pragma once

namespace ascibin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int ConvertAscii(char* data)
	{
		int number = 0;
		_asm
		{
				mov ebx, data
				mov ecx, 0
			B1:
				mov cl, [ebx]
				inc ebx
				cmp cl, 0
				je B2
				sub cl, 30h
				mov eax, 10
				mul number
				add eax, ecx
				mov number, eax
				jmp B1
			B2 :
		}

		return number;
	}

	/// <summary>
	/// Summary for ASCIIbinary
	/// </summary>
	public ref class ASCIIbinary : public System::Windows::Forms::Form
	{
	public:
		ASCIIbinary(void)
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
		~ASCIIbinary()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// ASCIIbinary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Name = L"ASCIIbinary";
			this->Text = L"ASCIIbinary";
			this->Load += gcnew System::EventHandler(this, &ASCIIbinary::ASCIIbinary_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ASCIIbinary_Load(System::Object^  sender, System::EventArgs^  e) {

		char temp[] = "2316";
		int number = ConvertAscii(temp);
		label1->Text = Convert::ToString(number);

	}
	};
}
