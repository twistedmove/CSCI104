#include <iostream>
#include <cstdlib>
#include <string>
#include "linklist.h"
#include "wall.h"
#include "wallpost.h"
#include "user.h"
#include "userlist.h"
#include <fstream>
#include <algorithm>
using namespace std;

string fixString(std::string newusername){
	string s = newusername;
	// remove whitespace
	for (unsigned int i=0; i < s.length(); i++){
//		cout << s[i] << endl;
		if (s[i] == ' '){
			s.erase(i,1);
		}
	}
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

void friendMenu(string newusername, string username){

	cout << "You are " << username << endl;
	cout << "You are on " << newusername << "'s page." << endl;
	cout << endl;
	cout << "*------------------------------------*" << endl;
	cout << "| 1. asdf                            |" << endl;
	cout << "| 2. adsff                           |" << endl;
	cout << "| 3. adsf                            |" << endl;
	cout << "*------------------------------------*" << endl;
}


void menu(){
			cout << "             ConnectMe v2.0           " << endl;
			cout << "*------------------------------------*" << endl;
			cout << "| 1. Login as a user.                |" << endl;
			cout << "| 2. Create a new user.              |" << endl;
			cout << "| 3. Quit the program                |" << endl;
			cout << "*------------------------------------*" << endl;
}

void usermenu(){
			cout << "             User Menu v2.0           " << endl;
			cout << "*------------------------------------*" << endl;
			cout << "|             WALLPOSTS              |" << endl;
			cout << "| 1. Display your wall posts.        |" << endl;
			cout << "| 2. Create a status update.         |" << endl;
			cout << "| 3. Delete a wall post.             |" << endl;
			cout << "|                                    |" << endl;
			cout << "|         PERSONAL SETTINGS          |" << endl;
			cout << "| 4. Edit personal information.      |" << endl;
			cout << "| 5. Display personal information.   |" << endl;
			cout << "|                                    |" << endl;
			cout << "|              FRIENDS               |" << endl;
			cout << "| 6. Search for user.                |" << endl;
			cout << "| 7. Friend a user.                  |" << endl;
			cout << "| 8. Display all friends.            |" << endl;
			cout << "| 9. Defriend a user.                |" << endl;
			cout << "| 10. See pending friend requests.   |" << endl;
			cout << "|                                    |" << endl;
			cout << "| 11. Log out.                       |" << endl;
			cout << "*------------------------------------*" << endl;
}


int main(){
	int selection = 0;
	int userselection = 0;
	std::string username;
	UserList *UserListDatabase = new UserList;

		UserListDatabase->importUserDatabase();
		UserListDatabase->completeList();

		cout << "         ConnectMe v2.0          " << endl;
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
									//cout << "Please enter your password." << endl;
									if (currentUser != NULL){
									cout << "Welcome back " << username << "!" << endl;
									cout << endl;

									usermenu();

									while (userselection !=11){
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
												char usernamesearch[256];
												cout << "Please enter a user to search." << endl;
												cin.getline (usernamesearch, 256);
												string newusername;
												newusername = fixString(usernamesearch);

												// destructor doesn't work here properly in findUser()
												bool searchUser = UserListDatabase->findUser(usernamesearch, currentUser);
												bool isUserFriend = UserListDatabase->checkifFriend(newusername, username);

												// if the user is true and is your friend then prompt friend menu
												if (isUserFriend == true){
													friendMenu(newusername, username);
												}
												if (searchUser == true){
													cout << "User(s) exists." << endl;
												}
												else{
													cout << "User(s) does not exist." << endl;
												}
												cout << endl;
												usermenu();
												break;
											}
											case 7:
											{
												string friendname;
												cout << "Please enter the name of the user you'd like to add as a friend." << endl;
												cin >> friendname;
												User* friendUser = UserListDatabase->checkUser(friendname);
												bool checkUser = UserListDatabase->validUser(friendname);
												if (checkUser == true){
													if (friendUser->getusername() == currentUser->getusername()){
														cout << "You cannot add yourself as a friend! Don't be a loner. Go out and make friends!" << endl;
													}
													else{
														currentUser->addFriend(friendUser);
														friendUser->addPendingFriend(currentUser);
														cout << "Success: Friend request added." << endl;
													}
												}
												else {
													cout << "No user exists." << endl;
												}
												break;
											}
											case 8:
											{
												currentUser->displayFriends();
												cout << endl;
												usermenu();
												break;
											}
											case 9:
											{
												string userinput;
												bool yes;

												cout << "Here are your current friends." << endl;
												currentUser->displayFriends();

												cout << "Please enter the name you would like to remove." << endl;
												cin >> userinput;

												yes = currentUser->removeFriend(userinput);
												if (yes == true){
													UserListDatabase->removeFromFriend(userinput, username);
												}
												cout << endl;
												usermenu();
												break;
											}
											case 10:
											{
												currentUser->displayPendingFriends();
												if (currentUser->pendingEmpty() == true){
													cout << "No pending friends." << endl;
													cout << endl;
												}
												else{
													currentUser->acceptFriendRequest();
													currentUser->removePendingRequest();
												}
												usermenu();

												break;
											}
											case 11:
											{
												UserListDatabase->exportUserDatabase();
												//cout << "> Database exported." << endl << endl;
												cout << ">> You have successfully been logged out." << endl;
												cout << endl;
												main();
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
										tempUser->setusername(name);
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
									UserListDatabase->exportUserDatabase();
									cout << "* Database has been exported successfully *" << endl;
									cout << "*-----------------------------------------*" << endl;
									cout << "| Program has been exited successfully.   |" << endl;
									cout << "*-----------------------------------------*" << endl;
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
