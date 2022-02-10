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

