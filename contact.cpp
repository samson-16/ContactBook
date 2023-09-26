#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

string PASSWORD;

// declare structure
struct mycontact {
    string name;
    string phonenumber;
    string email;
    string group;
};

vector<mycontact> contacts;

// File to store contacts
const string contactFile = "contacts.txt";
const string passwordFile = "password.dat"; // Password file in binary format

// Function to save contacts to a file
void saveContactsToFile() {
    ofstream file(contactFile);
    if (file.is_open()) {
        for (const mycontact& contact : contacts) {
            file << contact.name << "\t" << contact.phonenumber << "\t" << contact.email << "\t" << contact.group << "\n";
        }
        file.close();
    }
}

// Function to load contacts from a file
void loadContactsFromFile() {
    ifstream file(contactFile);
    if (file.is_open()) {
        mycontact contact;
        while (file >> contact.name >> contact.phonenumber >> contact.email >> contact.group) {
            contacts.push_back(contact);
        }
        file.close();
    }
}

// Function to save the password in binary format
void savePasswordToFile() {
    ofstream file(passwordFile, ios::binary);
    if (file.is_open()) {
        file.write(PASSWORD.c_str(), PASSWORD.size());
        file.close();
    }
}

// Function to load the password from a binary file
void loadPasswordFromFile() {
    ifstream file(passwordFile, ios::binary);
    if (file.is_open()) {
        file.seekg(0, ios::end);
        int length = file.tellg();
        file.seekg(0, ios::beg);
        char* buffer = new char[length];
        file.read(buffer, length);
        PASSWORD = string(buffer, length);
        file.close();
        delete[] buffer;
    }
}

// Function to set or verify the password
void setPassword() {
    one:
    cout << "Enter password: ";
    cin >> PASSWORD;
    int pass;
    cout << "ARE YOU SURE YOU WANT TO SET THIS AS YOUR PASSWORD:\n";
    cout << "[1] SURE\n";
    cout << "[0] CHANGE\n";
    cin >> pass;
    if (pass == 1) {
        cout << "Password created successfully\n";
        // Save the password in binary format
        savePasswordToFile();
    } else if (pass == 0) {
        cout << "Create a new password...\n";
        goto one;
    }
}

// Function to check the entered password
bool checkPassword() {
    string password;
    cout << "Enter password: ";
    cin >> password;
    return (password == PASSWORD);
}

// Function of add a contact
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
    cout << "Add this contact to a group\n";
    cout << "\t[1] ADD GROUP\n \t[0] TO CANCEL\n";
    cin >> choice;
    if (choice == 1) {
        cout << "GROUP: ";
        cin.ignore();
        getline(cin, contact.group);
        contacts.push_back(contact);
        // Save contacts after adding
        saveContactsToFile();
    } else if (choice == 0) {
        contact.group = "";
        cout << "NO group, Canceled\n";
        contacts.push_back(contact);
        // Save contacts after adding
        saveContactsToFile();
    } else {
        cout << "\t\tInvalid input...please choose correctly\n";
        goto add;
    }

    cout << "=====CONTACT SAVED SUCCESSFULLY=====\n";
}

// Function to display contacts
void displaycontacts() {
    // Check whether if a contact is empty before display
    if (contacts.empty()) {
        cout << "===!!NO CONTACT FOUND!!===";
        return;
    }

    int sort_option;
    // A choice of how to display an entered contact
    cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "Enter sort option:\n"
        << "1. ASCENDING order\n"
        << "2. DESCENDING order\n"
        << "3. Leave in the order they were SAVED\n"
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
    else if (sort_option == 3) {
        cout << "Time saved:" << endl;
    }
    else {
        cout << "Invalid input. \n";
        goto last;
    }

    for (const mycontact& contact : contacts) {
        cout << "NAME: " << contact.name << "\t";
        cout << "PHONENUMBER: " << contact.phonenumber << "\t";
        cout << "EMAIL: " << contact.email << "\t";
        cout << "GROUP: " << contact.group << endl;
    }

last:
    cout << "Check your input\n";
}

// Function to search for a contact
void searchcontact() {
    // Check whether if a contact is empty before searching
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
    for (const mycontact& contact : contacts) {
        // Crosscheck if a name searched is the same as names on the contact list
        if (contact.name == name) {
            cout << "NAME: " << contact.name << "\t";
            cout << "PHONENUMBER: " << contact.phonenumber << "\t";
            cout << "EMAIL: " << contact.email << "\t";
            cout << "GROUP: " << contact.group << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "===NO CONTACT FOUND WITH THE NAME YOU ENTERED===";
    }
}

// Function to delete a contact
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
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == namee) {
            it = contacts.erase(it);
            found = true;
            cout << "==CONTACT DELETED SUCCESSFULLY===";
            // Save contacts after deleting
            saveContactsToFile();
            break; // Exit the loop after deleting the contact
        }
    }
    if (!found) {
        cout << "==NAME TO BE DELETED IS NOT FOUND==";
    }
}

