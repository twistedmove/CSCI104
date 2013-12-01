/*
 * test.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: BryanChong
 */


#include <iostream>
#include "hash.h"
#include <string>
#include <exception>
using namespace std;

int main(){
	Hashtable<string, string> *table = new Hashtable<string, string>(10);

	table->add("Tina", "4.0");
	table->add("Bryan", "3.9");
	table->add("Steven", "3.7");
	table->add("Stephen", "3.6");
	table->add("David", "3.5");
	table->add("Bob", "3.4");
	table->add("Jane", "3.3");
	table->add("John", "3.2");
//	table->remove("Tina");
	table->print();

/*
	try{
		cout << table->get("Tina") << endl;
	} catch (std::logic_error &e){
		cout << e.what() << endl;
	}

	try{
		cout << table->get("Bryan") << endl;
	} catch (std::logic_error &e){
		cout << e.what() << endl;
	}
*/

	return 0;
}



