#include "Level2.h"
#include <iostream>
#include "GameManager.h"

Level2::Level2(GameManager* manager) :
    LevelBase(manager),
    enemy(60),
    shop(manager->getShop()) {
}

void Level2::start() {
    currentState = State::START;
    auto player = gameManager->getPlayer();

    player->printInfo();
    std::cout << Text::Level2::welcome() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        attack();
        break;
    case 2:
        std::cout << Text::Level2::payOffWarning() << std::endl;
        attack();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        start();
    }
}

void Level2::attack() {
    currentState = State::ATTACK;
    shop->offerToBuy();

    auto player = gameManager->getPlayer();
    player->printInfo();

    std::cout << Text::Level2::strategyOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        trap();
        break;
    case 2:
        peopleAttack();
        break;
    case 3:
        std::cout << Text::Level2::payOffWarning() << std::endl;
        peopleAttack();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        attack();
    }
}

void Level2::trap() {
    currentState = State::TRAP;
    std::cout << Text::Level2::trapOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << Text::Level2::trap1Result() << std::endl;
        gameManager->getPlayer()->setInfluence(
            gameManager->getPlayer()->getInfluence() - 15);
        peopleAttack();
        break;
    case 2:
        std::cout << Text::Level2::trap2Result() << std::endl;
        enemy.takeDamage(20);
        peopleAttack();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        trap();
    }
}

void Level2::peopleAttack() {
    currentState = State::PEOPLE_ATTACK;
    std::cout << Text::Level2::peopleAttackOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        if (checkResources(800)) {
            killers = 4;
            gameManager->getPlayer()->setMoney(
                gameManager->getPlayer()->getMoney() - 800);
            attackPlace();
        }
        break;
    case 2:
        if (checkResources(1200)) {
            killers = 6;
            gameManager->getPlayer()->setMoney(
                gameManager->getPlayer()->getMoney() - 1200);
            attackPlace();
        }
        break;
    case 3:
        if (checkResources(1600)) {
            killers = 8;
            gameManager->getPlayer()->setMoney(
                gameManager->getPlayer()->getMoney() - 1600);
            attackPlace();
        }
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        peopleAttack();
    }
}

void Level2::attackPlace() {
    currentState = State::ATTACK_PLACE;
    std::cout << Text::Level2::attackPlaceOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << Text::Level2::restaurantDescription() << std::endl;
        strategyAttack();
        break;
    case 2:
        std::cout << Text::Level2::desertDescription() << std::endl;
        strategyAttack();
        break;
    case 3:
        std::cout << Text::Level2::stationDescription() << std::endl;
        gameManager->getPlayer()->setInfluence(
            gameManager->getPlayer()->getInfluence() - 20);
        strategyAttack();
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        attackPlace();
    }
}

void Level2::strategyAttack() {
    currentState = State::STRATEGY_ATTACK;
    std::cout << Text::Level2::attackStrategyOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << Text::Level2::attackFirstResult() << std::endl;
        if (checkResources(0, 2)) {
            gameManager->getPlayer()->setGun(
                gameManager->getPlayer()->getGun() - 2);
            enemy.takeDamage(20);
            continueStrat();
        }
        break;
    case 2:
        gameManager->getPlayer()->setHp(
            gameManager->getPlayer()->getHp() - 15);
        if (checkResources(0, 2)) {
            gameManager->getPlayer()->setGun(
                gameManager->getPlayer()->getGun() - 2);
            enemy.takeDamage(10);
            continueStrat();
        }
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        strategyAttack();
    }
}

void Level2::continueStrat() {
    currentState = State::CONTINUE_STRAT;
    std::cout << Text::Level2::continueStrategyOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        if (checkResources(0, 0, 1)) {
            gameManager->getPlayer()->setGrenade(
                gameManager->getPlayer()->getGrenade() - 1);
            enemy.takeDamage(20);
            std::cout << Text::Level2::ifGrenadeUsed() << std::endl;
            finalPart();
        }
        break;
    case 2:
        if (checkResources(0, 3)) {
            gameManager->getPlayer()->setGun(
                gameManager->getPlayer()->getGun() - 3);
            enemy.takeDamage(20);
            std::cout << Text::Level2::ifGunsUsed() << std::endl;
            finalPart();
        }
        break;
    default:
        std::cout << Text::invalidChoice() << std::endl;
        continueStrat();
    }
}

void Level2::finalPart() {
    currentState = State::FINAL_PART;

    if (enemy.getHp() <= 0) {
        std::cout << Text::Level2::winShort() << std::endl;
        gameManager->getPlayer()->setMoney(
            gameManager->getPlayer()->getMoney() + 2000);
        gameManager->getPlayer()->setInfluence(
            gameManager->getPlayer()->getInfluence() + 20);
        gameManager->getPlayer()->setHp(
            gameManager->getPlayer()->getHp() + 20);
        gameManager->nextLevel();
    }
    else {
        std::cout << Text::Level2::finalOptions() << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (checkResources(0, 2)) {
                gameManager->getPlayer()->setGun(
                    gameManager->getPlayer()->getGun() - 2);
                enemy.takeDamage(20);
                std::cout << Text::Level2::winLong() << std::endl;
                gameManager->getPlayer()->setMoney(
                    gameManager->getPlayer()->getMoney() + 2000);
                gameManager->getPlayer()->setInfluence(
                    gameManager->getPlayer()->getInfluence() + 10);
                gameManager->getPlayer()->setHp(
                    gameManager->getPlayer()->getHp() + 20);
                gameManager->nextLevel();
            }
            break;
        case 2:
            if (checkResources(0, 0, 1)) {
                gameManager->getPlayer()->setGrenade(
                    gameManager->getPlayer()->getGrenade() - 1);
                enemy.takeDamage(20);
                std::cout << Text::Level2::winLong() << std::endl;
                gameManager->getPlayer()->setMoney(
                    gameManager->getPlayer()->getMoney() + 2000);
                gameManager->getPlayer()->setHp(
                    gameManager->getPlayer()->getHp() + 20);
                gameManager->nextLevel();
            }
            break;
        default:
            std::cout << Text::invalidChoice() << std::endl;
            finalPart();
        }
    }
}

bool Level2::checkResources(int money, int gun, int grenade) {
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