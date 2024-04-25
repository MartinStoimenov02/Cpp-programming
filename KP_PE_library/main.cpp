#include<iostream>
#include <stack>
#include<string>
#include <fstream>
#include <windows.h> 
#include "booksHelper.h"

using namespace std;

int main(){
	//stacks to store all information
	std::stack<Book> books;
    std::stack<Bookseller> booksellers;
    std::stack<Order> orders;

    ifstream bookFile("books.txt");
    ifstream booksellerFile("booksellers.txt");
    ifstream orderFile("orders.txt");

    // Check if the files are open
    if (!bookFile.is_open() || !booksellerFile.is_open() || !orderFile.is_open()) {
    }else{
		// Read Books from the books.txt file
	    Book book;
	    while (bookFile >> book) {
	        books.push(book);
	    }
	
	    // Read Booksellers from the booksellers.txt file
	    Bookseller seller;
	    while (booksellerFile >> seller) {
	        booksellers.push(seller);
	    }
	
	    // Read Orders from the orders.txt file
	    Order order;
	    while (orderFile >> order) {
	        orders.push(order);
	    }
	}

    // Close the input files
    bookFile.close();
    booksellerFile.close();
    orderFile.close();
		
	int command;
	for(;;){
		//main menu
		cout<<endl<<"please choose option:"<<endl;
		cout<<"1 - add book"<<endl;
		cout<<"2 - add bookseller"<<endl;
		cout<<"3 - add order"<<endl;
		cout<<"4 - print all books"<<endl;
		cout<<"5 - print all booksellers"<<endl;
		cout<<"6 - print all orders"<<endl; 
		cout<<"7 - Approve book"<<endl;
		cout<<"0 - exit"<<endl;
		// input command
		do{
			cin>>command;	
		}while(command<0 && command>7);
		
		cout<<endl;
		
		if(command==1){
			//create book obj and add into list
			string title;
			cout<<"title:";
			getline(cin, title);
			getline(cin, title);
			stack<string>authors;
			cout<<"insert authors:"<<endl<<"-To insert next author, just press ENTER!"<<endl<<"-To end insert authors, write 'STOP'!"<<endl;
			string author;
			while(authors.size()==0){
				getline(cin, author);
				while(author!="STOP"){
					authors.push(author);
					getline(cin, author);				
				}
				if(authors.size()==0){
					system("Color CF");
					cout<<"input at least one author!"<<endl;
				}
			}
			system("Color 0F");
			string edition;
			cout<<"edition:";
			cin>>edition;
			string ISBNnumber;
			cout<<"ISBN Nnumber:";
			cin>>ISBNnumber;
			string createDate;
			createDate = returnCurrentDate();
			int circulation;
			cout<<"circulation:";
			cin>>circulation;
			double price;
			cout<<"price:";
			cin>>price;
			Book newBook(title, authors, edition, ISBNnumber, createDate, circulation, price);
			books.push(newBook);
		}else if(command==2){
			//create bookseller obj and add into list
			string Id;
			cout<<"Id: ";
			cin>>Id;
			string name;
			cout<<"name: ";
			getline(cin, name);
			getline(cin, name);
			string address;
			cout<<"address: ";
			getline(cin, address);
			string phone;
			do{
				cout<<"phone number:";
				cin>>phone;
				system("Color CF");
			}while(phone.size()!=10);
			system("Color 0F");
			Bookseller bs(Id, name, address, phone);
			booksellers.push(bs);
		}else if(command==3){
			//create order obj and add into list
			int option;
			int booksell;
			Order newOrder;
			stack<Bookseller> booksellersCoppy;
			Bookseller booksellerOrder;
			Book bookObj;
			for(;;){
				// menu for order
				cout<<"choose option:"<<endl<<"1-choose bookseller;"<<endl<<"2 - choose books;"<<endl<<"10 - save order"<<endl<<"0 - back (without saving!)"<<endl;
				cin>>option;
				if(option == 1){
					// choose bookseller for each order
					booksellersCoppy = booksellers;
					printBooksellers(booksellersCoppy);
					do{
						cout<<"*choose bookseller (by number); if you want to back, choose 0:"<<endl;
						cin>>booksell;
					}while(booksell<0 || booksell>booksellersCoppy.size());
					
					// print warning, that says the order can't be saved without related bookseller
					if(booksell == 0){
						system("Color EC");
						cout<<"warning: you must choose bookseller! You can't save the order without bookseller!"<<endl;
						continue;
					}
					system("Color 0F");

					// get the choosen bookseller
					for(int i = 1; i < booksell; i++){
						booksellersCoppy.pop();
					}
					booksellerOrder = booksellersCoppy.top();
					cout<<"you choose: "<<booksellerOrder.getName()<<endl;
					newOrder.setBookseller(booksellerOrder);
				}
				//choose books for order
				else if(option == 2){
					stack<Book> booksCoppy; // coppy of the original books stack
					stack<Book> newBooks; // books to add in the order
					do{
						cout<<endl;
						printBooks(books);
						cout<<endl;
						// appropriation the original books stack to the coppy of each iteration of the do-while cycle
						booksCoppy = books;
						cout<<"count of choosen books: "<<newBooks.size()<<endl;
						cout<<"choose at least one books (by number); if you want to stop, choose 0: "<<endl;
						cin>>booksell; // input number of book, that you want to add to the order
						// check if the number doesn't exist
						if(booksell<0 || booksell>booksCoppy.size()){
							cout<<"Invalid book number! Try again!"<<endl;
							system("Color CF");
							continue;
						}else if(booksell==0){
							break;
						}
						// iterate over booksCoppy to find the nedded book
						for(int i = 1; i < booksell; i++){
							booksCoppy.pop();
						}
						bookObj = booksCoppy.top();
						// if the book isn't approved, you can't add to the order
						if(bookObj.isApproved()==false){
							system("Color CF");
							cout<<"This book isn't approved! You can't add to your order!"<<endl;
							continue;
						}
						// if book isn't avaible, there is no reasen to add it in order
						if(bookObj.getCirculation()==0){
							system("Color CF");
							cout<<"This book isn't avaible! Availability is 0!"<<endl;
							continue;
						}
						system("Color 0F");
						cout<<"you choose: "<<bookObj.getTitle()<<endl;
						// when you add a book to the order, reduce the circulation
						int circulation = bookObj.getCirculation()-1;
						bookObj.setCirculation(circulation);
						newBooks.push(bookObj);
						
						// clear the bookCoppy stack
						while(!booksCoppy.empty()){
							booksCoppy.pop();
						}
						
						// save the changes of the book in the books stack
						Book b;
						int i = 0;
						while(!books.empty()){
							b = books.top();
							if(i==booksell-1){
								b=bookObj;
							}
							booksCoppy.push(b);
							books.pop();
							i++;
						}
						books = booksCoppy;
					}while(booksell!=0);
					// if you close the 'choose book' menu, without actually choosen books, print warning
					if(newBooks.size()==0){
						system("Color EC");
						cout<<"warning: you must choose at least one book! You can't save the order without books!"<<endl;
					}else{
						system("Color 0F");
					}
					newOrder.setBooks(newBooks);
					
				}else if(option == 10){
					// if you try to save, check if there is books in order
					if(newOrder.getBooks().size()==0){
						system("Color CF");
						cout<<"error saving: you must choose at least one book for each order!"<<endl;
						continue;
					}
					// check if order has bookseller
					if(newOrder.getBookseller().getID()==""){
						system("Color CF");
						cout<<"error saving: you must choose bookseller for each order!"<<endl;
						continue;
					}
					system("Color 0F");
					newOrder.setTotalCost();
					orders.push(newOrder);
					cout<<"order saved succesfully!"<<endl;
					break;
				}else if(option == 0){
					system("Color 0F");
					break;
				}
			}
		}else if(command==4){
			// print all the books
			printBooks(books);
			int command; // to choose if you want to delete some books
			do{
				cout<<"choose option:"<<endl<<"1 - delete a book;"<<endl<<"0 - back;"<<endl;
				cin>>command;
				if(command==1){
					int bookNum;
					// input command in borders
					do{
						cout<<"which book you want to delete?(to back - press 0):";
						cin>>bookNum;
						if(bookNum==0){break;}
					}while(bookNum<0 || bookNum>books.size());
					books = deleteBooks(books, bookNum);
				}
			}while(command!=0);	
		}else if(command==5){ // the same as the command 4 and 6
			printBooksellers(booksellers);
			int command;
			do{
				cout<<"choose option:"<<endl<<"1 - delete a bookseller;"<<endl<<"0 - back;"<<endl;
				cin>>command;
				if(command==1){
					int booksellerNum;
					do{
						cout<<"which bookeller you want to delete?(to back - press 0):";
						cin>>booksellerNum;
						if(booksellerNum==0){break;}
					}while(booksellerNum<0 || booksellerNum>booksellers.size());
					booksellers = deleteBooksellers(booksellers, booksellerNum);
				}
			}while(command!=0);	
		}else if(command==6){ // the same as the command 4 and 5
			printOrders(orders);
			int command;
			do{
				cout<<"choose option:"<<endl<<"1 - delete a order;"<<endl<<"0 - back;"<<endl;
				cin>>command;
				if(command==1){
					int orderNum;
					do{
						cout<<"which order you want to delete?(to back - press 0):";
						cin>>orderNum;
						if(orderNum==0){break;}
					}while(orderNum<0 || orderNum>orders.size());
					orders = deleteOrders(orders, orderNum);
				}
			}while(command!=0);	
		}else if(command==7){ // command to approve books
			int bookNum;
			do{ // input book number, while it isn't correct (in the border of the stack)
				printBooks(books);
				cout<<"which book you want to aprove(to back - press 0):";
				cin>>bookNum;
				if(bookNum==0){break;}
			}while(bookNum<0 || bookNum>books.size());
			books = approveBooks(books, bookNum);
		}else if(command == 0){
			break;
		}
	}

	ofstream bookFileOut("books.txt");
    ofstream booksellerFileOut("booksellers.txt");
    ofstream orderFileOut("orders.txt");

    // Check if the files are open
    if (!bookFileOut.is_open() || !booksellerFileOut.is_open() || !orderFileOut.is_open()) {
        cerr << "Error: Unable to open output files." << endl;
        return 1;
    }

    // Write Books to the books.txt file
    while (!books.empty()) {
        bookFileOut << books.top();
        books.pop();
    }

    //Write Booksellers to the booksellers.txt file
    while (!booksellers.empty()) {
        booksellerFileOut << booksellers.top();
        booksellers.pop();
    }

    // Write Orders to the orders.txt file
    while (!orders.empty()) {
        orderFileOut << orders.top();
        orders.pop();
    }

    // Close the output files
    bookFileOut.close();
    booksellerFileOut.close();
    orderFileOut.close();
    
	return 0;
}
