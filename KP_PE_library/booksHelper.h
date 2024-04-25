#include<iostream>
#include<string>
#include <stack>
using namespace std;

class Book {
private:
    string title;
    stack<string> authors;
    string edition;
    string ISBNnumber;
    string createDate;
    int circulation;
    bool approved;
    string dateApproved;
    double price;

public:
    Book();
    Book(string title, stack<string> authors, string edition, string ISBNnumber,
        string createDate, int circulation, double price);

    string getTitle();
    void setTitle(string newTitle);
    stack<string> getAuthors();
    void setAuthors(stack<string> authors);
    string getEdition();
    void setEdition(string newEdition);
    string getISBNnumber();
    void setISBNnumber(string newISBNnumber);
    string getCreateDate();
    void setCreateDate(string newCreateDate);
    int getCirculation();
    void setCirculation(int newCirculation);
    bool isApproved();
    void setApproved(bool newApproved);
    string getDateApproved();
    void setDateApproved(string newDateApproved);
    double getPrice();
    void setPrice(double newPrice);
    
    // function to predefine << to write book in file
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.title << endl << book.edition << endl << book.ISBNnumber << endl << book.createDate << endl
           << book.circulation << endl << book.approved << endl << book.dateApproved << endl << book.price << endl;
        os << book.authors.size() << endl;
        std::stack<std::string> tempAuthors = book.authors;
        while (!tempAuthors.empty()) {
            os << tempAuthors.top() << endl;
            tempAuthors.pop();
        }
        return os;
    }
    
    // function to predefine >> to read book from file
    friend std::istream& operator>>(std::istream& is, Book& book) {
    	stack<string> readenAuthors;
    	std::getline(is, book.title);
        is >> book.edition >> book.ISBNnumber >> book.createDate
           >> book.circulation >> book.approved >> book.dateApproved >> book.price;
        int authorCount;
        is >> authorCount;
        is.ignore(); // Ignore the newline character
        std::string author;
        for (int i = 0; i < authorCount; i++) {
            //is>>author;
            std::getline(is, author);
            readenAuthors.push(author); 
        }
        book.authors = readenAuthors;
        return is;
    }

    ~Book();
};

class Bookseller {
private:
	string ID;
    string name;
    string address;
    string phone;

public:
    Bookseller();
    Bookseller(string ID, string name, string address, string phone);

	string getID();
    void setID(string ID);
    string getName();
    void setName(string newName);
    string getAddress();
    void setAddress(string newAddress);
    string getPhone();
    void setPhone(string newPhone);
    
    // function to predefine << to write bookseller in file
    friend std::ostream& operator<<(std::ostream& os, const Bookseller& seller) {
        os << seller.ID << endl << seller.name << endl << seller.address << endl << seller.phone << endl;
        return os;
    }

	// function to predefine >> to read bookseller from file
    friend std::istream& operator>>(std::istream& is, Bookseller& seller) {
    	is >> seller.ID;
    	is.ignore(); // Ignore the newline character
    	std::getline(is, seller.name);
    	std::getline(is, seller.address);
        is >> seller.phone;
        is.ignore(); // Ignore the newline character
        return is;
    }

    ~Bookseller();
};

class Order {
private:
    stack<Book> books;
    Bookseller bookseller;
    double totalCost;

public:
    Order();
    Order(stack<Book> books, Bookseller newBookseller);

    stack<Book> getBooks();
    void setBooks(stack<Book> newBooks);
    Bookseller getBookseller();
    void setBookseller(Bookseller newBookseller);
    double getTotalCost();
    void setTotalCost();
    
    // function to predefine << to write order in file
    friend std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << order.totalCost << endl;
        os << order.books.size() << endl;
        std::stack<Book> tempBooks = order.books;
        while (!tempBooks.empty()) {
            os << tempBooks.top();
            tempBooks.pop();
        }
        os << order.bookseller;
        return os;
    }

	// function to predefine >> to read order from file
    friend std::istream& operator>>(std::istream& is, Order& order) {
        is >> order.totalCost;
        int bookCount;
        is >> bookCount;
        stack<Book> readenBooks;
        Book book;
        is.ignore();
        for (int i = 0; i < bookCount; i++) {
        	stack<string> readenAuthors;
        	string title, edition, ISBNnumber, createDate, dateApproved;
			std::getline(is, title);
	    	book.setTitle(title);
		    int circulation;
		    bool approved;
		    double price;
	        is >> edition >> ISBNnumber >> createDate
	           >> circulation >> approved >> dateApproved >> price;
	        book.setEdition(edition);
	        book.setISBNnumber(ISBNnumber);
	        book.setCreateDate(createDate);
	        book.setCirculation(circulation);
	        book.setApproved(approved);
	        book.setDateApproved(dateApproved);
	        book.setPrice(price);
	        int authorCount;
	        is >> authorCount;
	        is.ignore(); // Ignore the newline character
	        std::string author;
	        for (int i = 0; i < authorCount; i++) {
	            std::getline(is, author);
	            readenAuthors.push(author); 
	        }
	        book.setAuthors(readenAuthors);
            readenBooks.push(book);
        }
        order.books = readenBooks;
        Bookseller seller;
        string Id;
        is >> Id;
        seller.setID(Id);
    	is.ignore(); // Ignore the newline character
    	string name, address, phone;
    	std::getline(is, name);
    	std::getline(is, address);
    	seller.setName(name);
    	seller.setAddress(address);
        is >> phone;
        seller.setPhone(phone);
        is.ignore(); // Ignore the newline character
        order.bookseller = seller;
        return is;
    }

    ~Order();
};

void printBooks(stack<Book> booksCopy);
void printBooksellers(stack<Bookseller> booksellersCopy);
void printOrders(stack<Order> ordersCopy);
string returnCurrentDate();
stack<Book> approveBooks (stack<Book> books, int bookNum);
stack<Book> deleteBooks(stack<Book> books, int bookNum);
stack<Bookseller> deleteBooksellers(stack<Bookseller> booksellers, int booksellerNum);
stack<Order> deleteOrders(stack<Order> orders, int orderNum);
