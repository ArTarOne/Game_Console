#include "function_game.hpp"
// доделать функцию
char generate_simbol( /*unsigned int seed, int param*/) { // функция генерации символа
    short int simb_low_step = 97; // первый символ алфавита
    short int simb_low_max = 26; // последний символ алфавита
    // запуск посева генератора
    /*
    std::cout << "\n\tseed:" << seed;
    (seed != 0) ? std::srand(static_cast <unsigned int> (std::time(0) ))
                : std::srand(seed); //*/

   return char( ( (std::rand() % simb_low_max) + simb_low_step) );
}

// 5 глава книги --------------------------------------------------------------------------------
int f5_askNumber(int high, int low){ // функция для игры - дай мне номер
    int num;
    do {
        std::cout << "Please enter a number "
                  << "(" << low << " - "
                         << high << " ):  ";
        std::cin >> num;
    } while(num > high || num < low);
    return num;
}

std::string f5_askTextML(std::string param){ // функция для игры - безумные библиотекари
    std::string txt;
    std::cout << param;
    std::cin >> txt;
    return txt;
}
int f5_askNumberML(std::string param) { // функция для игры - безумные библиотекари
    int num;
    std::cout << param;
    std::cin >> num;
    return num;
}
void f5_tellStoryML(std::string name, std::string noun, int number,
                  std::string bodyPart, std::string verb) { // функция для игры - безумные библиотекари
    std::cout << "\n\nHere's your story:\n"; //  1
    std::cout << "The famous explorer "; //  2
    std::cout << name; //  3
    std::cout << " had nearly given up a life-long quest to find\n"; //  4
    std::cout << "The Lost City of "; //  5
    std::cout << noun; //  6
    std::cout << " when one day, the "; //  7
    std::cout << noun; //  8
    std::cout << " found the explorer. \n"; //  9
    std::cout << "Surrounded by "; // 10
    std::cout << number; // 11
    std::cout << " " << noun; // 12
    std::cout << ", a tear came to "; // 13
    std::cout << name << "'s "; // 14
    std::cout << bodyPart << ".\n"; // 15
    std::cout << "After all this time, the quest was finally over. "; // 16
    std::cout << "And then, the "; // 17
    std::cout << noun << "\n"; // 18
    std::cout << "promptly devoured "; // 19
    std::cout << name << ". "; // 20
    std::cout << "The normal of the story? Be cereful what you "; // 21
    std::cout << verb; // 22
    std::cout << " for. "; // 23
}

char my5_hungman_get_word(const std::string &txt){ // функция для игры - виселица (моя реализация)
    char out_letter;
    do { // проверка на букву
        std::cout << txt + " " ;
        std::cin >> out_letter;
    } while( !(std::isalpha(out_letter)) );
    return std::toupper(out_letter); // слово загадано в верхнем регистре.
}

bool my5_hungman_compare_word(const char &fnd_letter, const std::string &fnd_str,
                              std::string &open_str) { // функция для игры - виселица (моя реализация)
    bool operation_flag = fnd_str.find(fnd_letter) != std::string::npos;
    if(operation_flag) {
        std::cout << "That's right! \'" << fnd_letter << "\' is in the word.\n";
        // insert letter in string
        if(fnd_str.size() == open_str.size()) {
            for(unsigned int index = 0; index < fnd_str.size(); index++)
                if(fnd_str[index] == fnd_letter)
                    open_str[index] = fnd_letter;
        }
        else
            std::cout << "Error: size-size!";

    }
    else
        std::cout << "Sorry. " << fnd_letter << "  isn't in the word.\n";

    return operation_flag;
}

int my5_func_default_param(const std::string &txt) { // параметр по умолчанию
    int num;
    std::cout << txt;
    std::cin >> num;
    return num;
}
int my5_func_overload() { // функция с перегрузкой
    int num;
    std::cout << "\n\toverload: Plese enter the number: ";
    std::cin >> num;
    return num;;
}
int my5_func_overload(const std::string &txt) { // функция с перешрузкой
    int num;
    std::cout << txt;
    std::cin >> num;
    return num;;
}

// 6 глава книги --------------------------------------------------------------------------------

