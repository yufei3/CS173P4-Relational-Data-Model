//
// Created by Rainy ZHAO on 2020/11/13.
//

#include "Database.h"

Database* new_Database(){
    Database* this=(Database*)malloc(sizeof(Database));
    return this;
}

int hash(int key){
    return key%100;
}
int convertStringtoInt(char* key){
    int result=0;
    for (int i=0; i<strlen(key); i++){
        result=result+(int)key[i];
    }
    return result;
}

void insert_CSG(Database* database, CSG* insertTuple){
    int index=hash(convertStringtoInt(insertTuple->StudentID));
    if (database->CSGTable[index]==NULL){ //this is an empty bucket
        database->CSGTable[index]=insertTuple;
    }
    else {
        //there already are some tuples in the bucket
        CSG* head=database->CSGTable[index];
        while (head!=NULL){
            if (equal_CSG(head, insertTuple)){
                return;
            }
            else if (head->next!=NULL){
                head=head->next;
            }
            else {
                head->next=insertTuple;
            }
        }
    }
}

void insert_SNAP(Database* database, SNAP* insertTuple){
    int index=hash(convertStringtoInt(insertTuple->StudentID));
    if (database->SNAPTable[index]==NULL){
        database->SNAPTable[index]=insertTuple;
    }
    else {
        SNAP* head=database->SNAPTable[index];
        while (head!=NULL){
            if (equal_SNAP(head, insertTuple)){
                return;
            }
            else if (head->next!=NULL){
                head=head->next;
            }
            else {
                head->next=insertTuple;
            }
        }
    }
}

void insert_CP(Database* database, CP* insertTuple){
    int index=hash(convertStringtoInt(insertTuple->Course));
    if (database->CPTable[index]==NULL){
        database->CPTable[index]=insertTuple;
    }
    else {
        CP* head=database->CPTable[index];
        while (head!=NULL){
            if (equal_CP(head, insertTuple)){
                return;
            }
            else if (head->next!=NULL){
                head=head->next;
            }
            else {
                head->next=insertTuple;
            }
        }
    }
}

void insert_CDH(Database* database, CDH* insertTuple){
    int index=hash(convertStringtoInt(insertTuple->Course));
    if (database->CDHTable[index]==NULL){
        database->CDHTable[index]=insertTuple;
    }
    else {
        CDH* head=database->CDHTable[index];
        while (head!=NULL){
            if (equal_CDH(head, insertTuple)){
                return;
            }
            else if (head->next!=NULL){
                head=head->next;
            }
            else {
                head->next=insertTuple;
            }
        }
    }
}

void insert_CR(Database* database, CR* insertTuple){
    int index=hash(convertStringtoInt(insertTuple->Course));
    if (database->CRTable[index]==NULL){
        database->CRTable[index]=insertTuple;
    }
    else {
        CR* head=database->CRTable[index];
        while (head!=NULL){
            if (equal_CR(head, insertTuple)){
                return;
            }
            else if (head->next!=NULL){
                head=head->next;
            }
            else {
                head->next=insertTuple;
            }
        }
    }
}

void delete_CSG(Database* database, CSG* deleteTuple){
    if (strcmp(deleteTuple->StudentID, "*")==0){
        //primary index is *, do linear search
        for (int i=0; i<Size; i++){ //loop every bucket
            bool end=false;
            CSG* j=database->CSGTable[i];
            while (j!=NULL && !end){
                if (equal_CSG(j, deleteTuple)){
                    database->CSGTable[i]=j->next;
                    j=database->CSGTable[i];
                }
                else if (j->next!=NULL && equal_CSG(j->next, deleteTuple)){
                        j->next=j->next->next;
                        j=j->next;
                }
                else { //not equal j->next & deleteTuple
                    j=j->next;
                }
                if (j==NULL){
                    end=true;
                }
            }
        }
    }
    else { //primary index is not *, use index to delete
        int index=hash(convertStringtoInt(deleteTuple->StudentID));
        if (database->CSGTable[index]==NULL){ //not found with the studentID
            return;
        }
        CSG* tuple=database->CSGTable[index];
        while(tuple!=NULL){
            if (equal_CSG(tuple, deleteTuple)){
                CSG* todelete=database->CSGTable[index];
                database->CSGTable[index]=database->CSGTable[index]->next;
                free(todelete);
                tuple=database->CSGTable[index];
            }
            else if (tuple->next!=NULL && equal_CSG(tuple->next, deleteTuple)){
                database->CSGTable[index]->next=database->CSGTable[index]->next->next;
                tuple=database->CSGTable[index]->next;
            }
            else if (tuple->next==NULL){
                break;
            }
            else {
                tuple=database->CSGTable[index]->next;
            }
        }
    }
}

