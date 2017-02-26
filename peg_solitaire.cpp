#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

//PegSolitaireBoard struct so that each board hold its own status board, valid moves, and empty peg locations
struct PegSolitaireBoard {
    int statusBoard[5][5];
    std::multimap<int, int>multimapOfValidMoves;
    std::vector<int>locationOfEmptyPegs;
};

//converts from indices to location on board and returns the location
int convertFromIndexToLocation(int i, int j) { 
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i == 0 && j == 1) {
        return 3;
    }
    if (i == 0 && j == 2) {
        return 6;
    }
    if (i == 0 && j == 3) {
        return 10;
    }
    if (i == 0 && j == 4) {
        return 15;
    }
    if (i == 1 && j == 0) {
        return 2;
    }
    if (i == 1 && j == 1) {
        return 5;
    }
    if (i == 1 && j == 2) {
        return 9;
    }
    if (i == 1 && j == 3) {
        return 14;
    }
    if (i == 2 && j == 0) {
        return 4;
    }
    if (i == 2 && j == 1) {
        return 8;
    }
    if (i == 2 && j == 2) {
        return 13;
    }
    if (i == 3 && j == 0) {
        return 7;
    }
    if (i == 3 && j == 1) {
        return 12;
    }
    if (i == 4 && j == 0) {
        return 11;
    }
    else {
        return 0;
    }
}

//set status to either zero or 1 based on a location given
void setStatusBasedOnLocation(PegSolitaireBoard *board, int location, int status) {
    if (location == 1) {
        board->statusBoard[0][0] = status;
    }
    if (location == 2) {
        board->statusBoard[1][0] = status;
    }
    if (location == 3) {
        board->statusBoard[0][1] = status;
    }
    if (location == 4) {
        board->statusBoard[2][0] = status;
    }
    if (location == 5) {
        board->statusBoard[1][1] = status;
    }
    if (location == 6) {
        board->statusBoard[0][2] = status;
    }
    if (location == 7) {
        board->statusBoard[3][0] = status;
    }
    if (location == 8) {
        board->statusBoard[2][1] = status;
    }
    if (location == 9) {
        board->statusBoard[1][2] = status;
    }
    if (location == 10) {
        board->statusBoard[0][3] = status;
    }
    if (location == 11) {
        board->statusBoard[4][0] = status;
    }
    if (location == 12) {
        board->statusBoard[3][1] = status;
    }
    if (location == 13) {
        board->statusBoard[2][2] = status;
    }
    if (location == 14) {
        board->statusBoard[1][3] = status;
    }
    if (location == 15) {
        board->statusBoard[0][4] = status;
    }
}

//initializes all pegs to -1 and then just the 15 pegs on the board to 1
void initializeStatusBoard(PegSolitaireBoard *board) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            board->statusBoard[i][j] = -1;
        }
    }

    int num = 5;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < num; ++j) {
            board->statusBoard[i][j] = 1;

        }
        num--;
    }
}

//sets a given locations status to zero
void setStatusBoard (PegSolitaireBoard *board, int location) {
    if (location == 1) {
        board->statusBoard[0][0] = 0;
    }
    if (location == 3) {
        board->statusBoard[0][1] = 0;
    }
    if (location == 6) {
        board->statusBoard[0][2] = 0;
    }
    if (location == 10) {
        board->statusBoard[0][3] = 0;
    }
    if (location == 15) {
        board->statusBoard[0][4] = 0;
    }
    if (location == 2) {
        board->statusBoard[1][0] = 0;
    }
    if (location == 5) {
        board->statusBoard[1][1] = 0;
    }
    if (location == 9) {
        board->statusBoard[1][2] = 0;
    }
    if (location == 14) {
        board->statusBoard[1][3] = 0;
    }
    if (location == 4) {
        board->statusBoard[2][0] = 0;
    }
    if (location == 8) {
        board->statusBoard[2][1] = 0;
    }
    if (location == 13) {
        board->statusBoard[2][2] = 0;
    }
    if (location == 7) {
        board->statusBoard[3][0] = 0;        
    }
    if (location == 12) {
        board->statusBoard[3][1] = 0;
    }
    if (location == 11) {
        board->statusBoard[4][0] = 0;
    }
}

