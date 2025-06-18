#include "Shop.h"
#include <iostream>

void Shop::printInfo() const {
    std::cout << "======== Магазин ========" << std::endl;
    std::cout << "1. Патроны: $" << priceCartridges << " (5 штук)" << std::endl;

    if (level >= 2) {
        std::cout << "2. Гранаты: $" << priceGrenade << " (3 штуки)" << std::endl;
    }
    else {
        std::cout << "Гранаты доступны на 2 уровне" << std::endl;
    }

    if (level >= 4) {
        std::cout << "3. РПГ: $" << priceRPG << " (1 штука)" << std::endl;
    }
    else {
        std::cout << "РПГ доступен на 4 уровне" << std::endl;
    }
}

void Shop::offerToBuy() {
    std::cout << "\nХотите что-нибудь купить?" << std::endl;
    std::cout << "1. Нет" << std::endl;
    std::cout << "2. Да" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 2) {
        printInfo();
        std::cout << "Выберите товар (1-3): ";
        int itemChoice;
        std::cin >> itemChoice;

        if (itemChoice >= 1 && itemChoice <= 3) {
            buyItem(static_cast<ItemType>(itemChoice - 1));
        }
    }
}

void Shop::buyItem(ItemType type) {
    auto playerPtr = player.lock();
    if (!playerPtr) return;

    switch (type) {
    case ItemType::CARTRIDGES:
        if (playerPtr->canAfford(priceCartridges)) {
            playerPtr->setMoney(playerPtr->getMoney() - priceCartridges);
            playerPtr->setGun(playerPtr->getGun() + 5);
            std::cout << "Куплено 5 патронов!" << std::endl;
        }
        else {
            std::cout << "Недостаточно денег!" << std::endl;
        }
        break;

    case ItemType::GRENADE:
        if (level >= 2) {
            if (playerPtr->canAfford(priceGrenade)) {
                playerPtr->setMoney(playerPtr->getMoney() - priceGrenade);
                playerPtr->setGrenade(playerPtr->getGrenade() + 3);
                std::cout << "Куплено 3 гранаты!" << std::endl;
            }
            else {
                std::cout << "Недостаточно денег!" << std::endl;
            }
        }
        break;

    case ItemType::RPG:
        if (level >= 4) {
            if (playerPtr->canAfford(priceRPG)) {
                playerPtr->setMoney(playerPtr->getMoney() - priceRPG);
                playerPtr->setRPG(playerPtr->getRPG() + 1);
                std::cout << "Куплен РПГ!" << std::endl;
            }
            else {
                std::cout << "Недостаточно денег!" << std::endl;
            }
        }
        break;
    }
}
