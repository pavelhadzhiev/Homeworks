#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class Book
{
    char* name;
    char* author;
    float price;
    int code;
public:
    Book()
    {
        name = "0";
        author = "0";
        price = 0;
        code = 0;
    }
    Book(char* inName, char* inAuthor, float inPrice, int inCode)
    {
        set_name(inName);
        set_author(inAuthor);
        set_price(inPrice);
        set_code(inCode);
    }
    void set_name(char* inName)
    {
        name = new char[strlen(inName)+1];
        strcpy(name,inName);
    }
    void set_author(char* inAuthor)
    {
        author = new char[strlen(inAuthor)+1];
        strcpy(author,inAuthor);
    }
    void set_price(float inPrice)
    {
        if (inPrice>0) price=inPrice;
        else price = 0;
    }
    void set_code(int inCode)
    {
        if (inCode>=10000 && inCode<=99999) code=inCode;
        else code=0;
    }
    char* get_name()const
    {
        return name;
    }
    char* get_author()const
    {
        return author;
    }
    float get_price()const
    {
        return price;
    }
    int get_code()const
    {
        return code;
    }
    void print()const
    {
        cout << "Name: " << get_name() << endl;
        cout << "Author: " << get_author() << endl;
        cout << "Price: " << setprecision(2) << fixed << get_price() << endl;
        cout << "Code: " << get_code() << endl << endl;
    }
};

void addBook(Book* arr, Book a, int &cnt)
{
    arr[cnt] = a;
    cnt ++;
}

void removeBook(Book* arr, Book a, int &cnt)
{
    bool flag = false;
    for (int i=0; i<cnt; i++)
    {
        if (arr[i].get_code()==a.get_code())
        {
            for (int j=i; j<cnt-1; j++)
            {
                arr[j]=arr[j+1];
            }
            cnt--;
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "The following book has been removed: " << endl;
        a.print(); cout << endl;
    }
    else cout << "No such book was found. " << endl;
}

void sortByPrice(Book* arr, int cnt)
{
    for (int i=0; i<cnt; i++)
    {
        for (int j=i+1; j<cnt; j++)
        {
            if (arr[j].get_price()<arr[i].get_price())
            {
                Book x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }
}

void getByCode(Book* arr, int cnt, int x)
{
    bool flag = false;
    for (int i=0; i<cnt; i++)
    {
        if (arr[i].get_code()==x) {
            cout << "The book with code " << x << " is: " << endl << endl;
            arr[i].print();
            flag=true;
        }
    }
    if (!flag) cout << "No available book with code " << x << ". " << endl << endl;
}

void getByAuthor(Book* arr, int cnt, char* author)
{
    bool flag = false;
    for (int i=0; i<cnt; i++)
    {
        if (strcmp(arr[i].get_author(),author)==0)
        {
            if (!flag) cout << "Available books by " << author << ": " << endl << endl;
            arr[i].print();
            flag = true;
        }
    }
    if (!flag) cout << "No available books by " << author << "." << endl << endl;
}

void printMoreExpensiveThan(Book* arr, int cnt, float price)
{
    bool flag=false;
    for (int i=0; i<cnt; i++)
    {
        if (arr[i].get_price()>price)
        {
            if (!flag) cout << "Available books more expensive than " << price << ": " << endl << endl;
            arr[i].print();
            flag = true;
        }
    }
    if (!flag) cout << "No available books more expensive than " << price << ". " << endl << endl;
}

int main()
{
    Book arr[100];
    int cnt = 0;
    Book a("The Hunger Games", "Suzanne Collins", 19.99, 10001); addBook(arr,a,cnt);
    Book b("Catching Fire", "Suzanne Collins", 14.99, 10002); addBook(arr,b,cnt);
    Book c("Mockingjay", "Suzanne Collins", 24.99, 10003); addBook(arr,c,cnt);
    Book d("East of Eden", "John Steinbeck", 15.00, 10004); addBook(arr,d,cnt);
    Book e("Game of Thrones", "George Martin", 26.00, 10005); addBook(arr,e,cnt);
    sortByPrice(arr,cnt);
    cout << "Available books: " << endl << endl;
    for (int i=0; i<cnt; i++) arr[i].print();
    getByCode(arr,cnt,10003);
    getByCode(arr,cnt,10006);
    getByAuthor(arr,cnt,"Suzanne Collins");
    getByAuthor(arr,cnt,"Michael Jackson");
    printMoreExpensiveThan(arr,cnt,15.00);
    printMoreExpensiveThan(arr,cnt,26.00);
    return 0;
}
