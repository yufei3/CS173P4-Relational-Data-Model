//
// Created by Rainy ZHAO on 2020/11/13.
//
#include <stdbool.h>
#include "Tuple.h"

CSG* new_CSG(char* Course, char* StudentID, char* Grade){
    CSG* this=(CSG*)calloc(1, sizeof(CSG));
    strcpy(this->Course, Course);
    strcpy(this->StudentID, StudentID);
    strcpy(this->Grade, Grade);
    return this;
}
SNAP* new_SNAP(char* StudentID, char* Name, char* Address, char* Phone){
    SNAP* this=(SNAP*)calloc(1, sizeof(SNAP));
    strcpy(this->StudentID, StudentID);
    strcpy(this->Name, Name);
    strcpy(this->Address, Address);
    strcpy(this->Phone, Phone);
    return this;
}
CP* new_CP(char* Course, char* Prerequisite){
    CP* this=(CP*)calloc(1, sizeof(CP));
    strcpy(this->Course, Course);
    strcpy(this->Prerequisite,Prerequisite);
    return this;
}
CDH* new_CDH(char* Course, char* Day, char* Hour){
    CDH* this=(CDH*)calloc(1, sizeof(CDH));
    strcpy(this->Course, Course);
    strcpy(this->Day, Day);
    strcpy(this->Hour, Hour);
    return this;
}
CR* new_CR(char* Course, char* Room){
    CR* this=(CR*)calloc(1, sizeof(CR));
    strcpy(this->Course, Course);
    strcpy(this->Room, Room);
    return this;
}
S* new_S(char* StudentID){
    S* this=(S*)calloc(1, sizeof(S));
    strcpy(this->StudentID, StudentID);
    return this;
}
DH* new_DH(char* Day, char* Hour){
    DH* this=(DH*)calloc(1, sizeof(DH));
    strcpy(this->Day, Day);
    strcpy(this->Hour, Hour);
    return this;
}
CRDH* new_CRDH(char* Course, char* Room, char* Day, char* Hour){
    CRDH* this=(CRDH*)calloc(1, sizeof(CRDH));
    strcpy(this->Course, Course);
    strcpy(this->Room, Room);
    strcpy(this->Day, Day);
    strcpy(this->Hour, Hour);
    return this;
}

bool equal_CSG(CSG* t1, CSG* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->StudentID, t2->StudentID)!=0) &&
    !((strcmp(t1->StudentID, "*")==0) || (strcmp(t2->StudentID, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Course, t2->Course)!=0) &&
    !((strcmp(t1->Course, "*")==0) || (strcmp(t2->Course, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Grade, t2->Grade)!=0) &&
    !((strcmp(t1->Grade, "*")==0) || (strcmp(t2->Grade, "*")==0))){
        return false;
    }
    return true; //all components are the same
}

bool equal_SNAP(SNAP* t1, SNAP* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->StudentID, t2->StudentID)!=0) &&
    !((strcmp(t1->StudentID, "*")==0) || (strcmp(t2->StudentID, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Name, t2->Name)!=0) &&
    !((strcmp(t1->Name, "*")==0) || (strcmp(t2->Name, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Address, t2->Address)!=0) &&
    !((strcmp(t1->Address, "*")==0) || (strcmp(t2->Address, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Phone, t2->Phone)!=0) &&
    !((strcmp(t1->Phone, "*")==0) || (strcmp(t2->Phone, "*")==0))){
        return false;
    }
    return true; //all components are the same
}
bool equal_CP(CP* t1, CP* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->Course, t2->Course)!=0) &&
    !((strcmp(t1->Course, "*")==0) || (strcmp(t2->Course, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Prerequisite, t2->Prerequisite)!=0) &&
    !((strcmp(t1->Prerequisite, "*")==0) || (strcmp(t2->Prerequisite, "*")==0))){
        return false;
    }
    return true; //all components are the same
}
bool equal_CDH(CDH* t1, CDH* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->Course, t2->Course)!=0) &&
        !((strcmp(t1->Course, "*")==0) || (strcmp(t2->Course, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Day, t2->Day)!=0) &&
        !((strcmp(t1->Day, "*")==0) || (strcmp(t2->Day, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Hour, t2->Hour)!=0) &&
        !((strcmp(t1->Hour, "*")==0) || (strcmp(t2->Hour, "*")==0))){
        return false;
    }
    return true; //all components are the same
}
bool equal_CR(CR* t1, CR* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->Course, t2->Course)!=0) &&
        !((strcmp(t1->Course, "*")==0) || (strcmp(t2->Course, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Room, t2->Room)!=0) &&
        !((strcmp(t1->Room, "*")==0) || (strcmp(t2->Room, "*")==0))){
        return false;
    }
    return true; //all components are the same
}
bool equal_S(S* t1, S* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->StudentID, t2->StudentID)!=0) &&
        !((strcmp(t1->StudentID, "*")==0) || (strcmp(t2->StudentID, "*")==0))){
        return false;
    }
    return true;
}
bool equal_CRDH(CRDH* t1, CRDH* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->Course, t2->Course)!=0) &&
        !((strcmp(t1->Course, "*")==0) || (strcmp(t2->Course, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Room, t2->Room)!=0) &&
        !((strcmp(t1->Room, "*")==0) || (strcmp(t2->Room, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Day, t2->Day)!=0) &&
        !((strcmp(t1->Day, "*")==0) || (strcmp(t2->Day, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Hour, t2->Hour)!=0) &&
        !((strcmp(t1->Hour, "*")==0) || (strcmp(t2->Hour, "*")==0))){
        return false;
    }
    return true; //all components are the same
}
bool equal_DH(DH* t1, DH* t2){
    if (t1==NULL || t2==NULL){
        return false;
    }
    if ((strcmp(t1->Day, t2->Day)!=0) &&
        !((strcmp(t1->Day, "*")==0) || (strcmp(t2->Day, "*")==0))){
        return false;
    }
    if ((strcmp(t1->Hour, t2->Hour)!=0) &&
        !((strcmp(t1->Hour, "*")==0) || (strcmp(t2->Hour, "*")==0))){
        return false;
    }
    return true;
}

