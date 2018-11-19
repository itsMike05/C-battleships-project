#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*	TO-DO 
	1. Show the board with zeroes as an empty places, show the mishits as '0'		---- DONE
	2. Prevent user from taking over-the-board shots								---- DONE
	3. After two same-spot shots, don't substract attempts number					---- DONE
	
*/
int n, m, x, y;
int **tab;

int random_a(int a)									// Drawing row position
{
	 return (rand()%(a));							// Returning random generated int from 0 to a
} 
int random_b(int b)									// Drawing column position
 {				
	 return (rand()%(b));							// Returning random generated int from 0 to b
 }

void print_x(int x, int y,int n, int m)				// Function for printing '0' where mishit occured
{
	tab[x][y] = 5;									// Assigning '5' to a mishit position
	for (int i = 0; i < n; i++) {					// Printing the 'modified' board
		for (int j = 0; j < m; j++) {
			printf("%d\t", tab[i][j]);
		}
		printf("\n");
	}
}

void play(int n, int m)
 {
	 
	 int game_over;									// Variable responsible for ending the game
	 int max_attempts = 5;							// Maximum number of attempts
	 int attempts = 0;								// Variable that holds the attempt count 
	 int a = random_a(n);
	 int b = random_b(m);
	 printf("\nGuess the position of one-masted ship : \n");
	 do {
		 game_over = 0;
		 printf("\nGuess the row : \n");
		 scanf_s("%d", &x);
		 printf("\nGuess the column : \n");
		 scanf_s("%d", &y);

		 if (a == x && b == y) {					// Game over in case of a hit
			 printf("\n\n\t\tYOU WON\n\n");
			 game_over = 1;
		 }
		 else if (x > n || y > m) {
			 printf("Dude, that's not even on the board");
		 }
		 else if (x == 5 && y == 5) {
			 printf("You picked this position already");
		 }
		 else {
			 print_x(x,y,n,m);						// Calling the print_x() function
			 printf("Attempts remaining : %d\n", (max_attempts - attempts) - 1);
			 game_over = 0;
			 attempts++;
			 if (attempts == max_attempts) {		// Game over when there is no more attempts left
				 printf("\n\n\tYou used all attempts\n\n");
				 break;
			 }
		 }
	 } while (game_over != 1);
 }

void main() 
{
	srand((unsigned int)time(NULL));				// Seed declaration for drawing the ship position
	printf("Enter the size of the board  \n\n");	// Board size input from user
	printf("Number of rows : ");
	scanf_s("%d",&n);
	printf("Number of columns : ");
	scanf_s("%d",&m);
	printf("\n\n\tHits will be stored as '5'");
	printf("\n\n\tTop left corner is index 0x0\n\n");

	tab = (int**)malloc(n*sizeof(int*));			// Memory allocation
	for (int i = 0; i < n;i++) {
		tab[i] = (int*)malloc(m*sizeof(int));
	} 
	
	for (int i = 0; i < n;i++) {					// Filling the boards with empty spots (ones)
		for (int j = 0; j < m;j++) {
			tab[i][j] = 1;
		}
	}

	/* for (int i = 0; i < n;i++) {					// Assigning one-masted ship to random row/column (when hidden - doesn't print the position)
		for (int j = 0; j < m;j++) {
			tab[random_a(n)][random_b(m)] = 0;
		}
	} */

	/* for (int i = 0; i < n;i++) {					// Printing the board to the screen (hided)
		for (int j = 0; j < m;j++) {
			printf("%d\t", tab[i][j]);
		}
		printf("\n");
	} */

	play(n,m);										// Calling the play() function 

	for (int i = 0; i < m;i++) {					// Freeing memory
		free(tab[i]);
	}
	free(tab);
}