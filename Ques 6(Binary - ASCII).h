#pragma once

namespace binascii {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	void Converts(int number, int radix, char* data)
	{
		_asm
		{
				mov ebx, data
				push radix
				mov eax, number
			L1 :
				mov edx, 0
				div radix
				push edx
				cmp eax, 0
				jnz L1
			L2 :
				pop edx
				cmp edx, radix
				je L4
				add dl, 30h
				cmp dl, 39h
				jbe L3
				add dl, 7
			L3:
				mov[ebx], dl
				inc ebx
				jmp L2
			L4 :
				mov byte ptr[ebx], 0
		}
	}



	/// <summary>
	/// Summary for binaryASCII
	/// </summary>
	public ref class binaryASCII : public System::Windows::Forms::Form
	{
	public:
		binaryASCII(void)
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
		~binaryASCII()
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
			this->label1->Location = System::Drawing::Point(31, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// binaryASCII
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Name = L"binaryASCII";
			this->Text = L"binaryASCII";
			this->Load += gcnew System::EventHandler(this, &binaryASCII::binaryASCII_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void binaryASCII_Load(System::Object^  sender, System::EventArgs^  e) {

		char temp[32];
		Converts(7423, 10, temp);
		String^ a = "";
		int count = 0;
		while (temp[count] != 0)
		{
			Char b = temp[count++];
			a += b;
		}
		label1->Text = a;
	}

};
}
