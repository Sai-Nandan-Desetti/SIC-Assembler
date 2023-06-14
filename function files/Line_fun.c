#include"assembler.h"


Line getLine(FILE *fin){

     struct Line line;

     char *l=calloc(80,sizeof(char));
     char l1[80];
     char *token,*words[3];
      
     int i;

     //loop to pass over commented or empty lines...
     do{
         l=fgets(l,80,fin);

         LINE_NUM++;                //global variable.

         strcpy(l1,l);
         token=strtok(l1," \t");

     }while(*token=='.'||l1[0]=='\n');
     
     
     for(i=0;i<3;i++)
         words[i]=calloc(10,sizeof(char));
    
     //parsing the line into its components: label, keyword and operand...
     for(i=0,token=strtok(l,"\t\n");token!=NULL;i++){
          words[i]=strcpy(words[i],token);
          token=strtok(NULL,"\t\n");
     }


     //assigning the appropriate values to label, keyword and operand
     switch(i){

         case 1: line.label=NULL;
                 line.keyword=words[0];
                 line.operand=NULL;
                 break;

         case 2: line.label=NULL;
                 line.keyword=words[0];
                 line.operand=words[1];
                 break;

         case 3: line.label=words[0];
                 line.keyword=words[1];
                 line.operand=words[2];
                 break;

         default: ERROR(1,LINE_NUM);
     }
   
     return line;
}



void displayLine(Line line){

     printf("%s %s %s\n",line.label,line.keyword,line.operand);
}



void writeLine(FILE *fp, Line line){

     if(line.loc==0xFFFF)
        fprintf(fp,"\t");
     else
        fprintf(fp,"%x\t",line.loc);

     if(line.label!=NULL)
        fprintf(fp,"%s\t",line.label);
     else
        fprintf(fp,"\t");
    
     fprintf(fp,"%s\t",line.keyword);
 
     if(line.operand!=NULL)
        fprintf(fp,"%s\n",line.operand);
     else
        fprintf(fp,"\t\n");
}


