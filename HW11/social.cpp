#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "linklist.h"
#include "wall.h"
#include "wallpost.h"
#include "user.h"
#include "userlist.h"
#define LR(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
using namespace std;


void clearScreen(){
	cout << string( 100, '\n' );
}



bool TimeComparitor(WallPost* A, WallPost* B){
	if (A->returnTime() > B->returnTime()){
		return true;
	}
	else{
		return false;
	}
}

/*
bool CreationComparitor(WallPost* A, WallPost* B){
	if (A->returnCreation() >= B->returnCreation()){
		return true;
	}
	else{
		return false;
	}
}
*/

// constants for md5 hash
const int k[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee , 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 , 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be , 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 , 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa , 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 , 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed , 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a , 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c , 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 , 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 , 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 , 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 , 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 , 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 , 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
const int r[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};


bool addZero(string a){
    string array[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    bool exists = std::find(std::begin(array), std::end(array), a) != std::end(array);
    if (exists)
        return true;
    else
        return false;
}

string convertIntToHex(int x){
    stringstream ss;
    ss << std::dec << x;
    string result(ss.str());
 /*   if (result == "0" || result == "1" ||result == "2" ||result == "3" ||result == "4" ||result == "5" ||result == "6" ||result == "7" ||result == "8" ||result == "9"){
    	return "0"+result;
    }
    else if (addZero(result)){
        return "0"+result;
    }
*/
    return result;
}


string convertIntToString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}

int convertHexToInt(int x){
    stringstream ss;
    ss >> std::hex >> x;
    return x;
}

void convertToBit(unsigned int a, unsigned char *c){
    c[0] = (unsigned char)a;
    c[1] = (unsigned char)(a = 8);
    c[2] = (unsigned char)(a = 16);
    c[3] = (unsigned char)(a = 24);
}

unsigned int convertToInt(const unsigned char *a){
//bitwise operation
    // return if either char that isn't NULL
    return (unsigned int) a[0] | ((unsigned int) a[1] * 256) | ((unsigned int) a[2] * 65536) | ((unsigned int) a[3] * 16777216);
}

void md5(const unsigned char *initialM, unsigned int initialL, unsigned char *encrypt) {
    unsigned int hashOne;
    unsigned int hashTwo;
    unsigned int hashThree;
    unsigned int hashFour;
    unsigned char *code = NULL;
    unsigned int newLength;
    unsigned int j;
    unsigned int w[16];
    unsigned int a, b, c, d, e, f, temp;
    int i;

// state variables for md5
    hashOne = 0x67452301;
    hashTwo = 0xefcdab89;
    hashThree = 0x98badcfe;
    hashFour = 0x10325476;

    for (newLength = initialL + 1; newLength % (64) != 56; newLength++){};

    code = new unsigned char(newLength + 8);
    memcpy(code, initialM, initialL);
    code[initialL] = 0x80;
    for (j = initialL + 1; j < newLength; j++){
        code[j] = 0;
    }
    convertToBit(initialL * 8, code + newLength);
    convertToBit(initialL >> 29, code + newLength + 4);

    for(j=0; j<newLength; j += (512/8)) {
        for (i = 0; i < 16; i++){
            w[i] = convertToInt(code + j + i*4);
        }

            a = hashOne;
            b = hashTwo;
            c = hashThree;
            d = hashFour;

    //adopted from wiki pseudocode for bits
        for(i = 0; i<64; i++) {
            if (i < 16) {
                e = (b & c) | ((~b) & d);
                f = i;
            } else if (i < 32) {
                e = (d & b) | ((~d) & c);
                f = (5*i + 1) % 16;
            } else if (i < 48) {
                e = b ^ c ^ d;
                f = (3*i + 5) % 16;
            } else {
                e = c ^ (b | (~d));
                f = (7*i) % 16;
            }

            temp = d;
            d = c;
            c = b;
            b = b + LR((a + e + k[i] + w[f]), r[i]);
            a = temp;

        }
        hashOne += a;
        hashTwo += b;
        hashThree += c;
        hashFour += d;

    }
   delete code;

    convertToBit(hashOne, encrypt);
    convertToBit(hashTwo, encrypt + 4);
    convertToBit(hashThree, encrypt + 8);
    convertToBit(hashFour, encrypt + 12);
}

int getSizeFromDatabase(){
	ifstream importFile("database.txt");
	std::string junk;
	int numlines = 0;

	if (importFile.fail()){
		std::cout << "*-----------------------------*" << std::endl;
		std::cout << "| database.txt does not exist |" << std::endl;
		std::cout << "*-----------------------------*" << std::endl;
	}

	if (importFile.good()){
		std::string line;
		while (std::getline(importFile, line)){
			++numlines;
		}
	}
	return numlines;
}

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

bool is_Empty(std::ifstream& file){
    return file.peek() == std::ifstream::traits_type::eof();
}


void importHangmanWord(vector<string> &wordList){
	std::ifstream importFile("hangman.txt");
		if (importFile.fail()){
			std::cout << "<!-- hangman.txt does not exist. --!>" << std::endl;
		}
			std::string temp;

			if (!is_Empty(importFile)){
				if (importFile.good()){
					while(!importFile.eof()){
							getline(importFile, temp, '\n');
							wordList.push_back(temp);
					}
				}
			}
		importFile.close();
}


void drawMan(int a){

	if(a == 1)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
	else if(a == 2)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |    o   "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
	else if(a == 3)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |    o   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
	else if(a == 4)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |    o   "<<endl;
			cout <<"   |   /|   "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
	else if(a == 5)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |    o   "<<endl;
			cout <<"   |   /|\\  "<<endl;
			cout <<"   |        "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
	else if(a == 6)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |    o   "<<endl;
			cout <<"   |   /|\\  "<<endl;
			cout <<"   |   /    "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
	else if(a == 7)
		{
			cout << endl;
			cout <<"   *----*   "<<endl;
			cout <<"   |    |   "<<endl;
			cout <<"   |    o   "<<endl;
			cout <<"   |   /|\\  "<<endl;
			cout <<"   |   / \\  "<<endl;
			cout <<"   |        "<<endl;
			cout <<"  --------- "<<endl<<endl;
		}
}

int playHangman(vector<string> wordList){
	string stringword;
	char userchoice[40];
	char userguess[40];
	int attempts = 1;
	int selector = 0;
	int length = 0;
	int counter = 0;
	char guess;
	int points = 0;



	srand(time(NULL));
	selector = rand() % wordList.size();
	stringword = wordList[selector];
	for (int k =0; k<stringword.size(); k++){
		userchoice[k] = stringword[k];
	}
	length = stringword.size();

	for (int i=0; i<length; i++){
		userguess[i] = '-';
	}
	userguess[length] = '\0';

	while (attempts != 7){
		cout << "Guess and input a letter! Don't kill the man." << endl;
		cout << "<!------    YOU HAVE 7 ATTEMPTS!    ------>" << endl;
		cout << endl;
		drawMan(attempts);
		cout << userguess << endl;
		cout << endl;
		cin >> guess;
		guess = tolower(guess);

		for (int j=0; j<length; j++){
			if (userchoice[j] == guess){
				userguess[j] = guess;
				counter = 1;

				if(stringword == userguess){
					cout << "Winner winner chicken dinner." << endl;
					points = 1;
					return points;
				}
			}
		}

		if (counter == 0){
			cout << "You're killing Kenny!" << endl;
			attempts++;
		}

		counter = 0;
	}

	drawMan(attempts);
	// Ascii generator with minor changes to fit code: http://patorjk.com/software/taag/#p=display&f=Big&t=Type%20Something%20
	cout << "   ____  __  __  _____ _  __     ______  _    _   _  _______ _      _      ______ _____    _  ________ _   _ _   ___     __ __     ______  _    _   ____    _       _       _	 " << endl;
	cout << "  / __ \\|  \\/  |/ ____| | \\ \\   / / __ \\| |  | | | |/ /_   _| |    | |    |  ____|  __ \\  | |/ /  ____| \\ | | \\ | \\ \\   / / \\ \\   / / __ \\| |  | | |  _ \\/\\| |/\\ /\\| |/\\ /\\| |/\\ " << endl;
	cout << " | |  | | \\  / | |  __| |  \\ \\_/ / |  | | |  | | | ' /  | | | |    | |    | |__  | |  | | | ' /| |__  |  \\| |  \\| |\\ \\_/ /   \\ \\_/ / |  | | |  | | | |_) \\ ` ' / \\ ` ' / \\ ` ' / " << endl;
	cout << " | |  | | |\\/| | | |_ | |   \\   /| |  | | |  | | |  <   | | | |    | |    |  __| | |  | | |  < |  __| | . ` | . ` | \\   /     \\   /| |  | | |  | | |  _ <_     _|_     _|_     _|" << endl;
	cout << " | |__| | |  | | |__| |_|    | | | |__| | |__| | | . \\ _| |_| |____| |____| |____| |__| | | . \\| |____| |\\  | |\\  |  | |_      | | | |__| | |__| | | |_) / , . \\ / , . \\ / , . \\ " << endl;
	cout << "  \\____/|_|  |_|\\_____(_)    |_|  \\____/ \\____/  |_|\\_\\_____|______|______|______|_____/  |_|\\_\\______|_| \\_|_| \\_|  |_(_)     |_|  \\____/ \\____/  |____/\\/|_|\\/ \\/|_|\\/ \\/|_|\\/ " << endl;

	cout << endl << endl;

	cout << "REFERENCE TO SOUTH PARK, if you don't get it." << endl;
	cout << "We need our easter eggs, laughs sometimes when coding ridiculous amounts of code." << endl;
	cout << "Anyway, here's your answer....." << endl;
	cout << "ANSWER: " << stringword << endl;
	cout << endl << endl;

	return points;
}



void friendMenu(string newusername, string username){

	cout << "You are " << username << endl;
	cout << "You are on " << newusername << "'s page." << endl;
	cout << endl;
	cout << "*---------------------------------------*" << endl;
	cout << "|              WALL COMMENT             |" << endl;
	cout << "| 1. Write on friend's wall.            |" << endl;
	cout << "| 2. Delete your post on friend's wall. |" << endl;
	cout << "|                                       |" << endl;
	cout << "|            WALL POST COMMENT          |" << endl;
	cout << "| 3. Comment on friend's wallpost.      |" << endl;
	cout << "| 4. Delete your comment.               |" << endl;
	cout << "|                                       |" << endl;
	cout << "| 5. Do not click.                      |" << endl;
	cout << "| 6. Exit.                              |" << endl;
	cout << "*---------------------------------------*" << endl;
}


void menu(){
	cout << "               ConnectMe v2.0            " << endl;
	cout << "*---------------------------------------*" << endl;
	cout << "| 1. Login as a user.                   |" << endl;
	cout << "| 2. Create a new user.                 |" << endl;
	cout << "| 3. Quit the program                   |" << endl;
	cout << "*---------------------------------------*" << endl;
}

void usermenu(){
	cout << "               User Menu v2.0            " << endl;
	cout << "*----------------------------------------*" << endl;
	cout << "|                WALLPOSTS               |" << endl;
	cout << "| 1. Display your wall posts.            |" << endl;
	cout << "| 2. Create a status update.             |" << endl;
	cout << "| 3. Delete a wall post.                 |" << endl;
	cout << "|                                        |" << endl;
	cout << "|            PERSONAL SETTINGS           |" << endl;
	cout << "| 4. Edit personal information.          |" << endl;
	cout << "| 5. Display personal information.       |" << endl;
	cout << "|                                        |" << endl;
	cout << "|                 FRIENDS                |" << endl;
	cout << "| 6. Search by name. (Access Friend)     |" << endl;
	cout << "| 7. Search by username. (Access Friend) |" << endl;
	cout << "| 8. Friend a user.                      |" << endl;
	cout << "| 9. Display all friends.                |" << endl;
	cout << "| 10. Defriend a user.                   |" << endl;
	cout << "| 11. See pending friend requests.       |" << endl;
	cout << "|                                        |" << endl;
	cout << "| 12. Game Center.                       |" << endl;
	cout << "|                                        |" << endl;
	cout << "| 13. Log out.                           |" << endl;
	cout << "*----------------------------------------*" << endl;
}


int main(){
	int selection = 0;
	int userselection = 0;
	int select = 0;
	std::string username;
	std::vector<std::string> wordList;
	importHangmanWord(wordList);



//	int totsiz = getSizeFromDatabase();

	UserList *UserListDatabase = new UserList();

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
											std::string userpword;
											cout << "Please enter your username." << endl;
											cout << "Username: ";
											cin >> username;
											User* currentUser = UserListDatabase->checkUser(username);
											cout << "Please enter your password." << endl;
											cout << "Password: ";
											cin >> userpword;
											int tlength;
											unsigned char tencrypt[16];
											string tfinal;

											tlength = userpword.size();
											char *tcode = new char[userpword.size()+1];
											strcpy(tcode, userpword.c_str());
											md5((unsigned char*)tcode, tlength, tencrypt);

											for (int j = 0; j <16; j++){
												tfinal += convertIntToHex(tencrypt[j]);
											}

											bool validPass = UserListDatabase->checkPassword(tfinal, username);


											if (currentUser != NULL && validPass == false){
												cout << "Invalid Password." << endl;
											}
											else if (currentUser != NULL && validPass == true){
									//clearScreen();
												cout << "Welcome back " << username << "!" << endl;
												cout << endl;

											usermenu();

											while (userselection !=13){
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
														int userin = 0;
														cout << "Sort WallPosts by: " << endl;
														cout <<	"      [1] Original Made" << endl;
														cout << "      [2] Recent Activity" << endl;
														cin >> userin;
														if (userin > 2 || userin < 1){
															cout << "Invalid entry." << endl;
															break;
														}
														if (userin == 1){
															currentUser->getWall()->printWallPosts();
														}
														else if (userin == 2){
															currentUser->getWall()->sort(TimeComparitor);
															//cout << "?" << endl;
														}
														//cout << "?" << endl;
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
														usermenu();
														break;
													}
													case 4: // edit personal information
													{
														char tempaddress[512];
														string zpassword;
														string zaddress;
														string zemail;
														int length;
														unsigned char encrypt[16];
														string final;

														cout << "Enter your new password." << endl;
														cin >> zpassword;
														cout << "Enter your new address." << endl;
														cin.ignore();		//skips the enter
														cin.getline(tempaddress,512);
														zaddress = tempaddress;
														cout << "Enter your new email." << endl;
														cin >> zemail;

														length = zpassword.size();
														char *code = new char[zpassword.size()+1];
														strcpy(code, zpassword.c_str());
														md5((unsigned char*)code, length, encrypt);

														for (int j = 0; j <16; j++){
															final += convertIntToHex(encrypt[j]);
														}


														currentUser->editInformation(final,zaddress,zemail);


														cout << "Information List: Do not share this information." << endl;
														cout << "------------------------------------------------" << endl;
														cout << "Username: " << username << endl;
														cout << "Password: " << zpassword << endl;
														cout << "Your address is: " << currentUser->getaddress() << endl;
														cout << "Email: " << currentUser->getemail() << endl;

														delete [] code;

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
														string searchusername = usernamesearch;
														string newusername;
														newusername = fixString(usernamesearch);

														// destructor doesn't work here properly in findUser()
														bool searchUser = UserListDatabase->findUser(usernamesearch, currentUser);
														bool isUserFriend = UserListDatabase->checkifFriend(searchusername, username);

														// if the user is true and is your friend then prompt friend menu
														if (isUserFriend == true){
															friendMenu(searchusername, username);
															while(select != 6){
																cout << "Selection: ";
																cin >> select;
																if (cin.fail()){
																	cin.clear();
																	cin.ignore(1024, '\n');
																	cout << "Invalid Selection." << endl;
																	continue;
																}
																cin.clear();
																cin.ignore(1024,'\n');
																cout << endl;

																switch(select){
																	case 1:	// write on friends wall
																	{
																		char friendpost[1024];
																		std::string post;

																		UserListDatabase->displayUserWallPost(searchusername);
																		cout << endl;

																		cout << "Please enter an message for " << searchusername << "'s wall." << endl;
																		cout << "<!-- MAX OF 1024 CHARACTERS --!>" << endl;
																		//std::cin.ignore();
																		std::cin.getline(friendpost,1024);
																		post = friendpost;

																		if (post != ""){
																			UserListDatabase->postFriendWall(post, searchusername, username);
																			cout << "Success" << endl;
																		}
																		else if (post == "" || post == " "){
																			cout << "You haven't written anything!" << endl;
																			friendMenu(searchusername, username);
																			break;
																		}
																		cout << endl;
																		friendMenu(searchusername, username);
																		break;
																	}
																	case 2: // delete your post on friend's wall
																	{
																		std::string delid;
																		UserListDatabase->displayUserWallPost(searchusername);
																		cout << endl;
																		cout << "Which post would you like to delete?" << endl;
																		cout << "Please note that you can only delete posts you are author of." << endl;
																		cout << "Enter 'c' to cancel." << endl;
																		cin >> delid;

																		if (delid == "c"){
																			cout << "<!------ Action canceled. ------!>" << endl;
																		}
																		else if (delid != "c"){
																			UserListDatabase->deleteFriendPost(delid ,newusername, username);
																		}

																		cout << endl;
																		friendMenu(searchusername, username);
																		break;
																	}
																	case 3: // comment on friend's wallpost
																	{
																		std::string comid;

																		UserListDatabase->displayUserWallPost(searchusername);
																		cout << endl;
																		cout << "Which post would you like to comment on?" << endl;
																		cout << "Enter 'c' to cancel." << endl;
																		cin >> comid;
																		if (comid == "c"){
																			cout << "<!------ Action canceled. ------!>" << endl;
																		}
																		else if (comid != "c"){
																			UserListDatabase->commentFriendWallPost(comid, searchusername, username);
																		}
																		cout << endl;
																		friendMenu(searchusername, username);
																		break;
																	}
																	case 4: // delete comment on friend's wallpost
																	{
																		std::string delid;
																		std::string delidtwo;

																		UserListDatabase->displayUserWallPost(searchusername);
																		cout << endl;
																		cout << "Please select the post with the comment you want to delete." << endl;
																		cout << "Please note that you can only delete posts you are author of." << endl;
																		cout << "Enter 'c' to cancel." << endl;
																		cin >> delid;
																		if (delid == "c"){
																			cout << "<!------ Action canceled. ------!>" << endl;
																			cout << endl;
																			friendMenu(searchusername, username);
																			break;
																		}
																		cout << "Please enter the comment id which you'd like to delete." << endl;
																		cin >> delidtwo;

																		if (delid == "c" || delidtwo == "c"){
																			cout << "<!------ Action canceled. ------!>" << endl;
																		}
																		else if (delid != "c" && delidtwo != "c"){
																			UserListDatabase->deleteCommentonFriendWall(delid, delidtwo, searchusername, username);
																		}


																		cout << endl;
																		friendMenu(searchusername, username);
																		break;
																	}
																	case 5:
																	{
																		cout << "This does nothing." << endl;

																		cout << endl;
																		friendMenu(searchusername, username);
																		break;
																	}
																	case 6:
																	{

																		cout << endl;
																		friendMenu(searchusername, username);
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
																}
															}
														}
														if (searchUser == true && isUserFriend == true){
															cout << "User "<< searchusername <<" is already your friend." << endl;
														}
														else if (searchUser == true){
															cout << "User(s) exists." << endl;
														}
														else{
															cout << "User(s) does not exist." << endl;
														}
														cout << endl;
														usermenu();
														break;
													}
													case 7:{

														int distance = 0;
														string searchusername;
														cout << "Please enter the username (case sensitive) of the user you'd like to search." << endl;
														cin >> searchusername;
														User* sUser = UserListDatabase->searchByUserName(searchusername);
														if (sUser == NULL){
														}else if(sUser != NULL){
															cout << "User exists!" << endl;
														}

														try{
															distance = UserListDatabase->BFS(searchusername, username);
														} catch (std::logic_error &e){
															std::cout << e.what() << std::endl;
														}

														cout << "The distance between you and this user is: " << distance << endl << endl << endl;

														usermenu();
														break;
													}
													case 8:
													{
														string friendname;
														cout << "Please enter the name of the user you'd like to add as a friend." << endl;
														cin >> friendname;
														User* friendUser = UserListDatabase->checkUser(friendname);
														bool checkUser = UserListDatabase->validUser(friendname);
														bool isUserFriend = UserListDatabase->checkifFriend(friendname, username);
														if (checkUser == true){
															if (friendUser->getusername() == currentUser->getusername()){
																cout << "You cannot add yourself as a friend! Don't be a loner. Go out and make friends!" << endl;
															}
															else if (isUserFriend == true){
																cout << "You are already friends with this person!" << endl;
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
													case 9:
													{
														currentUser->displayFriends();
														cout << endl;
														usermenu();
														break;
													}
													case 10:
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
													case 11:
													{
														currentUser->displayPendingFriends();
														if (currentUser->pendingEmpty() == true){
															cout << "No pending friends." << endl;
															cout << endl;
														}
														else{
															std::string userinput;
															std::cout << "Please enter the name you would like to ACCEPT from your pending friend requests." << std::endl;
															std::cout << "Press c to cancel." << std::endl;
															std::cout << "Entry: ";
															std::cin >> userinput;


															currentUser->acceptFriendRequest(userinput);
															currentUser->removePendingRequest();
															UserListDatabase->displayFriendsFriend(userinput);
														}


														usermenu();
														break;
													}
													case 12:
													{
														int points;
														int champpoints;
														string champ;
														points = playHangman(wordList);
														currentUser->setpoints(points);
														champ = UserListDatabase->checkChampion(champpoints);
														cout << "Leader: " << champ << " with most correct guesses of: " << champpoints << endl;

														usermenu();
														break;
													}
													case 13:
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
											delete [] tcode;
											menu();
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

										char tempaddress[512];
										string zpassword;
										string zaddress;
										string zemail;
										int length;
									    unsigned char encrypt[16];
									    string final;


										cout << "Enter your new password." << endl;
										cin >> zpassword;
										cout << "Enter your new address." << endl;
										cin.ignore();		//skips the enter
										cin.getline(tempaddress,512);
										zaddress = tempaddress;
										cout << "Enter your new email." << endl;
										cin >> zemail;


										length = zpassword.size();
										char *code = new char[zpassword.size()+1];
										strcpy(code, zpassword.c_str());
										md5((unsigned char*)code, length, encrypt);
									    for (int j = 0; j <16; j++){
									        final += convertIntToHex(encrypt[j]);
									    }

									    cout << final << endl;

									// FOR PRINTING
									/*  for (i = 0; i < 16; i++){
											fprintf(stderr, "%2.2x", encrypt[i]);
										}
									*/
										UserListDatabase->addUser(*tempUser, name, final, zaddress, zemail);
									    delete [] code;
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
