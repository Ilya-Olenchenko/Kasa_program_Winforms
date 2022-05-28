#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <windows.h>

namespace kasa {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	const int MAX = 8;//Кількість клієнтів

	int sum_text = MAX; //Скільки лишилось ввести клієнтів
	int num = 0; //скільки клієнтів вже є в базі

	struct Order {

		string PLAT; //розрахунковий рахунок платника
		string POL; //розрахунковий рахунок одержувача
		double  SUMMA; //сума, що перераховується в грн.

		string datatime; //точний час на момент проведення платежу
	};

	Order SPISOK[MAX];

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
	private: System::Windows::Forms::Label^ label_big_text;

	protected:

	protected:

	private: System::Windows::Forms::Label^ label_to_add;
	private: System::Windows::Forms::Button^ button_add;

	private: System::Windows::Forms::ListBox^ listBox_client;
	private: System::Windows::Forms::Button^ button_search;
	private: System::Windows::Forms::TextBox^ textBox_Searh_PLAT;
	private: System::Windows::Forms::Label^ label_search_PLAT;
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
			this->label_big_text = (gcnew System::Windows::Forms::Label());
			this->label_to_add = (gcnew System::Windows::Forms::Label());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->listBox_client = (gcnew System::Windows::Forms::ListBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->textBox_Searh_PLAT = (gcnew System::Windows::Forms::TextBox());
			this->label_search_PLAT = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox_PLAT
			// 
			this->textBox_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_PLAT->Location = System::Drawing::Point(36, 106);
			this->textBox_PLAT->Margin = System::Windows::Forms::Padding(4);
			this->textBox_PLAT->Name = L"textBox_PLAT";
			this->textBox_PLAT->Size = System::Drawing::Size(348, 30);
			this->textBox_PLAT->TabIndex = 0;
			// 
			// textBox_POL
			// 
			this->textBox_POL->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_POL->Location = System::Drawing::Point(36, 193);
			this->textBox_POL->Margin = System::Windows::Forms::Padding(4);
			this->textBox_POL->Name = L"textBox_POL";
			this->textBox_POL->Size = System::Drawing::Size(348, 30);
			this->textBox_POL->TabIndex = 1;
			// 
			// textBox_SUMMA
			// 
			this->textBox_SUMMA->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_SUMMA->Location = System::Drawing::Point(36, 278);
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
			this->label_PLAT->Location = System::Drawing::Point(36, 80);
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
			this->label_POL->Location = System::Drawing::Point(36, 167);
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
			this->label_SUMMA->Location = System::Drawing::Point(36, 252);
			this->label_SUMMA->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_SUMMA->Name = L"label_SUMMA";
			this->label_SUMMA->Size = System::Drawing::Size(290, 22);
			this->label_SUMMA->TabIndex = 5;
			this->label_SUMMA->Text = L"Сума, що перераховується в грн.:";
			// 
			// label_big_text
			// 
			this->label_big_text->AutoSize = true;
			this->label_big_text->BackColor = System::Drawing::SystemColors::Menu;
			this->label_big_text->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_big_text->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_big_text->ForeColor = System::Drawing::Color::Black;
			this->label_big_text->Location = System::Drawing::Point(31, 11);
			this->label_big_text->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_big_text->Name = L"label_big_text";
			this->label_big_text->Size = System::Drawing::Size(367, 31);
			this->label_big_text->TabIndex = 6;
			this->label_big_text->Text = L"Додайте записи до бази даних.";
			this->label_big_text->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_to_add
			// 
			this->label_to_add->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_to_add->Location = System::Drawing::Point(424, 53);
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
			this->button_add->Location = System::Drawing::Point(456, 106);
			this->button_add->Margin = System::Windows::Forms::Padding(4);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(273, 47);
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
			this->listBox_client->Location = System::Drawing::Point(31, 46);
			this->listBox_client->Margin = System::Windows::Forms::Padding(4);
			this->listBox_client->Name = L"listBox_client";
			this->listBox_client->Size = System::Drawing::Size(367, 334);
			this->listBox_client->Sorted = true;
			this->listBox_client->TabIndex = 9;
			this->listBox_client->Visible = false;
			this->listBox_client->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox_client_SelectedIndexChanged);
			// 
			// button_search
			// 
			this->button_search->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_search->Location = System::Drawing::Point(456, 333);
			this->button_search->Margin = System::Windows::Forms::Padding(4);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(273, 47);
			this->button_search->TabIndex = 10;
			this->button_search->Text = L"Показати";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Visible = false;
			this->button_search->Click += gcnew System::EventHandler(this, &MyForm::button_visual_Click);
			// 
			// textBox_Searh_PLAT
			// 
			this->textBox_Searh_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_Searh_PLAT->Location = System::Drawing::Point(456, 256);
			this->textBox_Searh_PLAT->Margin = System::Windows::Forms::Padding(4);
			this->textBox_Searh_PLAT->Multiline = true;
			this->textBox_Searh_PLAT->Name = L"textBox_Searh_PLAT";
			this->textBox_Searh_PLAT->Size = System::Drawing::Size(272, 31);
			this->textBox_Searh_PLAT->TabIndex = 11;
			this->textBox_Searh_PLAT->Visible = false;
			// 
			// label_search_PLAT
			// 
			this->label_search_PLAT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_search_PLAT->Location = System::Drawing::Point(424, 193);
			this->label_search_PLAT->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_search_PLAT->Name = L"label_search_PLAT";
			this->label_search_PLAT->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_search_PLAT->Size = System::Drawing::Size(365, 59);
			this->label_search_PLAT->TabIndex = 12;
			this->label_search_PLAT->Text = L"Введіть розрахунковий рахунок платника, або виберіть зі списку.";
			this->label_search_PLAT->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 409);
			this->Controls->Add(this->label_search_PLAT);
			this->Controls->Add(this->textBox_Searh_PLAT);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->listBox_client);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->label_to_add);
			this->Controls->Add(this->label_big_text);
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
			for (int i = 0; i < MAX; ++i) {
				listBox_client->Items->Add(msclr::interop::marshal_as<String^>(SPISOK[i].PLAT) + " ("
					+ msclr::interop::marshal_as<String^>(SPISOK[i].datatime)+ ")");
			}
		}

		String^ print_messegbox(int i) //вивід повної інформації про платіж
		{
			String^ text = "Розрахунковий рахунок платника: " + msclr::interop::marshal_as<String^>(SPISOK[i].PLAT)
				+ "\nРозрахунковий рахунок одержувача: " + msclr::interop::marshal_as<String^>(SPISOK[i].POL)
				+ "\nЗнята сума: " + SPISOK[i].SUMMA
				+ "\nЧас перерахунку платежу: " + msclr::interop::marshal_as<String^>(SPISOK[i].datatime);
			return text;
		}

		void add() //функція додавання клієнтів в базу
		{
			String^ sum = textBox_SUMMA->Text;
			int a;
			bool chek = false;
			if (textBox_PLAT->Text != "" && textBox_POL->Text != "" && textBox_SUMMA->Text != "") {


					SPISOK[num].PLAT = msclr::interop::marshal_as<std::string>(textBox_PLAT->Text->ToString());
					SPISOK[num].POL = msclr::interop::marshal_as<std::string>(textBox_POL->Text->ToString());
					SPISOK[num].SUMMA = Convert::ToDouble(textBox_SUMMA->Text);
					SPISOK[num].datatime = msclr::interop::marshal_as<std::string>(DateTime::Now.ToString());
					num += 1;

					textBox_PLAT->Text = "";
					textBox_POL->Text = "";
					textBox_SUMMA->Text = "";
					sum_text -= 1;
					label_to_add->Text = "Залишилось додати записів: " + sum_text;
				
			}
			else {
				MessageBox::Show("Не можна допускати порожні поля!");
			}
		}
		//кнопка додавання
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e) {
		add();

		if (num == MAX) {
			label_big_text->Text = "База даних";
			label_PLAT->Visible = false;
			label_POL->Visible = false;
			label_SUMMA->Visible = false;
			textBox_PLAT->Visible = false;
			textBox_POL->Visible = false;
			textBox_SUMMA->Visible = false;
			label_to_add->Visible = false;
			button_add->Visible = false;

			enter_to_listbox(); //Занесення клієнтів в ListBox

			listBox_client->Visible = true;
			textBox_Searh_PLAT->Visible = true;
			label_search_PLAT->Visible = true;
			button_search->Visible = true;
		}
	}
	//Показ інформації про вибраного клієнта через textbox
	private: System::Void button_visual_Click(System::Object^ sender, System::EventArgs^ e) {
		bool check = false;
		String^ text = "";
		if (textBox_Searh_PLAT->Text != "") {
			for (int i = 0; i < MAX; ++i) {
				if ((SPISOK[i].PLAT + " (" + SPISOK[i].datatime + ")") == (msclr::interop::marshal_as<std::string>(textBox_Searh_PLAT->Text) + " (" + SPISOK[i].datatime + ")")) {
					text += (print_messegbox(i)) + "\n\n";
					check = true;
				}
			}

			if (check == false) {
				MessageBox::Show("Введеного вами параметра нема в списку бази даних.");
				textBox_Searh_PLAT->Text = "";
			}
			else
				MessageBox::Show(text);
		}
		else
			MessageBox::Show("Поле пошуку порожнє!");
	}
	//Показ інформації про вибраного клієнта через лістбокс
	private: System::Void listBox_client_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ curItem = listBox_client->SelectedItem->ToString();

		for (int i = 0; i < MAX; ++i) {
			if (msclr::interop::marshal_as<std::string>(curItem) == (SPISOK[i].PLAT + " (" + SPISOK[i].datatime + ")")) {
				MessageBox::Show(print_messegbox(i));	
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
};
}
