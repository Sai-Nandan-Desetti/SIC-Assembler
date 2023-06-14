#include"assembler.h"


Keyword searchAssemblyDirective(char *keyword){

    if(strcmp(keyword,"START")==EQUAL)
       return START;

    if(strcmp(keyword,"WORD")==EQUAL)
       return WORD;

    if(strcmp(keyword,"RESW")==EQUAL)
       return RESW;

    if(strcmp(keyword,"RESB")==EQUAL)
       return RESB;

    if(strcmp(keyword,"BYTE")==EQUAL)
       return BYTE;

    if(strcmp(keyword,"END")==EQUAL)
       return END;

    return NOT_ASSEMBLY_DIRECTIVE;
}


Keyword getKeywordType(OpTab opTab, char *keyword){

    Keyword type;

    type=searchOpCode(opTab,keyword);

    if(type==NOT_OPCODE){
       type=searchAssemblyDirective(keyword);
       if(type==NOT_ASSEMBLY_DIRECTIVE)
          return NOT_KEYWORD;
    }
  
    return type;
}
    
    
unsigned int locCtrValue(char *operand, Keyword keywordType){

    unsigned int op,locCtr=0;
    char *byte_string;

    switch(keywordType){

        case OPCODE: locCtr+=3; 
                     break; 

        case WORD:   locCtr+=3; 
                     break;

        case RESW:   sscanf(operand,"%x",&op);
                     if((int)op<0)
                       ERROR(0,LINE_NUM);
                     locCtr+=3*op;
                     break;

        case RESB:   sscanf(operand,"%x",&op);
                     if((int)op<0)
                       ERROR(0,LINE_NUM);
                     locCtr+=op;
                     break;

        case BYTE:   byte_string=calloc(strlen(operand),sizeof(char));
                     strcpy(byte_string,operand);
                     locCtr+=strlen(strtok(byte_string+1,"'"));
                     break;  
                  
        default:     ERROR(3,LINE_NUM);
    } 

    return locCtr;
}


bool correctInput(int argc){

     if(argc<2){

        printf("\nPlease input a .sic file\n");
        return false;
     }

     if(argc>2){

        printf("\nOne file as input please...\n");
        return false;
     }

     return true;
}
     
void ERROR(int errorCode, int line_no){

     switch(errorCode){
    
         case 0: printf("\nIncorrect operand value ");
                 break;

         case 1: printf("\nIncorrect instruction format ");
                 break;

         case 2: printf("\nDuplicate label ");
                 break;

         case 3: printf("\nInvalid operation ");
                 break;
     }

     printf("at line number: %d\n",line_no);

     exit(0);
}
