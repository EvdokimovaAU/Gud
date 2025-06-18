#include "Level1.h"
#include <iostream>
#include "GameManager.h"

#include <limits>

Level1::Level1(GameManager* manager) :
    LevelBase(manager),
    enemy(40),
    shop(manager->getShop()) {
}

void Level1::start() {
    currentState = State::START;
    auto player = gameManager->getPlayer();

    player->printInfo();
    std::cout << Text::Level1::welcome() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        destroyEnemy();
        break;
    case 2:
        negotiations();
        break;
    default:
        handleInvalidChoice();
        start();
    }
}

void Level1::destroyEnemy() {
    currentState = State::DESTROY_ENEMY;
    std::cout << Text::Level1::strategyOptions() << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        shop->offerToBuy();
        peopleDesert();
        break;
    case 2:
        shop->offerToBuy();
        enemysLair();
        break;
    case 3:
        std::cout << Text::Level1::nothingHappened() << std::endl;
        destroyEnemy();
        break;
    default:
        handleInvalidChoice();
        destroyEnemy();
    }
}

void Level1::negotiations() {
    currentState = State::NEGOTIATIONS;
    std::cout << Text::Level1::negotiationOptions() << std::endl;

    int choice;
    std::cin >> choice;
    auto player = gameManager->getPlayer();

    switch (choice) {
    case 1:
        if (checkPlayerResources(2000)) {
            std::cout << Text::Level1::winNegotiation1() << std::endl;
            applyMoneyChange(-2000);
            applyInfluenceChange(-15);
        }
        break;
    case 2:
        if (checkPlayerResources(1000)) {
            std::cout << Text::Level1::winNegotiation2() << std::endl;
            applyMoneyChange(-1000);
            applyInfluenceChange(-10);
        }
        break;
    case 3:
        std::cout << Text::Level1::loseNegotiation() << std::endl;
        gameManager->loseGame();
        break;
    default:
        handleInvalidChoice();
        negotiations();
    }

    if (gameManager->isGameRunning()) {
        player->printInfo();
        gameManager->nextLevel();
    }
}

void Level1::peopleDesert() {
    currentState = State::PEOPLE_DESERT;
    std::cout << Text::Level1::peopleDesertOptions() << std::endl;

    int choice;
    std::cin >> choice;
    auto player = gameManager->getPlayer();

    switch (choice) {
    case 1:
        if (checkPlayerResources(700)) {
            killers = 2;
            applyMoneyChange(-700);
            strategyDesert();
        }
        break;
    case 2:
        if (checkPlayerResources(750)) {
            killers = 2;
            applyMoneyChange(-750);
            strategyDesert();
        }
        break;
    case 3:
        if (checkPlayerResources(1100)) {
            killers = 4;
            applyMoneyChange(-1100);
            strategyDesert();
        }
        break;
    case 4:
        if (checkPlayerResources(1500)) {
            killers = 4;
            applyMoneyChange(-1500);
            strategyDesert();
        }
        break;
    default:
        handleInvalidChoice();
        peopleDesert();
    }
}

void Level1::strategyDesert() {
    currentState = State::STRATEGY_DESERT;
    std::cout << Text::Level1::desertStrategy() << std::endl;

    int choice;
    std::cin >> choice;
    auto player = gameManager->getPlayer();

    switch (choice) {
    case 1:
        if (checkPlayerResources(0, 3)) {
            std::cout << Text::Level1::desertAttackResult() << std::endl;
            applyDamageToEnemy(20);
            player->setGun(player->getGun() - 3);
            loseOrWin();
        }
        break;
    case 2:
        if (checkPlayerResources(0, 4)) {
            std::cout << Text::Level1::desertDefenseResult() << std::endl;
            applyDamageToEnemy(20);
            player->setGun(player->getGun() - 4);
            applyDamageToPlayer(20);
            loseOrWin();
        }
        break;
    default:
        handleInvalidChoice();
        strategyDesert();
    }
}

