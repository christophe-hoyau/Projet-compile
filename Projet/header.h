#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

// Les mots clés de notre langage concernant le fichier
extern const char* file_token[];
extern const int file_token_keep[];
extern const int file_token_index[];

extern const char* declaration_token[];
extern const int declaration_token_keep[];
extern const int declaration_token_index[];

extern const char* mode_token[];
extern const int mode_token_keep[];
extern const int mode_token_index[];

extern const char* expression_token[];
extern const int expression_token_keep[];
extern const int expression_token_index[];

extern const char* instruction_token[];
extern const int instruction_token_keep[];
extern const int instruction_token_index[];

extern const char* operator_token[];
extern const int operator_token_keep[];
extern const int operator_token_index[];

extern const char* type_token[];
extern const int type_token_keep[];
extern const int type_token_index[];

extern const char* identifier_token[];
extern const int identifier_token_keep[];
extern const int identifier_token_index[];

extern const char* literal_token[];
extern const int literal_token_keep[];
extern const int literal_token_index[];


// Énumération pour les tokens
typedef enum {
    // Mots-clés pour le fichier
    WITH_FILE_TOKEN, USE_FILE_TOKEN, PROCEDURE_FILE_TOKEN, IS_FILE_TOKEN, SEMICOLON_FILE_TOKEN, PUT_FILE_TOKEN,
    // Déclarations
    TYPE_DECLARATION_TOKEN, ACCESS_DECLARATION_TOKEN, RECORD_DECLARATION_TOKEN, END_DECLARATION_TOKEN, COLON_DECLARATION_TOKEN, ASSIGNMENT_DECLARATION_TOKEN, BEGIN_DECLARATION_TOKEN, FUNCTION_DECLARATION_TOKEN, RETURN_DECLARATION_TOKEN,
    // Modes
    IN_MODE_TOKEN, OUT_MODE_TOKEN,
    // Expressions
    TRUE_EXPRESSION_TOKEN, FALSE_EXPRESSION_TOKEN, NULL_EXPRESSION_TOKEN, LEFT_PAREN_EXPRESSION_TOKEN, RIGHT_PAREN_EXPRESSION_TOKEN, NOT_EXPRESSION_TOKEN, NEW_EXPRESSION_TOKEN,QUOTE_EXPRESSION_TOKEN,
    // Instructions
    IF_INSTRUCTION_TOKEN, THEN_INSTRUCTION_TOKEN, ELSIF_INSTRUCTION_TOKEN, ELSE_INSTRUCTION_TOKEN, FOR_INSTRUCTION_TOKEN, REVERSE_INSTRUCTION_TOKEN, LOOP_INSTRUCTION_TOKEN, WHILE_INSTRUCTION_TOKEN,
    // Opérateurs
    EQUAL_OPERATOR_TOKEN, NOT_EQUAL_OPERATOR_TOKEN, LESS_THAN_OPERATOR_TOKEN, LESS_EQUAL_OPERATOR_TOKEN, GREATER_THAN_OPERATOR_TOKEN, GREATER_EQUAL_OPERATOR_TOKEN, PLUS_OPERATOR_TOKEN, MINUS_OPERATOR_TOKEN, MULTIPLY_OPERATOR_TOKEN, DIVIDE_OPERATOR_TOKEN, REM_OPERATOR_TOKEN, AND_OPERATOR_TOKEN, THEN_OPERATOR_TOKEN, OR_OPERATOR_TOKEN, DOT_OPERATOR_TOKEN,
    // Types
    CHARACTER_TYPE_TOKEN, BOOLEAN_TYPE_TOKEN, INTEGER_TYPE_TOKEN, FLOAT_TYPE_TOKEN, ACCESS_TYPE_TOKEN,
    // Identificateurs
    IDENTIFIER_TOKEN,
    // Valeurs littérales
    INTEGER_LITERAL_TOKEN, FLOAT_LITERAL_TOKEN, CHAR_LITERAL_TOKEN, BOOLEAN_LITERAL_TOKEN,
    // Fin de fichier
    EOF_TOKEN,
    // Erreur
    ERROR_TOKEN
} ada_token_type;



#endif // HEADER_H
