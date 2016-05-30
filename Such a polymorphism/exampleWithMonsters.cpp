#include <iostream>

class Monster
{
    public:
        virtual void attack()
        {
            std::cout << "Monster attacked you " << std::endl;
        }
};

class Troll: public Monster
{
    public:
        void attack()
        {
            std::cout << "Troll attacked you" << std::endl;
        }
};

class Orc: public Monster
{
    public:
        void attack()
        {
            std::cout << "Orc attacked you" << std::endl;
        }
};

class Goblin: public Monster
{
};

int main( )
{
    Monster** arrOfMonsters = new Monster*[5];

    Orc theBadOne;
    Orc epicOrc;
    Goblin doucheGoblin;
    Troll iTroll;
    Troll niceHuh;

    arrOfMonsters[0] = &theBadOne;
    arrOfMonsters[1] = &epicOrc;
    arrOfMonsters[2] = &doucheGoblin;
    arrOfMonsters[3] = &iTroll;
    arrOfMonsters[4] = &niceHuh;

    for(int i = 0; i < 5; i++)
    {
        arrOfMonsters[i]->attack();
    }

    return 0;
}