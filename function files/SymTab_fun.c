#include"assembler.h"


int searchLabel(SymTab symTab, char *label){

    SymFieldPtr temp=symTab.head;
 
    while(temp!=NULL){

         if(strcmp(temp->label,label)==EQUAL)
            return FOUND;
         
         temp=temp->next;
    }
 
    return NOT_FOUND;
}


SymTab insertLabel(SymTab symTab, char *label, unsigned int loc){

     SymFieldPtr field = (SymFieldPtr)calloc(1,sizeof(struct SymField));

     field->label=calloc(strlen(label),sizeof(char));
     field->label=strcpy(field->label,label);
     field->loc=loc;
     field->next=NULL;

     if(symTab.head==NULL)
        symTab.head=field;

     else{
           SymFieldPtr temp=symTab.head;

           while(temp->next!=NULL)
                 temp=temp->next;

           temp->next=field;
     }

     return symTab;
}


void displaySymTab(SymTab symTab){

     SymFieldPtr temp=symTab.head;

     while(temp!=NULL){

          printf("%s\t%x\n",temp->label,temp->loc);
          temp=temp->next;
     }
}

