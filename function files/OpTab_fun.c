#include"assembler.h"

void displayOpTab(OpTab op){

     for(int i=0;i<NO_OF_INSTRUCTIONS;i++)
         printf("%s %x\n",op.mnemonic[i],op.hexCode[i]);
}



Keyword searchOpCode(OpTab opTab, char *keyword){

    int left=0,right=NO_OF_INSTRUCTIONS-1;
    int mid;
    int check;

    while(left<=right){
         
         mid=(left+right)/2;
 
         check=strcmp(opTab.mnemonic[mid],keyword);

         if(check==EQUAL)
            return OPCODE;

         else if(check<0)
             left=mid+1;

         else
             right=mid-1;
    }

    return NOT_OPCODE;
}


