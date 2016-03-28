#include <iostream>
#include <string.h>
#include "Header.h"
using namespace std;
int main()
{
	Animal mine;
	Animal* hotel;
	int size = 3;
	hotel = new Animal[size];
	char name[20] = { 'Iva' };
	bool gender;
	bool animalType;
	bool inHotel;
	unsigned int age;
	unsigned int id;
	char* nName;
	char flag;
	nName = new char[strlen(name) + 1];
	strcpy(nName, name);
	
	
	for (int i = 0; i < size; i++)
	{
		cout << "Enter age" << endl;
		cin >> age;
		cout << "Enter ID" << endl;
		cin >> id;

		cout << "Enter M for male and F for femalse" << endl;
		cin >> flag;
		if (flag == 'M' && flag == 'm')
		{
			gender = true;
		}
		else if (flag == 'F' && flag == 'f')
		{
			gender = false;
		}
		else
			cout << "OK" << endl;

		cout << "Enter D for Dogge and P for ..  Kitty" << endl;
		cin >> flag;
		if (flag == 'D' && flag == 'd')
		{
			animalType = true;
		}
		else if (flag == 'F' && flag == 'f')
		{
			animalType = false;
		}
		else
			cout << "OK " << endl;

		cout << "Enter Y for pet in hotel and N for pet not in hotel" << endl;
		cin >> flag;
		if (flag == 'Y' && flag == 'y')
		{
			inHotel = true;
		}
		else if (flag == 'N' && flag == 'n')
		{
			inHotel = false;
		}
		else
			cout << "OK " << endl;
		init(hotel[i], nName, age, id, animalType, gender, inHotel);
		print(hotel[i]);
	}


	for (int i = 0; i < size; i++)
	{
		delete[] hotel[i].name;
	}
	delete[] hotel; 
	delete[] nName;
	return 0;
}