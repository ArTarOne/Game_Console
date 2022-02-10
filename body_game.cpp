#include "body_game.hpp"


int main_body() {
    int num1 = 0;
    int num2 = 10;
    int num3 = 100;
    std::cout << "num1: " << num1 << "  num2: " << num2 << "  num3: " << num3 << std::endl;
    num3 = my6_test(num1, num2);
    std::cout << "num1: " << num1 << "  num2: " << num2 << "  num3: " << num3 << std::endl;
    return 0;
}


// -------------------------------------------------------------------------------
// 2 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------

int my2_menu_chooser() {
    using std::cout;

    enum difficulty {EASY = 1, NORMAL, HARD, ULTRA_HARD };

    cout << "Difficulty Leavels\n\n";
    cout << "1 - Easy\n";
    cout << "2 - Normal\n";
    cout << "3 - Hard\n";
    cout << "4 - Ultra Hard\n";


    int choice;
    cout << "Choice level: ";
    std::cin >> choice;

    switch(choice) {
        case difficulty::EASY:
            cout << "You picked Easy.\n";
            break;

        case difficulty::NORMAL:
            cout << "You picked Normal.\n";
            break;

        case difficulty::HARD:
            cout << "You picked Hard.\n";
            break;

        case difficulty::ULTRA_HARD:
            cout << "You picked Ultra Hard.\n";
            break;

        default:
            cout << "You made an illegal choice.\n";
            break;
    }

    return 0;
}

int my2_find_err() {
   int x = 0;
    while(x < 10) { // условие выхода из цикла
        ++x;
        std::cout << x << std::endl;
    }

    return 0;
}

int my2_guess_pc_number() {
    using std::cout;
    using std::cin;

    // ввод параметров
    srand(static_cast <unsigned int> (time(0) )); //поссев для генератора сл.чисел
    int randNumber = 0; //(rand() % 100) + 1; // генерируем число от 1 до 100
    int tries = 0;
    int guess = -1;

    int max_rand = 100;
    int min_rand = 1;

    cout << "\n\tWelcom to Guess PC my Number\n\n";
    cout << "Enter a guess for PC: ";
    cin >> guess;

    // тело игры
    do {
        randNumber = (rand() % max_rand) + min_rand; // генерируем число от 1 до 100
        cout << "PC generate number: " << randNumber << "  ";

        tries += 1;
        if (guess > randNumber) {
            cout << "Too low!\n\n";
            min_rand = randNumber;
            max_rand -= min_rand;
        }
        else if (guess < randNumber) {
            cout << "Too high!\n\n";
            max_rand = randNumber;
            max_rand -= min_rand;
            //max_rand = 100 - randNumber;
        }
        else
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";

    } while(guess != randNumber);

    return 0;

}

// -------------------------------------------------------------------------------
// 3 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------
// словомеска с очками =)
int my3_word_jumble() {
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
    int score = len_wrd * 2;

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
            score /= 2;
        }
        else {
            cout << "Sorry, that's is not it. ";
            score -= 1;

        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    // завершение игры
    if(guess == theWord) {
        cout << "\n You get a score in gamr: " << score;
        cout << "\nThat's it! You guessed it!\n";
    }
    cout << "\nThanks for playing.\n";
    return 0;
}

// -------------------------------------------------------------------------------
// 4 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------
int my4_test2(){
    std::vector <int> my_vec = {10, 20, 30, 40, 50, 60, 70, 80};
    std::vector <int>::iterator iter;
    for(iter = my_vec.begin(); iter != my_vec.end(); iter++) {
        (*iter)++; // *iter++ не работает = ) похоже у ++ приоритет выше.
        //std::cout << *iter << " ";
    }

    for(iter = my_vec.begin(); iter != my_vec.end(); iter++)
        std::cout << *iter << std::endl;
    return 0;
}

