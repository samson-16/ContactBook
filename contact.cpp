// c++ code of contact managment system
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
string PASSWORD ;
// declare structure
struct mycontact {
 string name;
 string phonenumber;
 string email;
 string group; 
};

vector<mycontact> contacts;
// construct function
// function of add contact

void addcontact() {
 mycontact contact;
 cout << "NAME: ";
 cin.ignore();
 getline(cin, contact.name);
 cout << "PHONENUMBER: ";
 getline(cin, contact.phonenumber);
 cout << "EMAIL: ";
 getline(cin, contact.email);
 int choice;
	int add;
	add:
 cout<<"add this contact to a group\n";
 cout<<"\t[1] ADD GROUP\n \t[0]TO CANCEL\n";
 cin>>choice;
 if(choice==1){
    cout << "GROUP: ";
    cin.ignore(); 
    getline(cin, contact.group);
    contacts.push_back(contact);
 }
 else if(choice==0){
    contact.group=""; 
    cout<<"NO group, Canceled\n";
    contacts.push_back(contact); }
	else{
		cout<<"\t\tinvliad input...please choose correctly\n";
		goto add;
	}
	 
 cout << "=====CONTACT SAVED SUCCESSFULLY=====\n";
}
// function to display an input contact
void displaycontacts() {
	//check whether if a contact is an empty before display 
 if (contacts.empty()) {
   cout << "===!!NO CONTACT FOUND!!===";
   return;
 }
	
 int sort_option;
	// a choice how to display an entered contact 
	cout<<"\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
 cout << "Enter sort option:\n"
      << "1. ASCENDING order\n"
      << "2. DESCENDING order\n"
      << "3. Leave in order they were SAVED\n"
      << "OPTION: ";
 cin >> sort_option;

 if (sort_option == 1) {
   sort(contacts.begin(), contacts.end(), [](mycontact a, mycontact b) {
     return a.name < b.name;
   });
 } else if (sort_option == 2) {
   sort(contacts.begin(), contacts.end(), [](mycontact a, mycontact b) {
     return a.name > b.name;
   });
 }
  else if(sort_option==3){
  	cout<<"Time saved:"<<endl;
  }
 else {
 	cout<<"invalid input. \n";
 	goto last;
 }

 for (size_t i = 0; i < contacts.size(); i++) {
   cout << i + 1 << ". NAME: " << contacts[i].name << endl;
   cout << " PHONENUMBER: " << contacts[i].phonenumber << endl;
   cout << " EMAIL: " << contacts[i].email << endl;

 }
 last:
 	cout<<"check your input\n";
 
}
// a function below helps a user to find a contact from a dozen of contacts saved 
void searchcontact() {
	//check whether if a contact is an empty before searching 
 
 if (contacts.empty()) {
 cout << "===!!NO CONTACT FOUND!!===";
 return;
 }
 string name;
 cout << "===WELCOME TO SEARCH BAR===";
 cout << "ENTER NAME ";
 cin.ignore();
 getline(cin, name);
 bool found = false;
 cout << "===SEARCH RESULT===\n";
 for (size_t i = 0; i < contacts.size(); i++) {
 // crosscheck if a name searched is the same as names on contact list
	 if (contacts[i].name == name) {

 cout << "NAME: " << contacts[i].name << endl;
 cout << "PHONENUMBER: " << contacts[i].phonenumber << endl;
 cout << "EMAIL: " << contacts[i].email << endl;
 cout << "GROUP: " << contacts[i].group << endl; // Display contact group
 found = true;
 }
 }
 if (!found) {
 cout << "===NO CONTACT FOUND WITH THE NAME YOU ENTERED===";
 }
}
// the below function is to erase unwanted or mistaken contact
void deletecont() {
 if (contacts.empty()) {
 cout << "===!!NO CONTACT FOUND!!===";
 return;
 }
 string namee;
 cout << "===ENTER CONTACT NAME TO BE DELETED: ";
 cin.ignore();
 getline(cin, namee);
 bool found = false;
 for (size_t i = 0; i < contacts.size(); i++) {
 if (contacts[i].name == namee) {
 contacts.erase(contacts.begin() + i);
 found = true;
 cout << "==CONTACT DELETED SUCCESSFULLY===";
 break; // Exit the loop after deleting the contact
 }
 }
 if (!found) {
 cout << "==NAME TO BE DELETED IS NOT FOUND==";
 }
}

void advancedsearch() {
 if (contacts.empty()) {
 cout << "===!!NO CONTACT FOUND!!===";
 return;
 }
 string keyword;
 cout << "===WELCOME TO ADVANCED SEARCH BAR===";
 cout << "ENTER KEYWORD: ";
 cin.ignore();
 getline(cin, keyword);
 bool found = false;
 cout << "===SEARCH RESULT===\n";
 for (size_t i = 0; i < contacts.size(); i++) {
 if (contacts[i].name.find(keyword) != string::npos ||
 contacts[i].phonenumber.find(keyword) != string::npos ||
 contacts[i].email.find(keyword) != string::npos ||
 contacts[i].group.find(keyword) != string::npos) {
 cout << "NAME: " << contacts[i].name << endl;
 cout << "PHONENUMBER: " << contacts[i].phonenumber << endl;
 cout << "EMAIL: " << contacts[i].email << endl;
 cout << "GROUP: " << contacts[i].group << endl;
 found = true;
 }
 }
 if (!found) {
 cout << "===NO CONTACT FOUND WITH THE KEYWORD YOU ENTERED===";
 }
}

