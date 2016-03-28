//Kristin, 71605



#include <iostream>
#include <cstring>

using namespace std;

struct Pet{

	bool type; // kuche - true, kotka - false
	char name[20];
	short int age;
	bool sex; // true - male, false - female
	int counter;
	bool inHotelOrNot;//true - still, false - not in hotel
};

void initPet(Pet &test, bool type, char * name, short int age, bool sex, int number, bool inHotel)
{
	test.type = type;
	strcpy_s(test.name, name);
	test.age = age;
	test.sex = sex;
	test.counter = number;
	test.inHotelOrNot = inHotel;
}

void printPet(Pet test)
{
	cout << test.type << endl;
	cout << test.name << endl;
	cout << test.age << endl;
	cout << test.sex << endl;
	cout << test.counter << endl;
	cout << test.inHotelOrNot << endl;
}

void changeStillInHotel(Pet &test)
{
	if (test.inHotelOrNot)
		test.inHotelOrNot = false;
	else test.inHotelOrNot = true;
}



bool isInHotelOrNot(Pet * hotel, int number)
{
	if (hotel[number].inHotelOrNot)
		return true;
	else
		return false;
}

void toLower(char * str)
{
	int i = 0;
	while (str[i])
	{
		tolower(str[i]);
		i++;
	}

}


void printByName(Pet * hotel, char * nameChoice, int sizeOfHotel)
{
	toLower(nameChoice);

	for (int i = 0; i < sizeOfHotel; i++)
	{
		toLower(hotel[i].name);

		if (strcmp(hotel[i].name, nameChoice) == 0)
			printPet(hotel[i]);
		
	}
}


void searchForYoungestOldest(Pet * hotel, int sizeOfHotel)
{
	int ageYoung = hotel[0].age, ageOld = hotel[0].age;
	int indexYoung = 0, indexOld = 0;

	

	for (int i = 0; i < sizeOfHotel; i++)
	{
		if (isInHotelOrNot(hotel, i))
		{

			if (hotel[i].age < ageYoung)
			{
				ageYoung = hotel[i].age;
				indexYoung = i;
			}

			if (hotel[i].age > ageOld)
			{
				ageOld = hotel[i].age;
				indexOld = i;
			}



		}
		


	}

	cout << "Youngest: " << endl;
	printPet(hotel[indexYoung]);

	cout << "Oldest: " << endl;
	printPet(hotel[indexOld]);

}

void statistics(Pet * hotel, int sizeOfHotel)
{
	int countMDogs = 0, countMCats = 0, countFDogs = 0, countFCats = 0;

	for (int i = 0; i < sizeOfHotel; i++)
	{
		if (hotel[i].type && hotel[i].sex)
			countMDogs++;

		if (hotel[i].type && !hotel[i].sex)
			countFDogs++;

		if (!hotel[i].type && hotel[i].sex)
			countMCats++;

		if (!hotel[i].type && !hotel[i].sex)
			countFCats++;
	}

	cout << "Male dogs: " << countMDogs << endl;
	cout << "Female dogs: " << countFDogs << endl;
	cout << "Male cats: " << countMCats << endl;
	cout << "Female cats: " << countFCats << endl;

}





int main()
{

	Pet first, second, third, forth ;
	initPet(first, true, "Garry", 12, true,0, true);
	initPet(second, true, "Merry", 5, false,1, true);
	initPet(third, false, "Timy", 1, true,2, false);
	initPet(forth, false, "Stela", 15, false,3, true);


	/*
	printPet(first);

	changeStillInHotel(first);

	printPet(first);*/



	int sizeOfHotel = 4;
	Pet * hotel;
	hotel = new Pet[20];

	hotel[0] = first;
	hotel[1] = second;
	hotel[2] = third;
	hotel[2] = forth;

	/*for (int i = 0; i < sizeOfHotel; i++)
	{
		printPet(hotel[i]);

	}
*/
	//cout << isInHotelOrNot(hotel, 3);

	// printByName(hotel, "Merry", sizeOfHotel);
	//searchForYoungestOldest(hotel, sizeOfHotel);


	//statistics(hotel, sizeOfHotel);

	delete[] hotel;
	return 0;
}