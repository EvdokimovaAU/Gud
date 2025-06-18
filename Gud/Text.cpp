#include "Text.h"
#include <sstream>

using namespace std;

// ==================== ����� ������ ====================
string Text::invalidChoice() {
    return "�������� �����! ����������, �������� ���� �� ������������ ���������.";
}

string Text::notEnoughMoney() {
    return "������������ ����� ��� ����� ��������!";
}

string Text::gameOver() {
    return "���� ��������. ������ ������ ������? (1 - ��, 2 - ���)";
}

string Text::playerStats(int influence, int hp, int money, int gun, int grenade, int rpg) {
    stringstream ss;
    ss << "\n���� ������� ����:\n"
        << "�������: " << influence << "%\n"
        << "���� ������� (HP): " << hp << "\n"
        << "�������: $" << money << "\n";

    if (gun > 0 || grenade > 0 || rpg > 0) {
        ss << "���������:\n";
        if (gun > 0) ss << "���������: " << gun << "\n";
        if (grenade > 0) ss << "�������: " << grenade << "\n";
        if (rpg > 0) ss << "���: " << rpg << "\n";
    }

    return ss.str();
}

// ==================== ������� 1 ====================
string Text::Level1::welcome() {
    return "�����:\n"
        "������������ ������ ��������, � ��� ����� �������� �����.\n"
        "������ ������������� ������� �������������� ����� ��� ����� ������.\n"
        "1. ���������� ���������� �����\n"
        "2. ���������� ������������";
}

string Text::Level1::strategyOptions() {
    return "��� �������?\n"
        "1. ����������� � ������� �� ����������\n"
        "2. ��������� � ������ �����\n"
        "3. ���������� � ���� �� '��������'";
}

string Text::Level1::peopleDesertOptions() {
    return "������� ����� �����?\n"
        "1. 2 ������� ($700)\n"
        "2. 1 ������ + 1 ������������� ($750)\n"
        "3. 1 ������ + 2 ������������� ($1100)\n"
        "4. 2 ������� + 2 ������������� ($1500)";
}

string Text::Level1::desertStrategy() {
    return "���������:\n1. �����\n2. ������";
}

string Text::Level1::desertAttackResult() {
    return "��������� �����! -20HP �����, -3 �������";
}

string Text::Level1::desertDefenseResult() {
    return "���� �������� ������! -20HP �����, -4 �������, -20HP ���";
}

string Text::Level1::death() {
    return "����� ����������� ���� ���!";
}

string Text::Level1::survive() {
    return "������������� ������ ��� �� ������������ ��������!";
}

string Text::Level1::win() {
    return "������! +$1000, +10% �������, +20HP";
}

string Text::Level1::peopleLairOptions() {
    return "��������:\n1. 2 ($700)\n2. 3 ($900)\n3. 4 ($1200)";
}

string Text::Level1::lairAttackResult() {
    return "���� ���� � ������! -10HP �����, -2 �������, �� ��� � �����\n"
        "1. ������� ��\n2. �������� ($3000)";
}

string Text::Level1::winNegotiation1() {
    return "�� ��������� $2000. -15% �������";
}

string Text::Level1::winNegotiation2() {
    return "�� ��������� $1000. -10% �������";
}

string Text::Level1::loseNegotiation() {
    return "��� ��� �����!";
}

string Text::Level1::nothingHappened() {
    return "����� �� ������!";
}

string Text::Level1::negotiationOptions() {
    return "��� ����� $2000\n1. �����������\n2. ����������� �� $1000\n3. ���������� $500";
}

// ==================== ������� 2 ====================
string Text::Level2::welcome() {
    return "�����:\n��� ������ ����� ��� ����������!\n"
        "1. ���������\n2. ����������";
}

string Text::Level2::payOffWarning() {
    return "������ �� ����� ������! �������� ���������.";
}

string Text::Level2::strategyOptions() {
    return "���������:\n1. �������\n2. ��������\n3. �����";
}

