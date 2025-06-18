#pragma once
#include <string>
#include <vector>

class Text {
public:
    static std::string playerStats(int influence, int hp, int money,
        int gun, int grenade, int rpg);
    // Уровень 1
    struct Level1 {
        static std::string welcome();
        static std::string strategyOptions();
        static std::string peopleDesertOptions();
        static std::string desertStrategy();
        static std::string desertAttackResult();
        static std::string desertDefenseResult();
        static std::string death();
        static std::string survive();
        static std::string win();
        static std::string peopleLairOptions();
        static std::string lairAttackResult();
        static std::string winNegotiation1();
        static std::string winNegotiation2();
        static std::string loseNegotiation();
        static std::string nothingHappened();
        static std::string negotiationOptions();
    };
    // Уровень 2
    struct Level2 {
        static std::string welcome();
        static std::string payOffWarning();
        static std::string strategyOptions();
        static std::string trapOptions();
        static std::string trap1Result();
        static std::string trap2Result();
        static std::string attackPlaceOptions();
        static std::string peopleAttackOptions();
        static std::string restaurantDescription();
        static std::string stationDescription();
        static std::string desertDescription();
        static std::string attackStrategyOptions();
        static std::string attackFirstResult();
        static std::string defenseResult();
        static std::string continueStrategyOptions();
        static std::string ifGrenadeUsed();
        static std::string ifGunsUsed();
        static std::string finalOptions();
        static std::string winLong();
        static std::string winShort();
    };

    // Уровень 3
    struct Level3 {
        static std::string welcome();
        static std::string refusalWarning();
        static std::string loseRefusal();
        static std::string meetingDescription();
        static std::string spyOptions();
        static std::string stupidSpyResult();
        static std::string cleverSpyOptions();
        static std::string cleverSpyResult();
        static std::string attackOptions();
        static std::string laboratoryDescription();
        static std::string scientistsOptions();
        static std::string killScientistsResult();
        static std::string kidnapScientistsResult();
        static std::string labOptions();
        static std::string winCheap();
        static std::string winExpensive();
    };

    // Уровень 4
    struct Level4 {
        static std::string welcome();
        static std::string buyOffResult();
        static std::string peacefulOptions1();
        static std::string peacefulOptions2();
        static std::string winPolice();
        static std::string attackPoliceOptions();
        static std::string searchOptions();
        static std::string fightResult();
        static std::string trapWarning();
        static std::string trapOptions();
        static std::string policeWin();
    };

    // Уровень 5
    struct Level5 {
        static std::string welcome();
        static std::string meetingDescription();
        static std::string attackChapoOptions();
        static std::string trapResult();
        static std::string friendOptions();
        static std::string attackPlaneOptions1();
        static std::string attackPlaneOptions2();
        static std::string trapStrategyOptions();
        static std::string trapMargoOptions();
        static std::string deathMargoOptions();
        static std::string winSad();
        static std::string neutralPlaceOptions1();
        static std::string neutralPlaceOptions2();
        static std::string warResult();
        static std::string surveillanceOptions();
        static std::string winShort();
        static std::string attackStrategyOptions1();
        static std::string attackStrategyOptions2();
        static std::string attackStrategyOptions3();
        static std::string ifDefenseResult();
        static std::string ifAttackResult();
        static std::string howContinueOptions();
        static std::string ifPatronsResult();
        static std::string rpgOrGrenadeOptions();
        static std::string noRpgResult();
        static std::string winFinal();
    };
    // Общие фразы
    static std::string invalidChoice();
    static std::string notEnoughMoney();
    static std::string gameOver();
};

