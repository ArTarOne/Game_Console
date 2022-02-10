#include "exc_from_book_class.hpp"

// глава 8 кгниги. -------------------------------------------------------------
// class CritterBegin
void CritterBegin::Greet() {
    std::cout << "Hi. I am a critter. My Hunger level is " << m_Hunger << "\n";
}

CritterBegin::CritterBegin(int hunger) { // определение конструктора
    std::cout << "A new critter has been born!" << std::endl;
    m_Hunger = hunger;
}

// end class CritterBegin

// class CritterPrivate
CritterPrivate::CritterPrivate(int hunger): //  инициализатор-конструктор
    m_Hunger(hunger) {
    std::cout << "A new critter private has been born!" << std::endl;
}

int CritterPrivate::GetHunger() const {
    return m_Hunger;
}

void CritterPrivate::SetHunger(int hunger) {
    if(hunger < 0)
        std::cout << " You can not set a critter privet to a negative number.\n\n";
    else
        m_Hunger = hunger;
}
// end class CritterPrivet

// class CritterStatic
int CritterStatic::s_Total = 0; // инициализация статической переменной члена -данных

CritterStatic::CritterStatic(int hung):
    m_Hunger(hung) {
    std::cout << "A new critter static has been born!" << std::endl;
    s_Total++;
}

int CritterStatic::GetTotal() {
    return s_Total;
}
// end class CritterStatic

// class CritterBook
CritterBook::CritterBook(int hung, int bor):
    m_Hunger(hung),
    m_Boredom(bor) {
}

inline int CritterBook::GetMode() const {
    return m_Hunger + m_Boredom;
}

void CritterBook::PassTime(int time) {
    m_Hunger += time;
    m_Boredom += time;
}

void CritterBook::Talk() {
    enum emtion { OKAY = 5, FRUSTRATED = 10, MAD = 15};
    std::cout << "i'm CritterBook and I feel: ";
    int mode = GetMode();

    if(mode > MAD)
        std::cout << "mad. \n";
    else if(mode > FRUSTRATED)
        std::cout << "frustated. \n";
    else if(mode > OKAY)
        std::cout << "okay. \n";
    else
        std::cout << "happy. \n";
    PassTime();
}

void CritterBook::Eat(int food) {
    std::cout << "Brruuppp.\n";
    m_Hunger -= food;
    if(m_Hunger < 0)
        m_Hunger = 0;
    PassTime();
}

void CritterBook::Play(int fun) {
    std::cout << "Wheee!\n";
    m_Boredom -= fun;
    if(m_Boredom < 0)
        m_Boredom = 0;
    PassTime();
}
// end class CritterBook

// глава 9 кгниги. -------------------------------------------------------------
// class Critter9
Critter9::Critter9(const std::string & name):
    m_Name(name) { // non body
}

inline std::string Critter9::GetName() const {
    return m_Name;
}
// end class Critter9 */

// class CrittersFarm
CrittersFarm::CrittersFarm(int spaces) {
    m_Critters.reserve(spaces);
}

void CrittersFarm::AddCritter(const Critter9 & rCritter) {
    m_Critters.push_back(rCritter);
}

void CrittersFarm::RollCall() const {
    for(std::vector <Critter9> ::const_iterator item = m_Critters.begin();
        item != m_Critters.end(); item++) {
    std::cout << item->GetName() << "\there" << std::endl;
    }
}
// end class CrittersFarm

// class CritterFriend
CritterFriend::CritterFriend(const std::string & name):
    m_Name(name) { // non body
}

// глобальная дружественная функция, которая может получить
// доступ ко всем членам объекта класса CritterFriend
void f9_PeekCretter(const CritterFriend & rCritter) {
    std::cout << rCritter.m_Name << std::endl;
}

// глобальная дружественная функция, которая может получить
// доступ ко всем членам объекта класса CritterFriend
// перегруженный оператор '<<', позволяет отправлять объекты типа CritterFriend
// в поток std::cout
std::ostream & operator << (std::ostream & os, const CritterFriend & rCritter) {
    os << "CritterFriend Object - ";
    os << "m_Name: " << rCritter.m_Name;
    return os;
}
// end class CritterFriend */

