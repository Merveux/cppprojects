
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// =====================================
// 1. BOOK CLASS
// =====================================

class Book {

public:

    // Different book genres
    enum Genre {
        fiction,
        nonfiction,
        periodical,
        biography,
        children
    };

private:

    string ISBN;
    string Title;
    string Author;
    int copyright_date;
    bool checked_out;
    Genre genre;


public:

    // Constructor
    Book(string i, string t, string a, int d, Genre g) {
        ISBN = i;
        Title = t;
        Author = a;
        copyright_date = d;
        genre = g;
        checked_out = false;
    }


    // Getters
    string getISBN() {
        return ISBN;
    }

    string getTitle() {
        return Title;
    }

    string getAuthor() {
        return Author;
    }

    int getCopyrightDate() {
        return copyright_date;
    }

    bool isCheckedOut() {
        return checked_out;
    }

    Genre getGenre() {
        return genre;
    }


    // Check out a book
    void checkOut() {
        if (checked_out == false) {
            checked_out = true;
            cout << "Book checked out successfully." << endl;
        }
        else {
            cout << "Book is already checked out." << endl;
        }
    }


    // Check in a book
    void checkIn() {
        if (checked_out == true) {
            checked_out = false;
            cout << "Book checked in successfully." << endl;
        }
        else {
            cout << "Book is not checked out." << endl;
        }
    }


    // Overload == operator
    bool operator==(Book b) {
        return ISBN == b.ISBN;
    }


    // Overload != operator
    bool operator!=(Book b) {
        return ISBN != b.ISBN;
    }


    // Convert genre into text
    string displayGenre() {

        if (genre == fiction) {
            return "Fiction";
        }
        else if (genre == nonfiction) {
            return "Nonfiction";
        }
        else if (genre == periodical) {
            return "Periodical";
        }
        else if (genre == biography) {
            return "Biography";
        }
        else {
            return "Children";
        }
    }


    // Overload << operator
    friend ostream& operator<<(ostream& out, Book b) {

        out << "Title: " << b.Title << endl;
        out << "Author: " << b.Author << endl;
        out << "ISBN: " << b.ISBN << endl;
        out << "Genre: " << b.displayGenre() << endl;

        return out;
    }

};


// =====================================
// 2. PATRON CLASS
// =====================================

class Patron {

private:

    string username;
    string card_number;
    int owed_fees;


public:

    // Constructor
    Patron(string u, string c, int f) {
        username = u;
        card_number = c;
        owed_fees = f;
    }


    // Getters
    string getUsername() {
        return username;
    }

    string getCardNumber() {
        return card_number;
    }

    int getOwedFees() {
        return owed_fees;
    }


    // Check if patron owes fees
    bool owesFees() {
        if (owed_fees > 0) {
            return true;
        }
        else {
            return false;
        }
    }


    // Setter for fees
    void setFees(int f) {
        owed_fees = f;
    }

};


// =====================================
// 3. TRANSACTION CLASS
// =====================================

class Transaction {

private:

    Book book;
    Patron patron;
    string activity;
    string date;


public:

    // Constructor
    Transaction(Book b, Patron p, string a, string d)
        : book(b), patron(p), activity(a), date(d) {
    }


    // Display transaction
    void display() {

        cout << "\nTransaction Details" << endl;

        cout << book;

        cout << "Patron: " << patron.getUsername() << endl;
        cout << "Activity: " << activity << endl;
        cout << "Date: " << date << endl;
    }

};


// =====================================
// 4. LIBRARY CLASS
// =====================================

class Library {

private:

    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;


public:

    // Add a book
    void addBook(Book b) {

        // Prevent duplicate ISBNs
        for (int i = 0; i < books.size(); i++) {

            if (books[i] == b) {
                cout << "Book already exists." << endl;
                return;
            }
        }

        books.push_back(b);

        cout << "Book added successfully." << endl;
    }


    // Add a patron
    void addPatron(Patron p) {

        // Prevent duplicate card numbers
        for (int i = 0; i < patrons.size(); i++) {

            if (patrons[i].getCardNumber() == p.getCardNumber()) {
                cout << "Patron already exists." << endl;
                return;
            }
        }

        patrons.push_back(p);

        cout << "Patron added successfully." << endl;
    }


