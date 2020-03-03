#include <iostream>
#include<string>
#include<stdlib.h>

using namespace std;

//#define TESTING

struct group
{
    int no_of_box;
    string name;
    string  direction;
    int address[8][2];
};

int k[4][4];
int table[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int combination = 0;
int no_of_grp = -1;
group g[80];

void _table()
{
    cout<<"+---------+---+\n";
    cout<<"| a b c d |   |\n";
    cout<<"+---------+---+\n";
    cout<<"| 0 0 0 0 | "<<table[0]<<" |\n";
    cout<<"| 0 0 0 1 | "<<table[1]<<" |\n";
    cout<<"| 0 0 1 0 | "<<table[2]<<" |\n";
    cout<<"| 0 0 1 1 | "<<table[3]<<" |\n";
    cout<<"| 0 1 0 0 | "<<table[4]<<" |\n";
    cout<<"| 0 1 0 1 | "<<table[5]<<" |\n";
    cout<<"| 0 1 1 0 | "<<table[6]<<" |\n";
    cout<<"| 0 1 1 1 | "<<table[7]<<" |\n";
    cout<<"| 1 0 0 0 | "<<table[8]<<" |\n";
    cout<<"| 1 0 0 1 | "<<table[9]<<" |\n";
    cout<<"| 1 0 1 0 | "<<table[10]<<" |\n";
    cout<<"| 1 0 1 1 | "<<table[11]<<" |\n";
    cout<<"| 1 1 0 0 | "<<table[12]<<" |\n";
    cout<<"| 1 1 0 1 | "<<table[13]<<" |\n";
    cout<<"| 1 1 1 0 | "<<table[14]<<" |\n";
    cout<<"| 1 1 1 1 | "<<table[15]<<" |\n";
    cout<<"+---------+---+\n";
}

void k_map_fill()
{
    k[0][0] = table[0];
    k[0][1] = table[1];
    k[0][2] = table[3];
    k[0][3] = table[2];

    k[1][0] = table[4];
    k[1][1] = table[5];
    k[1][2] = table[7];
    k[1][3] = table[6];

    k[2][0] = table[12];
    k[2][1] = table[13];
    k[2][2] = table[15];
    k[2][3] = table[14];

    k[3][0] = table[8];
    k[3][1] = table[9];
    k[3][2] = table[11];
    k[3][3] = table[10];
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
#ifdef TESTING
                    cout<<"Group 8 Row\n";
#endif
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 8;
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i ;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].address[2][0] = i ;
                    g[no_of_grp].address[2][1] = j+2;
                    g[no_of_grp].address[3][0] = i ;
                    g[no_of_grp].address[3][1] = j+3;
                    g[no_of_grp].address[4][0] = i+1;
                    g[no_of_grp].address[4][1] = j;
                    g[no_of_grp].address[5][0] = i+1;
                    g[no_of_grp].address[5][1] = j+1;
                    g[no_of_grp].address[6][0] = i+1;
                    g[no_of_grp].address[6][1] = j+2;
                    g[no_of_grp].address[7][0] = i+1;
                    g[no_of_grp].address[7][1] = j+3;
                    g[no_of_grp].name = "rectangle";
                    g[no_of_grp].direction = "horizontal";
                }
            }
            if(i == 0 && j<=2)
            {
                if(k[i][j] == 1 && k[i+1][j] == 1 && k[i+2][j] == 1 && k[i+3][j] == 1 && k[i][j+1] == 1 && k[i+1][j+1] == 1 && k[i+2][j+1] == 1 && k[i+3][j+1] == 1 )
                {
#ifdef TESTING
                    cout<<"Group 8 Column\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 8;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].address[2][0] = i+1;
                    g[no_of_grp].address[2][1] = j;
                    g[no_of_grp].address[3][0] = i+1;
                    g[no_of_grp].address[3][1] = j+1;
                    g[no_of_grp].address[4][0] = i+2;
                    g[no_of_grp].address[4][1] = j;
                    g[no_of_grp].address[5][0] = i+2;
                    g[no_of_grp].address[5][1] = j+1;
                    g[no_of_grp].address[6][0] = i+3;
                    g[no_of_grp].address[6][1] = j;
                    g[no_of_grp].address[7][0] = i+3;
                    g[no_of_grp].address[7][1] = j+1;
                    g[no_of_grp].name = "rectangle";
                    g[no_of_grp].direction = "vertical";
                }
            }
            if( i == 3 && j  == 0)
            {
                if(k[i][j] == 1 && k[i][j+1] == 1 && k[i][j+2] == 1 && k[i][j+3] == 1 && k[i-3][j] == 1 && k[i-3][j+1] == 1 && k[i-3][j+2] == 1 && k[i-3][j+3] == 1 )
                {
#ifdef TESTING
                    cout<<"Group 8 Row Horizontal\n";
#endif // TESTING
                    combination = combination + 1;
                    g[no_of_grp].no_of_box = 8;
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i ;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].address[2][0] = i ;
                    g[no_of_grp].address[2][1] = j+2;
                    g[no_of_grp].address[3][0] = i ;
                    g[no_of_grp].address[3][1] = j+3;
                    g[no_of_grp].address[4][0] = i-3;
                    g[no_of_grp].address[4][1] = j;
                    g[no_of_grp].address[5][0] = i-3;
                    g[no_of_grp].address[5][1] = j+1;
                    g[no_of_grp].address[6][0] = i-3;
                    g[no_of_grp].address[6][1] = j+2;
                    g[no_of_grp].address[7][0] = i-3;
                    g[no_of_grp].address[7][1] = j+3;
                    g[no_of_grp].name = "rectangle row";
                    g[no_of_grp].direction = "horizontal";
                }
            }
            if( i == 3 && j  == 0)
            {
                if(k[i][j] == 1 && k[i-1][j] == 1 && k[i-2][j] == 1 && k[i-3][j] == 1 && k[i][j+3] == 1 && k[i-1][j+3] == 1 && k[i-2][j+3] == 1 && k[i-3][j+3] == 1 )
                {
#ifdef TESTING
                    cout<<"Group 8 Column Vertical\n";
#endif // TESTING
                    combination = combination + 1;
                    g[no_of_grp].no_of_box = 8;
                    g[no_of_grp].address[0][0] = i-3;
                    g[no_of_grp].address[0][1] = j+3;
                    g[no_of_grp].address[1][0] = i-3;
                    g[no_of_grp].address[1][1] = j;

                    g[no_of_grp].address[2][0] = i-2;
                    g[no_of_grp].address[2][1] = j+3;
                    g[no_of_grp].address[3][0] = i-2;
                    g[no_of_grp].address[3][1] = j;

                    g[no_of_grp].address[4][0] = i-1;
                    g[no_of_grp].address[4][1] = j+3;
                    g[no_of_grp].address[5][0] = i-1;
                    g[no_of_grp].address[5][1] = j;

                    g[no_of_grp].address[6][0] = i;
                    g[no_of_grp].address[6][1] = j+3;
                    g[no_of_grp].address[7][0] = i;
                    g[no_of_grp].address[7][1] = j;
                    g[no_of_grp].name = "rectangle column";
                    g[no_of_grp].direction = "vertical";
                }
            }
            /* Group 4 Square*/
            if(j<=2 && i<=2)
            {
                if(k[i][j] == 1 && k[i][j+1]==1 && k[i+1][j] == 1 && k[i+1][j+1] == 1 )
                {
#ifdef TESTING
                    cout<<"Group 4 square\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 4;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].address[2][0] = i+1;
                    g[no_of_grp].address[2][1] = j;
                    g[no_of_grp].address[3][0] = i+1;
                    g[no_of_grp].address[3][1] = j+1;
                    g[no_of_grp].name = "square";
                    g[no_of_grp].direction = "none";
                }
            }
            if(j == 3 && i <=2)
            {
                if(k[i][j] == 1 && k[i+1][j] == 1 && k[i][j-3] == 1 && k[i+1][j-3])
                {
#ifdef TESTING
                    cout<<"Group 4 Square Horizontal\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 4;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i;
                    g[no_of_grp].address[1][1] = j-3;
                    g[no_of_grp].address[2][0] = i+1;
                    g[no_of_grp].address[2][1] = j;
                    g[no_of_grp].address[3][0] = i+1;
                    g[no_of_grp].address[3][1] = j-3;
                    g[no_of_grp].name = "square row";
                    g[no_of_grp].direction = "none";
                }
            }
            if(i == 0 && j <= 2)
            {
                if(k[i][j] ==  1 && k[i][j+1] == 1 && k[i+3][j] == 1 && k[i+3][j+1] == 1)
                {
#ifdef TESTING
                    cout<<"Group 4 Square Vertical\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 4;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].address[2][0] = i+3;
                    g[no_of_grp].address[2][1] = j;
                    g[no_of_grp].address[3][0] = i+3;
                    g[no_of_grp].address[3][1] = j+1;
                    g[no_of_grp].name = "square column";
                    g[no_of_grp].direction = "none";
                }
            }
            if( i == 0 && j == 3 )
            {
                if(k[i][j] ==  1 && k[i+3][j]==1 && k[i][j-3] == 1 && k[i+3][j-3] == 1)
                {
#ifdef TESTING
                    cout<<"Group 4 Square four corners\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 4;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i;
                    g[no_of_grp].address[1][1] = j-3;
                    g[no_of_grp].address[2][0] = i+3;
                    g[no_of_grp].address[2][1] = j;
                    g[no_of_grp].address[3][0] = i+3;
                    g[no_of_grp].address[3][1] = j-3;
                    g[no_of_grp].name = "square corner";
                    g[no_of_grp].direction = "none";
                }
            }
            /* Group 4 Rectangle*/
            if(i < 4 && j == 0)
            {
                if(k[i][j] == 1 && k[i][j+1]== 1 && k[i][j+2] == 1 && k[i][j+3] == 1)
                {
#ifdef TESTING
                    cout<<"Group 4 Rectangle Row\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 4;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].address[2][0] = i;
                    g[no_of_grp].address[2][1] = j+2;
                    g[no_of_grp].address[3][0] = i;
                    g[no_of_grp].address[3][1] = j+3;
                    g[no_of_grp].name = "rectangle";
                    g[no_of_grp].direction = "horizontal";
                }
            }
            if(i == 0 && j <4)
            {
                if(k[i][j] == 1 && k[i+1][j]== 1 && k[i+2][j] == 1 && k[i+3][j] == 1)
                {
#ifdef TESTING
                    cout<<"Group 4 Rectangle Column\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 4;
                    g[no_of_grp].address[0][0] = i;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i+1;
                    g[no_of_grp].address[1][1] = j;
                    g[no_of_grp].address[2][0] = i+2;
                    g[no_of_grp].address[2][1] = j;
                    g[no_of_grp].address[3][0] = i+3;
                    g[no_of_grp].address[3][1] = j;
                    g[no_of_grp].name = "rectangle";
                    g[no_of_grp].direction = "vertical";
                }
            }
            /* Group 2 Row*/
            if(i < 4 && j<=2 )
            {
                if(k[i][j]==1 && k[i][j+1]==1)
                {
#ifdef TESTING
                    cout<<"Group 2 Row\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 2;
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i ;
                    g[no_of_grp].address[1][1] = j+1;
                    g[no_of_grp].name = "duo";
                    g[no_of_grp].direction = "horizontal";
                }
            }
            if(i < 4 && j == 3)
            {
                if(k[i][j]==1 && k[i][j-3]==1)
                {
#ifdef TESTING
                    cout<<"Group 2 Row Horizontal\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 2;
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i ;
                    g[no_of_grp].address[1][1] = j-3;
                    g[no_of_grp].name = "duo row";
                    g[no_of_grp].direction = "horizontal";
                }
            }
            /* Group 2 Column*/
            if(i <= 2 && j<4 )
            {
                if(k[i][j]==1 && k[i+1][j]==1)
                {
#ifdef TESTING
                    cout<<"Group 2 Column\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 2;
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i+1 ;
                    g[no_of_grp].address[1][1] = j;
                    g[no_of_grp].name = "duo";
                    g[no_of_grp].direction = "vertical";
                }
            }
            if(i == 3 && j < 4)
            {
                if(k[i][j]==1 && k[i-3][j]==1)
                {
#ifdef TESTING
                    cout<<"Group 2 Column Vertical\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 2;
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                    g[no_of_grp].address[1][0] = i-3 ;
                    g[no_of_grp].address[1][1] = j;
                    g[no_of_grp].name = "duo column";
                    g[no_of_grp].direction = "vertical";
                }
            }
            /*Group 1*/
            if ( i < 4 && j < 4)
            {
                if(k[i][j] == 1)
                {
#ifdef TESTING
                    cout<<"Group 1\n";
#endif // TESTING
                    combination = combination + 1;
                    no_of_grp = no_of_grp + 1;
                    g[no_of_grp].no_of_box = 1;
                    g[no_of_grp].name = "single";
                    g[no_of_grp].direction = "none";
                    g[no_of_grp].address[0][0] = i ;
                    g[no_of_grp].address[0][1] = j;
                }
            }
        }
    }
}

