#include <stdio.h>

int check(int matri[9][9])
{
    for(int r=0; r<9; r++)
    {
        int linha[10] = {0};
        for(int s=0; s<9; s++)
        {
            int x = matri[r][s];
            if (x < 1 || x > 9 || linha[x] == 1)
            {
                return 0;
            }
            linha[x] = 1; 
            
        }
    }
    for(int t=0; t<9; t++)
    {
        int coluna[10] = {0};
        for(int u=0; u<9; u++)
        {
            int y = matri[t][u];
            if (y < 1 || y > 9 || coluna[y] == 1)
            {
                return 0; 
            }
            coluna[y] = 1;
        }
    }
    for (int boxB = 0; boxB < 3; boxB++) 
    {
        for (int boxC = 0; boxC < 3; boxC++) 
        {
            int submatri[10] = {0};
            for (int b = boxB * 3; b < (boxB + 1) * 3; b++) 
            {
                for (int c = boxC * 3; c < (boxC + 1) * 3; c++) 
                {
                    int z = matri[b][c];
                    if (z < 1 || z > 9 || submatri[z] == 1) 
                    {
                        return 0;
                    }
                    submatri[z] = 1;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    int matri[9][9];
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        for (int j = 0; j < 9; j++) 
        {
            for (int k = 0; k < 9; k++) 
            {
                scanf("%d", &matri[j][k]);
            }
        }
        printf("Instancia %d \n", i);
        if (check(matri) == 1) 
        {
            printf("SIM\n");
        } 
        else 
        {
            printf("NAO\n");
        }
    }
    return 0;
}