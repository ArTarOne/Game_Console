#ifndef FUNCTION_GAME_HPP
#define FUNCTION_GAME_HPP

#include <windows.h> // для руссского языка setlocate("LC_CTYPE", "Russian")
#include <locale.h>

#include <iostream>

#include <string> // для lost_fortune
#include <vector> // 4 глава
#include <algorithm> // 4 глава
#include <stddef.h> // глава 7 std::nullptr_t

#include <cstdlib> // требуется для (rund, srund)
#include <ctime> // требуется для (system time)
#include <cctype> // 4 глава
// практика с функциями...
char generate_simbol(/*unsigned int seed = 0, int param = 0*/); // функция генерации

// 5 глава
char my5_hungman_get_word(const std::string &); // функция для игры - виселица (моя реализация)
bool my5_hungman_compare_word(const char &fnd_letter, const std::string &fnd_str,
                              std::string &open_str); // функция для игры - виселица (моя реализация)
int my5_func_default_param(const std::string &txt = "\n\tPlease input number: "); // параметр по умолчанию
int my5_func_overload(); // функция с перегрузкой
int my5_func_overload(const std::string &); // функция с перешрузкой

int f5_askNumber(int high, int low = 1); // функция для игры - дай мне номер
/* inline  int f5_radiation(int health); // функция для игры - получи урон */
inline int f5_radiation(int health) { // // функция для игры - получи урон
    return (health / 2);
}
std::string f5_askTextML(std::string ); // функция для игры - безумные библиотекари
int f5_askNumberML(std::string ); // функция для игры - безумные библиотекари
void f5_tellStoryML(std::string, std::string, int,
                    std::string, std::string); // функция для игры - безумные библиотекари

// 6 глава
// функции для игры - крестики-нолики
void f6_instruction(); // правила игры
char f6_askYesNo(const std::string &);
int  f6_askNumber(const std::string &, int high = 9, int low = 1);
char f6_humanPiece(); // чем ходит человек
inline char f6_opponent(char inParam){ // чем ходит компухтер
    // const char X = 'X'; // крестик
    // const char O = 'O'; // нолик
    return inParam == 'X' ? 'O' : 'X';
}
void f6_displayBoard(const std::vector <char> &); // отображение игрового поля
char f6_winner(const std::vector <char> &); // Определить победителя поля игры
inline bool f6_isLegal(const std::vector <char> &inBrd, int move) { //Легальный ли ход?
    //const char EMPTY = ' '; // пустая ячейка
    return inBrd[move] == ' ';
}
int  f6_humanMove(std::vector <char> &);// ход кожанного ублюдка
int  f6_compucterMove(std::vector <char>, char);// ход компухтера
void f6_annonceWinner(char, char, char); //Поздравить победителя

// мои функции для главы 6.
void my6_f_askTextML(const std::string &, std::string &); // функция для игры - безумные библиотекари моя переделка через ссылки
int my6_f_askNumberML(const std::string &); // функция для игры - безумные библиотекари моя переделка через ссылки
void my6_f_tellStoryML(const std::string &, const std::string &, int,
                       const std::string &, const std::string &); // функция для игры - безумные библиотекари моя переделка через ссылки

int & my6_test(int, int &); // проверка

// 7 глава

void f7_badSwap(int, int); // пример плохого swap
void f7_goodSwapPointer(int* const pX, int* const pY); // swap через константный указатель!!!
// если  std::string* f7_ptrToElement(const std::vector <std::string> * const pVec, unsigned int i) { // не даёт сделать return
inline std::string* f7_ptrToElement(std::vector <std::string> * const pVec, unsigned int i) {
//inline std::string* f7_ptrToElement(const std::vector <std::string> * pVec, unsigned int i) { // так тоже не работает
    // возвращает адрес строкового объекта, расположенного в позиции i
    // в том векторе, на который направлн указатель pVec
    return pVec->size() >= i ? &((*pVec)[i]) : nullptr; // моя доработка, типо, безопасно = )
}
inline std::string f7_ptrToElementTest(const std::vector <std::string> * const pVec, unsigned int i) { // а без возвращаемого указателя - работает !!!
    return pVec->size() >= i ? (*pVec)[i] : nullptr;
    //return (*pVec)[i];
}
void f7_increaseArray(int * const, const int); // функция для Array Passer
void f7_dispalyArray(const int * constd, const int); // функция для Array Passer
// ------------------------- 7 глава книги - функции для Крестики-нолики 2.0 ---
void f7_instruction_pointer(); // правила игры
char f7_askYesNo_pointer(const std::string * const);
char f7_askYesNo_pointer_char(const char * const);
int  f7_askNumber_pointer(const char * const, int high = 9, int low = 1);
char f7_Piece_pointer(); // чем ходит человек
inline char f7_opponent_pointer(char inParam){ // чем ходит компухтер
    // const char X = 'X'; // крестик
    // const char O = 'O'; // нолик
    return inParam == 'X' ? 'O' : 'X';
}
void f7_displayBoard_pointer(const std::vector <char> * const); // отображение игрового поля
char f7_winner_pointer(const std::vector <char> * const); // Определить победителя поля игры
inline bool f7_isLegal_pointer(const std::vector <char> * const pointerBrd, int move) { //Легальный ли ход?
    //const char EMPTY = ' '; // пустая ячейка
    return pointerBrd->data()[move] == ' ';
}
int  f7_humanMove_pointer(const std::vector <char> * const);// ход кожанного ублюдка
int  f7_compucterMove_pointer(std::vector <char>, char);// ход компухтера
void f7_annonceWinner_pointer(char, char, char); //Поздравить победителя

void my7_f_askTextML(const char* const, std::string * const); // функция для игры - безумные библиотекари моя переделка через указатели
int my7_f_askNumberML(const char* const); // функция для игры - безумные библиотекари моя переделка через указатели
void my7_f_tellStoryML(const std::string * const, const std::string * const, int,
                       const std::string * const, const std::string * const); // функция для игры - безумные библиотекари моя переделка через указатели

// 8 глава

// 9 глава
// возвращает целочисленную еременную из "кучи"
int * f9_intOneHeap(); // фиункция для программы heap динамическое выделение памяти.
void f9_leak1_Heap(); // создает утечку памяти
void f9_leak2_Heap(); // создает утечку памяти еще

#endif //FUNCTION_GAME_HPP
