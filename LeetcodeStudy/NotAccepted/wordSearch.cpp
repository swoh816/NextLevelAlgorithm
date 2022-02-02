int visited[8][8];
char paddedBoard[8][8];

// int direction[][]
int recursiveFunction(char* word, char** paddedBoard, int** visited, int i, int j)
{
    ++word;
    if (paddedBoard[i+1][j] == *word && visited[i+1][j] != 1)
    {
        recursiveFunction(word, paddedBoard, visited, i+1, j);
    }
    else if (paddedBoard[i][j+1] == *word && visited[i][j+1] != 1)
    {
        recursiveFunction(word, paddedBoard, visited, i, j+1);
    }
    else if (paddedBoard[i-1][j] == *word && visited[i-1][j] != 1)
    {
        recursiveFunction(word, paddedBoard, visited, i-1, j);
    }
    else if (paddedBoard[i][j-1] == *word && visited[i][j-1] != 1)
    {
        recursiveFunction(word, paddedBoard, visited, i, j-1);
    }
    else
    {
        --word;
    }
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<*boardColSize; j++)
        {
            paddedBoard[i+1][j+1] = board[i][j];
        }
    }

    for(int i=1; i<=boardSize; i++)
    {
        for(int j=1; j<=*boardColSize; j++)
        {
            if (paddedBoard[i][j] == *word)
            {
                recursiveFunction(word, paddedBoard, visited, i, j);
            }
        }
    }

}