//prints status board in correct format
void printStatusBoard(PegSolitaireBoard *board) {
    printf("          %i      \n", board->statusBoard[0][0]);
    printf("        %i   %i    \n", board->statusBoard[1][0], board->statusBoard[0][1]);
    printf("      %i   %i   %i   \n", board->statusBoard[2][0], board->statusBoard[1][1], board->statusBoard[0][2]);
    printf("    %i   %i   %i   %i \n", board->statusBoard[3][0], board->statusBoard[2][1], board->statusBoard[1][2], board->statusBoard[0][3]);
    printf("  %i   %i   %i   %i   %i\n", board->statusBoard[4][0], board->statusBoard[3][1], board->statusBoard[2][2], board->statusBoard[1][3], board->statusBoard[0][4]);
}

//prints location board in correct format
void printLocationBoard() {
    printf("          1         \n");
    printf("        2   3       \n");
    printf("      4   5   6     \n");
    printf("    7   8   9   10  \n");
    printf("  11  12  13  14  15\n");
}

//returns a map with the key being the empty peg and the value being a vector of all possible moves
std::map<int, std::vector<int> > getMapOfValidMoves() {
    std::vector<int>empty1;
    empty1.push_back(4);
    empty1.push_back(6);
    std::vector<int>empty2;
    empty2.push_back(7);
    empty2.push_back(9);
    std::vector<int>empty3;
    empty3.push_back(8);
    empty3.push_back(10);
    std::vector<int>empty4;
    empty4.push_back(1);
    empty4.push_back(6);
    empty4.push_back(11);
    empty4.push_back(13);
    std::vector<int>empty5;
    empty5.push_back(12);
    empty5.push_back(14);
    std::vector<int>empty6;
    empty6.push_back(1);
    empty6.push_back(4);
    empty6.push_back(13);
    empty6.push_back(15);
    std::vector<int>empty7;
    empty7.push_back(2);
    empty7.push_back(9);
    std::vector<int>empty8;
    empty8.push_back(3);
    empty8.push_back(10);
    std::vector<int>empty9;
    empty9.push_back(2);
    empty9.push_back(7);
    std::vector<int>empty10;
    empty10.push_back(3);
    empty10.push_back(8);
    std::vector<int>empty11;
    empty11.push_back(4);
    empty11.push_back(13);
    std::vector<int>empty12;
    empty12.push_back(5);
    empty12.push_back(14);
    std::vector<int>empty13;
    empty13.push_back(4);
    empty13.push_back(6);
    empty13.push_back(11);
    empty13.push_back(15);
    std::vector<int>empty14;
    empty14.push_back(5);
    empty14.push_back(12);
    std::vector<int>empty15;
    empty15.push_back(6);
    empty15.push_back(13);
    std::map<int, std::vector<int> >validMoves;
    validMoves.insert(std::pair<int, std::vector<int> >(1, empty1));
    validMoves.insert(std::pair<int, std::vector<int> >(2, empty2));
    validMoves.insert(std::pair<int, std::vector<int> >(3, empty3));
    validMoves.insert(std::pair<int, std::vector<int> >(4, empty4));
    validMoves.insert(std::pair<int, std::vector<int> >(5, empty5));
    validMoves.insert(std::pair<int, std::vector<int> >(6, empty6));
    validMoves.insert(std::pair<int, std::vector<int> >(7, empty7));
    validMoves.insert(std::pair<int, std::vector<int> >(8, empty8));
    validMoves.insert(std::pair<int, std::vector<int> >(9, empty9));
    validMoves.insert(std::pair<int, std::vector<int> >(10, empty10));
    validMoves.insert(std::pair<int, std::vector<int> >(11, empty11));
    validMoves.insert(std::pair<int, std::vector<int> >(12, empty12));
    validMoves.insert(std::pair<int, std::vector<int> >(13, empty13));
    validMoves.insert(std::pair<int, std::vector<int> >(14, empty14));
    validMoves.insert(std::pair<int, std::vector<int> >(15, empty15));
    return validMoves;
}

