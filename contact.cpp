
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
string PASSWORD ;
struct mycontact {
 string name;
 string phonenumber;
 string email;
 string group; 
};

vector<mycontact> contacts;

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
 cout<<"add this contact to a group\n";
 cout<<"\t[1]. to add\n \t[0]to cancel\n";
 cin>>choice;
 if(choice==1){
 cout << "GROUP: ";
 getline(cin, contact.group); // Get the contact group
 contacts.push_back(contact);}
 else if(choice==0){
 	cout<<"NO group,Canceled\n";
 }
 cout << "=====CONTACT SAVED SUCCESSFULLY=====\n";
 
}

void displaycontacts() {
 if (contacts.empty()) {
   cout << "===!!NO CONTACT FOUND!!===";
   return;
 }
 int sort_option;
 cout << "Enter sort option:\n"
      << "1. Ascending order\n"
      << "2. Descending order\n"
      << "3. Leave in order they were saved\n"
      << "Option: ";
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
 else
  cout<<"invalid input\n";

 for (size_t i = 0; i < contacts.size(); i++) {
   cout << i + 1 << ". NAME: " << contacts[i].name << endl;
   cout << " PHONENUMBER: " << contacts[i].phonenumber << endl;
   cout << " EMAIL: " << contacts[i].email << endl;
   cout << " GROUP: " << contacts[i].group << endl; // Display contact group
 }
}

void searchcontact() {
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
	cout<<"\t\t\tWELCOME TO CONTACTBOOK\n";
	 cout<<"\t***************************************************\n";
	cout<<"\t\twould like to put password:\n";
	cout<<" To control unauthorized access, keeping your sensitive personal information safe.\n";
	cout<<"\t\t[1] to continue:\n \t\t[0] to cancel and continue without a password:\n";
	int choice1;
	cin>>choice1;
	if(choice1==1){
	
	 cout << "Enter password: "<<endl;
	getline(cin,PASSWORD);
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
 cout<<"\t\tCLICK\n \t\t[1]. continue using contactbook\n";
 cout<<"\t\t[0] to exit\n";
 cin>>use;
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
 	int numcontacts;
 cout << "\n\t ==== Contact Management System ====\n";
 cout << "How Many contacts you want to add: ";
 cin >> numcontacts;
 for (int i = 0; i < numcontacts; i++) {
 addcontact();
 }
 break;

 case 2:
 displaycontacts();
 break;

 case 3:
 searchcontact();
 break;

 case 4:
 deletecont();
 break;

 case 5:
 advancedsearch();
 break;

 default:
 cout << "!!!!!INVALID INPUT!!!!!";
 }
 }

 return 0;
 
}