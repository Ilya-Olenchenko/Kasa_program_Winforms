#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <windows.h>
#include "Order.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

namespace kasa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int MAX2 = 8;
	static Order SPISOK2[MAX2];

	public ref class Form2 : public System::Windows::Forms::Form
	{
	private:int num2 = 0;
	public:
		Form2(Order SPISOK[], int num)
		{
			
			for (int i = 0; i < MAX2; ++i) {
				SPISOK2[i].PLAT = SPISOK[i].PLAT;
				SPISOK2[i].POL = SPISOK[i].POL;
				SPISOK2[i].SUMMA = SPISOK[i].SUMMA;
				SPISOK2[i].data = SPISOK[i].data;
			}
			
			num2 = num;
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox_Searh_PLAT;
	private: System::Windows::Forms::Label^ label_search_PLAT;
	private: System::Windows::Forms::Button^ button_search2;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox_Searh_PLAT = (gcnew System::Windows::Forms::TextBox());
			this->label_search_PLAT = (gcnew System::Windows::Forms::Label());
			this->button_search2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox_Searh_PLAT
			// 
			this->textBox_Searh_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_Searh_PLAT->Location = System::Drawing::Point(30, 72);
			this->textBox_Searh_PLAT->Margin = System::Windows::Forms::Padding(4);
			this->textBox_Searh_PLAT->Multiline = true;
			this->textBox_Searh_PLAT->Name = L"textBox_Searh_PLAT";
			this->textBox_Searh_PLAT->Size = System::Drawing::Size(340, 31);
			this->textBox_Searh_PLAT->TabIndex = 12;
			// 
			// label_search_PLAT
			// 
			this->label_search_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_search_PLAT->Location = System::Drawing::Point(13, 9);
			this->label_search_PLAT->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_search_PLAT->Name = L"label_search_PLAT";
			this->label_search_PLAT->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_search_PLAT->Size = System::Drawing::Size(357, 59);
			this->label_search_PLAT->TabIndex = 13;
			this->label_search_PLAT->Text = L"Введіть розрахунковий рахунок платника.";
			// 
			// button_search2
			// 
			this->button_search2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_search2->Location = System::Drawing::Point(30, 127);
			this->button_search2->Margin = System::Windows::Forms::Padding(4);
			this->button_search2->Name = L"button_search2";
			this->button_search2->Size = System::Drawing::Size(195, 60);
			this->button_search2->TabIndex = 14;
			this->button_search2->Text = L"Показати повну інформацію";
			this->button_search2->UseVisualStyleBackColor = true;
			this->button_search2->Click += gcnew System::EventHandler(this, &Form2::button_search_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(461, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 15;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(926, 412);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_search2);
			this->Controls->Add(this->label_search_PLAT);
			this->Controls->Add(this->textBox_Searh_PLAT);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e) {

		bool check = false;
		String^ text = "";

		if (textBox_Searh_PLAT->Text != "") {
			for (int i = 0; i < num2; ++i) {
				if ((SPISOK2[i].PLAT + " (" + SPISOK2[i].data + ")") == (msclr::interop::marshal_as<std::string>(textBox_Searh_PLAT->Text) + " (" + SPISOK2[i].data + ")")) {
					text += (print_messegbox2(i)) + "\n\n";
					check = true;
				}
			}

			if (check == false) {
				MessageBox::Show("Введеного вами розрахункового рахунку платника нема в списку бази даних.");
			}
			else
				label1->Text = text;
		}
		else
			MessageBox::Show("Поле пошуку порожнє!");

	}

		   String^ print_messegbox2(int i) //вивід повної інформації про платіж
		   {
			   String^ text = "Розрахунковий рахунок платника: " + msclr::interop::marshal_as<String^>(SPISOK2[i].PLAT)
				   + "\nРозрахунковий рахунок одержувача: " + msclr::interop::marshal_as<String^>(SPISOK2[i].POL)
				   + "\nЗнята сума: " + SPISOK2[i].SUMMA + " грн."
				   + "\nЧас перерахунку платежу: " + msclr::interop::marshal_as<String^>(SPISOK2[i].data);
			   return text;
		   }
	};
}