// Function for advanced search
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
    for (const mycontact& contact : contacts) {
        if (contact.name.find(keyword) != string::npos ||
            contact.phonenumber.find(keyword) != string::npos ||
            contact.email.find(keyword) != string::npos ||
            contact.group.find(keyword) != string::npos) {
            cout << "NAME: " << contact.name << "\t";
            cout << "PHONENUMBER: " << contact.phonenumber << "\t";
            cout << "EMAIL: " << contact.email << "\t";
            cout << "GROUP: " << contact.group << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "===NO CONTACT FOUND WITH THE KEYWORD YOU ENTERED===";
    }
}

// Function to edit a contact
void editContact() {
    if (contacts.empty()) {
        cout << "===!!NO CONTACT FOUND!!===";
        return;
    }
    string name;
    cout << "Enter the name of the contact you want to edit: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;

    for (mycontact& contact : contacts) {
        if (contact.name == name) {
            cout << "Editing Contact: " << contact.name << "\n";
            cout << "Enter new information:\n";
            cout << "NEW NAME: ";
            getline(cin, contact.name);
            cout << "NEW PHONENUMBER: ";
            getline(cin, contact.phonenumber);
            cout << "NEW EMAIL: ";
            getline(cin, contact.email);
            cout << "NEW GROUP: ";
            getline(cin, contact.group);
            found = true;
            cout << "Contact edited successfully!\n";
            // Save contacts after editing
            saveContactsToFile();
            break;
        }
    }

    if (!found) {
        cout << "===NO CONTACT FOUND WITH THE NAME YOU ENTERED===";
    }
}
int main() {
    system("color 3E");
    // Greetings
    cout << "\t\t\tWELCOME TO CONTACTBOOK\n";
    cout << "\t***********\n";
    cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

    // Load password from file
    loadPasswordFromFile();

    if (PASSWORD.empty()) {
        // If no password is set, ask to set one
        cout << "\t\tWould you like to set a password:\n";
        cout << "To control unauthorized access, keeping your sensitive personal information safe.\n";
        cout << "\t\t[1] To set a password:\n \t\t[0] To cancel and continue without a password:\n";

        int choice1;
        cin >> choice1;
        if (choice1 == 1) {
            setPassword();
        } else if (choice1 == 0) {
            cout << "Canceled\n";
        }
    }

    cout << "\t\t************\n";
    cout << "\t\t==========================================================\n";

    if (!PASSWORD.empty()) {
        // Verify password if it's set
        if (!checkPassword()) {
            cout << "Incorrect password. Exiting program." << endl;
            return 1;
        }
    }

    // Load contacts from the file when the program starts
    loadContactsFromFile();

    // Rest of the code remains the same with some modifications

    for (;;) {
        int ch;
        //menu bar
        cout << "\n\t ==== Contact Management System ====";
        cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add Contact\n\t\t[2] Display all Contacts\n\t\t[3] Search contact\n\t\t[4] Delete Contact\n\t\t[5] Advanced Search\n\t\t[6] Edit contact\n\t\t[0] Exit\n\t\t=================\n\t\t";
        cout << "Enter the choice: ";
        cin >> ch;

        switch (ch) {
        case 0:
            // Save contacts to the file before exiting
            saveContactsToFile();
            cout << "\n\n\t\tThank you for using CMS...";
            return 0;
            exit(1);

        case 1:
            // function of add a contact
            int numcontacts;
            cout << "\n\t ==== Contact Management System ====\n";
            cout << "How Many contacts you want to add: ";
            cin >> numcontacts;
            for (int i = 0; i < numcontacts; i++) {
                cout << "\t\t======================================================" << endl;
                cout << "CREATE CONTACT " << i + 1 << endl;
                addcontact();
            }
            break;

        case 2:
            // function of Display contacts
            displaycontacts();
            break;
        case 3:
            // function of search for a contact
            searchcontact();
            break;

        case 4:
            // function of delete unwanted contact
            deletecont();
            // Save contacts after deleting
            saveContactsToFile();
            break;

        case 5:
            // advanced search
            advancedsearch();
            break;
        case 6: // Add this option for editing contacts
            editContact();
            break;

        default:
            cout << "!!!!!INVALID INPUT!!!!!";
        }
    }

    return 0;
}
