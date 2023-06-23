#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string lastName;
    string city;
    string email;
    string phoneNumber;
};

class ContactBook {
public:
    void addContact();
    void searchContact();
    void deleteContact();
    void showAllContacts();
    void deleteAllContacts();
    void updateContact();
};

void ContactBook::addContact() {
	system("cls");
    Contact contact;
    ofstream file("contacts.txt", ios::app);
    cout << "Enter name: ";
    cin >> contact.name;
    cout << "Enter last name: ";
    cin >> contact.lastName;
    cout << "Enter city: ";
    cin >> contact.city;
    cout << "Enter email: ";
    cin >> contact.email;
    cout << "Enter phone number: ";
    cin >> contact.phoneNumber;
    file <<endl<< contact.name << " " << contact.lastName << " " << contact.city << " " << contact.email << " " << contact.phoneNumber << endl;
    file.close();
     system("cls");
    cout<<"Contact Added."<<endl;
}

void ContactBook::searchContact() {
	system("cls");
    ifstream file("contacts.txt");
    string searchKeyword;
    bool found = false;
    cout << "Enter name or last name or Phonebook or Email or City to search: ";
    cin >> searchKeyword;
    char str1[40],str2[40],str3[40],str4[40],str5[40];
    while (!file.eof()) {
        
        file.getline(str1,41,' ');
		file.getline(str2,41,' ');
		file.getline(str3,41,' ');
		file.getline(str4,41,' ');
		file.getline(str5,41,'\n');
        if (str1 == searchKeyword || str2 == searchKeyword||str3==searchKeyword||str4==searchKeyword) {
            found = true;
            cout << endl<<"Name: " <<str1<< endl;
            cout << "Last name: " << str2 << endl;
            cout << "City: " << str3 << endl;
            cout << "Email: " << str4 << endl;
            cout << "Phone number: " << str5 << endl;
            break;
        }
    }
    if (found==false) {
        cout << "Contact not found." << endl;
    }
    file.close();
}
void ContactBook::deleteContact() {
	system("cls");
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");
    string deleteKeyword;
    bool found = false;
    cout << "Enter name or last name to delete: ";
    cin >> deleteKeyword;
    string name, lastName, city, email, phoneNumber;
    while (file >> name >> lastName >> city >> email >> phoneNumber) {
        if (name == deleteKeyword || lastName == deleteKeyword) {
            found = true;
            cout << "Are you sure you want to delete this contact? (Y/N): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                cout << "Contact deleted." << endl;
            } else {
                temp << name << " " << lastName << " " << city << " " << email << " " << phoneNumber << endl;
                cout << "Contact not deleted." << endl;
            }
        } else {
            temp << name << " " << lastName << " " << city << " " << email << " " << phoneNumber << endl;
        }
    }
    if (found == false) {
        cout << "Contact not found." << endl;
    }
    file.close();
    temp.close();
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
}
void ContactBook::showAllContacts() {
	system("cls");
    ifstream file("contacts.txt");
    string name, lastName, city, email, phoneNumber;
    bool x=0;
    while (file >> name >> lastName >> city >> email >> phoneNumber) {
        cout << "Name: " << name << endl;
        cout << "Last name: " << lastName << endl;
        cout << "City: " << city << endl;
        cout << "Email: " << email << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << endl;
        x=1;
    }
    file.close();
    if(x==0)
    {
    	cout<<"No Contacts."<<endl;
	}
}
void ContactBook::deleteAllContacts() {
    system("cls");
    cout << "Are you sure you want to delete all contacts? (y/n)" << endl;
    char confirmation;
    cin >> confirmation;
    if (confirmation == 'y' || confirmation == 'Y') {
        ofstream file("contacts.txt");
        file.close();
        cout << "All contacts deleted." << endl;
    } else {
        cout << "Deletion cancelled." << endl;
    }
}
void ContactBook::updateContact() {
    system("cls");
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");
    string updateKeyword;
    bool found = false;
    cout << "Enter name or last name to update: ";
    cin >> updateKeyword;
    string name, lastName, city, email, phoneNumber;
    while (file >> name >> lastName >> city >> email >> phoneNumber) {
        if (name != updateKeyword && lastName != updateKeyword) {
            temp << name << " " << lastName << " " << city << " " << email << " " << phoneNumber << endl;
        } else {
            found = true;
            string newName, newLastName, newCity, newEmail, newPhoneNumber;
            cout << "Enter new name: ";
            cin >> newName;
            cout << "Enter new last name: ";
            cin >> newLastName;
            cout << "Enter new city: ";
            cin >> newCity;
            cout << "Enter new email: ";
            cin >> newEmail;
            cout << "Enter new phone number: ";
            cin >> newPhoneNumber;
            temp << newName << " " << newLastName << " " << newCity << " " << newEmail << " " << newPhoneNumber << endl;
        }
    }
    if (found == false) {
        cout << "Contact not found." << endl;
    } else {
        cout << "Contact updated." << endl;
    }
    file.close();
    temp.close();
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
}
int main() {
   ContactBook contactBook;
    char choice;
    system("COLOR 1E");
    while (true) {
        cout << "***=====================CONTACT MANAGER VER 0.01=========================***"<<endl<<"1.Add contact" << endl;
        cout << "2. Search contact" << endl;
        cout << "3. Delete contact" << endl;
        cout << "4. Show all contacts" << endl;
        cout << "5. Delete all contacts" << endl;
        cout << "6. Update contact" <<endl;
        cout << "7. Exit" <<endl<<"************************************************************************************"<< endl;
        cout << "Enter your choice: ";
        cin>>choice;   
        switch (choice) {
            case '1':
                contactBook.addContact();
                break;
            case '2':
                contactBook.searchContact();
                break;
            case '3':
                contactBook.deleteContact();
                break;
            case '4':
                contactBook.showAllContacts();
                break;
            case '5':
                contactBook.deleteAllContacts();
                break;
            case '6':
            	contactBook.updateContact();
            	break;
            case '7':
                return 0;
            default:
            	system("cls");
                cout << "Invalid choice." << endl;
                break;
        }
	

}

}
