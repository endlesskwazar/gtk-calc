//
// Created by endlesskwazar on 19.03.19.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

#include <glib/gtypes.h>
#include <glib.h>
#include "operators.h"
#include "store.h"

Operators getOperatorByChar(const gchar* charOperator){
    if(g_str_equal("+",charOperator))
        return Operators::plusOperator;
}

#endif //UNTITLED_UTILS_H
