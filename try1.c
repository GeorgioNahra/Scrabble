#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGER 15
#define COLONNE 15


typedef struct {
   char letter;
   int multiplier;
} BoardCell;


typedef struct {
   BoardCell cells[RANGER][COLONNE];
} GameBoard;

typedef struct Joueur{
    char nom;
    int num;
    char chevalet;
    int score;
}jou;

void initializeGameBoard(GameBoard *board)
{
   for (int i = 0; i < RANGER; ++i) {
       for (int j = 0; j < COLONNE; ++j) {
           board->cells[i][j].letter = ' ';
           board->cells[i][j].multiplier = 1;
       }
   }
}

void displayGameBoard(GameBoard *board)
{
   // Afficher les indices de colonnes (lettres A à O)
   printf("    ");
   for (char col = 'A'; col < 'A' + COLONNE; ++col) {
       printf(" %c ", col);
   }
   printf("\n");
   // Afficher le plateau de jeu avec les indices de lignes (1 à 15)
   for (int i = 0; i < RANGER; ++i) {
       printf("%2d |", i + 1);
       for (int j = 0; j < COLONNE; ++j) {
           printf("[%c]", board->cells[i][j].letter);
       }
       printf("\n");
   }
}

void commencer()
{
    struct Joueur jou;
    int nombreDeJoueur = 0;
    int rangeNum = 7;

    printf("Combien de joueur: ");
    scanf("%d", &nombreDeJoueur);
    if (nombreDeJoueur > 4 || nombreDeJoueur < 1) {
        printf("Le nombre de joueur est invalide, entrez un nouveux nombre: ");
        scanf("%d", &nombreDeJoueur);
    while (nombreDeJoueur > 4 || nombreDeJoueur < 1);}
        for (int i = 0; i < nombreDeJoueur; i++) {
            printf("Entrez le nom de Joueur: ");
            scanf(" %s", &jou.nom);
            jou.num = rand()%rangeNum;
            printf("Le nombre de joueur random c %d\n", jou.num);
        }
}

int main() {
   GameBoard board;
    time_t t;
    srand((unsigned)time(&t));


    commencer();
   initializeGameBoard(&board);
   displayGameBoard(&board);


   return 0;
}
