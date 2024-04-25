#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h> 
#include "booksHelper.h"
using namespace std;

Book::Book() {}

Book::Book(string title, stack<string> authors, string edition, string ISBNnumber,
           string createDate, int circulation, double price) {
    setTitle(title);
    setAuthors(authors);
    setEdition(edition);
    setISBNnumber(ISBNnumber);
    setCreateDate(createDate);
    setCirculation(circulation);
    setPrice(price);
    setApproved(false);
    setDateApproved("notApproved!");
}

string Book::getTitle() {
    return title;
}

void Book::setTitle(string newTitle) {
    title = newTitle;
}

stack<string> Book::getAuthors() {
    return authors;
}

void Book::setAuthors(stack<string> authors) {
    this->authors = authors;
}

string Book::getEdition() {
    return edition;
}

void Book::setEdition(string newEdition) {
    edition = newEdition;
}

string Book::getISBNnumber() {
    return ISBNnumber;
}

void Book::setISBNnumber(string newISBNnumber) {
    ISBNnumber = newISBNnumber;
}

string Book::getCreateDate() {
    return createDate;
}

void Book::setCreateDate(string newCreateDate) {
    createDate = newCreateDate;
}

int Book::getCirculation() {
    return circulation;
}

void Book::setCirculation(int newCirculation) {
    circulation = newCirculation;
}

bool Book::isApproved() {
    return approved;
}

void Book::setApproved(bool newApproved) {
    approved = newApproved;
}

string Book::getDateApproved() {
    return dateApproved;
}

void Book::setDateApproved(string newDateApproved) {
    dateApproved = newDateApproved;
}

double Book::getPrice() {
    return price;
}

void Book::setPrice(double newPrice) {
    price = newPrice;
}

Book::~Book() {}

Bookseller::Bookseller() {}

Bookseller::Bookseller(string ID, string name, string address, string phone) {
    setID(ID);
	setName(name);
    setAddress(address);
    setPhone(phone);
}

string Bookseller::getID() {
    return this->ID;
}

void Bookseller::setID(string ID) {
    this->ID = ID;
}

string Bookseller::getName() {
    return name;
}

void Bookseller::setName(string newName) {
    name = newName;
}

string Bookseller::getAddress() {
    return address;
}

void Bookseller::setAddress(string newAddress) {
    address = newAddress;
}

string Bookseller::getPhone() {
    return phone;
}

void Bookseller::setPhone(string newPhone) {
    phone = newPhone;
}

Bookseller::~Bookseller() {}

Order::Order() {}

Order::Order(stack<Book> books, Bookseller newBookseller) {
    setBooks(books);
    setBookseller(newBookseller);
}

stack<Book> Order::getBooks() {
    return books;
}

void Order::setBooks(stack<Book> newBooks) {
    this->books = newBooks;
}

Bookseller Order::getBookseller() {
    return bookseller;
}

void Order::setBookseller(Bookseller newBookseller) {
    bookseller = newBookseller;
}

double Order::getTotalCost() {
    return totalCost;
}

void Order::setTotalCost() {
    stack<Book> insertedBooks = getBooks();
    double sum = 0;
    while (!insertedBooks.empty()) {
        Book b = insertedBooks.top();
        sum += b.getPrice();
        insertedBooks.pop();
    }
    totalCost = sum;
}

Order::~Order() {}

// function to print books
void printBooks(stack<Book> booksCopy) {
    int cnt = 1;
    Book printBook;
    stack<string> authors;
    while (!booksCopy.empty()) {
        cout << cnt << ":" << endl;
        printBook = booksCopy.top();
        cout << "title:" << printBook.getTitle() << endl;
        authors = printBook.getAuthors();
        while (!authors.empty()) {
            cout << "author:" << authors.top() << endl;
            authors.pop();
        }
        cout << "edition:" << printBook.getEdition() << endl;
        cout << "ISBNnumber:" << printBook.getISBNnumber() << endl;
        cout << "createDate:" << printBook.getCreateDate() << endl;
        cout << "circulation:" << printBook.getCirculation() << endl;
        cout << "approved:" << printBook.isApproved() << endl;
        cout << "date approved:" << printBook.getDateApproved() << endl;
        cout << "price: " << printBook.getPrice() << " lv." << endl << endl;
        booksCopy.pop();
        cnt++;
    }
}