void delete_SNAP(Database* database, SNAP* deleteTuple){
    if (strcmp(deleteTuple->StudentID, "*")==0){
        //primary index is *, do linear search
        for (int i=0; i<Size; i++){ //loop every bucket
            bool end=false;
            SNAP* j=database->SNAPTable[i];
            while (j!=NULL && !end){
                if (equal_SNAP(j, deleteTuple)){
                    database->SNAPTable[i]=j->next;
                    j=database->SNAPTable[i];
                }
                else if (j->next!=NULL && equal_SNAP(j->next, deleteTuple)){
                    j->next=j->next->next;
                    j=j->next;
                }
                else { //not equal j->next & deleteTuple
                    j=j->next;
                }
                if (j==NULL){
                    end=true;
                }
            }
        }
    }
    else { //primary index is not *, use index to delete
        int index=hash(convertStringtoInt(deleteTuple->StudentID));
        if (database->SNAPTable[index]==NULL){ //not found with the studentID
            return;
        }
        SNAP* tuple=database->SNAPTable[index];
        while(tuple!=NULL){
            if (equal_SNAP(tuple, deleteTuple)){
                SNAP* todelete=database->SNAPTable[index];
                database->SNAPTable[index]=database->SNAPTable[index]->next;
                free(todelete);
                tuple=database->SNAPTable[index];
            }
            else if (tuple->next!=NULL && equal_SNAP(tuple->next, deleteTuple)){
                database->SNAPTable[index]->next=database->SNAPTable[index]->next->next;
                tuple=database->SNAPTable[index]->next;
            }
            else if (tuple->next==NULL){
                break;
            }
            else {
                tuple=database->SNAPTable[index]->next;
            }
        }
    }
}

void delete_CP(Database* database, CP* deleteTuple){
    if (strcmp(deleteTuple->Course, "*")==0){
        //primary index is *, do linear search
        for (int i=0; i<Size; i++){ //loop every bucket
            bool end=false;
            CP* j=database->CPTable[i];
            while (j!=NULL && !end){
                if (equal_CP(j, deleteTuple)){
                    database->CPTable[i]=j->next;
                    j=database->CPTable[i];
                }
                else if (j->next!=NULL && equal_CP(j->next, deleteTuple)){
                    j->next=j->next->next;
                    j=j->next;
                }
                else { //not equal j->next & deleteTuple
                    j=j->next;
                }
                if (j==NULL){
                    end=true;
                }
            }
        }
    }
    else { //primary index is not *, use index to delete
        int index=hash(convertStringtoInt(deleteTuple->Course));
        if (database->CPTable[index]==NULL){ //not found with the studentID
            return;
        }
        CP* tuple=database->CPTable[index];
        while(tuple!=NULL){
            if (equal_CP(tuple, deleteTuple)){
                CP* todelete=database->CPTable[index];
                database->CPTable[index]=database->CPTable[index]->next;
                free(todelete);
                tuple=database->CPTable[index];
            }
            else if (tuple->next!=NULL && equal_CP(tuple->next, deleteTuple)){
                database->CPTable[index]->next=database->CPTable[index]->next->next;
                tuple=database->CPTable[index]->next;
            }
            else if (tuple->next==NULL){
                break;
            }
            else {
                tuple=database->CPTable[index]->next;
            }
        }
    }
}

