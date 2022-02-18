#include "my_class_game.hpp"
// 8 глава книги, мои классы!!
// class myCritter
MyCritter::MyCritter(int hung, int bor):
    m_Hunger(hung),
    m_Boredom(bor) {
}

inline int MyCritter::GetHungre() const {
    return m_Hunger;
}

inline int MyCritter::GetBoredom() const {
    return m_Boredom;
}

void MyCritter::PassTime(int time) {
    m_Hunger += time;
    m_Boredom += time;
}

void MyCritter::Talk() {
    enum emotionCritter { OKAY = 5, FRUSTRATED = 10, MAD = 15};
    enum statusCritter { OK_ = 3, FRUST_ = 6, MAD_ = 10};
    std::cout << "i'm CritterBook and I feel: ";
    int hunger = GetHungre();
    int boredom = GetBoredom();
    int mode = hunger +  boredom;
    // mode
    if(mode > MAD)
        std::cout << "mad. ";
    else if(mode > FRUSTRATED)
        std::cout << "frustated. ";
    else if(mode > OKAY)
        std::cout << "okay. ";
    else
        std::cout << "happy. ";
    // hunger
    if(hunger > MAD_)
        std::cout << "Terribly hungry!!! And";
    else if(hunger > FRUST_)
        std::cout << "I want to eat... And";
    else if(hunger > OK_)
        std::cout << "I well-fed and";
    else
        std::cout << "I am fully ate and";
    // boredom
    if(boredom > MAD_)
        std::cout << " dying of boredom!!!\n";
    else if(boredom > FRUST_)
        std::cout << " bored me...\n";
    else if(boredom > OK_)
        std::cout << " not bored.\n";
    else
        std::cout << " not bored at all.\n";
    PassTime();
}

void MyCritter::Status(){
    std::cout << "My level hunger is: " << m_Hunger << std::endl;
    std::cout << "My level boredom is: " << m_Boredom << std::endl;
    PassTime();
}

void MyCritter::Eat(int food) {
    std::cout << "Brruuppp.\n";
    m_Hunger -= food;
    if(m_Hunger < 0)
        m_Hunger = 0;
    PassTime();
}

void MyCritter::Play(int fun) {
    std::cout << "Wheee!\n";
    m_Boredom -= fun;
    if(m_Boredom < 0)
        m_Boredom = 0;
    PassTime();
}
// end class myCritter

// 9 глава книги, мои классы!! =================================================
// class myLobby
myLobbyGame::myLobbyGame():
    mm_pHead(nullptr),
    mm_pTail(mm_pHead){ // zero body class
    std::cout << "\nConstr Lobby run\n";
}
myLobbyGame::~myLobbyGame() {
    std::cout << "\nDestr Lobby run\n";
    //myClearAll();
}

void myLobbyGame::myAddPlayer() {
    // создать нового игрока...
    std::cout << "Please enter the name of the new myPlayer: ";
    std::string getName;
    std::cin >> getName;
    //std::cout << "\n\t\'" << getName << "\' - input text\n";

    myPlayer * pNewPlr = new myPlayer(getName);
    // если список пуст, поставить игрока в начала списка игроков
    if(mm_pHead == nullptr)
        mm_pTail = mm_pHead = pNewPlr;
    else { //в противном случае гайти конец  списка.
        // доработать хвост тут.
        // Добавляем нового игрока в конец списЬка
        mm_pTail->mySetNextPlayer(pNewPlr);
        // обновляем "хвост"
        mm_pTail = mm_pTail->myGetNextPlayer();
    }// */
}
void myLobbyGame::myClearAll() { // чистит всех игроков
    while(mm_pHead != nullptr)
        myRemovePlayer();
}
void myLobbyGame::myRemovePlayer() {
    if(mm_pHead == nullptr) {
        std::cout << "The LobbyPlayer is empty. No one to remove!\n";
        mm_pTail = nullptr;
    }
    else {
        myPlayer * pTmpPlr = mm_pHead;
        mm_pHead = mm_pHead->myGetNextPlayer();
        delete pTmpPlr;
    }
    if(mm_pHead == nullptr)
        mm_pTail = mm_pHead;
}

void myLobbyGame::myGetTail() {
    if(mm_pTail != nullptr)
        std::cout << "   Tail-Tail: " << *mm_pTail << " is tail!";
    else
        std::cout << "   Tail-Tail: nullptr!\n";
}

std::ostream & operator << (std::ostream & out, const myLobbyGame & rLob) {
    myPlayer * pIterP = rLob.mm_pHead;
    out << "\nHere's who's in the game myLobbyGame:";
    if(pIterP == nullptr)
        out << "The myLobbyGame is empty, sorry.\n";
    else
        while(pIterP != nullptr) {
            out << *pIterP;
            pIterP = pIterP->myGetNextPlayer();
        } // */
    out << "\n";
    return out;
}
// end class myLobby //*/