    // Check out a book
    void checkOutBook(string isbn, string card, string date) {

        int bookIndex = -1;
        int patronIndex = -1;


        // Find the book
        for (int i = 0; i < books.size(); i++) {

            if (books[i].getISBN() == isbn) {
                bookIndex = i;
            }
        }


        // Find the patron
        for (int i = 0; i < patrons.size(); i++) {

            if (patrons[i].getCardNumber() == card) {
                patronIndex = i;
            }
        }


        // Check if book exists
        if (bookIndex == -1) {
            cout << "Error: Book not found." << endl;
            return;
        }


        // Check if patron exists
        if (patronIndex == -1) {
            cout << "Error: Patron not found." << endl;
            return;
        }


        // Check if patron owes fees
        if (patrons[patronIndex].owesFees() == true) {
            cout << "Error: Patron owes library fees." << endl;
            return;
        }


        // Check if book is already checked out
        if (books[bookIndex].isCheckedOut() == true) {
            cout << "Error: Book is already checked out." << endl;
            return;
        }


        // Create transaction
        Transaction t(books[bookIndex], patrons[patronIndex],
                      "Check Out", date);

        transactions.push_back(t);


        // Check out the book
        books[bookIndex].checkOut();

    }


    // Check in a book
    void checkInBook(string isbn, string card, string date) {

        int bookIndex = -1;
        int patronIndex = -1;


        // Find the book
        for (int i = 0; i < books.size(); i++) {

            if (books[i].getISBN() == isbn) {
                bookIndex = i;
            }
        }


        // Find the patron
        for (int i = 0; i < patrons.size(); i++) {

            if (patrons[i].getCardNumber() == card) {
                patronIndex = i;
            }
        }


        if (bookIndex == -1) {
            cout << "Error: Book not found." << endl;
            return;
        }


        if (patronIndex == -1) {
            cout << "Error: Patron not found." << endl;
            return;
        }


        if (books[bookIndex].isCheckedOut() == false) {
            cout << "Error: Book is not checked out." << endl;
            return;
        }


        // Create transaction
        Transaction t(books[bookIndex], patrons[patronIndex],
                      "Check In", date);

        transactions.push_back(t);


        // Check in the book
        books[bookIndex].checkIn();

    }


    // Return names of patrons who owe fees
    vector<string> getPatronsWithFees() {

        vector<string> names;


        for (int i = 0; i < patrons.size(); i++) {

            if (patrons[i].owesFees() == true) {

                names.push_back(patrons[i].getUsername());

            }
        }

        return names;
    }


    // Display all books
    void displayBooks() {

        cout << "\nLIBRARY BOOKS" << endl;

        for (int i = 0; i < books.size(); i++) {

            cout << books[i];

            if (books[i].isCheckedOut() == true) {
                cout << "Status: Checked Out" << endl;
            }
            else {
                cout << "Status: Available" << endl;
            }

            cout << endl;
        }
    }


    // Display all transactions
    void displayTransactions() {

        for (int i = 0; i < transactions.size(); i++) {

            transactions[i].display();

        }
    }

};


// =====================================
// MAIN FUNCTION
// =====================================

int main() {

    // Create library
    Library library;


    // Create books using the different genres
    Book b1("101", "Things Fall Apart",
            "Chinua Achebe", 1958, Book::fiction);

    Book b2("102", "Introduction to C++",
            "Bjarne Stroustrup", 2013, Book::nonfiction);

    Book b3("103", "National Geographic",
            "Various Authors", 2024, Book::periodical);

    Book b4("104", "The Life of Mandela",
            "John Smith", 2020, Book::biography);

    Book b5("105", "Fairy Tales",
            "Charles Perrault", 2022, Book::children);


    // Add books to library
    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);
    library.addBook(b4);
    library.addBook(b5);


    // Create patrons
    Patron p1("Alice", "001", 0);
    Patron p2("Bob", "002", 100);
    Patron p3("Charlie", "003", 0);


    // Add patrons to library
    library.addPatron(p1);
    library.addPatron(p2);
    library.addPatron(p3);


    // Display books
    library.displayBooks();


    // Test checkout
    cout << "\n--- CHECKOUT TEST ---" << endl;

    library.checkOutBook("101", "001", "21/11/2026");

    // Bob cannot check out because he owes fees
    library.checkOutBook("102", "002", "21/11/2026");


    // Test check-in
    cout << "\n--- CHECK-IN TEST ---" << endl;

    library.checkInBook("101", "001", "22/11/2026");


    // Display transactions
    cout << "\n--- TRANSACTIONS ---" << endl;

    library.displayTransactions();


    // Display patrons who owe fees
    cout << "\n--- PATRONS WHO OWE FEES ---" << endl;

    vector<string> names = library.getPatronsWithFees();

    for (int i = 0; i < names.size(); i++) {

        cout << names[i] << endl;

    }


    return 0;
}