void delete_CDH(Database* database, CDH* deleteTuple){
    if (strcmp(deleteTuple->Course, "*")==0){
        //primary index is *, do linear search
        for (int i=0; i<Size; i++){ //loop every bucket
            bool end=false;
            CDH* j=database->CDHTable[i];
            while (j!=NULL && !end){
                if (equal_CDH(j, deleteTuple)){
                    database->CDHTable[i]=j->next;
                    j=database->CDHTable[i];
                }
                else if (j->next!=NULL && equal_CDH(j->next, deleteTuple)){
                    j->next=j->next->next;
                    j=j->next;
                }
                else { //not equal j->next & deleteTuple
                    j=j->next;
                }
                if (j==NULL){
                    end=true;
                }
            }
        }
    }
    else { //primary index is not *, use index to delete
        int index=hash(convertStringtoInt(deleteTuple->Course));
        if (database->CDHTable[index]==NULL){ //not found with the studentID
            return;
        }
        CDH* tuple=database->CDHTable[index];
        while(tuple!=NULL){
            if (equal_CDH(tuple, deleteTuple)){
                CDH* todelete=database->CDHTable[index];
                database->CDHTable[index]=database->CDHTable[index]->next;
                free(todelete);
                tuple=database->CDHTable[index];
            }
            else if (tuple->next!=NULL && equal_CDH(tuple->next, deleteTuple)){
                database->CDHTable[index]->next=database->CDHTable[index]->next->next;
                tuple=database->CDHTable[index]->next;
            }
            else if (tuple->next==NULL){
                break;
            }
            else {
                tuple=database->CDHTable[index]->next;
            }
        }
    }
}

void delete_CR(Database* database, CR* deleteTuple){
    if (strcmp(deleteTuple->Course, "*")==0){
        //primary index is *, do linear search
        for (int i=0; i<Size; i++){ //loop every bucket
            bool end=false;
            CR* j=database->CRTable[i];
            while (j!=NULL && !end){
                if (equal_CR(j, deleteTuple)){
                    database->CRTable[i]=j->next;
                    j=database->CRTable[i];
                }
                else if (j->next!=NULL && equal_CR(j->next, deleteTuple)){
                    j->next=j->next->next;
                    j=j->next;
                }
                else { //not equal j->next & deleteTuple
                    j=j->next;
                }
                if (j==NULL){
                    end=true;
                }
            }
        }
    }
    else { //primary index is not *, use index to delete
        int index=hash(convertStringtoInt(deleteTuple->Course));
        if (database->CRTable[index]==NULL){ //not found with the studentID
            return;
        }
        CR* tuple=database->CRTable[index];
        while(tuple!=NULL){
            if (equal_CR(tuple, deleteTuple)){
                CR* todelete=database->CRTable[index];
                database->CRTable[index]=database->CRTable[index]->next;
                free(todelete);
                tuple=database->CRTable[index];
            }
            else if (tuple->next!=NULL && equal_CR(tuple->next, deleteTuple)){
                database->CRTable[index]->next=database->CRTable[index]->next->next;
                tuple=database->CRTable[index]->next;
            }
            else if (tuple->next==NULL){
                break;
            }
            else {
                tuple=database->CRTable[index]->next;
            }
        }
    }
}

CSG** lookup_CSG(Database* database, CSG* lookupTuple){
    CSG** result=(CSG**)calloc(20, sizeof(CSG*));
    if (strcmp(lookupTuple->StudentID, "*")==0){
        //primary index is *, do linear search
        int i=0;
        for (int bucket=0; bucket<Size; bucket++){ //loop every bucket
            for (CSG* j=database->CSGTable[bucket]; j!=NULL; j=j->next){
                if (equal_CSG(j, lookupTuple)){
                    result[i]=j;
                    i++;
                }
            }
        }
    }
    else {
        int index = hash(convertStringtoInt(lookupTuple->StudentID));
        int i = 0;  //pointer to the current tuple in the result list
        for (CSG* j = database->CSGTable[index]; j != NULL; j = j->next) {
            if (equal_CSG(lookupTuple, j)) {
                result[i] = j;
                i++;
            }
        }
    }

    if (result[0]==NULL){ //result is empty
        return NULL;
    }
    else return result;
}

