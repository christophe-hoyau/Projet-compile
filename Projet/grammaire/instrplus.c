#include "fichier.h"
#include "instr.h"

int Instrplus(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider=1;
    // si on a pas 	IDENT, begin, return, if, for, while, put alors on return -1
    if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 12 && (*element_token)->tokenCodageId != 14 && (*element_token)->tokenCodageId != 24 && (*element_token)->tokenCodageId != 28 && (*element_token)->tokenCodageId != 31 && (*element_token)->tokenCodageId != 52){
        printf(GREEN"Erreur : il faut un ident, un begin, un return, un if, un for ou un while \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
         printf("token : %d\n", (*element_token)->tokenCodageId);
        return -1;  
    }
    // INSTRPLUS -> INSTR INSTRPLUS .
    // Appel de la fonction Instr
    root->children[0] = createNode("INSTR", root);
    valider = Instr(element_token, root->children[0]);
    if (valider == -1){
        return -1;
    }
    root->children[1] = createNode("INSTRPLUS", root);
    // si on a IDENT ou begin ou  return ou if ou for ou while  on appelle Instrplus
    if ((*element_token)->tokenCodageId == 53 || (*element_token)->tokenCodageId == 12 || (*element_token)->tokenCodageId == 14 || (*element_token)->tokenCodageId == 24 || (*element_token)->tokenCodageId == 28 || (*element_token)->tokenCodageId == 31 || (*element_token)->tokenCodageId == 52){
        return Instrplus(element_token, root->children[1]);
        
    }
    root->numChildren = 2;
    
    

    

    return valider;
}