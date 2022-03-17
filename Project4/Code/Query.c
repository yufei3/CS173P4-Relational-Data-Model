//
// Created by Rainy ZHAO on 2020/11/14.
//
#include <stdio.h>
#include "Query.h"
#define NameSize 20
#define CourseSize 7
#define DaySize 2
#define TimeSize 5

void Query(Database* database){
    int num=-1;
//    char name[NameSize];
//    char course[CourseSize];
//    char time[TimeSize];
//    char day[DaySize];
    char* name=(char*)malloc(NameSize*sizeof(char));
    char* course=(char*)malloc(CourseSize*sizeof(char));
    char* time=(char*)malloc(TimeSize*sizeof(char));
    char* day=(char*)malloc(DaySize*sizeof(char));

    printf("Please enter the index of question (1 for What Question, 2 for Where Question, 0 for stop): ");
    scanf("%d", &num);
    setbuf(stdin, NULL);
    switch (num){
        case 0:
            printf("Exit...\n");
            break;
        case 1:
            printf("What grade did StudentName get in CourseName?\n");
            printf("Enter student name: ");
            scanf("%[^\n]", name);
            printf("Enter course name: ");
            scanf("%s", course);
            Question1(database, name, course);
            break;
        case 2:
            printf("Where is StudentName at Time on Day?\n");
            printf("Enter student name: ");
            scanf("%[^\n]", name);
            setbuf(stdin, NULL);
            printf("Enter hour: ");
            scanf("%s", time);
            setbuf(stdin, NULL);
            printf("Enter day: ");
            scanf("%s", day);

            Question2(database, name, time, day);
            break;
        default:
            printf("Invalid input. Exit.\n");
            break;
    }
    if (num==1 || num==2){
        Query(database);
    }
}

//What grade did StudentName get in CourseName?
/*
 * Question 1
 * for all tuples that have inputStudentName as name
 * find their studentID with the SNAP relation
 * find each tuple T with the given studentID and inputCourseName with the CSG relation
 * print the grade of T
 */
void Question1(Database* database, char* inputStudentName, char* inputCourseName){
    bool pair=false;
    printf("What grade did %s get in %s?\n", inputStudentName, inputCourseName);
    SNAP** set=lookup_SNAP(database, new_SNAP("*", inputStudentName, "*", "*"));
    int i=0;
    if (set==NULL){
        pair=true;
        printf("There is no student with name %s.\n", inputStudentName);
    }
    else {
        while (set[i] != NULL) { //for all tuples with the inputStudentName
            char *ID = set[i]->StudentID;
            CSG **result = lookup_CSG(database, new_CSG(inputCourseName, ID, "*"));
            int j = 0;
            if (result!=NULL) {
                while (result[j] != NULL) {
                    pair = true;
                    char *grade = result[j]->Grade;
                    printf("%s get %s in %s.\n", inputStudentName, grade, inputCourseName);
                    j++;
                }
            }
            i++;
        }
    }
    if (!pair){
        printf("Do not find the grade with given studentName and courseName.\n");
    }
    printf("\n");
}


//Where is StudentName at Time on Day?
/*
 * for all tuples in SNAP, find the studentID with inputStudentName as name
 * find all courses they take with CSG relation
 * check whether there is a CDH tuple with the found course, inputDay, inputTime as components
 * if there is, find the corresponding room of that found course in CR relation
 */
void Question2(Database* database, char* inputStudentName, char* inputTime, char* inputDay){
    bool pair=false;
    printf("Where is %s at %s on %s?\n", inputStudentName, inputTime, inputDay);
    SNAP** set=lookup_SNAP(database, new_SNAP("*", inputStudentName, "*", "*"));
    int i=0;
    if (set==NULL){
        pair=true;
        printf("There is no student with name %s.\n", inputStudentName);
    }
    else {
        while (set[i] != NULL) { //for all tuples with the inputStudentName
            char *ID = set[i]->StudentID;
            CSG **courses = lookup_CSG(database, new_CSG("*", ID, "*"));
            int j = 0;
            if (courses == NULL) {
                printf("No such courses with the given studentID.\n");
            }
            else {
                while (courses[j] != NULL) {
                    char *mycourse = courses[j]->Course;
                    if (lookup_CDH(database, new_CDH(mycourse, inputDay, inputTime)) != NULL) {
                        pair = true;
                        char *room = lookup_CR(database, new_CR(mycourse, "*"))[0]->Room;
                        printf("%s is at %s at %s on %s.\n", inputStudentName, room, inputTime, inputDay);
                    }
                    j++;
                }
            }
            i++;
        }
    }
    if (!pair){
        printf("Do not find the corresponding course with given studentName, hour, and day.\n");
    }
    printf("\n");
}

