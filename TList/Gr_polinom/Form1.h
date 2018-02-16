#pragma once
#include "TPolinom.h"
#include  <string>
namespace Gr_polinom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		TPolinom *p;
		int k;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;

	public: 

	public: 
	private: System::Windows::Forms::Button^  button4;
	public: 
		Form1(void)
		{
			InitializeComponent();
			p=new TPolinom[10];
			k=0;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(396, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(440, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(36, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(440, 111);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(36, 25);
			this->button2->TabIndex = 1;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(440, 49);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(36, 25);
			this->button3->TabIndex = 1;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(414, 25);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(68, 20);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Добавить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Результат";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(396, 20);
			this->textBox2->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(488, 150);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: String^ PolToString(TPolinom &p){

				 String^ tmp="";
				 for(p.reset();!p.isEnd();p.goNext()){
					 if (!p.isStart() && p.getCoeffM()>0) tmp+="+";
					 if (p.getCoeffM()!=1) tmp+=p.getCoeffM();
					 if (p.getXM()) if (p.getXM()>1) tmp+="x^"+p.getXM();
					                else tmp+="x";
					 if (p.getYM()) if (p.getYM()>1) tmp+="y^"+p.getYM();
					                else tmp+="y";
					 if (p.getZM()) if (p.getZM()>1) tmp+="z^"+p.getZM();
					                else tmp+="z";
				 }
				 return tmp;
		}
	private: string MarshalString ( String ^ s) {  
				string os;
			    using namespace Runtime::InteropServices;  
				const char* chars =   
			    (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
			    os = chars;  
				Marshal::FreeHGlobal(IntPtr((void*)chars));  
				return os;
       }  
	private : void toPolinom(String^ a,int k){
				  TMonom q;
				  string a1=MarshalString(a);
				  string tmp="";
				  for(int i=0;i<a1.size();i++){
					  if (a1[i]=='+'){ p[k].sortInput(q.toMonom(tmp)); tmp=""; continue;}
					  if (a1[i]=='-'){ p[k].sortInput(q.toMonom(tmp)); tmp=""; }
					  tmp+=a1[i];
					  if (i==a1.size()-1){ p[k].sortInput(q.toMonom(tmp)); }
				  }
				  }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 p[0].clearList();
				 p[1].clearList();
				 toPolinom(textBox1->Text,0);
				 toPolinom(textBox2->Text,1);
				 
			
		 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 label1->Text=PolToString(p[0]*p[1]);
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
             label1->Text=PolToString(p[0]+p[1]);
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			   label1->Text=PolToString(p[0]-p[1]);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

