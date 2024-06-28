#include "fichier.h"
#include "identpoint.h"
#include "exprplusvirgule.h"


int Expracces(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(3* sizeof(struct Node*));
    int valider =1;
    // EXPRACCES -> '(' EXPRPLUSVIRGULE ')' 
    if ((*element_token)->tokenCodageId == 20){
        root->children[0] = createNode("(", root);
    (*element_token) = (*element_token)->next;
    // Appel de la fonction Exprplusvirgule
    root->children[1] = createNode("EXPRPLUSVIRGULE", root);
    valider = Exprplusvirgule(element_token, root->children[1]);
    if (valider == -1){
        return -1;
    }

    // )
    if ((*element_token)->tokenCodageId != 21){
        printf(GREEN"Erreur : il faut un ')' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->children[2] = createNode(")", root);
     (*element_token) = (*element_token)->next;
        root->numChildren = 3;
     return valider;
     }
   
    //EXPRACCES -> . IDENT IDENTPOINT 
    if ((*element_token)->tokenCodageId == 46){
        root->children[0] = createNode(".", root);
        (*element_token) = (*element_token)->next;
        // IDENT
        if ((*element_token)->tokenCodageId != 53){
            printf(GREEN"Erreur : il faut un ident \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode("ident", root);
        (*element_token) = (*element_token)->next;
        // Appel de la fonction Identpoint
        root->children[2] = createNode("IDENTPOINT", root);
        valider = Identpoint(element_token, root->children[2]);
        if (valider == -1){
            return -1;
        }
        root->numChildren = 3;
        return valider;
    }
    root->numChildren = 0;

    return valider;
}