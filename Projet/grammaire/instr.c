#include "fichier.h"
#include "expr.h"
#include "instrbis.h"
#include "instrplus.h"
#include "boucle1.h"
#include "boucle2.h"
#include "exprinterro.h"

int Instr(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    
    int valider =1;

    // si on a pas IDENT, begin, return, if, for, while, put alors on return -1
    if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 12 && (*element_token)->tokenCodageId != 14 && (*element_token)->tokenCodageId != 24 && (*element_token)->tokenCodageId != 28 && (*element_token)->tokenCodageId != 31 && (*element_token)->tokenCodageId != 52){
        printf(GREEN"Erreur : il faut un ident, un begin, un return, un if, un for ou un while \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
       root->numChildren = 0;
        return -1;  
    }
    // Instr -> begin INSTRPLUS end ;
    if ((*element_token)->tokenCodageId == 12){
        root->children[0] = createNode("begin", root);
        (*element_token) = (*element_token)->next;
        // Appel de la fonction Instrplus
        root->children[1] = createNode("INSTRPLUS", root);
        valider = Instrplus(element_token, root->children[1]);  
        if (valider==-1){
            return -1;
        }
        
        //end 
        if ((*element_token)->tokenCodageId != 9){
            printf(GREEN"Erreur : il faut le mot end \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[2] = createNode("end", root);
        (*element_token) = (*element_token)->next;
        // ;
        
        if ((*element_token)->tokenCodageId != 5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[3] = createNode(";", root);
        root->numChildren = 4;
        (*element_token) = (*element_token)->next;
        return 1;
    }
        
    // INSTR -> for IDENT in REVERSE? EXPR '..' EXPR
    if ((*element_token)->tokenCodageId == 28){
        root->children[0] = createNode("for", root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId != 53){
            printf(GREEN"Erreur : il faut un ident \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode((*element_token)->valeur[0], root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId != 15){
            printf(GREEN"Erreur : il faut le mot in \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[2] = createNode("in", root);
        (*element_token) = (*element_token)->next;
        // cas reverse
        if ((*element_token)->tokenCodageId == 29){
            root->children[3] = createNode("reverse", root);
            (*element_token) = (*element_token)->next;
            // si on a pas un IDENT, (, character, ENTIER, CARACTERE, true, false, null, not, -
            if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 20 && (*element_token)->tokenCodageId != 47 && (*element_token)->tokenCodageId != 54 && (*element_token)->tokenCodageId != 56 && (*element_token)->tokenCodageId != 57 && (*element_token)->tokenCodageId != 61 && (*element_token)->tokenCodageId != 19 && (*element_token)->tokenCodageId != 22 && (*element_token)->tokenCodageId != 39){
                printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not ou un - \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            root->children[4] = createNode("EXPR", root);
            valider = Expr(element_token, root->children[4]);
            if (valider==-1){
                return -1;
            }
            // ..
            if ((*element_token)->tokenCodageId != 46 && (*element_token)->next->tokenCodageId != 46){
                printf(GREEN"Erreur : il faut le mot . \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            root->children[5] = createNode("..", root);
            (*element_token) = (*element_token)->next->next;
            // si on a pas un IDENT, (, character, ENTIER, CARACTERE, true, false, null, not, -
            if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 20 && (*element_token)->tokenCodageId != 47 && (*element_token)->tokenCodageId != 54 && (*element_token)->tokenCodageId != 56 && (*element_token)->tokenCodageId != 57 && (*element_token)->tokenCodageId != 61 && (*element_token)->tokenCodageId != 19 && (*element_token)->tokenCodageId != 22 && (*element_token)->tokenCodageId != 39){
                printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not ou un - \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            root->children[6] = createNode("EXPR", root);
            valider = Expr(element_token, root->children[6]);
            if (valider==-1){
                return -1;
            }
            root->numChildren = 7;
            return 1;
            
        }
        else {
            //EXPR .. EXPR
            // si on a pas un IDENT, (, character, ENTIER, CARACTERE, true, false, null, not, -
            if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 20 && (*element_token)->tokenCodageId != 47 && (*element_token)->tokenCodageId != 54 && (*element_token)->tokenCodageId != 56 && (*element_token)->tokenCodageId != 57 && (*element_token)->tokenCodageId != 61 && (*element_token)->tokenCodageId != 19 && (*element_token)->tokenCodageId != 22 && (*element_token)->tokenCodageId != 39){
                printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not ou un - \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            root->children[3] = createNode("EXPR", root);
            valider = Expr(element_token, root->children[3]);
            if (valider==-1){
                return -1;
            }
            // ..
            if ((*element_token)->tokenCodageId != 46 && (*element_token)->next->tokenCodageId != 46){
                printf(GREEN"Erreur : il faut le mot . \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            root->children[4] = createNode("..", root);
            (*element_token) = (*element_token)->next->next;
            // si on a pas un IDENT, (, character, ENTIER, CARACTERE, true, false, null, not, -
            if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 20 && (*element_token)->tokenCodageId != 47 && (*element_token)->tokenCodageId != 54 && (*element_token)->tokenCodageId != 56 && (*element_token)->tokenCodageId != 57 && (*element_token)->tokenCodageId != 61 && (*element_token)->tokenCodageId != 19 && (*element_token)->tokenCodageId != 22 && (*element_token)->tokenCodageId != 39){
                printf(GREEN"Erreur : il faut un ident, un (, un character, un entier, un caractere, un true, un false, un null, un not ou un - \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            root->children[5] = createNode("EXPR", root);
            valider = Expr(element_token, root->children[5]);
            if (valider==-1){
                return -1;
            }
            root->numChildren = 6;
            return 1;
        }
    }
    // INSTR -> return EXPRINTERRO ';'
    if ((*element_token)->tokenCodageId == 14){

        root->children[0] = createNode("return", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPRINTERRO", root);
        root->numChildren = 2;
       
        valider = Exprinterro(element_token, root->children[1]);
        if (valider==-1){
            return -1;
        }
         printf("Sortie : %s\n", (*element_token)->valeur[0]);
    printf("Sortie : %d\n", (*element_token)->tokenCodageId);
        // ;

        if ((*element_token)->tokenCodageId != 5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        
        root->children[2] = createNode(";", root);
        root->numChildren = 3;
        (*element_token) = (*element_token)->next;
    }
    // INSTR -> while EXPR loop INSTRPLUS end loop ';'
    if ((*element_token)->tokenCodageId==31){
        root->children[0] = createNode("while", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPR", root);
        // Appel de la fonction Expr
        valider = Expr(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }
        root->children[2] = createNode("loop", root);
        // loop
        if ((*element_token)->tokenCodageId != 30){
            printf(GREEN"Erreur : il faut le mot loop \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        (*element_token) = (*element_token)->next;
        root->children[3] = createNode("INSTRPLUS", root);
        // Appel de la fonction Instrplus
        valider = Instrplus(element_token, root->children[3]);
        if (valider == -1){
            return -1;
        }
        root->children[4] = createNode("end", root);
        // end
        if ((*element_token)->tokenCodageId != 9){
            printf(GREEN"Erreur : il faut le mot end \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        (*element_token) = (*element_token)->next;
        // loop
        if ((*element_token)->tokenCodageId != 30){
            printf(GREEN"Erreur : il faut le mot loop \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[5] = createNode("loop", root);
        (*element_token) = (*element_token)->next;
        // ;
        if ((*element_token)->tokenCodageId != 5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[6] = createNode(";", root);
        root->numChildren = 7;
        (*element_token) = (*element_token)->next;
        
    }

    // INSTR -> IDENT INSTRBIS
     

    if ((*element_token)->tokenCodageId == 53){
        root->children[0] = createNode("ident", root);
        (*element_token) = (*element_token)->next;
        // Appel de la fonction Instrbis
        root->children[1] = createNode("INSTRBIS", root);
        valider = Instrbis(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }               
        root->numChildren = 2;

        return 1;
    }
    // EXPR -> if EXPR then INSTRPLUS BOUCLE1 BOUCLE2 end if ;
    if ((*element_token)->tokenCodageId == 24){
        root->children[0] = createNode("if", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("EXPR", root);
        // Appel de la fonction Expr
        valider = Expr(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }
        // then
        root->children[2] = createNode("then", root);
        if ((*element_token)->tokenCodageId != 25){
            printf(GREEN"Erreur : il faut le mot then \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }  
        (*element_token) = (*element_token)->next;
        // Appel de la fonction Instrplus
        root->children[3] = createNode("INSTRPLUS", root);
        valider = Instrplus(element_token, root->children[3]);
        if (valider == -1){
            return -1;
        }
        // on regarde si y'a un elsif ou un else
        if ((*element_token)->tokenCodageId==27){
            root->children[4] = createNode("BOUCLE1", root);
            // on appelle la fonction Boucle1
            valider = Boucle1(element_token, root->children[4]);
            if (valider == -1){
                return -1;
            }
            root->children[5] = createNode("BOUCLE2", root);
            // on appelle la fonction Boucle2
            valider = Boucle2(element_token, root->children[5]);
            if (valider == -1){
                return -1;
            }
            //end 
            root->children[6] = createNode("end", root);
            if ((*element_token)->tokenCodageId != 9){
                printf(GREEN"Erreur : il faut le mot end \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            (*element_token) = (*element_token)->next;
            root->children[7] = createNode("if", root);
            // if
            if ((*element_token)->tokenCodageId != 24){
                printf(GREEN"Erreur : il faut le mot if \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            (*element_token) = (*element_token)->next;
            // ;
            root->children[8] = createNode(";", root);
            if ((*element_token)->tokenCodageId != 5){
                printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
            (*element_token) = (*element_token)->next;
            root -> numChildren = 9;
        }}
        
    // INSTR -> put '(' ident ou char ou bool ou integer ')' ';'
    if ((* element_token)->tokenCodageId==52){
        root->children[0] = createNode("put", root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId != 20 ){
            printf(GREEN"Erreur : il faut un ( \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;  
        }
        root->children[1] = createNode("(", root);
        (*element_token) = (*element_token)->next;

        if ((*element_token)->tokenCodageId!=53 && (*element_token)->tokenCodageId!=58 && (*element_token)->tokenCodageId!=57 && (*element_token)->tokenCodageId!=61 && (*element_token)->tokenCodageId!=54){
            printf(GREEN"Erreur : il faut un ident, un character, un true ou un false \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;  
        }
        if ((*element_token)->tokenCodageId==58){
            root->children[2] = createNode((*element_token)->valeur[0], root);
            (*element_token) = (*element_token)->next;
            if ((*element_token)->tokenCodageId!=56){
                printf(GREEN"Erreur : il faut un char \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;  
            }
            root->children[3] = createNode((*element_token)->valeur[0], root);
            (*element_token) = (*element_token)->next;
            if ((*element_token)->tokenCodageId!=58){
                printf(GREEN"Erreur : il faut un ' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;  
            }
            root->children[4] = createNode((*element_token)->valeur[0], root);
            (*element_token) = (*element_token)->next;
            // si on a pas un )
            if ((*element_token)->tokenCodageId!=21){
                printf(GREEN"Erreur : il faut un ) \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;  
            
                }
                root->children[5] = createNode(")", root);
                (*element_token) = (*element_token)->next;
                if ((*element_token)->tokenCodageId!=5){
                    printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                    return -1;  
                }
                root->children[6] = createNode(";", root);
                root->numChildren = 7;
                (*element_token) = (*element_token)->next;
                return 1;
            
            }
        else {
            root->children[2] = createNode((*element_token)->valeur[0], root);
            (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId!=21){
            printf(GREEN"Erreur : il faut un ) \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;  
        }
        root->children[3] = createNode(")", root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId!=5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;  
        }
        root->children[4] = createNode(";", root);
        root->numChildren = 5;
        (*element_token) = (*element_token)->next;
        return 1;
    }
    }


   

    return valider;
}