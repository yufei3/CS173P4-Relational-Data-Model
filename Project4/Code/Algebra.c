//
// Created by Rainy ZHAO on 2020/11/15.
//
#include "Algebra.h"

//Example 8.12
//choose those tuples that have the Course component course
CSG** select_CSG(Database* database, char* course){
    CSG** result=(CSG**)calloc(100, sizeof(CSG*));
    int index=0;
    for (int i=0; i<Size; i++){
        for (CSG* j=database->CSGTable[i]; j!=NULL; j=j->next){
            if (strcmp(j->Course, course)==0){
                result[index]=j;
                index++;
            }
        }
    }
    if (result==NULL){
        return NULL;
    }
    else {
        return result;
    }
}
//Example 8.13
S** project_CSG_ID(CSG** relation){
    S** result=(S**)calloc(100, sizeof(S*));
    int index=0;
    for (int i=0; i<100; i++){
        if (relation[i]!=NULL) {
            S *toAdd = new_S(relation[i]->StudentID);
            int found = 0;
            for (int j = 0; j <=index && found==0; j++) {
                if (result[j] != NULL && equal_S(result[j], toAdd)){
                    found=1;
                }
            }
            if (found==0){
                result[index]=toAdd;
                index++;
            }
            else free(toAdd);
        }

    }
    if (result==NULL){
        return NULL;
    }
    else {
        return result;
    }
}

//Example 8.14
CRDH** join_CR_CDH(Database* database){
    int index=0;
    CRDH** result=(CRDH**)calloc(500, sizeof(CRDH*));
    for (int i=0; i<Size; i++){
        if (database->CRTable[i]!=NULL){
            for (CR* iterCR=database->CRTable[i]; iterCR!=NULL; iterCR=iterCR->next){
                for (int k=0; k<Size; k++){
                    if (database->CDHTable[k]!=NULL){
                        for (CDH* iterCDH=database->CDHTable[k]; iterCDH!=NULL && strcmp(iterCR->Course, iterCDH->Course)==0; iterCDH=iterCDH->next){
                            CRDH* toAdd=new_CRDH(iterCR->Course, iterCR->Room, iterCDH->Day, iterCDH->Hour);
                            int found=0;
                            for (int j=0; j<=index && found==0; j++){
                                if (result[j]!=NULL && equal_CRDH(result[j], toAdd)){
                                    found=1;
                                }
                            }
                            if (found==0){
                                result[index]=toAdd;
                                index++;
                            }
                            else free(toAdd);
                        }
                    }
                }
            }
        }
    }
    if (result==NULL){
        return NULL;
    }
    else {
        return result;
    }
}

//Example 8.15
CRDH** select_CRDH(CRDH** relation, char* room){
    CRDH** result=(CRDH**)calloc(100, sizeof(CSG*));
    int index=0;
    for (int i=0; i<500; i++){
        if (relation[i]!=NULL){
            if (strcmp(relation[i]->Room, room)==0){
                result[index]=relation[i];
                index++;
            }
        }
    }
    return result;
}
DH** project_CRDH_HourDay(CRDH** relation){
    DH** result=(DH**)calloc(100, sizeof(DH*));
    int index=0;
    for (int i=0; i<100; i++){
        if (relation[i]!=NULL){
            DH* toAdd=new_DH(relation[i]->Day, relation[i]->Hour);
            int found=0;
            for (int j=0; j<100 && found==0; j++){
                if (result[j]!=NULL && equal_DH(result[j], toAdd)){
                    found=1;
                }
            }
            if (found==0){
                result[index]=toAdd;
                index++;
            }
            else free(toAdd);
        }
    }
    if (result==NULL){
        return NULL;
    }
    else{
        return result;
    }
}

void print_S(S** result, int length){
    for (int i=0; i<length; i++){
        if (result[i]!=NULL){
            printf("%s\n", result[i]->StudentID);
        }
    }
    printf("\n");
}

void print_CRDH(CRDH** result, int length){
    for (int i=0; i<length; i++){
        if (result[i]!=NULL){
            printf("%s %s %s %s\n", result[i]->Course, result[i]->Room, result[i]->Day, result[i]->Hour);
        }
    }
    printf("\n");
}

void print_CSG(CSG** result, int length){
    for (int i=0; i<length; i++){
        if (result[i]!=NULL){
            printf("%s %s %s\n", result[i]->Course, result[i]->StudentID, result[i]->Grade);
        }
    }
    printf("\n");
}

void print_DH(DH** result, int length){
    for (int i=0; i<length; i++){
        if (result[i]!=NULL){
            printf("%s %s\n", result[i]->Day, result[i]->Hour);
        }
    }
    printf("\n");
}