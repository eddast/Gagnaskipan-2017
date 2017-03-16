#ifndef INTERFACE_H
#define INTERFACE_H
#include "gameplay.h"


class Interface
{
    public:
        virtual ~Interface(){}
        void start();
        void exit_program();

    private:
        void main_menu();
        void menu_or_quit();
        void instructions();
        void WB_header();
        void WB_add_header();
        void game_header();
        void high_score_header();

};

#endif // INTERFACE_H
