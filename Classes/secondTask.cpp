#include <iostream>
#include <cstring>

using namespace std;

struct bankAccount{

    int balance;
    char name[30];

};

void init(bankAccount &accountForInit, int balanceInput,const char* nameInput)
{
    accountForInit.balance = balanceInput;
    size_t len = strlen(nameInput);
    strncpy(accountForInit.name, nameInput, len);
}

class Bank{
    private:
        bankAccount* arrayOfAccounts;
        int countOfAccounts;
        int sizeOfArray;

    public:
        Bank(int n);
        ~Bank();

        void addAccount(bankAccount&);
        void deposit(const char*, int);
        bool withdraw(const char*, int);
        void checkBallance(const char*);
};

Bank::Bank(int n)
{
    sizeOfArray = n;
    countOfAccounts = 0;
    arrayOfAccounts = new bankAccount[sizeOfArray];
}

Bank::~Bank()
{
    delete[] arrayOfAccounts;
}

void Bank::addAccount(bankAccount &forAdd)
{
    if(countOfAccounts == sizeOfArray)
    {
        cout << "You can't add more accounts " << endl;
    }
    else
    {
        arrayOfAccounts[countOfAccounts] = forAdd;
        countOfAccounts++;
    }
}

void Bank::deposit(const char* name, int amountOfMoney)
{
    bool flag = true;
    int len = strlen(name);
    for(int i = 0; i < countOfAccounts; i++)
    {
        if(strncmp(name,arrayOfAccounts[i].name,len) == 0)
        {
            arrayOfAccounts[i].balance += amountOfMoney;
            cout << amountOfMoney << " added to account with name :  " << name << endl;
            flag = false;
        }
    }
    if(flag)
    {
        cout << "There is no account with that name ! " << endl;
    }
}

bool Bank::withdraw(const char* name, int amountOfMoney)
{
    bool flag = true;
    cout << countOfAccounts << endl;
    int len = strlen(name);
    for(int i = 0; i < countOfAccounts; i++)
    {
        if(strncmp(name,arrayOfAccounts[i].name,len) == 0)
        {
            if(amountOfMoney > arrayOfAccounts[i].balance)
            {
                return false;
            }
            arrayOfAccounts[i].balance -= amountOfMoney;
            cout << amountOfMoney << " taken by account with name :  " << name << endl;
            flag = false;
        }
    }
    if(flag)
    {
        cout << "There is no account with that name ! " << endl;
    }

    return true;
}

void Bank::checkBallance(const char* name)
{
    bool flag = true;
    int len = strlen(name);
    for(int i = 0; i < countOfAccounts; i++)
    {
        if(strncmp(name,arrayOfAccounts[i].name,len) == 0)
        {
            cout << "The balance in this account is " << arrayOfAccounts[i].balance << endl;
            flag = false;
        }
    }
    if(flag)
    {
        cout << "There is no account with that name ! " << endl;
    }
}


int main()
{
    int countOfAcc = 0;
    cout << "Enter count of accounts : ";
    cin >> countOfAcc;
    Bank myBank(countOfAcc);
    for(int i = 0; i < countOfAcc; i++)
    {
        bankAccount forAdd;
        cout << "\nEnter name : ";
        char* name = new char[30];
        cin.clear();
        cin.sync();
        cin.getline(name,30);
        cout << name << endl;
        cout << "\nEnter balance : ";
        int balance = 0;
        cin >> balance;
        init(forAdd,balance,name);

        myBank.addAccount(forAdd);

        delete[] name;
    }

    cout << "Chose name to deposit : ";
    cout << "\nEnter name : ";
    char* nameForDeposit = new char[30];
    cin.clear();
    cin.sync();
    cin.getline(nameForDeposit,30);
    cout << "\nEnter amount of money : ";
    int money;
    cin >> money;
    myBank.deposit(nameForDeposit,money);

    cout << "Chose name to withdraw : ";
    cout << "\nEnter name : ";
    char* nameForWithdraw = new char[30];
    cin.clear();
    cin.sync();
    cin.getline(nameForWithdraw,30);
    cout << "\nEnter amount of money : ";
    cin >> money;
    myBank.withdraw(nameForWithdraw,money);

    cout << "Chose name to check : ";
    cout << "\nEnter name : ";
    char* nameForCheck = new char[30];
    cin.clear();
    cin.sync();
    cin.getline(nameForCheck,30);

    myBank.checkBallance(nameForCheck);

    delete[] nameForCheck;
    delete[] nameForDeposit;
    delete[] nameForWithdraw;

    return 0;
}
