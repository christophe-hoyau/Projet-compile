#include "fichier.h"
#include "expr.h"

int Exprplusvirgule(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider =1;
    int a=0; // a est pair si on appelle expr et impair si on a , 
    int b=0; 
    // tant qu'on a IDENT, (, character, ENTIER, CARACTERE, true, false, null, not, - , ',' on appelle et si on a ) on s'arrete 
    while ((*element_token)->tokenCodageId == 53 || (*element_token)->tokenCodageId == 20 || (*element_token)->tokenCodageId == 47 || (*element_token)->tokenCodageId == 54 || (*element_token)->tokenCodageId == 56 || (*element_token)->tokenCodageId == 57 || (*element_token)->tokenCodageId == 61 || (*element_token)->tokenCodageId == 19 || (*element_token)->tokenCodageId == 22 || (*element_token)->tokenCodageId == 39 || (*element_token)->tokenCodageId == 59  ){
        // Appel de la fonction Expr si on a pas ',' 
        if ((*element_token)->tokenCodageId != 59 && a%2 == 0){
            a++;
            root->children[b] = createNode("EXPR", root);
            b++;
            valider = Expr(element_token, root->children[b-1]);
            if (valider == -1){
                return -1;
            }
        }
        else if ((*element_token)->tokenCodageId == 59 && a%2 == 1){
            a++;
            root->children[b] = createNode(",", root);
            b++;
            (*element_token) = (*element_token)->next;
        }
        else {
            printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not, un - ou un , \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
    }
    if (a%2 ==0){
        printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not, un - ou un , \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    // si on a pas de ) on return -1
    if ((*element_token)->tokenCodageId != 21){
        printf(GREEN"Erreur : il faut un ) \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->numChildren = b;
    return valider;
}
