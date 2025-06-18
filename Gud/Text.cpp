#include "Text.h"
#include <sstream>

using namespace std;

// ==================== Общие тексты ====================
string Text::invalidChoice() {
    return "Неверный выбор! Пожалуйста, выберите один из предложенных вариантов.";
}

string Text::notEnoughMoney() {
    return "Недостаточно денег для этого действия!";
}

string Text::gameOver() {
    return "Игра окончена. Хотите начать заново? (1 - Да, 2 - Нет)";
}

string Text::playerStats(int influence, int hp, int money, int gun, int grenade, int rpg) {
    stringstream ss;
    ss << "\nВаша текущая мощь:\n"
        << "Влияние: " << influence << "%\n"
        << "Сила картеля (HP): " << hp << "\n"
        << "Капитал: $" << money << "\n";

    if (gun > 0 || grenade > 0 || rpg > 0) {
        ss << "Инвентарь:\n";
        if (gun > 0) ss << "Пистолеты: " << gun << "\n";
        if (grenade > 0) ss << "Гранаты: " << grenade << "\n";
        if (rpg > 0) ss << "РПГ: " << rpg << "\n";
    }

    return ss.str();
}

// ==================== Уровень 1 ====================
string Text::Level1::welcome() {
    return "Пабло:\n"
        "Здравствуйте мистер Корлеоне, я ваш новый помощник Пабло.\n"
        "Мелкие наркоторговцы продают некачественный товар под вашим именем.\n"
        "1. Уничтожить противника силой\n"
        "2. Попытаться договориться";
}

string Text::Level1::strategyOptions() {
    return "Как напасть?\n"
        "1. Встретиться в пустыне со снайперами\n"
        "2. Ворваться в логово врага\n"
        "3. Пригласить к себе на 'разговор'";
}

string Text::Level1::peopleDesertOptions() {
    return "Сколько людей взять?\n"
        "1. 2 киллера ($700)\n"
        "2. 1 киллер + 1 телохранитель ($750)\n"
        "3. 1 киллер + 2 телохранителя ($1100)\n"
        "4. 2 киллера + 2 телохранителя ($1500)";
}

string Text::Level1::desertStrategy() {
    return "Стратегия:\n1. Атака\n2. Защита";
}

string Text::Level1::desertAttackResult() {
    return "Внезапная атака! -20HP врагу, -3 патрона";
}

string Text::Level1::desertDefenseResult() {
    return "Враг атаковал первым! -20HP врагу, -4 патрона, -20HP вам";
}

string Text::Level1::death() {
    return "Глава группировки убил вас!";
}

string Text::Level1::survive() {
    return "Телохранители спасли вас от смертельного выстрела!";
}

string Text::Level1::win() {
    return "Победа! +$1000, +10% влияния, +20HP";
}

string Text::Level1::peopleLairOptions() {
    return "Наемники:\n1. 2 ($700)\n2. 3 ($900)\n3. 4 ($1200)";
}

string Text::Level1::lairAttackResult() {
    return "Ваши люди в логове! -10HP врагу, -2 патрона, но они в плену\n"
        "1. Бросить их\n2. Выкупить ($3000)";
}

string Text::Level1::winNegotiation1() {
    return "Вы заплатили $2000. -15% влияния";
}

string Text::Level1::winNegotiation2() {
    return "Вы заплатили $1000. -10% влияния";
}

string Text::Level1::loseNegotiation() {
    return "Они вас убили!";
}

string Text::Level1::nothingHappened() {
    return "Никто не пришел!";
}

string Text::Level1::negotiationOptions() {
    return "Они хотят $2000\n1. Согласиться\n2. Торговаться до $1000\n3. Предложить $500";
}

// ==================== Уровень 2 ====================
string Text::Level2::welcome() {
    return "Пабло:\nАль Пачино хочет вас уничтожить!\n"
        "1. Атаковать\n2. Откупиться";
}

string Text::Level2::payOffWarning() {
    return "Пачино не берет взятки! Придется сражаться.";
}

string Text::Level2::strategyOptions() {
    return "Стратегия:\n1. Ловушка\n2. Разборки\n3. Откуп";
}

string Text::Level2::trapOptions() {
    return "Ловушка:\n1. Подставить дельца\n2. Подбросить плохой товар";
}

