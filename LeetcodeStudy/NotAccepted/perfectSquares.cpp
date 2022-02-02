int queue[100];
int step = 1;
int queueIdx = 0;


// First in first out
typedef struct
{
    int diffInt;
    int currInt;
} Node;


int primeArray[25];
int endIdx = 0;

int isPrime(int p)
{
    for (int i=2; i<100; i++)
    {
        if (p%i == 0)
        {
            return -1;
        }
    }
    return 1;
}

int powerArray[25] = {0};

int isSquare(int n)
{
    if (n == 1)
    {
        return 1;
    }
    for(int primeIdx=0; primeIdx<endIdx-1; primeIdx++)
    {
        while (n%primeArray[primeIdx] == 0)
        {
            powerArray[primeIdx]++;
            n /= primeArray[primeIdx];
        }
        // If not square
        if (powerArray[primeIdx]%2 != 0)
        {
            return -1;
        }
        // If square
        else
        {
            // If n is no more divisible
            if (n == 1)
            {
                return 1;
            }
        }
    }
}

// st: step
// diffInt: n-\sum{squares of all preceding primes}
// pIdx: primeIdx
int returnStepBFS(int st, int diffInt, int pIdx)
{
    if (st != 0)
    {
        for(int i=pIdx; i < endIdx; i++)
        {
            returnStepBFS(st-1, diffInt-primeArray[pIdx]*primeArray[pIdx], i);
        }
    }
    else
    {
        // if (diffInt-primeArray[pIdx]*primeArray[pIdx] == 0)
        if (isSquare(diffInt-primeArray[pIdx]*primeArray[pIdx]))
        {
            return step;
        }
        
    }
}


int main()
{
    isSquare(10);
    return 0;
}


int numSquares(int n){
    for(int i=2; i<100; i++)
    {
        if(isPrime(i))
        {
            primeArray[endIdx] = i;
            endIdx++;
        }
    }

    // First in
    // First out
    int result;
    int temp = n;
    while(temp--)
    {
         returnStepBFS(step, n, 0);
    }
}