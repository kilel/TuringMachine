#include "StdAfx.h"
#include "MT.h"

MT::MT(array<String^>^t, String^n): code(t),name(n)
{
	if(!machine_list)
		create_stat_data();
	create_data();
	machine_num = machine_list->Length;
	checked_ways->Resize(checked_ways, checked_ways->Length+1);	//добавили в просмотренные
	checked_ways[checked_ways->Length - 1] = n;
	//com_to_machine[com->Length-1] = checked_ways->Length - 1;	//зачем мне это?

	machine_list->Resize(machine_list, checked_ways->Length);
	machine_list[machine_num] = this;
}
MT::~MT()
{
	empty();
	for(int i = 0; i < code->Length; ++i)
		delete code[i];
	if(code)
		delete code;
	if(checked_ways)
	{
		for(int i = 0; i < checked_ways->Length; i++)
			if(checked_ways[i] == name)
			{
				checked_ways[i] = "";
				break;
			}
	}
	if(name)
		delete name;
	
}
void MT::clear()
{//delete all machines
	if(machine_list)
	{
		for(int i = 0; i < machine_list->Length; ++i)
			delete machine_list[i];
		delete machine_list;
	}
	if(checked_ways)
		delete checked_ways;
	if(stack)
		delete stack;
	
}
void MT::empty()
{//delete сurrent machine data
	if(com)
		delete com;
	if(labels)
		delete labels;
	if(foundlabels)
		delete foundlabels;
	if(com_to_machine)
		delete com_to_machine;
	if(lab_num)
		delete lab_num;
	if(errors)
		delete errors;
}
void MT::create_data()
{
	if(!trim_chars)
	{
		trim_chars = gcnew array<wchar_t>(2);
		trim_chars[0] = 32;
		trim_chars[1] = L'\t';
	}
	str_num = 0;
	text_pos = 0;
	errors = "";
	labels = gcnew array<String^>(0);
	foundlabels = gcnew array<String^>(0);
	lab_num = gcnew array<Point>(0);
	com_to_machine = gcnew array<int>(0);
	com = gcnew array<String^>(5);
	com[0] = L"goto";
	com[1] = L"if";
	com[2] = L"s";
	com[3] = L"l";
	com[4] = L"r";
}
void MT::create_stat_data()
{
	machine_list = gcnew array<MT^>(0);
	checked_ways = gcnew array<String^>(0);
	stack = gcnew array<int>(1);
	stack[0] = 0;
}
void MT::an_def(String^tmp)
{//check def МТ. string format #NAME FULL_WAY  or #NAME ~REL_WAY
	int c;
	tmp = tmp->Substring(1)->Trim(trim_chars);//delete first # + trimming
	if(tmp->Length == 0)//error_empty 
		errors += "Ошибка 4.1, пустое определение (в машине "+ name +"), строка " + str_num + "\n";
	if(tmp[0] == '#' || tmp[0] == '&')
		errors += "Ошибка 4.2, определение машины не может начинаться с '#' и '&' (в машине "+ name +"), строка " + str_num + "\n";
	if((c = include(tmp,':',0, tmp->Length)) > 0)
		errors += "Ошибка 4.3, определение машины не может содержать ':' (в машине "+ name +"), строка " + str_num + "\n";
	c = eat_word(tmp);	// <0, если одно слово. иначе возвратит длину первого слова 	
	if(c < 0)
		errors += "Ошибка 4.04, машина по этому пути не найдена "+ tmp +" (в машине "+ name +"), строка " + str_num + "\n";
	else
	{
		String^ tt = tmp->Substring(0,c)->Trim(trim_chars);		//имя создаваемой машины
		for(int j = 0; j < com->Length; j++)		//есть ли такая машина уже?
			if(String::Compare(com[j], tt) == 0) //переопределение машины запрещено
				errors += "Ошибка 4.5: переопределение машины "+ tt +" (в машине "+ name +"), строка " + str_num + "\n";
		com->Resize(com, com->Length+1);  //добавили машину в команды
		com[com->Length-1] = tt;		
		com_to_machine->Resize(com_to_machine, com->Length);
		tmp = tmp->Substring(c)->Trim(trim_chars);	//работаем с адресом
		if(tmp[0] == '~')		//относительный, делаем абсолютным
			tmp = Directory::GetCurrentDirectory() + tmp->Substring(1);
		if(File::Exists(tmp))
		{
			for(int j = 0; j < checked_ways->Length; j++)
				if(String::Compare(checked_ways[j], tmp, 1) == 0)	//такая машина уже осмотрена/осматривается, не надо сюда заходить
				{
					com_to_machine[com->Length-1] = j;
					return;
				}
			/*checked_ways->Resize(checked_ways, checked_ways->Length+1);	//добавили в просмотренные
			checked_ways[checked_ways->Length - 1] = tmp;
			com_to_machine[com->Length-1] = checked_ways->Length - 1;

			machine_list->Resize(machine_list, checked_ways->Length);
			machine_list[machine_list->Length -1] = gcnew MT( File::ReadAllLines(tmp), tmp);*/
			errors += (gcnew MT( File::ReadAllLines(tmp), tmp))->syntax();
			//errors += machine_list[machine_list->Length -1]->syntax();//
			
		}
		else
			errors += "Ошибка 4.04, машина по этому пути не найдена "+ tt +" (в машине "+ name +"), строка " + str_num + "\n";
	}
	return;
}