// class myPlayer
myPlayer::myPlayer(const std::string & rName):
    mm_Name(rName),
    mm_pNextPlayer(nullptr) { // zero body class
}

inline std::string myPlayer::myGetName() const {
    return mm_Name;
}
inline myPlayer * myPlayer::myGetNextPlayer() const {
    return mm_pNextPlayer;
}

inline void myPlayer::mySetNextPlayer(myPlayer * const pPlayer) {
    mm_pNextPlayer = pPlayer;
}
std::ostream & operator << (std::ostream & outPl, const myPlayer & rPlr) {
    //std::cout << "\tTest myPlayer \'<<\' in cout!\n";
    outPl << "\nname myPlayer: " << rPlr.mm_Name;
    return outPl;
}
// end class myPlayer // */

// 10глава книги, мои классы!! =================================================

// class myEnemyProtect * * *
myEnemyProtect::myEnemyProtect(const int dmg) : m_Dmg(dmg) { // zero body class
}
void myEnemyProtect::Attack() const {
    std::cout << "Attack inflicts \'" << m_Dmg << "\' damage point!\n";
}
// end class myEnemyProtect // */

// class myBoss * * *
myBoss::myBoss() : m_SpecialDmg(m_Dmg * 4){ //zero body class
}
void myBoss::SpecialAttack() const {
    std::cout << "Special attack inflicts \'" << (m_Dmg + m_SpecialDmg)
              << "\' damage points.\n";
}
// end class myBoss // */

// class myFinalBoss  * * *
myFinalBoss::myFinalBoss() { //zero body class
}
void myFinalBoss::UltraAttack() const {
    // в 10 раз больше урона
    std::cout << "Ultra attack inflicts \'" << ((m_Dmg + m_SpecialDmg) * 10)
              << "\' damage points.\n";
}
// end class myFinalBoss // */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// class myCreature * * *
myCreature::myCreature(int health):
    m_Health(health) { // zero body class constructor
}
myCreature::~myCreature() {
    std::cout << "Destructor myCreature is runing.\n";
}
void myCreature::ShowHealth() const {
    std::cout << "Health: \'" << m_Health << "\'\n";
}
// end class myCreature // */

// class myOrc * * *
myOrc::myOrc(int orcHealth):
    myCreature(orcHealth) { // zero body class constructor
}
myOrc::~myOrc() {
    std::cout << "Destructor myOrc is runing.\n";
}
void myOrc::Greet() const {
    std::cout << "The myOrc grants hello.\n";
}
// end class myOrc // */

// class myOrcBoss * * *
myOrcBoss::myOrcBoss(int bossHealth) : myOrc(bossHealth) { // zero body class constructor
}
myOrcBoss::~myOrcBoss() {
    std::cout << "Destructor myOrcBoss is runing.\n";
}
void myOrcBoss::Greet() const {
    std::cout << "The myOrcBoss growls hello.\n";
}
// end class myFinalBoss // */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// проект myblackJack ----------- 10 глава --------- LAST TASC ----------------
/* * * * * * * * * * * * *    std::cout <<   * * * * * * * * * * * * * * * * */
// вывод в cout карты
std::ostream & operator << (std::ostream & out, const myCard & rCard) {
    //out << "BJ_Card out <<";
    const std::string RANKS[] = {"v00", "v01", "v02", "v03", "v04", "v05",
                                 "v06", "v07", "v08", "v09", "v10",
                                 "vJJ", "vQQ", "vKK"};
    // enum suit {S_CLUBS, S_DIAMOND, S_HEARTS, S_SPADERS};
    const std::string SUITS[] = {"_mC", "_mD", "_mH", "_mS"};
    // поправил, работает = )
    rCard.m_IsFaceUp ? (out << RANKS[rCard.m_Rank] << SUITS[rCard.m_Suit]) : (out << "vXX_mX");

    return out;
}
// вывод в cout игрока
std::ostream & operator << (std::ostream & out, const myGenericPlayer & rGPlr) {
    //out << "BJ_GenericPlayer out <<";
    out << rGPlr.m_NamePlayer << ":\t";
    std::vector <myCard*> ::const_iterator pCard; // указатель на указатель = )

    if(!rGPlr.m_Cards.empty()) {
        for(pCard = rGPlr.m_Cards.begin(); pCard != rGPlr.m_Cards.end(); pCard++)
            out << *(*pCard) << "\t";

        if(rGPlr.GetTotal() != 0)
            out << "(" << rGPlr.GetTotal() << ")";
    }
    else
        out << "<empty>";
    return out;
}
/* * * * * * * * * * * * *    class myCard   * * * * * * * * * * * * * * * * */
// class myCard
myCard::myCard(rank r, suit s, bool iFace) :
    m_Rank(r), m_Suit(s), m_IsFaceUp(iFace) { // zero body class constructor
}
int myCard::GetValue() const {
    // если карта лицом вниз
    const int C_TEN = 10;
    int value = 0;
    if(m_IsFaceUp) {
        // значение - число указанное на карте
        value = m_Rank;
        // значение равно 10 для открытых карт
        if(value > C_TEN)
            value = C_TEN;
    }
    return  value;
    //return  (value > C_TEN) ? C_TEN : value;;
}
inline void myCard::Flip() {
    m_IsFaceUp = !(m_IsFaceUp); // укажем явно
}
// end class myCard