string Text::Level2::trapOptions() {
    return "�������:\n1. ���������� ������\n2. ���������� ������ �����";
}

string Text::Level2::trap1Result() {
    return "������! ��� ������� ��� ������. -15% �������";
}

string Text::Level2::trap2Result() {
    return "�����! -20HP �����";
}

string Text::Level2::attackPlaceOptions() {
    return "�����:\n1. ��������\n2. �������\n3. ������";
}

string Text::Level2::peopleAttackOptions() {
    return "����:\n1. 4 ($800)\n2. 6 ($1200)\n3. 8 ($1600)";
}

string Text::Level2::restaurantDescription() {
    return "�������� - ������� �����, ������� ����������";
}

string Text::Level2::stationDescription() {
    return "������ - ����� ����������! -20% ������� ��� ��������";
}

string Text::Level2::desertDescription() {
    return "������� - ��������� ����� ��� ��������";
}

string Text::Level2::attackStrategyOptions() {
    return "�������:\n1. �����\n2. ������";
}

string Text::Level2::attackFirstResult() {
    return "�� ��������� �������! -20HP �����, -2 �������";
}

string Text::Level2::defenseResult() {
    return "�� ����������. -15HP ���, -10HP �����";
}

string Text::Level2::continueStrategyOptions() {
    return "����������:\n1. �������\n2. ��������";
}

string Text::Level2::ifGrenadeUsed() {
    return "�������! -20HP �����";
}

string Text::Level2::ifGunsUsed() {
    return "������ ��������! -2 ����� �����";
}

string Text::Level2::finalOptions() {
    return "�����:\n1. ������ �����\n2. ������� ������������ (-10% �������, -1 �������)";
}

string Text::Level2::winLong() {
    return "������! +$2000, +10% �������, +20HP";
}

string Text::Level2::winShort() {
    return "������� ������! +$2000, +20HP";
}

// ==================== ������� 3 ====================
string Text::Level3::welcome() {
    return "�����:\n���������� ��������� �����������!\n"
        "1. ����������� � ������������\n2. ������������";
}

string Text::Level3::refusalWarning() {
    return "��� ���� �������� ������ ��������!";
}

string Text::Level3::loseRefusal() {
    return "�� ��������� ����. ���� ��������.";
}

string Text::Level3::meetingDescription() {
    return "����� ���������� � �����������. ���� ����� ���������.\n"
        "1. ������� �������� ($1200)\n2. ������� ������ ($700)";
}

string Text::Level3::spyOptions() {
    return "����� ������ ������:\n1. ����������\n2. ��������";
}

string Text::Level3::stupidSpyResult() {
    return "����� ����������! �������� ���������.";
}

string Text::Level3::cleverSpyOptions() {
    return "2 ���������:\n1. ����� ($700)\n2. ������";
}

string Text::Level3::cleverSpyResult() {
    return "����� ���� ������! -2 �������";
}

string Text::Level3::attackOptions() {
    return "������ �������!\n1. ����������� (-3 �������)\n2. �������";
}

string Text::Level3::laboratoryDescription() {
    return "�� � �����������. ������ ������� ������� ���������.";
}

string Text::Level3::scientistsOptions() {
    return "������:\n1. ����� � ����\n2. �����";
}

string Text::Level3::killScientistsResult() {
    return "�� �������� ������ � ���������! ���������.";
}

string Text::Level3::kidnapScientistsResult() {
    return "������ �������� �� ���! �������� �����������:\n"
        "1. ������� ($1500)\n2. ������� ($3000)";
}

string Text::Level3::labOptions() {
    return "�����������:\n1. ������ �����������\n2. ����������� ��������";
}

string Text::Level3::winCheap() {
    return "������! +$1000 �� �������";
}

string Text::Level3::winExpensive() {
    return "������! +$2000 �� �������";
}

// ==================== ������� 4 ====================
string Text::Level4::welcome() {
    return "�����:\n������� ������� ����!\n"
        "1. �������������\n2. ���������\n3. ���������";
}

