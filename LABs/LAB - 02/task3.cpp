#include<iostream>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<windows.h>

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

void addToStudentBuffered(int N)
{
    ofstream ofs("studentdatabase.txt", ios::binary | ios::out);
    Student *s = new Student[N];

    for (int i = 1; i < N; i++)
    {
        s[i].roll = i;
    }

    ofs.write((char *)(s), N * sizeof(Student));
    ofs.close();

    delete[] s;

}

void addToStudentUnBuffered(int N)
{
    ofstream ofs("studentdatabase.txt", ios::binary | ios::out);
    Student s;

    for (int i = 0; i < N; i++)
    {
        s.roll = i;
        ofs.write((char *)(&s), sizeof(Student));
    }
    ofs.close();

}


int main()
{
    Student s;

    SYSTEMTIME systime;

    cout << "\nWriting Records to File one by one";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    addToStudentUnBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;



    cout << "\nWriting Records to File at once";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    addToStudentBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    return 0;
}