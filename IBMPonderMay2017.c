/*
    Problem: https://www.research.ibm.com/haifa/ponderthis/challenges/May2017.html
    Ponder This Challenge:
    In the string CABACB, each letter appears exactly twice and the number of characters
    between the "A"s is one, between the "B"s is two, and between the "C"s is three.
    The same problem with the letters A-E cannot be solved, but adding a 
    space (in the form of a hyphen) allows it to be solved.
    For example, in the string ADAEC-DBCEB, the number of characters between the "A"s is one,
    between the "B"s is two, between the "C"s is three (counting the space), between the "D"s
    is four, and between the "E"s is five.
    Find a string of letters (A-Z) and "-" whose length is no more than 53 characters, where
    each of the 26 letters A-Z appears exactly twice, and there is one character between
    the "A"s, two between the "B"s ... and 26 between the "Z"s.
*/

#include <stdio.h>

#define SIZE 75
#define SEPERATOR '-'
void initialize();
void generateKey();
void generateAlternative();
void fillTuplets(char ch, int distanceBetween);
void verifyResult();

char result[SIZE];

char alpha[26];

int main(int argc, const char * argv[]) {
//    verifyResult();
    
    initialize();
    generateKey();
//    initialize();
//    generateAlternative();
    return 0;
}

void verifyResult(){
    char result[] = "ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHBICB-FCEHJLIFE";
    
    for (int i = 0; i < 53; i++) {
        char posChar = result[i];
        for (int j = i + 1; j < 53; j++) {
            if (posChar == result[j]) {
                printf("%c distance: %d\n", posChar, j - i - 1);
            }
        }
    }
    
}
int nextAvailablePosition(int availablePosition){
    for (int i = availablePosition; i < SIZE; i++) {
        if (result[i] == SEPERATOR) {
            availablePosition = i;
            break;
        }
    }
    return availablePosition;
}

void generateAlternative() {
    
    int space = 1;
    for (char i = 0; i < 13; i += 1) {

        fillTuplets('A' + i, space);
        fillTuplets('Z' - i, 27 - space);
        
        space++;
        //printf("Filled Characters: %c, %c; String: %s\n", 'A' + i, 'Z' - i, result);
        
        printf("%s\n", result);
    }
}

void fillTuplets(char ch, int distanceBetween) {
    int emptyPosition = nextAvailablePosition(0);
    while (result[emptyPosition + distanceBetween + 1] != SEPERATOR) {
        //  printf("conflict Ch: %c", result[emptyPosition + distanceBetween + 1]);
        emptyPosition = nextAvailablePosition(emptyPosition + 1);
    }
    
    result[emptyPosition] = ch;
    result[emptyPosition + distanceBetween + 1] = ch;
}

void generateKey() {
    int space = 26;
    for (char ch = 'Z'; ch >= 'A'; ch -= 1) {
        fillTuplets(ch, space);
        space--;
        printf("%s\n", result);
    }
}

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        result[i] = SEPERATOR;
    }
    result[SIZE-1] = '\0';
    
    // initialize alphabets
    for (int i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
    }
}

/*
 With the result from the program, reached solution by hand
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHFIB--BEFHJLIEC---C
 --->
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHBICB-FCEHJLIFE
 
 
 Some rough work done:
 
 A-A
 ABA-B or B-ABA
 CABACB or BCABAC
 CADACB-DB
 ACADBC-BD
 C--DCABADB
 ACADECB-DBE
 ACADECB-DBE
 
 
 
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHFIB--BEFHJLIEC---C
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHBICB-FCEHJLIFE  C-3 & B-2 & E-5 F6 I-9
 ZXYUSWPVMKTGCRBQCBOGNKMPSUXZYWVTRQONLJHEI---FE-HJLIF   D-4 & E-5 & F-6 & A-1
 
 
 YWUSQOMKIGECA-ACEGIKMOQSUWY
 ZXVTRPNLJHFDB--BDFHJLNPRTVXZ
 
 
 YWUSQO-KIGECA-ACEGIK-OQSUWY  M13
 ZXVTRP-LJHFDB--BDFHJL-PRTVXZ N14
 
 YWUSQOMKIGEC---CEGIKMOQSUWY
 ZXVTRPNLJHF------FHJLNPRTVX
 
 A B D
 
 A - 1
 BCD
 E - 5
 FGHI
 J - 10
 KLMN
 O - 15
 PQRS
 T - 20
 UVWX
 Y - 25
 
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHFIB--BEFHJLIEC---C
 --->
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJHBICB-FCEHJLIFE
 
 ZXYUSWPVMKTGDRAQADOGNKMPSUXZYWVTRQONLJH-I------HJLI--
 
 */
