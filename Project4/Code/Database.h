//
// Created by Rainy ZHAO on 2020/11/13.
//

#ifndef UNTITLED4_DATABASE_H
#define UNTITLED4_DATABASE_H

#include "Tuple.h"
#include <stdio.h>
#define Size 100

typedef struct Database{
    CSG* CSGTable[Size];
    SNAP* SNAPTable[Size];
    CP* CPTable[Size];
    CDH* CDHTable[Size];
    CR* CRTable[Size];
}Database;

Database* new_Database();
void insert_CSG(Database* database, CSG* insertTuple);
void insert_SNAP(Database* database, SNAP* insertTuple);
void insert_CP(Database* database, CP* insertTuple);
void insert_CDH(Database* database, CDH* insertTuple);
void insert_CR(Database* database, CR* insertTuple);

void delete_CSG(Database* database, CSG* deleteTuple);
void delete_SNAP(Database* database, SNAP* insertTuple);
void delete_CP(Database* database, CP* insertTuple);
void delete_CDH(Database* database, CDH* insertTuple);
void delete_CR(Database* database, CR* insertTuple);

CSG** lookup_CSG(Database* database, CSG* lookupTuple);
SNAP** lookup_SNAP(Database* database, SNAP* lookupTuple);
CP** lookup_CP(Database* database, CP* lookupTuple);
CDH** lookup_CDH(Database* database, CDH* lookupTuple);
CR** lookup_CR(Database* database, CR* lookupTuple);

void print_myCSG(CSG** input);
void print_mySNAP(SNAP** input);
void print_myCP(CP** input);
void print_myCDH(CDH** input);
void print_myCR(CR** input);

void CSGfile(Database* database, char* filename);
void SNAPfile(Database* database, char* filename);
void CPfile(Database* database, char* filename);
void CDHfile(Database* database, char* filename);
void CRfile(Database* database, char* filename);

void print_myCSGInput(CSG** input);
void print_mySNAPInput(SNAP** input);
void print_myCPInput(CP** input);
void print_myCDHInput(CDH** input);
void print_myCRInput(CR** input);
#endif //UNTITLED4_DATABASE_H