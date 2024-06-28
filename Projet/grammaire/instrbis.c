#include "fichier.h"
#include "expr.h"
#include "identpoint.h"
#include "exprplusvirgule.h"

int Instrbis(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(5 * sizeof(struct Node*));
    int valider = 1;
    // INSTRBIS -> ;
    if ((*element_token)->tokenCodageId == 5){
        root->numChildren = 0;
        root->children[0] = createNode(";", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // INSTRBIS -> ( EXPRPLUSVIRGULE ) ;
    else if ((*element_token)->tokenCodageId == 20){
        root->children[0] = createNode("(", root);
        (*element_token) = (*element_token)->next;
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
        // ;
        if ((*element_token)->tokenCodageId != 5){
            printf(GREEN"Erreur : il faut un ';' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[3] = createNode(";", root);
        root->numChildren = 4;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // INSTRBIS -> IDENTPOINT ':=' EXPR ';' 
    else if ((*element_token)->tokenCodageId == 11){
        root->children[0] = createNode(":=", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPR", root);
        valider = Expr(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }

        // ;
        if ((*element_token)->tokenCodageId != 5){
            printf(GREEN"Erreur : il faut un ';' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[2] = createNode(";", root);
        root->numChildren = 3;
        (*element_token) = (*element_token)->next;

        return valider;
    }
    else if ((*element_token)->tokenCodageId == 53){
        root->children[0] = createNode("IDENTPOINT", root);
        // appelle de la fonction Identpoint
        valider = Identpoint(element_token, root->children[0]);
        // :=
        if ((*element_token)->tokenCodageId != 11){
            printf(GREEN"Erreur : il faut un ':=' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode(":=", root);
        (*element_token) = (*element_token)->next;
        root->children[2] = createNode("EXPR", root);
        // EXPR
        valider = Expr(element_token, root->children[2]);
        if (valider == -1){
            return -1;
        }
        // ;
        if ((*element_token)->tokenCodageId != 5){
            printf(GREEN"Erreur : il faut un ';' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[3] = createNode(";", root);
        root->numChildren = 4;
            
            (*element_token) = (*element_token)->next;  
        
    }
    return valider;
}