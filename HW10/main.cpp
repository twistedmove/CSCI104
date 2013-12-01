#include <iostream>
#include <vector>
#include "hash.h"
#include <fstream>
#include <cstdlib>
#include <limits>
#include <sstream>
using namespace std;

void menu(){
	cout << "                                 " << endl;
	cout << "               Menu              " << endl;
	cout << "*-------------------------------*" << endl;
	cout << "| 1. Student/GPA                |" << endl;
	cout << "| 2. Thanksgiving Donation      |" << endl;
	cout << "| 3. Thanksgiving Calories      |" << endl;
	cout << "| 4. Google                     |" << endl;
	cout << "| 5. Quit the program           |" << endl;
	cout << "*-------------------------------*" << endl;
	cout << "                                 " << endl;
}

void gpamenu(){
	cout << "                                 " << endl;
	cout << "               Menu              " << endl;
	cout << "*-------------------------------*" << endl;
	cout << "| 1. Add Key                    |" << endl;
	cout << "| 2. Delete Key                 |" << endl;
	cout << "| 3. View All                   |" << endl;
	cout << "| 4. Quit                       |" << endl;
	cout << "*-------------------------------*" << endl;
	cout << "                                 " << endl;
}


int nextPrime(int input){
	bool isPrime;
	int val;

	for(val = input+1;; val++){
		isPrime = true;
		for(int i = 2; i*i <= val; i++){
			if (val % i == 0){
				isPrime = false;
			}
		}
		if(isPrime == true){
			break;
		}
	}
	return val;
}


string intString(int number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}

bool is_Empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

void importCalorie(int &turk, int &plat, int &total, vector<string> &turkeyList, vector<string> &sideList){
	ifstream importFile("calorie.txt");
		if (importFile.fail()){
			cout << "<!-- calorie.txt does not exist. --!>" << endl;
		}
		string iterturkey;
		string iterside;
		string tot;
		string temp;
		string trash;

		if (!is_Empty(importFile)){
			if (importFile.good()){
				importFile >> iterturkey;
				int numturkey = atoi(iterturkey.c_str());
				turk = numturkey;
				importFile >> iterside;
				int numside = atoi(iterside.c_str());
				plat = numside;
				importFile >> tot;
				int value = atoi(tot.c_str());
				total = value;
				getline(importFile, trash, '\n');
				if(!importFile.eof()){
					for (int i=0; i < numturkey; i++){
						getline(importFile, temp, '\n');
						turkeyList.push_back(temp);
					}
					for (int i=0; i < numside; i++){
						getline(importFile, temp, '\n');
						sideList.push_back(temp);
					}
				}
			}
		}
		importFile.close();
}

void importFood(int &totsize, vector<string> &foodlist){
	ifstream importFile("turkey.txt");
		if (importFile.fail()){
			cout << "<!-- turkey.txt does not exist. --!>" << endl;
		}

		string size;
		string temp;

		if (!is_Empty(importFile)){
			if (importFile.good()){
				getline(importFile, size, '\n');
				int value = atoi(size.c_str());
				totsize = value;
				if(!importFile.eof()){
					for (int i=0; i < value; i++){
						getline(importFile, temp, '\n');
						foodlist.push_back(temp);
					}
				}
			}
		}


		importFile.close();
}

int importGoogleSize(){
	int totsize = 0;
//	ifstream importFile("small.txt");
	ifstream importFile("medium.txt");
	if (importFile.fail()){
		cout << "<!-- File does not exist. --!>" << endl;
	}
	string size;

	if (!is_Empty(importFile)){
		if (importFile.good()){
			getline(importFile, size, '\n');
			int value = atoi(size.c_str());
			totsize = value;
		}
	}
	return totsize;
	importFile.close();
}

void importGoogle(int &totalsize, vector<vector <string> > &vect){
	int counter = 0;

//	ifstream importFile("small.txt");
	ifstream importFile("medium.txt");
		if (importFile.fail()){
			cout << "<!-- File does not exist. --!>" << endl;
		}
		string size;

		if (!is_Empty(importFile)){
			if (importFile.good()){
				getline(importFile, size, '\n');
				int value = atoi(size.c_str());
				totalsize = value;
				while (!importFile.eof()){
					string temp;
					string word;
					getline(importFile, temp, '\n');
					vect[counter].push_back(temp);
					istringstream iss(temp);
					while (getline(iss, word, ' ')){
						vect[counter].push_back(word);
					}
					counter++;
				}
			}
		}
		importFile.close();
}


