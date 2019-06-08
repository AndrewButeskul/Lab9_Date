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
		cout << "��� �����:  ";
		cin >> user[i].login;
		cout << endl;

		cout << "������� ���� ������ � ������ (����� ������ �/�/���) - ";
		for (size_t j = 0; j < 3; j++)
		{
			cin >> user[i].data_online[j];
		}
		cout << endl;
		cout << "������� ����� ������ ������: (����� ������ �/�/�) -  ";
		for (size_t j = 0; j < 3; j++)
		{
			cin >> user[i].begin_time_online[j];
		}
		cout << endl;
		cout << "������� ����� ��������� ������: (����� ������ �/�/�) - ";
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
		cout << "��� �����:" << user[i].login << endl;

		cout << "���� ������ � ������: ";
		for (size_t j = 0; j < 3; j++)
		{
			 cout << user[i].data_online[j] << "/ ";
		}
		cout << endl;
		cout << "D���� ������ ������: ";
		for (size_t j = 0; j < 3; j++)
		{
			cout << user[i].begin_time_online[j] << ":";
		}
		cout << endl;
		cout << "����� ��������� ������: ";
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
	cout << "������ ������� ��������� � ����" << endl;
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
		cout << "������ ������� �������������\n";
	}
	system("pause");
}

void Menu(vector<Mystruct>& user, int n, ofstream &out, ifstream &fin)
{
    link:
	system("cls");
	int selection = 0;
	cout << "�������� ������:\n" <<
		"1. ���������� ������ � �������������.\n" <<
		"2. �������� ������������� � ����.\n" <<
		"3. ������������� ������.\n" <<
		"4. ���������� ������� ������ � ������ � ������� ����.\n" <<
		"5. ������������ ������������ ������.\n" <<
		"6. �����.\n";
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
	cout << "������� ���������� �������������:" << endl;
	cin >> n;
	vector<Mystruct> user(n);

	cout << "�� ������ �������� ��������� ��� ������������� ������� ������? ( 1 - ��������� | 2 - �������������)\n";
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