#pragma once
#include "MT.h"
#include "help_form.h"

#define DEBAG_MODE 0
namespace turing20 {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			canvas = gcnew Bitmap(4000, pic->Height);
			g = Graphics::FromImage(canvas);
			tape = gcnew array<wchar_t>(30);
			for(int i = 0; i < 30; i++)
				tape[i] = '*';
			draw_tape();
			position = 0;
			STOPWHEREYOUARECITIZEN = 0;
			CODEISRUNNING = 0;
			Filename = "";
			content_before = "";
			h = gcnew help_form();
		}
#pragma region Windows Form Designer generated code
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mt;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  new_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  open_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  save_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  saveas_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  exit;
	private: System::Windows::Forms::ToolStripMenuItem^  лентаToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  lenta_lenth;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  code;

	private: System::Windows::Forms::TextBox^  lenta_text;
	private: System::Windows::Forms::NumericUpDown^  lenta_pos;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::ToolStripMenuItem^  run_button;
	private: System::Windows::Forms::ToolStripMenuItem^  run_syntax_button;


	private: System::Windows::Forms::ToolStripMenuItem^  run_step_button;
	private: System::Windows::Forms::ToolStripMenuItem^  параметрыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  setings_show;
	private: System::Windows::Forms::OpenFileDialog^  opendialog;



	private: System::Windows::Forms::SaveFileDialog^  savedialog;

	private: System::Windows::Forms::ToolStripMenuItem^  error_show;




	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::RichTextBox^  errors;

	private: System::Windows::Forms::HScrollBar^  l_scrool;
	private: System::Windows::Forms::ToolStripMenuItem^  lenta_show;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::ToolStripMenuItem^  run_stop_button;
	private: System::Windows::Forms::ToolStripMenuItem^  run_suspend_button;
	private: System::Windows::Forms::ToolStripMenuItem^  spr;
	private: System::Windows::Forms::ToolStripMenuItem^  Help;
	private: System::Windows::Forms::ToolStripMenuItem^  about;
	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


