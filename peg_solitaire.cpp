#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

void mapLocationToIndex() {
    std::multimap<std::string, int>locationAndIndex;
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[0][0]", 1));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[0][1]", 3));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[0][2]", 6));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[0][3]", 10));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[0][4]", 15));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[1][0]", 2));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[1][1]", 5));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[1][2]", 9));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[1][3]", 14));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[2][0]", 4));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[2][1]", 8));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[2][2]", 13));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[3][0]", 7));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[3][1]", 12));
    locationAndIndex.insert(std::pair<std::string, int>("locationBoard[4][0]", 11));
}

void statusBoard(int board[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            board[i][j] = -1;
        }
    }

    int num = 5;
    for (int i = 0; i < num + 4; ++i) {
        for (int j = 0; j < num; ++j) {
            board[i][j] = 1;

        }
        num--;
    }
}

void outputBoard(int board[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] != -1) {
                printf("%i  ", board[i][j]);
            }
        }
        
        printf("\n");
    }
}

void pegLocations(int locationBoard[5][5], int location) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            locationBoard[i][j] = -1;
        }
    }

    int num = 5;
    for (int i = 0; i < num + 4; ++i) {
        for (int j = 0; j < num; ++j) {
            locationBoard[i][j] = 1;

        }
        num--;
    }

    if (location == 1) {
        locationBoard[0][0] = 0;
    }
    if (location == 3) {
        locationBoard[0][1] = 0;
    }
    if (location == 6) {
        locationBoard[0][2] = 0;
    }
    if (location == 10) {
        locationBoard[0][3] = 0;
    }
    if (location == 15) {
        locationBoard[0][4] = 0;
    }
    if (location == 2) {
        locationBoard[1][0] = 0;
    }
    if (location == 5) {
        locationBoard[1][1] = 0;
    }
    if (location == 9) {
        locationBoard[1][2] = 0;
    }
    if (location == 14) {
        locationBoard[1][3] = 0;
    }
    if (location == 4) {
        locationBoard[2][0] = 0;
    }
    if (location == 8) {
        locationBoard[2][1] = 0;
    }
    if (location == 13) {
        locationBoard[2][2] = 0;
    }
    if (location == 7) {
        locationBoard[3][0] = 0;        
    }
    if (location == 12) {
        locationBoard[3][1] = 0;
    }
    if (location == 11) {
        locationBoard[4][0] = 0;
    }
}

void findValidMoves(int board[5][5]) {
//     std::vector<std::string> possiblePegsToBeMoved;
    std::multimap<std::string, std::string>possiblePegsToBeMoved;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == 0) {
                if (i + 2 < 5 && board[i+2][j] != -1) {
                    std::string pegToBeMoved = "board[" + std::to_string(i+2) + "][" + std::to_string(j) + "]";
                    std::string holeToBeOccupied = "board[" + std::to_string(i) + "][" + std::to_string(j) + "]";
                    possiblePegsToBeMoved.insert(std::pair<std::string, std::string>(holeToBeOccupied, pegToBeMoved));
                    // possiblePegsToBeMoved.push_back(boardIndex.c_str());
                }
                if (i - 2 >= 0 && board[i-2][j] != -1) {
                    std::string pegToBeMoved = "board[" + std::to_string(i-2) + "][" + std::to_string(j) + "]";
                    std::string holeToBeOccupied = "board[" + std::to_string(i) + "][" + std::to_string(j) + "]";
                    possiblePegsToBeMoved.insert(std::pair<std::string, std::string>(holeToBeOccupied, pegToBeMoved));
                    // possiblePegsToBeMoved.push_back(boardIndex.c_str());
                }
                if (j + 2 < 5 && board[i][j+2] != -1) {
                    std::string pegToBeMoved = "board[" + std::to_string(i) + "][" + std::to_string(j+2) + "]";
                    std::string holeToBeOccupied = "board[" + std::to_string(i) + "][" + std::to_string(j) + "]";
                    possiblePegsToBeMoved.insert(std::pair<std::string, std::string>(holeToBeOccupied, pegToBeMoved));
                    // possiblePegsToBeMoved.push_back(boardIndex.c_str());
                }
                if (j - 2 >= 0 && board[i][j-2] != -1) {
                    std::string pegToBeMoved = "board[" + std::to_string(i) + "][" + std::to_string(j-2) + "]";
                    std::string holeToBeOccupied = "board[" + std::to_string(i) + "][" + std::to_string(j) + "]";
                    possiblePegsToBeMoved.insert(std::pair<std::string, std::string>(holeToBeOccupied, pegToBeMoved));
                    // possiblePegsToBeMoved.push_back(boardIndex.c_str());
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int board[5][5];
    int locationBoard[5][5];

    int emptyPegLocation = 0;
    std::string printBoard;
    
    if (argc != 3) {
        printf("usage: ./a.out emptyPegLocation printBoard\n%s\n%s",
               "where emptyPegLocation is between 1 and 15 (inclusive)",
               "and printBoard is either 'true' or 'false'\n");
    } else {
        emptyPegLocation = atoi(argv[1]);
        printBoard = argv[2];

        if (emptyPegLocation < 1 || emptyPegLocation > 15 || (printBoard != "true" && printBoard != "false"))  {
            printf("usage: ./a.out emptyPegLocation printBoard\n%s\n%s",
                   "where emptyPegLocation is between 1 and 15 (inclusive)",
                   "and printBoard is either 'true' or 'false'\n");
        }

        statusBoard(board);
        pegLocations(locationBoard, emptyPegLocation);
        outputBoard(locationBoard);
        findValidMoves(locationBoard);
        mapLocationToIndex();
    }
}