int my4_list_of_game(){
    using namespace std;

    vector <string> listGame; // сам список игр
    //*
    listGame.push_back("1 World Of Warcraft");
    listGame.push_back("2 Worl Of Tanks");
    listGame.push_back("3 Gotica");
    listGame.push_back("4 WarFrame");
    listGame.push_back("5 God Of War");
    listGame.push_back("6 Mad Max III");
    listGame.push_back("7 Black and White");
    listGame.push_back("8 Battle of Risen"); // */
    vector <string> ::const_iterator iter;

    // команды игры
    const string ENTER_GAME = "1";
    const string DEL_GAME = "2";
    const string PRINT_LIST_GAME = "3";
    const string GET_COMMAND_GAME = "4";

    const string QUIT_GAME = "quit"; // Для выхода из игры
    const string YES = "y"; const string YESS = "yes";
    const string NO = "n"; const string NOO = "no";

    string command;
    bool exit_game_flag = true;
    bool print_command = true;
    bool bad_command;
    cout << "\n\t\tWelcome in List of Game!\n\n";

    do { // тело игры
        bad_command = !exit_game_flag;
        if(print_command) {
            cout << "\nYou can control game:";
            cout << "\n\t\t\'quit\' - quit the game;";
            cout << "\n\t\t1 - add name game in list;";
            cout << "\n\t\t2 - erase name game in list;";
            cout << "\n\t\t3 - get list of game;";
            cout << "\n\t\t4 - get command game;";
            print_command = false;
        }

        cout << "\n\tEnter command:";
        cin >> command;
        exit_game_flag = command != QUIT_GAME;

        // вывод управления игры
        if(command == GET_COMMAND_GAME) { // комманда 4
            print_command = true;
            bad_command = false;
        }
        // Вывод листа с играми
        if(command == PRINT_LIST_GAME) { // комманда 3
            if(listGame.empty())
                cout << "\nSorry, list game is empty! Fill list plaese.";
            else {
                int counter = 1; // пронумеруем список от 1
                cout << "\nN. of Game \t Name Game.\n";
                for(iter = listGame.begin(); iter != listGame.end(); iter++)
                    cout << "   " << counter++ << "\t\t" << *iter << endl;
            }
            bad_command = false;
        }
        //Заполнение листа с играми
        if(command == ENTER_GAME) { // комманда 1
            string enter_game;
            string enter_command;
            bool exit_bool_flag = true;
            do {
                cout << "\nEnter name game: ";
                cin >> enter_game;
                cout << "\nDo you want add this Game name in list: " << enter_game;
                cout << "\nEnter \'yes\' or \'y\'. If you don't want it, press any key.\n";
                cin >> enter_command;
                if(enter_command == YES or enter_command == YESS) {
                    listGame.push_back(enter_game);
                    cout << "\n\tGame add in list.";
                }
                else {
                    cout << "\n\tDo yo exit in this command \'Add game in list\'";
                    cout << "\n\tEnter \'yes' or \'y\'";
                    cin >> enter_command;
                    exit_bool_flag = !(enter_command == YES or enter_command == YESS);
                }
            } while(exit_bool_flag);
            bad_command = false;
        }
        //удаление игр из листа
        if(command == DEL_GAME) {  // комманда 2
            if(listGame.empty())
                cout << "\nSorry, list game is empty! Fill list plaese. Command \'1\'";
            else {
                vector <string> ::iterator erase_iter = listGame.end();
                bool exit_bool_flag = true;
                bool digit_glag = true;
                string enter_game;
                int number_game = -1;
                string enter_command;
                do {
                    cout << "\nYou erese game from the list of game.";
                    cout << "\nEnter name game or number game." << endl;
                    cin >> enter_game;
                    for(auto liter : enter_game)
                        if(!isdigit(liter)) {
                            digit_glag = false;
                            break;
                        }
                    if(digit_glag)
                        number_game = stoi(enter_game);
                    else
                        for(erase_iter = listGame.begin(); erase_iter != listGame.end(); erase_iter++)
                            if(*erase_iter == enter_game) {
                                cout << "\nThe game is find";
                                break;
                            }
                     //cout << "\n!\terase iterator: " << *erase_iter << endl;

                    if(number_game > 0 or erase_iter != listGame.end()) {
                        cout << "\nDo you want erase the game? Enter \'y\' or \'yes\'";
                        cout << "\nIf you don't want to erase a game, press any key.\n";
                        cin >> enter_command;
                        if(enter_command == YES or enter_command == YESS) {
                            if(number_game > 0 and unsigned(number_game) < listGame.size()) {
                                listGame.erase(listGame.begin() +(number_game - 1));
                            }
                            else {
                                listGame.erase(erase_iter);
                            }
                        }
                    }

                    cout << "\n\tDo yo exit in this command \'Erase a game in list\'";
                    cout << "\n\tEnter \'yes' or \'y\'\n";
                    cin >> enter_command;
                    exit_bool_flag = !(enter_command == YES or enter_command == YESS);

                } while(exit_bool_flag);
            }
            bad_command = false;
        }

        if(bad_command) cout << "\nSorry, you have selected an unregistered command, try agane.";
    } while (exit_game_flag);

    //Конец игры
    cout << "\n\t\t  - - -   ";
    cout << "\n\t\tGood buy!";
    return 0;
}
// -------------------------------------------------------------------------------
// 5 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------