string Text::Level2::trap1Result() {
    return "Провал! Ваш человек вас предал. -15% влияния";
}

string Text::Level2::trap2Result() {
    return "Успех! -20HP врагу";
}

string Text::Level2::attackPlaceOptions() {
    return "Место:\n1. Ресторан\n2. Пустыня\n3. Вокзал";
}

string Text::Level2::peopleAttackOptions() {
    return "Люди:\n1. 4 ($800)\n2. 6 ($1200)\n3. 8 ($1600)";
}

string Text::Level2::restaurantDescription() {
    return "Ресторан - хорошее место, минимум свидетелей";
}

string Text::Level2::stationDescription() {
    return "Вокзал - много свидетелей! -20% влияния при стрельбе";
}

string Text::Level2::desertDescription() {
    return "Пустыня - идеальное место для разборок";
}

string Text::Level2::attackStrategyOptions() {
    return "Тактика:\n1. Атака\n2. Защита";
}

string Text::Level2::attackFirstResult() {
    return "Вы атаковали первыми! -20HP врагу, -2 патрона";
}

string Text::Level2::defenseResult() {
    return "Вы защищались. -15HP вам, -10HP врагу";
}

string Text::Level2::continueStrategyOptions() {
    return "Продолжить:\n1. Граната\n2. Стрельба";
}

string Text::Level2::ifGrenadeUsed() {
    return "Граната! -20HP врагу";
}

string Text::Level2::ifGunsUsed() {
    return "Точные выстрелы! -2 врага убито";
}

string Text::Level2::finalOptions() {
    return "Финал:\n1. Быстро убить\n2. Жестоко расправиться (-10% влияния, -1 граната)";
}

string Text::Level2::winLong() {
    return "Победа! +$2000, +10% влияния, +20HP";
}

string Text::Level2::winShort() {
    return "Быстрая победа! +$2000, +20HP";
}

// ==================== Уровень 3 ====================
string Text::Level3::welcome() {
    return "Пабло:\nОбнаружена секретная лаборатория!\n"
        "1. Встретиться с информатором\n2. Игнорировать";
}

string Text::Level3::refusalWarning() {
    return "Это шанс получить мощный наркотик!";
}

string Text::Level3::loseRefusal() {
    return "Вы проиграли шанс. Игра окончена.";
}

string Text::Level3::meetingDescription() {
    return "Марго рассказала о лаборатории. Вход через прачечную.\n"
        "1. Послать бандитов ($1200)\n2. Послать шпиона ($700)";
}

string Text::Level3::spyOptions() {
    return "Шпион увидел охрану:\n1. Проследить\n2. Спросить";
}

string Text::Level3::stupidSpyResult() {
    return "Шпион провалился! Придется атаковать.";
}

string Text::Level3::cleverSpyOptions() {
    return "2 охранника:\n1. Атака ($700)\n2. Засада";
}

string Text::Level3::cleverSpyResult() {
    return "Шпион убил охрану! -2 патрона";
}

string Text::Level3::attackOptions() {
    return "Охрана атакует!\n1. Расстрелять (-3 патрона)\n2. Граната";
}

string Text::Level3::laboratoryDescription() {
    return "Вы в лаборатории. Ученые создают красные кристаллы.";
}

string Text::Level3::scientistsOptions() {
    return "Ученые:\n1. Взять в плен\n2. Убить";
}

string Text::Level3::killScientistsResult() {
    return "Вы потеряли доступ к наркотику! Поражение.";
}

string Text::Level3::kidnapScientistsResult() {
    return "Ученые работают на вас! Выберите лабораторию:\n"
        "1. Дешевая ($1500)\n2. Дорогая ($3000)";
}

string Text::Level3::labOptions() {
    return "Лаборатория:\n1. Подвал забегаловки\n2. Современный комплекс";
}

string Text::Level3::winCheap() {
    return "Победа! +$1000 за уровень";
}

string Text::Level3::winExpensive() {
    return "Победа! +$2000 за уровень";
}

// ==================== Уровень 4 ====================
string Text::Level4::welcome() {
    return "Пабло:\nПолиция готовит рейд!\n"
        "1. Подготовиться\n2. Подкупить\n3. Атаковать";
}

string Text::Level4::buyOffResult() {
    return "Полицейского поймали! Вас арестовали.";
}

