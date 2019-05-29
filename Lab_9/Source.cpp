#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;

struct Mystruct
{
	string login;
	char data_online;
	clock_t time_online;
	clock_t time_end;
	int accept_information;
	int sent_information;
};

/*void Input(vector<Mystruct>& user, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "Enter your login:  ";
		cin >> user[i].login;
		cout << endl;
		cout << "Enter data online:  ";
		cin >> user[i].data_online;
		cout << endl;
		cout << "Enter time  start online:  ";
		cin >> user[i].time_online;
		cout << endl;
		cout << "Enter time end online:  ";
		cin >> user[i].time_end;
		cout << endl;
		

	}
}*/

int main()
{
	/*int n;
	cout << "Enter amount users:" << endl;
	cin >> n;
	vector<Mystruct> user(n);*/
	Mystruct user;

	cout << "Enter your login:  ";
	cin >> user.login;
	cout << endl;
	cout << "Enter data online:  ";
	cin >> user.data_online;
	cout << endl;
	cout << "Enter time  start online:  ";
	cin >> user.time_online;
	cout << endl;
	cout << "Enter time end online:  ";
	cin >> user.time_end;
	cout << endl;

	system("pause");
	return 0;
}