//#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->new_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->open_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveas_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лентаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->run_button = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->run_syntax_button = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->run_step_button = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->run_stop_button = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->run_suspend_button = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->параметрыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setings_show = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->error_show = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lenta_show = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->spr = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->about = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->l_scrool = (gcnew System::Windows::Forms::HScrollBar());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->lenta_lenth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lenta_text = (gcnew System::Windows::Forms::TextBox());
			this->lenta_pos = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->code = (gcnew System::Windows::Forms::RichTextBox());
			this->opendialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->savedialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->errors = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_lenth))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_pos))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->mt, this->лентаToolStripMenuItem, 
				this->параметрыToolStripMenuItem, this->spr});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(671, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mt
			// 
			this->mt->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->new_mt, this->open_mt, 
				this->save_mt, this->saveas_mt, this->exit});
			this->mt->Name = L"mt";
			this->mt->Size = System::Drawing::Size(67, 20);
			this->mt->Text = L"Машина";
			// 
			// new_mt
			// 
			this->new_mt->Name = L"new_mt";
			this->new_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->new_mt->Size = System::Drawing::Size(234, 22);
			this->new_mt->Text = L"Новая";
			this->new_mt->Click += gcnew System::EventHandler(this, &Form1::new_mt_Click);
			// 
			// open_mt
			// 
			this->open_mt->Name = L"open_mt";
			this->open_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->open_mt->Size = System::Drawing::Size(234, 22);
			this->open_mt->Text = L"Открыть";
			this->open_mt->Click += gcnew System::EventHandler(this, &Form1::open_mt_Click);
			// 
			// save_mt
			// 
			this->save_mt->Name = L"save_mt";
			this->save_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->save_mt->Size = System::Drawing::Size(234, 22);
			this->save_mt->Text = L"Сохранить";
			this->save_mt->Click += gcnew System::EventHandler(this, &Form1::save_mt_Click);
			// 
			// saveas_mt
			// 
			this->saveas_mt->Name = L"saveas_mt";
			this->saveas_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->saveas_mt->Size = System::Drawing::Size(234, 22);
			this->saveas_mt->Text = L"Сохранить как...";
			this->saveas_mt->Click += gcnew System::EventHandler(this, &Form1::saveas_mt_Click);
			// 
			// exit
			// 
			this->exit->Name = L"exit";
			this->exit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->exit->Size = System::Drawing::Size(234, 22);
			this->exit->Text = L"Выход";
			this->exit->Click += gcnew System::EventHandler(this, &Form1::exit_Click);
			// 
			// лентаToolStripMenuItem
			// 
			this->лентаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->run_button, 
				this->run_syntax_button, this->run_step_button, this->run_stop_button, this->run_suspend_button});
			this->лентаToolStripMenuItem->Name = L"лентаToolStripMenuItem";
			this->лентаToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->лентаToolStripMenuItem->Text = L"Запуск";
			// 
			// run_button
			// 
			this->run_button->Name = L"run_button";
			this->run_button->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->run_button->Size = System::Drawing::Size(356, 22);
			this->run_button->Text = L"Выполнить код по таймеру";
			this->run_button->Click += gcnew System::EventHandler(this, &Form1::run_button_Click);
			// 
			// run_syntax_button
			// 
			this->run_syntax_button->Name = L"run_syntax_button";
			this->run_syntax_button->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::B));
			this->run_syntax_button->Size = System::Drawing::Size(356, 22);
			this->run_syntax_button->Text = L"Синтаксическая проверка";
			this->run_syntax_button->Click += gcnew System::EventHandler(this, &Form1::run_syntax_burron_Click);
			// 
			// run_step_button
			// 
			this->run_step_button->Name = L"run_step_button";
			this->run_step_button->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Space));
			this->run_step_button->Size = System::Drawing::Size(356, 22);
			this->run_step_button->Text = L"Выполнить код по шагам";
			this->run_step_button->Click += gcnew System::EventHandler(this, &Form1::run_step_button_Click);
			// 
			// run_stop_button
			// 
			this->run_stop_button->Enabled = false;
			this->run_stop_button->Name = L"run_stop_button";
			this->run_stop_button->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Shift | System::Windows::Forms::Keys::F5));
			this->run_stop_button->Size = System::Drawing::Size(356, 22);
			this->run_stop_button->Text = L"Остановить выполнение кода";
			this->run_stop_button->Click += gcnew System::EventHandler(this, &Form1::run_stop_button_Click);
			// 
			// run_suspend_button
			// 
			this->run_suspend_button->Enabled = false;
			this->run_suspend_button->Name = L"run_suspend_button";
			this->run_suspend_button->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::Space));
			this->run_suspend_button->Size = System::Drawing::Size(356, 22);
			this->run_suspend_button->Text = L"Приостановить выполнение кода";
			this->run_suspend_button->Click += gcnew System::EventHandler(this, &Form1::run_suspend_button_Click);
			// 
			// параметрыToolStripMenuItem
			// 
			this->параметрыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->setings_show, 
				this->error_show, this->lenta_show});
			this->параметрыToolStripMenuItem->Name = L"параметрыToolStripMenuItem";
			this->параметрыToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->параметрыToolStripMenuItem->Text = L"Вид";
			// 
			// setings_show
			// 
			this->setings_show->Checked = true;
			this->setings_show->CheckState = System::Windows::Forms::CheckState::Checked;
			this->setings_show->Name = L"setings_show";
			this->setings_show->Size = System::Drawing::Size(138, 22);
			this->setings_show->Text = L"Параметры";
			this->setings_show->Click += gcnew System::EventHandler(this, &Form1::setings_show_Click);
			// 
			// error_show
			// 
			this->error_show->Checked = true;
			this->error_show->CheckState = System::Windows::Forms::CheckState::Checked;
			this->error_show->Name = L"error_show";
			this->error_show->Size = System::Drawing::Size(138, 22);
			this->error_show->Text = L"Ошибки";
			this->error_show->Click += gcnew System::EventHandler(this, &Form1::error_show_Click);
			// 
			// lenta_show
			// 
			this->lenta_show->Checked = true;
			this->lenta_show->CheckState = System::Windows::Forms::CheckState::Checked;
			this->lenta_show->Name = L"lenta_show";
			this->lenta_show->Size = System::Drawing::Size(138, 22);
			this->lenta_show->Text = L"Лента";
			this->lenta_show->Click += gcnew System::EventHandler(this, &Form1::lenta_show_Click);
			// 
			// spr
			// 
			this->spr->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Help, this->about});
			this->spr->Name = L"spr";
			this->spr->Size = System::Drawing::Size(65, 20);
			this->spr->Text = L"Справка";
			// 
			// Help
			// 
			this->Help->Name = L"Help";
			this->Help->Size = System::Drawing::Size(149, 22);
			this->Help->Text = L"Помощь";
			this->Help->Click += gcnew System::EventHandler(this, &Form1::Help_Click);
			// 
			// about
			// 
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(149, 22);
			this->about->Text = L"О программе";
			this->about->Click += gcnew System::EventHandler(this, &Form1::about_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox1->Controls->Add(this->l_scrool);
			this->groupBox1->Controls->Add(this->pic);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(0, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(671, 80);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Лента";
			// 
			// l_scrool
			// 
			this->l_scrool->LargeChange = 1;
			this->l_scrool->Location = System::Drawing::Point(3, 60);
			this->l_scrool->Maximum = 0;
			this->l_scrool->Name = L"l_scrool";
			this->l_scrool->Size = System::Drawing::Size(665, 20);
			this->l_scrool->TabIndex = 1;
			this->l_scrool->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::l_scrool_Scroll);
			// 
			// pic
			// 
			this->pic->Location = System::Drawing::Point(3, 16);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(665, 44);
			this->pic->TabIndex = 0;
			this->pic->TabStop = false;
			// 
			// lenta_lenth
			// 
			this->lenta_lenth->Location = System::Drawing::Point(6, 36);
			this->lenta_lenth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9000, 0, 0, 0});
			this->lenta_lenth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			this->lenta_lenth->Name = L"lenta_lenth";
			this->lenta_lenth->Size = System::Drawing::Size(94, 20);
			this->lenta_lenth->TabIndex = 98;
			this->lenta_lenth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			this->lenta_lenth->ValueChanged += gcnew System::EventHandler(this, &Form1::lenta_lenth_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Длина ленты";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox2->Controls->Add(this->lenta_text);
			this->groupBox2->Controls->Add(this->lenta_pos);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->lenta_lenth);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox2->Location = System::Drawing::Point(551, 104);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(120, 317);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметры";
			// 
			// lenta_text
			// 
			this->lenta_text->Location = System::Drawing::Point(6, 85);
			this->lenta_text->Name = L"lenta_text";
			this->lenta_text->Size = System::Drawing::Size(90, 20);
			this->lenta_text->TabIndex = 99;
			this->lenta_text->TextChanged += gcnew System::EventHandler(this, &Form1::lenta_text_TextChanged);
			// 
			// lenta_pos
			// 
			this->lenta_pos->Location = System::Drawing::Point(6, 135);
			this->lenta_pos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {29, 0, 0, 0});
			this->lenta_pos->Name = L"lenta_pos";
			this->lenta_pos->Size = System::Drawing::Size(90, 20);
			this->lenta_pos->TabIndex = 100;
			this->lenta_pos->ValueChanged += gcnew System::EventHandler(this, &Form1::lenta_pos_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Задать ленту";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Текущая позиция";
			// 
			// code
			// 
			this->code->AcceptsTab = true;
			this->code->DetectUrls = false;
			this->code->Dock = System::Windows::Forms::DockStyle::Fill;
			this->code->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->code->Location = System::Drawing::Point(0, 104);
			this->code->Name = L"code";
			this->code->Size = System::Drawing::Size(551, 211);
			this->code->TabIndex = 0;
			this->code->Text = L"";
			this->code->WordWrap = false;
			this->code->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::code_KeyDown);
			this->code->SizeChanged += gcnew System::EventHandler(this, &Form1::code_resize);
			this->code->Resize += gcnew System::EventHandler(this, &Form1::code_resize);
			this->code->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::code_KeyDown);
			this->code->Click += gcnew System::EventHandler(this, &Form1::code_CursorChanged);
			// 
			// opendialog
			// 
			this->opendialog->Filter = L"kilel Turing Machines|*.tmk|All Files|*.*";
			// 
			// savedialog
			// 
			this->savedialog->DefaultExt = L"tmk";
			this->savedialog->Filter = L"kilel Turing Machines|*.tmk|All Files|*.*";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->errors);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->groupBox3->Location = System::Drawing::Point(0, 315);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(551, 106);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Лог";
			// 
			// errors
			// 
			this->errors->AcceptsTab = true;
			this->errors->DetectUrls = false;
			this->errors->Dock = System::Windows::Forms::DockStyle::Fill;
			this->errors->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->errors->Location = System::Drawing::Point(3, 16);
			this->errors->Name = L"errors";
			this->errors->ReadOnly = true;
			this->errors->Size = System::Drawing::Size(545, 87);
			this->errors->TabIndex = 0;
			this->errors->Text = L"";
			this->errors->WordWrap = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Right;
			this->label4->Location = System::Drawing::Point(499, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Строка 0";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(671, 421);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->code);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"TuringMachine";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Resize += gcnew System::EventHandler(this, &Form1::resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_lenth))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_pos))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	///<global var>
	public:
		array<wchar_t>^tape;
		int position;
		Bitmap^ canvas;
		Graphics^g;
		MT^main;
		int STOPWHEREYOUARECITIZEN;
		int CODEISRUNNING;
		String^ Filename, ^content_before;
		help_form ^h;
	///</global>
	///<code>
	
	
#pragma region commented code
	/*void add_s(array<String^> ^s, String^ t, array<int> ^lab_num , int f)
	{
		for(int i = 0; i < s->Length;i++)
			if(String::Compare(s[i],t,1) == 0)
				return;
		s->Resize(s,s->Length+1);
		s[s->Length-1] = t->ToLower();
		if(f)
		{
			lab_num->Resize(lab_num,lab_num->Length+1);
			lab_num[lab_num->Length-1] = f-1;
		}
	}
	int include(String^s, wchar_t c, int start_pos, int end_pos)
	{
		for(int i = start_pos; i < end_pos; i++)
			if(i > s->Length)
				return (-1);
			else if(s[i] == c)
				return i;
		return (-1);
	}
	int eat_word(String^ s)
	{
		int a;
		for( int k = 0; k < 4; k++)
			if((a = include(s,trim_chars[k],0,s->Length)) > 0)
				return a;
		return -1;
	}
	String^ eating_worm(String^s, int b, String^ MT, RichTextBox^ rrr)
	{
		int a;
		do
		{
			a = eat_word(s);
			if(a > 0)
			{
				errors->Text += "Ошибка 404(;?), машина "+ MT +", строка " + rrr->GetLineFromCharIndex(a+b) + "\n";
				s = s->Substring(a)->Trim(trim_chars);
			} 
		}while(a > 0);
		return s;
	}
*/
	/*void check_sint(RichTextBox^ rrr, String^ MT)//syntax checkin
	{
		array<String^> ^com1, ^checked_ways1, ^labels, ^foundlabels;
		array<int> ^lab_num;
		com1 = gcnew array<String^>(5);
		com1[0] = L"goto";
		com1[1] = L"if(";
		com1[2] = L"s";
		com1[3] = L"l";
		com1[4] = L"r";
		checked_ways1 = gcnew array<String^>(0);
		labels = gcnew array<String^>(0);
		foundlabels = gcnew array<String^>(0);
		lab_num = gcnew array<int>(0);

		
		String^s = rrr->Text->Trim(trim_chars);
		errors->Text = "";
		String ^tmp, ^ttt;
		int n = s->Length, a=0,b=0,c=0;
		for(int i = 0; i < n; i++)
		{
st:		if(i >= n)
				goto end_syn;
			a = 0; b = 0;c = 0;
			if((b = include(s, L';', i, n)) < 0)	//search 4 next ';'
			{
				errors->Text += "Ошибка 404(;?): машина "+ MT +" строки [" + rrr->GetLineFromCharIndex(i) + ", " + rrr->GetLineFromCharIndex(n-1) + "]\n";
				goto end_syn;
			}
			tmp = s->Substring(i, b-i)->Trim(trim_chars);
			ttt = s->Substring(i,b-i);
			if(tmp->Length != 0)							//проверка определения МТ
			{
				if(tmp[0] == '#')		
				{
					tmp = tmp->Substring(1)->Trim(trim_chars);
					if(tmp->Length == 0)
					{
						errors->Text += "Ошибка 4, машины не могут начинаться с '#' и '&' (в машине "+ MT +"), строка " + rrr->GetLineFromCharIndex(i) + "\n";
						i = b;
						goto st;
					}
					if(tmp[0] == '#' || tmp[0] == '&')
					{
						errors->Text += "Ошибка 4, машины не могут начинаться с '#' и '&' (в машине "+ MT +"), строка " + rrr->GetLineFromCharIndex(i) + "\n";
						i = b;
						goto st;
					}
					if((c = include(tmp,':',0, tmp->Length)) > 0)
					{
						errors->Text += "Ошибка 4, машины не могут содержать ':' (в машине "+ MT +"), строка " + rrr->GetLineFromCharIndex(i) + "\n";
						i = b;
						goto st;
					}
					c = eat_word(tmp);														
					if(c < 0)
					{
						errors->Text += "Ошибка 1: не найден путь определения машины "+ tmp +" в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(i) + "\n";
						tmp = "";
					}
					else
					{
						String^ tt = tmp->Substring(0,c);		//имя создаваемой машины
						for(int j = 0; j < com1->Length; j++)		//есть ли такая машина уже?
							if(String::Compare(com1[j], tt, 1) == 0)
							{			//переопределение машины запрещено
								i = b+1; 
								errors->Text += "Ошибка 2: переопределение машины "+ tt +" в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(i) + "\n";
								goto st;		//выход в начало цикла
							}
						com1->Resize(com1, com1->Length+1);
						com1[com1->Length-1] = tt;
						tmp = tmp->Substring(c)->Trim(trim_chars);
						if(tmp[0] == '~')
							tmp = Directory::GetCurrentDirectory() + tmp->Substring(1);
						if(File::Exists(tmp))
						{
							for(int j = 0; j < checked_ways->Length; j++)
								if(String::Compare(checked_ways1[j], tmp, 1) == 0)
								{			//такая машина уже осмотрена/осматривается, не надо сюда заходить
									i = b+1; 
									goto st;
								}
							checked_ways1->Resize(checked_ways1, checked_ways1->Length+1);	//добавили в просмотренные
							checked_ways1[checked_ways1->Length - 1] = tmp;
							RichTextBox^ nn = gcnew RichTextBox();
							nn->Lines = File::ReadAllLines(tmp);
							check_sint(nn,tt);
							delete nn;
							
						}
						else
						{
							tmp = "";
							errors->Text += "Ошибка 1: неверный путь определения машины "+ tt +" в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(i) + "\n";
						}
					}
				}
			else if((c = include(ttt, L':', 0, ttt->Length) ) > 0)		//проверка на метку
			{
				String^ tt = ttt->Substring(0,c)->Trim(trim_chars);
				eating_worm(tt,i,MT,rrr);
				
				for(int i = 0; i < labels->Length;i++)
						if(String::Compare(labels[i],tt,1) == 0)
							return;
				labels->Resize(labels,labels->Length+1);
				labels[labels->Length-1] = tt->ToLower();
				i += c+1;
				goto st;
				}
			else if(tmp[0] == '&')		//напечатать первый символ из перечисленных далее
			{
				tmp = tmp->Substring(1)->Trim(trim_chars);
				eating_worm(tmp,i,MT,rrr);
				tmp = "";
			}
			else if(tmp->Length >3)
			{
				if(tmp->Substring(0,3) == "if(")					//проверка на иф  if(k) m; или if($k) m;
				{
					tmp = tmp->Substring(3);
					if((c = include(tmp, L')', 0, tmp->Length) ) < 0)
					{	
						errors->Text += "Ошибка 5: нет закрывающей скобки в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(i) + "\n";
						i = b+1;
						goto st;
					}
					String^ tt = tmp->Substring(0,c)->Trim(trim_chars);
					if(eat_word(tt) > 0)
					{
						errors->Text += "Ошибка 6: разрывное содержимое скобок в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(i) + "\n";
						i = b+1;
						goto st;
					}
					tt = tmp->Substring(c);
					if(tt->Length == 1)
					{
						errors->Text += "Ошибка 7: нет метки после if() "+ MT +", строка " + rrr->GetLineFromCharIndex(i+c) + "\n";
						i = b+1;
						goto st;
					}
					tmp = tt->Substring(1)->Trim(trim_chars);
					for(int i = 0; i < foundlabels->Length;i++)
							if(String::Compare(foundlabels[i],tmp,1) == 0)
								return;
					foundlabels->Resize(foundlabels,foundlabels->Length+1);
					foundlabels[foundlabels->Length-1] = tmp->ToLower();
					lab_num->Resize(lab_num,lab_num->Length+1);
					lab_num[lab_num->Length-1] = i+c+2;
					eating_worm(tmp,i+c,MT,rrr);
					tmp = "";
					}
				else if(tmp->Length > 5)
				{
					if(tmp->Substring(0,5) == "goto ")					//проверка на goto
					{
						tmp = tmp->Substring(5)->Trim(trim_chars);
						
						for(int i = 0; i < foundlabels->Length;i++)
							if(String::Compare(foundlabels[i],tmp,1) == 0)
								return;
						foundlabels->Resize(foundlabels,foundlabels->Length+1);
						foundlabels[foundlabels->Length-1] = tmp->ToLower();
						lab_num->Resize(lab_num,lab_num->Length+1);
						lab_num[lab_num->Length-1] = i+5;
						tmp = "";
					}
				}
			
			}
}
			eating_worm(tmp,i,MT, rrr);				//проверка tmp на монолитность
			if(tmp->Length == 0)
			{
				i = b+1;
				goto st;
			}
			for(int j = 0; j < com1->Length; j++)
				if(String::Compare(com1[j], tmp, 1) == 0)
				{
					i = b+1;
					goto st;
				}
				errors->Text += "Ошибка 3: не определена машина "+ tmp +" в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(i) + "\n";
			i = b;
		}
end_syn:
		for(int i = 0;  i < foundlabels->Length; i++)
		{
			for(int j = 0; j < labels->Length; j++)
				if(String::Compare(labels[j], foundlabels[i],1) == 0)
					goto st1;
			errors->Text += "Ошибка 8: не найдена метка "+ foundlabels[i] +" в машине "+ MT +", строка " + rrr->GetLineFromCharIndex(lab_num[i]) + "\n";
st1:		;
		}
	}*/
#pragma endregion
void every_step_i_do()
{
	String^ t = (main->next_step(tape[position]));
		if(DEBAG_MODE)
			errors->Text += "\n"+ t;
		if(STOPWHEREYOUARECITIZEN)
			t = "s";
		if(t->Length == 1)
		{
			switch(t[0])
			{
			case 's':
				run_button->Enabled = true;
				run_step_button->Enabled = true;
				run_syntax_button->Enabled = true;
				run_stop_button->Enabled = false;
				run_suspend_button->Enabled = false;
				groupBox2->Enabled = true;
				errors->Text = "Готово!";
				STOPWHEREYOUARECITIZEN = 0;
				CODEISRUNNING = 0;
				MT::clear();
				timer->Stop();
				break;
			case 'r':
				r();
				break;
			case 'l':
				l();
				break;
			}
		}else
		{
			if(t[0] == '&')
			{
				tape[position] = t[1];
				draw_tape();
				return;
			}
			MessageBox::Show("длина исполнимой строки больше нормы");;
			timer->Stop();
			return;
		}
}
void timer_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		every_step_i_do();
	}