string Text::Level4::peacefulOptions1() {
    return "Подготовка:\n1. Перевести деньги\n2. Спрятать под полом";
}

string Text::Level4::peacefulOptions2() {
    return "Оружие:\n1. Закопать\n2. Спрятать в лаборатории";
}

string Text::Level4::winPolice() {
    return "Обыск прошел чисто! +$2500";
}

string Text::Level4::attackPoliceOptions() {
    return "Атака:\n1. Ловушка\n2. Ждать рейда";
}

string Text::Level4::searchOptions() {
    return "Рейд:\n1. Подготовиться\n2. Атаковать";
}

string Text::Level4::fightResult() {
    return "Перестрелка! Все ваши люди убиты, вы в тюрьме.";
}

string Text::Level4::trapWarning() {
    return "Внимание! Нужны гранаты или РПГ";
}

string Text::Level4::trapOptions() {
    return "Ловушка:\n1. РПГ\n2. Гранаты";
}

string Text::Level4::policeWin() {
    return "Вы убили полицию, но ФБР вас найдет!";
}

// ==================== Уровень 5 ====================
string Text::Level5::welcome() {
    return "Пабло:\nФинальная битва с Эль Чапо!\n"
        "1. Встреча\n2. План атаки";
}

string Text::Level5::meetingDescription() {
    return "Чапо хочет ваш наркотик!\n1. Согласиться\n2. Отказаться";
}

string Text::Level5::attackChapoOptions() {
    return "Стратегия:\n1. Союз с другим картелем\n2. Подставить\n3. Война";
}

string Text::Level5::trapResult() {
    return "Чапо раскрыл вашу ловушку!";
}

string Text::Level5::friendOptions() {
    return "Союзник:\n1. 30% бизнеса\n2. Дружба\n3. Угрозы";
}

string Text::Level5::attackPlaneOptions1() {
    return "Люди:\n1. Все силы\n2. Часть сил";
}

string Text::Level5::attackPlaneOptions2() {
    return "План:\n1. Ловушка\n2. Лобовая атака";
}

string Text::Level5::trapStrategyOptions() {
    return "Ловушка:\n1. Марго\n2. Нейтральная территория\n3. Слежка";
}

string Text::Level5::trapMargoOptions() {
    return "Марго - сестра Чапо! Убить?\n1. Да\n2. Нет";
}

string Text::Level5::deathMargoOptions() {
    return "Способ:\n1. РПГ\n2. Гранаты\n3. Стрельба";
}

string Text::Level5::winSad() {
    return "Вы победили, но потеряли любовь...";
}

string Text::Level5::neutralPlaceOptions1() {
    return "Место:\n1. Пустыня\n2. Ресторан";
}

string Text::Level5::neutralPlaceOptions2() {
    return "План:\n1. Снайперы\n2. Снайперы + пехота";
}

string Text::Level5::warResult() {
    return "Это был подставной! Чапо объявляет войну!";
}

string Text::Level5::surveillanceOptions() {
    return "Чапо едет к отцу. Способ убийства:\n1. РПГ\n2. Гранаты\n3. Стрельба";
}

string Text::Level5::winShort() {
    return "Вы победили Чапо!";
}

string Text::Level5::attackStrategyOptions1() {
    return "Место:\n1. Пустыня\n2. Ресторан";
}

string Text::Level5::attackStrategyOptions2() {
    return "Силы:\n1. Снайперы\n2. Снайперы + пехота";
}

string Text::Level5::attackStrategyOptions3() {
    return "Тактика:\n1. Защита\n2. Атака";
}

string Text::Level5::ifDefenseResult() {
    return "Защита! -4 врага убито";
}

string Text::Level5::ifAttackResult() {
    return "Атака! Несколько врагов убито";
}

string Text::Level5::howContinueOptions() {
    return "Продолжить:\n1. Стрельба\n2. РПГ\n3. Гранаты";
}

string Text::Level5::ifPatronsResult() {
    return "Враг использовал РПГ! Вы погибли.";
}

string Text::Level5::rpgOrGrenadeOptions() {
    return "Действие:\n1. Стрелять\n2. Гранаты\n3. РПГ x2";
}

string Text::Level5::noRpgResult() {
    return "Неэффективно! Вас уничтожили.";
}

string Text::Level5::winFinal() {
    return "ПОБЕДА! Вы стали наркокоролем!";
}