#include "Shop.h"
#include <iostream>

void Shop::printInfo() const {
    std::cout << "======== ������� ========" << std::endl;
    std::cout << "1. �������: $" << priceCartridges << " (5 ����)" << std::endl;

    if (level >= 2) {
        std::cout << "2. �������: $" << priceGrenade << " (3 �����)" << std::endl;
    }
    else {
        std::cout << "������� �������� �� 2 ������" << std::endl;
    }

    if (level >= 4) {
        std::cout << "3. ���: $" << priceRPG << " (1 �����)" << std::endl;
    }
    else {
        std::cout << "��� �������� �� 4 ������" << std::endl;
    }
}

void Shop::offerToBuy() {
    std::cout << "\n������ ���-������ ������?" << std::endl;
    std::cout << "1. ���" << std::endl;
    std::cout << "2. ��" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 2) {
        printInfo();
        std::cout << "�������� ����� (1-3): ";
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
            std::cout << "������� 5 ��������!" << std::endl;
        }
        else {
            std::cout << "������������ �����!" << std::endl;
        }
        break;

    case ItemType::GRENADE:
        if (level >= 2) {
            if (playerPtr->canAfford(priceGrenade)) {
                playerPtr->setMoney(playerPtr->getMoney() - priceGrenade);
                playerPtr->setGrenade(playerPtr->getGrenade() + 3);
                std::cout << "������� 3 �������!" << std::endl;
            }
            else {
                std::cout << "������������ �����!" << std::endl;
            }
        }
        break;

    case ItemType::RPG:
        if (level >= 4) {
            if (playerPtr->canAfford(priceRPG)) {
                playerPtr->setMoney(playerPtr->getMoney() - priceRPG);
                playerPtr->setRPG(playerPtr->getRPG() + 1);
                std::cout << "������ ���!" << std::endl;
            }
            else {
                std::cout << "������������ �����!" << std::endl;
            }
        }
        break;
    }
}