/* * * * * * * * * * * * *    class myHand   * * * * * * * * * * * * * * * * */
// class myHand
myHand::myHand(int reserv) {
    m_Cards.reserve(reserv);
}
myHand::~myHand() {
    Clear();
}
void myHand::Clear() {
    // проходим по вектору через итератор, освобождаем память
    std::vector <myCard * >::iterator iter;
    for(iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
        delete *iter; // удаляется объект BJ_Card
        *iter = nullptr;
    }
    // очищаем вектор указателей
    m_Cards.clear();
}
void myHand::AddCard(myCard *pCard) {
//inline void BJ_Hand::AddCard(BJ_Card *pCard) {
    m_Cards.push_back(pCard);
}
int myHand::GetTotal() const {
    // если карт в руке нет
    if(m_Cards.empty())
        return 0;
    // Если первая карта имеет значение 0, то она лежит рубашкой вверх, вернуть 0
    if(m_Cards[0]->GetValue() == 0)
        return 0;

    int MAX_ONE_VALUE = 11; // очков в одной карте
    // находим сумму очков всех карт, Туз = 1
    int total = 0;
    std::vector <myCard *> :: const_iterator c_iter;

    for(c_iter = m_Cards.begin(); c_iter != m_Cards.end(); c_iter++)
        total += (*c_iter)->GetValue();
    // отределяем туз в руке
    bool inHandAce = false;
    for(c_iter = m_Cards.begin(); c_iter != m_Cards.end(); c_iter++) {
        if((*c_iter)->GetValue() == myCard::R_ACE)
            inHandAce = true;
    }
    // если в руке туз, а сумма маленькая, туз даёт 11 очклв
    if(inHandAce and (total <= MAX_ONE_VALUE))
        total += (MAX_ONE_VALUE - 1); // туз = 1 очку +10 = 11 очков

    return total;
}
// end class myHand // */

/* * * * * * * * * * *    class myGenericPlayer   * * * * * * * * * * * * * */
// end class myGenericPlayer
myGenericPlayer::myGenericPlayer(const std::string & rName):
    m_NamePlayer(rName) { // zero body class constructor
}
myGenericPlayer::~myGenericPlayer() {// zero body ~destructor
}
inline bool myGenericPlayer::IsBusted() const {
    //return (GetTotal() > 21);
    return (GetTotal() >= 21); // 21 включительно ?
}
inline void myGenericPlayer::Bust() const {
    std::cout << m_NamePlayer << " busts...\n";
}
// end class myGenericPlayer // */

/* * * * * * * * * * * *    class myPlayerBJ   * * * * * * * * * * * * * * * */
// end class myPlayerBJ
myPlayerBJ::myPlayerBJ(const std::string & rName):
    myGenericPlayer(rName) { // zero body class constructor
}
myPlayerBJ::~myPlayerBJ() { // zero body ~destructor
}
bool myPlayerBJ::IsHitt() const{
    std::cout << m_NamePlayer <<", do you want a hit else? (\'Y\'/\'y\' or any key): ";
    char answer;
    std::cin >> answer;
    return (answer == 'y' or answer == 'Y');
}
inline void myPlayerBJ::Win() const {
    std::cout << m_NamePlayer << " wins!.\n";
}
inline void myPlayerBJ::Lose() const {
    std::cout << m_NamePlayer << " loses.\n";
}
inline void myPlayerBJ::Push() const {
    std::cout << m_NamePlayer << " pushes (draws).\n";
}
// end class myPlayerBJ // */

/* * * * * * * * * * * * *    class myHouse   * * * * * * * * * * * * * * * */
// class myHouse
myHouse::myHouse(const std::string & rNameHouse):
    myGenericPlayer(rNameHouse) { // zero body class constructor
}
myHouse::~myHouse() { // zero body ~destructor
}
inline bool myHouse::IsHitt() const {
    //const int HOUSE_HITT = 16;
    return (GetTotal() <= 16);
}
void myHouse::FlipFirstCard() {
    if(!m_Cards.empty() )
        m_Cards[0]->Flip();
    else
        std::cout << "Sorry, no card to flip!\n";
}
// end class myHouse // */

