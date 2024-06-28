#include "analyseur_lexical.h"
#include "grammaire/fichier.h"





// ouvrir le fichier ada_test.txt
FILE* fichier = NULL;
// creer le fichier vide ada_sans_commentaires.txt
FILE* fichier_sortie = NULL;
// creer le fichier vide ada_sans_commentaires.txt pour lire
FILE* fichier_sortie_lecture = NULL;



int main(){
    char * mot = "33";
    int a;
    int index= index_token_word(mot);
    char * motss = "with";
    int index2= index_token_word(motss);
    printf("33 : %d\n", index);
    printf("with : %d\n", index2);
    a=estUnFloat(mot);
    printf("%d\n", a);

    fichier = fopen("ada_test.txt", "r+");
    // ouvrir le fichier ada_sans_commentaires.txt
    fichier_sortie = fopen("ada_sans_commentaires.txt", "w+");

    supprimer_commentaires(fichier, fichier_sortie);
    // fermer le fichier ada_test.txt
    fclose(fichier);
    // fermer le fichier ada_sans_commentaires.txt
    fclose(fichier_sortie);
    fichier_sortie_lecture = fopen("ada_sans_commentaires.txt", "r+");


    struct linked_list_token_valeur * list_token = malloc(sizeof(struct linked_list_token_valeur));
    struct element_token_valeur * element_token = malloc(sizeof(struct element_token_valeur));

   

    // initialiser la liste vide
    element_token->tokenCodageId = 0;
    for (int i = 0; i < 1000; i++){
        element_token->valeur[i] = NULL;
    }
    element_token->line = 0;
    element_token->column = 0;
    element_token->next = NULL;
    list_token->head = element_token;
    // test la fonction litMotFichier
    litMotFichier(fichier_sortie_lecture, list_token);
    afficher_liste_tokens(list_token);

    struct Node* root = createNode("FICHIER", NULL);
    
    int valider = Fichier (list_token, root);
    if (valider == -1 ){
        printf("le fichier n'est pas valide\n");
    }

 
    
    // fermer le fichier ada_sans_commentaires.txt

    fclose(fichier_sortie_lecture);

    // Créer une surface Cairo
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 30000, 8000);
    cairo_t* cr = cairo_create(surface);

    // Configurer la police
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 20.0);

    // Dessiner l'arbre abstrait
    drawTree(root, cr, 400, 200, 1000);

    // Sauvegarder l'image dans un fichier PNG
    cairo_surface_write_to_png(surface, "tree.png");

    // Libérer la mémoire allouée pour l'arbre abstrait et la surface Cairo
   
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    return valider;
    
}

