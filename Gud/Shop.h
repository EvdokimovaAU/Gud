#pragma once
#include <memory>
#include "Player.h"

class Shop {
public:
    enum class ItemType { CARTRIDGES, GRENADE, RPG };

private:
    std::weak_ptr<Player> player;
    int level = 1;

    // Цены
    const int priceCartridges = 500;
    const int priceGrenade = 1500;
    const int priceRPG = 2000;

    // Урон
    const int damageGun = 10;
    const int damageGrenade = 20;
    const int damageRPG = 30;

public:
    explicit Shop(std::shared_ptr<Player> player) : player(player) {}

    void printInfo() const;
    void offerToBuy();
    void buyItem(ItemType type);

    void setLevel(int newLevel) { level = newLevel; }
};
