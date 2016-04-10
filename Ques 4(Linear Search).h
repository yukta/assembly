#pragma once
int ar[10]; // global array
int A,B; // values which check if linear search was sucess A=1 for success
namespace LinearSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

		void linearsearch(int search,int total) //linear search
		{
			_asm
			{
				mov ecx,total 		
				lea ESI, ar			; //can be mov offset too
				
			l1:
				mov eax,[ESI]			; // getting in the start value
				cmp eax , search
				je l3    ;// if the elements are equal
				dec ecx
				cmp ecx, 0   ;//count returns to 0
				je l4
				ADD ESI , 4				;// because of int size = 4 bytes
				jmp l1
				
			l3: 
				mov A, 1

			l4:			;//end the program

			}// end of _asm
		}

		void binarysearch(int search,int total)
		{
			_asm
			{
			

			}
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(43, 111);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(208, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(182, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Input an array separated by a comma";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 194);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Linear Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 150);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Search Element";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(151, 150);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(151, 194);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Binary";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(179, 229);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"No";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) //Linear Search
			 {
					String^ a; 
					
					a=textBox1->Text;
					int len = a->Length;
					int ind=0; int k=0; String^ part;
					for(int i=0;i<len; i++)
					{
					if(a[i]==',')             // comma separated array index
					{
						part = a->Substring(ind,i-ind);
						ar[k] = Convert::ToInt32(part);
						k++;
						ind=i+1;
					}
					}
					int search=Convert::ToInt32(textBox2->Text);
					linearsearch(search,k); // test for linear 
					if(A==0)
						textBox3->Text="NO"+A;
					else
						textBox3->Text="YES";
					
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)   
		 {
			
		 }
};
}

