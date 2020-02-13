#include <iostream>

using namespace std;

int k[4][4];

int table[16][1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void _table()
{
    cout<<"+---------+---+\n";
    cout<<"| a b c d |   |\n";
    cout<<"+---------+---+\n";
    cout<<"| 0 0 0 0 | "<<table[0][0]<<" |\n";
    cout<<"| 0 0 0 1 | "<<table[1][0]<<" |\n";
    cout<<"| 0 0 1 0 | "<<table[2][0]<<" |\n";
    cout<<"| 0 0 1 1 | "<<table[3][0]<<" |\n";
    cout<<"| 0 1 0 0 | "<<table[4][0]<<" |\n";
    cout<<"| 0 1 0 1 | "<<table[5][0]<<" |\n";
    cout<<"| 0 1 1 0 | "<<table[6][0]<<" |\n";
    cout<<"| 0 1 1 1 | "<<table[7][0]<<" |\n";
    cout<<"| 1 0 0 0 | "<<table[8][0]<<" |\n";
    cout<<"| 1 0 0 1 | "<<table[9][0]<<" |\n";
    cout<<"| 1 0 1 0 | "<<table[10][0]<<" |\n";
    cout<<"| 1 0 1 1 | "<<table[11][0]<<" |\n";
    cout<<"| 1 1 0 0 | "<<table[12][0]<<" |\n";
    cout<<"| 1 1 0 1 | "<<table[13][0]<<" |\n";
    cout<<"| 1 1 1 0 | "<<table[14][0]<<" |\n";
    cout<<"| 1 1 1 1 | "<<table[15][0]<<" |\n";
    cout<<"+---------+---+\n";
}

void k_map_fill()
{
    k[0][0] = table[0][0];
    k[0][1] = table[1][0];
    k[0][2] = table[3][0];
    k[0][3] = table[2][0];

    k[1][0] = table[4][0];
    k[1][1] = table[5][0];
    k[1][2] = table[7][0];
    k[1][3] = table[6][0];

    k[2][0] = table[12][0];
    k[2][1] = table[13][0];
    k[2][2] = table[15][0];
    k[2][3] = table[14][0];

    k[3][0] = table[8][0];
    k[3][1] = table[9][0];
    k[3][2] = table[11][0];
    k[3][3] = table[10][0];
}

void k_map_display()
{
    cout<<"       c'd'   c'd    c d    c d'\n";
    cout<<"       0 0    0 1    1 1    1 0 \n";
    cout<<"     +------+------+------+------+\n";
    cout<<"a'b' |   "<<k[0][0]<<"  |   "<<k[0][1]<<"  |   "<<k[0][2]<<"  |   "<<k[0][3]<<"  |\n";
    cout<<"0 0  |      |      |      |      |\n";
    cout<<"     +------+------+------+------+\n";
    cout<<"a'b  |   "<<k[1][0]<<"  |   "<<k[1][1]<<"  |   "<<k[1][2]<<"  |   "<<k[1][3]<<"  |\n";
    cout<<"0 1  |      |      |      |      |\n";
    cout<<"     +------+------+------+------+\n";
    cout<<"a b  |   "<<k[2][0]<<"  |   "<<k[2][1]<<"  |   "<<k[2][2]<<"  |   "<<k[2][3]<<"  |\n";
    cout<<"1 1  |      |      |      |      |\n";
    cout<<"     +------+------+------+------+\n";
    cout<<"a b' |   "<<k[3][0]<<"  |   "<<k[3][1]<<"  |   "<<k[3][2]<<"  |   "<<k[3][3]<<"  |\n";
    cout<<"1 0  |      |      |      |      |\n";
    cout<<"     +------+------+------+------+\n";
}

void k_map_solver()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {

             /* Group 8 */
             if( i <=2 && j == 0)
             {
                 if(k[i][j] == 1 && k[i][j+1] == 1 && k[i][j+2] == 1 && k[i][j+3] == 1 && k[i+1][j] == 1 && k[i+1][j+1] == 1 && k[i+1][j+2] == 1 && k[i+1][j+3] == 1 )
                 {
                     cout<<"Group 8 Row\n";
                 }
             }
             if(i == 0 && j<=2)
             {
                 if(k[i][j] == 1 && k[i+1][j] == 1 && k[i+2][j] == 1 && k[i+3][j] == 1 && k[i][j+1] == 1 && k[i+1][j+1] == 1 && k[i+2][j+1] == 1 && k[i+3][j+1] == 1 )
                 {
                     cout<<"Group 8 Column\n";
                 }
             }
             if( i == 3 && j  == 0)
             {
                 if(k[i][j] == 1 && k[i][j+1] == 1 && k[i][j+2] == 1 && k[i][j+3] == 1 && k[i-3][j] == 1 && k[i-3][j+1] == 1 && k[i-3][j+2] == 1 && k[i-3][j+3] == 1 )
                 {
                     cout<<"Group 8 Column Vertical\n";
                 }
             }
             if( i == 3 && j  == 0)
             {
                 if(k[i][j] == 1 && k[i-1][j] == 1 && k[i-2][j] == 1 && k[i-3][j] == 1 && k[i][j+3] == 1 && k[i-1][j+3] == 1 && k[i-2][j+3] == 1 && k[i-3][j+3] == 1 )
                 {
                     cout<<"Group 8 Row Horizontal\n";
                 }
             }
             /* Group 4 Square*/
            if(j<=2 && i<=2)
            {
                if(k[i][j] == 1 && k[i][j+1]==1 && k[i+1][j] == 1 && k[i+1][j+1] == 1 )
                {
                    cout<<"Group 4 square\n";
                }
            }
             if(j == 3 && i <=2)
            {
                if(k[i][j] == 1 && k[i+1][j] == 1 && k[i][j-3] == 1 && k[i+1][j-3])
                {
                cout<<"Group 4  Square Horizontal\n";
                }
            }
            if(i == 0 && j <= 2)
            {
                if(k[i][j] ==  1 && k[i][j+1] == 1 && k[i+3][j] == 1 && k[i+3][j+1] == 1)
                {
                    cout<<"Group 4 Square Vertical\n";
                }
            }
            if( i == 0 && j == 3 )
            {
                if(k[i][j] ==  1 && k[i+3][j]==1 && k[i][j-3] == 1 && k[i+3][j-3] == 1)
                {
                    cout<<"Group 4 Square four corners\n";
                }
            }
            /* Group 4 Rectangle*/
            if(i < 4 && j == 0)
            {
                if(k[i][j] == 1 && k[i][j+1]== 1 && k[i][j+2] == 1 && k[i][j+3] == 1)
                {
                    cout<<"Group 4 Rectangle Row\n";
                }
            }
            if(i == 0 && j <4)
            {
                if(k[i][j] == 1 && k[i+1][j]== 1 && k[i+2][j] == 1 && k[i+3][j] == 1)
                {
                    cout<<"Group 4 Rectangle Column\n";
                }
            }
            /* Group 2 Row*/
            if(i < 4 && j<=2 )
            {
                if(k[i][j]==1 && k[i][j+1]==1)
                {
                    cout<<"Group 2 Row\n";
                }
            }
            if(i < 4 && j == 3)
            {
                if(k[i][j]==1 && k[i][j-3]==1)
                {
                    cout<<"Group 2 Row Horizontal\n";
                }
            }
            /* Group 2 Column*/
             if(i <= 2 && j<4 )
            {
                if(k[i][j]==1 && k[i+1][j]==1)
                {
                    cout<<"Group 2 Column\n";
                }
            }
            if(i == 3 && j < 4)
            {
                if(k[i][j]==1 && k[i-3][j]==1)
                {
                    cout<<"Group 2 Column Vertical\n";
                }
            }


        }
    }
}


int main()
{
    int n=0;
    char choice = 'y';
    while(choice != 'n')
    {
        cout<<"Enter minterms \n";
        cin>>n;
        table[n][0]=1;
        cout<<"Do you want to enter more minterms\n";
        cin>>choice;
    }
    _table();
    k_map_fill();
    k_map_display();
    k_map_solver();
    return 0;
}