//returns a vector of all empty peg locations on board
std::vector<int> findEmptyPegLocations(PegSolitaireBoard *board) {
    std::vector<int>emptyPegs;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board->statusBoard[i][j] == 0) {
                emptyPegs.push_back(convertFromIndexToLocation(i, j));
            }
        }
    }
    return emptyPegs;
}

//returns the peg jumped over based on 2 pegs given, one begin the destination and one being the source
int findPegJumpedOver(int peg1, int peg2) {
    if ((peg1 == 1 || peg2 == 1) && (peg1 == 6 || peg2 == 6)) {
        return 3;
    }
    if ((peg1 == 1 || peg2 == 1) && (peg1 == 4 || peg2 == 4)) {
        return 2;
    }
    if ((peg1 == 2 || peg2 == 2) && (peg1 == 7 || peg2 == 7)) {
        return 4;
    }
    if ((peg1 == 2 || peg2 == 2) && (peg1 == 9 || peg2 == 9)) {
        return 5;
    }
    if ((peg1 == 3 || peg2 == 3) && (peg1 == 8 || peg2 == 8)) {
        return 5;
    }
    if ((peg1 == 3 || peg2 == 3) && (peg1 == 10 || peg2 == 10)) {
        return 6;
    }
    if ((peg1 == 4 || peg2 == 4) && (peg1 == 6 || peg2 == 6)) {
        return 5;
    }
    if ((peg1 == 4 || peg2 == 4) && (peg1 == 11 || peg2 == 11)) {
        return 7;
    }
    if ((peg1 == 4 || peg2 == 4) && (peg1 == 13 || peg2 == 13)) {
        return 8;
    }
    if ((peg1 == 5 || peg2 == 5) && (peg1 == 12 || peg2 == 12)) {
        return 8;
    }
    if ((peg1 == 5 || peg2 == 5) && (peg1 == 14 || peg2 == 14)) {
        return 9;
    }
    if ((peg1 == 6 || peg2 == 6) && (peg1 == 13 || peg2 == 13)) {
        return 9;
    }
    if ((peg1 == 6 || peg2 == 6) && (peg1 == 15 || peg2 == 15)) {
        return 10;
    }
    if ((peg1 == 7 || peg2 == 7) && (peg1 == 9 || peg2 == 9)) {
        return 8;
    }
    if ((peg1 == 8 || peg2 == 8) && (peg1 == 10 || peg2 == 10)) {
        return 9;
    }
    if ((peg1 == 11 || peg2 == 11) && (peg1 == 13 || peg2 == 13)) {
        return 12;
    }
    if ((peg1 == 12 || peg2 == 12) && (peg1 == 14 || peg2 == 14)) {
        return 13;
    }
    if ((peg1 == 13 || peg2 == 13) && (peg1 == 15 || peg2 == 15)) {
        return 14;
    }
    else {
        return -1;
    }
}

//moves a peg by setting the moving peg to 0, the destination peg to 1, and the peg jumped over to 0
void movePeg(PegSolitaireBoard *board, int movingPeg, int destinationHole) {
    setStatusBasedOnLocation(board, movingPeg, 0);
    setStatusBasedOnLocation(board, destinationHole, 1);
    int pegJumpedOver = findPegJumpedOver(movingPeg, destinationHole);
    setStatusBasedOnLocation(board, pegJumpedOver, 0);
}

//global variables to hold previous state of boards
std::vector<std::vector<int> >previousEmptyPegLocationStates;
std::vector<std::multimap<int, int> >previousMapValidMoveStates;