int main() {
	//Greetings 
	cout<<"\t\t\tWELCOME TO CONTACTBOOK\n";
	 cout<<"\t***************************************************\n";
	cout<<"\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	// asking user to have a password
	cout<<"\t\twould like to put password:\n";
	
	cout<<" To control unauthorized access, keeping your sensitive personal information safe.\n";
	cout<<"\t\t[1] To continue:\n \t\t[0] To cancel and continue without a password:\n";
	int choice1;
	cin>>choice1;
	if(choice1==1){
	one:
		 cout << "Enter password:";
cin>>PASSWORD;
int pass;
cout<<"ARE U SURE YOU WANT TO CREATE THIS AS YOUR PASSWORD:\n";
cout<<"[1] SURE\n";
cout<<"[0] CHANGE\n";
cin>>pass;
if(pass==1){
	cout<<"created succesfully\n";
}
else if(pass==0){
	cout<<"creat new password...\n";
	goto one;
}

cout<<"\t\t************************************************************\n";
cout<<"\t\t==========================================================\n";
		string password;
	cout<<"Enter password: ";
	cin>>password;
 if (password != PASSWORD) {
   cout << "Incorrect password. Exiting program." << endl;
   return 1;
 }
	 }

	else if(choice1==0){
		cout<<"canceled"<<endl;	
		
	}
	

 cout<<"\t***************************************************\n";
 int use;
 label:
 cout<<"\t\tCLICK\n \t\t[1]continue using contactbook\n";
 cout<<"\t\t[0] to exit\n";
 cin>>use;
 cout<<"\t\t============================================================\n";
 if(use==1){
  goto first;
 }
 else if(use==0){
 cout<<"THANK YOU FOR USING CONTACTBOOK\n ";
 exit(1);}
 else {
 	cout<<"invalid input, please choose correctly\n";
 	goto label;
 }
first:
 for (;;) {
 int ch;
//menu bar
 cout << "\n\t ==== Contact Management System ====";
 cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add Contact\n\t\t[2] Display all Contacts\n\t\t[3] Search contact\n\t\t[4] Delete Contact\n\t\t[5] Advanced Search\n\t\t[0] Exit\n\t\t=================\n\t\t";
 cout << "Enter the choice: ";
 cin >> ch;

 switch (ch) {
 case 0:
 cout << "\n\n\t\tThank you for using CMS...";
 return 0;
 exit(1);

 case 1:
	 //function of add a contact
 	int numcontacts;
 cout << "\n\t ==== Contact Management System ====\n";
 cout << "How Many contacts you want to add: ";
 cin >> numcontacts;
 for (int i = 0; i < numcontacts; i++) {
 	cout<<"\t\t======================================================"<<endl;
 	cout<<"CREATE CONTACT "<<i+1<<endl;
 addcontact();
 }
 break;

 case 2:
	 // function of Display contacts
 displaycontacts();
 break;

 case 3:
	 //function ofsearch for a contact 
 searchcontact();
 break;

 case 4:
       // function of delete unwanted contact 

 deletecont();
 break;

 case 5:
	 //advanced search
 advancedsearch();
 break;

 default:
 cout << "!!!!!INVALID INPUT!!!!!";
 }
 }

 return 0;
 
}
/*
The code is a C++ program for a contact management system. It allows the user to add, display, search, and delete contacts 

1. The code starts by including the necessary libraries and declaring a global variable PASSWORD.

2. The code defines a structure called mycontact, which represents a contact with fields for name, phone number, email, and group.

3. The code declares a vector called contacts to store the contacts.

4. The code defines a function called addcontact() that prompts the user to enter the details of a contact (name, phone number, email, and group) and adds it to the contacts vector.

5. The code defines a function called displaycontacts() that displays all the contacts stored in the contacts vector. It allows the user to choose how to sort the contacts (ascending, descending, or leave in the order they were saved).

6. The code defines a function called searchcontact() that prompts the user to enter a name and searches for contacts with that name in the contacts vector. It displays the matching contacts if found.

7. The code defines a function called deletecont() that prompts the user to enter a name and deletes the contact with that name from the contacts vector if found.

8. The code defines a function called advancedsearch(), but its implementation is missing.

Overall, the code provides basic functionality for managing contacts. However, there are some improvements that can be made, such as adding input validation and error handling, implementing the missing advancedsearch() function, and organizing the code into separate files and classes for better modularity and maintainability.
*/
