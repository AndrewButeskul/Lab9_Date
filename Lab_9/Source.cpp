#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;

struct Mystruct
{
	string login;
	int data_online[3];
	int begin_time_online[3];
	int time_end[3];
	int accept_information;
	int sent_information;
};

void Input(vector<Mystruct>& user, int n)
{
	system("cls");	
	for (size_t i = 0; i < n; i++)
	{
		cout << "Ваш логин:  ";
		cin >> user[i].login;
		cout << endl;

		cout << "Введите дату выхода в онлайн (через пробел д/м/год) - ";
		for (size_t j = 0; j < 3; j++)
		{
			cin >> user[i].data_online[j];
		}
		cout << endl;
		cout << "Введите время начало сеанса: (через пробел ч/м/с) -  ";
		for (size_t j = 0; j < 3; j++)
		{
			cin >> user[i].begin_time_online[j];
		}
		cout << endl;
		cout << "Введите время окончания сеанса: (через пробел ч/м/с) - ";
		for (size_t j = 0; j < 3; j++)
		{
			cin >> user[i].time_end[j];
		}
		cout << endl;
	}
}

void Print(vector<Mystruct>& user, int n)
{
	system("cls");
	for (size_t i = 0; i < n; i++)
	{
		cout << "Ваш Логин:" << user[i].login << endl;

		cout << "Дата выхода в онлайн: ";
		for (size_t j = 0; j < 3; j++)
		{
			 cout << user[i].data_online[j] << "/ ";
		}
		cout << endl;
		cout << "Dремя начало сеанса: ";
		for (size_t j = 0; j < 3; j++)
		{
			cout << user[i].begin_time_online[j] << ":";
		}
		cout << endl;
		cout << "Время окончания сеанса: ";
		for (size_t j = 0; j < 3; j++)
		{
			cout << user[i].time_end[j] << ":";
		}
		cout << endl << endl;
	}
	system("pause");
}

void Out(vector<Mystruct>& user, int n, ofstream &out)
{
	out.open("Data.txt");
	if (!out.is_open())
		cout << "Error open!\n";
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			out << user[i].login << endl;

			for (size_t j = 0; j < 3; j++)
			{
				out << user[i].data_online[j] << " ";
			}
			out << endl;
			for (size_t j = 0; j < 3; j++)
			{
				out << user[i].begin_time_online[j] << " ";
			}
			out << endl;
			for (size_t j = 0; j < 3; j++)
			{
				out << user[i].time_end[j] << " ";
			}
			out << endl << endl;
		}
	}
	cout << "Данные успешно сохранены в файл" << endl;
	system("pause");
}

void Fin(vector<Mystruct>& user, int n, ifstream &fin)
{	
	fin.open("Data.txt");
	if (!fin.is_open())
		cout << "Error open!\n";
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			fin >> user[i].login;
			for (size_t j = 0; j < 3; j++)
			{
				fin >> user[i].data_online[j];
			}
			for (size_t j = 0; j < 3; j++)
			{
				fin >> user[i].begin_time_online[j];
			}
			for (size_t j = 0; j < 3; j++)
			{
				fin >> user[i].time_end[j];
			}
		}
		cout << "Данные успешно импортированы\n";
	}
	system("pause");
}

void Online_amount(vector<Mystruct>& user, int n)
{
	vector <int> index;
	bool find = false;
	int month, amount_online = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (user[i].data_online[3] == 2018)
			index.push_back(i);
	}

	cout << "Введите номер месяца: ";
	cin >> month;
	for (size_t i = 0; i < index.size(); i++)
	{
		if (user[i].data_online[2] == month)
		{
			amount_online++;
			find = true;
		}
	}
	if (find)
		cout << endl << "Количество сеансов - " << amount_online << endl;
	else
		cout << endl << "Не найдено пользователей" << endl;
	system("pause");
}

void Exchange(vector<Mystruct>& user, int n, vector<int>& time_online)
{
	for (size_t i = 0; i < n; i++)
	{
		time_online[i] = (user[i].time_end[1] * 3600 + user[i].time_end[2] * 60 + user[i].time_end[3]) -
			(user[i].begin_time_online[1] * 3600 + user[i].begin_time_online[2] * 60 + user[i].begin_time_online[3]);
	}
}

void Max_online(vector<Mystruct>& user, int n, vector<int>& time_online)
{
	int data[3];
	bool find = false;
	vector<int> index;
	vector<int> time;
	int max_time, index_max;
	Exchange(user, n, time_online);
	cout << "Введите дату (через пробел) - ";
	for (size_t i = 0; i < 3; i++)
	{
		cin >> data[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		if (user[i].data_online[1] == data[1] && user[i].data_online[2] == data[2] && user[i].data_online[3] == data[3])
		{
			index.push_back(i);
			time.push_back(time_online[i]);
			find = true;
		}
	}
	if (find)
	{
		max_time = time[0];
		for (size_t i = 0; i < index.size(); i++)
		{
			if (time[i] > max_time)
			{
				max_time = time[i];
				index_max = i;
			}
		}
		cout << endl << "Логин: " << user[index_max].login << endl;
		cout << endl << "Максимальное время сеанса - " << max_time << "cекунд\n";
	}
	else
		cout << endl << "Не найдено пользователей" << endl;
	system("pause");
}

void Menu(vector<Mystruct>& user, int n, ofstream &out, ifstream &fin)
{
    link:
	system("cls");
	int selection = 0;
	cout << "Выберете раздел:\n" <<
		"1. Посмотреть данные о пользователях.\n" <<
		"2. Записать пользователей в файл.\n" <<
		"3. Импортировать данные.\n" <<
		"4. Количество сеансов выхода в онлайн в прошлом году.\n" <<
		"5. Максимальная длительность сеанса.\n" <<
		"6. Выход.\n";
	cin >> selection;
	switch (selection)
	{
	case 1:
		Print(user, n);
		goto link;
		break;
	case 2:
		Out(user, n, out);
		goto link;
		break;
	case 3:
		Fin(user, n, fin);
		goto link;
		break;
	case 4:
		Online_amount(user, n);
		goto link;
		break;
	case 5:
		break;
	case 6:
		exit(0);
		break;
	default:
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	ofstream out;
	ifstream fin;
	int n, selection = 0;
	cout << "Введите количество пользователей:" << endl;
	cin >> n;
	vector<Mystruct> user(n);
	vector<int> time_online(n);


	cout << "Вы хотите добавить заполнить или импортировать готовые данные? ( 1 - Заполнить | 2 - Импортировать)\n";
	cin >> selection;

	switch (selection)
	{
	case 1: 		
		Input(user, n);
		break;
	case 2:
		Menu(user, n, out, fin);
		break;
	default:
		exit(0);
		break;
	}

	system("pause");
	return 0;
}