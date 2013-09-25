#include <iostream>
#include <cstdlib>
#include <string>
#include "linklist.h"
#include "wall.h"
#include "wallpost.h"
#include "user.h"
#include "userlist.h"
using namespace std;

void menu(){
			cout << "             ConnectMe v1.0           " << endl;
			cout << "*------------------------------------*" << endl;
			cout << "| 1. Login as a user.                |" << endl;
			cout << "| 2. Create a new user.              |" << endl;
			cout << "| 3. Quit the program                |" << endl;
			cout << "*------------------------------------*" << endl;
}

void usermenu(){
			cout << "             User Menu v1.0           " << endl;
			cout << "*------------------------------------*" << endl;
			cout << "| 1. Display all wall posts.         |" << endl;
			cout << "| 2. Create a new wall post.         |" << endl;
			cout << "| 3. Delete a wall post.             |" << endl;
			cout << "| 4. Edit personal information.      |" << endl;
			cout << "| 5. Display personal information.   |" << endl;
			cout << "| 6. Log out.                        |" << endl;
			cout << "*------------------------------------*" << endl;
}


int main(){

	int selection = 0;
	int userselection = 0;
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
									User* currentUser = UserListDatabase->checkUser(username);
									if (currentUser != NULL){
									cout << "Welcome back " << username << "!" << endl;

									usermenu();

									while (userselection !=6){
										cout << "Selection: ";
										cin >> userselection;
										if (cin.fail()){
											cin.clear();
											cin.ignore(1024, '\n');
											cout << "Invalid Selection." << endl;
											continue;
										}
										cin.clear();
										cin.ignore(1024,'\n');

										cout << endl;
										switch (userselection){
											case 1: // display all wall post
											{
												currentUser->getWall()->printWallPosts();
												cout << endl;
												usermenu();
												break;
											}
											case 2: // create a new wall post
											{
												string newmessage;
												char messagepost[512];
												cout << "Please enter a status update to your wall." << endl;
												cin.getline(messagepost,512);
												newmessage = messagepost;
												currentUser->addWallPost(newmessage);
												cout << endl;
												usermenu();
												break;
											}
											case 3:	// delete a wallpost
											{
												int id;
												cout << "Please enter the post ID number you wish to remove." << endl;
												cin >> id;
												currentUser->removeWallPost(id);
												break;
											}
											case 4: // edit personal information
											{
												currentUser->editInformation();
												cout << endl;
												usermenu();
												break;
											}
											case 5: // display personal information
											{
												currentUser->printInformation();
												cout << endl;
												usermenu();
												break;
											}
											case 6:
											{
												cout << "You have been logged out." << endl;
												cout << "Program has exited." << endl;
												break;
											}
											default:
											{
												cout << " *--------------------------------*" << endl;
												cout << " |        Invalid choice.         |" << endl;
												cout << " *--------------------------------*" << endl;
												cout << endl;
												break;
											}
										} // end switch
									} // end while
									return userselection;
								} // if statement
									else {
										cout << "*-----------------------------------------*" << endl;
										cout << "| Error: User does not exist in database. |" << endl;
										cout << "*-----------------------------------------*" << endl;
									}
									break;
								} // end case 1
						// Create user function
							case 2:
								{
									string name;
									cout << "Please enter a username." << endl;
									cin >> name;
									User* existingUser = UserListDatabase->checkUser(name);
									if (existingUser == NULL){
										User *tempUser = new User();
										tempUser->setUsername(name);
										UserListDatabase->addUser(*tempUser);
									}
									else{
										cout << endl;
										cout << "! User exists already. Please choose a different username. !" << endl;
									}
									cout << endl;
									menu();
									break;
								}
						// This quits the program
							case 3:
								{
									cout << "*---------------------------------------*" << endl;
									cout << "| Program has been exited successfully. |" << endl;
									cout << "*---------------------------------------*" << endl;
									cout << endl;
								break;
								}
						// Error output
							default:
								{
									cout << "*--------------------------------*" << endl;
									cout << "|        Invalid choice.         |" << endl;
									cout << "*--------------------------------*" << endl;
									cout << endl;
								break;
								}
						}
					}
				return selection;


	return 0;
}
