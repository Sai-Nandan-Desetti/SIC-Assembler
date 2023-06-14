#include"assembler.h"

//int LINE_NUM=0;

void main(int argc, char *argv[]){

          FILE *f_op,*inputFile,*interFile;  
  
          unsigned int startAddress;
          unsigned int locCtr;
          int programLength;

          struct Line	line;
          struct OpTab	opTab;
          struct SymTab	symTab;

//////////////////////////////////////////////////// INITIALIZATIONS /////////////////////////////////////////////////////////

// 1. Line number.
          LINE_NUM=0;

// 2. Starting address.
          startAddress=0;

// 3. opTab...

          f_op=fopen("SIC_instructions","r");
    
          int i=0;
          do{
               opTab.mnemonic[i]=calloc(5,sizeof(char));
               fscanf(f_op,"%s %x",opTab.mnemonic[i],&opTab.hexCode[i]);
               i++;

          }while(strcmp(opTab.mnemonic[i-1],"WD")!=EQUAL);

          fclose(f_op);

// 4. symTab head.
          symTab.head=NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////// OPENING THE FILES /////////////////////////////////////////////////////

// 1. Input file...

          if(!correctInput(argc))
             return;

          inputFile=fopen(argv[1],"r");

          if(inputFile==NULL){
 
             printf("\nThe input file does not exist!\n");
             return;
          }


// 2. Intermediate file...
         
          interFile=fopen(strcat(argv[1],".inter"),"w");
          fprintf(interFile,"Loc\tLabel\tOpcode\tOperand\n\n");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////// (PASS 1) ASSEMBLING THE CODE /////////////////////////////////////////////////
 
// 1.Reading the first line...

          line=getLine(inputFile);

          if(strcmp(line.keyword,"START")==EQUAL){

             sscanf(line.operand,"%x",&line.loc);
             if((int)line.loc<0)
                ERROR(0,LINE_NUM);

             writeLine(interFile,line);

             startAddress=locCtr=line.loc;

             line=getLine(inputFile);
          }

          else
              locCtr=0;


// 2.The main loop that scans through the input file...

          while(strcmp(line.keyword,"END")!=EQUAL){

                line.loc=locCtr;
 
                if(line.label!=NULL){
                   
                   if(searchLabel(symTab,line.label)==FOUND)
                      ERROR(2,LINE_NUM);

                   else
                       symTab=insertLabel(symTab,line.label,locCtr);
                }
                
                writeLine(interFile,line);

                locCtr+=locCtrValue(line.operand,getKeywordType(opTab,line.keyword));

                line=getLine(inputFile);

          }

          line.loc=0xFFFF;            
          writeLine(interFile,line);  //writing the last line


// 3. Set programLength.

          programLength=locCtr-startAddress;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////// DISPLAY OUTPUT ////////////////////////////////////////////////////////

// 1. SymTab...

          printf("SymTab details: \n");
          printf("\nLabel\tAddress\n") ;
          displaySymTab(symTab);

// 2. programLength.

          printf("\nProgram length: %d bytes\n",programLength);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//closing the files...

          fclose(inputFile);
          fclose(interFile);

}  //end of main()
