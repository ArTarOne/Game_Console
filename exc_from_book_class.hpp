#ifndef EXC_FROM_BOOK_CLASS
#define EXC_FROM_BOOK_CLASS

#include "function_game.hpp"
// классы из книги "Изучаем С++ через программирование игр" - Майкд Доусон
// практика с функциями...


// 8 глава ---------------------------------------------------------------------
class CritterBegin {
    public:
        CritterBegin(int hunger = 0); // прототип конструктор класса (Construction Critter)
        int m_Hunger; // член данных
        void Greet(); //прототип члена функции
}; // точка-запятая, конец класса Critter!

class CritterPrivate {
    public:
    CritterPrivate(int hunger = 0);
    int GetHunger() const; // const выпячено...
    void SetHunger(int hunger = 0);

    private: // закрытый раздел
    int m_Hunger;
};

class CritterStatic {
public:
    static int s_Total; // объявление статической переменной
    static int GetTotal(); // прототип статической функции-члена
    CritterStatic(int hung = 0);
private:
    int m_Hunger;
};

///
/// \brief CritterBook
/// Описание планирования игры - Тамагочи
/// \details
/// Создать Тамагочи
/// Если пользователь не собирается завершить игру
///         Представить мень с вариантами выбора
///     Если пользователь хочет послушать Тамагочи
///         Предложить Тамагочи что-то сказать
///     Если пользователь хочет покормить Тамагочи
///         Предложить тамагочи поесть
///     Если пользователь хочет поиграть с Тамагочи
///         Предложить Тамагочи поиграть
/// \return
///

class CritterBook{
    int m_Hunger;
    int m_Boredom;
public:
    void Talk();
    void Eat(int food = 4); // прототип статической функции-члена
    void Play(int fun = 4);
    CritterBook(int hung = 0, int bor = 0);
private:
    int GetMode() const;
    void PassTime(int time = 1);
};

// 9 глава ---------------------------------------------------------------------
class Critter9 {
    std::string m_Name;
public:
    Critter9(const std::string & name = " ");
    std::string GetName() const;
}; //*/

class CrittersFarm {
    std::vector <Critter9> m_Critters;
public:
    CrittersFarm(int spaces = 1);
    void AddCritter(const Critter9 & rCritter);
    void RollCall() const;
};

class CritterFriend {
    // Указывам, что следующие глобальные функции являюься
    // дружественными по отношению к калассу CritterFriend
    friend void f9_PeekCretter(const CritterFriend & rCritter);
    friend std::ostream & operator << (std::ostream & os, const CritterFriend & rCritter);
public:
    CritterFriend(const std::string & name = "");
private:
    std::string m_Name;
};
// Дружественная ффункция для класса CritterFriend
void f9_PeekCretter(const CritterFriend & rCritter);
// перегрузка оператора для класса CritterFriend
std::ostream & operator << (std::ostream & os, const CritterFriend & rCritter);

class CritterHeap {
    std::string * m_pName;
    int m_Age;
public:
    CritterHeap(const std::string & name = "", int age = 0);
    ~CritterHeap(); //прототипо деструктора
    CritterHeap(const CritterHeap & rCrtH); // прототип конструктор копирования
    // перегрузка оператора присваивания
    CritterHeap & operator = (const CritterHeap & rCrt);
    void Greet();
};

void f9_testDestruction();
void f9_testCopyConstructor(CritterHeap aCopy); // передача по значению
void f9_testAssignmentOp();


class C9_Player {
    std::string m_Name;
    C9_Player * m_pNextPlayer; // указател на следующего игрока
public:
    C9_Player(const std::string & rName = "");
    std::string GetName() const;
    C9_Player * GetNextPlayer() const;
    void SetNextPlayer(C9_Player * const pPlayer);
};

class C9_LobbyPlayer {
    C9_Player * m_pHeadPlayer; // начало списка
    friend std::ostream & operator << (std::ostream & out, const C9_LobbyPlayer & rLob);
public:
    C9_LobbyPlayer();
    ~C9_LobbyPlayer();
    void AddPlayer();
    void RemovePlayer();
    void ClearAll();
};

// 10 глава --------------------------------------------------------------------

class f10_Enemy {
    //int m_Damage;
public:
    int m_Damage;
    f10_Enemy();
    void Attack() const;
};

class f10_Boss1 : public f10_Enemy {
    int m_MultiDamage;
public:
    //int m_MultiDamage;
    f10_Boss1();
    void SpecialAttack() const;
};

class f10_Enemy_protec {
protected:
    int m_Damage;
public:
    f10_Enemy_protec();
    void Attack() const;
};

class f10_Boss2 : public f10_Enemy_protec {
    int m_MultiDamage;
public:
    //int m_MultiDamage;
    f10_Boss2();
    void SpecialAttack() const;
};

class f10_Enemy_virtual {
    int m_Dmg;
public:
    f10_Enemy_virtual(int dmg = 12);
    // функция создаётся как виртуальная для последующего переопределения
    void virtual Taunt() const;
    // функция создаётся как виртуальная для последующего переопределения
    void virtual Attack() const;
};

class f10_Boss3 : public f10_Enemy_virtual {
public:
    f10_Boss3(int dmg_boss = 45);
    // virtual опционально в данном случае
    void virtual Taunt() const;
    //в данном случае уберем virtual
    void Attack() const;
};

class f10_Enemy_polymorph {
public:
    f10_Enemy_polymorph(int dmg = 18);
    virtual ~f10_Enemy_polymorph();
    void virtual Attack() const;
protected:
    int * m_pDmg;
};

class f10_Boss4 : public f10_Enemy_polymorph {
public:
    f10_Boss4(int multi = 3);
    virtual ~f10_Boss4();
    void virtual Attack() const;
protected:
    int * m_pMulti;
};

class f10_Creature { // абстрактный класс
public:
    f10_Creature(int health = 100);
    virtual ~f10_Creature();
    virtual void Greet() const = 0; // чистая виртуальная функция-член
    virtual void ShowHealth() const;
protected:
    int m_Health;
};

class f10_Orc : public f10_Creature {
public:
    f10_Orc(int orcHelath = 150);
    virtual ~f10_Orc();
    virtual void Greet() const; // определение виртуальной функции для конкретного класса
};
// проект blackJack ---------------10 глава ------------------------------------

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
    BJ_House(const std::string & rNameHouse);
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

#endif //EXC_FROM_BOOK_CLASS
