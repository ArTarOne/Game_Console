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

/* game Balc Jack  ___________________________________________________________*/
/*
class BJ_Card {
public:
    enum rank {R_ACE = 1, R_TWO, R_THREE, R_FOUR, R_FIVE, R_SIX, R_SEVEN,
               R_EIGHT, R_NINE, R_TEN, R_JACK, R_QUEEN, R_KING};
    enum suit {S_CLUBS, S_DIAMOND, S_HEARTS, S_SPADERS};
// прегружаем оператор <<, что бы можно было отображать объект в стандартный поток вывода
    friend std::ostream & operator << (std::ostream & out, const BJ_Card & rCard);
    BJ_Card(rank r = R_ACE, suit s = S_SPADERS, bool iFace = true);
    int GetValue() const; // возвращает значение карты от 1 до 11
    void Flip(); // переворачивает карту лицом вниз или вверх
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

class BJ_Hand {
public:
    BJ_Hand(int reserv = 7);
    ~BJ_Hand();
    void AddCard(BJ_Card * pCard); // добавляем карту в руку // const?
    void Clear(); // очищаем руку от карт
    // получаем сумму очков в руке, присваиваем Тузу 1 или 11
    // в зависимости от ситуации
    int GetTotal() const;
protected:
    std::vector <BJ_Card * > m_Cards;
};

class BJ_GenericPlayer : public BJ_Hand {
// печать ввод-вывод
friend std::ostream & operator << (std::ostream & out, const BJ_GenericPlayer & rPlayer);
public:
    BJ_GenericPlayer(const std::string & rName = "");
    virtual ~BJ_GenericPlayer();
    virtual bool IsHitt() const = 0; // показывает, хочет ли игрок продолжать брать карты
    bool IsBusted() const; // Возвращает значение, если у игрока "перебор", больше 21
    void Bust() const; // объявляет, что у игрока перебор
protected:
    std::string m_NamePlayer;
};

class BJ_Player : public BJ_GenericPlayer {
public:
    BJ_Player(const std::string & rName = "");
    virtual ~BJ_Player();
    virtual bool IsHitt() const; // показывае, хочет ли игрок продолжать брать карты
    void Win() const; // объявляет, что игрок победил
    void Lose() const; // объявляет, что игрок проиграл
    void Push() const; // объявляет ничью
};

class BJ_House : public BJ_GenericPlayer {
public:
    BJ_House(const std::string & rNameHouse = "House");
    virtual ~BJ_House();
    virtual bool IsHitt() const; // показывает, хочет ли игрок продолжать брать карты
    void FlipFirstCard(); // переворачивает первую карту
};

class BJ_Deck : public BJ_Hand {
public:
    BJ_Deck();
    virtual ~BJ_Deck();
    void Populate(); // создание колоды карт из 52 карт
    void Shuffle(); // Тусование колоды карт
    void Deal(BJ_Hand & rHand); // раздаёт одну карту в руку
    void AdditionalMore(BJ_GenericPlayer & rGPlayer); // даёт дополнительные карты игроку
};

class BJ_Game {
    BJ_Deck m_Deck;
    BJ_House m_House;
    std::vector <BJ_Player> m_Players;
public:
    BJ_Game(const std::vector <std::string> & rNameVec);
    ~BJ_Game();
    void StartPlay(); // запустить игру в BlackJack
};

// перегруженные операторы вывода BJ
std::ostream & operator << (std::ostream & out, const BJ_Card & rCard);
std::ostream & operator << (std::ostream & out, const BJ_GenericPlayer & rGPlr);
// game Black JAck __________________________________________________________ */


#endif //MY_CLASS_GAME_HPP
