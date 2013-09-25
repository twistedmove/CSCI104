#include <iostream>
#include <cstdlib>
#include <string>
#include "linklist.h"
#include "wall.h"
#include "wallpost.h"
#include "user.h"
#include "userlist.h"
using namespace std;

int main(){

	int selection = 0;
	std::string username;
	UserList *UserListDatabase = new UserList;


		cout << "         ConnectMe v1.0          " << endl;
		cout << "*-------------------------------*" << endl;
		cout << "| 1. Login as a user.           |" << endl;
		cout << "| 2. Create a new user.         |" << endl;
		cout << "| 3. Quit the program           |" << endl;
		cout << "*-------------------------------*" << endl;

		while (selection != 3)
					{
						cout << "Selection: ";
						cin >> selection;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							cout << "Invalid Selection." << endl;
							continue;
						}
						cin.clear();
						cin.ignore(1024,'\n');

						cout << endl;
						switch (selection)
						{
						// Login function
							case 1:
								{
									cout << "Please enter your username." << endl;
									cout << "Username: ";
									cin >> username;
									break;
								}
						// Create user function
							case 2:
								{
									User *tempUser = new User();
									UserListDatabase->addUser(*tempUser);

									break;
								}
						// This quits the program
							case 3:
								{
									cout << "              *---------------------------------------*" << endl;
									cout << "              | Program has been exited successfully. |" << endl;
									cout << "              *---------------------------------------*" << endl;
									cout << endl;
								break;
								}
						// Error output
							default:
								{
									cout << "              *--------------------------------*" << endl;
									cout << "              |        Invalid choice.         |" << endl;
									cout << "              *--------------------------------*" << endl;
									cout << endl;
								break;
								}
						}
					}
				return selection;


	return 0;
}