int my5_hungman(const int wrong) { // игра виселица с функциями... Надо допиликать...
    using namespace std;

    // подготовка
    const int MAX_WRONG = wrong;
    vector <string> secr_wrd; // подборка слов для загадывания

    secr_wrd.push_back("GUESS");
    secr_wrd.push_back("HANGMAN");
    secr_wrd.push_back("DIFFICULT");
    secr_wrd.push_back("EASY");
    secr_wrd.push_back("PEN");

    srand(static_cast <unsigned int> (time(0)));
    random_shuffle(secr_wrd.begin(), secr_wrd.end());

    const string THE_WRD = secr_wrd[0]; // слово для отгадывания

    int count_wrong = 0;
    string piece_wrd(THE_WRD.size(), '-'); // слово которое отгадываем
    string used_wrd = ""; // отгаданные буквы

    //приглашение в игру
    cout << "Welcom to Hungman. Good luck!\n\n";

    // Основной игровой цикл
    while((count_wrong < MAX_WRONG) and (piece_wrd != THE_WRD)) {
        cout << "\nYou have " << MAX_WRONG - count_wrong;
        cout << " incorrect guesses left. \n";
        cout << "\nYou've used the following letters: \n" << used_wrd << endl;
        cout << "\nSo far, the word is: \n" << piece_wrd << endl;

        // получаем букву
        char guess = my5_hungman_get_word("\n\tEnter your guess:");


        while(used_wrd.find(guess) != string::npos) {
            cout << "\nYou've already guessed " << guess << endl;
            guess = my5_hungman_get_word("\n\tEnter your guess again:");
        }

        used_wrd += guess;
        //count_wrong++; // отладка
        /* Заменить это ... Сделать тут функцию и обернуть в if
        if(THE_WRD.find(guess) != string::npos) {
            cout << "That's right! \'" << guess << "\' is in the word.\n";
            // обновить переменную piece_wrd
            for(unsigned long i = 0; i < THE_WRD.size(); i++){
                if(THE_WRD[i] == guess) {
                    piece_wrd[i] = guess;
                }
            }
        }
        else {
            cout << "Sorry. " << guess << "  isn't in the word.\n";
            count_wrong++;
        }//  заменить на функцию и обернуть в if */

        if( !my5_hungman_compare_word(guess, THE_WRD, piece_wrd) )
            count_wrong++;
    }

    // конец игры
    if(count_wrong == MAX_WRONG)
        cout << "\nYou've been hanged!!!";
    else
        cout << "\nYou guessed it!";

    cout << "\nThe word was " << THE_WRD << endl;

    return 0;
}

int my5_test3() { // параметр по умолчанию и перегрузка.
    std::cout << "my5_test3\n\n";
    std::cout << my5_func_default_param();
    std::cout << my5_func_default_param("\nSet param num: ");
    std::cout << my5_func_overload();
    std::cout << my5_func_overload("\nOverload: Set PARAM num num: ");
    return 0;
}

// -------------------------------------------------------------------------------
// 6 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------

int my6_mad_lib() { // игра - сумашедшие переделать по заданию... ССЫЛКИ;
    std::cout << "Welcom to Mad Libraries\n";
    std::cout << "Version by ArTarOne! =) Good Luck!\n\n";

    std::cout << "Answer the following quiestions to help create a new story.\n";

    std::string name;
    std::string noun;
    std::string body;
    std::string verb;
    int number = my6_f_askNumberML("Please enter a number: ");

    my6_f_askTextML(std::string("Please enter a name: "), name);
    my6_f_askTextML(std::string("Please enter a plural noun: "), noun);
    my6_f_askTextML(std::string("Please enter a body part: "), body);
    my6_f_askTextML(std::string("Please enter a verb: "), verb);

    my6_f_tellStoryML(name, noun, number, body, verb); //*/
    return 0;
}

// -------------------------------------------------------------------------------
// 7 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------
// С помощью указателя на указатель вызовите функцию-цлен size();
int my7_test1() { // Программа с указателем, направленный на объект string
    std::string myStr = "Test str in \"my7_test1\"\n";
    const std::string STR = "Const string text\n";
    std::string * const pStr = &myStr;
    const std::string * ppStr = &STR;
    std::cout << "pStr: " << *pStr << "pStr->size(): " << pStr->size() << std::endl << std::endl;
    std::cout << "ppStr: " << *ppStr << "ppStr->size(): " << ppStr->size() << std::endl;
    return 0;
}

int my7_test3() { // Адреса памяти
    int a = 10;
    int& b = a;
    int* c = &b;
    std::cout << &a <<std::endl;
    std::cout << &b <<std::endl;
    std::cout << &(*c) <<std::endl;
    std::cout << c <<std::endl;
    return 0;
}

