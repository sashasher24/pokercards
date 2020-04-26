#include "header.h"

bool duplicate (char *cards[]) {
    for (int i = 0; i <= 4; i++) {
        for (int j = i+1; j <= 4; j++) {
            if (!mx_strcmp(cards[i],cards[j])) {
                mx_printerr("Duplicate cards: ");
		mx_printerr(cards[i]);
		mx_printerr("\n");
                exit(1);
            }
        }
    }
    return 0;
}

void inval_card(char *cards[]) {
    int i = 0;
    bool rank = 0;
    bool suit = 0;
    while (cards[i] != '\0') {
        if ((mx_strlen(cards[i]) == 2 && ((cards[i][0] >= '2' && cards[i][0] <= '9') || cards[i][0] == 'J' || cards[i][0] == 'Q' || cards[i][0] == 'K' || cards[i][0] == 'A')) || (mx_strlen(cards[i]) == 3 && (cards[i][0] == '1' && cards[i][1] == '0'))) {
            rank = 1;
        }
        else {
            rank = 0;
        }
        int j = mx_strlen(cards[i]) -1;
        if (cards[i][j] == 'H' || cards[i][j] == 'C' || cards[i][j] == 'S' || cards[i][j] == 'D') {
            suit = 1;
        }
        else {
            suit = 0;
        }
        if (!rank && !suit) {
            mx_printerr("Invalid card: ");
	    mx_printerr(&cards[i][0]);
	    mx_printerr(&cards[i][j]);
	    mx_printerr("\n");
            exit(1);
        }
        else if(rank && !suit) {
	    mx_printerr("Invalid suit: ");
            mx_printerr(&cards[i][j]);
            mx_printerr("\n");
            exit(1);
        }
        else if (!rank && suit) {
	    mx_printerr("Invalid rank: ");
            mx_printerr(&cards[i][j]);
            mx_printerr("\n");
            exit(1);
        }
        i++;
    }
}

bool ispair (char *cards[]) {
    for (int i = 1; i <= 5; i++) {
        for (int j = i+1; j <= 5; j++) {
            if(cards[i][0] == cards[j][0]) {
                return 1;
            }
        }
    }
    return 0;
}

bool twopair (char *cards[]) {
    int num = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = i+1; j <= 5; j++) {
            if(cards[i][0] == cards[j][0]) {
                num++;
            }
        }
    }
    if (num == 2) return 1; 
    return 0;
}

bool three(char *cards[]) {
    int num = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = i+1; j <= 5; j++) {
            if (cards[i][0] == cards[j][0] ) {
                num +=1;
            }
            if (num == 2) return 1; 
        } 
    }
    return 0;
}

bool four(char *cards[]) {
    int num = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = i+1; j <= 5; j++) {
              if (cards[i][0] == cards[j][0] ) {
                  num++;
          }
        }
        if (num == 3) return 1; 
    } 
    return 0;
}

bool flash(char *cards[]) {
    for (int i = 1; i <= 4; i++) {
        int j = mx_strlen(cards[i]) -1;
        if (cards[i][j] != cards[i+1][j]) {
            return 0;
        }
    }
    return 1;
}

bool full_house(char *cards[]) {
    int num = 0;
    char r;
    for (int i = 1; i <= 5; i++) {
        for (int j = i+1; j <= 5; j++) {
            if (cards[i][0] == cards[j][0] ) {
                num++;
            }
        }
        if (num == 2) {
            r = cards[i][0]; 
            break;
        }
    }
    if (num != 2) {
        return 0;
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = i+1; j <= 5; j++) {
            if(cards[i][0] != r && cards[i][0] == cards[j][0]) {
                return 1;
            }
        }
    }
    return 0;
}

void combination(char *cards[]) {
     if (four(cards)) {
         mx_printstr("Four of a kind");
         exit(0);
     }
     else if (flash(cards)) {
        mx_printstr("Flash");
        exit(0);
    }
    else if (full_house(cards)) {
        mx_printstr("Full House");
        exit(0);
    }
    else if (three(cards)) {
        mx_printstr("Three of a kind");
        exit(0);
    }
    else if (twopair(cards)) {
        mx_printstr("Two pairs");
        exit(0);
    }
    else if (ispair(cards)) {
        mx_printstr("One pair");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
     if (argc != 6) {
         mx_printerr("usage: ./race03 [card1] [card2] [card3] [card4] [card5]");
        mx_printerr("\n"); 
    	exit(1);
     }
    if (duplicate(argv)) {
        exit(1);
    }
    inval_card(argv);
    combination(argv);
    return 0;
}
