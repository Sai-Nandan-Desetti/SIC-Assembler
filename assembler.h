#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define NO_OF_INSTRUCTIONS 26


int LINE_NUM;

enum Equality	   {EQUAL,NOT_EQUAL};
enum SearchResult  {FOUND,NOT_FOUND};
enum Keyword       {NOT_KEYWORD,OPCODE,NOT_OPCODE,NOT_ASSEMBLY_DIRECTIVE,START,WORD,RESB,RESW,BYTE,END};

typedef enum Keyword Keyword;



////////////////////////////////////////////////////// DATA STRUCTURES ///////////////////////////////////////////////////////

struct Line {

       char *label;
       char *keyword;
       char *operand;
       unsigned int loc;

};

typedef struct Line Line;




struct OpTab{

       char *mnemonic[NO_OF_INSTRUCTIONS];
       unsigned int hexCode[NO_OF_INSTRUCTIONS];

};

typedef struct OpTab OpTab;




struct SymField{

       char *label;
       unsigned int loc;
       struct SymField *next;
};

typedef struct SymField* SymFieldPtr;

struct SymTab{

       SymFieldPtr head;
};

typedef struct SymTab SymTab;



//////////////////////////////////////////////////////// FUNCTIONS ///////////////////////////////////////////////////////////


//OpTab functions...

void displayOpTab(OpTab);
Keyword searchOpCode(OpTab, char *keyword);


//Line functions...

Line getLine(FILE *inputFile);
void displayLine(Line);
void writeLine(FILE *interFile, Line line);


//SymTab functions...

int searchLabel(SymTab, char *label);
SymTab insertLabel(SymTab, char *label, unsigned int loc);
void displaySymTab(SymTab);      



//General functions...

bool correctInput(int argc);
void ERROR(int errorCode, int line_num);

Keyword searchAssemblyDirective(char *keyword);

Keyword getKeywordType(OpTab, char *keyword);
unsigned int locCtrValue(char *operand, Keyword keywordType);