int my7_mad_lib() { // игра - сумашедшие переделать по заданию... УКАЗАТЕЛИ;
    std::cout << "Welcom to Mad Libraries\n";
    std::cout << "Version by ArTarOne! Ponter edition!!! =) Good Luck!\n\n";

    std::cout << "Answer the following quiestions to help create a new story.\n";

    std::string name;
    std::string noun;
    std::string body;
    std::string verb;
    my7_f_askTextML("Please enter a name: ", &name);
    my7_f_askTextML("Please enter a plural noun: ", &noun);
    my7_f_askTextML("Please enter a body part: ", &body);
    my7_f_askTextML("Please enter a verb: ", &verb);

    int number = my7_f_askNumberML("Please enter a number: ");
    //std::cout << name + "  " << noun + "  " <<
    //             body + "  " << verb + "  " << number;
    my7_f_tellStoryML(&name, &noun, number, &body, &verb); //*/
    return 0;
}

// -------------------------------------------------------------------------------
// 8 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------
int my8_Critter_mode() { // доделываю тамагочу
    //                 0     1     2     3     4         5
    enum CaseChoice {EXIT, TALK, FOOD, PLAY, STATUS, DEFAULT_CH};

    MyCritter mcrt;
    mcrt.Talk();
    int choice = DEFAULT_CH;
    do {

        std::cout << "\nMyCretter Cretaker!\n";
        std::cout << "\t\'0\' - Quit game\n";
        std::cout << "\t\'1\' - Liste to your critter\n";
        std::cout << "\t\'2\' - Feed your critter\n";
        std::cout << "\t\'3\' - Play with your critter\n";
        std::cout << "\t\'4\' - Show my status boredom and hunger\n";

        choice = f6_askNumber("You choice: ", (DEFAULT_CH - 1), EXIT);
        std::cout << std::endl;

        switch(choice) {
        case EXIT:
            std::cout << "Good-bye.\n";
            break;
        case TALK:
            mcrt.Talk();
            break;
        case FOOD:
            mcrt.Eat();
            break;
        case PLAY:
            mcrt.Play();
            break;
        case STATUS:
            mcrt.Status();
            break;
        default:
            std::cout << "\nSorry? but " << choice << " isn't a valid chioce.\n";
        }
    } while(choice != EXIT);
    std::cout << "\t\nYou Exit game! CretterBook say: Bey-bey!\n";
    return 0;
}

// -------------------------------------------------------------------------------
// 9 глава книги. Задачки --------------------------------------------------------
// -------------------------------------------------------------------------------

int my9_lobby_mode() {  // игра с лобби и игроками доработанный вариант.
    enum choice_switch {EXIT_CH, ADD_CH, REMOVE_CH, CLEAR_CH, TAIL_CH, MAX_CH};

    myLobbyGame lobby;
    /*
    myPlayer plr("Maxim");
    std::cout << "\nGAME LOBBY PLAYER\n";
    std::cout << plr << std::endl;
    std::cout << "\nAdd player: \n";
    lobby.myAddPlayer();
    std::cout << "\nAdd player next 1: \n";
    lobby.myAddPlayer();
    std::cout << "\nAdd player next 2: \n";
    lobby.myAddPlayer();
    std::cout << "out lobby: \n";

    std::cout << lobby; // */

    int choice;
    do {
        std::cout << lobby;
        std::cout << "\nGAME LOBBY PLAYER\n";
        std::cout << "\'0\' - Exit the game.\n";
        std::cout << "\'1\' - Add a player to the lobby game.\n";
        std::cout << "\'2\' - Remove  a player from the lobby game.\n";
        std::cout << "\'3\' - Clear all lobby.\n";
        std::cout << "\'4\' - Testing... Show a tail the lobby.\n\n";
        std::cout << "Enter your choice: ";
        choice = f6_askNumber("Enter your choice: ", (MAX_CH - 1), EXIT_CH);

        switch(choice) {
        case EXIT_CH:
            std::cout << "\nGood bye...\n";
            break;
        case ADD_CH:
            lobby.myAddPlayer();
            break;
        case REMOVE_CH:
            lobby.myRemovePlayer();
            break;
        case CLEAR_CH:
            lobby.myClearAll();
            break;
        case TAIL_CH:
            lobby.myGetTail();
            break;
        default:
            std::cout << "That choice \'"<< choice << "\' was not valid.\n";
        }
    } while(choice != EXIT_CH); // */
    return 0;
}

// -------------------------------------------------------------------------------
// 10 глава книги. Задачки -------------------------------------------------------
// -------------------------------------------------------------------------------