// class CritterHeap
CritterHeap::CritterHeap(const std::string & name, int age) {
    std::cout << "Constructor called.\n";
    m_pName = new std::string(name);
    m_Age = age;
}

CritterHeap::~CritterHeap() {
    std::cout << "\t~Destructor called.\n";
    delete m_pName;
}

CritterHeap::CritterHeap(const CritterHeap & rCrtH) {
    std::cout << "Copy constructor called.\n";
    m_pName = new std::string(*(rCrtH.m_pName));
    m_Age = rCrtH.m_Age;
}
// определение перегруженной операции присваивания
CritterHeap & CritterHeap::operator = (const CritterHeap &rCrt) {
    std::cout << "Overload Assigment Operator \'=\' called\n";
    if(this != &rCrt) {
        delete m_pName;
        m_pName = new std::string(*(rCrt.m_pName));
        m_Age = rCrt.m_Age;
    }
    return *this;
}

void CritterHeap::Greet() {
    std::cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old. ";
    std::cout << "&m_pName" << &m_pName << std::endl;
}

void f9_testDestruction() {
    CritterHeap toDestroy("Rover", 3);
    toDestroy.Greet();
}
void f9_testCopyConstructor(CritterHeap aCopy) {
    aCopy.Greet();
}
void f9_testAssignmentOp() {
    std::cout << "f9_testAssignmentOp run\n";
    CritterHeap crt1("Critter 1", 7);
    CritterHeap crt2("Critter 2", 12);
    std::cout << "crt1 and crt2 -> Greet(): \n";
    crt1.Greet();
    crt2.Greet();
    std::cout << "crt1 = crt2 \n";
    crt1 = crt2;
    std::cout << "crt1 and crt2 -> Greet(): \n";
    crt1.Greet();
    crt2.Greet();

    CritterHeap crt3("CRT 3", 23);
    crt3 = crt3;
    crt3.Greet();
}
// end class CritterHeap */

// class C9_Player
C9_Player::C9_Player(const std::string & rName):
    m_Name(rName),
    m_pNextPlayer(nullptr) { // zero body class
}

inline std::string C9_Player::GetName() const {
    return m_Name;
}
inline C9_Player * C9_Player::GetNextPlayer() const {
    return m_pNextPlayer;
}

inline void C9_Player::SetNextPlayer(C9_Player * const pPlayer) {
    m_pNextPlayer = pPlayer;
}
// end class C9_Player // */

// class C9_LobbyPlayer
C9_LobbyPlayer::C9_LobbyPlayer():
    m_pHeadPlayer(nullptr) { // zero body class
}
C9_LobbyPlayer::~C9_LobbyPlayer() {
    ClearAll();
}

void C9_LobbyPlayer::AddPlayer() {
    // создать нового игрока...
    std::cout << "Please enter the name of the new C9_Player: ";
    std::string name;
    std::cin >> name;

    C9_Player * pNewP = new C9_Player(name);
    // если список пуст, поставить игрока в начала списка игроков
    if(m_pHeadPlayer == nullptr)
        m_pHeadPlayer = pNewP;
    else { //в противном случае гайти конец  списка.
        C9_Player * pIterP = m_pHeadPlayer;
        while(pIterP->GetNextPlayer() != nullptr)
            pIterP = pIterP->GetNextPlayer();
        // Добавляем нового игрока в конец списЬка
        pIterP->SetNextPlayer(pNewP);
    }
}
void C9_LobbyPlayer::ClearAll() { // чистит всех игроков
    while(m_pHeadPlayer != nullptr)
        RemovePlayer();
}
void C9_LobbyPlayer::RemovePlayer() {
    if(m_pHeadPlayer == nullptr)
        std::cout << "The LobbyPlayer is empty. No one to remove!\n";
    else {
        C9_Player * pTempPlayer = m_pHeadPlayer;
        m_pHeadPlayer = m_pHeadPlayer->GetNextPlayer();
        delete pTempPlayer;
    }
}

