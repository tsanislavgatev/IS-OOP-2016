// FN: 71638

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 20;

struct Pet
{
    bool kind; // True - dog, False - cat
    char name[20];
    int age;
    bool sex; // True - male, False - female
    int number;
    bool in_hotel;

    void print ();
    void changeStatus ();
};

class Hotel
{
  private:

    Pet* hotel;
    int current;

  public:

      Hotel ()
      {
          hotel = new Pet[MAX_SIZE];
          current = 0;
      }

      ~Hotel ()
      {
          delete [] hotel;
      }

      void addAnimal (Pet);
      bool checkByNumber (int);
      void printByName (const char* );
      void printOldestYoungest ();
      void statSex ();
      bool isHotelFull ();
};

Pet init_animal (bool kind, const char* name, int age, bool sex, int number, bool in_hotel);


int main()
{
    Hotel hotel;

    Pet a = init_animal (true, "Sharo",5,true,0,true);
    Pet b = init_animal (false, "Mariika",10,false,1,true);
    Pet c = init_animal (false, "Alex",3,false,2,false);
    Pet d = init_animal (true, "Pepi",18,false,3,true);

    //a.changeStatus ();

    hotel.addAnimal (a);
    hotel.addAnimal (b);
    hotel.addAnimal (c);
    hotel.addAnimal (d);

    //cout << hotel.isHotelFull () << endl;
    //hotel.statSex ();
    //hotel.printByName ("Sharo");
    //hotel.printOldestYoungest ();
    //cout << hotel.checkByNumber (6);


    return 0;
}

Pet init_animal (bool kind, const char* name, int age, bool sex, int number, bool in_hotel)
{
    Pet temp;

    temp.kind = kind;
    strcpy (temp.name,name);
    temp.age = age;
    temp.sex = sex;
    temp.number = number;
    temp.in_hotel = in_hotel;

    return temp;
}

void Hotel :: addAnimal (Pet a)
{
    if (isHotelFull())
        return;

    hotel[current] = a;
    ++current;
}

void Pet :: print ()
{
    cout << "Kind: "; (kind) ? cout << "dog\n" : cout << "cat\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years old\n";
    cout << "Sex: "; (sex) ? cout << "male\n" : cout << "female\n";
    cout << "Number: " << number << endl;
    cout << "In hotel: "; (in_hotel) ? cout << "True\n" : cout << "False\n";
}

void Pet :: changeStatus ()
{
    if (in_hotel)
        in_hotel = false;

    else
        in_hotel = true;
}

bool Hotel :: checkByNumber (int num)
{
    for (int i = 0; i < current; ++i)

        if (hotel[i].number == num)
            return hotel[i].in_hotel;

    return false;
}

void Hotel :: printByName (const char* name)
{
    for (int i = 0; i < current; ++i)

        if (!strcmp (hotel[i].name, name))
            hotel[i].print ();
}

void Hotel :: printOldestYoungest ()
{
    Pet old = hotel[0];

    for (int i = 1; i < current; ++i)

        if (hotel[i].age > old.age)
            old = hotel[i];

    Pet young = hotel[0];

    for (int i = 1; i < current; ++i)

        if (hotel[i].age < young.age)
            young = hotel[i];

    cout << "The oldest animal is:\n"; old.print ();
    cout << endl;
    cout << "The youngest animal is:\n"; young.print ();
}

void Hotel :: statSex ()
{
    int male_dog = 0, female_dog = 0, male_cat = 0, female_cat = 0;

    for (int i = 0; i < current; ++i)
    {
        if (hotel[i].in_hotel)
        {
            if (hotel[i].sex && hotel[i].kind)
                ++male_dog;
            else if (hotel[i].sex && !hotel[i].kind)
                ++male_cat;
            else if (!hotel[i].sex && hotel[i].kind)
                ++female_dog;
            else
                ++female_cat;
        }
    }

    cout << "There are " << male_dog << " male and " << female_dog << " female dogs in the hotel\n";
    cout << "There are " << male_cat << " male and " << female_cat << " female cats in the hotel!\n";
}

bool Hotel :: isHotelFull ()
{
    if (current < MAX_SIZE)
        return false;
    return true;
}