#pragma region additional functions
	void lenta_text_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		int n = lenta_lenth->Value.ToInt32(lenta_lenth->Value);
		for(int i = 0; i < n; i++)
			if(i < lenta_text->Text->Length)
				tape[i] = lenta_text->Text[i];
			else
				tape[i] = '*';
		draw_tape();
	}
	void lenta_lenth_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		int n = tape->Length;
		lenta_pos->Maximum = lenta_lenth->Value - 1;
		l_scrool->Maximum = Convert::ToInt32( lenta_lenth->Value) - 30;
		int m = lenta_lenth->Value.ToInt32(lenta_lenth->Value);
		tape->Resize(tape, m);
		lenta_text_TextChanged(sender,e);
		draw_tape();
	}
	void resize(System::Object^  sender, System::EventArgs^  e) 
	{
		pic->Width = groupBox1->Width - 6;
		pic->Height = groupBox1->Height - 19;
		label4->Location.X = code->Width-83;
		l_scrool->Width = pic->Width;
		draw_tape();
	}
	void lenta_pos_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		position = lenta_lenth->Value.ToInt32(lenta_pos->Value);
		draw_tape();
	}
	void code_CursorChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		label4->Text ="Строка " + code->GetLineFromCharIndex(code->SelectionStart);
	}
	void error_show_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		error_show->Checked = !error_show->Checked;
		groupBox3->Visible=error_show->Checked;
	}
	void code_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		label4->Text ="Строка " + code->GetLineFromCharIndex(code->SelectionStart);
	}
	void setings_show_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		setings_show->Checked = !setings_show->Checked;
		groupBox2->Visible=setings_show->Checked;
	}
	void code_resize(System::Object^  sender, System::EventArgs^  e) 
	{
		label4->Location::set(Point(code->Width-83,label4->Location::get().Y));
	}