/* * * * * * * * * * * * *    class myDeck   * * * * * * * * * * * * * * * * */
// class myDeck
myDeck::myDeck() {
    const int MAX_CARD = 52;
    m_Cards.reserve(MAX_CARD);
    Populate(); // инициализировать колоду карт
}
myDeck::~myDeck() { // zero body ~destructor
}
void myDeck::Populate() {
    Clear(); // это зачем ?
    // создаём стандартуню колоду карт
    for(int s = myCard::S_CLUBS; s <= myCard::S_SPADERS; s++)
        for(int r = myCard::R_ACE; r <= myCard::R_KING; r++)
            AddCard(new myCard(static_cast <myCard::rank>(r),
                                static_cast <myCard::suit>(s) ) );
}
void myDeck::Shuffle() {
    std::random_shuffle(m_Cards.begin(), m_Cards.end() );
    //std::cout << "test Shaffle: \n";
    //for(auto iter : m_Cards)
    //    std::cout << "test : value: " << iter->GetValue() << "\n";
}
void myDeck::Deal(myHand &rHand) {
    if(!m_Cards.empty()) {
        rHand.AddCard(m_Cards.back());
        m_Cards.pop_back(); // вытащить карту !!! Эту строчку я пропустил...
    }
    else
        std::cout << "Out of cards. Unable to deal.";
}
void myDeck::AdditionalMore(myGenericPlayer &rGPlayer) {
    std::cout << std::endl;
// продолжаем раздавать карты до тех пор, пока у игрока не случится перебор
// или пока не захочет взять еще одлну
    while( (!(rGPlayer.IsBusted())) and rGPlayer.IsHitt() ) {
        Deal(rGPlayer);
        if(rGPlayer.IsBusted())
            rGPlayer.Bust();
    }
}
inline int myDeck::GetRemainingCard() const {
    return m_Cards.size();
}
// end class myDeck // */

/* * * * * * * * * * * * *    class myGameBJ   * * * * * * * * * * * * * * * */
// class myGameBJ
myGameBJ::myGameBJ(const std::vector <std::string> & rNameVec) {
    // создать вектор игроков из вектора с именами...
    std::vector <std::string> ::const_iterator pName;
    for(pName = rNameVec.begin(); pName != rNameVec.end(); pName++)
        m_Players.push_back(myPlayerBJ(*pName));
    // посев генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(0)));
    NewDeck();

}
myGameBJ::~myGameBJ(){ // zero body ~destructor
}
void myGameBJ::NewDeck() { // создать новую колоду и перемешать
    m_Deck.Populate();
    m_Deck.Shuffle();
}
void myGameBJ::StartPlay() {
    const int MAX_CARD = 2;
    std::vector <myPlayerBJ> ::iterator pPlayer; // раздать каждому по 2 карты
    //if (условие) //
    //    количество карт и игроков // создать новую колоду
    for(int card = 0; card < MAX_CARD; card++) {
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
            m_Deck.Deal(*pPlayer);

        m_Deck.Deal(m_House);
    }
    m_House.FlipFirstCard(); // спрятать первую карту диллера

    //открыть руки всех игроков
    for(auto pPlrs = begin(m_Players); pPlrs != end(m_Players); pPlrs++)
        std::cout << *pPlrs << std::endl;

    std::cout << m_House << std::endl; // открываем диллера

    int lastCarts = m_Deck.GetRemainingCard();
    // создать игрокам дополнитлеьные карты
    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
        m_Deck.AdditionalMore(*pPlayer);

    m_House.FlipFirstCard(); // показать первую карту диллера
    std::cout << std::endl << m_House;
    m_Deck.AdditionalMore(m_House); // раздать диллеру дополнительную карту

    if(m_House.IsBusted()) { // проверка кто выйграл/проиграл
        // все, кто остался в игре - побеждают
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
            if(!(pPlayer->IsBusted() ) )
                pPlayer->Win();
    }
    else // сравнивает суммы очков игроков (кто остался) с очками диллера
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
            if(pPlayer->GetTotal() > m_House.GetTotal())
               pPlayer->Win();
            else if(pPlayer->GetTotal() < m_House.GetTotal())
                pPlayer->Lose();
            else
                pPlayer->Push();
        }
    if( (lastCarts == 0) or (lastCarts < (( static_cast <int> (m_Players.size()) + 1) * 2) ) ) {
        std::cout << "\nCreate new deck!\n";
        NewDeck();
    }
    // очищает руки всех игроков
    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
        pPlayer->Clear();
    m_House.Clear();


}
// end class myGameBJ // */
