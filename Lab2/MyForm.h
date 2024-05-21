#include <chrono>
#include <vector>
#include "Arrs.h"
#include "Sorts.h"
#include <string>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#pragma once

namespace Lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::ComboBox^ comboBoxSorts;
	protected:

	protected:

	private: System::Windows::Forms::RadioButton^ rabioA1;
	private: System::Windows::Forms::RadioButton^ radioA2;
	private: System::Windows::Forms::RadioButton^ radioA3;
	private: System::Windows::Forms::RadioButton^ radioOurData;




	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::RadioButton^ radioRandom;

	private: System::Windows::Forms::Button^ button1;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBoxSorts = (gcnew System::Windows::Forms::ComboBox());
			this->rabioA1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioA2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioA3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioOurData = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioRandom = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBoxSorts
			// 
			this->comboBoxSorts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->comboBoxSorts->FormattingEnabled = true;
			this->comboBoxSorts->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Поразрядная", L"Вставками", L"Пузырьковая",
					L"Шейкера", L"Быстрая"
			});
			this->comboBoxSorts->Location = System::Drawing::Point(12, 12);
			this->comboBoxSorts->Name = L"comboBoxSorts";
			this->comboBoxSorts->Size = System::Drawing::Size(419, 46);
			this->comboBoxSorts->TabIndex = 1;
			this->comboBoxSorts->Text = L"Выберите сортировку";
			// 
			// rabioA1
			// 
			this->rabioA1->AutoSize = true;
			this->rabioA1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->rabioA1->Location = System::Drawing::Point(12, 64);
			this->rabioA1->Name = L"rabioA1";
			this->rabioA1->Size = System::Drawing::Size(207, 43);
			this->rabioA1->TabIndex = 2;
			this->rabioA1->TabStop = true;
			this->rabioA1->Text = L"Массив А1";
			this->rabioA1->UseVisualStyleBackColor = true;
			// 
			// radioA2
			// 
			this->radioA2->AutoSize = true;
			this->radioA2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->radioA2->Location = System::Drawing::Point(12, 111);
			this->radioA2->Name = L"radioA2";
			this->radioA2->Size = System::Drawing::Size(207, 43);
			this->radioA2->TabIndex = 3;
			this->radioA2->TabStop = true;
			this->radioA2->Text = L"Массив А2";
			this->radioA2->UseVisualStyleBackColor = true;
			// 
			// radioA3
			// 
			this->radioA3->AutoSize = true;
			this->radioA3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->radioA3->Location = System::Drawing::Point(12, 160);
			this->radioA3->Name = L"radioA3";
			this->radioA3->Size = System::Drawing::Size(207, 43);
			this->radioA3->TabIndex = 4;
			this->radioA3->TabStop = true;
			this->radioA3->Text = L"Массив А3";
			this->radioA3->UseVisualStyleBackColor = true;
			// 
			// radioOurData
			// 
			this->radioOurData->AutoSize = true;
			this->radioOurData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->radioOurData->Location = System::Drawing::Point(12, 209);
			this->radioOurData->Name = L"radioOurData";
			this->radioOurData->Size = System::Drawing::Size(248, 43);
			this->radioOurData->TabIndex = 5;
			this->radioOurData->TabStop = true;
			this->radioOurData->Text = L"Свои данные";
			this->radioOurData->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(12, 345);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(382, 350);
			this->textBox1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label1->Location = System::Drawing::Point(12, 303);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(323, 39);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Ввод своих данных";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox2->Location = System::Drawing::Point(540, 345);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(382, 350);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label2->Location = System::Drawing::Point(667, 303);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 39);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Вывод";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label3->Location = System::Drawing::Point(533, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(167, 39);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Скорость";
			// 
			// radioRandom
			// 
			this->radioRandom->AutoSize = true;
			this->radioRandom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->radioRandom->Location = System::Drawing::Point(12, 258);
			this->radioRandom->Name = L"radioRandom";
			this->radioRandom->Size = System::Drawing::Size(556, 33);
			this->radioRandom->TabIndex = 12;
			this->radioRandom->TabStop = true;
			this->radioRandom->Text = L"Случайный массив (по введенному размеру)";
			this->radioRandom->UseVisualStyleBackColor = true;
			this->radioRandom->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button1->Location = System::Drawing::Point(519, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 51);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1044, 707);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioRandom);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioOurData);
			this->Controls->Add(this->radioA3);
			this->Controls->Add(this->radioA2);
			this->Controls->Add(this->rabioA1);
			this->Controls->Add(this->comboBoxSorts);
			this->Name = L"MyForm";
			this->Text = L"Сортировки";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ SysString = "";

		if (rabioA1->Checked) {
			MySort(A1);
			for (auto i : A1) {
				SysString += System::Convert::ToString(i) + " ";
			}
		}
		else if (radioA2->Checked) {
			MySort(A2);
			for (auto i : A2) {
				SysString += System::Convert::ToString(i) + " ";
			}
		}
		else if (radioA3->Checked) {
			MySort(A3);
			for (auto i : A3) {
				SysString += System::Convert::ToString(i) + " ";
			}
		}
		else if (radioOurData->Checked) {
			
			String^ s = textBox1->Text;
			msclr::interop::marshal_context context;
			std::string os = context.marshal_as<std::string>(s);
			std::stringstream sos(os);
			std::string cur;
			if (isStringIsNumber(os)) {
				std::vector<int> vec;
				while (sos >> cur) {
					vec.push_back(stoi(cur));
				}
				MySort(vec);
				for (auto i : vec) {
					SysString += System::Convert::ToString(i) + " ";
				}
			}
			else {
				std::vector<int> vec;
				while (sos >> cur) {
					for (auto c : cur) {
						vec.push_back(static_cast<int>(c));
					}
				}
				MySort(vec);
				for (int i = 0; i < vec.size(); i++) {
					char ci = static_cast<char>(vec[i]);
					
					SysString += System::Char::ToString(ci) + " ";
				}
			}
		}
		else if (radioRandom->Checked) {
			String^ s = textBox1->Text;
			msclr::interop::marshal_context context;
			std::string os = context.marshal_as<std::string>(s);
			if (!isNumber(os)) {
				MessageBox::Show("Размер массива должен быть числом", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			size_t size = stoi(os);
			std::vector<int> vec = GenerateVector(size);

			
			MySort(vec);
			for (auto i : vec) {
				SysString += System::Convert::ToString(i) + " ";
			}
		}
		textBox2->Text = SysString;
		

	}

	private: void MySort(std::vector<int>& arr) {
		auto start = std::chrono::high_resolution_clock::now();
		if (comboBoxSorts->Text == "Поразрядная") {
			radixSort(arr);
		}
		else if (comboBoxSorts->Text == "Вставками") {
			insertionSort(arr);
		}
		else if (comboBoxSorts->Text == "Пузырьковая") {
			bubbleSort(arr);
		}
		else if (comboBoxSorts->Text == "Шейкера") {
			cocktailSort(arr);
		}
		else if (comboBoxSorts->Text == "Быстрая") {
			quickSort(arr);
		}
		else {
			MessageBox::Show("Не выбрана сортировка!!!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		std::stringstream stream;
		stream << duration.count() << " секунд";
		std::string durationString = stream.str();
		System::String^ durationStr = gcnew System::String(durationString.c_str());

		label3->Text = "Скорость " +  durationStr;
	}



private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
