#include "function_game.hpp"
#include "exc_from_book.hpp"

// ---------------------------------------------------------------------------
// ------------------- 2 глава книги -----------------------------------------
// ---------------------------------------------------------------------------
// утраченый клад
//
// Весе действия в этом теле функции.
// Пробуем = )
int lost_fortune() {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    // объявление переменных
    const int GOLD_PIECES = 975;
    int adventurers = 20;
    int killed = 8;
    int survivors;

    string leader = "Maxim";

    // получаю информацию
    cout << "Welcom to Lost Fortune \n\n";
    cout << "Please enter the following for your personalized adventure \n";
    //cout << "Enter a number: " << adventurers;
    cout << "Enter a number: ";

    cin >> adventurers;

    cout << "   Enter a number, smaller then the first: " << killed;

    //cin >> killed;

    survivors = adventurers - killed;
    cout << "    Enter your last name: ";
    // моя доработка...
    cout << leader << endl;
    //cin >> leader;


    // Сюжет игры = )
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << " - - in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary rogue. " << leader << ".\n";
    cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of " << leader;
    cout << ", and the ogres were defeated, but at a cost. ";
    cout << "Of the adventures. " << killed << "were vanquished. ";
    cout << "leaving just " << survivors << " in the group. \n";
    cout << "\nThe part was about to give up all hope. ";
    cout << "But while laying the deceased to rest. ";
    cout << "they stumbltd upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
    cout << leader << " help on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course. \n";

    // конец игры
    return 0;
}

