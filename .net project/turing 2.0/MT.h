#pragma once
#include <vector>
#include <string>

	using namespace System;
	using namespace std;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
ref class MT
{
private:
	static array<int>^ stack;
	array<String^>^com,  ^labels, ^foundlabels ;
	static array<String^> ^checked_ways;
	static array<MT^> ^machine_list;
	array<int> ^com_to_machine;		//инъективное отображение com |-> machines
	array<Point> ^lab_num;				//координаты метки.
	static array<wchar_t> ^trim_chars;
	array<String^>^code;
	int text_pos;
	int str_num;
	String^ name;
	int machine_num;
	String^errors;

	void empty();
	int include(String^s, wchar_t c, int start_pos, int end_pos);
	int eat_word(String^ s);
	String^ eating_worm(String^s);
	void create_data();
	void create_stat_data();
	void an_def(String^s);
	void an_if(String^s);
	void an_lab(String^s);
	void an_out(String^s);
	void an_goto(String^s);
	void analyze(String^s);
	String^ next_word();
	void change_label(String^tmp);
public:

	MT(array<String^>^t, String^n);
	~MT();
	static void clear() ;
	String^ syntax();
	void start_machine();
	String^ next_step(wchar_t current);
};
