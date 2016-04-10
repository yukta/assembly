#pragma once


namespace BCD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int bcd(int a,int b) // the real code for BCD addition
	{
		int sum;
		_asm
		{
			mov eax , a
			mov ebx , b
			
			add al , bl				; //adding lower first
			DAA						; //DAA operation
			mov cl,al				; //store the lower order

			mov al,ah				; // moving next higher 8 bits of EAX
			adc al,bh				; // Adding but with a carry
			DAA						; // Adjust
			mov ch,al				; // value now in CX = CH CL

			rol eax,16				; //now access the higher 16 bits

			adc al, bl				; //carry of past
			DAA
			mov dl,al				; // because CL is already occupied

			mov al,ah
			adc al , bh				; // adding with cary
			DAA
			mov dh,al				; // value now in DX = DH DL

			rol edx,16				; //shifting values to their desired position
			mov dx,0				; // vacating DX for cx
			add dx,cx				; // value in EDX

			mov sum,edx				; //value moved

		}
		return sum;
	}

	int bcddiff(int a,int b) // for subtraction
	{
		int diff;
		_asm
		{

			mov eax , a
			mov ebx , b
			
			sub al , bl				; //subtracting lower first
			DAS						; //DAS operation
			mov cl,al				; //store the lower order

			mov al,ah				; // moving next higher 8 bits of EAX
			sbb al,bh				; // Subtract but with a borrow
			DAS						; // Subtract adjust
			mov ch,al				; // value now in CX = CH CL

			rol eax,16				; //now access the higher 16 bits

			SBB al, bl				; //carry of past
			DAS
			mov dl,al				; // because CL is already occupied

			mov al,ah
			sbb al , bh				; // subtraction wit hcarry
			DAS
			mov dh,al				; // value now in DX = DH DL

			rol edx,16				; //shifting values to their desired position
			mov dx,0				; // vacating DX for cx
			add dx,cx				; // value in EDX

			mov diff,edx				; //value moved

		}
		return diff;
	}

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  BCD;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	protected: 

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
			this->BCD = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// BCD
			// 
			this->BCD->Location = System::Drawing::Point(16, 145);
			this->BCD->Name = L"BCD";
			this->BCD->Size = System::Drawing::Size(75, 23);
			this->BCD->TabIndex = 0;
			this->BCD->Text = L"Compute";
			this->BCD->UseVisualStyleBackColor = true;
			this->BCD->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"number 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Number 2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(100, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(100, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(173, 145);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(139, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Sum";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(120, 198);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Subtract";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(174, 198);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 8;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BCD);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)  // event handler
			 {
				 int a = Convert::ToInt32(textBox1->Text);
				 int b = Convert::ToInt32(textBox2->Text);

				int c = bcd(a,b);
					
				 textBox3->Text = " "+c; 

				 c = bcddiff(a,b);
				 textBox4->Text=" "+c;
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