void Level1::loseOrWin() {
    currentState = State::LOSE_OR_WIN;
    auto player = gameManager->getPlayer();

    if (killers == 4) {
        if (checkPlayerResources(0, 2)) {
            std::cout << Text::Level1::survive() << std::endl;
            applyDamageToEnemy(20);
            player->setGun(player->getGun() - 2);

            std::cout << Text::Level1::win() << std::endl;
            applyMoneyChange(1000);
            applyInfluenceChange(10);
            applyDamageToPlayer(-20); // Восстановление HP
        }
    }
    else {
        std::cout << Text::Level1::death() << std::endl;
        gameManager->loseGame();
    }

    if (gameManager->isGameRunning()) {
        player->printInfo();
        gameManager->nextLevel();
    }
}

void Level1::enemysLair() {
    currentState = State::ENEMYS_LAIR;
    std::cout << Text::Level1::peopleLairOptions() << std::endl;

    int choice;
    std::cin >> choice;
    auto player = gameManager->getPlayer();

    switch (choice) {
    case 1:
        if (checkPlayerResources(700)) {
            killers = 2;
            applyMoneyChange(-700);
            strategyLair();
        }
        break;
    case 2:
        if (checkPlayerResources(900)) {
            killers = 3;
            applyMoneyChange(-900);
            strategyLair();
        }
        break;
    case 3:
        if (checkPlayerResources(1200)) {
            killers = 4;
            applyMoneyChange(-1200);
            strategyLair();
        }
        break;
    default:
        handleInvalidChoice();
        enemysLair();
    }
}

void Level1::strategyLair() {
    currentState = State::STRATEGY_LAIR;
    auto player = gameManager->getPlayer();

    if (checkPlayerResources(0, 2)) {
        player->setGun(player->getGun() - 2);
        applyDamageToPlayer(15);

        std::cout << Text::Level1::lairAttackResult() << std::endl;
        applyDamageToEnemy(10);
        player->printInfo();

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            shop->offerToBuy();
            peopleDesert();
            break;
        case 2:
            if (checkPlayerResources(3000)) {
                std::cout << Text::Level1::winNegotiation1() << std::endl;
                applyMoneyChange(-3000);
                applyInfluenceChange(-15);
                gameManager->nextLevel();
            }
            break;
        default:
            handleInvalidChoice();
            strategyLair();
        }
    }
}

// Вспомогательные методы
void Level1::handleInvalidChoice() {
    std::cout << Text::invalidChoice() << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Level1::checkPlayerResources(int requiredMoney, int requiredGun) {
    auto player = gameManager->getPlayer();

    if (player->getMoney() < requiredMoney) {
        std::cout << Text::notEnoughMoney() << std::endl;
        gameManager->loseGame();
        return false;
    }

    if (player->getGun() < requiredGun) {
        std::cout << "Недостаточно патронов!" << std::endl;
        gameManager->loseGame();
        return false;
    }

    return true;
}

void Level1::applyDamageToEnemy(int damage) {
    enemy.takeDamage(damage);
    std::cout << "Враг получил " << damage << " урона. Осталось HP: " << enemy.getHp() << std::endl;
}

void Level1::applyDamageToPlayer(int damage) {
    auto player = gameManager->getPlayer();
    player->setHp(player->getHp() - damage);
    std::cout << "Вы получили " << damage << " урона. Осталось HP: " << player->getHp() << std::endl;
}

void Level1::applyMoneyChange(int amount) {
    auto player = gameManager->getPlayer();
    player->setMoney(player->getMoney() + amount);
    std::cout << (amount > 0 ? "Получено $" : "Потрачено $") << abs(amount) << std::endl;
}

void Level1::applyInfluenceChange(int amount) {
    auto player = gameManager->getPlayer();
    player->setInfluence(player->getInfluence() + amount);
    std::cout << (amount > 0 ? "Влияние +" : "Влияние ") << amount << "%" << std::endl;
}
