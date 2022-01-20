
// Function to calculate best score
int minimax(char board[][SIDE], int depth, bool isAI) {
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true) {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else {
        if (depth < 9) {
            if (isAI == true){
                bestScore = -999;
                for (int i = 0; i < SIDE; i++)  
                    for (int j = 0; j < SIDE; j++)
                        if (board[i][j] == ' ') {
                            board[i][j] = COMPUTERMOVE;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = ' ';
                            if (score > bestScore)  bestScore = score; 
                        } 
                return bestScore;
            }
            else {
                bestScore = 999;
                for (int i = 0; i < SIDE; i++)
                    for (int j = 0; j < SIDE; j++) 
                        if (board[i][j] == ' ') {
                            board[i][j] = HUMANMOVE;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = ' ';
                            if (score < bestScore)  bestScore = score;
                           
                        } 
                return bestScore;
            }
        }
        else return 0; 
    }
    return 0;
}

// Function to calculate best move
int bestMove(char board[][SIDE], int moveIndex){
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    for (int i = 0; i < SIDE; i++) 
        for (int j = 0; j < SIDE; j++) 
            if (board[i][j] == ' '){ 
                board[i][j] = COMPUTERMOVE;
                score = minimax(board, moveIndex + 1, false);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    x = i;
                    y = j;}  
            }
    
    return x * 3 + y;
}

