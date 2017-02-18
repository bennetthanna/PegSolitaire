#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

std::map<int, std::vector<int> > findValidMoves() {
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

std::vector<int> findEmptyPegLocations(int board[5][5]) {
    std::vector<int>emptyPegs;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == 0) {
                emptyPegs.push_back(convertFromIndexToLocation(i, j));
            }
        }
    }

    return emptyPegs;
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

std::multimap<std::string, std::string> findValidMoves(int board[5][5]) {
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

    return possiblePegsToBeMoved;
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
        std::map<int, std::vector<int> >validMoves;
        validMoves = findValidMoves();

        std::map<int, std::vector<int> >::iterator findIterator;
        findIterator = validMoves.find(emptyPegLocation);
        if (findIterator != validMoves.end()) {
            std::cout << findIterator->first << " => ";
            for (int i = 0; i < (findIterator->second).size(); ++i) {
                std::cout << findIterator->second[i] << " ";
            }
            std::cout << std::endl;
        }

        std::vector<int>emptyPegLocations;
        emptyPegLocations = findEmptyPegLocations(locationBoard);
        for (int i = 0; i < emptyPegLocations.size(); ++i) {
            std::cout << "Empty peg locations = " << emptyPegLocations[i] << std::endl;
        }

        for (int i = 0; i < emptyPegLocations.size(); ++i) {
            std::map<int, std::vector<int> >::iterator it;
            for (it = validMoves.begin(); it != validMoves.end(); ++it) {
                for (int j = 0; j < it->second.size(); ++j) {
                    if(emptyPegLocations[i] == it->second[j]) {
                        printf("ERASE PLEASE\n");
                        it->second.erase(it->second.begin() + j);
                    } 
                }
            }
        }


        std::map<int, std::vector<int> >::iterator it2;
        for (it2=validMoves.begin(); it2!=validMoves.end(); ++it2) {
            std::cout << it2->first << " => ";
            for (int i = 0; i < (it2->second).size(); ++i) {
                std::cout << it2->second[i] << " ";
            }
            std::cout << std::endl;
        }

    }
}