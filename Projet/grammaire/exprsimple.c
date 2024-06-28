#include "fichier.h"
#include "expracces.h"
#include "expr.h"


int Exprsimple(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(7 * sizeof(struct Node*));
    int valider =1;
    // si on a pas un IDENT, (, character, ENTIER, CARACTERE, true, false, null, not, -
    if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 20 && (*element_token)->tokenCodageId != 47 && (*element_token)->tokenCodageId != 54 && (*element_token)->tokenCodageId != 56 && (*element_token)->tokenCodageId != 57 && (*element_token)->tokenCodageId != 61 && (*element_token)->tokenCodageId != 19 && (*element_token)->tokenCodageId != 22 && (*element_token)->tokenCodageId != 39){
            printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not ou un - \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
    }
    //EXPRSIMPLE -> ENTIER .
    if ((*element_token)->tokenCodageId == 54){
        (*element_token) = (*element_token)->next;
        root->children[0] = createNode((*element_token)->valeur[0], root);
        root->numChildren = 1;
        return 1;
    }
    //EXPRSIMPLE -> CARACTERE .
    if ((*element_token)->tokenCodageId == 56){
        (*element_token) = (*element_token)->next;
        root->children[0] = createNode((*element_token)->valeur[0], root);
        root->numChildren = 1;
        return 1;
    }
    //EXPRSIMPLE -> true .
    if ((*element_token)->tokenCodageId == 57){
        (*element_token) = (*element_token)->next;
        root->children[0] = createNode("true", root);
        root->numChildren = 1;
        return 1;
    }
    //EXPRSIMPLE -> false .
    if ((*element_token)->tokenCodageId == 61){
        (*element_token) = (*element_token)->next;
        root->children[0] = createNode("false", root);
        root->numChildren = 1;
        return 1;
    }
    //EXPRSIMPLE -> null .
    if ((*element_token)->tokenCodageId == 19){
        (*element_token) = (*element_token)->next;
        root->children[0] = createNode("null", root);
        root->numChildren = 1;
        return 1;
    }
    // EXPRSIMPLE -> ( EXPR ) 
    if ((*element_token)->tokenCodageId == 20){
        root->children[0] = createNode("(", root);
        (*element_token) = (*element_token)->next;
        // Appel de la fonction Expr
        root->children[1] = createNode("EXPR", root);
        valider = Expr(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }
        // )
        if ((*element_token)->tokenCodageId != 21){
            printf(GREEN"Erreur : il faut un ) \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[2] = createNode(")", root);
        root->numChildren = 3;
        return 1;
    }
    // EXPRSIMPLE -> not EXPRSIMPLE
    if ((*element_token)->tokenCodageId == 22){
        root->children[0] = createNode("not", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPRSIMPLE", root);
        // Appel de la fonction Exprsimple
        int valider = Exprsimple(element_token,root->children[1]);
        if (valider == -1){
            return -1;
        }
        root->numChildren = 2;
        return 1;
    }
    // EXPRSIMPLE -> - EXPRSIMPLE
    if ((*element_token)->tokenCodageId == 39){
        root->children[0] = createNode("-", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPRSIMPLE", root);
        // Appel de la fonction Exprsimple
        root->children[1] = createNode("EXPRSIMPLE", root);
        int valider = Exprsimple(element_token,root->children[1]);
        if (valider == -1){
            return -1;
        }
        root->numChildren = 2;
        return 1;
    }
    // EXPRSIMPLE -> IDENT EXPRACCES


    if ((*element_token)->tokenCodageId == 53){

        root->children[0] = createNode("ident", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPRACCES", root);
        // Appel de la fonction Expracces

        root->numChildren = 2;
        return Expracces(element_token,root->children[1]);
        
    }
    // EXPRSIMPLE -> character ‘ val ( EXPR )
    if ((*element_token)->tokenCodageId == 47){
        root->children[0] = createNode("character", root);
        (*element_token) = (*element_token)->next;
        // '
        if ((*element_token)->tokenCodageId != 58){
            printf(GREEN"Erreur : il faut un ' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode("'", root);
        (*element_token) = (*element_token)->next;
        // val
        if ((*element_token)->tokenCodageId != 62){
            printf(GREEN"Erreur : il faut un entier \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[2] = createNode((*element_token)->valeur[0], root);
        (*element_token) = (*element_token)->next;
        // (
        if ((*element_token)->tokenCodageId != 20){
            printf(GREEN"Erreur : il faut un ( \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[3] = createNode("(", root);
        (*element_token) = (*element_token)->next;
        root->children[4] = createNode("EXPR", root);
        // Appel de la fonction Expr
        valider = Expr(element_token, root->children[4]);
        // )
        if ((*element_token)->tokenCodageId != 21){
            printf(GREEN"Erreur : il faut un ) \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[5] = createNode(")", root);
        root->numChildren = 6;
        return 1;
    }
    root->numChildren = 0;
    return valider;
}