//returns 0 on success = more valid moves, keep going
//returns -1 on error = no more valid moves, backtrack
int updateBoard(PegSolitaireBoard *board) {
    std::map<int, std::vector<int> >::iterator findMovesForEmptyPegIterator;
    std::multimap<int, int>::iterator it;
    std::multimap<int, int>::const_iterator it2 = board->multimapOfValidMoves.begin();
    std::map<int, std::vector<int> >allMovesOnBoard; 
    allMovesOnBoard = getMapOfValidMoves();

    //clear out board data structures
    board->locationOfEmptyPegs.clear();
    board->multimapOfValidMoves.clear();
    //find the locations of all empty pegs for the given board
    board->locationOfEmptyPegs = findEmptyPegLocations(board);

    //based on the location of empty pegs, find the corresponding available moves to those pegs
    for (int i = 0; i < board->locationOfEmptyPegs.size(); ++i) {
        findMovesForEmptyPegIterator = allMovesOnBoard.find(board->locationOfEmptyPegs[i]);
        if (findMovesForEmptyPegIterator != allMovesOnBoard.end()) {
            for (int i = 0; i < findMovesForEmptyPegIterator->second.size(); ++i) {
                board->multimapOfValidMoves.insert(std::pair<int, int>(findMovesForEmptyPegIterator->first, findMovesForEmptyPegIterator->second[i]));
            }
        }
    }

    //go through all of the available moves and erase the invalid ones
    //a move is invalid if the jumped over peg is already empty or if the source peg is empty
    for (int j = 0; j < board->locationOfEmptyPegs.size(); ++j) {
        for (it2 = board->multimapOfValidMoves.begin(); it2 != board->multimapOfValidMoves.end(); ) {
            if (std::find(board->locationOfEmptyPegs.begin(), board->locationOfEmptyPegs.end(), findPegJumpedOver(it2->first, it2->second)) != board->locationOfEmptyPegs.end()) {
                board->multimapOfValidMoves.erase(it2);
                if (board->multimapOfValidMoves.size() != 0) {
                    it2 = board->multimapOfValidMoves.begin();
                } else {
                    return -1;
                }
            } 

            if (board->locationOfEmptyPegs[j] == it2->second) {
                board->multimapOfValidMoves.erase(it2);
                if (board->multimapOfValidMoves.size() != 0) {
                        it2 = board->multimapOfValidMoves.begin();
                } else {
                    return -1;
                }
            } 

            else {
                it2++;
            }
        }
    }

    //move the peg the first possible valid move
    it = board->multimapOfValidMoves.begin();
    movePeg(board, it->second, it->first);

    //hold onto the state of the board in the global variables
    previousEmptyPegLocationStates.push_back(board->locationOfEmptyPegs); 
    previousMapValidMoveStates.push_back(board->multimapOfValidMoves);

    //if it got this far it was a success = return 0
    return 0;
}

//prints out the status board and the path based on user input of true or false
void printBoardsIfTrue(std::vector<std::vector<int> >previousEmptyPegLocationStates, std::vector<std::multimap<int, int> >previousMapValidMoveStates) {
    PegSolitaireBoard *successBoard;
    successBoard = new PegSolitaireBoard;

    for (int i = 0; i < previousEmptyPegLocationStates.size(); ++i) {
        delete(successBoard);
        successBoard = new PegSolitaireBoard;
        successBoard->locationOfEmptyPegs = previousEmptyPegLocationStates[i];
        initializeStatusBoard(successBoard);
        for (int j = 0; j < successBoard->locationOfEmptyPegs.size(); ++j) {
            setStatusBoard(successBoard, successBoard->locationOfEmptyPegs[j]);
        }
        printStatusBoard(successBoard);
        printf("=====================\n");
        std::multimap<int, int>::iterator itr = previousMapValidMoveStates[i].begin();
        printf("%i -> %i\n", itr->second, itr->first);
    }

}

//prints out just the path based on user input
void printPathIfFalse(std::vector<std::multimap<int, int> >previousMapValidMoveStates) {
    for (int i = 0; i < previousMapValidMoveStates.size(); ++i) {
        std::multimap<int, int>::iterator itr = previousMapValidMoveStates[i].begin();
        printf("%i -> %i\n", itr->second, itr->first);
    }
}

