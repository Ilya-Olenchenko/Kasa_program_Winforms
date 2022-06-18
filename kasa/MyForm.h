#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <windows.h>
#include "Order.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Form2.h"
namespace kasa {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	const int MAX = 8;	//Кількість клієнтів
	int visible = 0;
	int sum_text = MAX; //Скільки лишилось ввести клієнтів
	int num = 0;		//скільки клієнтів вже є в базі

	int temp_num = 0;
	Order SPISOK[MAX];

	const char* filename = "file.bin";

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			label_to_add->Text = "Залишилось додати записів: " + sum_text;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox_PLAT;
	private: System::Windows::Forms::TextBox^ textBox_POL;
	private: System::Windows::Forms::TextBox^ textBox_SUMMA;
	private: System::Windows::Forms::Label^ label_PLAT;
	private: System::Windows::Forms::Label^ label_POL;
	private: System::Windows::Forms::Label^ label_SUMMA;
	protected:
	protected:
	private: System::Windows::Forms::Label^ label_to_add;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::ListBox^ listBox_client;
	private: System::Windows::Forms::Button^ button_search;


	private: System::Windows::Forms::Button^ button_del;
	private: System::Windows::Forms::Button^ button_edit;
	private: System::Windows::Forms::TextBox^ textBox_edit_POL;
	private: System::Windows::Forms::TextBox^ textBox_edit_SUMM;
	private: System::Windows::Forms::Button^ button_edit_fin;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button_OTMEHA;
	private: System::Windows::Forms::Button^ button_save;
	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::TextBox^ textBox_Searh_PLAT;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>