#pragma endregion
#pragma region lenta functions
	void r()
	{
		if(position != tape->Length - 1)
		{
			position++;
			lenta_pos->Value++;
		}
		else
		{
			position = 0;
			lenta_pos->Value = 0;
		}
	}
	void l()
	{
		if(position != 0)
		{
			position--;
			lenta_pos->Value--;
		}
		else
		{
			position = tape->Length-1;
			lenta_pos->Value = tape->Length-1;
		}
	}
	void draw_tape()
	{
		g->Clear(this->BackColor);
		double h = (double)(pic->Width-2)/30.0;
		for(int i = 0; i < 30; i++)
		{
			if((i+l_scrool->Value) == position)
				g->FillRectangle(Brushes::Red, i*h,2,Math::Floor(h)+1,18);
			g->DrawLine(Pens::Black, i*h, 2, (i+1)*h, 2);
			g->DrawLine(Pens::Black, i*h, 20, (i+1)*h, 20);
			g->DrawLine(Pens::Black, i*h, 2, i*h, 35);
			g->DrawLine(Pens::Black, (i+1)*h, 2, (i+1)*h, 35);
			g->DrawLine(Pens::Black, i*h, 35, (i+1)*h, 35);
			g->DrawString(""+tape[i+l_scrool->Value], this->Font, Brushes::Black, (i+0.5)*h - 3, 7);
			g->DrawString(""+(i+l_scrool->Value), this->Font, Brushes::Black, (i)*h , 22);
		}
		pic->Image = canvas;
	}
	void l_scrool_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) 
	{
		draw_tape();
	}
	void lenta_show_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		lenta_show->Checked = !lenta_show->Checked;
		groupBox1->Visible = lenta_show->Checked;

	}
