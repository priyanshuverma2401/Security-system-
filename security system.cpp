#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<windows.h>

using namespace std;

int main(){
	
	int a,i=0;
	string name,password0,password1,password2,user,pass,text,old,word1,word2;
	float age;
	string creds[2],cp[2];
	
	cout<<"		SECURITY SYSTEM		"<<endl;
	cout<<"____________________________"<<endl;
	cout<<"|      1. register		   |"<<endl;
	cout<<"|      2. login		       |"<<endl;
	cout<<"|      3. change password   |"<<endl;
	cout<<"|______1. end prgram________|"<<endl<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"enter your choice: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<" ___________________________"<<endl;
				cout<<"|________Register___________|"<<endl;
				cout<<"|___________________________|"<<endl;
				cout<<"Please enter username: ";
				cin>>name;
				cout<<"Please enter password: ";
				cin>>password0;
				cout<<"please enter your age: ";
				cin>>age;
				ofstream of1;
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<"\n";
					of1<<password0;
					cout<<"Registration Successfull"<<endl;
				}
				break;
			}
				
		case 2:{
			i=0;
			cout<<"___________________________________"<<endl;
			cout<<"|----------Log In-----------------|"<<endl;
			cout<<"|_________________________________|"<<endl;
			ifstream of2;
			of2.open("file.txt");
			cout<<"Please enter the username: ";
			cin>>user;
			cout<<"Please enter your password:";
			cin>>pass;
			if(of2.is_open()){
				while(!of2.eof()){
					while(getline(of2,text)){
					istringstream iss(text);
					iss>>word1;
					creds[i]=word1;
					i++;
					}
					if(user==creds[0]&&pass==creds[1]){
						cout<<"--------logIn successfull--------"<<endl<<endl;
						cout<<"details : "<<endl;
						
						cout<<"username: "+name<<endl;
						cout<<"password: "+pass<<endl;
						cout<<"age: "<<age<<endl;
					}
					else{
						cout<<endl<<endl;
						cout<<"incorrect credential\n";
						cout<<" 1. press 2 to login  "<<endl;
						cout<<" 2. press 3 to change password "<<endl;
					}
				}
			}
			break;
		}
		
		case 3:{
			i=0;
			cout<<"------------change password-----------------"<<endl;
			ifstream of0;
			of0.open("file.txt");
			cout<<"Enter old password: ";
			cin>>old;
			if(of0.is_open()){
				while(!of0.eof()){
					while(getline(of0,text)){
						istringstream iss(text);
						iss>>word1;
						cp[i]=word1;
						i++;
					}
					if(old==cp[1]){
						of0.close();
						ofstream of1;
						of1.open("file.txt");
						if(of1.is_open()){
							cout<<"enter your new password: ";
							cin>>password1;
							cout<<"Enter your password again: ";
							cin>>password2;
							if(password1==password2){
								of1<<cp[0]<<"\n";
								of1<<password1;
								cout<<"Password changed successfully."<<endl;
								
							}
							else{
								of1<<cp[0]<<"\n";
								of1<<old;
								cout<<"password do not match"<<endl;
							}
						}
					}
					else{
						cout<<"Please enter a valid pasword: "<<endl;
						break;
						
					}
					
				}
			}
			break;
		}
		
		case 4:{
			cout<<"----------THANK YOU------------"<<endl;
			
			break;
		}
		
		default : 
		cout<<"Please enter a valid choice."<<endl;
	}
}
while(a!=4);
	
	return 0;
}
