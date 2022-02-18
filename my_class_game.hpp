#ifndef MY_CLASS_GAME_HPP
#define MY_CLASS_GAME_HPP

#include "function_game.hpp"

// 8 глава книги, мои классы!!! ================================================

class MyCritter{
    int m_Hunger;
    int m_Boredom;
public:
    void Talk();
    void Status(); // показать точное значение Hunger и Boredom
    void Eat(int food = 4); // прототип статической функции-члена
    void Play(int fun = 4);
    MyCritter(int hung = 0, int bor = 0);
private:
    int GetHungre() const;
    int GetBoredom() const;
    void PassTime(int time = 1);
};

// 9 глава книги, мои классы!!! ================================================

class myPlayer {
    std::string mm_Name;
    myPlayer * mm_pNextPlayer; // указател на следующего игрока
    friend std::ostream & operator << (std::ostream & out, const myPlayer & rPlr);
public:
    myPlayer(const std::string & rName = "");
    std::string myGetName() const;
    myPlayer * myGetNextPlayer() const;
    void mySetNextPlayer(myPlayer * const pPlayer);
};

class myLobbyGame {
    myPlayer * mm_pHead; // начало списка
    myPlayer * mm_pTail; // rjytw списка
    friend std::ostream & operator << (std::ostream & outPl, const myLobbyGame & rLob);
public:
    myLobbyGame();
    ~myLobbyGame();
    void myAddPlayer();
    void myRemovePlayer();
    void myClearAll();
    void myGetTail(); // получение хвоста
};

// 10 глава книги, мои классы!!! ================================================

class myEnemyProtect {
public:
    myEnemyProtect(const int dmf = 20);
    void Attack() const;
protected:
    int m_Dmg;
};

class myBoss : public myEnemyProtect {
public:
    myBoss();
    void SpecialAttack() const;
protected:
    int m_SpecialDmg;
};

class myFinalBoss : public myBoss {
public:
    myFinalBoss();
    void UltraAttack() const;
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class myCreature { // абстрактный класс
public:
    myCreature(int health = 100);
    virtual ~myCreature();
    virtual void Greet() const = 0; // чистая виртуальная функция-член
    virtual void ShowHealth() const;
protected:
    int m_Health;
};

class myOrc : public myCreature {
public:
    myOrc(int orcHealth = 150);
    virtual ~myOrc();
    void Greet() const override; // определение виртуальной функции для конкретного класса
};

class myOrcBoss : public myOrc {
public:
    myOrcBoss(int bossHealth = 185);
    virtual ~myOrcBoss();
    void Greet() const override; // определение виртуальной функции для конкретного класса
};
/* game Balc Jack  ___________________________________________________________*/

class myCard {
public:
    enum rank {R_ACE = 1, R_TWO, R_THREE, R_FOUR, R_FIVE, R_SIX, R_SEVEN,
               R_EIGHT, R_NINE, R_TEN, R_JACK, R_QUEEN, R_KING};
    enum suit {S_CLUBS, S_DIAMOND, S_HEARTS, S_SPADERS};
// прегружаем оператор <<, что бы можно было отображать объект в стандартный поток вывода
    friend std::ostream & operator << (std::ostream & out, const myCard & rCard);
    myCard(rank r = R_ACE, suit s = S_SPADERS, bool iFace = true);
    int GetValue() const; // возвращает значение карты от 1 до 11
    void Flip(); // переворачивает карту лицом вниз или вверх
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

class myHand {
public:
    myHand(int reserv = 7);
    ~myHand();
    void AddCard(myCard * pCard); // добавляем карту в руку // const?
    void Clear(); // очищаем руку от карт
    // получаем сумму очков в руке, присваиваем Тузу 1 или 11
    // в зависимости от ситуации
    int GetTotal() const;
protected:
    std::vector <myCard * > m_Cards;
};

class myGenericPlayer : public myHand {
// печать ввод-вывод
friend std::ostream & operator << (std::ostream & out, const myGenericPlayer & rPlayer);
public:
    myGenericPlayer(const std::string & rName = "");
    virtual ~myGenericPlayer();
    virtual bool IsHitt() const = 0; // показывает, хочет ли игрок продолжать брать карты
    bool IsBusted() const; // Возвращает значение, если у игрока "перебор", больше 21
    void Bust() const; // объявляет, что у игрока перебор
protected:
    std::string m_NamePlayer;
};

class myPlayerBJ : public myGenericPlayer {
public:
    myPlayerBJ(const std::string & rName = "");
    virtual ~myPlayerBJ();
    virtual bool IsHitt() const; // показывае, хочет ли игрок продолжать брать карты
    void Win() const; // объявляет, что игрок победил
    void Lose() const; // объявляет, что игрок проиграл
    void Push() const; // объявляет ничью
};

class myHouse : public myGenericPlayer {
public:
    myHouse(const std::string & rNameHouse = "House");
    virtual ~myHouse();
    virtual bool IsHitt() const; // показывает, хочет ли игрок продолжать брать карты
    void FlipFirstCard(); // переворачивает первую карту
};

class myDeck : public myHand {
public:
    myDeck();
    virtual ~myDeck();
    int GetRemainingCard() const; // получить остаоок карт
    void Populate(); // создание колоды карт из 52 карт
    void Shuffle(); // Тусование колоды карт
    void Deal(myHand & rHand); // раздаёт одну карту в руку
    void AdditionalMore(myGenericPlayer & rGPlayer); // даёт дополнительные карты игроку
};

class myGameBJ {
    myDeck m_Deck;
    myHouse m_House;
    std::vector <myPlayerBJ> m_Players;
    void NewDeck(); // создать новую колоду
public:
    myGameBJ(const std::vector <std::string> & rNameVec);
    ~myGameBJ();
    void StartPlay(); // запустить игру в BlackJack
};

// перегруженные операторы вывода BJ
std::ostream & operator << (std::ostream & out, const myCard & rCard);
std::ostream & operator << (std::ostream & out, const myGenericPlayer & rGPlr);
// game Black JAck __________________________________________________________ */

#endif //MY_CLASS_GAME_HPP