void k_map_fill(int n)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            k[i][j] = 1;
        }
    }
}

/*TESTINGing Function*/
#ifdef TESTING
void groups()
{
    for(int i=0; i<=no_of_grp; i++)
    {
        cout<<g[i].name<<"\n";
        cout<<g[i].direction<<"\n";
        cout<<g[i].no_of_box<<"\n";
        cout<<"-------------------\n";
    }
}
#endif // TESTING

void sort_grp()
{
    group temp;
    for(int i=0; i<=no_of_grp; i++)
    {
        for(int j= i+1; j<=no_of_grp; j++)
        {
            if(g[i].no_of_box < g[j].no_of_box )
            {
                temp = g[i];
                g[i] = g[j];
                g[j] = temp;
            }
        }
    }
}

void grp_selector()
{
    sort_grp();
    /* Code optimization not done*/
    for(int i=0; i<=no_of_grp; i++)
    {
        for(int j = i + 1; j<=no_of_grp; j++)
        {
            if(g[i].no_of_box == 8 && g[j].no_of_box == 1)
            {
                for(int l=0; l<8; l++)
                {
                    if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1])
                    {
                        g[j].no_of_box = 0;
                    }
                }
            }
            if(g[i].no_of_box == 8 && g[j].no_of_box == 2)
            {
                if(g[i].direction == "horizontal")
                {
                    if(g[i].name == "rectangle")
                    {
                        if(g[j].direction == "horizontal" && g[j].name == "duo")
                        {
                            for(int m=0; m<3; m++)
                            {
                                if(g[i].address[m][0] == g[j].address[0][0] && g[i].address[m][1] == g[j].address[0][1] && g[i].address[m+1][0] == g[j].address[1][0] && g[i].address[m+1][1] == g[j].address[1][1])
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                            for(int l=4; l<7; l++)
                            {
                                if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+1][0] == g[j].address[1][0] && g[i].address[l+1][1] == g[j].address[1][1])
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        if(g[j].direction == "vertical" && g[j].name == "duo")
                        {
                            for(int l=0; l<4; l++)
                            {
                                if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+4][0] == g[j].address[1][0] && g[i].address[l+4][1] == g[j].address[1][1])
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        /*Optimized Code*/
                        if(g[j].direction == "horizontal" && g[j].name == "duo row")
                        {

                            if(g[i].address[0][0] == g[j].address[0][0] || g[i].address[4][0] == g[j].address[0][0] )
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        /* end */
                    }
                    if(g[i].name == "rectangle row")
                    {
                        /*Optimized Code*/
                        if(g[j].name == "duo")
                        {
                            if(g[j].address[0][0] == 0 || g[j].address[0][0] == 3)
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        if(g[j].name == "duo row")
                        {
                            if(g[j].address[0][0] == 0 || g[j].address[0][0] == 3)
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        if(g[j].name == "duo column")
                        {
                            g[j].no_of_box = 0;
                        }
                        /* end */
                    }
                }
                if(g[i].direction == "vertical")
                {
                    if(g[i].name =="rectangle")
                    {
                        if(g[j].direction == "horizontal" && g[j].name == "duo")
                        {
                            for(int l=0; l<4; l++)
                            {
                                if(g[i].address[l*2 + 0][0] == g[j].address[0][0] && g[i].address[l*2+0][1] == g[j].address[0][1] && g[i].address[l*2+1][0] == g[j].address[1][0] && g[i].address[l*2+1][1] == g[j].address[1][1])
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        if(g[j].direction == "vertical" && g[j].name == "duo")
                        {
                            for(int l=0; l<=6; l++)
                            {
                                if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+2][0] == g[j].address[1][0] && g[i].address[l+2][1] == g[j].address[1][1])
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        if(g[j].direction == "vertical" && g[j].name == "duo column")
                        {

                            if(g[i].address[0][1] == g[j].address[0][1] || g[i].address[1][1] == g[j].address[0][1] )
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                    }
                    if(g[i].name == "rectangle column")
                    {
                        /*Optimized Code*/
                        if(g[j].name == "duo")
                        {
                            if(g[j].address[0][1] == 0 || g[j].address[0][1] == 3)
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        if(g[j].name == "duo row")
                        {
                            g[j].no_of_box = 0;
                        }
                        if(g[j].name == "duo column")
                        {
                            if(g[j].address[0][1] == 0 || g[j].address[0][1]== 3)
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        /* end */
                    }
                }
            }
            if(g[i].no_of_box == 8 && g[j].no_of_box == 4)
            {
                if(g[i].name == "rectangle")
                {
                    if(g[i].direction =="horizontal")
                    {
                        if(g[j].name == "square")
                        {
                            if(g[j].direction == "none")
                            {
                                for(int l=0; l<3; l++)
                                {
                                    if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+1][0] == g[j].address[1][0] && g[i].address[l+1][1] == g[j].address[1][1] && g[i].address[l+4][0] == g[j].address[2][0] && g[i].address[l+4][1] == g[j].address[2][1] && g[i].address[l+5][0] == g[j].address[3][0] && g[i].address[l+5][1] == g[j].address[3][1] )
                                    {
                                        g[j].no_of_box = 0;
                                    }
                                }
                            }
                        }
                        if(g[j].name == "square row")
                        {
                            if(g[j].address[0][0] == g[i].address[0][0])
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                    }
                    if(g[i].direction =="vertical")
                    {
                        if(g[j].name == "square")
                        {
                            if(g[j].direction == "none")
                            {
                                for(int l=0; l<3; l++)
                                {
                                    if(g[i].address[l*2+0][0] == g[j].address[0][0] && g[i].address[l*2+0][1] == g[j].address[0][1] && g[i].address[l*2+1][0] == g[j].address[1][0] && g[i].address[l*2+1][1] == g[j].address[1][1] && g[i].address[l*2+2][0] == g[j].address[2][0] && g[i].address[l*2+2][1] == g[j].address[2][1] && g[i].address[l*2+3][0] == g[j].address[3][0] && g[i].address[l*2+3][1] == g[j].address[3][1] )
                                    {
                                        g[j].no_of_box = 0;
                                    }
                                }
                            }
                        }
                        if(g[j].name == "square column")
                        {
                            if(g[j].address[0][1] == g[i].address[0][1])
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                    }
                    if(g[j].name == "rectangle")
                    {
                        if(g[j].direction == "horizontal" && g[i].direction == "horizontal")
                        {
                            for(int l=0; l<2; l++)
                            {
                                if(g[i].address[l*4 + 0][0] == g[j].address[0][0] && g[i].address[l*4 + 0][1] == g[j].address[0][1] && g[i].address[l*4 + 1][0] == g[j].address[1][0] && g[i].address[l*4 + 1][1] == g[j].address[1][1] && g[i].address[l*4 + 2][0] == g[j].address[2][0] && g[i].address[l*4 + 2][1] == g[j].address[2][1] && g[i].address[l*4 + 3][0] == g[j].address[3][0] && g[i].address[l*4 + 3][1] == g[j].address[3][1] )
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        if(g[j].direction == "vertical" && g[i].direction == "vertical")
                        {
                            for(int l=0; l<2; l++)
                            {
                                if(g[i].address[l+0][0] == g[j].address[0][0] && g[i].address[l+0][1] == g[j].address[0][1] &&  g[i].address[l+2][0] == g[j].address[1][0] && g[i].address[l+2][1] == g[j].address[1][1]&&  g[i].address[l+4][0] == g[j].address[2][0] && g[i].address[l+4][1] == g[j].address[2][1]&& g[i].address[l+6][0] == g[j].address[3][0] && g[i].address[l+6][1] == g[j].address[3][1])
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                    }
                }
                if(g[i].name == "rectangle row")
                {
                    if(g[j].name == "square column")
                    {
                        g[j].no_of_box = 0;
                    }
                    if(g[j].name == "rectangle" && g[j].direction == "horizontal")
                    {
                        if(g[j].address[0][0] == 0 || g[j].address[0][0] == 3)
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    if(g[j].name == "square corner")
                    {
                        g[j].no_of_box = 0;
                    }
                }
                if(g[i].name == "rectangle column")
                {
                    if(g[j].name == "square row")
                    {
                        g[j].no_of_box = 0;
                    }
                    if(g[j].name =="rectangle" && g[j].direction == "vertical")
                    {
                        if(g[j].address[0][1] == 0 || g[j].address[0][1] == 3)
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    if(g[j].name == "square corner")
                    {
                        g[j].no_of_box = 0;
                    }
                }
            }
            if(g[i].no_of_box ==  4 && g[j].no_of_box == 1)
            {
                for(int l=0; l<4; l++)
                {
                    if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1])
                    {
                        g[j].no_of_box = 0;
                    }
                }
            }
            if(g[i].no_of_box ==  4 && g[j].no_of_box == 2)
            {
                if(g[i].name == "square")
                {
                    if(g[j].direction  == "horizontal")
                    {
                        if(g[i].address[0][0] == g[j].address[0][0] && g[i].address[0][1] == g[j].address[0][1] && g[i].address[1][0] == g[j].address[1][0] && g[i].address[1][1] == g[j].address[1][1])
                        {
                            g[j].no_of_box = 0;
                        }
                        if(g[i].address[2][0] == g[j].address[0][0] && g[i].address[2][1] == g[j].address[0][1] && g[i].address[3][0] == g[j].address[1][0] && g[i].address[3][1] == g[j].address[1][1])
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    if(g[j].direction  == "vertical")
                    {
                        if(g[i].address[0][0] == g[j].address[0][0] && g[i].address[0][1] == g[j].address[0][1] && g[i].address[2][0] == g[j].address[1][0] && g[i].address[2][1] == g[j].address[1][1])
                        {
                            g[j].no_of_box = 0;
                        }
                        if(g[i].address[1][0] == g[j].address[0][0] && g[i].address[1][1] == g[j].address[0][1] && g[i].address[3][0] == g[j].address[1][0] && g[i].address[3][1] == g[j].address[1][1])
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                }
                else if(g[i].name == "square row")
                {
                    /*Optimized code*/
                    if(g[j].name == "duo row")
                    {
                        if(g[i].address[0][0] == g[j].address[0][0] || g[i].address[2][0] == g[j].address[0][0])
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    if(g[j].name == "duo" && g[j].direction == "vertical")
                    {
                        if((g[i].address[0][0] == g[j].address[0][0] && g[i].address[0][1] == g[j].address[0][1]) || (g[i].address[1][0] == g[j].address[0][0] && g[i].address[1][1] == g[j].address[0][1]))
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    /*End*/
                }
                else if(g[i].name == "rectangle")
                {
                    if(g[j].direction == "horizontal" && g[i].direction == "horizontal")
                    {
                        if(g[j].name == "duo")
                        {
                            for(int l=0; l<3; l++)
                            {
                                if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+1][0] == g[j].address[1][0] && g[i].address[l+1][1] == g[j].address[1][1] )
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        /*Optimized */
                        else if(g[j].name == "duo row")
                        {
                            if(g[i].address[0][0] == g[j].address[0][0])
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        /*End*/

                    }
                    if(g[j].direction == "vertical" && g[i].direction == "vertical")
                    {
                        if(g[j].name == "duo")
                        {
                            for(int l=0; l<3; l++)
                            {
                                if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+1][0] == g[j].address[1][0] && g[i].address[l+1][1] == g[j].address[1][1] )
                                {
                                    g[j].no_of_box = 0;
                                }
                            }
                        }
                        /*Code Optimized*/
                        else if(g[j].name == "duo column")
                        {
                            if(g[i].address[0][1] == g[j].address[0][1])
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                        /*end*/

                    }
                }
                if(g[i].name == "square corner")
                {
                    /*Code Optimized*/
                    if(g[j].name == "duo row")
                    {
                        if(g[j].address[0][0] == 0 || g[j].address[0][0] == 3)
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    else if(g[j].name == "duo column")
                    {
                        if(g[j].address[0][1] == 0 || g[j].address[0][1] == 3)
                        {
                            g[j].no_of_box = 0;
                        }
                    }
                    /*end*/
                }
            }
            if(g[i].no_of_box ==  2 && g[j].no_of_box == 1)
            {
                if((g[i].address[0][0] == g[j].address[0][0] && g[i].address[0][1] == g[j].address[0][1]) || ( g[i].address[1][0] == g[j].address[0][0] && g[i].address[1][1] == g[j].address[0][1]))
                {
                    g[j].no_of_box = 0;
                }
            }
        }
    }
    sort_grp();

    for(int i=0; i<=no_of_grp; i++)
    {
        if(g[i].no_of_box == 0)
        {
            no_of_grp = i - 1;
            break;
        }
    }
}
/*Under Development*/
void expression()
{
    for(int i=0; i<=no_of_grp; i++)
    {
        if(g[i].no_of_box == 8)
        {
            if(g[i].direction == "horizontal")
            {
                if(g[i].address[0][0] == 0 && g[i].address[4][0] == 1)
                {
                    cout<<"a'b'c'd'";
                    if(i != no_of_grp)
                    {
                        cout<<" + ";
                    }
                }
            }
        }
        if(g[i].no_of_box == 1)
        {
            if(g[i].address[0][0] == 0 && g[i].address[0][1] == 0)
            {
                cout<<"a'b'c'd'";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 0 && g[i].address[0][1] == 1)
            {
                cout<<"a'b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 0 && g[i].address[0][1] == 2)
            {
                cout<<"a'b'c d ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 0 && g[i].address[0][1] == 3)
            {
                cout<<"a'b'c d'";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 1 && g[i].address[0][1] == 0)
            {
                cout<<"a'b c'd'";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 1 && g[i].address[0][1] == 1)
            {
                cout<<"a'b c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 1 && g[i].address[0][1] == 2)
            {
                cout<<"a'b c d ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 1 && g[i].address[0][1] == 3)
            {
                cout<<"a'b c d'";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 2 && g[i].address[0][1] == 0)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 2 && g[i].address[0][1] == 1)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 2 && g[i].address[0][1] == 2)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 2 && g[i].address[0][1] == 3)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 3 && g[i].address[0][1] == 0)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 3 && g[i].address[0][1] == 1)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 3 && g[i].address[0][1] == 2)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
            else if(g[i].address[0][0] == 3 && g[i].address[0][1] == 3)
            {
                cout<<"a b'c'd ";
                if(i != no_of_grp)
                {
                    cout<<" + ";
                }
            }
        }
    }

}

void input()
{
    int n=0;
    char choice = 'y';
#ifdef TESTING
    while(choice != 'n')
    {
        cout<<"Enter minterms \n";
        cin>>n;
        table[n]=1;
        cout<<"Do you want to enter more minterms\n";
        cin>>choice;
    }
#endif // TESTING

}

void menu()
{
    int choice = 0;
    while(choice != 5)
    {
        system("cls");
        cout<<"==================================================\n";
        cout<<"                    MENU\n";
        cout<<"==================================================\n";
        cout<<"[1]Solve SOP\n";
        cout<<"[2]Fill Table\n";
        cout<<"[3]Fill K Map\n";
        cout<<"[4]Help\n";
        cout<<"[5]Exit\n";
        cout<<"::";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Working!\n";
            break;
        default :
            cout<<"Invalid Choice Try again!\n";
            cout<<"or press 4 for help\n";
            system("pause");
        }
    }
}
int main(int argc, char *argv[])
{
#ifndef TESTING
    menu();
#endif // TESTING
#ifdef TESTING
    input();
    _table();
    k_map_fill();
    k_map_display();
    k_map_solver();
    grp_selector();
    cout<<"Groups after selection\n";
    groups();
#endif
    return 0;
}