void f6_instruction() { // правила игры
    std::cout << "Welcom to the ultimate man-machine showdowm: Tic-Tac-Toe ver 2.0.\n";
    std::cout << "This is a Pointer Version!.\n";
    std::cout << "- - - where human brain is pit against silicon processor\n\n";
    std::cout << "Make your move known by entering a number. 1 - 8. The nymber\n";
    std::cout << "corresponds to the desired board position, as illustrated:\n\n";
    std::cout << " 1 | 2 | 3\n";
    std::cout << " ---------\n";
    std::cout << " 4 | 5 | 6\n";
    std::cout << " ---------\n";
    std::cout << " 7 | 8 | 9\n\n";
    std::cout << "Prepare yourself, human. The battle is about to begin.\n\n";

}
char f6_askYesNo(const std::string  &question){
    char response;
    do {
        std::cout << question << " \'y\'/\'n\': ";
        std::cin >> response;
    } while(response != 'y' && response != 'n');
    return response;
}
int  f6_askNumber(const std::string &txt, int high, int low) { // low = 1; high = 9 // default
    const int MAX_NUMS = 2; // одна циферка нужна
    int num_out = 0;
    std::string tmp;
    do {
        std::cout << txt << "  (" << low << " - " << high << "): ";
        std::cin >> tmp;
        if(std::isdigit(tmp[0]) && tmp.size() < MAX_NUMS)
            num_out = std::stoi(tmp);
        else
            num_out = -1;
    } while( !(low <= num_out && num_out <= high) );
    return num_out;
}
char f6_humanPiece(){ // чем ходит человек
    const char X = 'X';
    const char O = 'O';
    char goFirst = f6_askYesNo("Do you require the first move?");
    if(goFirst == 'y') {
        std::cout  << "\nThen take the first move. You will need it.\n";
        return X;
    }
    else {
        std::cout << "\nYou bravery will be your undoing... I will go first.\n";
        return O;
    }
}
//inline char f6_opponent(char inParam); // чем ходит компухтер
void f6_displayBoard(const std::vector <char> &inBrd){ // отображение игрового поля
    enum line_board {LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9, MAX_LINE_B};
    std::cout << "\n\t" << inBrd[LB1] << " | " << inBrd[LB2] << " | " << inBrd[LB3];
    std::cout << "\n\t---------";// 9 штучек
    std::cout << "\n\t" << inBrd[LB4] << " | " << inBrd[LB5] << " | " << inBrd[LB6];
    std::cout << "\n\t---------";// 9 штучек
    std::cout << "\n\t" << inBrd[LB7] << " | " << inBrd[LB8] << " | " << inBrd[LB9];
    std::cout << "\n\n";
}
char f6_winner(const std::vector <char> &inBrd){ // Определить победителя поля игры
    const char EMPTY = ' ';
    // const char X = 'X';
    // const char O = 'O';
    const char TIE = 'T';
    const char NO_ONE = 'N';
    // все возможные варианты выигрышных рядов
    enum line_win {FRST, SEC, THERD, MAX_LINE};
    const int TOTAL_ROWS = 8;
    const int WINNING_ROWS[TOTAL_ROWS][MAX_LINE] =  { {0, 1, 2}, //{ {1, 2 ,3},   // 1
                                                      {3, 4, 5},   //{4, 5 ,6},   // 2
                                                      {6, 7, 8},   //{7, 8 ,9},   // 3
                                                      {0, 3, 6},   //{1, 4 ,7},   // 4
                                                      {1, 4, 7},   //{2, 5 ,8},   // 5
                                                      {2, 5, 8},   //{3, 6 ,9},   // 6
                                                      {0, 4, 8},   //{1, 5 ,9},   // 7
                                                      {2, 4, 6}, };//{3, 5 ,7},   };// 8
    // если не в одном из выигрышных рядов уже присутствует ТРИ одинаковых значения
    // (и при этом они не равны EMPTY), то победитель определен.
    for(int row = 0; row < TOTAL_ROWS; row++)
        if( (inBrd[WINNING_ROWS[row][FRST]] != EMPTY) &&
            (inBrd[WINNING_ROWS[row][FRST]] == inBrd[WINNING_ROWS[row][SEC]]) &&
            (inBrd[WINNING_ROWS[row][SEC]] == inBrd[WINNING_ROWS[row][THERD]]) )
            return inBrd[WINNING_ROWS[row][FRST]];
    // посколько победитель не определился, проверяем на ничью
    // (остались л пустые клетки)
    if(count(inBrd.begin(), inBrd.end(), EMPTY) == 0)
        return TIE;
    // поскульку победителя нет и ничья не наступила
    // продолжаем игру
    return NO_ONE;
}
//inline bool f6_isLegal(const std::vector <char> &, int); //Легальный ли ход?
int  f6_humanMove(std::vector <char> &inBrd) { // ход кожанного ублюдка
    int move = f6_askNumber("Where will you move?") - 1;  // так как вводим от 1 до 9
    while(!f6_isLegal(inBrd, move)) {
        std::cout << "\nThat square is already occupied, foolish human.\n";
        move = f6_askNumber("Where will you move?") - 1;  // так как вводим от 1 до 9
    }
    std::cout << "Fine...\n";
    return move;
}
int  f6_compucterMove(std::vector <char> brd, char piece){ // ход компухтера
    // константы
    const char EMPTY = ' ';
    typedef unsigned short int ushIn;
    ushIn move = 0;
    bool found = false;
    // если компухтер может выйграть - то он делает этот ход.
    while(!found && move < brd.size()) {
        if(f6_isLegal(brd, move)) {
            brd[move] = piece;
            found = f6_winner(brd) == piece;
            brd[move] = EMPTY;
        }
        //else move++; // почему не else?
        if(!found) move++;
    }

    // Блокировать ход человека, если не можем победить!
    if(!found) {
        move = 0;
        const char HUM_WIN = f6_opponent(piece);
        while(!found && move < brd.size()) {
            if(f6_isLegal(brd, move)) {
                brd[move] = HUM_WIN;
                found = f6_winner(brd) == HUM_WIN;
                brd[move] = EMPTY;
            }
            //else move++; // почему не else?
            if(!found) move++;
        }
    }
    // занять отптима мальную свободную клетку.
    if(!found) {
        ushIn iter = 0;
        const int BEST_MOVE[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
        // выбираем отптимальную свободную клетку
        while(!found && iter < brd.size()) {
            move = BEST_MOVE[iter];
            if(f6_isLegal(brd, move))
                found = true;
            iter++;
        }
    }
    // move + 1, так как отображаем от 1 до 9 квадратики
    std::cout << "I shall take  square number " << move + 1 << std::endl;
    return move;

}
void f6_annonceWinner(char win, char hum, char pc){ //Поздравить победителя
    std::cout << "winner piece: " << win << "  Human piece: " << hum  <<  "  computer piece: " << pc << std::endl;
    if(win == pc) {
        std::cout << "\'" << win <<  "\''s won!\n";
        std::cout << "As I predictred? human, I am triumphant once more - - proof\n";
        std::cout << "that computers are superior to human  in all regards.\n";
    }
    else if(win == hum) {
        std::cout << "\'" << win <<  "\''s won!\n";
        std::cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        std::cout << "But never again! I, the computer, so swear it!\n";
    }
    else {
        std::cout << "It is a TIE...\n";
        std::cout << "You were most luckly, human, and somehow managed to tie me.\n";
        std::cout << "Celebrate... For this is the best you will ever  achieve.\n";
    }
}
// для игры безумные библиотекари, реализация с сылками
void my6_f_askTextML(const std::string &print_param, std::string &wright_param) { // функция для игры - безумные библиотекари моя переделка через ссылки
    std::cout << print_param;
    std::cin >> wright_param;
}
int my6_f_askNumberML(const std::string &param) { // функция для игры - безумные библиотекари моя переделка через ссылки
    int num;
    const char MINUS = '-';
    std::string tmp;
    bool flag = false;
    do { // валидация ввода циферек = )
        std::cout << param;
        std::cin >> tmp;
        for(const auto &c: tmp) {
            //std::cout << c << std::endl;
            if(std::isdigit(c) || c == MINUS)
                flag = true;
            else {
                flag = false;
                break;
            }
        }
    flag ? num = std::stoi(tmp) : num = -9999999;
    } while(!flag);
    return num;
}
void my6_f_tellStoryML(const std::string &rName, const std::string &rNoun, int number,
                       const std::string &rBodyPart, const std::string &rVerb){ // функция для игры - безумные библиотекари моя переделка через ссылки
    std::cout << "\n\nHere's your story:\n"; //  1
    std::cout << "The famous explorer "; //  2
    std::cout << rName; //  3
    std::cout << " had nearly given up a life-long quest to find\n"; //  4
    std::cout << "The Lost City of "; //  5
    std::cout << rNoun; //  6
    std::cout << " when one day, the "; //  7
    std::cout << rNoun; //  8
    std::cout << " found the explorer. \n"; //  9
    std::cout << "Surrounded by "; // 10
    std::cout << number; // 11
    std::cout << " " << rNoun; // 12
    std::cout << ", a tear came to "; // 13
    std::cout << rName << "'s "; // 14
    std::cout << rBodyPart << ".\n"; // 15
    std::cout << "After all this time, the quest was finally over. "; // 16
    std::cout << "And then, the "; // 17
    std::cout << rNoun << "\n"; // 18
    std::cout << "promptly devoured "; // 19
    std::cout << rName << ". "; // 20
    std::cout << "The normal of the story? Be cereful what you "; // 21
    std::cout << rVerb; // 22
    std::cout << " for. "; // 23
}
// проверка ссылок
int & my6_test(int param, int &rParam) {
    int local_per1 = param + 1;
    int local_per2 = rParam + 2;
    int local_per3 = 3;
    rParam = local_per3 + local_per2 + local_per1 + 1000;
    return rParam; // return rParam + 200; Тоже не работает = )
}

// 7 глава книги --------------------------------------------------------------------------------
void f7_badSwap(int X, int Y) { // пример плохого swap
    int tmp = X;
    X = Y;
    Y = tmp;
}
void f7_goodSwapPointer(int* const pX, int* const pY) { // swap через константный указатель!!!
    // сохраняем в tmp значение, на которое указывает pX
    int tmp = *pX;
    *pX = *pY; // сохраняем значение, на которое указывает pY по адресу, на которое указывает pX
    *pY = tmp; // сохраняем значение, на которое изначально казывало pX в  адресс, на которое указывает pY
}
void f7_increaseArray(int * const pArray, const int NUM_MAX) { // функция для Array Passer
    for(int i = 0; i < NUM_MAX; i++)
        //pArray[i] += 500;
        (*(pArray+i)) += 500;
}
void f7_dispalyArray(const int * const pArray, const int NUM_MAX) { // функция для Array Passer
    for(int i = 0; i < NUM_MAX; i++)
        //std::cout << *(pArray + i) << std::endl;
        std::cout << pArray[i] << std::endl;
}
// ------------------------- 7 глава книги - функции для Крестики-нолики 2.0 ---
void f7_instruction_pointer() { // правила игры
    std::cout << "Welcom to the ultimate man-machine showdowm: Tic-Tac-Toe.\n";
    std::cout << "- - - where human brain is pit against silicon processor\n\n";
    std::cout << "Make your move known by entering a number. 1 - 8. The nymber\n";
    std::cout << "corresponds to the desired board position, as illustrated:\n\n";
    std::cout << " 1 | 2 | 3\n";
    std::cout << " ---------\n";
    std::cout << " 4 | 5 | 6\n";
    std::cout << " ---------\n";
    std::cout << " 7 | 8 | 9\n\n";
    std::cout << "Prepare yourself, human. The battle is about to begin.\n\n";

}
char f7_askYesNo_pointer(const std::string * const question){
    char response;
    do {
        std::cout << *question << " \'y\'/\'n\': ";
        std::cin >> response;
    } while(response != 'y' && response != 'n');
    return response;
}
char f7_askYesNo_pointer_char(const char * const question){
    char response;
    do {
        short i =0;
        while(question[i] != '\0')
            std::cout << *(question + i++);

        std::cout << " \'y\'/\'n\': ";
        std::cin >> response;
    } while(response != 'y' && response != 'n');
    return response;
}
int  f7_askNumber_pointer(const char * const txt, int high, int low) { // low = 1; high = 9 // default
    const int MAX_NUMS = 2; // одна циферка нужна
    int num_out = 0;
    std::string tmp;
    do {
        short i = 0;
        while(txt[i] != '\0')
            std::cout << *(txt + i++);

        std::cout << txt << "  (" << low << " - " << high << "): ";
        std::cin >> tmp;
        if(std::isdigit(tmp[0]) && tmp.size() < MAX_NUMS)
            num_out = std::stoi(tmp);
        else
            num_out = -1;
    } while( !(low <= num_out && num_out <= high) );
    return num_out;
}
char f7_Piece_pointer(){ // чем ходит человек
    const char X = 'X';
    const char O = 'O';
    char goFirst = f7_askYesNo_pointer_char("Do you require the first move?");
    if(goFirst == 'y') {
        std::cout  << "\nThen take the first move. You will need it.\n";
        return X;
    }
    else {
        std::cout << "\nYou bravery will be your undoing... I will go first.\n";
        return O;
    }
}
//inline char f7_opponent_pointer(char inParam); // чем ходит компухтер
void f7_displayBoard_pointer(const std::vector <char> * const pBrd){ // отображение игрового поля
    enum line_board {LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9, MAX_LINE_B};
    std::cout << "\n\t" << pBrd->data()[LB1] << " | " << pBrd->data()[LB2] << " | " << pBrd->data()[LB3];
    std::cout << "\n\t---------";// 9 штучек
    std::cout << "\n\t" << pBrd->data()[LB4] << " | " << pBrd->data()[LB5] << " | " << pBrd->data()[LB6];
    std::cout << "\n\t---------";// 9 штучек
    std::cout << "\n\t" << pBrd->data()[LB7] << " | " << pBrd->data()[LB8] << " | " << pBrd->data()[LB9];
    std::cout << "\n\n";// */
}
char f7_winner_pointer(const std::vector <char> * const pBrd){ // Определить победителя поля игры
    const char EMPTY = ' ';
    // const char X = 'X';
    // const char O = 'O';
    const char TIE = 'T';
    const char NO_ONE = 'N';
    // все возможные варианты выигрышных рядов
    enum line_win {FRST, SEC, THERD, MAX_LINE};
    const int TOTAL_ROWS = 8;
    const int WINNING_ROWS[TOTAL_ROWS][MAX_LINE] =  { {0, 1, 2}, //{ {1, 2 ,3},   // 1
                                                      {3, 4, 5},   //{4, 5 ,6},   // 2
                                                      {6, 7, 8},   //{7, 8 ,9},   // 3
                                                      {0, 3, 6},   //{1, 4 ,7},   // 4
                                                      {1, 4, 7},   //{2, 5 ,8},   // 5
                                                      {2, 5, 8},   //{3, 6 ,9},   // 6
                                                      {0, 4, 8},   //{1, 5 ,9},   // 7
                                                      {2, 4, 6}, };//{3, 5 ,7},   };// 8
    // если не в одном из выигрышных рядов уже присутствует ТРИ одинаковых значения
    // (и при этом они не равны EMPTY), то победитель определен.
    for(int row = 0; row < TOTAL_ROWS; row++)
        if( (pBrd->data()[WINNING_ROWS[row][FRST]] != EMPTY) &&
            (pBrd->data()[WINNING_ROWS[row][FRST]] == pBrd->data()[WINNING_ROWS[row][SEC]]) &&
            (pBrd->data()[WINNING_ROWS[row][SEC]] == pBrd->data()[WINNING_ROWS[row][THERD]]) )
            return pBrd->data()[WINNING_ROWS[row][FRST]];
    // посколько победитель не определился, проверяем на ничью
    // (остались л пустые клетки)
    if(count(pBrd->begin(), pBrd->end(), EMPTY) == 0)
        return TIE;
    // поскульку победителя нет и ничья не наступила
    // продолжаем игру
    return NO_ONE;
}
//inline bool f6_isLegal(const std::vector <char> &, int); //Легальный ли ход?
int  f7_humanMove_pointer(const std::vector <char> * const pBrd) { // ход кожанного ублюдка
    int move = f7_askNumber_pointer("Where will you move?") - 1;  // так как вводим от 1 до 9
    while(!f7_isLegal_pointer(pBrd, move)) {
        std::cout << "\nThat square is already occupied, foolish human.\n";
        move = f7_askNumber_pointer("Where will you move?") - 1;  // так как вводим от 1 до 9
    }
    std::cout << "Fine...\n";
    return move;
}
int  f7_compucterMove_pointer(std::vector <char> copy_brd, char piece){ // ход компухтера
    // константы
    const char EMPTY = ' ';
    typedef unsigned short int usint;
    usint move = 0;
    bool found = false;
    // если компухтер может выйграть - то он делает этот ход.
    while(!found && move < copy_brd.size()) {
        if(f7_isLegal_pointer(&copy_brd, move)) {
            copy_brd[move] = piece;
            found = f7_winner_pointer(&copy_brd) == piece;
            copy_brd[move] = EMPTY;
        }
        //else move++; // почему не else?
        if(!found) move++;
    }

    // Блокировать ход человека, если не можем победить!
    if(!found) {
        move = 0;
        const char HUM_WIN = f6_opponent(piece);
        while(!found && move < copy_brd.size()) {
            if(f7_isLegal_pointer(&copy_brd, move)) {
                copy_brd[move] = HUM_WIN;
                found = f7_winner_pointer(&copy_brd) == HUM_WIN;
                copy_brd[move] = EMPTY;
            }
            //else move++; // почему не else?
            if(!found) move++;
        }
    }
    // занять отптима мальную свободную клетку.
    if(!found) {
        usint iter = 0;
        const int BEST_MOVE[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
        // выбираем отптимальную свободную клетку
        while(!found && iter < copy_brd.size()) {
            move = BEST_MOVE[iter];
            if(f7_isLegal_pointer(&copy_brd, move))
                found = true;
            iter++;
        }
    }
    // move + 1, так как отображаем от 1 до 9 квадратики
    std::cout << "I shall take  square number " << move + 1 << std::endl;
    return move;

}
void f7_annonceWinner_pointer(char win, char hum, char pc){ //Поздравить победителя
    std::cout << "winner piece: " << win << "  Human piece: " << hum  <<  "  computer piece: " << pc << std::endl;
    if(win == pc) {
        std::cout << "\'" << win <<  "\''s won!\n";
        std::cout << "As I predictred? human, I am triumphant once more - - proof\n";
        std::cout << "that computers are superior to human  in all regards.\n";
    }
    else if(win == hum) {
        std::cout << "\'" << win <<  "\''s won!\n";
        std::cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        std::cout << "But never again! I, the computer, so swear it!\n";
    }
    else {
        std::cout << "It is a TIE...\n";
        std::cout << "You were most luckly, human, and somehow managed to tie me.\n";
        std::cout << "Celebrate... For this is the best you will ever  achieve.\n";
    }
}


void my7_f_askTextML(const char* const pTxt, std::string * const write_param) { // функция для игры - безумные библиотекари моя переделка через указатели
    short i = 0;
    while(pTxt[i] != '\0')
        std::cout << *(pTxt + i++);
    std::cin >> *write_param;
}
int my7_f_askNumberML(const char* const pParam){ // функция для игры - безумные библиотекари моя переделка через указатели
    int num;
    const char MINUS = '-';
    std::string tmp;
    bool flag = false;
    do { // валидация ввода циферек = )
        short i =0;
        while(pParam[i] != '\0')
            std::cout << *(pParam + i++);

        std::cin >> tmp;
        for(const auto &c: tmp) {
            //std::cout << c << std::endl;
            if(std::isdigit(c) || c == MINUS)
                flag = true;
            else {
                flag = false;
                break;
            }
        }
    flag ? num = std::stoi(tmp) : num = -9999999;
    } while(!flag);
    return num;
    return 0;
}
void my7_f_tellStoryML(const std::string * const pName, const std::string * const pNoun, int num,
                       const std::string * const pBody, const std::string * const pVerb) { // функция для игры - безумные библиотекари моя переделка через указатели
    std::cout << "\n\nHere's your story from pointer:\n"; //  1
    std::cout << "The famous explorer "; //  2
    std::cout << *pName; //  3
    std::cout << " had nearly given up a life-long quest to find\n"; //  4
    std::cout << "The Lost City of "; //  5
    std::cout << *pNoun; //  6
    std::cout << " when one day, the "; //  7
    std::cout << *pNoun; //  8
    std::cout << " found the explorer. \n"; //  9
    std::cout << "Surrounded by "; // 10
    std::cout << num; // 11
    std::cout << " " << *pNoun; // 12
    std::cout << ", a tear came to "; // 13
    std::cout << *pName << "'s "; // 14
    std::cout << *pBody << ".\n"; // 15
    std::cout << "After all this time, the quest was finally over. "; // 16
    std::cout << "And then, the "; // 17
    std::cout << *pNoun << "\n"; // 18
    std::cout << "promptly devoured "; // 19
    std::cout << *pName << ". "; // 20
    std::cout << "The normal of the story? Be cereful what you "; // 21
    std::cout << *pVerb; // 22
    std::cout << " for. "; // 23
}

// 8 глава книги --------------------------------------------------------------------------------

// 9 глава книги --------------------------------------------------------------------------------
// возвращает целочисленную еременную из "кучи"
int * f9_intOneHeap() { // фиункция для программы heap динамическое выделение памяти.
    int * pTemp = new int(20);
    return pTemp;
}
void f9_leak1_Heap() { // создает утечку памяти
    int * drip = new int(50);
}
void f9_leak2_Heap() { // создает утечку памяти еще раз
    int * drip2 = new int(100);
    drip2 = new int(100);
    delete drip2;
}
