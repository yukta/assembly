#pragma once

namespace Multiplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	unsigned int c, d;		// for unsigned multiplication
	int f, g; // for the division part

	void multiply(unsigned int a, unsigned int b)
	{
		_asm
		{
			mov eax, a
			mov ebx, b
			imul ebx		; // signed multiply
			mov c, edx			; // above 32 bits 
			mov d, eax			; // lower 
		}
	}

	void divide(int a, int b)
	{
		_asm
		{
			mov eax, a
			mov ebx, b
			cdq			;// compatibility for divide i.e 64 bit / 32 bit 
			idiv ebx
			mov f, eax ; //quotient 
			mov g, edx	; //remainder
		}
	}


	/// <summary>
	/// Summary for MulDiv
	/// </summary>
	public ref class MulDiv : public System::Windows::Forms::Form
	{
	public:
		MulDiv(void)
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
		~MulDiv()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(105, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"a";
			this->label1->Click += gcnew System::EventHandler(this, &MulDiv::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(276, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MulDiv::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(105, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"b";
			this->label2->Click += gcnew System::EventHandler(this, &MulDiv::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(276, 94);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(149, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MulDiv::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(105, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Result";
			this->label3->Click += gcnew System::EventHandler(this, &MulDiv::label1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(276, 138);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(149, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MulDiv::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(142, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 31);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Multiplication";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MulDiv::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(276, 215);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(113, 30);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Division";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MulDiv::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(139, 248);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Number 1 * Number 2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(279, 248);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Number 1 / Nubmer 2";
			// 
			// Mul
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(517, 367);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Mul";
			this->Text = L"Multiply ";
			this->Load += gcnew System::EventHandler(this, &MulDiv::MulDiv_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MulDiv_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

		 try
		 {
			unsigned int a = Convert::ToInt32(textBox1->Text);
			unsigned int b = Convert::ToInt32(textBox2->Text);
			__int64 ans = 0;			//  32 X 32 = 64 bit

			multiply(a, b);	// call multiply func
			
			
			// manipulation for the EDX register
			
			ans = ans | c;
			ans = ans << 32;
			ans = ans | d;

			textBox3->Text =" "+ans;
		 }
		 catch (...)
		 {
			MessageBox::Show("Invalid Number. Please Try Again");
		 }
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
			// Divide Function	
		
		try
		{
			int a = Convert::ToInt32(textBox1->Text);
			int b = Convert::ToInt32(textBox2->Text);

			divide(a, b);

			textBox3->Text =" "+f+" "+g; // the quotient and remainder
		}
		catch (...)
		{
			MessageBox::Show("Limit exceeded");
		}
	}
};

