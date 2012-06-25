#pragma once


namespace turing20 {

	using namespace System;
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
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
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
	private: System::Windows::Forms::ToolStripMenuItem^  new_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  open_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  save_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  saveas_mt;
	private: System::Windows::Forms::ToolStripMenuItem^  exit;
	private: System::Windows::Forms::ToolStripMenuItem^  ëåíòàToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  lenta_lenth;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  lenta_text;
	private: System::Windows::Forms::NumericUpDown^  lenta_pos;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::ToolStripMenuItem^  îòğàáîòàòüÊîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîÒàéìåğóToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîØàãàìToolStripMenuItem;
	private:
		/// <summary>
		/// Òğåáóåòñÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->new_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->open_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveas_mt = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ëåíòàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lenta_lenth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lenta_text = (gcnew System::Windows::Forms::TextBox());
			this->lenta_pos = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->îòğàáîòàòüÊîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîÒàéìåğóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîØàãàìToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_lenth))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_pos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mt, this->ëåíòàToolStripMenuItem});
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
			this->mt->Size = System::Drawing::Size(59, 20);
			this->mt->Text = L"Ìàøèíà";
			// 
			// new_mt
			// 
			this->new_mt->Name = L"new_mt";
			this->new_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->new_mt->Size = System::Drawing::Size(230, 22);
			this->new_mt->Text = L"Íîâàÿ";
			// 
			// open_mt
			// 
			this->open_mt->Name = L"open_mt";
			this->open_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->open_mt->Size = System::Drawing::Size(230, 22);
			this->open_mt->Text = L"Îòêğûòü";
			// 
			// save_mt
			// 
			this->save_mt->Name = L"save_mt";
			this->save_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->save_mt->Size = System::Drawing::Size(230, 22);
			this->save_mt->Text = L"Ñîõğàíèòü";
			// 
			// saveas_mt
			// 
			this->saveas_mt->Name = L"saveas_mt";
			this->saveas_mt->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->saveas_mt->Size = System::Drawing::Size(230, 22);
			this->saveas_mt->Text = L"Ñîõğàíèòü êàê...";
			// 
			// exit
			// 
			this->exit->Name = L"exit";
			this->exit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->exit->Size = System::Drawing::Size(230, 22);
			this->exit->Text = L"Âûõîä";
			// 
			// ëåíòàToolStripMenuItem
			// 
			this->ëåíòàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->îòğàáîòàòüÊîäToolStripMenuItem, 
				this->ïîÒàéìåğóToolStripMenuItem, this->ïîØàãàìToolStripMenuItem});
			this->ëåíòàToolStripMenuItem->Name = L"ëåíòàToolStripMenuItem";
			this->ëåíòàToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->ëåíòàToolStripMenuItem->Text = L"Çàïóñê";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox1->Controls->Add(this->pic);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(0, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(671, 63);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ëåíòà";
			// 
			// lenta_lenth
			// 
			this->lenta_lenth->Location = System::Drawing::Point(6, 36);
			this->lenta_lenth->Name = L"lenta_lenth";
			this->lenta_lenth->Size = System::Drawing::Size(94, 20);
			this->lenta_lenth->TabIndex = 98;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Äëèíà ëåíòû";
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
			this->groupBox2->Location = System::Drawing::Point(551, 87);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(120, 334);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ïàğàìåòğû";
			// 
			// lenta_text
			// 
			this->lenta_text->Location = System::Drawing::Point(6, 85);
			this->lenta_text->Name = L"lenta_text";
			this->lenta_text->Size = System::Drawing::Size(90, 20);
			this->lenta_text->TabIndex = 99;
			// 
			// lenta_pos
			// 
			this->lenta_pos->Location = System::Drawing::Point(6, 135);
			this->lenta_pos->Name = L"lenta_pos";
			this->lenta_pos->Size = System::Drawing::Size(90, 20);
			this->lenta_pos->TabIndex = 100;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Çàäàòü ëåíòó";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Òåêóùàÿ ïîçèöèÿ";
			// 
			// richTextBox1
			// 
			this->richTextBox1->AcceptsTab = true;
			this->richTextBox1->DetectUrls = false;
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 87);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(551, 334);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->WordWrap = false;
			// 
			// pic
			// 
			this->pic->Location = System::Drawing::Point(0, 13);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(671, 50);
			this->pic->TabIndex = 0;
			this->pic->TabStop = false;
			// 
			// îòğàáîòàòüÊîäToolStripMenuItem
			// 
			this->îòğàáîòàòüÊîäToolStripMenuItem->Name = L"îòğàáîòàòüÊîäToolStripMenuItem";
			this->îòğàáîòàòüÊîäToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->îòğàáîòàòüÊîäToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->îòğàáîòàòüÊîäToolStripMenuItem->Text = L"Îòğàáîòàòü êîä";
			// 
			// ïîÒàéìåğóToolStripMenuItem
			// 
			this->ïîÒàéìåğóToolStripMenuItem->Name = L"ïîÒàéìåğóToolStripMenuItem";
			this->ïîÒàéìåğóToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F5));
			this->ïîÒàéìåğóToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->ïîÒàéìåğóToolStripMenuItem->Text = L"Ïî òàéìåğó";
			// 
			// ïîØàãàìToolStripMenuItem
			// 
			this->ïîØàãàìToolStripMenuItem->Name = L"ïîØàãàìToolStripMenuItem";
			this->ïîØàãàìToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F10;
			this->ïîØàãàìToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->ïîØàãàìToolStripMenuItem->Text = L"Ïî øàãàì";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(671, 421);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"turing 2.0";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_lenth))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lenta_pos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		///<íà÷àëî êîäà>








		///<êîíåö êîäà>
};
}