		void InitializeComponent(void)
		{
			this->textBox_PLAT = (gcnew System::Windows::Forms::TextBox());
			this->textBox_POL = (gcnew System::Windows::Forms::TextBox());
			this->textBox_SUMMA = (gcnew System::Windows::Forms::TextBox());
			this->label_PLAT = (gcnew System::Windows::Forms::Label());
			this->label_POL = (gcnew System::Windows::Forms::Label());
			this->label_SUMMA = (gcnew System::Windows::Forms::Label());
			this->label_to_add = (gcnew System::Windows::Forms::Label());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->listBox_client = (gcnew System::Windows::Forms::ListBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->button_del = (gcnew System::Windows::Forms::Button());
			this->button_edit = (gcnew System::Windows::Forms::Button());
			this->textBox_edit_POL = (gcnew System::Windows::Forms::TextBox());
			this->textBox_edit_SUMM = (gcnew System::Windows::Forms::TextBox());
			this->button_edit_fin = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_OTMEHA = (gcnew System::Windows::Forms::Button());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->textBox_Searh_PLAT = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox_PLAT
			// 
			this->textBox_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_PLAT->Location = System::Drawing::Point(13, 66);
			this->textBox_PLAT->Margin = System::Windows::Forms::Padding(4);
			this->textBox_PLAT->Name = L"textBox_PLAT";
			this->textBox_PLAT->Size = System::Drawing::Size(348, 30);
			this->textBox_PLAT->TabIndex = 0;
			// 
			// textBox_POL
			// 
			this->textBox_POL->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_POL->Location = System::Drawing::Point(13, 129);
			this->textBox_POL->Margin = System::Windows::Forms::Padding(4);
			this->textBox_POL->Name = L"textBox_POL";
			this->textBox_POL->Size = System::Drawing::Size(348, 30);
			this->textBox_POL->TabIndex = 1;
			// 
			// textBox_SUMMA
			// 
			this->textBox_SUMMA->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_SUMMA->Location = System::Drawing::Point(12, 204);
			this->textBox_SUMMA->Margin = System::Windows::Forms::Padding(4);
			this->textBox_SUMMA->Name = L"textBox_SUMMA";
			this->textBox_SUMMA->Size = System::Drawing::Size(348, 30);
			this->textBox_SUMMA->TabIndex = 2;
			this->textBox_SUMMA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_SUMMA_KeyPress);
			// 
			// label_PLAT
			// 
			this->label_PLAT->AutoSize = true;
			this->label_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_PLAT->Location = System::Drawing::Point(9, 40);
			this->label_PLAT->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_PLAT->Name = L"label_PLAT";
			this->label_PLAT->Size = System::Drawing::Size(298, 22);
			this->label_PLAT->TabIndex = 3;
			this->label_PLAT->Text = L"Розрахунковий рахунок платника:";
			// 
			// label_POL
			// 
			this->label_POL->AutoSize = true;
			this->label_POL->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_POL->Location = System::Drawing::Point(13, 103);
			this->label_POL->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_POL->Name = L"label_POL";
			this->label_POL->Size = System::Drawing::Size(316, 22);
			this->label_POL->TabIndex = 4;
			this->label_POL->Text = L"Розрахунковий рахунок одержувача:";
			// 
			// label_SUMMA
			// 
			this->label_SUMMA->AutoSize = true;
			this->label_SUMMA->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_SUMMA->Location = System::Drawing::Point(13, 174);
			this->label_SUMMA->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_SUMMA->Name = L"label_SUMMA";
			this->label_SUMMA->Size = System::Drawing::Size(290, 22);
			this->label_SUMMA->TabIndex = 5;
			this->label_SUMMA->Text = L"Сума, що перераховується в грн.:";
			// 
			// label_to_add
			// 
			this->label_to_add->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_to_add->Location = System::Drawing::Point(382, 9);
			this->label_to_add->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_to_add->Name = L"label_to_add";
			this->label_to_add->Size = System::Drawing::Size(345, 31);
			this->label_to_add->TabIndex = 7;
			this->label_to_add->Text = L"Залишилось додати записів: 8";
			// 
			// button_add
			// 
			this->button_add->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_add->Location = System::Drawing::Point(13, 253);
			this->button_add->Margin = System::Windows::Forms::Padding(4);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(348, 47);
			this->button_add->TabIndex = 8;
			this->button_add->Text = L"Зберегти";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// listBox_client
			// 
			this->listBox_client->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox_client->FormattingEnabled = true;
			this->listBox_client->ItemHeight = 22;
			this->listBox_client->Location = System::Drawing::Point(387, 40);
			this->listBox_client->Margin = System::Windows::Forms::Padding(4);
			this->listBox_client->Name = L"listBox_client";
			this->listBox_client->Size = System::Drawing::Size(367, 312);
			this->listBox_client->Sorted = true;
			this->listBox_client->TabIndex = 9;
			this->listBox_client->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox_client_SelectedIndexChanged);
			// 
			// button_search
			// 
			this->button_search->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_search->Location = System::Drawing::Point(550, 360);
			this->button_search->Margin = System::Windows::Forms::Padding(4);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(195, 60);
			this->button_search->TabIndex = 10;
			this->button_search->Text = L"Показати повну інформацію";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MyForm::button_visual_Click);
			// 
			// button_del
			// 
			this->button_del->Location = System::Drawing::Point(853, 185);
			this->button_del->Name = L"button_del";
			this->button_del->Size = System::Drawing::Size(135, 60);
			this->button_del->TabIndex = 13;
			this->button_del->Text = L"Видалити";
			this->button_del->UseVisualStyleBackColor = true;
			this->button_del->Click += gcnew System::EventHandler(this, &MyForm::button_del_Click);
			// 
			// button_edit
			// 
			this->button_edit->Location = System::Drawing::Point(853, 132);
			this->button_edit->Name = L"button_edit";
			this->button_edit->Size = System::Drawing::Size(337, 47);
			this->button_edit->TabIndex = 14;
			this->button_edit->Text = L"Редагування";
			this->button_edit->UseVisualStyleBackColor = true;
			this->button_edit->Click += gcnew System::EventHandler(this, &MyForm::button_edit_Click);
			// 
			// textBox_edit_POL
			// 
			this->textBox_edit_POL->Location = System::Drawing::Point(853, 133);
			this->textBox_edit_POL->Multiline = true;
			this->textBox_edit_POL->Name = L"textBox_edit_POL";
			this->textBox_edit_POL->Size = System::Drawing::Size(340, 30);
			this->textBox_edit_POL->TabIndex = 15;
			this->textBox_edit_POL->Visible = false;
			// 
			// textBox_edit_SUMM
			// 
			this->textBox_edit_SUMM->Location = System::Drawing::Point(853, 193);
			this->textBox_edit_SUMM->Multiline = true;
			this->textBox_edit_SUMM->Name = L"textBox_edit_SUMM";
			this->textBox_edit_SUMM->Size = System::Drawing::Size(340, 26);
			this->textBox_edit_SUMM->TabIndex = 16;
			this->textBox_edit_SUMM->Visible = false;
			this->textBox_edit_SUMM->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_edit_SUMM_KeyPress);
			// 
			// button_edit_fin
			// 
			this->button_edit_fin->Location = System::Drawing::Point(853, 225);
			this->button_edit_fin->Name = L"button_edit_fin";
			this->button_edit_fin->Size = System::Drawing::Size(107, 30);
			this->button_edit_fin->TabIndex = 17;
			this->button_edit_fin->Text = L"Редагувати";
			this->button_edit_fin->UseVisualStyleBackColor = true;
			this->button_edit_fin->Visible = false;
			this->button_edit_fin->Click += gcnew System::EventHandler(this, &MyForm::button_edit_fin_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(849, 108);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(316, 22);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Розрахунковий рахунок одержувача:";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(849, 168);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(290, 22);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Сума, що перераховується в грн.:";
			this->label2->Visible = false;
			// 
			// button_OTMEHA
			// 
			this->button_OTMEHA->Location = System::Drawing::Point(967, 225);
			this->button_OTMEHA->Name = L"button_OTMEHA";
			this->button_OTMEHA->Size = System::Drawing::Size(104, 33);
			this->button_OTMEHA->TabIndex = 20;
			this->button_OTMEHA->Text = L"Відмінити";
			this->button_OTMEHA->UseVisualStyleBackColor = true;
			this->button_OTMEHA->Visible = false;
			this->button_OTMEHA->Click += gcnew System::EventHandler(this, &MyForm::button_OTMEHA_Click);
			// 
			// button_save
			// 
			this->button_save->Location = System::Drawing::Point(17, 397);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(156, 23);
			this->button_save->TabIndex = 21;
			this->button_save->Text = L"Зберегти в файл";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &MyForm::button_save_Click);
			// 
			// button_load
			// 
			this->button_load->Location = System::Drawing::Point(197, 397);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(132, 23);
			this->button_load->TabIndex = 22;
			this->button_load->Text = L"Зчитати з файла";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &MyForm::button_load_Click);
			// 
			// textBox_Searh_PLAT
			// 
			this->textBox_Searh_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_Searh_PLAT->Location = System::Drawing::Point(853, 94);
			this->textBox_Searh_PLAT->Margin = System::Windows::Forms::Padding(4);
			this->textBox_Searh_PLAT->Multiline = true;
			this->textBox_Searh_PLAT->Name = L"textBox_Searh_PLAT";
			this->textBox_Searh_PLAT->Size = System::Drawing::Size(340, 31);
			this->textBox_Searh_PLAT->TabIndex = 11;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1221, 430);
			this->Controls->Add(this->button_load);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->button_OTMEHA);
			this->Controls->Add(this->button_edit);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->button_del);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_edit_fin);
			this->Controls->Add(this->textBox_edit_SUMM);
			this->Controls->Add(this->textBox_edit_POL);
			this->Controls->Add(this->textBox_Searh_PLAT);
			this->Controls->Add(this->listBox_client);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->label_to_add);
			this->Controls->Add(this->label_SUMMA);
			this->Controls->Add(this->label_POL);
			this->Controls->Add(this->label_PLAT);
			this->Controls->Add(this->textBox_SUMMA);
			this->Controls->Add(this->textBox_POL);
			this->Controls->Add(this->textBox_PLAT);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void enter_to_listbox() //Занесення клієнтів в ListBox
		{
			listBox_client->Items->Clear();

			for (int i = 0; i < num; ++i) {
				listBox_client->Items->Add(msclr::interop::marshal_as<String^>(SPISOK[i].PLAT) +
					" (" + msclr::interop::marshal_as<String^>(SPISOK[i].data) + ")");
			}
		}

		String^ print_messegbox(int i) //вивід повної інформації про платіж
		{
			String^ text = "Розрахунковий рахунок платника: " + msclr::interop::marshal_as<String^>(SPISOK[i].PLAT)
				+ "\nРозрахунковий рахунок одержувача: " + msclr::interop::marshal_as<String^>(SPISOK[i].POL)
				+ "\nЗнята сума: " + SPISOK[i].SUMMA + " грн."
				+ "\nЧас перерахунку платежу: " + msclr::interop::marshal_as<String^>(SPISOK[i].data);
			return text;
		}


		//кнопка додавання
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e) {
		bool chek = false;

		if (num == MAX) {
			textBox_edit_POL->Text = "";
			textBox_edit_SUMM->Text = "";
			textBox_Searh_PLAT->Text = "";
			MessageBox::Show("Додано максимальну кількість записів в базу!");
		}
		else {
			if (textBox_PLAT->Text != "" && kasa::MyForm::textBox_POL->Text != "" && kasa::MyForm::textBox_SUMMA->Text != "") {
				for (int i = 0; i < num; ++i) {
					if (textBox_PLAT->Text->ToString() == msclr::interop::marshal_as<String^>(SPISOK[i].PLAT)) {
						chek = true;
						break;
					}
				}
				if (chek == false) {
					DateTime^ DateTimeNow = gcnew DateTime;
					DateTimeNow = DateTime::Now;

					SPISOK[num].PLAT = msclr::interop::marshal_as<std::string>(textBox_PLAT->Text->ToString());
					SPISOK[num].POL = msclr::interop::marshal_as<std::string>(textBox_POL->Text->ToString());
					SPISOK[num].SUMMA = Convert::ToDouble(textBox_SUMMA->Text);
					SPISOK[num].data = msclr::interop::marshal_as<std::string>(DateTimeNow->Day.ToString() + "." + DateTimeNow->Month.ToString() + "." + DateTimeNow->Year.ToString() + "-" + DateTimeNow->Hour.ToString() + ":" + DateTimeNow->Minute.ToString() + ":" + DateTimeNow->Second.ToString());
					num += 1;

					enter_to_listbox(); //Занесення клієнтів в ListBox

					textBox_PLAT->Text = "";
					textBox_POL->Text = "";
					textBox_SUMMA->Text = "";
					sum_text -= 1;
					label_to_add->Text = "Можливість додати ще " + sum_text + " запис(ів).";
				}
				else {
					MessageBox::Show("Платник вже присутній в базі даних!");
				}
			}
			else {
				MessageBox::Show("Не можна допускати порожні поля!");
			}
		}
	}

	private: System::Void button_edit_Click(System::Object^ sender, System::EventArgs^ e) {
		bool chek = false;

		for (int i = 0; i < num; ++i) {
			if (textBox_Searh_PLAT->Text->ToString() == msclr::interop::marshal_as<String^>(SPISOK[i].PLAT)) {
				chek = true;
				temp_num = i;
				break;
			}
		}

		if (chek == true) {
			textBox_Searh_PLAT->Visible = true;;

			button_del->Visible = false;
			button_search->Visible = false;
			button_edit->Visible = false;

			textBox_edit_POL->Visible = true;
			textBox_edit_SUMM->Visible = true;
			button_OTMEHA->Visible = true;

			button_edit_fin->Visible = true;
			button_edit->Visible = false;

			label1->Visible = true;
			label2->Visible = true;

		}
		else {
			MessageBox::Show("Введеного вами розрахункового рахунку платника нема в списку бази даних.");
		}
	}


	private: System::Void button_edit_fin_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox_edit_POL->Text != "" && textBox_edit_SUMM->Text != "" && textBox_Searh_PLAT->Text != "") {

			SPISOK[temp_num].PLAT = msclr::interop::marshal_as<std::string>(textBox_Searh_PLAT->Text->ToString());
			SPISOK[temp_num].POL = msclr::interop::marshal_as<std::string>(textBox_edit_POL->Text->ToString());
			SPISOK[temp_num].SUMMA = Convert::ToDouble(textBox_edit_SUMM->Text);

			enter_to_listbox(); //Занесення клієнтів в ListBox

			textBox_edit_POL->Visible = false;
			textBox_edit_SUMM->Visible = false;
			button_OTMEHA->Visible = false;
			button_edit_fin->Visible = false;

			label1->Visible = false;
			label2->Visible = false;

			button_edit->Visible = true;
			textBox_edit_POL->Text = "";
			textBox_edit_SUMM->Text = "";
			textBox_Searh_PLAT->Text = "";


			button_del->Visible = true;
			button_search->Visible = true;
			button_edit->Visible = true;


			MessageBox::Show("Запис змінено.");
		}
		else {
			MessageBox::Show("Не можна допускати порожні поля!");
		}

	}

	private: System::Void button_OTMEHA_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox_edit_POL->Visible = false;
		textBox_edit_SUMM->Visible = false;

		label1->Visible = false;
		label2->Visible = false;

		button_edit_fin->Visible = false;

		button_edit->Visible = true;
		textBox_edit_POL->Text = "";
		textBox_edit_SUMM->Text = "";
		textBox_Searh_PLAT->Text = "";

		button_del->Visible = true;
		button_search->Visible = true;
		button_edit->Visible = true;
	}



		  //Показ інформації про вибраного клієнта через textbox
	private: System::Void button_visual_Click(System::Object^ sender, System::EventArgs^ e) {
		Form2^ f2 = gcnew Form2(SPISOK, num);
		f2->ShowDialog();
	}



		   //Показ інформації про вибраного клієнта через лістбокс
	private: System::Void listBox_client_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		String^ curItem = listBox_client->SelectedItem->ToString();

		for (int i = 0; i < MAX; ++i) {
			if (msclr::interop::marshal_as<std::string>(curItem) == (SPISOK[i].PLAT + " (" + SPISOK[i].data + ")")) {
				textBox_Searh_PLAT->Text = msclr::interop::marshal_as<String^>(SPISOK[i].PLAT);
			}
		}
	}

		   //KeyPress подія для заборони вводу всіх символів в textBox_SUMMA окрім чисел
	private: System::Void textBox_SUMMA_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (Char::IsDigit(e->KeyChar))
			return;
		if (e->KeyChar == (char)Keys::Back)
			return;
		e->Handled = true;
	}

	private: System::Void button_del_Click(System::Object^ sender, System::EventArgs^ e) { //видалення вибраного елементу з масиву
		bool chek = false;

		for (int j = 0; j < num; ++j) {
			if (textBox_Searh_PLAT->Text == msclr::interop::marshal_as<String^>(SPISOK[j].PLAT)) {
				for (int i = j; i < num - 1; ++i)
				{
					SPISOK[i] = SPISOK[i + 1];
				}
				num -= 1;
				chek = true;
				textBox_Searh_PLAT->Text = "";
				sum_text += 1;
				label_to_add->Text = "Можливість додати ще " + sum_text + " запис(ів).";
				enter_to_listbox();
				break;
			}
		}
		if (chek == false) {
			MessageBox::Show("Введеного вами розрахункового рахунку платника нема в списку бази даних.");
		}
	}


	private: System::Void textBox_edit_SUMM_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (Char::IsDigit(e->KeyChar))
			return;
		if (e->KeyChar == (char)Keys::Back)
			return;
		e->Handled = true;
	}
	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e) {

		ofstream file;
		file.open(filename);
		for (int i = 0; i < num; ++i)
		{
			file << SPISOK[i].PLAT << " " << SPISOK[i].POL << " " << SPISOK[i].SUMMA << " " << SPISOK[i].data << endl;
		}
		file.close();
	}


	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		ifstream file(filename);
		num = 0;

		for (int i = 0; !file.eof(); ++i)
		{
			file >> SPISOK[i].PLAT >> SPISOK[i].POL >> SPISOK[i].SUMMA >> SPISOK[i].data;
			num += 1;
		}
		num -= 1;
		file.close();

		sum_text = MAX - num;

		label_to_add->Text = "Можливість додати ще " + sum_text + " запис(ів).";
		enter_to_listbox();
	}
	};
}
