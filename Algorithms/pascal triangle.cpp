#define row 1000
#define col 1000
int nCp[row][col];
void pascal()
{
    for (int line = 0; line < row; line++)
    {
        for (int i = 0; i <= col; i++)
        {
            if (line == i || i == 0)
                nCp[line][i] = 1;
            else
                nCp[line][i] = nCp[line-1][i-1] + nCp[line-1][i];
        }
    }
}
