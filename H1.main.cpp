#include <iostream>
#include <iomanip>

using namespace std;

struct marksFirstSem
{
    double DIS;
    double LA;
    double UP;
    double DS;
    void read();
    void print()const;
};

struct marksSecondSem
{
    double English;
    double EAI;
    double AG;
    double DIS;
    double OOP;
    void read();
    void print()const;
};

struct student
{
    char name[30];
    int FN;
    int course;
    long long EGN;
    char major[30];
    marksFirstSem first;
    marksSecondSem second;
    void read();
    void print()const;
    double grade()const;
};

struct university
{
    char name[30];
    char address[50];
    student arrayOfStudents[1000];
    int numberOfStudents;
    void read();
    void print()const;
    void addStudent();
    double grade()const;
    void sortByResults();
    void printStudents()const;
    void getStudentInfo();
};

int main()
{
    university a;
    a.read();
    a.addStudent();
    a.sortByResults();
    a.printStudents();
    a.getStudentInfo();
    return 0;
}

void marksFirstSem::read()
{
    cout << "DIS I: "; cin >> DIS;
    cout << "LA: "; cin >> LA;
    cout << "DS: "; cin >> DS;
    cout << "UP: "; cin >> UP;
}

void marksSecondSem::read()
{
    cout << "DIS II: "; cin >> DIS;
    cout << "AG: "; cin >> AG;
    cout << "EAI: "; cin >> EAI;
    cout << "OOP: "; cin >> OOP;
    cout << "English: "; cin >> English;
}

void marksFirstSem::print()const
{
    cout << "DIS I: " << DIS << endl;
    cout << "LA: " << LA << endl;
    cout << "DS: " << DS << endl;
    cout << "UP: " << UP << endl;
}

void marksSecondSem::print()const
{
    cout << "DIS II: " << DIS << endl;
    cout << "AG: " << AG << endl;
    cout << "EAI: " << EAI << endl;
    cout << "OOP: " << OOP << endl;
    cout << "English: " << English << endl;
}

void student::read()
{
    cout << "Student: ";
    cin.getline(name,30);
    cout << "Major: ";
    cin.getline(major,30);
    cout << "Course: ";
    cin >> course;
    cout << "FN: ";
    cin >> FN;
    cout << "EGN: ";
    cin >> EGN;
    cout << "< Marks >" << endl;
    first.read();
    second.read();
}

void student::print()const
{
    cout << "Student: " << name << endl;
    cout << "Major: " << major << endl;
    cout << "Course: " << course << endl;
    cout << "FN: " << FN << endl;
    cout << "EGN: " << EGN << endl;
    cout << "Results: " << setprecision(3) << grade()  << endl;
}

double student::grade()const
{
    return (first.DIS + first.LA + first.DS + first.UP + second.AG + second.DIS + second.EAI +
    second.English + second.OOP)/9;
}

void university::read()
{
    cout << "University: "; cin.getline(name,30);
    cout << "Address: "; cin.getline(address,50);
    cout << "< Enter students > " << endl << endl;
    char check='y';
    numberOfStudents = 0;
    while (check=='Y' || check=='y')
    {
        student a;
        a.read();
        arrayOfStudents[numberOfStudents]=a;
        cout << "Type Y to enter another student or N to stop: "; cin >> check;
        char blabla[10];
        cin.getline(blabla,10); // just to clear line for next getline (need info on how to do this more classy)
        cout << endl;
        numberOfStudents++;
    }
}

void university::print()const

{
    cout << "University: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Number of students: " << numberOfStudents << endl;
    cout << "Average results: " << grade() << endl << endl;
}

double university::grade()const
{
    double sum=0;
    for (int i=0; i<numberOfStudents; i++)
    {
        sum+=arrayOfStudents[i].grade();
    }
    return sum/numberOfStudents;
}

void university::addStudent()
{
    if(numberOfStudents<1000)
    {
        cout << "< Add a student to " << name << " >" << endl;
        arrayOfStudents[numberOfStudents++].read();
    }
    else cout << "No more space in university. ";
}

void university::sortByResults()
{
    for (int i=0; i<numberOfStudents; i++)
    {
        for (int j=i; j<numberOfStudents; j++)
        {
            if (arrayOfStudents[j].grade()>arrayOfStudents[i].grade())
                swap(arrayOfStudents[i],arrayOfStudents[j]);
        }
    }
}

void university::printStudents()const
{
    cout << "< Students in " << name << " >" << endl;
    for (int i=0; i<numberOfStudents; i++)
    {
        arrayOfStudents[i].print();
        cout << endl;
    }
}

void university::getStudentInfo()
{
    int FN;
    cout << "Enter the FN of a student from " << name << ": ";
    cin >> FN; cout << endl;
    for (int i=0; i<numberOfStudents; i++)
    {
        if (arrayOfStudents[i].FN==FN)
        {
            arrayOfStudents[i].print();
            break;
        }
        if (i==numberOfStudents-1)cout << "There is no student from " << name << " with this FN." << endl;
    }
}