// function to print booksellers
void printBooksellers(stack<Bookseller> booksellersCopy) {
    int cnt = 1;
    Bookseller printBookseller;
    while (!booksellersCopy.empty()) {
        cout << cnt << ":" << endl;
        printBookseller = booksellersCopy.top();
        cout << "ID:" << printBookseller.getID() << endl;
        cout << "name:" << printBookseller.getName() << endl;
        cout << "address:" << printBookseller.getAddress() << endl;
        cout << "phone number:" << printBookseller.getPhone() << endl << endl;
        booksellersCopy.pop();
        cnt++;
    }
}

// function to print orders
void printOrders(stack<Order> ordersCopy) {
    int cnt = 1;
    Order printOrder;
    while (!ordersCopy.empty()) {
        cout << "order No: " << cnt << ":" << endl;
        printOrder = ordersCopy.top();

        stack<Bookseller> printBookseller;
        cout << "Bookseller " << cnt << ".";
        printBookseller.push(printOrder.getBookseller());
        printBooksellers(printBookseller);

        cout << "books:" << endl;
        printBooks(printOrder.getBooks());

        cout << "total price:" << printOrder.getTotalCost() << " lv." << endl;

        cout << endl << endl << "-----------------------" << endl << endl;
        ordersCopy.pop();
        cnt++;
    }
}

string returnCurrentDate(){
	// Get the current time
    std::time_t now = std::time(0);

    // Convert the current time to a tm struct
    std::tm* timeinfo = std::localtime(&now);

    // Extract and print the components of the date
    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon + 1;  // Months are 0-based
    int day = timeinfo->tm_mday;
    
    std::stringstream dateStream;
    dateStream << day << "-" << month << "-" << year;

    return dateStream.str();
}

// function to approve books
stack<Book> approveBooks (stack<Book> books, int bookNum){
	int i=0;
	stack<Book> coppybooks;
	Book b;
	// iterate over books, to find the book, that you want to approve
	while(!books.empty()){
		b = books.top();
		if(i==bookNum-1){
			if(b.isApproved()==true){
				cout<<"this book is already approved!"<<endl;
			}else{
				b.setApproved(true);
				b.setDateApproved(returnCurrentDate());
				cout<<"you approve this book successfully!"<<endl;
			}
		}
		coppybooks.push(b);
		books.pop();
		i++;
	}
	return coppybooks;
}


stack<Book> deleteBooks(stack<Book> books, int bookNum){
	int i=0;
	stack<Book> coppybooks;
	Book b;
	// iterate over books to find the book that you want to delete
	while(!books.empty()){
		b = books.top();
		// when the iterator 'i' is on the book tha you want to delete, the loop doesn't add this to the new stack
		if(i!=bookNum-1){
			coppybooks.push(b);
		}else{
			cout<<"you delete book "<<b.getTitle()<<" successfully!"<<endl;
		}
		books.pop();
		i++;
	}
	return coppybooks;
}

// the same as the deleteBooks function
stack<Bookseller> deleteBooksellers(stack<Bookseller> booksellers, int booksellerNum){
	int i=0;
	stack<Bookseller> coppybooksellers;
	Bookseller bs;
	while(!booksellers.empty()){
		bs = booksellers.top();
		if(i!=booksellerNum-1){
			coppybooksellers.push(bs);
		}else{
			cout<<"you delete bookseller "<<bs.getName()<<" successfully!"<<endl;
		}
		booksellers.pop();
		i++;
	}
	return coppybooksellers;
}

// the same as the deleteBooks function
stack<Order> deleteOrders(stack<Order> orders, int orderNum){
	int i=0;
	stack<Order> coppyorders;
	Order o;
	while(!orders.empty()){
		o = orders.top();
		if(i!=orderNum-1){
			coppyorders.push(o);
		}else{
			cout<<"you delete order with  "<<o.getBookseller().getName()<<" bookseller successfully!"<<endl;
		}
		orders.pop();
		i++;
	}
	return coppyorders;
}
