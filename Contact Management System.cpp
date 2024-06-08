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
};
int main(){
	Start obj;
	cout<<" Press 1 for AddContact "<<endl;
	cout<<" Press 2 for ShowContact "<<endl;
	cout<<" Press 3 for SearchContact "<<endl;
	cout<<" Press 4 for UpdateContact "<<endl;
	cout<<"\n Number :->  ";
	int n;
	cin>>n;
	switch(n){
	
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
    default :
	    cout<<" Invalid number ";	}
	
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
	
	file.open("data.csv",ios ::out| ios ::app);
	file<<PhoneNo<<","<<Name<<","<<Address<<","<<Description<<endl;
	file.close();
}
void Start :: ShowAll(){
	
	file.open("data.csv",ios :: in);
	
	getline(file,PhoneNo,',');
	getline(file,Name,',');
	getline(file,Address,',');
	getline(file,Description,'\n');
	 
	 while(!file.eof()){
	 	cout<<"Phone Number :: "<<PhoneNo<<endl;
	 	cout<<"Name :: "<<Name<<endl;
	 	cout<<"Phone Address :: "<<Address<<endl;
	 	cout<<"Phone Description :: "<<Description<<endl;
	 	
	    getline(file,PhoneNo,',');
	    getline(file,Name,',');
	    getline(file,Address,',');
	    getline(file,Description,'\n');
	    cout<<endl;
	 }
	 file.close();
	
}
void Start :: SearchContact(){
	
	cout<<"Enter Phone Number :: ";
	getline(cin,Search);
	
	file.open("data.csv",ios :: in);
	
	getline(file,PhoneNo,',');
	getline(file,Name,',');
	getline(file,Address,',');
	getline(file,Description,'\n');
	 
	 while(!file.eof()){
	 	if(PhoneNo == Search){
		 
	 	cout<<"Phone Number :: "<<PhoneNo<<endl;
	 	cout<<"Name :: "<<Name<<endl;
	 	cout<<"Phone Address :: "<<Address<<endl;
	 	cout<<"Phone Description :: "<<Description<<endl;}
	 	
	    getline(file,PhoneNo,',');
	    getline(file,Name,',');
	    getline(file,Address,',');
	    getline(file,Description,'\n');
	    cout<<endl;
	 }
	 file.close();
}
void Start::Update(){
	
}
