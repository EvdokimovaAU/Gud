#pragma once

class Enemy {
private:
    int hp;

public:
    explicit Enemy(int initialHp) : hp(initialHp) {}

    int getHp() const { return hp; }
    void setHp(int value) { hp = (value < 0) ? 0 : value; }
    void takeDamage(int damage) { setHp(hp - damage); }

    bool isAlive() const { return hp > 0; }
};