std::ostream & operator << (std::ostream & out, const C9_LobbyPlayer & rLob) {
    C9_Player * pIterP = rLob.m_pHeadPlayer;
    out << "\nHere's who's in the game C9_LobbyPlayer: \n";
    if(pIterP == nullptr)
        out << "The C9_LobbyPlayer is empty, sorry.\n";
    else
        while(pIterP != nullptr) {
            out << "Player name is: " << pIterP->GetName() << std::endl;
            pIterP = pIterP->GetNextPlayer();
        }
    return out;
}
// end class C9_LobbyPlayer // */

// глава 10 кгниги. -------------------------------------------------------------
// class f10_Enemy
f10_Enemy::f10_Enemy():
    m_Damage(10) { //zero body class
}
void f10_Enemy::Attack() const {
    std::cout << "Attack inflicts \'" << m_Damage << "\' damage point!\n";
}
// end class f10_Enemy // */

// class f10_Boss1
f10_Boss1::f10_Boss1():
    m_MultiDamage(3) { //zero body class
}
void f10_Boss1::SpecialAttack() const {
    std::cout << "Special attack inflicts \'" << (m_Damage * m_MultiDamage)
              << "\' damage points.\n";
}
// end class f10_Boss1 // */

// class f10_Enemy_protec
f10_Enemy_protec::f10_Enemy_protec():
    m_Damage(15) { // zero body class
}
void f10_Enemy_protec::Attack() const {
    std::cout << "Attack inflicts \'" << m_Damage << "\' damage point!\n";
}
// end class f10_Enemy_protec // */
f10_Boss2::f10_Boss2():
    m_MultiDamage(3) { //zero body class
}
void f10_Boss2::SpecialAttack() const {
    std::cout << "Special attack inflicts \'" << (m_Damage * m_MultiDamage)
              << "\' damage points.\n";
}
// end class f10_Boss2 // */

// class f10_Enemy_virtual
f10_Enemy_virtual::f10_Enemy_virtual(int dmg):
    m_Dmg(dmg) { // zero body class constructor
}
inline void f10_Enemy_virtual::Taunt() const {
    std::cout << "The Enemay virtual says he will fight you win.\n";
}
inline void f10_Enemy_virtual::Attack() const {
    std::cout << "Attack! Inflicts \'" << m_Dmg << "\' damage points.\n";
}
// end class f10_Enemy_virtual

// class f10_Boss3
f10_Boss3::f10_Boss3(int damage_boss):
    f10_Enemy_virtual(damage_boss) { // zero body class constructor
}
inline void f10_Boss3::Taunt() const {
    std::cout << "The Boss 3.0 says he will end your pitiful existence.\n";
}
inline void f10_Boss3::Attack() const {
    f10_Enemy_virtual::Attack();
    std::cout << "And laught heartily at your.\n";
}
// end class f10_Boss3 // */

// class f10_Enemy_polymorph
f10_Enemy_polymorph::f10_Enemy_polymorph(int dmg) {
    m_pDmg = new int(dmg);
}
f10_Enemy_polymorph::~f10_Enemy_polymorph() {
    std::cout << "In Enemy polymorph Destructor, deleting m_pDmg.\n";
    delete m_pDmg;
    m_pDmg = nullptr;
}
void f10_Enemy_polymorph::Attack() const {
    std::cout << "An enemy polymorph attacts and inflicts \'" << *m_pDmg << "\' damage points.\n";
}
// end class f10_Enemy_polymorph // */

// class f10_Boss4
f10_Boss4::f10_Boss4(int multi) {
    m_pMulti = new int(multi);
}
f10_Boss4::~f10_Boss4() {
    std::cout << "In Boss 4.0 Destructor, deleting m_pMulti.\n";
    delete m_pMulti;
    m_pMulti = nullptr;
}
void f10_Boss4::Attack() const{
    std::cout << "A Boss 4.0 attacks and inflicts \'" << (*m_pDmg) * (*m_pMulti)
              << "\' damage points.\n";
}
// end class f10_Boss4 // */

