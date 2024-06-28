#include "fichier.h"
#include "paramsinterro.h"
#include "declstar.h"
#include "instrplus.h"
#include "declbis.h"
#include "type.h"
#include "suite.h"
#include "identinterro.h"

int Decl(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(40 * sizeof(struct Node*));
    int valider = 1;
    // si on a pas de type, fonction, procédure, ident ou begin alors on return -1
    if ((*element_token)->tokenCodageId != 6 && (*element_token)->tokenCodageId != 13 && (*element_token)->tokenCodageId != 3 && (*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 12){
        printf(GREEN"Erreur : il faut un type, une fonction, une procedure, un ident ou un begin \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;  
    }
    // DECL → procedure IDENT PARAMSINTERRO is DECLSTAR begin INSTRPLUS end IDENTINTERRO ;
    if ((*element_token)->tokenCodageId==3){

        root->children[0] = createNode("procedure", root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId!=53){
            printf(GREEN"Erreur : le nom de la procedure n'est pas le bon \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }

        root->children[1] = createNode((*element_token)->valeur[0], root);
        (*element_token) = (*element_token)->next;

        root->children[2] = createNode("PARAMSINTERRO", root);
        valider = Paramsinterro(element_token,root->children[2]);
        if (valider==-1){
            return -1;
        }
        if ((*element_token)->tokenCodageId!=4){
            printf(GREEN"Erreur : il faut le mot is \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[3] = createNode("is", root);
        (*element_token) = (*element_token)->next;
        root->children[4] = createNode("DECLSTAR", root);
        valider = Declstar(element_token,root->children[4]);
        if (valider==-1){
            return -1;
        }
        // begin
        if ((*element_token)->tokenCodageId!=12){
            printf(GREEN"Erreur : il faut le mot begin \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[5] = createNode("begin", root);
        (*element_token) = (*element_token)->next;
        root->children[6] = createNode("INSTRPLUS", root);
        valider = Instrplus(element_token,root->children[6]);
        if (valider==-1){
            return -1;
        }
       
        // end
        if ((*element_token)->tokenCodageId!=9){
            printf(GREEN"Erreur : il faut le mot end \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[7] = createNode("end", root);
        (*element_token) = (*element_token)->next;
        // identerro

        root->children[8] = createNode("IDENTINTERRO", root);
        valider = Identinterro(element_token,root->children[8]);
        if (valider==-1){
            return -1;
        }
        // ;
        if ((*element_token)->tokenCodageId!=5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        
       
       
        (*element_token) = (*element_token)->next;
    }
    // DECL -> function IDENT PARAMSINTERRO return TYPE is DECLSTAR begin INSTRPLUS end IDENTINTERRO ';'
    if ((*element_token)->tokenCodageId==13){
        root->children[0] = createNode("function", root);
        (*element_token) = (*element_token)->next;
        // ident
        if ((*element_token)->tokenCodageId!=53){
            printf(GREEN"Erreur : le nom de la fonction n'est pas le bon \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode((*element_token)->valeur[0], root);
        (*element_token) = (*element_token)->next;
        root->children[2] = createNode("PARAMSINTERRO", root);
        valider = Paramsinterro(element_token,root->children[2]);
        if (valider==-1){
            return -1;
        }

        if ((*element_token)->tokenCodageId!=14){
            printf(GREEN"Erreur : il faut le mot return \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[3] = createNode("return", root);
        (*element_token) = (*element_token)->next;
        root->children[4] = createNode("TYPE", root);
        valider = Type(element_token,root->children[4]);
        if (valider==-1){
            return -1;
        }

        if ((*element_token)->tokenCodageId!=4){
            printf(GREEN"Erreur : il faut le mot is \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[5] = createNode("is", root);
        (*element_token) = (*element_token)->next;
        root->children[6] = createNode("DECLSTAR", root);
        valider = Declstar(element_token,root->children[6]);
        if (valider==-1){
            return -1;
        }
        // begin
        if ((*element_token)->tokenCodageId!=12){
            printf(GREEN"Erreur : il faut le mot begin \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[7] = createNode("begin", root);
        (*element_token) = (*element_token)->next;
        root->children[8] = createNode("INSTRPLUS", root);

        valider = Instrplus(element_token,root->children[8]);
        if (valider==-1){
            return -1;
        }



        // end
        if ((*element_token)->tokenCodageId!=9){
            printf(GREEN"Erreur : il faut le mot end \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[9] = createNode("end", root);
        (*element_token) = (*element_token)->next;
        // identerro
        root->children[10] = createNode("IDENTINTERRO", root);
        root->numChildren = 11;
        valider = Identinterro(element_token,root->children[10]);
        if (valider==-1){
            return -1;
        }
        // ;
        if ((*element_token)->tokenCodageId!=5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }

        (*element_token) = (*element_token)->next;

        return valider;
    }
    // DECL -> type IDENT DECLBIS
    if ((*element_token)->tokenCodageId==6){
        root->children[0] = createNode("type", root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId!=53){
            printf(GREEN"Erreur : le nom du type n'est pas le bon \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode((*element_token)->valeur[0], root);
        (*element_token) = (*element_token)->next;
        root->children[2] = createNode("DECLBIS", root);
        valider = Declbis(element_token,root->children[2]);
        if (valider==-1){
            return -1;
        }
    }
    // DECL -> IDENTPLUSVIRGULE : TYPE SUITE ;
    if ((*element_token)->tokenCodageId==53){
        root->children[0] = createNode("IDENTPLUSVIRGULE", root);
        (*element_token) = (*element_token)->next;
        // tant qu'on  , ou ident
        int a=0; // vaut 0 si on a un ident, 1 si on a un ,
        int b=0;
        while((*element_token)->tokenCodageId==59 || (*element_token)->tokenCodageId==53){
            if ((*element_token)->tokenCodageId!=59&& a%2==0){
                a++;
                root->children[b] = createNode((*element_token)->valeur[0], root);
                b++;
                (*element_token) = (*element_token)->next;
            }
            else if ((*element_token)->tokenCodageId!=53 && a%2==1){
                a++;
                root->children[b] = createNode(",", root);
                b++;
                (*element_token) = (*element_token)->next;
            }
            else {
                printf(GREEN"Erreur : il faut un ident ou un , \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
                return -1;
            }
        }
            
        if ((*element_token)->tokenCodageId!=10){
            printf(GREEN"Erreur : il faut le mot : \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;  
        }
        root->children[b] = createNode(":", root);
        (*element_token) = (*element_token)->next;
        root->children[b+1] = createNode("TYPE", root);
        valider = Type(element_token,root->children[b+1]);
        if (valider==-1){
            return -1;
        }
        root->children[b+2] = createNode("SUITE", root);
        valider = Suite(element_token,root->children[b+2]);
        if (valider==-1){
            return -1;
        }
        if ((*element_token)->tokenCodageId!=5){
            printf(GREEN"Erreur : il faut un ; \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;  
        }
        root->children[b+3] = createNode(";", root);
        root->numChildren = b+4;
        (*element_token) = (*element_token)->next;
    }

    return valider;
}