#include <stdio.h>
//#include "Database.h"
#include "Query.h"
#include "Algebra.h"


int main() {

    Database* database=new_Database();

    CSGfile(database, "CSG.txt");
    SNAPfile(database, "SNAP.txt");
    CPfile(database, "CP.txt");
    CDHfile(database, "CDH.txt");
    CRfile(database, "CR.txt");

//    CSGfile(database, "/Users/rainyzhao/Desktop/Project4/Code/CSG.txt");
//    SNAPfile(database, "/Users/rainyzhao/Desktop/Project4/Code/SNAP.txt");
//    CPfile(database, "/Users/rainyzhao/Desktop/Project4/Code/CP.txt");
//    CDHfile(database, "/Users/rainyzhao/Desktop/Project4/Code/CDH.txt");
//    CRfile(database, "/Users/rainyzhao/Desktop/Project4/Code/CR.txt");

    printf("\nCourse-StudentID-Grade relation\n");
    print_myCSG(database->CSGTable);
    printf("StudentID-Name-Address-Phone relation\n");
    print_mySNAP(database->SNAPTable);
    printf("Course-Prerequisite relation\n");
    print_myCP(database->CPTable);
    printf("Course-Day-Hour relation\n");
    print_myCDH(database->CDHTable);
    printf("Course-Room relation\n");
    print_myCR(database->CRTable);

/*
    Database* database=new_Database();
    printf("Inserting values to Course-StudentID-Grade relation\n");
    insert_CSG(database, new_CSG("CS101", "12345", "A"));
    insert_CSG(database, new_CSG("CS101", "67890", "B"));
    insert_CSG(database, new_CSG("EE200", "12345", "C"));
    insert_CSG(database, new_CSG("EE200", "22222", "B+"));
    insert_CSG(database, new_CSG("CS101", "33333", "A-"));
    insert_CSG(database, new_CSG("PH100", "67890", "C+"));
    printf("Course-StudentID-Grade relation\n");
    print_myCSG(database->CSGTable);

    printf("Inserting values to StudentID-Name-Address-Phone relation\n");
    insert_SNAP(database, new_SNAP("12345", "C.Brown", "12 Apple St.", "555-1234"));
    insert_SNAP(database, new_SNAP("67890", "L.Van Pelt", "34 Pear Ave.", "555-5678"));
    insert_SNAP(database, new_SNAP("22222", "P.Patty", "56 Grape Blvd.", "555-9999"));
    printf("StudentID-Name-Address-Phone relation\n");
    print_mySNAP(database->SNAPTable);

    printf("Inserting values to Course-Prerequisite relation\n");
    insert_CP(database, new_CP("CS101", "CS100"));
    insert_CP(database, new_CP("EE200", "EE005"));
    insert_CP(database, new_CP("EE200", "CS100"));
    insert_CP(database, new_CP("CS120", "CS101"));
    insert_CP(database, new_CP("CS121", "CS120"));
    insert_CP(database, new_CP("CS205", "CS101"));
    insert_CP(database, new_CP("CS206", "CS121"));
    insert_CP(database, new_CP("CS206", "CS205"));
    printf("Course-Prerequisite relation\n");
    print_myCP(database->CPTable);

    printf("Inserting values to Course-Day-Hour relation\n");
    insert_CDH(database, new_CDH("CS101", "M", "9AM"));
    insert_CDH(database, new_CDH("CS101", "W", "9AM"));
    insert_CDH(database, new_CDH("CS101", "F", "9AM"));
    insert_CDH(database, new_CDH("EE200", "Tu", "10AM"));
    insert_CDH(database, new_CDH("EE200", "W", "1PM"));
    insert_CDH(database, new_CDH("EE200", "Th", "10AM"));
    printf("Course-Day-Hour relation\n");
    print_myCDH(database->CDHTable);

    printf("Inserting values to Course-Room relation\n");
    insert_CR(database, new_CR("CS101", "Turing Aud."));
    insert_CR(database, new_CR("EE200", "25 Ohm Hall"));
    insert_CR(database, new_CR("PH100", "Newton Lab."));
    printf("Course-Room relation\n");
    print_myCR(database->CRTable);
*/


    printf("Operations of Example 8.2.\n");
    printf("lookup((CS101, 12345,*), Course-StudentId-Grade): ");
    CSG** temp1=lookup_CSG(database, new_CSG("CS101", "12345", "*"));
    print_myCSGInput(temp1);

    printf("lookup((CS205, CS120), Course-Prerequisite): ");
    CP** temp2=lookup_CP(database, new_CP("CS205", "CS120"));
    print_myCPInput(temp2);

    printf("delete((CS101, *), Course-Room):\n");
    delete_CR(database, new_CR("CS101", "*"));
    printf("After delete the tuple(s), the CR relation\n");
    print_myCR(database->CRTable);

    printf("insert((CS205, CS120), Course-Prerequisite):\n");
    insert_CP(database, new_CP("CS205", "CS120"));
    printf("After insert the tuple(s), the CP relation\n");
    print_myCP(database->CPTable);

    printf("insert((CS205, CS101), Course-Prerequisite):\n");
    insert_CP(database, new_CP("CS205", "CS101"));
    printf("After insert the tuple(s), the CP relation\n");
    print_myCP(database->CPTable);


    //undo the changes to better do part 2 and part 3
    insert_CR(database, new_CR("CS101", "Turing Aud."));
    delete_CP(database, new_CP("CS205", "CS120"));

    //Part 2
    Query(database);
    printf("\n");

    //Part 3
    printf("8.12: Selection of CSG based on Course CS101.\n");
    CSG** result1=select_CSG(database, "CS101");
    print_CSG(result1, 100);
    printf("8.13: Projection of CSG onto studentID.\n");
    S** result2=project_CSG_ID(result1);
    print_S(result2, 100);
    printf("8.14 Join CR and CDH.\n");
    CRDH** result3=join_CR_CDH(database);
    print_CRDH(result3, 500);
    printf("8.15 Select for those tuples having Room Turing Aud.\n");
    printf("Project onto Day and Hour.\n");
    DH** result4=project_CRDH_HourDay(select_CRDH(join_CR_CDH(database), "Turing Aud."));
    print_DH(result4, 100);

}

