#include <iostream>
#include <string>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    Date(int day = 0, int month = 0, int year = 0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

struct Student
{
    char name[50];
    Date birthDay;
    float label;

    Student(char name[], int day, int month, int year, float label = 0)
    {
        strcpy_s(this->name, name);
        birthDay.day = day;
        birthDay.month = month;
        birthDay.year = year;
        this->label = label;
    }
};

void StudentsSort(Student group[], int size);

int main()
{
    Student bob("Bob", 17, 5, 2001, 11.5);

    bob.birthDay.day = 17;
    bob.birthDay.month = 5;
    bob.birthDay.year = 2001;

    bob.label = 11.5;
    strcpy_s(bob.name, "Bob");

    cout << bob.name << " " << "\n";

    Student* bobPtr = &bob;


    int sizeGroup;
    cout << "Input size of group: ";
    cin >> sizeGroup;

    Student* group = new Student[sizeGroup];

    for (int i = 0; i < 16; i++)
    {
        cout << "Input name " << i + 1 << " student: ";
        cin.getline(group[i].name, 50, ';');

        cout << "Input age: ";
        cin >> group[i].age;

        cout << "Input label: ";
        cin >> group[i].label;
    }


}

void StudentsSort(Student group[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int indexMin = i;
        for (int j = i; j < size; j++)
            if (group[indexMin].age > group[j].age)
                indexMin = j;
        Student temp = group[indexMin];
        group[indexMin] = group[i];
        group[i] = temp;
    }
}