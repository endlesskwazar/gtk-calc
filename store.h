//
// Created by endlesskwazar on 13.03.19.
//

#ifndef UNTITLED_STORE_H
#define UNTITLED_STORE_H

#include <glib/gtypes.h>
#include "operators.h"
#include "utils.h"
#include "evaluetor.h"
#include "consts.h"

struct Store{
    gchar* leftOperand = "";
    gchar* rightOperand = "";
    gboolean isSecondOperand;
    Operators currentOperator;
    gdouble result;
    GtkWidget* calcDisplayEntry;

    void appendToDisplay(const gchar* value){
        const gchar* currentText = gtk_entry_get_text(GTK_ENTRY(calcDisplayEntry));
        //last NULL - terminating list
        gchar* res = g_strconcat(currentText, value, NULL);
        gtk_entry_set_text(GTK_ENTRY(this->calcDisplayEntry), res);
    }

    void setOperator(const gchar* charOperator){
        isSecondOperand = !isSecondOperand;
        currentOperator = getOperatorByChar(charOperator);
        appendToDisplay(charOperator);
    }

    void setOperand(const gchar* value){
        if(isSecondOperand)
            rightOperand = g_strconcat(rightOperand, value, NULL);
        else
            leftOperand = g_strconcat(leftOperand, value, NULL);
        appendToDisplay(value);
    }

    void clearDisplay(){
        gtk_entry_set_text(GTK_ENTRY(calcDisplayEntry), "");
    }

    void calculateResult(){
        gdouble res = eval(
                g_strtod(leftOperand, NULL),
                g_strtod(rightOperand, NULL),
                currentOperator);
        clearDisplay();
        //convert gdouble to gcahr
        gchar buf[ACCURATE_FACTOR];
        gchar* resToDisplay = g_ascii_dtostr(buf, 5, res);
        appendToDisplay(resToDisplay);
    }


};

#endif //UNTITLED_STORE_H