string Text::Level4::buyOffResult() {
    return "������������ �������! ��� ����������.";
}

string Text::Level4::peacefulOptions1() {
    return "����������:\n1. ��������� ������\n2. �������� ��� �����";
}

string Text::Level4::peacefulOptions2() {
    return "������:\n1. ��������\n2. �������� � �����������";
}

string Text::Level4::winPolice() {
    return "����� ������ �����! +$2500";
}

string Text::Level4::attackPoliceOptions() {
    return "�����:\n1. �������\n2. ����� �����";
}

string Text::Level4::searchOptions() {
    return "����:\n1. �������������\n2. ���������";
}

string Text::Level4::fightResult() {
    return "�����������! ��� ���� ���� �����, �� � ������.";
}

string Text::Level4::trapWarning() {
    return "��������! ����� ������� ��� ���";
}

string Text::Level4::trapOptions() {
    return "�������:\n1. ���\n2. �������";
}

string Text::Level4::policeWin() {
    return "�� ����� �������, �� ��� ��� ������!";
}

// ==================== ������� 5 ====================
string Text::Level5::welcome() {
    return "�����:\n��������� ����� � ��� ����!\n"
        "1. �������\n2. ���� �����";
}

string Text::Level5::meetingDescription() {
    return "���� ����� ��� ��������!\n1. �����������\n2. ����������";
}

string Text::Level5::attackChapoOptions() {
    return "���������:\n1. ���� � ������ ��������\n2. ����������\n3. �����";
}

string Text::Level5::trapResult() {
    return "���� ������� ���� �������!";
}

string Text::Level5::friendOptions() {
    return "�������:\n1. 30% �������\n2. ������\n3. ������";
}

string Text::Level5::attackPlaneOptions1() {
    return "����:\n1. ��� ����\n2. ����� ���";
}

string Text::Level5::attackPlaneOptions2() {
    return "����:\n1. �������\n2. ������� �����";
}

string Text::Level5::trapStrategyOptions() {
    return "�������:\n1. �����\n2. ����������� ����������\n3. ������";
}

string Text::Level5::trapMargoOptions() {
    return "����� - ������ ����! �����?\n1. ��\n2. ���";
}

string Text::Level5::deathMargoOptions() {
    return "������:\n1. ���\n2. �������\n3. ��������";
}

string Text::Level5::winSad() {
    return "�� ��������, �� �������� ������...";
}

string Text::Level5::neutralPlaceOptions1() {
    return "�����:\n1. �������\n2. ��������";
}

string Text::Level5::neutralPlaceOptions2() {
    return "����:\n1. ��������\n2. �������� + ������";
}

string Text::Level5::warResult() {
    return "��� ��� ����������! ���� ��������� �����!";
}

string Text::Level5::surveillanceOptions() {
    return "���� ���� � ����. ������ ��������:\n1. ���\n2. �������\n3. ��������";
}

string Text::Level5::winShort() {
    return "�� �������� ����!";
}

string Text::Level5::attackStrategyOptions1() {
    return "�����:\n1. �������\n2. ��������";
}

string Text::Level5::attackStrategyOptions2() {
    return "����:\n1. ��������\n2. �������� + ������";
}

string Text::Level5::attackStrategyOptions3() {
    return "�������:\n1. ������\n2. �����";
}

string Text::Level5::ifDefenseResult() {
    return "������! -4 ����� �����";
}

string Text::Level5::ifAttackResult() {
    return "�����! ��������� ������ �����";
}

string Text::Level5::howContinueOptions() {
    return "����������:\n1. ��������\n2. ���\n3. �������";
}

string Text::Level5::ifPatronsResult() {
    return "���� ����������� ���! �� �������.";
}

string Text::Level5::rpgOrGrenadeOptions() {
    return "��������:\n1. ��������\n2. �������\n3. ��� x2";
}

string Text::Level5::noRpgResult() {
    return "������������! ��� ����������.";
}

string Text::Level5::winFinal() {
    return "������! �� ����� ������������!";
}