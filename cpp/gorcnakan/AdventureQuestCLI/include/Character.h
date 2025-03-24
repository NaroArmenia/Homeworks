#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attackPower;
    int defense;

public:
    Character(const std::string& name, int health, int attackPower, int defense)
        : name(name), health(health), attackPower(attackPower), defense(defense) {}

    virtual ~Character() = default;

    virtual void displayStats() const = 0;
    virtual void takeDamage(int damage) = 0;

    int getHealth() const;
    int getAttackPower() const;
    int getDefense() const;
    std::string getName() const;
};

#endif