#pragma endregion	
#pragma region Menu functions
	int synt()
	{
		main = gcnew MT(code->Lines, "MAIN");
		errors->Text = main->syntax();
		if(errors->Text->Length == 0)
			errors->Text = "ok";
		else
		{
			CODEISRUNNING = 0;
			MT::clear();
			error_show->Checked = true;
			groupBox3->Visible = error_show->Checked;
			MessageBox::Show("Обнаружены синтаксические ошибки, прекращаю работу");
			return 1;
		}
		return 0;
	}
	void run_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(CODEISRUNNING == 0)
		{
			CODEISRUNNING = 1;
			if(synt())
				return;
			main->start_machine();
		}
			run_button->Enabled = false;
			run_step_button->Enabled = false;
			run_syntax_button->Enabled = false;
			run_stop_button->Enabled = true;
			run_suspend_button->Enabled = true;
			groupBox2->Enabled = false;
		timer->Start();	
	}
	void run_syntax_burron_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		synt();
		MT::clear();
	}
	void run_step_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(!run_stop_button->Enabled)
		{//first step
			CODEISRUNNING = 1;
			if(synt())
				return;
			main->start_machine();
			run_syntax_button->Enabled = false;
			groupBox2->Enabled = false;
			run_suspend_button->Enabled = false;
			run_stop_button->Enabled = true;
		}
		every_step_i_do();
	}
	void run_stop_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		timer->Stop();
		STOPWHEREYOUARECITIZEN = 1;
		every_step_i_do();
	}
	void run_suspend_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		timer->Stop();
		run_suspend_button->Enabled = false;
		run_step_button->Enabled = true;
		run_button->Enabled = true;
	}
	int ask_to_save(System::Object^  sender, System::EventArgs^  e)
	{
		if(content_before != code->Text)
			switch(MessageBox::Show("Сохранить файл?","Диалог сохранения",MessageBoxButtons::YesNoCancel))
			{
				case System::Windows::Forms::DialogResult::OK:
					save_mt_Click(sender,e);
					return 1;
				case System::Windows::Forms::DialogResult::Cancel:
					return 0;
			}
		return -1;
	}
	void new_mt_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(ask_to_save(sender,e))
		{
			Filename = "";
			code->Text = "";
			this->Text = "turing 2.0    ";
			content_before = code->Text;
		}
	}
	void open_mt_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(ask_to_save(sender,e) && opendialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		{
			Filename = opendialog->FileName;
			code->Lines = File::ReadAllLines(Filename);
			this->Text = "turing 2.0    "+Filename;
			content_before = code->Text;
		}
	}
	void save_mt_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(Filename->Length != 0)
		{
			File::WriteAllLines(Filename,code->Lines);
			content_before = code->Text;
		}
		else
			saveas_mt_Click(sender,e);
	}
	void saveas_mt_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		switch(savedialog->ShowDialog())
		{
			case System::Windows::Forms::DialogResult::OK:
				Filename = savedialog->FileName;
				File::WriteAllLines(Filename,code->Lines);
				content_before = code->Text;
				this->Text = "turing 2.0    "+Filename;
				break;
		}
	}
	void exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Close();
	}
	void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if(!ask_to_save(sender,e))
			e->Cancel = true;
	}
	void Help_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		h = gcnew help_form();
		h->Show();
	}
	void about_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		MessageBox::Show("turing 2.0\n\nбаги кидать сюда:\nki.lel@ya.ru","О программе");
	}
	
#pragma endregion


	
	
};
}

