//
// Created by Rainy ZHAO on 2020/11/13.
//

#ifndef UNTITLED4_TUPLE_H
#define UNTITLED4_TUPLE_H

#endif //UNTITLED4_TUPLE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IDLength 7
#define CourseLength 7
#define GradeLength 3
#define NameLength 20
#define AddressLength 30
#define PhoneLength 10
#define DayLength 3
#define HourLength 6
#define RoomLength 30

//Course-StudentID-Grade
typedef struct CSG{
    char StudentID[IDLength];
    char Course[CourseLength];
    char Grade[GradeLength];
    struct CSG* next;
}CSG;

//StudentID-Name-Address-Phone
typedef struct SNAP{
    char StudentID[IDLength];
    char Name[NameLength];
    char Address[AddressLength];
    char Phone[PhoneLength];
    struct SNAP* next;
}SNAP;

//Course-Prerequisite
typedef struct CP{
    char Course[CourseLength];
    char Prerequisite[CourseLength];
    struct CP* next;
}CP;

//Course-Day-Hour
typedef struct CDH{
    char Course[CourseLength];
    char Day[DayLength];
    char Hour[HourLength];
    struct CDH* next;
}CDH;

//Course-Room
typedef struct CR{
    char Course[CourseLength];
    char Room[RoomLength];
    struct CR* next;
}CR;

//Used only for part 3 Relational Algebra--Projection of CSG onto StudentID
typedef struct S{
    char StudentID[IDLength];
    struct S* next;
}S;

//Used only for part 3 Relational Algebra
typedef struct CRDH{
    char Course[CourseLength];
    char Room[RoomLength];
    char Day[DayLength];
    char Hour[HourLength];
    struct CRDH* next;
}CRDH;

//Used only for part 3 Relational Algebra
typedef struct DH{
    char Day[DayLength];
    char Hour[HourLength];
    struct DH* next;
}DH;

CSG* new_CSG(char* Course, char* StudentID, char* Grade);
SNAP* new_SNAP(char* StudentID, char* Name, char* Address, char* Phone);
CP* new_CP(char* Course, char* Prerequisite);
CDH* new_CDH(char* Course, char* Day, char* Hour);
CR* new_CR(char* Course, char* Room);
CRDH* new_CRDH(char* Course, char* Room, char* Day, char* Hour);
S* new_S(char* StudentID);
DH* new_DH(char* Day, char* Hour);

bool equal_CSG(CSG* t1, CSG* t2);
bool equal_SNAP(SNAP* t1, SNAP* t2);
bool equal_CP(CP* t1, CP* t2);
bool equal_CDH(CDH* t1, CDH* t2);
bool equal_CR(CR* t1, CR* t2);
bool equal_CRDH(CRDH* t1, CRDH* t2);
bool equal_S(S* t1, S* t2);
bool equal_DH(DH* t1, DH* t2);