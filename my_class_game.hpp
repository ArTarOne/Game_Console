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

#endif //MY_CLASS_GAME_HPP