int main(){
	vector<string> foodList;
	vector<string> turkeyList;
	vector<string> sideList;

	// Case 4
		int asize = 0;
		vector<vector <string> > vect;
		asize = importGoogleSize();
		asize *= 3;
		vect.reserve(asize);
		importGoogle(asize, vect);
		int nextprime = nextPrime(asize*100);
		Hashtable<string, string> goog(nextprime);

		for (int i =0; i<asize; i++){
			for (int j =1; j<vect[i].size(); j++){
				goog.add(vect[i][j],vect[i][0]);
			}
		}



	int selection = 0;
	menu();
	while (selection != 5){
		cout << "Selection: ";
		cin >> selection;
		if (cin.fail()){
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
			case 1:
			{
				int num = 100;
				int nextprime;

				nextprime = nextPrime(num*3);
				Hashtable<string, string> table(nextprime);

				int menuselect = 0;

				while(menuselect !=4){
					gpamenu();
					cout << "Selection: ";
					cin >> menuselect;
					if (cin.fail()){
						cin.clear();
						cin.ignore(1024, '\n');
						cout << "Invalid Selection." << endl;
						continue;
					}
					cin.clear();
					cin.ignore(1024,'\n');
					cout << endl;
					switch (menuselect){
						case 1:
						{
							string one;
							string two;

							cout << "Please enter the key (string/STUDENT) you would like to add." << endl;
							cin >> one;
							cout << "Please enter the value for the key (float/GPA): " << one << endl;
							cin >> two;

							table.add(one, two);
							break;
						}
						case 2:
						{
							string one;
							cout << "Please enter the key you would like to delete." << endl;
							cin >> one;
							try{
								table.remove(one);
							} catch (std::logic_error &e){
								cout << e.what() << endl;
							}
							break;
						}
						case 3:
						{
							table.print();
							break;
						}
						case 4:
						{
							cout << "!-- TERMINATED -- !" << endl;
							break;
						}
					}
				}

				menu();
				break;
			}
			case 2:
			{
				int bsize;
				string donate = "default";
				importFood(bsize, foodList);
				Hashtable<string, string> table(bsize*3000);
				for (int i=0; i<foodList.size(); i++){
						string counter = intString(i);
						table.add(foodList[i], counter);
				}
				try{
					donate = table.mostCommon();
				} catch (std::logic_error &e){
					cout << e.what() << endl;
				}
				if (donate != "default"){
					cout << "You should donate " << donate << endl;
				}
				foodList.clear();

				menu();
				break;
			}
			case 3:
			{
				int newsum = 0;
				int compare = 0;
				int target = 0;
				int turk = 0;
				int side = 0;
				importCalorie(turk, side, target, turkeyList, sideList);


				int t = turkeyList.size();
				int s = sideList.size();

				int turkprime = nextPrime(t*30000);
				int sideprime = nextPrime(s*30000);
				Hashtable<string, string> ttable(turkprime);
				Hashtable<string, string> stable(sideprime);
				for (int i =0; i < t; i++){
					ttable.add(turkeyList[i],turkeyList[i]);
				}
				cout << endl;
				for (int i =0;i < s;i++){
					stable.add(sideList[i],sideList[i]);
				}

				for (int i =0; i < turk; i++){
					string find;
					string returned;
					int var = atoi(turkeyList[i].c_str());
					newsum = target - var;
					find = intString(newsum);

					try{
						returned = stable.get(find);
					} catch(std::logic_error &e){}

					compare = atoi(returned.c_str());
					if (newsum == compare){
						cout << target << " = " << var << " + " << returned << endl;
						break;
					}
				}
				if (newsum != compare){
					cout << "No existing combination. Sorry." << endl;
				}

				turkeyList.clear();
				sideList.clear();
				ttable.destroy();
				stable.destroy();
				menu();
				break;
			}
			case 4:
			{
				string searchkey;

				cout << "Please enter a key to search." << endl;
				cin >> searchkey;
				cout << endl;
				cout << "Your search results: " << endl;
				goog.findKey(searchkey);

				menu();
				break;
			}
			case 5:
			{
				cout << "<!-- PROGRAM TERMINATED --!>" << endl;
				break;
			}
			default:
			{
				cout << "<!-- INVALID SELECTION --!>" << endl;
			}
		}
	}


	return 0;
}