SNAP** lookup_SNAP(Database* database, SNAP* lookupTuple){
    SNAP** result=(SNAP**)calloc(20, sizeof(SNAP*));
    if (strcmp(lookupTuple->StudentID, "*")==0){
        //primary index is *, do linear search
        int i=0;
        for (int bucket=0; bucket<Size; bucket++){ //loop every bucket
            for (SNAP* j=database->SNAPTable[bucket]; j!=NULL; j=j->next){
                if (equal_SNAP(j, lookupTuple)){
                    result[i]=j;
                    i++;
                }
            }
        }
    }
    else {
        int index = hash(convertStringtoInt(lookupTuple->StudentID));
        int i = 0;  //pointer to the current tuple in the result list
        for (SNAP* j = database->SNAPTable[index]; j != NULL; j = j->next) {
            if (equal_SNAP(lookupTuple, j)) {
                result[i] = j;
                i++;
            }
        }
    }

    if (result[0]==NULL){ //result is empty
        return NULL;
    }
    else return result;
}

CP** lookup_CP(Database* database, CP* lookupTuple){
    CP** result=(CP**)calloc(20, sizeof(CP*));
    if (strcmp(lookupTuple->Course, "*")==0){
        //primary index is *, do linear search
        int i=0;
        for (int bucket=0; bucket<Size; bucket++){ //loop every bucket
            for (CP* j=database->CPTable[bucket]; j!=NULL; j=j->next){
                if (equal_CP(j, lookupTuple)){
                    result[i]=j;
                    i++;
                }
            }
        }
    }
    else {
        int index = hash(convertStringtoInt(lookupTuple->Course));
        int i = 0;  //pointer to the current tuple in the result list
        for (CP* j = database->CPTable[index]; j != NULL; j = j->next) {
            if (equal_CP(lookupTuple, j)) {
                result[i] = j;
                i++;
            }
        }
    }

    if (result[0]==NULL){ //result is empty
        return NULL;
    }
    else return result;
}

CDH** lookup_CDH(Database* database, CDH* lookupTuple){
    CDH** result=(CDH**)calloc(20, sizeof(CDH*));
    if (strcmp(lookupTuple->Course, "*")==0){
        //primary index is *, do linear search
        int i=0;
        for (int bucket=0; bucket<Size; bucket++){ //loop every bucket
            for (CDH* j=database->CDHTable[bucket]; j!=NULL; j=j->next){
                if (equal_CDH(j, lookupTuple)){
                    result[i]=j;
                    i++;
                }
            }
        }
    }
    else {
        int index = hash(convertStringtoInt(lookupTuple->Course));
        int i = 0;  //pointer to the current tuple in the result list
        for (CDH* j = database->CDHTable[index]; j != NULL; j = j->next) {
            if (equal_CDH(lookupTuple, j)) {
                result[i] = j;
                i++;
            }
        }
    }

    if (result[0]==NULL){ //result is empty
        return NULL;
    }
    else return result;
}

CR** lookup_CR(Database* database, CR* lookupTuple){
    CR** result=(CR**)calloc(20, sizeof(CR*));
    if (strcmp(lookupTuple->Course, "*")==0){
        //primary index is *, do linear search
        int i=0;
        for (int bucket=0; bucket<Size; bucket++){ //loop every bucket
            for (CR* j=database->CRTable[bucket]; j!=NULL; j=j->next){
                if (equal_CR(j, lookupTuple)){
                    result[i]=j;
                    i++;
                }
            }
        }
    }
    else {
        int index = hash(convertStringtoInt(lookupTuple->Course));
        int i = 0;  //pointer to the current tuple in the result list
        for (CR* j = database->CRTable[index]; j != NULL; j = j->next) {
            if (equal_CR(lookupTuple, j)) {
                result[i] = j;
                i++;
            }
        }
    }

    if (result[0]==NULL){ //result is empty
        return NULL;
    }
    else return result;
}

