#include <iostream>
#include <string>
using namespace std;

// Base class
class Publication
{
protected:
    string title;
    float price;

public:
    // Get publication details
    virtual void getdata()
    {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
    }

    // Display publication details
    virtual void putdata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class: Book
class Book : public Publication
{
private:
    int pageCount;

public:
    void getdata() override
    {
        Publication::getdata();

        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putdata() override
    {
        Publication::putdata();

        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class: Tape
class Tape : public Publication
{
private:
    float playingTime;

public:
    void getdata() override
    {
        Publication::getdata();

        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
    }

    void putdata() override
    {
        Publication::putdata();

        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main()
{
    Book book;
    Tape tape;

    cout << "Enter Book Details" << endl;
    book.getdata();

    cout << "\nEnter Tape Details" << endl;
    tape.getdata();

    cout << "\n===== Book Information =====" << endl;
    book.putdata();

    cout << "\n===== Tape Information =====" << endl;
    tape.putdata();

    return 0;
}