#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define WHITE "\e[48;5;255m"
#define BLACK "\e[48;5;250m"

#define CLEAR "\e[2J"

// define and initialize chess pieces
unsigned short Wk=0x2654,Wq=0x2655,Wr=0x2656,Wb=0x2657,Wn=0x2658,Wp=0x2659;
unsigned short Bk=0x265A,Bq=0x265B,Br=0x265C,Bb=0x265D,Bn=0x265E,Bp=0x265F;
		
// define array to hold current positions
// Note: black pieces are upper case, white are lower
char board[8][8] = {{'R','N','B','Q','K','B','N','R'},
					{'P','P','P','P','P','P','P','P'},
					{' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' '},
					{'p','p','p','p','p','p','p','p'},
					{'r','n','b','q','k','b','n','r'} };

void DisplayChessBoard();
void PlacePiecesOnBoard();
void MoveCursorTo(int row, int col);
void SetSquareColour(int row, int col);
void MoveThePiece(char p);

int main() {
	char lfcol,ltcol,hold;
	int fcol=4,frow,tcol,trow;
	setlocale(LC_CTYPE, "");
    printf(CLEAR);
	DisplayChessBoard();
	PlacePiecesOnBoard();
	while (fcol < 9 && fcol > 0) {
		MoveCursorTo(11,1);
		printf("Move? ");
		scanf("%c%d%c%d",&lfcol,&frow,&ltcol,&trow);
		getchar();
        if(lfcol == 'q') exit(1);
		fcol=lfcol-96;
		tcol=ltcol-96;
		frow=9-frow;
		trow=9-trow;
		// Clear the FROM square
		SetSquareColour(frow,fcol);
		printf(" ");
		// Update the board array
		hold = board[frow-1][fcol-1];
		board[trow-1][tcol-1] = hold;
		board[frow-1][fcol-1] = ' ';
		// Update the display
		SetSquareColour(trow,tcol);
		MoveThePiece(hold);
	}
	return 0;
}

void MoveThePiece(char piece) {
	switch (piece) {
			case 'p':	printf("%lc",Wp);
						break;
			case 'r':	printf("%lc",Wr);
						break;
			case 'n':	printf("%lc",Wn);
						break;
			case 'b':	printf("%lc",Wb);
						break;
			case 'q':	printf("%lc",Wq);
						break;							
			case 'k':	printf("%lc",Wk);
						break;
			case 'P':	printf("%lc",Bp);
						break;
			case 'R':	printf("%lc",Br);
						break;
			case 'N':	printf("%lc",Bn);
						break;
			case 'B':	printf("%lc",Bb);
						break;
			case 'Q':	printf("%lc",Bq);
						break;							
			case 'K':	printf("%lc",Bk);
						break;
		}
}

void SetSquareColour(int row, int col) {
	MoveCursorTo(row,col);
	if((row%2 == 1 && col%2 == 1) || (row%2 == 0 && col%2 == 0))
		printf(WHITE);
	else
		printf(BLACK);
}

void PlacePiecesOnBoard() {
	int col;
	for(col=1;col<9;col++) {
		SetSquareColour(2,col);
		printf("%lc",Bp);
		SetSquareColour(1,col);
		switch (col) {
			case 1: printf("%lc",Br);
					break;
			case 2: printf("%lc",Bn);
					break;
			case 3: printf("%lc",Bb);
					break;
			case 4: printf("%lc",Bq);
					break;
			case 5: printf("%lc",Bk);
					break;
			case 6: printf("%lc",Bb);
					break;
			case 7: printf("%lc",Bn);
					break;
			case 8: printf("%lc",Br);
					break;
		}
	}
	for(col=1;col<9;col++) {
		SetSquareColour(7,col);
		printf("%lc",Wp);
		SetSquareColour(8,col);
		switch (col) {
			case 1: printf("%lc",Wr);
					break;
			case 2: printf("%lc",Wn);
					break;
			case 3: printf("%lc",Wb);
					break;
			case 4: printf("%lc",Wq);
					break;
			case 5: printf("%lc",Wk);
					break;
			case 6: printf("%lc",Wb);
					break;
			case 7: printf("%lc",Wn);
					break;
			case 8: printf("%lc",Wr);
					break;
		}
	}
}

void MoveCursorTo(int r, int c) {
	printf("\e[%1d;%1df",r,c);
}

void DisplayChessBoard() {
	int row, col;
	for(row=1;row<9;row++) {
		for(col=1;col<9;col++) {
			MoveCursorTo(row,col);
			if(row%2 == 1)
				if(col%2 == 1) {
					printf(WHITE);
					printf(" ");
				}
				else {
					printf(BLACK);
					printf(" ");
				}
			else
				if(col%2 == 1) {
					printf(BLACK);
					printf(" ");
				}
				else {
					printf(WHITE);
					printf(" ");
				}
		}
	}
	for(row=1;row<9;row++) {
		MoveCursorTo(row,9);
		printf("%d",9-row);
	}
	for(col=1;col<9;col++) {
		MoveCursorTo(9,col);
		switch (col) {
			case 1: printf("a");
					break;
			case 2: printf("b");
					break;
			case 3: printf("c");
					break;
			case 4: printf("d");
					break;
			case 5: printf("e");
					break;
			case 6: printf("f");
					break;
			case 7: printf("g");
					break;
			case 8: printf("h");
					break;
			}
		}
}
