#include "Level3.h"
#include <iostream>
#include "GameManager.h"

Level3::Level3(GameManager* manager) :
    LevelBase(manager),
    enemy(60),
    shop(manager->getShop()) {
}

void Level3::start() {
    currentState = State::START;
    std::cout << Text::Level3::welcome() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        meeting();
        break;
    case 2:
        noMeeting();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        start();
    }
}

void Level3::meeting() {
    currentState = State::MEETING;
    std::cout << Text::Level3::meetingDescription() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        shooting();
        break;
    case 2:
        spy();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        meeting();
    }
}

void Level3::noMeeting() {
    currentState = State::NO_MEETING;
    std::cout << Text::Level3::refusalWarning() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        meeting();
        break;
    case 2:
        std::cout << Text::Level3::loseRefusal() << std::endl;
        gameManager->loseGame();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        noMeeting();
    }
}

void Level3::spy() {
    currentState = State::SPY;
    if (checkResources(700)) {
        gameManager->getPlayer()->setMoney(
            gameManager->getPlayer()->getMoney() - 700);

        std::cout << Text::Level3::spyOptions() << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            cleverSpy();
            break;
        case 2:
            std::cout << Text::Level3::stupidSpyResult() << std::endl;
            shop->offerToBuy();
            shooting();
            break;
        default:
            std::cout << Text::invalidChoice() << std::endl;
            spy();
        }
    }
}

void Level3::cleverSpy() {
    currentState = State::CLEVER_SPY;
    std::cout << Text::Level3::cleverSpyOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        shooting();
        break;
    case 2:
        if (checkResources(0, 2)) {
            gameManager->getPlayer()->setGun(
                gameManager->getPlayer()->getGun() - 2);
            std::cout << Text::Level3::cleverSpyResult() << std::endl;
            laboratory();
        }
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        gameManager->loseGame();
    }
}

void Level3::shooting() {
    currentState = State::SHOOTING;
    if (checkResources(1200)) {
        gameManager->getPlayer()->setMoney(
            gameManager->getPlayer()->getMoney() - 1200);

        shop->offerToBuy();

        std::cout << Text::Level3::attackOptions() << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (checkResources(0, 3)) {
                gameManager->getPlayer()->setGun(
                    gameManager->getPlayer()->getGun() - 3);
                enemy.takeDamage(40);
                laboratory();
            }
            break;
        case 2:
            if (checkResources(0, 0, 1)) {
                gameManager->getPlayer()->setGrenade(
                    gameManager->getPlayer()->getGrenade() - 1);
                laboratory();
            }
            break;
        default:
            std::cout << Text::invalidChoice() << std::endl;
            shooting();
        }
    }
}

void Level3::laboratory() {
    currentState = State::LABORATORY;
    std::cout << Text::Level3::laboratoryDescription() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        kidnapScientists();
        break;
    case 2:
        std::cout << Text::Level3::killScientistsResult() << std::endl;
        gameManager->loseGame();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        laboratory();
    }
}

void Level3::kidnapScientists() {
    currentState = State::KIDNAP_SCIENTISTS;
    std::cout << Text::Level3::kidnapScientistsResult() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << Text::Level3::winCheap() << std::endl;
        gameManager->nextLevel();
        break;
    case 2:
        std::cout << Text::Level3::winExpensive() << std::endl;
        gameManager->nextLevel();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        kidnapScientists();
    }
}

bool Level3::checkResources(int money, int gun, int grenade) {
    auto player = gameManager->getPlayer();

    if (player->getMoney() < money) {
        std::cout << Text::notEnoughMoney() << std::endl;
        gameManager->loseGame();
        return false;
    }

    if (player->getGun() < gun) {
        std::cout << "Недостаточно патронов!" << std::endl;
        gameManager->loseGame();
        return false;
    }

    if (player->getGrenade() < grenade) {
        std::cout << "Недостаточно гранат!" << std::endl;
        gameManager->loseGame();
        return false;
    }

    return true;
}
