#include <iostream>
#include <conio>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>
#include <queue>
#include <fstream>
using namespace std;

queue<int> myq;

struct info	//structure that stores the information about the clients
{
	int id;
	char name[25];
	int age;
	char place[25];
}
nu[10];

void ACD(info[], int);

void showq(queue<int> myq)
{
	queue<int> g = myq;
	while (!g.empty())
	{
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}

void ACD(info nu[10], int n)
{
	//cout<<nu.id<<endl;
	int i = 0;
	//cout<<n;
	for (i = 0; i < n; i++)
		myq.push(nu[i].id);
	showq(myq);
}

int n;
void Register()	//basic function to get the details of the client
{
	int i;
	cout << "Enter the number of Clients:";
	cin >> n;

	for (i = 0; i < n; i++)	//to take the details
	{

		cout << "\nKindly Enter your Details " << " USER" << i + 1;

		cout << "\n\tEnter your ID : ";
		cin >> nu[i].id;

		cout << "\n\tEnter your Name : ";
		cin >> nu[i].name;

		cout << "\n\tEnter your Age : ";
		cin >> nu[i].age;

		cout << "\n\tEnter your place : ";
		cin >> nu[i].place;
	}
}

void display()
{
	system("cls");
	int i;
	cout << "\nDetails of New Users:";
	cout << "\n" << "\t" << "NAME" << "\t" <<
		"AGE" << "\t" << "PLACE" << "\t" << "ID";
	for (i = 0; i < 3; i++)
		cout << "\n" << "\t" << nu[i].name << "\t" <<
		nu[i].age << "\t" << nu[i].place << "\t" << nu[i].id;
}

void Virtual() {}

void activity_selection(int start[], int end[], int n, int id[])
{
	cout << "\nThe Employee ID of the employee selected are: ";
	cout << endl << id[0];
	int j, i = 0;
	for (j = 1; j < n; j++)
		if (start[j] >= end[i])
		{
			cout << " " << id[j];
			i = j;
		}

	cout << "\n\nThese Employees can work without their schedules clashing!!";
	getch();
	system("cls");
}

void avoidclashing()
{
	int n, i;
	system("cls");
	cout << "\nThis is an advanced mechanism to avoid clashing between multiple employees during working hours:\n";
	cout << "\n\nEnter the number available call center employees: ";
	cin >> n;
	int start[n], end[n], id[n];
	cout << "\n\nKindly enter the starting and ending shift time of the employees(where the ending time is sorted ascending)\n";
	cout << "Please enter the Employee ID,start time and end time simultaneously: \n";
	//here sorted input is taken for simplicity
	for (i = 0; i < n; i++)
		cin >> id[i] >> start[i] >> end[i];
	activity_selection(start, end, n, id);
}

void feedback()
{
	system("cls");
	fstream file;
	char arr[60];

	file.open("comp.txt", ios::out);

	if (!file)
	{
		cout << "SERVOR ERROR!!!" << endl;
	}

	cout << "Please Enter your feedback (WORSE/BAD/AVERAGE/GOOD/EXCELLENT):" << endl;
	cin >> arr;
	file << arr;

	file.close();

	file.open("comp.txt", ios:: in);

	if (!file)
	{
		cout << "SERVOR ERROR!!!" << endl;
	}
	int a;
	cout << "Do you wish to see your feedback?(1/0): ";
	cin >> a;
	if (a == 1)
	{
		char ch;

		cout << "Your Feedback: \n";

		while (!file.eof())
		{
			file >> ch;
			cout << ch;
		}

		file.close();
	}
	else
		cout << "\n\nThank you\n\n";
	cout << "\n\nThank You,We will get back to you after clarifying the issue:\n\n";

}
int main()
{
	system("color 0a");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease wait while loading\n\n";
	char a = 177, b = 219;
	cout << "\t\t\t\t\t";
	for (int i = 0; i <= 23; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t\t";
	for (int i = 0; i <= 23; i++)
	{
		cout << b;
		for (int j = 0; j <= 1e8; j++);
	}

	system("cls");

	cout << "\n\n\n\n\n\n\t\tWelcome to Automatic Call Distributor\n\n\t\tYour one stop Destination for all Call Related Issues";
	cout << "\n\n\n\n\n\n\t\tKindly dial the numbers on your keypad to select your choices(Press any number)";
	getch();
	system("cls");

	int c, num, i;
	system("cls");
	while (1)
	{
		cout << "\n1.Register\n";
		cout << "2.Speak to Our Representatives\n";
		cout << "3.File Feedback\n";
		cout << "4.Exit\n";
		cout << "\n\n\n\t\t\tThe following are administrator privilege:\n";
		cout << "\t\t\t\t\t5.Employee Schedule Clashing \n";
		cout << "\t\t\t\t\t6.Display the Users Details";
		cout << "\nYour choice :";
		cin >> c;
		switch (c)
		{
			case 1:
				Register();
				break;

			case 2:
				ACD(nu, n);
				break;

			case 3:
				feedback();
				break;

			case 4:
				exit(0);

			case 5:
				avoidclashing();
				break;

			case 6:
				display();
				break;
		}
	}

	return 0;
}