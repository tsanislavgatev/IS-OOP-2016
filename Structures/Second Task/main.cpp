#include <iostream>

using namespace std;

struct Person{
    char name[15];
    size_t age;
    int idn[10];
};

struct Student{
    Person per;
    int group;
    int fn;
};

void initPerson(Person &forInit, char name[15], size_t age, int idn[10])
{
    forInit.age = age;
    for(int i = 0; i < 10; i++)
    {
        forInit.idn[i] = idn[i];
    }

    int index = 0;
    while(name[index] != '\0')
    {
        forInit.name[index] = name[index];
        index++;
    }
}

void printPerson(Person &forPrint)
{
    cout << "Age : " << forPrint.age << endl;
    cout << "Name : ";
    int indx = 0;
    while(forPrint.name[indx + 2] != '\0')
    {
        cout << forPrint.name[indx];
        indx++;
    }
    cout << "\nIDN : ";
    for(int i = 0; i < 10; i++)
    {
        cout << forPrint.idn[i];
    }
}

void initStudent(Student &forInit, Person &per, int group, int fn)
{
    forInit.per = per;
    forInit.fn = fn;
    forInit.group = group;
}

void printStudent(Student &forPrint)
{
    cout << "\nAge : " << forPrint.per.age << endl;
    cout << "Name : ";
    int indx = 0;
    while(forPrint.per.name[indx + 2] != '\0')
    {
        cout << forPrint.per.name[indx];
        indx++;
    }
    cout << "\nIDN : ";
    for(int i = 0; i < 10; i++)
    {
        cout << forPrint.per.idn[i];
    }
    cout << "\nGroup : " << forPrint.group << endl;
    cout << "FN : " << forPrint.fn << endl;
}

int main()
{
    int perAge = 18;
    char perName[] = {'a','b','c','d','c','\0'};
    int idn[10] = {9,9,1,2,3,4,5,6,7,4};
    Person test;

    initPerson(test,perName,perAge,idn);

    printPerson(test);

    Student nat;

    initStudent(nat,test,2,54322);

    printStudent(nat);

    return 0;
}

/*
    Ако искате като допълнителна задача, можете да тествате работенето със структури,
    като изкарате всички студенти от дадена група, всички студенти с факултетен номер
    по - голям от дадено число и т.н. Ако има някакви въпроси, пишете ми във фб или мейл.
*/
