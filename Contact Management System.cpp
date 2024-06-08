#include <bits/stdc++.h>
#include<fstream>
using namespace std;
class Start{
	string PhoneNo,Name,Address,Description,Search;
	fstream file;
	public:
		void AddContact();
		void ShowAll();
		void SearchContact();
		void Update();
		void DeleteContact();	
};
int main() {
    Start obj;
    int n;
    
    while (true) {
        cout << " Press 1 for AddContact " << endl;
        cout << " Press 2 for ShowContact " << endl;
        cout << " Press 3 for SearchContact " << endl;
        cout << " Press 4 for UpdateContact " << endl;
        cout << " Press 5 for DeleteContact " << endl;
        cout << " Press 6 to Exit " << endl;
        cout << "\n Number :->  ";
        cin >> n;

        switch (n) {
            case 1:
                obj.AddContact();
                break;
            case 2:
                obj.ShowAll();
                break;
            case 3:
                obj.SearchContact();
                break;
            case 4:
                obj.Update();
                break;
            case 5:
                obj.DeleteContact();
                break;
            case 6:
                return 0;
            default:
                cout << " Invalid number " << endl;
        }
    }
    return 0;
}


void Start :: AddContact(){
	cout<<"Enter Phone Number :: ";
	getline(cin,PhoneNo);
		getline(cin,PhoneNo);
	cout<<"Enter Name :: ";
	getline(cin,Name);
	cout<<"Enter Address :: ";
	getline(cin,Address);
	cout<<"Enter Description :: ";
	getline(cin,Description);
	cout<<endl;
	
	file.open("data.csv",ios ::out| ios ::app);
	file<<PhoneNo<<","<<Name<<","<<Address<<","<<Description<<endl;
	file.close();
}
void Start :: ShowAll(){
	
	file.open("data.csv",ios :: in);
	
	if(!file){
		cout<<"No Contact found "<<endl;
	return ;}
	bool found=false;
	getline(file,PhoneNo,',');
	getline(file,Name,',');
	getline(file,Address,',');
	getline(file,Description,'\n');
	 
	 while(!file.eof()){
	 	cout<<"Phone Number :: "<<PhoneNo<<endl;
	 	cout<<"Name :: "<<Name<<endl;
	 	cout<<"Phone Address :: "<<Address<<endl;
	 	cout<<"Phone Description :: "<<Description<<endl;
	 	cout<<"-----------------------------"<<endl;
	 	
	    getline(file,PhoneNo,',');
	    getline(file,Name,',');
	    getline(file,Address,',');
	    getline(file,Description,'\n');
	    cout<<endl;
	 }
	 file.close();
	 
	 if(!found){
	 	cout<<"No Contacts found. "<<endl;
	 }
	
}
void Start::SearchContact() {
    cout << "Enter Phone Number to search :: ";
    getline(cin, Search);
    getline(cin, Search); // Double getline to clear the buffer

    file.open("data.csv", ios::in);
    bool found = false;

    getline(file, PhoneNo, ',');
    getline(file, Name, ',');
    getline(file, Address, ',');
    getline(file, Description, '\n');

    while (!file.eof()) {
        if (PhoneNo == Search) {
            found = true;
            cout << "Phone Number :: " << PhoneNo << endl;
            cout << "Name :: " << Name << endl;
            cout << "Address :: " << Address << endl;
            cout << "Description :: " << Description << endl;
            break; // Contact found, exit the loop
        }
        
        getline(file, PhoneNo, ',');
        getline(file, Name, ',');
        getline(file, Address, ',');
        getline(file, Description, '\n');
    }

    file.close();

    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void Start::Update() {
    cout << "Enter Phone Number to update :: ";
    getline(cin, Search);
    getline(cin, Search); // Double getline to clear the buffer

    file.open("data.csv", ios::in);
    fstream tempFile;
    tempFile.open("temp.csv", ios::out);

    bool found = false;

    getline(file, PhoneNo, ',');
    getline(file, Name, ',');
    getline(file, Address, ',');
    getline(file, Description, '\n');

    while (!file.eof()) {
        if (PhoneNo == Search) {
            found = true;
            cout << "Enter new Name :: ";
            getline(cin, Name);
            cout << "Enter new Address :: ";
            getline(cin, Address);
            cout << "Enter new Description :: ";
            getline(cin, Description);
            cout<<endl;
        }
        tempFile << PhoneNo << "," << Name << "," << Address << "," << Description << endl;

        getline(file, PhoneNo, ',');
        getline(file, Name, ',');
        getline(file, Address, ',');
        getline(file, Description, '\n');
    }

    file.close();
    tempFile.close();

    remove("data.csv");
    rename("temp.csv", "data.csv");

    if (found) {
        cout << "Contact updated successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}
void Start::DeleteContact() {
    cout << "Enter Phone Number to delete :: ";
    getline(cin, Search);
    getline(cin, Search); // Double getline to clear the buffer

    file.open("data.csv", ios::in);
    fstream tempFile;
    tempFile.open("temp.csv", ios::out);

    bool found = false;

    getline(file, PhoneNo, ',');
    getline(file, Name, ',');
    getline(file, Address, ',');
    getline(file, Description, '\n');

    while (!file.eof()) {
        if (PhoneNo == Search) {
            found = true;
            // Skip writing this contact to the temp file to effectively delete it
        } else {
            tempFile << PhoneNo << "," << Name << "," << Address << "," << Description << endl;
        }

        getline(file, PhoneNo, ',');
        getline(file, Name, ',');
        getline(file, Address, ',');
        getline(file, Description, '\n');
    }

    file.close();
    tempFile.close();

    remove("data.csv");
    rename("temp.csv", "data.csv");

    if (found) {
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}
