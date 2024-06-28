#include "fichier.h"
#include "decl.h"
int Declstar(struct element_token_valeur ** element_token, struct Node * root){
    
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider =1;

    // si on a pas de type, fonction, procédure, ident ou begin alors on return -1
    if ((*element_token)->tokenCodageId != 6 && (*element_token)->tokenCodageId != 13 && (*element_token)->tokenCodageId != 3 && (*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 12){
        printf(GREEN"Erreur : il faut un type, une fonction, une procedure, un ident ou un begin \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;  
    }
    // Declstar -> epsilon si on a un begin
    else if ((*element_token)->tokenCodageId == 12){
        root->numChildren = 0;
        return valider;
    } 
    // Declstar -> DECL Declstar
    else {
        root->children[0] = createNode("DECL", root);
        
        valider = Decl(element_token,root->children[0]);
        if (valider == -1){
            return -1;
        }
        
        root->children[1] = createNode("DECLSTAR", root);
        root->numChildren = 2;
        return Declstar(element_token, root->children[1]);
        
    }
 
    return valider;

}