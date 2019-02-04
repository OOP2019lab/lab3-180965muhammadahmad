// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include <string.h>
#include <iostream>
#include "githubuser.h"
using namespace std;

// this function deep copy all the data from orrignal array to duplicate array
void backup(gitHubUser *originalArry, gitHubUser *&backupArry, int userCount)
{
	backupArry = new gitHubUser[userCount];
	for (int i = 0; i<userCount; i++)
	{
		backupArry[i].firstName = originalArry[i].firstName;
		backupArry[i].username = originalArry[i].username;
		backupArry[i].email = originalArry[i].email;
		backupArry[i].countfolder = originalArry[i].countfolder;
		backupArry[i].githubfolders = new string[backupArry[i].countfolder];
		for (int j = 0; j<backupArry[i].countfolder; j++)
		{
			backupArry[i].githubfolders[j] = originalArry[i].githubfolders[j];


		}
		if ((originalArry[i].institue_name != nullptr) || (originalArry[i].qualification_level != nullptr))
		{
			backupArry[i].institue_name = new string;
			backupArry[i].qualification_level = new string;

			*backupArry[i].institue_name = *originalArry[i].institue_name;
			*backupArry[i].qualification_level = *originalArry[i].qualification_level;
		}
		else
		{
			backupArry[i].institue_name = new string;
			backupArry[i].qualification_level = new string;
			backupArry[i].institue_name = nullptr;
			backupArry[i].qualification_level = nullptr;
		}
	}

}
// this function deletes 
void remove(gitHubUser &user)
{
	user.qualification_level = nullptr;
	user.institue_name = nullptr;





}

//printing the data of students
void print(gitHubUser &user)
{
	cout << "The student first name is " << user.firstName << endl;
	cout << "The student user name is " << user.username << endl;
	cout << "The student email is " << user.email << endl;
	for (int i = 0; i<user.countfolder; i++)
	{
		cout << "The folder name is " << user.githubfolders[i] << endl;

	}
	if (user.institue_name != nullptr)
	{
		cout << "The isnstitution name of " << user.firstName << " is " << *user.institue_name << endl;
		cout << "The education level of " << user.firstName << " is " << *user.qualification_level << endl;
	}


}



// this function takes the educational background of the student
void setEduBckGrnd(gitHubUser &user)
{

	user.institue_name = new string;
	user.qualification_level = new string;
	cout << user.firstName << " enter your institution name" << endl;
	cin >> *user.institue_name;
	cout << user.firstName << " enter your level of education" << endl;
	cin >> *user.qualification_level;




}
// this functions takes input from the file
void readDataFromFile(gitHubUser * &users, string filepath)
{
	ifstream in;
	in.open(filepath.c_str());
	int size;
	in >> size;
	users = new gitHubUser[size];
	for (int i = 0; i<size; i++)
	{
		in >> users[i].firstName;
		in >> users[i].username;
		in >> users[i].email;
		in >> users[i].countfolder;
		users[i].githubfolders = new string[users[i].countfolder];
		for (int j = 0; j<(users[i].countfolder); j++)
		{
			in >> users[i].githubfolders[j];
		}


	}
	in.close();



}
int main()
{
	gitHubUser *backuparray = nullptr;
	gitHubUser *classroom = nullptr;

	int check = 1;
	while (check != 0)
	{
		cout << "enter 1 for reading data from file " << endl;
		cout << "enter 2 for writing the students educayional background" << endl;
		cout << "enter 3 for printing the data readed from file" << endl;
		cout << "enter 4 for copying data to duplicate array and print it" << endl;
		cout << endl;
		cin >> check;
		if (check == 1)
		{
			readDataFromFile(classroom, "file.txt");

		}
		else if (check == 2)
		{
			int option = 0;
			for (int i = 0; i<2; i++)

			{

				cout << "enter 1 if you want to get educational backgroung of " << classroom[i].firstName << " && input 0 if you donot want the educational background" << endl;
				cin >> option;
				if (option == 1)
				{
					setEduBckGrnd(classroom[i]);

				}
				else
				{
					classroom[i].qualification_level = nullptr;
					classroom[i].institue_name = nullptr;
				}
			}
		}
		else if (check == 3)
		{
			for (int i = 0; i<2; i++)
			{
				print(classroom[i]);
				cout << endl;
			}
		}
		else if (check == 4)
		{
			//taking the size of student from file
			int stdcount;
			ifstream read;
			read.open("file.txt");
			read >> stdcount;
			read.close();
			backup(classroom, backuparray, stdcount);
			for (int i = 0; i<stdcount; i++)

			{
				print(backuparray[i]);
				cout << endl;
			}
		}
		cout << "enter 9 to continue and 0 to end the program" << endl;
		cin >> check;
	}
	// deallocation of dynamic array
	for (int i = 0; i < 2; i++)
	{
		delete[i]classroom;
		delete[i]backuparray;
	}
	classroom = nullptr;
	backuparray = nullptr;


	return 0;
}
