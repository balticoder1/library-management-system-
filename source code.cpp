#include<iostream>

using namespace std;
//golobal variables
int bookId[50];
string bookName[50];
int totalBook[50];
int avaibaleBook[50];
int bookCount = 0;

//function dec
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

//main funtion 

int main(){
	int chose;
		
	do{
		cout<<"\n\n\t-----------------------------LIBRARY MANAGEMENT SYSTEM-----------------------------------"<<endl;
		cout<<"\t-----------------------------------------------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"\t1. Student "<<endl;
		cout<<"\t-----------------------------------------------------------------------------------------"<<endl;
		cout<<"\t2. Administrator"<<endl;
		cout<<"\t-----------------------------------------------------------------------------------------"<<endl;
		cout<<"\t3. Exit"<<endl;
		cout<<"\t-----------------------------------------------------------------------------------------"<<endl;
		cout<<"\tenter your chose : ";
		cin>>chose;
		
		//-------------------student ---------------
		
		if(chose == 1){
			int Schose;
			do{
				cout<<endl<<"\t---------------------------------STUDENT MENU -------------------------------------------"<<endl;
				cout<<"\t1. View All Books "<<endl;
				cout<<"\t2. Search Book (by ID)"<<endl;
				cout<<"\t3. Issue a Book "<<endl;
				cout<<"\t4. Return a Book "<<endl;
				cout<<"\t0. Back to Main Menu "<<endl;
				cout<<"\tenter your chose : ";
				cin>>Schose;
				
				if(Schose == 1){
					displayBooks();
				}
				else if(Schose == 2){
					searchBook();	
				}else if(Schose == 3){
					issueBook();
				}
				else if(Schose == 4){
					returnBook();
				}
				else if(Schose == 0){
					break;
				}
				else {
					cout<<"\ninvalid chose , try agin"<<endl;
				}
				
			}while(Schose != 0);
		}
		
		//-----------------admin---------------
		else if(chose == 2){
			int Achose;
			do{
				cout<<endl<<"\t--------------------------------ADMINISTRATOR MENU ------------------------------------"<<endl;
				cout<<"\t1. Add New Book"<<endl;
				cout<<"\t2. Display All Books"<<endl;
				cout<<"\t0. Back to Main Menu"<<endl;
				cout<<"\tenter your chose : ";
				cin>>Achose;
				
				if(Achose == 1){
					addBook();
				}
				else if(Achose == 2){
					displayBooks();
				}
				else if(Achose == 0){
					break;
				}
				else{
					cout<<"\tinvalid chose, try again "<<endl;
				}
				
			}while(Achose != 0);
		}
		else if(chose == 3){
			cout<<"\texiting the programme";
			break;
		}
		else{ 
			cout<<"\tinvalid chose , try again "<<endl<<endl;
		}
		
	}while(true);
	
	return 0; 
}//main funtion end here




void addBook(){
	cout<<"\n\tenter a book Id :";
	cin>>bookId[bookCount];
	cout<<"\tenter book name : ";
	cin.ignore();
	getline(cin,bookName[bookCount]);
	cout<<"\tenter total number of book :";
	cin>>totalBook[bookCount];
	
	avaibaleBook[bookCount] = totalBook[bookCount];

    bookCount++;
    cout << "\n\tBook added successfully!" << endl;
}

void displayBooks(){
	if(bookCount == 0){
		cout<<"\n\tAt this Time , no books found in library "<<endl<<endl;
	}
	cout<<"\n\tBook Id \tName \tTotalBook\tAviable Book"<<endl;
	
	for( int i = 0; i < bookCount; i++){
		cout<<"\t "<<bookId[i]<<"\t\t "<<bookName[i]<<"\t\t "<<totalBook[i]<<"\t "<<avaibaleBook[i]<<endl;
	}
}

void searchBook(){
	int searchId;
	cout<<"\n\tenter a Book Id to search : ";
	cin>>searchId; //set the target
	
	for(int i = 0; i < bookCount; i++){
		if(bookId[i] == searchId){
			cout<<"\n\t book found: "<<bookId[i]<<" aviable "<<bookName[i]<<" "<<avaibaleBook[i]<<" "<<endl;
			
			return;
		}
	}
	
	cout<<"\n\tbook not fount "<<endl;
}


void issueBook(){
    int searchId;
    cout << "\tEnter Book ID to issue: ";
    cin >> searchId;//target

    for(int i = 0; i < bookCount; i++){
        if(bookId[i] == searchId){
            if(avaibaleBook[i] > 0){
                avaibaleBook[i]--;
                cout << "\tBook issued successfully!" << endl;
            } else {
                cout << "\tNo copies available." << endl;
            }
            return;
        }
    }

    cout << "\tBook not found." << endl;
}


void returnBook(){
    int searchId;
    cout << "\tEnter Book ID to return: ";
    cin >> searchId;

    for(int i = 0; i < bookCount; i++){
        if(bookId[i] == searchId){
            avaibaleBook[i]++;
            cout << "\tBook returned successfully!" << endl;
            return;
        }
    }

    cout << "\tBook not found." << endl;
} 

//coder = Mubashir




