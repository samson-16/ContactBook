#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// declare structure
struct mycontact {
    string name;
    string phonenumber;
    string email;
    string group;
};
mycontact contact;
void addContactToFile(mycontact &contact) {
    ofstream file("mycontact.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << contact.name << "\t" << contact.phonenumber << "\t" << contact.email << "\t" << contact.group << "\n";
        file.close();
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

void addContact() {
    
    cout << "NAME: ";
    cin.ignore();
    getline(cin, contact.name);
    cout << "PHONENUMBER: ";
    getline(cin, contact.phonenumber);
    cout << "EMAIL: ";
    getline(cin, contact.email);
    
    // Check if the email address contains the @ symbol
    if (contact.email.find("@") == string::npos) {
        // If the email address does not contain the @ symbol, prompt the user to include it
        cout << "Please include the @ symbol in the email address." << endl;
        getline(cin, contact.email);
    }
    int choice;
    cout << "Add this contact to a group?" << endl;
    cout << "[1] ADD GROUP\n[0] TO CANCEL\n";
    cin >> choice;
    if (choice == 1) {
        cout << "GROUP: ";
        cin.ignore();
        getline(cin, contact.group);
    } else {
        contact.group = "";
        cout << "No group, Canceled" << endl;
    }

    cout << "=====CONTACT SAVED SUCCESSFULLY=====" << endl;
    addContactToFile(contact);
}

void displayContacts() {
    ifstream infile("mycontact.txt");
    string line;

    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}

void searchContact() {
    string name;
    cout << "Enter the name of the contact to search for: ";
    cin.ignore();
    getline(cin, name);

    ifstream infile("mycontact.txt");
    string line;
    bool found = false;

    while (getline(infile, line)) {
        if (line.find(name) != string::npos) {
            cout << "Contact found:" << endl;
            cout << line << endl;
            found = true;
            break;
        }
    }

    infile.close();

    if (!found) {
        cout << "Contact not found." << endl;
    }
}


int main() {
    cout << "\t\t\tWELCOME TO CONTACTBOOK\n";
    cout << "\t***********\n";
    cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

    
     int choice;
    do {
        cout << "MENU:\n";
        cout << "[1] Add Contact\n";
        cout << "[2] Display Contacts\n";
        cout << "[3] Search Contact\n";
        cout<<  "[4] edit contact\n";
        cout<<  "[5] advanced search contact\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	 case 0:
                cout << "Exiting the program.\n";
                break;
            case 1:
                 char ch;
    do {
        addContact();
        cout << "Enter 'a' to add more contacts or any other key to exit: ";
        cin >> ch;
    } while (ch == 'a');
                break;
            case 2:
                cout << "Displaying Contacts:" << endl;
                  displayContacts();
                break;
            case 3:
                searchContact();
                break;
          
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}