void MT::an_if(String^tmp)
{//check 4 if(###?). string format if(SYMBOL) LABEL or if($VARIABLE) LABEL;
	int c;
	tmp = tmp->Substring(2)->Trim(trim_chars);	//обрежем if
	if(tmp[0] != '(')
	{
		errors += "Ошибка 5.0, нет открывающей скобки в if (в машине "+ name +"), строка " + str_num + "\n";
		return;
	}
	tmp = tmp->Substring(1)->Trim(trim_chars);
	if((c = include(tmp, L')', 0, tmp->Length) ) < 0)	//найдём ')'
	{
		errors += "Ошибка 5.1, нет закрывающей скобки в if (в машине "+ name +"), строка " + str_num + "\n";
		return;
	}
	String^ tt = tmp->Substring(0,c)->Trim(trim_chars);	//содержимое скобок
	if(eat_word(tt) > 0)
	{
		errors += "Ошибка 5.2, разрывное содержимое скобок if(...) (в машине "+ name +"), строка " + str_num + "\n";
		return;
	}
	tt = tmp->Substring(c)->Trim(trim_chars);
	if(tt->Length == 1)
	{
		errors += "Ошибка 5.3, нет метки после if(...) (в машине "+ name +"), строка " + str_num + "\n";
		
	}
	tmp = tt->Substring(1)->Trim(trim_chars);
	foundlabels->Resize(foundlabels,foundlabels->Length+1);
	foundlabels[foundlabels->Length-1] = tmp->ToLower();
	eating_worm(tmp);
	tmp = "";
	return ;	
}
void MT::an_lab(String^tmp)
{//check 4 label. string format LABEL: SOMETHING;
	int c = include(tmp, L':', 0, tmp->Length);	//find ':' in str. it exists. sure.
	String^ tt = tmp->Substring(0,c)->Trim(trim_chars);	//get LABEL from string
	eating_worm(tt);	//worm want to eat it and returns us a last part of LABEL
	for(int i = 0; i < labels->Length;i++)
		if(String::Compare(labels[i],tt) == 0)
		{
			errors += "Ошибка 5.3, повтор метки "+ tt +" (в машине "+ name +"), строка " + str_num + "\n";
			analyze(tmp->Substring(c+1)->Trim(trim_chars));
			return;
		}
	labels->Resize(labels,labels->Length+1);
	labels[labels->Length-1] = tt;
	lab_num->Resize(lab_num,lab_num->Length+1);
	lab_num[lab_num->Length-1] = Point(str_num, text_pos);
	analyze(tmp->Substring(c+1)->Trim(trim_chars));
	return ;
}
void MT::an_out(String^tmp)
{//выводит первую букву слова, следующего за ним. проверить, одно ли это слово.
	tmp = tmp->Substring(1)->Trim(trim_chars);
	eating_worm(tmp);
}
void MT::an_goto(String^tmp)
{
	tmp = tmp->Substring(5)->Trim(trim_chars);

	foundlabels->Resize(foundlabels,foundlabels->Length+1);
	foundlabels[foundlabels->Length-1] = tmp->ToLower();
	tmp = "";
	return ;	
}
void MT::analyze(String^tmp)
{
	int c;
	if(tmp->Length != 0)	//проверка спец выражений
	{
		if(tmp[0] == '#')
		{
			an_def(tmp);
			return;
		};
		if((c = include(tmp, L':', 0, tmp->Length) ) > 0)
		{
			an_lab(tmp);
			return;
		}
		if(tmp[0] == '&')
		{
			an_out(tmp);
			return;
		}
		if(tmp->Length >3)
			if(tmp->Substring(0,2) == "if")
			{
				an_if(tmp);
				return;
			};
		if(tmp->Length > 5)
			if(tmp->Substring(0,5) == "goto ")
			{
				an_goto(tmp);
				return;
			}
	}
	eating_worm(tmp);				//проверка tmp на монолитность
	if(tmp->Length == 0)//пустая команда
		return;
	c = 0;
	for(int j = 0; j < com->Length; j++)	//поиск команды среди существующих
		if(String::Compare(com[j], tmp) == 0)
		{
			c = 1;
			break;
		}
	if(!c)
		errors += "Ошибка 3, обращение к неопределённой машине "+ tmp +" (в машине "+ name +"), строка " + str_num + "\n";
	
}
String^ MT::syntax()
{
	empty();
	create_data();
	int a=0,b=0,c=0;
	for(str_num = 0; str_num < code->Length; str_num++)
	{
		a=0;b=0;c=code[str_num]->Length;
		while((b = include(code[str_num],L';', a, c))>0)
		{
			analyze(code[str_num]->Substring(a, b-a)->Trim(trim_chars));
			a = b+1;
		}
		if(code[str_num]->Trim(trim_chars)->Length>0)
			if(code[str_num]->Trim(trim_chars)[code[str_num]->Trim(trim_chars)->Length-1] != L';')
				errors += "Ошибка WTF?!, нет \';\' в конце строки (в машине "+ name +"), строка " + str_num + "\n";
	}
	for(int i = 0; i < foundlabels->Length; ++i)
	{
		c = 0;
		for(int j = 0; j < labels->Length; ++j)
			if(!String::Compare(foundlabels[i], labels[j]))
			{
				c = 1;
				break;
			}
		if(!c)
			errors += "Ошибка WTF?!, использование неопределённой метки "+ foundlabels[i] +" (в машине "+ name +"), строка " + str_num + "\n";
	}
	return errors;
}