// class f10_Creature
f10_Creature::f10_Creature(int health):
    m_Health(health) { // zero body class constructor
}
f10_Creature::~f10_Creature() {
    std::cout << "Destructor Creature is runing.\n";
}
void f10_Creature::ShowHealth() const {
    std::cout << "Health: \'" << m_Health << "\'\n";
}
// end class f10_Creature // */

// class f10_Orc
f10_Orc::f10_Orc(int orcHealth):
    f10_Creature(orcHealth) { // zero body class constructor
}
f10_Orc::~f10_Orc() {
    std::cout << "Destructor Orc is runing.\n";
}
void f10_Orc::Greet() const {
    std::cout << "The f10_Orc grants hello.\n";
}
// end class f10_Orc // */
// ++++++++++++++++++++++++++++++++++++++++
// проект blackJack ---------------10 глава ------------------------------------
// перешруженная функция вывода в поток std::cout

// class BJ_Card
BJ_Card::BJ_Card(rank r, suit s, bool iFace) :
    m_Rank(r), m_Suit(s), m_IsFaceUp(iFace) { // zero body class constructor
}
int BJ_Card::GetValue() const {
    // если карта лицом вниз
    const int C_TEN = 10;
    int value = 0;
    if(m_IsFaceUp) {
        // значение - число указанное на карте
        value = m_Rank;
        // значение равно 10 для открытых карт
        //! проверить работоспособность этой конструкции
        (value > C_TEN) ? (value = C_TEN) : value;
    }
    return  value;
    //return  (value > C_TEN) ? C_TEN : value;;
}
inline void BJ_Card::Flip() {
    m_IsFaceUp = !m_IsFaceUp;
}
// end class BJ_Card

// class BJ_Hand
BJ_Hand::BJ_Hand(int reserv) {
    m_Cards.reserve(reserv);
}
BJ_Hand::~BJ_Hand() {
    Clear();
}
void BJ_Hand::Clear() {
    // проходим по вектору через итератор, освобождаем память
    std::vector <BJ_Card * >::iterator iter;
    for(iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
        delete *iter; // удаляется объект BJ_Card
        *iter = nullptr;
    }
    // очищаем вектор указателей
    m_Cards.clear();
}
inline void BJ_Hand::AddCard(BJ_Card *pCard) {
    m_Cards.push_back(pCard);
}
int BJ_Hand::GetTotal() const {
    int MAX_ONE_VALUE = 11; // очков в одной карте
    // если карт в руке нет
    if(m_Cards.empty())
        return 0;
    // Если первая карта имеет значение 0, то она лежит рубашкой вверх, вернуть 0
    if(m_Cards[0]->GetValue() == 0)
        return 0;
    // находим сумму очков всех карт, Туз = 1
    int total = 0;
    std::vector <BJ_Card *>::const_iterator c_iter;
    for(c_iter = m_Cards.begin(); c_iter != m_Cards.end(); c_iter++)
            total += (*c_iter)->GetValue();
    // отределяем туз в руке
    bool inHandAce = false;
    for(c_iter = m_Cards.begin(); c_iter != m_Cards.end(); c_iter++) {
        if((*c_iter)->GetValue() == BJ_Card::ACE)
            inHandAce = true;
    }
    // если в руке туз, а сумма маленькая, туз даёт 11 очклв
    if(inHandAce and (total <= MAX_ONE_VALUE))
        total += (MAX_ONE_VALUE - 1); // туз = 1 очку +10 = 11 очков
    return total;
}
// end class BJ_Hand // */

// end class BJ_GenericPlayer
BJ_GenericPlayer::BJ_GenericPlayer(const std::string & rName):
    m_NamePlayer(rName) { // zero body class constructor
}
BJ_GenericPlayer::~BJ_GenericPlayer() {// zero body ~destructor
}
inline bool BJ_GenericPlayer::IsBusted() const {
    return (GetTotal() > 21);
}
inline void BJ_GenericPlayer::Bust() const {
    std::cout << m_NamePlayer << " busts...\n";
}
// end class BJ_GenericPlayer // */