int main(int argc, char**argv) {
    int emptyPegLocation = 0;
    std::string shouldPrintBoard;

    //error check command line arguments
    if (argc != 3) {
        printf("usage: ./a.out emptyPegLocation shouldPrintBoard\n%s\n%s\n",
               "where emptyPegLocation is between 1 and 15 (inclusive)",
               "and shouldPrintBoard is either 'true' or 'false'");
        printLocationBoard();
        exit(1);
    } else {
        emptyPegLocation = atoi(argv[1]);
        shouldPrintBoard = argv[2];

        if (emptyPegLocation < 1 || emptyPegLocation > 15 || (shouldPrintBoard != "true" && shouldPrintBoard != "false"))  {
            printf("usage: ./a.out emptyPegLocation shouldPrintBoard\n%s\n%s",
                   "where emptyPegLocation is between 1 and 15 (inclusive)",
                   "and shouldPrintBoard is either 'true' or 'false'\n");
            printLocationBoard();
            exit(1);
        }


        PegSolitaireBoard *board;
        board = new PegSolitaireBoard; 

        PegSolitaireBoard *newBoard;
        newBoard = new PegSolitaireBoard;

        //initialize the board to all 1's
        initializeStatusBoard(board);
        //set the location given by the user command line argument to 0
        setStatusBoard(board, emptyPegLocation);

        //while there are still valid moves keep updating the board
        do {
            updateBoard(board);
        } while (updateBoard(board) != -1);

        //if it hits here there are no more valid moves and must backtrack
        do {

            //reset newBoard
            delete(newBoard);

            //pop back the elements of the previous board states while the the map size is 1
            //if map size is 1 that means there was only one valid move and that move was already made
            while (previousMapValidMoveStates[previousMapValidMoveStates.size() - 1].size() == 1 && previousMapValidMoveStates.size() > 0) {
                previousMapValidMoveStates.pop_back();
                previousEmptyPegLocationStates.pop_back();
            }

            //once it finds a state with more than one valid move
            //erase the first one - this one was already made previously and didn't work
            std::multimap<int, int>::iterator it;
            it = previousMapValidMoveStates[previousMapValidMoveStates.size() - 1].begin();
            previousMapValidMoveStates[previousMapValidMoveStates.size() - 1].erase(it);
            it = previousMapValidMoveStates[previousMapValidMoveStates.size() - 1].begin();

            //create a new board with the given attributes
            newBoard = new PegSolitaireBoard;
            newBoard->multimapOfValidMoves = previousMapValidMoveStates[previousMapValidMoveStates.size() - 1];
            newBoard->locationOfEmptyPegs = previousEmptyPegLocationStates[previousEmptyPegLocationStates.size() - 1];

            //initialize the new boards status to all 1s and then set the empty peg locations
            initializeStatusBoard(newBoard);
            for (int i = 0; i < newBoard->locationOfEmptyPegs.size(); ++i) {
                setStatusBoard(newBoard, newBoard->locationOfEmptyPegs[i]);
            }

            //move the peg the first possible move
            movePeg(newBoard, it->second, it->first);

            //while there are still valid moves keep updating the board
            do {
                updateBoard(newBoard);
            } while (updateBoard(newBoard) != -1);

        //continue to do this while there are less than 14 empty pegs
        } while (newBoard->locationOfEmptyPegs.size() < 14);

        //if it hits here it was a success
        //print out board based on user's command line argument
        if (shouldPrintBoard == "true") {
            std::multimap<int, int>::iterator it = previousMapValidMoveStates[0].begin();
            printf("\nStarting empty peg: %i\n", it->first);
            printBoardsIfTrue(previousEmptyPegLocationStates, previousMapValidMoveStates);
            printStatusBoard(newBoard);
            printf("=====================\n");
        } else {
            std::multimap<int, int>::iterator it = previousMapValidMoveStates[0].begin();
            printf("\nStarting empty peg: %i\n", it->first);
            printPathIfFalse(previousMapValidMoveStates);
        }
    }
}
