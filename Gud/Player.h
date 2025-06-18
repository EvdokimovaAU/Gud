#pragma once
#include <iostream>

class Player {
private:
    int influence;  // 30-100%
    int hp;         // 0-100
    int money;

    int gun;
    int grenade;
    int rpg;

public:
    Player(int initialInfluence, int initialHp, int initialMoney);

    void printInfo() const;

    // Геттеры
    int getInfluence() const { return influence; }
    int getHp() const { return hp; }
    int getMoney() const { return money; }
    int getGun() const { return gun; }
    int getGrenade() const { return grenade; }
    int getRPG() const { return rpg; }

    // Сеттеры
    void setInfluence(int value);
    void setHp(int value);
    void setMoney(int value);
    void setGun(int value);
    void setGrenade(int value);
    void setRPG(int value);

    bool canAfford(int amount) const { return money >= amount; }
};
