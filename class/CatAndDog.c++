#include <iostream>

struct BornTime
{
    int day;
    int month;
    int year;    
};

class Animal
{
private:
    BornTime born;
    char *name;
public:
    Animal(BornTime, char*); // Constructor
    ~Animal(); // Destructor
};

Animal::Animal(BornTime n_born, char* n_name)
{
    born = n_born;
    name = n_name;
}
Animal::~Animal()
{
    std::cout << "Rip: " << name << ", born day: " << born.day << std::endl;
}

class Cat : public Animal {
    private:
        int howManyMiauSay;
    public:
        Cat(BornTime, char*, int);// : Animal(n_bornAge, n_name) {};
        ~Cat();
        void SayMiau();
};

Cat::Cat(BornTime n_born, char *n_name, int n_howManyMiauSay) : Animal(n_born, n_name)
{
    howManyMiauSay = n_howManyMiauSay;
}
Cat::~Cat()
{
    howManyMiauSay = howManyMiauSay / 4;
    SayMiau();
}
void Cat::SayMiau()
{
    for(int i = 0; i < howManyMiauSay; i++) {
        std::cout << "Miau" << std::endl;
    }
}

class Dog : public Animal {
    private:
        int howManyGuauSay;
    public:
        Dog(BornTime, char*, int);// : Animal(n_bornAge, n_name) {};
        ~Dog();
        void SayGuau();
};

Dog::Dog(BornTime n_born, char *n_name, int n_howManyGuauSay) : Animal(n_born, n_name)
{
    howManyGuauSay = n_howManyGuauSay;
}
Dog::~Dog()
{
    howManyGuauSay = howManyGuauSay / 4;
    SayGuau();
}
void Dog::SayGuau()
{
    for(int i = 0; i < howManyGuauSay; i++) {
        std::cout << "Guau" << std::endl;
    }
}

int main()
{
    Cat *myCat = new Cat({5, 1, 2000}, (char*) "Kitty", 8);
    myCat->SayMiau();
    std::cout << "But the miau is not for ever" << std::endl;
    delete myCat;

    Dog *myDog = new Dog({5, 1, 2002}, (char *) "Dolf", 8);
    myDog->SayGuau();
    std::cout << "But the guau is not for ever" << std::endl;
    delete myDog;

    return 0;
}