//
// Created by endlesskwazar on 19.03.19.
//

#ifndef UNTITLED_EVALUETOR_H
#define UNTITLED_EVALUETOR_H

#include <glib/gtypes.h>
#include "operators.h"

gdouble eval(gdouble leftOperand, gdouble rightOperand, Operators op){
    gdouble res = 0;

    switch (op){
        case Operators::plusOperator:
            res = leftOperand + rightOperand;
            break;
    }

    return res;
}

#endif //UNTITLED_EVALUETOR_H
