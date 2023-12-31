#include <iostream>
#include <iomanip>


using namespace std;

//___________________________________________________________________________

int board[6][10] = 
{
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};

//___________________________________________________________________________

const int piece[][5][5] = 
{
	// piece number 1: 1 case
	// name piece: Cross
	//  #
    // ###
    //  #
    {
        { -1,  1, -1, -1, -1 },
        {  1,  1,  1, -1, -1 },
        { -1,  1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 2: 2 case
    // #####
    {
        {  2,  2,  2,  2,  2 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  2, -1, -1, -1, -1 },
        {  2, -1, -1, -1, -1 },
        {  2, -1, -1, -1, -1 },
        {  2, -1, -1, -1, -1 },
        {  2, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 3: 4 case
    // #
    // ###
    //   #
    {
        {  3, -1, -1, -1, -1 },
        {  3,  3,  3, -1, -1 },
        { -1, -1,  3, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  3,  3, -1, -1 },
        { -1,  3, -1, -1, -1 },
        {  3,  3, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  3,  3, -1, -1, -1 },
        { -1,  3, -1, -1, -1 },
        { -1,  3,  3, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1,  3, -1, -1 },
        {  3,  3,  3, -1, -1 },
        {  3, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 4: 4 case
    // ###
    // #
    // #
    {
        {  4,  4,  4, -1, -1 },
        {  4, -1, -1, -1, -1 },
        {  4, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  4,  4,  4, -1, -1 },
        { -1, -1,  4, -1, -1 },
        { -1, -1,  4, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1,  4, -1, -1 },
        { -1, -1,  4, -1, -1 },
        {  4,  4,  4, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  4, -1, -1, -1, -1 },
        {  4, -1, -1, -1, -1 },
        {  4,  4,  4, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 5: 4 case
    //  ##
    // ##
    // #
    {
        { -1,  5,  5, -1, -1 },
        {  5,  5, -1, -1, -1 },
        {  5, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  5,  5, -1, -1, -1 },
        { -1,  5,  5, -1, -1 },
        { -1, -1,  5, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1,  5, -1, -1 },
        { -1,  5,  5, -1, -1 },
        {  5,  5, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  5, -1, -1, -1, -1 },
        {  5,  5, -1, -1, -1 },
        { -1,  5,  5, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
   // piece number 6: 4 case
    // ###
    //  #
    //  #
    {
        {  6,  6,  6, -1, -1 },
        { -1,  6, -1, -1, -1 },
        { -1,  6, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1,  6, -1, -1 },
        {  6,  6,  6, -1, -1 },
        { -1, -1,  6, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  6, -1, -1, -1 },
        { -1,  6, -1, -1, -1 },
        {  6,  6,  6, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  6, -1, -1, -1, -1 },
        {  6,  6,  6, -1, -1 },
        {  6, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 7: 4 case
    // ###
    // # #
    {
        {  7,  7,  7, -1, -1 },
        {  7, -1,  7, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  7,  7, -1, -1, -1 },
        { -1,  7, -1, -1, -1 },
        {  7,  7, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  7, -1,  7, -1, -1 },
        {  7,  7,  7, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  7,  7, -1, -1, -1 },
        {  7, -1, -1, -1, -1 },
        {  7,  7, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
   // piece number 8: 8 case
    // #
    // ###
    //  #
    {
        {  8, -1, -1, -1, -1 },
        {  8,  8,  8, -1, -1 },
        { -1,  8, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  8,  8, -1, -1 },
        {  8,  8, -1, -1, -1 },
        { -1,  8, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  8, -1, -1, -1 },
        {  8,  8,  8, -1, -1 },
        { -1, -1,  8, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  8, -1, -1, -1 },
        { -1,  8,  8, -1, -1 },
        {  8,  8, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  8,  8, -1, -1, -1 },
        { -1,  8,  8, -1, -1 },
        { -1,  8, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  8, -1, -1, -1 },
        {  8,  8,  8, -1, -1 },
        {  8, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  8, -1, -1, -1 },
        {  8,  8, -1, -1, -1 },
        { -1,  8,  8, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1,  8, -1, -1 },
        {  8,  8,  8, -1, -1 },
        { -1,  8, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 9: 8 case
    // ####
    //    #
    {
        {  9,  9,  9,  9, -1 },
        { -1, -1, -1,  9, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1,  9, -1, -1, -1 },
        { -1,  9, -1, -1, -1 },
        { -1,  9, -1, -1, -1 },
        {  9,  9, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  9, -1, -1, -1, -1 },
        {  9,  9,  9,  9, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  9,  9, -1, -1, -1 },
        {  9, -1, -1, -1, -1 },
        {  9, -1, -1, -1, -1 },
        {  9, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  9, -1, -1, -1, -1 },
        {  9, -1, -1, -1, -1 },
        {  9, -1, -1, -1, -1 },
        {  9,  9, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1, -1,  9, -1 },
        {  9,  9,  9,  9, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  9,  9, -1, -1, -1 },
        { -1,  9, -1, -1, -1 },
        { -1,  9, -1, -1, -1 },
        { -1,  9, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        {  9,  9,  9,  9, -1 },
        {  9, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 10: 8 case
    // ####
    //   #
    {
        { 10, 10, 10, 10, -1 },
        { -1, -1, 10, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 10, -1, -1, -1 },
        { -1, 10, -1, -1, -1 },
        { 10, 10, -1, -1, -1 },
        { -1, 10, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 10, -1, -1, -1 },
        { 10, 10, 10, 10, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 10, -1, -1, -1, -1 },
        { 10, 10, -1, -1, -1 },
        { 10, -1, -1, -1, -1 },
        { 10, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 10, -1, -1, -1, -1 },
        { 10, -1, -1, -1, -1 },
        { 10, 10, -1, -1, -1 },
        { 10, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1, 10, -1, -1 },
        { 10, 10, 10, 10, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 10, -1, -1, -1 },
        { 10, 10, -1, -1, -1 },
        { -1, 10, -1, -1, -1 },
        { -1, 10, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 10, 10, 10, 10, -1 },
        { -1, 10, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
    // piece number 11: 8 case
    // ###
    //   ##
    {
        { 11, 11, 11, -1, -1 },
        { -1, -1, 11, 11, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 11, -1, -1, -1 },
        { -1, 11, -1, -1, -1 },
        { 11, 11, -1, -1, -1 },
        { 11, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 11, 11, -1, -1, -1 },
        { -1, 11, 11, 11, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 11, -1, -1, -1 },
        { 11, 11, -1, -1, -1 },
        { 11, -1, -1, -1, -1 },
        { 11, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 11, -1, -1, -1, -1 },
        { 11, -1, -1, -1, -1 },
        { 11, 11, -1, -1, -1 },
        { -1, 11, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, -1, 11, 11, -1 },
        { 11, 11, 11, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 11, -1, -1, -1, -1 },
        { 11, 11, -1, -1, -1 },
        { -1, 11, -1, -1, -1 },
        { -1, 11, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 11, 11, 11, -1 },
        { 11, 11, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    //______________________________________________
   // piece number 12: 8 case
    // ###
    //  ##
    {
        { 12, 12, 12, -1, -1 },
        { -1, 12, 12, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 12, -1, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 12, 12, -1, -1, -1 },
        { 12, 12, 12, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 12, 12, -1, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { 12, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 12, -1, -1, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { -1, 12, 12, -1, -1 },
        { 12, 12, 12, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 12, 12, -1, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { -1, 12, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    },
    {
        { 12, 12, 12, -1, -1 },
        { 12, 12, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 },
        { -1, -1, -1, -1, -1 }
    }
};


//___________________________________________________________________________

const int pieceMin[12] =        {  3,  1,  3,  3,  3,  3,  2,  3,  2,  2,  2,  2 };
const int pieceMax[12] =        {  3,  5,  3,  3,  3,  3,  3,  3,  4,  4,  4,  3 };
const int pieceIdx[12] =        {  0,  1,  3,  7, 11, 15, 19, 23, 31, 39, 47, 55 };
const int orientMax[12] =       {  1,  2,  4,  4,  4,  4,  4,  8,  8,  8,  8,  8 };

int pieceOrient[12] =           { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int pieceRow[12] =              { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int pieceCol[12] =              { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int lastPiece = -1;
int solutionCount = 0;

//___________________________________________________________________________

void printBoard() {
  for (int row = 0; row < 6; row++) {
    for (int col = 0; col < 10; col++) {
      if (board[row][col] == -1) {
        cout << setw(3) << "."; 
      } else {
        cout << setw(3) << board[row][col];
      }
    }
    cout << endl; 
  }
}

//___________________________________________________________________________


// first print orient of the piece, scond print first row of piece, third print first col of piece
void printSolution() {

  cout << "Solution " << solutionCount << ":" << endl;
  
  for (int i = 0; i < 12; i++) {
    if (pieceOrient[i] == -1) {
      cout << "Piece " << i+1 << " not placed yet" << endl;
      continue; 
    }
    
    cout << "Piece " << i+1 << ": ";
    cout << "Orient " << pieceOrient[i] << ", ";
    cout << "Row " << pieceRow[i]+1 << ", "; 
    cout << "Col " << pieceCol[i]+1 << endl;
  }

}

//___________________________________________________________________________

// test the last piece. If the last element is not placed in the range of the board or is placed on another element, the test is false.
bool testPiece(int row, int col, int orient) {
  // Loop through rows and cols of piece
  for (int r = 0; r < pieceMax[lastPiece+1]; r++) {
    for (int c = 0; c < pieceMax[lastPiece+1]; c++) {
      
      // Get value at current position
      int val = piece[pieceIdx[lastPiece+1] + orient][r][c];
      
      // Check if value is not empty
      if (val != -1) {
      
        // Check row and col are in bounds
        if (row + r > 5 || col + c > 9) {
          return false; 
        }
        
        // Check board position is empty
        if (board[row+r][col+c] != -1) {
          return false;
        }
      }
    } 
  }

  return true;
}
//___________________________________________________________________________

void placePiece(int row, int col, int orient)
{
	// Place the next piece
    ++lastPiece;
    for (int r = 0; r != pieceMax[lastPiece]; ++r)
    {
        for (int c = 0; c != pieceMax[lastPiece]; ++c)
        {
            const int val = piece[pieceIdx[lastPiece] + orient][r][c];
            if (val != -1)
            {
                board[row + r][col + c] = val;
            }
        }
    }
    pieceRow[lastPiece] = row;
    pieceCol[lastPiece] = col;
    pieceOrient[lastPiece] = orient;
}

//___________________________________________________________________________

// remove last element for replace with new element(Recursion)
// If the piece is placed in the wrong place, after testing it, it removes the piece.
void removePiece()
{
    for (int r = 0; r != pieceMax[lastPiece]; ++r)
    {
        for (int c = 0; c != pieceMax[lastPiece]; ++c)
        {
            const int val = piece[pieceIdx[lastPiece] + pieceOrient[lastPiece]][r][c];
            if (val != -1)
            {
                board[pieceRow[lastPiece] + r][pieceCol[lastPiece] + c] = -1;
            }
        }
    }
    pieceRow[lastPiece] = -1;
    pieceCol[lastPiece] = -1;
    pieceOrient[lastPiece] = -1;
    --lastPiece;
}

//___________________________________________________________________________

//The number of elements with value -1 that are next to each other in the board
int mark(int row, int col, int markVal)
{
    int markCount = 0;

    if (board[row][col] == -1)
    {
        board[row][col] = markVal;
        ++markCount;

        if (0 < row)
        {
            markCount += mark(row - 1, col, markVal);
        }
        if (row < 5)
        {
            markCount += mark(row + 1, col, markVal);
        }
        if (0 < col)
        {
            markCount += mark(row, col - 1, markVal);
        }
        if (col < 9)
        {
            markCount += mark(row, col + 1, markVal);
        }
    }

    return markCount;
}
 
//___________________________________________________________________________

//We check whether 5 elements next to each other are empty or not (using the mark function)
bool prune()
{
    bool bResult = false;
    int markVal = -2;
    int totalMarkCount = 0;

    for (int row = 0; row <= 5; ++row)
    {
        for (int col = 0; col <= 9; ++col)
        {
            const int markCount = mark(row, col, markVal);
            if (markCount)
            {
                --markVal;
                totalMarkCount += markCount;
            }
            else
            {
                continue;
            }
            if (markCount % 5)
            {
                bResult = true;
                goto cleanup;
            }
            if (totalMarkCount + lastPiece*5 == 60)
            {
                goto cleanup;
            }
        }
    }

cleanup:
// clear all board
    for (int row = 0; row <= 5; ++row)
    {
        for (int col = 0; col <= 9; ++col)
        {
            if (board[row][col] < 0)
            {
                board[row][col] = -1;
            }
        }
    }

    return bResult;
}

//___________________________________________________________________________

void solvePiece(int row, int col, int orient)
{
    if (!testPiece(row, col, orient))
    {
        return;
    }

    placePiece(row, col, orient);

    if (lastPiece == 11)
    {
    	// enter for print next solution
    	cout << "\n\n" << "Waiting for the command to run! Please enter" << endl << ":)" << endl;
    	char x = getchar();
        ++solutionCount;
        printSolution();
        printBoard();
		
    }
    else
    {
        if (!prune())
        {
            const int rowMax =  6 - pieceMin[lastPiece + 1];
            const int colMax = 10 - pieceMin[lastPiece + 1];
            for (int orient = 0; orient < orientMax[lastPiece + 1]; ++orient)
            {
                for (int row = 0; row <= rowMax; ++row)
                {
                    for (int col = 0; col <= colMax; ++col)
                    {
                        solvePiece(row, col, orient);
                    }
                }
            }
        }
    }

    removePiece();
}

//___________________________________________________________________________

// arrange all of element than cross element (element number 1)
// If all 12 pieces are placed in their place, it is one of the answers to the problem, which displays the numerical solution and the board.
// Otherwise, it executes the solution again using the causal function.
void solveCross(int row, int col)
{
    if (!testPiece(row, col, 0))
    {
        return;
    }

    placePiece(row, col, 0);

    if (!prune())
    {
    	
        const int rowMax = 6 - pieceMin[lastPiece + 1];
        const int colMax = 10 - pieceMin[lastPiece + 1];
        for (int orient = 0; orient < orientMax[lastPiece + 1]; ++orient)
        {
            if (pieceRow[0] == pieceCol[0] && pieceRow[1] == pieceCol[1] && 0 < orient)
            {
                // Special case: if symmetric about diagonal, use only one line orientation.
                break;
            }
            for (int row = 0; row <= rowMax; ++row)
            {
                for (int col = 0; col <= colMax; ++col)
                {
                    solvePiece(row, col, orient);
                }
            }
        }
    }

    removePiece();
}

//___________________________________________________________________________

int main(int argc, char* argv[])
{
	//______________________________________________
	
	// modes that cross ( mean piece number 1) in all place in the board
	/*
	for (int row = 0; row <= 3; ++row)
        {
            for (int col = 0; col <= 7; ++col)
            {
                solveCross(row, col);
            }
        }
    	// number of solution: 8989
    */
    //______________________________________________
    
    // modes that cross ( mean piece number 1) start in place (0, 0) into (1, 1)
    /*
    for (int row = 0; row <= 1; ++row)
        {
            for (int col = 0; col <= 1; ++col)
            {
                solveCross(row, col);
            }
        }
		// number of solution: 936
    */    
	/*  
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		 0,  0,  1,  0,  0,  0,  0,  0,  0,  0		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		 0,  0,  1,  0,  0,  0,  0,  0,  0,  0		 0,  1,  1,  1,  0,  0,  0,  0,  0,  0		 0,  1,  0,  0,  0,  0,  0,  0,  0,  0		0,  0,  1,  0,  0,  0,  0,  0,  0,  0
		 0,  1,  1,  1,  0,  0,  0,  0,  0,  0		 0,  0,  1,  0,  0,  0,  0,  0,  0,  0		 1,  1,  1,  0,  0,  0,  0,  0,  0,  0		0,  1,  1,  1,  0,  0,  0,  0,  0,  0
		 0,  0,  1,  0,  0,  0,  0,  0,  0,  0		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		 0,  1,  0,  0,  0,  0,  0,  0,  0,  0		0,  0,  1,  0,  0,  0,  0,  0,  0,  0
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0		0,  0,  0,  0,  0,  0,  0,  0,  0,  0
	*/  
	
	//______________________________________________
	
	// If we do not consider symmetric modes, the position of the cross can be from (0, 0) to (0, 3):
	
	for (int row = 0; row <= 1; ++row)
        {
            for (int col = 0; col <= 3; ++col)
            {
                solveCross(row, col);
            }
        }
        // number of solution: 2182
	//______________________________________________________
	
    cout << "Number of solutions is: " << solutionCount;
    
	//______________________________________________________
}