int MT::include(String^s, wchar_t c, int start_pos, int end_pos)
{
	for(int i = start_pos; i < end_pos; i++)
		if(i > s->Length)
			return (-1);
		else if(s[i] == c)
			return i;
	return (-1);
}
int MT::eat_word(String^ s)
{
	int a;
	for( int k = 0; k < 2; k++)
		if((a = include(s,trim_chars[k],0,s->Length)) > 0)
			return a;
	return -1;
}
String^ MT::eating_worm(String^s)
{
	int a;
	do
	{
		a = eat_word(s);
		if(a > 0)
		{
			errors += "Ошибка 404(;?), машина "+ name +", строка " + str_num + "\n";
			s = s->Substring(a)->Trim(trim_chars);
		} 
	}while(a > 0);
	return s;
}
void MT::start_machine()
{
	str_num = 0;
	text_pos = 0;
}
String^ MT::next_word()
{
	int b = this->text_pos;
	if(code->Length == 0)
		return "s";
	int a = include(code[str_num],L';', text_pos, code[str_num]->Length );
	while(a < 0 && str_num < code->Length - 1)
	{
		text_pos = 0;
		b = 0;
		str_num++;
		a = include(code[str_num],L';', text_pos, code[str_num]->Length );
	}
	if( str_num > code->Length - 1 )
		return "s";
	if(a < 0)
	{
		//MessageBox::Show("error next_word(). please check");
		return "s";
	}
	text_pos = a+1;
	return code[str_num]->Substring(b, a-b)->Trim(trim_chars);
}
void MT::change_label(String^ tmp)
{
	for(int i = 0; i < labels->Length;  i++)
		if(!tmp->Compare(tmp, labels[i]))
		{
			str_num = lab_num[i].X;
			text_pos = lab_num[i].Y;
			break;
		}
}
String^ MT::next_step(wchar_t current)				////дописать
{
	String ^tmp, ^expr;
	while(machine_num != stack[stack->Length-1])
	{
		tmp = machine_list[stack[stack->Length-1]]->next_step(current);
		if(tmp[0] == 's')
		{
			stack->Resize(stack,stack->Length-1);
			if(stack->Length == 0)
				return tmp;
			else continue;
		}
		else
			return tmp;
	}
	int a = 0;
	tmp = "";
	while(tmp->Length == 0)
	{
		tmp = next_word();
		a = include(tmp, L':', 0, tmp->Length );
		while(a > 0)
		{
			tmp = tmp->Substring(a+1)->Trim(trim_chars);
			a = include(tmp, L':', 0, tmp->Length );
		}
	}
	if(tmp[0] == '#')
		return next_step(current);
	if(tmp->Length == 1)
		if(tmp[0] == 's' || tmp[0] == 'l' || tmp[0] == 'r')
			return tmp;
	if(tmp[0] == '&')
		return tmp;
	if(tmp->Length > 5)
		if(!tmp->Compare(tmp->Substring(0,4),"goto"))
		{
			tmp = tmp->Substring(5)->Trim(trim_chars);
			change_label(tmp);
			return next_step(current);		///прошли по метке
		}
		else if(!tmp->Compare(tmp->Substring(0,2),"if"))
		{
			tmp = tmp->Substring(2)->Trim(trim_chars);
			tmp = tmp->Substring(1)->Trim(trim_chars);
			a = include(tmp,L')', 0, tmp->Length);
			expr = tmp->Substring(0,a)->Trim(trim_chars);
			tmp = tmp->Substring(a+1)->Trim(trim_chars);
			if(expr->Length>1)
			{
				if(expr[0] == L'!' && expr[1] == current)
					next_step(current);
				else if(expr[0] == L'!')
				{
					change_label(tmp);
					return next_step(current);
				}
				//если никуда не зашёл, то не было ! в начале строки. идём в обычное условие.
			}
			if( expr->Length == 0)
			{
				change_label(tmp);
				return next_step(current);
			}
			else if( expr[0] == current )
			{
				change_label(tmp);
				return next_step(current);
			}

		}
		for(int i = 5; i < com->Length; i++)
		{
			if(com[i] == tmp)
			{
				stack->Resize(stack,stack->Length+1);
				stack[stack->Length-1] = i-4;
				machine_list[stack[stack->Length-1]]->start_machine();
				return next_step(current);
			}
		}
	///
	return tmp;
	///
	//return "";
}