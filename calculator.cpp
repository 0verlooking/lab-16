#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& animalName) : name(animalName) {
    }

    virtual void makeSound() const = 0;
};

class Bird : public Animal {
protected:
    int wingspan;

public:
    Bird(const std::string& birdName, int birdWingspan) : Animal(birdName), wingspan(birdWingspan) {
    }

    void makeSound() const override {
        std::cout << name << " is chirping." << std::endl;
    }
};

class Human : public Animal {
protected:
    std::string nationality;

public:
    Human(const std::string& humanName, const std::string& humanNationality) : Animal(humanName), nationality(humanNationality) {
    }

    void makeSound() const override {
        std::cout << name << " is speaking." << std::endl;
    }

    void introduce() const {
        std::cout << "My name is " << name << ". I am a " << nationality << "." << std::endl;
    }
};

int main() {
    Animal* animal = new Bird("Sparrow", 10);
    animal->makeSound();

    Animal* human = new Human("John", "American");
    human->makeSound();

    Human* person = dynamic_cast<Human*>(human);
    if (person) {
        person->introduce();
    }

    delete animal;
    delete human;

    return 0;
}