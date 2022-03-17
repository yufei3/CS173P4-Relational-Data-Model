//
// Created by Rainy ZHAO on 2020/11/15.
//

#ifndef UNTITLED4_ALGEBRA_H
#define UNTITLED4_ALGEBRA_H

#endif //UNTITLED4_ALGEBRA_H
#include "Database.h"

//Example 8.12
CSG** select_CSG(Database* database, char* Course);

//Example 8.13
S** project_CSG_ID(CSG** relation);

//Example 8.14
CRDH** join_CR_CDH(Database* database);

//Example 8.15
CRDH** select_CRDH(CRDH** relation, char* room);
DH** project_CRDH_HourDay(CRDH** relation);

void print_S(S** result, int length);
void print_CRDH(CRDH** result, int length);
void print_CSG(CSG** result, int length);
void print_DH(DH** result, int length);