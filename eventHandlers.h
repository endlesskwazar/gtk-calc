//
// Created by endlesskwazar on 19.03.19.
//

#ifndef UNTITLED_EVENTHANDLERS_H
#define UNTITLED_EVENTHANDLERS_H

#include <gtk/gtkbutton.h>
#include "store.h"

void on_seven_button_clicked(GtkButton* btn, gpointer data){
    Store* store = (Store*)data;
    store->setOperand("7");
}

void on_plus_button_clicked(GtkButton *btn, gpointer data){
    Store* store = (Store*)data;
    store->setOperator("+");
}

void on_equal_button_clicked(GtkButton* btn, gpointer data){
    Store* store = (Store*)data;
    store->calculateResult();
}

#endif //UNTITLED_EVENTHANDLERS_H
