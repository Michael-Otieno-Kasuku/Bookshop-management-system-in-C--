//C++ program to illustrate bookshop management system using file handling
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//Bookshop class
class bookshope{
	public:
		void control_panel();
		void add_book();
		void show_book();
		void check_book();
		void update_book();
		void del_book();
};
//Function to dispaly menus
void bookshope::control_panel(){
	system("cls");
	cout<<"\n\n\t\t\tMMUST LIBRARY SYSTEM";
	cout<<"\n\n1. ADD BOOK";
	cout<<"\n2. DISPLAY BOOKS AVAILABLE";
	cout<<"\n3. CHECK INDIVIDUAL BOOK";
	cout<<"\n4. UPDATE BOOK INFO";
	cout<<"\n5. DELETE BOOK INFO";
	cout<<"\n6. QUIT";
}

//function to add a book
void bookshope::add_book(){
	system("cls");
	fstream file;
	int no_copy;
	string b_name, a_name, b_id;
	cout<<"\n\n\t\t\t\tADD BOOK";
	cout<<"\n\nBook ID : ";
	cin>>b_id;
	cout<<"\nBook Name : ";
	cin>>b_name;
	cout<<"\nAuthor Name : ";
	cin>>a_name;
	cout<<"\nNo. of Books : ";
	cin>>no_copy;
	//open the file in append or output mode
	file.open("book.txt",ios::out|ios::app);
	file<<" "<<b_id<<" "
	    <<b_name<<" "<<a_name
	    <<" "<<no_copy<<"\n";
	    file.close();
}
//function to display the book
void bookshope::show_book(){
	system("cls");
	fstream file;
	int no_copy;
	string b_name, b_id, a_name;
	cout<<"\n\n\t\t\t\tALL BOOKS";
	//open file in input mode
	file.open("book.txt",ios::in);
	if(!file)
	cout<<"\n\nFile Opening Error!";
	else
	{
		cout<<"\n\n\nBook ID\t\tBook"
		    <<"\t\tAuthor\t\tNo . of "
		      " Books\n\n";
		      file>>b_id>>b_name;
		      file>>a_name>>no_copy;
		      
		      //till end of file is reached
		      while(!file.eof()){
		      cout<<" "<<b_id
		          <<"\t\t"<<b_name
		          <<"\t\t"<<a_name
		          <<"\t\t"<<no_copy
		          <<"\n\n";
		      file>>b_id>>b_name;
		      file>>a_name>>no_copy;
			}
			//close the file
			file.close();
			}
			system("pause");
}
//function to check the book
void bookshope::check_book()
{
	system("cls");
	fstream file;
	int no_copy, count = 0;
	string b_id, b_name, a_name, b_idd;
	cout<<"\n\n\t\tCheck "
	    <<"Particular Book";
		//open file in input mode
		file.open("book.txt", ios::in);
		if(!file)
		cout<<"\n\nFile Openning Error!";
		else
		{
			cout<<"\n\nBook ID : ";
			cin>>b_idd;
			file>>b_idd>>b_name;
			file>>a_name>>no_copy;
			
			while(!file.eof()){
				if(b_idd==b_id){
					system("cls");
					cout<<"\n\n\t\t\t"
					    <<"Check particular Book";
				    cout<<"\n\nBook ID : "
				        <<b_id;
				    cout<<"\nName : "<<b_name;
				    cout<<"\nAuthor : "<<a_name;
				    cout<<"\nNo. of Books : "<<no_copy;
				    cout<<endl<<endl;
				    count++;
				    break;
				}
				file>>b_id>>b_name;
				file>>a_name>>no_copy;
			}
			system("pause");
			file.close();
			if(count==0)
			cout<<"Book ID not found...";
		}
}
//function to update the book
void bookshope::update_book(){
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count=0;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;
	
	cout<<"\n\n\t\t\tUpdate Book Record";
	file1.open("book1.txt",ios::app|ios::out);
	file.open("book.txt",ios::in);
	
	if(!file)
	cout<<"\n\nFile Openning Error!";
	else
	{
		cout<<"\nBook ID : ";
		cin>>b_id;
		file>>b_idd>>b_name;
		file>>a_name>>no_copy;
		//tillend of file is reached
		while(!file.eof()){
			if(b_id==b_idd){
				system("cls");
				cout<<"\t\t\t\tUpdate Book Record";
				cout<<"\n\nNew Book Name : ";
				cin>>b_na;
				cout<<"\nAuthor Name : ";
				cin>>a_na;
				cout<<"\nNo. of Books : ";
				cin>>no_co;
				file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n\n";
				count++;
			}
			else
			file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n\n";
			file>>b_idd>>b_name;
			file>>a_name>>no_copy;
		}
		if(count==0)
		cout<<"\n\nBook ID Not Found....";
	}
	cout<<endl;
	//close the files
	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt","book.txt");
	system("pause");
}
//functio to delete a book
void bookshope::del_book(){
	system("cls");
	fstream file, file1;
	int no_copy, count =0;
	string b_id, b_idd, b_name, a_name;
	cout<<"\n\n\t\t\t\t\tDelete  a book";
	//append a fike in input mode
	file1.open("book1.txt",ios::app|ios::out);
	file.open("book.txt",ios::in);
	if(!file)
	cout<<"\n\nFile opening Error...";
	else
	{
		cout<<"\n\nBook ID : ";
		cin>>b_id;
		file>>b_idd>>b_name;
		file>>b_idd>>b_name;
		file>>a_name>>no_copy;
		while(!file.eof()){
			if(b_id==b_idd){
				system("cls");
				cout<<"\n\n\n\t\t\t\t\t Delete a book\n\n\book is deleted successfully...\n\n";
				count++;
			}
			else
			{
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n\n";
				file>>b_idd>>b_name;
				file>>a_name>>no_copy;
			}
			if(count==0)
			cout<<"\n\nBook ID Not Found...";
		}
		system("pause");
		//colsing the file
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","D://book.txt");
			}
}
//function for book shop record
void bookShopRecord(){
	int choice;
	char x;
	bookshope b;
	while(1){
		b.control_panel();
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				do{
					b.add_book();
					cout<<"\n\nWant to add another book? (y/n) : ";
					cin>>x;
				}while(x=='y');
				break;
			case 2:
				b.show_book();
				break;
			case 3:
				b.check_book();
				break;
			case 4:
				b.update_book();
				break;
			case 5:
				b.del_book();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"\n\nINVALID CHOICE\n";
		}
	}
}
//Driver code
int main()
{
	//Function call
	bookShopRecord();
	
	return 0;
}