void print_myCSG(CSG** input){
    if (input==NULL){
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CSG* toPrint=input[i];
            while (toPrint!=NULL){
                printf("%s %s %s\n", toPrint->Course, toPrint->StudentID, toPrint->Grade);
                toPrint=toPrint->next;
                hasVal++;
            }
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_mySNAP(SNAP** input){
    if (input==NULL){
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            SNAP* toPrint=input[i];
            while (toPrint!=NULL){
                printf("%s %s %s %s\n", toPrint->StudentID, toPrint->Name, toPrint->Address, toPrint->Phone);
                toPrint=toPrint->next;
                hasVal++;
            }
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_myCP(CP** input){
    if (input==NULL){
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CP* toPrint=input[i];
            while (toPrint!=NULL){
                printf("%s %s\n", toPrint->Course, toPrint->Prerequisite);
                toPrint=toPrint->next;
                hasVal++;
            }
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_myCDH(CDH** input){
    if (input==NULL){
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CDH* toPrint=input[i];
            while (toPrint!=NULL){
                printf("%s %s %s\n", toPrint->Course, toPrint->Day, toPrint->Hour);
                toPrint=toPrint->next;
                hasVal++;
            }
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_myCR(CR** input){
    if (input==NULL){
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CR* toPrint=input[i];
            while (toPrint!=NULL){
                printf("%s %s\n", toPrint->Course, toPrint->Room);
                toPrint=toPrint->next;
                hasVal++;
            }
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}

void CSGfile(Database* database, char* filename){
    int MAX_LINE=100;
    char buf1[MAX_LINE];
    FILE *in1;
    in1=fopen(filename, "r");

    if (in1==NULL){
        printf("No such file.\n");
    }
    else {
        while (fgets(buf1, MAX_LINE, in1)!=NULL){
            char* split;
            split=strtok(buf1, ",");
            char* id=(char*)malloc(7*sizeof(char));
            char* course=(char*)malloc(7*sizeof(char));
            char* grade=(char*)malloc(3*sizeof(char));
            int i=0;
            while(split!=NULL){
                if (i==0){
                    strcpy(course, split);
                }
                if (i==1){
                    strcpy(id, split);
                }
                if (i==2){
                    strcpy(grade, split);
                }
                split=strtok(NULL, ",");
                i++;
            }
            if (strlen(grade)>0 && grade[strlen(grade)-1]=='\n'){
                grade[strlen(grade)-1]='\0';
            }
            insert_CSG(database, new_CSG(course, id, grade));
        }
    }
}
void SNAPfile(Database* database, char* filename){
    int MAX_LINE=100;
    char buf2[MAX_LINE];
    FILE *in2;
    in2=fopen(filename, "r");

    if (in2==NULL){
        printf("No such file.\n");
    }
    else {
        while (fgets(buf2, MAX_LINE, in2)!=NULL){
            char* split;
            split=strtok(buf2, ",");
            char* id=(char*)malloc(7*sizeof(char));
            char* name=(char*)malloc(20*sizeof(char));
            char* address=(char*)malloc(30*sizeof(char));
            char* phone=(char*)malloc(10*sizeof(char));
            int i=0;
            while(split!=NULL){
                if (i==0){
                    strcpy(id, split);
                }
                if (i==1){
                    strcpy(name, split);
                }
                if (i==2){
                    strcpy(address, split);
                }
                if (i==3){
                    strcpy(phone, split);
                }
                split=strtok(NULL, ",");
                i++;
            }
            if (strlen(phone)>0 && phone[strlen(phone)-1]=='\n'){
                phone[strlen(phone)-1]='\0';
            }
            insert_SNAP(database, new_SNAP(id, name, address, phone));
        }
    }
}

void CPfile(Database* database, char* filename){
    int MAX_LINE=100;
    char buf3[MAX_LINE];
    FILE *in3;
    in3=fopen(filename, "r");

    if (in3==NULL){
        printf("No such file.\n");
    }
    else {
        while (fgets(buf3, MAX_LINE, in3)!=NULL){
            char* split;
            split=strtok(buf3, ",");
            char* course=(char*)malloc(7*sizeof(char));
            char* prereq=(char*)malloc(7*sizeof(char));
            int i=0;
            while(split!=NULL){
                if (i==0){
                    strcpy(course, split);
                }
                if (i==1){
                    strcpy(prereq, split);
                }
                split=strtok(NULL, ",");
                i++;
            }
            if (strlen(prereq)>0 && prereq[strlen(prereq)-1]=='\n'){
                prereq[strlen(prereq)-1]='\0';
            }
            insert_CP(database, new_CP(course, prereq));
        }
    }
}

void CDHfile(Database* database, char* filename){
    int MAX_LINE=100;
    char buf4[MAX_LINE];
    FILE *in4;
    in4=fopen(filename, "r");

    if (in4==NULL){
        printf("No such file.\n");
    }
    else {
        while (fgets(buf4, MAX_LINE, in4)!=NULL){
            char* split;
            split=strtok(buf4, ",");
            char* course=(char*)malloc(7*sizeof(char));
            char* day=(char*)malloc(3*sizeof(char));
            char* hour=(char*)malloc(6*sizeof(char));
            int i=0;
            while(split!=NULL){
                if (i==0){
                    strcpy(course, split);
                }
                if (i==1){
                    strcpy(day, split);
                }
                if (i==2){
                    strcpy(hour, split);
                }
                split=strtok(NULL, ",");
                i++;
            }
            if (strlen(hour)>0 && hour[strlen(hour)-1]=='\n'){
                hour[strlen(hour)-1]='\0';
            }
            insert_CDH(database, new_CDH(course, day, hour));
        }
    }
}
void CRfile(Database* database, char* filename){
    int MAX_LINE=100;
    char buf5[MAX_LINE];
    FILE *in5;
    in5=fopen(filename, "r");

    if (in5==NULL){
        printf("No such file.\n");
    }
    else {
        while (fgets(buf5, MAX_LINE, in5)!=NULL){
            char* split;
            split=strtok(buf5, ",");
            char* course=(char*)malloc(7*sizeof(char));
            char* room=(char*)malloc(30*sizeof(char));
            int i=0;
            while(split!=NULL){
                if (i==0){
                    strcpy(course, split);
                }
                if (i==1){
                    strcpy(room, split);
                }
                split=strtok(NULL, ",");
                i++;
            }
            if (strlen(room)>0 && room[strlen(room)-1]=='\n'){
                room[strlen(room)-1]='\0';
            }
            insert_CR(database, new_CR(course, room));
        }
    }
}
void print_myCSGInput(CSG** input){
    if (input==NULL){
        printf("\n");
        printf("\n");
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CSG* toPrint=input[i];
            printf("%s %s %s\n", toPrint->Course, toPrint->StudentID, toPrint->Grade);
            hasVal++;

        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_mySNAPInput(SNAP** input){
    if (input==NULL){
        printf("\n");
        printf("\n");
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            SNAP* toPrint=input[i];
            printf("%s %s %s %s\n", toPrint->StudentID, toPrint->Name, toPrint->Address, toPrint->Phone);
            hasVal++;
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_myCPInput(CP** input){
    if (input==NULL){
        printf("\n");
        printf("\n");
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CP* toPrint=input[i];
            printf("%s %s\n", toPrint->Course, toPrint->Prerequisite);
            hasVal++;
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_myCDHInput(CDH** input){
    if (input==NULL){
        printf("\n");
        printf("\n");
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CDH* toPrint=input[i];
            printf("%s %s %s\n", toPrint->Course, toPrint->Day, toPrint->Hour);
            hasVal++;
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
void print_myCRInput(CR** input){
    if (input==NULL){
        printf("\n");
        printf("\n");
        return;
    }
    int hasVal=0;
    for (int i=0; i<100; i++){
        if (input[i]!=NULL){
            CR* toPrint=input[i];
            printf("%s %s\n", toPrint->Course, toPrint->Room);
            hasVal++;
        }
    }
    if (hasVal==0){
        printf("empty set\n");
    }
    printf("\n");
}
