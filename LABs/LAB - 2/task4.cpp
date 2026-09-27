#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct Student
{
    int roll;
    char name[30];
    Student() : roll(0)
    {
        strcpy(name, "none");
    }
};

void readAllRecordsBuffered(int N)
{
    ifstream ofs("studentdatabase.txt", ios::binary | ios::in);
    Student *s = new Student[N];
   
    ofs.read((char *)(s), N * sizeof(Student));
    ofs.close();

    delete[] s;
}

void readAllRecordsUnBuffered(int N)
{
    ifstream ofs("studentdatabase.txt", ios::binary | ios::in);
    Student s;

    for (int i = 0; i < N; i++)
    {
        ofs.read((char *)(&s), sizeof(Student));
        //cout << "Roll no. " << s.roll << "\t" << "Name : " << s.name << endl;

    }
    ofs.close();
}

int main()
{
    Student s;

    SYSTEMTIME systime;
    cout << "\nReading Records From File one by one";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    readAllRecordsUnBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;



    cout << "\nReading Records From File at once";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    readAllRecordsBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    return 0;
}