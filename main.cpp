//#include <QCoreApplication>
//#include <QLocale>
//#include <QTranslator>
/* что сгенерировало Qt
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "My_Game_Console_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    return a.exec();
} */


#include "body_game.hpp"
#include "exc_from_book.hpp"

int main() {
    // переменные для теста.
    //int num = 80;

    //std::cout << "Morning" << std::endl;
    //lost_fortune();
    //guess_my_number();
    //my2_menu_chooser();
    //my2_find_err();
    //my2_guess_pc_number();
    //word_jumble();
    //my3_word_jumble();
    //hungman();
    //my4_test2();
    //my4_list_of_game();

    //give_me_a_number(num);
    //taking_gamage(num);
    //mad_lib();
    //std:: cout << my5_hungman_get_word("test"); // проверка функции
    //my5_hungman(2);
    //my5_test3();
    //tic_tac_toi(false);
    //my6_mad_lib();
    //main_body();
    //swap_pointer_ver();
    //inventory_pointer();
    //array_passer();
    //tic_tac_toe_ver_pointer(true); // крестики-ноли ки 2.0
    //my7_test3();
    //my7_mad_lib();
    //G8_CritterBegin();
    //G8_TamagochiBook();
    //my8_Critter_mode();
    //G9_critter_farm();
    //G9_critter_friend();
    //G9_heap();
    //G9_critter_heap_game();
    //G9_Lobby_game();
    //my9_lobby_mode();
    //G10_enemy_boss1();
    //G10_enemy_boss2();
    //G10_virtual_boss();
    //G10_polymorphicBadGay();
    //G10_abstractCreater();
    G10_BlackJack();

    /* генератор символов = )
    std::srand(static_cast <unsigned int> (std::time(0) ));
    char gen_simb;
    const char stop_simb = 'a';
    int counter = 1;
    std::cout << "Start generate simbols\n\n";
    do {
        gen_simb = generate_simbol();
        if(counter++ % 100 == 0)
            std::cout << counter << std::endl;
    } while(gen_simb != stop_simb);
    std::cout << "\n\tstop generate! simb: " << gen_simb << " !stop: " << stop_simb
              << "  !counter = " << counter; // */
    return 0;
}
