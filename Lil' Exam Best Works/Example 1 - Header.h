struct Animal
{
	char* name;
	unsigned int age;
	unsigned int id;
	bool gender; // True for male
	bool animalType; // True for dogee
	bool isInHotel;
};

void init(Animal &mine, char* name, unsigned int age, unsigned int id, bool animalType, bool gender, bool isInHotel);
void print(Animal &mine);
bool setIsInHotel(Animal &mine,const char YN); // Y for yes, N for no
bool isInHotel(Animal *hotel, unsigned int size,unsigned int id);
void printByName(Animal *hotel, unsigned int size, char* name);
Animal getYoungest(Animal* hotel,unsigned int size, char OY); // O for Oldset Y for youngest
void getCountByGender(Animal *hotel, unsigned int size);
bool setName(Animal &mine, char*nName);
bool setAge(Animal &mine, unsigned int nAge);
bool setId(Animal &mine, unsigned int nId);