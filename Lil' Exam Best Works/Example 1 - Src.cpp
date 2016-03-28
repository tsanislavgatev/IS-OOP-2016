#include <iostream>
#include "Header.h"
#include <string.h>
using namespace std;

void init(Animal &mine, char* name, unsigned int age, unsigned int id, bool animalType, bool gender, bool isInHotel)
{
	setName(mine, name);
	setAge(mine, age);
	setId(mine, id);
	mine.animalType = animalType;
	mine.gender = gender;
	mine.isInHotel = isInHotel;
}
void print(Animal &mine)
{
	cout << "Name : " <<  mine.name << endl;
	cout << "Age : " << mine.age << endl;
	cout << "Identification number : " << mine.id << endl;
	if (mine.animalType == true)
		cout << "Animal Type : Dog" << endl;
	else
		cout << "Animal Type : Cat" << endl;
	if (mine.gender == true)
		cout << " Gender : Male" << endl;
	else
		cout << " Gender : Male" << endl;
	if (mine.isInHotel == true)
		cout << mine.name <<" is in the hotel " << endl;
	else
		cout << mine.name << " is NOT in the hotel " << endl;
}
bool setIsInHotel(Animal &mine,const char YN)
{
	if (YN == 'Y' && YN == 'y')
	{
		mine.isInHotel = true;
		return true;
	}
	else if (YN == 'N' && YN == 'n')
	{
		mine.isInHotel = false;
		return true;
	}
	else
		cout << "Invalid input" << endl;
		return false;
}
bool isInHotel(Animal *hotel, unsigned int size, unsigned int id)
{
	for (int i = 0; i < size; i++)
	{
		if (hotel[i].id == id)
		{
			return hotel[i].isInHotel;
		}
	}
	return false;
}
void printByName(Animal *hotel, unsigned int size, char* name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(hotel[i].name, name) == 0)
		{
			print(hotel[i]);
		}
	}
}
Animal getYoungest(Animal* hotel, unsigned int size, char OY)
{
	if (OY == 'Y' && OY == 'y')
	{
		unsigned int temp = hotel[0].age;
		int idx = 0;
		for (int i = 1; i < size; i++)
		{
			if (hotel[i].age < temp)
			{
				temp = hotel[i].age;
				idx = i;
			}
		}
		return hotel[idx];
	} 
	else if (OY == 'O' && OY == 'o')
	{
		unsigned int temp = hotel[0].age;
		int idx = 0;
		for (int i = 1; i < size; i++)
		{
			if (hotel[i].age < temp)
			{
				temp = hotel[i].age;
				idx = i;
			}
		}
		return hotel[idx];
	}
	else
	{
		cout << "Incorect input" << endl;
		return hotel[0];
	}
}
void getCountByGender(Animal *hotel, unsigned int size)
{
	int maleKitty = 0;
	int femaleKitty = 0;
	int maleDogge = 0;
	int femaleDogge = 0;
	for (int i = 0; i < size; i++)
	{
		if (hotel[i].gender == true && hotel[i].animalType == true)
			maleDogge += 1;
		else if (hotel[i].gender == true && hotel[i].animalType == false)
			femaleDogge += 1;
		else if (hotel[i].gender == false && hotel[i].animalType == true)
			maleKitty += 1;
		else
			femaleKitty;
	}
	cout << "There are " << femaleDogge << "female and " << maleDogge << "male dogge(s)" << endl;
	cout << "Ima " << femaleKitty << "MALKI KOTETA i " << maleKitty << " kotaraka" << endl;
}
bool setName(Animal &mine, char*nName)
{
	if (nName != NULL)
	{
		mine.name = new char[strlen(nName) + 1];
		strcpy(mine.name, nName);
		return true;
	}
	else
		return false;
}
bool setAge(Animal &mine, unsigned int nAge)
{
	if (nAge > 0 && nAge < 20)
	{
		mine.age = nAge;
		return true;
	}
	else
		return false;
}
bool setId(Animal &mine, unsigned int nId)
{
	if (nId > 0 && nId < 21)
	{
		mine.id = nId;
		return true;
	}
	else
		return false;
}