// Игра Угадай число =)
int guess_my_number() {
    using std::cout;
    using std::cin;
    setlocale(LC_CTYPE, "Russian"); // попытка включить русский
    //system("chcp 1251"); // Russian lang. Кодовая страница
    // ввод параметров
    srand(static_cast <unsigned int> (time(0) )); //поссев для генератора сл.чисел
    int randNumber = (rand() % 100) + 1; // генерируем число от 1 до 100
    int tries = 0;
    int guess = -1;

    cout << "\n\tWelcom to Guess My Number ГУсЪ\n\n";

    // тело игры
    do {
        cout << "Enter a guess: ";
        cin >> guess;
        tries += 1;
        if (guess > randNumber)
            cout << "Too high!\n\n";
        else if (guess < randNumber)
            cout << "Too low!\n\n";
        else
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";

    } while(guess != randNumber);

    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 3 глава книги -----------------------------------------
// ---------------------------------------------------------------------------
// словомеска, переписываю игру из книги = )
int word_jumble() {

    using namespace std;

    srand(static_cast<unsigned int>(time(0))); // поссев для генератора случаных чисел

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string game_words[NUM_WORDS][NUM_FIELDS] =  {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going skowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };

    int choice_wrd = rand() % NUM_WORDS;
    string theWord = game_words[choice_wrd][WORD];
    string theHint = game_words[choice_wrd][HINT];
    string jumble = theWord; // перемешанный вариант слова
    int len_wrd = jumble.size();
    //int score = len_wrd * 2;

    // перемешиваем слово
    for(int i = 0, inx1, inx2; i < len_wrd; i++) {
        inx1 = rand() % len_wrd;
        inx2 = rand() % len_wrd;

        char tmp = jumble[inx1];
        jumble[inx1] = jumble[inx2];
        jumble[inx2] = tmp;
    }

    // приглашаем пользователя
    cout << "\t\t\tWelcom to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n\n";
    cout << "The jumble is: " << jumble;

    string guess;
    cout << "\t\tYour guesse: ";
    cin >> guess;

    // игровой цикл    
    while((guess != theWord) && (guess != "quit")) {

        if(guess == "hint") {
            cout << theHint;
            //score /= 2;
        }
        else {
            cout << "Sorry, that's is not it. ";
            //score -= 1;

        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    // завершение игры
    if(guess == theWord) {
        //cout << "\n You get a score in gamr: " << score;
        cout << "\nThat's it! You guessed it!\n";
    }
    cout << "\nThanks for playing.\n";
    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 4 глава книги -----------------------------------------
// ---------------------------------------------------------------------------

int hungman() {
    using namespace std;

    // подготовка
    const int MAX_WRONG = 8;
    vector <string> secr_wrd; // подборка слов для загадывания

    secr_wrd.push_back("GUESS");
    secr_wrd.push_back("HANGMAN");
    secr_wrd.push_back("DIFFICULT");
    secr_wrd.push_back("YASY");
    secr_wrd.push_back("PEN");

    srand(static_cast <unsigned int> (time(0)));
    random_shuffle(secr_wrd.begin(), secr_wrd.end());

    const string THE_WRD = secr_wrd[0]; // слово для отгадывания

    int wrong = 0;
    string piece_wrd(THE_WRD.size(), '-'); // слово которое отгадываем
    string used_wrd = ""; // отгаданные буквы

    //приглашение в игру
    cout << "Welcom to Hungman. Good luck!\n\n";

    // Основной игровой цикл
    while((wrong < MAX_WRONG) and (piece_wrd != THE_WRD)) {
        cout << "\nYou have " << MAX_WRONG - wrong;
        cout << " incorrect guesses left. \n";
        cout << "\nYou've used the following letters: \n" << used_wrd << endl;
        cout << "\nSo far, the word is: \n" << piece_wrd << endl;

        // получаем бокву
        char guess;
        cout << "\n\tEnter your guess: ";
        cin >> guess;

        guess = toupper(guess); // переводим букву в верхний регистр

        while(used_wrd.find(guess) != string::npos) {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used_wrd += guess;

        if(THE_WRD.find(guess) != string::npos) {
            cout << "That's right! " << guess << "is in the word.\n";
            // обновить переменную piece_wrd
            for(unsigned long i = 0; i < THE_WRD.size(); i++){
                if(THE_WRD[i] == guess) {
                    piece_wrd[i] = guess;
                }
            }
        }
        else {
            cout << "Sorry. " << guess << "  isn't in the word.\n";
            wrong++;
        }
    }

    // конец игры
    if(wrong == MAX_WRONG)
        cout << "\nYou've been hanged!!!";
    else
        cout << "\nYou guessed it!";

    cout << "\nThe word was " << THE_WRD << endl;

    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 5 глава книги -----------------------------------------
// ---------------------------------------------------------------------------

int give_me_a_number(int param) { // игра - дай мне номер
    int number = f5_askNumber(param);
    std::cout << "Thanks for entering: " << number << "\n\n";
    number = f5_askNumber(10, 5);
    std::cout << "Thanks for entering: " << number << "\n\n";
    return 0;
}

int taking_gamage(const int param){ // игра - получи урон
    static int health = param;
    std::cout << "Your health is " << health << "\n\n";
    health = f5_radiation(health);
    std::cout << "Arter radiation exposure your health is " << health << "\n\n";
    health = f5_radiation(health);
    std::cout << "Arter radiation exposure your health is " << health << "\n\n";
    health = f5_radiation(health);
    std::cout << "Arter radiation exposure your health is " << health << "\n\n";
    return 0;
}

int mad_lib() { // игра - сумашедшие библиотекари
    std::cout << "Welcom to Mad Libraries\n\n";
    std::cout << "Answer the following quiestions to help create a new story.\n";

    std::string name = f5_askTextML(std::string("Please enter a name: "));
    std::string noun = f5_askTextML(std::string("Please enter a plural noun: "));
    int number = f5_askNumberML("Please enter a number: ");
    std::string body = f5_askTextML(std::string("Please enter a body part: "));
    std::string verb = f5_askTextML(std::string("Please enter a verb: "));
    f5_tellStoryML(name, noun, number, body, verb);
    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 6 глава книги -----------------------------------------
// ---------------------------------------------------------------------------
int tic_tac_toi(const bool rnd_frst_move){ // игра - крестики-нолики. defaulf = false;
    // константы
    const char EMPTY = ' ';
    const char X = 'X';
    const char O = 'O';
    //const char TIE = 'T';
    const char NO_ONE = 'N';

    const int NUM_SQUARES = 9; // кол-во клеточек/позиций

    int move;
    std::vector <char> board(NUM_SQUARES, EMPTY); //игровое поле

    f6_instruction();
    char human;
    //* Моя доработка, автоматического выбора хода = )
    if(rnd_frst_move) {
        std::srand(static_cast <unsigned int> (std::time(0)));
        std::rand() % 2 ? human = X : human = O;
        std::cout << "\nAutomatic move selection...";
    }
    else // конец моей доработки = ) */
        human = f6_humanPiece();

    char compuHter = f6_opponent(human);
    char turn = X; // первые ходяд Крестики
    //*
    while(f6_winner(board) == NO_ONE) { // тело игры
        if(turn == human) {
            move = f6_humanMove(board);
            board[move] = human;
            std::cout << "\n\t\t human piece: " << human << "  move: " << move <<
                                                      "  (" << move+1 << ")";
        }
        else {
            move = f6_compucterMove(board, compuHter);
            board[move] = compuHter;
            std::cout << "\n\t\t compuHter piece: " << compuHter << "  move: " << move <<
                                                              "  (" << move+1 << ")";
        }
        f6_displayBoard(board);
        turn = f6_opponent(turn);
    } // */
    /*
    while(f6_winner(board) == NO_ONE) { // тело игры
        move = f6_humanMove(board);
        board[move] = human;
        f6_displayBoard(board);
    } // */

    f6_annonceWinner(f6_winner(board), human, compuHter);
    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 7 глава книги -----------------------------------------
// ---------------------------------------------------------------------------
int swap_pointer_ver() { // программа для работы с указателями
    int myScore = 150;
    int yourScore = 1000;
    std::cout << "Original values\n";
    std::cout << "myScore: " << myScore << "\n" << "yourScore: " << yourScore << "\n\n";
    std::cout << "Calling f7_badSwap()\n";
    f7_badSwap(myScore, yourScore);
    std::cout << "myScore: " << myScore << "\n" << "yourScore: " << yourScore << "\n\n";
    std::cout << "Calling f7_goodSwapPointer()\n";
    f7_goodSwapPointer(&myScore, &yourScore);
    std::cout << "myScore: " << myScore << "\n" << "yourScore: " << yourScore << "\n\n";
    return 0;
}

int inventory_pointer() { // демонстритует возврат указателя
    std::vector <std::string> inventory;
    inventory.push_back("sword");
    inventory.push_back("lancer");
    inventory.push_back("knife");
    inventory.push_back("shield");
    std::cout << "Sending the object pinted to by returned pointer to std::cout\n";
    // отображаем строковый элемент, на который направлен возвращаемый указателью
    std::cout << *(f7_ptrToElement(&inventory, 0)) <<"\n\n";
    // присваиваем один указатель другому - малозатратная операция
    std::cout << "Assigning the returned pointer to another  pointer\n";
    std::string * pStr = (f7_ptrToElement(&inventory, 1));
    std::cout << "Sending the object ponted to the new pointer to std::cout\n";
    std::cout << *pStr << std::endl << std::endl;

    // копируем строковый объекс - затратная операция
    std::cout << "Sending the object ponted to by pointer to a string object\n";
    std::string str = *(f7_ptrToElement(&inventory, 2));
    std::cout << "Sending the new string object to std::cout\n" << str << "\n\n";

    // изменение строкового объекта  посредством возвращаемого указателя
    std::cout << "Altering an object thought a returned pointer\n";
    *pStr = "Health Potiion";
    std::cout << "Sending the altered object to std::cout\n";
    std::cout << inventory[1] << std::endl;
    std::cout << "\n\tShow all inventory\n";
    for(auto &item : inventory)
        std::cout << item << std::endl;
    return 0;
}

int array_passer() {// взаимоотношение между массивом и указателем
    std::cout << "\tArray Passer run!\n\n";
    std::cout << "Creating an array of high score\n";
    const int NUM_SCORE = 5;
    int highScore[NUM_SCORE] = {1000, 2000, 3000, 4000, 5000};
    std::cout << "Displaying score using array as a constant pointer.\n";
    std::cout << *highScore << std::endl;
    std::cout << *(highScore + 1) << std::endl;
    for(int i = 2; i < NUM_SCORE; i++)
        std::cout << "\t" << highScore[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Increasing score by passing array as a constant pointer.\n\n";
    f7_increaseArray(highScore, NUM_SCORE);
    std::cout << "Display score by passing array as a constant pointer to a constant.\n";
    f7_dispalyArray(highScore, NUM_SCORE);

    std::cout << "\n\nTest poiner-array.\n";
    int testNum = 2020;
    int * const myPointer = &testNum;
    std::cout << "int * const myPointer = &testNum (int testNum = 2020).\n";
    std::cout << "myPointer[0]: " << myPointer[0] << std::endl;
    std::cout << "*myPointer: " << *myPointer << std::endl;

    return 0;
}

// игра - крестики-нолики. Версия с указателями.
int tic_tac_toe_ver_pointer(const bool rnd_frst_move){ // игра - крестики-нолики. defaulf = false;
    // константы
    const char EMPTY = ' ';
    const char X = 'X';
    const char O = 'O';
    //const char TIE = 'T';
    const char NO_ONE = 'N';

    const int NUM_SQUARES = 9; // кол-во клеточек/позиций

    int move;
    std::vector <char> board(NUM_SQUARES, EMPTY); //игровое поле

    f7_instruction_pointer();
    char human;
    //* Моя доработка, автоматического выбора хода = )
    if(rnd_frst_move) {
        std::srand(static_cast <unsigned int> (std::time(0)));
        std::rand() % 2 ? human = X : human = O;
        std::cout << "\nAutomatic move selection...\n";
    }
    else // конец моей доработки = ) */
        human = f7_Piece_pointer();

    char compuHter = f7_opponent_pointer(human);
    char turn = X; // первые ходяд Крестики
    //f7_displayBoard_pointer(&board);
    //*
    while(f6_winner(board) == NO_ONE) { // тело игры
        if(turn == human) {
            move = f7_humanMove_pointer(&board);
            board[move] = human;
            std::cout << "\n\t\t human piece: " << human << "  move: " << move <<
                                                      "  (" << move+1 << ")";
        }
        else {
            move = f7_compucterMove_pointer(board, compuHter);
            board[move] = compuHter;
            std::cout << "\n\t\t compuHter piece: " << compuHter << "  move: " << move <<
                                                              "  (" << move+1 << ")";
        }
        f7_displayBoard_pointer(&board);
        turn = f7_opponent_pointer(turn);
    } // */
    /*
    while(f7_winner_pointer(&board) == NO_ONE) { // тело игры
        move = f7_humanMove_pointer(&board);
        board[move] = human;
        f7_displayBoard_pointer(&board);
    } // */

    f7_annonceWinner_pointer(f7_winner_pointer(&board), human, compuHter);
    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 8 глава книги -----------------------------------------
// ---------------------------------------------------------------------------
int G8_CritterBegin() { // программа работы с классовм Critter
    /*  // выполнени программы без конструктора (Simple Critter)
    CritterBegin crit1;
    CritterBegin crit2;

    crit1.m_Hunger = 90;
    std::cout << "crit1's hunger level is " << crit1.m_Hunger << std::endl;
    crit2.m_Hunger = 8000;
    std::cout << "crit2's hunger level is " << crit2.m_Hunger << std::endl;

    crit1.Greet();
    crit2.Greet();
    // */

    /*  // Выполнение программы с конструктором (Construction Critter)
    CritterBegin crit1;
    CritterBegin crit2(7);

    crit1.Greet();
    crit2.Greet();
    //  */

    /*  // выполнени программы без конструктора (Simple Critter) // /
    CritterPrivate crtPrv(5);
    //std::cout << crtPrv.m_Hunger; // недопустимо, член-класса m_Hunget является закрытым
    std::cout << "Calling GetHunger(): " << crtPrv.GetHunger() << "\n\n";
    std::cout << "Calling SetHunger() with: \'-1\'\n";
    crtPrv.SetHunger(-1);
    std::cout << "Calling SetHunger() with: \'9\'\n";
    crtPrv.SetHunger(9);
    std::cout << "Calling GetHunger(): " << crtPrv.GetHunger() << "\n\n";
    // */
    /*  // выполнени программы без конструктора (Simple Critter) // */
    std::cout << "The total number  critter static is: ";
    std::cout << CritterStatic::s_Total << std::endl;
    CritterStatic cr1, cr2, cr3, cr4;
    std::cout << "\nNow a total number  critter static is: ";
    std::cout << CritterStatic::s_Total << std::endl;
    std::cout << "\nCritterStatic::s_Total = 5: ";
    std::cout << (CritterStatic::s_Total = 5)  << std::endl;

    // */
    return 0;
}

int G8_TamagochiBook() { // Игра - тамагочи из книги
    enum CaseChoice {EXIT, TALK, FOOD, PLAY, DEFAULT_CH};

    CritterBook crt;
    crt.Talk();
    int choice = DEFAULT_CH;
    do {

        std::cout << "\nCretterBook Cretaker!\n";
        std::cout << "\t\'0\' - Quit game\n";
        std::cout << "\t\'1\' - Liste to your critter book\n";
        std::cout << "\t\'2\' - Feed your critter book\n";
        std::cout << "\t\'3\' - Play with your critter book\n";

        choice = f6_askNumber("You choice: ", (DEFAULT_CH - 1), EXIT);
        std::cout << std::endl;

        switch(choice) {
        case EXIT:
            std::cout << "Good-bye.\n";
            break;
        case TALK:
            crt.Talk();
            break;
        case FOOD:
            crt.Eat();
            break;
        case PLAY:
            crt.Play();
            break;
        default:
            std::cout << "\nSorry? but " << choice << " isn't a valid chioce.\n";
        }
    } while(choice != EXIT);
    std::cout << "\t\nYou Exit game! CretterBook say: Bey-bey!\n";
    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 9 глава книги -----------------------------------------
// ---------------------------------------------------------------------------

int G9_critter_farm() { // ферма тамагочи,  агрегирование
    const int MAX_CRITTER = 4;
    Critter9 crt0("Maxim");
    std::cout << "My Critter9's name is" << crt0.GetName() << std::endl;
    std::cout << "Creating  Critters9 Farm.\n";
    CrittersFarm myFarm(MAX_CRITTER);
    std::cout << "\nAdding some critters to the farm.\n";
    myFarm.AddCritter(Critter9("Oleg"));
    myFarm.AddCritter(Critter9("Anikin"));
    myFarm.AddCritter(Critter9("Pak"));
    std::cout << "Calling Roll...\n\n";
    myFarm.RollCall();
    std::cout << "\nAdd in Farm critter: " << crt0.GetName() << std::endl;
    myFarm.AddCritter(crt0);
    std::cout << "Calling Roll... Again...\n\n";
    myFarm.RollCall();
    return 0;
}

int G9_critter_friend() { // дружественные функции и перегрузка оператора
    CritterFriend crtF("Ski - Ba");
    std::cout << "Calling f9_PeekCritter() to access crtF's private data member .m_Name: \n";
    f9_PeekCretter(crtF);
    std::cout << "\nSending crtF object to std::cout with the \'<<\' operator:\n";
    std::cout << crtF;
    return 0;
}

int G9_heap() { // динамическое выделение памяти и утечка
    int* pHeap = new int;
    *pHeap = 10;
    std::cout << "*pHeap: " << *pHeap << "\n\n";
    int* pHeap2 = f9_intOneHeap();
    std::cout << "*pHeap2: " << *pHeap2 << "\n\n";
    std::cout << "Freeing memory pointed to by pHeap.\n\n";
    delete pHeap;
    std::cout << "Freeing memory pointed to by pHeap2.\n\n";
    delete pHeap2;
    // избавляемся от висячих указателей
    pHeap = nullptr;
    pHeap2 = nullptr;
    return 0;
}

int G9_critter_heap_game() { // Тамагочи с кучей = )
    f9_testDestruction();
    std::cout << std::endl;
    CritterHeap crtHeap("Pocheer", 90);
    crtHeap.Greet();
    f9_testCopyConstructor(crtHeap);
    crtHeap.Greet();
    std::cout << std::endl;
    f9_testAssignmentOp();
    return 0;
}

int G9_Lobby_game() { // игра с лобби и игроками
    enum choice_set_switch {EXIT_CH, ADD_CH, REMOVE_CH, CLEAR_CH, MAX_CH};

    C9_LobbyPlayer myLobby;
    int choice;

    do {
        std::cout << myLobby;
        std::cout << "\nGAME LOBBY PLAYER\n";
        std::cout << "\'0\' - Exit the game.\n";
        std::cout << "\'1\' - Add a player to the lobby game.\n";
        std::cout << "\'2\' - Remove  a player from the lobby game.\n";
        std::cout << "\'3\' - Clear all lobby.\n\n";
        std::cout << "Enter your choice: ";
        choice = f6_askNumber("Enter your choice: ", (MAX_CH - 1), EXIT_CH);

        switch(choice) {
        case EXIT_CH:
            std::cout << "\nGood bye...\n";
            break;
        case ADD_CH:
            myLobby.AddPlayer();
            break;
        case REMOVE_CH:
            myLobby.RemovePlayer();
            break;
        case CLEAR_CH:
            myLobby.ClearAll();
            break;
        default:
            std::cout << "That choice \'"<< choice << "\' was not valid.\n";
        }
    } while(choice != EXIT_CH);

    return 0;
}

// ---------------------------------------------------------------------------
// ------------------- 10 глава книги ----------------------------------------
// ---------------------------------------------------------------------------

int G10_enemy_boss1() { // первая программа с простым наследованием.
    std::cout << "Create an Enemy.\n";
    f10_Enemy unit1;
    unit1.Attack();
    std::cout << "\n\nCreate a Boss1.0.\n";
    f10_Boss1 boss;
    boss.Attack();
    boss.SpecialAttack();
    return 0;
}

int G10_enemy_boss2() { // вторая программа с наследованием protected.
    std::cout << "Create an Enemy with protected m_Damage.\n";
    f10_Enemy_protec unit1;
    unit1.Attack();
    std::cout << "\n\nCreate a Boss2.0.\n";
    f10_Boss2 boss;
    boss.Attack();
    boss.SpecialAttack();
    return 0;
}

int G10_virtual_boss() { // игра overriding Boss 3.0
    std::cout << "Create f10_Enemy_virtual.\n";
    f10_Enemy_virtual enemy_;
    std::cout << "\tf10_Enemy_virtual is Taunt: \n";
    enemy_.Taunt();
    std::cout << "\tf10_Enemy_virtual is Attack: \n";
    enemy_.Attack();
    std::cout << "\n\nCreate Boss 3.0.\n";
    f10_Boss3 boss3;
    std::cout << "\tBoss 3.0 is Taunt: \n";
    boss3.Taunt();
    std::cout << "\tBoss 3.0 is Attack: \n";
    boss3.Attack();
    return 0;
}

int G10_polymorphicBadGay() { // принципы работы полиморфизма и виртуальные детрукторы
    std::cout <<  "\tCalling Attack() on Boss 4.0 object though pointer to Enemy Polymorph:\n";
    f10_Enemy_polymorph * pBadGay = new f10_Boss4();
    pBadGay->Attack();
    std::cout <<  "\n\n\tDeleting pointer to Enemy polymorph:\n";
    delete pBadGay;
    pBadGay = nullptr;
    return 0;
}

int G10_abstractCreater() { // пример абстрактных (базовых) классов.
    std::cout << "\tCreate Orc from Creature class by poiner.\n";
    f10_Creature *pMob = new f10_Orc();
    pMob->Greet();
    pMob->ShowHealth();
    delete pMob;
    pMob = nullptr;
    return 0;
}
