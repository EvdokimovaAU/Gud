#include "Player.h"

Player::Player(int initialInfluence, int initialHp, int initialMoney) :
    influence(initialInfluence), hp(initialHp), money(initialMoney),
    gun(5), grenade(0), rpg(0) {
}

void Player::printInfo() const {
    std::cout << "\n���� ������� ����:" << std::endl;
    std::cout << "�������: " << influence << "%" << std::endl;
    std::cout << "���� ������� (HP): " << hp << std::endl;
    std::cout << "�������: $" << money << std::endl;

    if (gun > 0 || grenade > 0 || rpg > 0) {
        std::cout << "���������: " << std::endl;
        if (gun > 0) std::cout << "���������: " << gun << std::endl;
        if (grenade > 0) std::cout << "�������: " << grenade << std::endl;
        if (rpg > 0) std::cout << "���: " << rpg << std::endl;
    }
}

void Player::setInfluence(int value) {
    influence = value;
    if (influence < 30) {
        std::cout << "���������� ������ �������: " << influence << "%" << std::endl;
    }
}

void Player::setHp(int value) {
    hp = value;
    if (hp <= 0) {
        hp = 0;
        std::cout << "HP ����� �� 0! ������� ���������." << std::endl;
    }
}

void Player::setMoney(int value) {
    money = value;
    if (money < 0) money = 0;
}

void Player::setGun(int value) {
    gun = value;
    if (gun < 0) gun = 0;
}

void Player::setGrenade(int value) {
    grenade = value;
    if (grenade < 0) grenade = 0;
}

void Player::setRPG(int value) {
    rpg = value;
    if (rpg < 0) rpg = 0;
}
