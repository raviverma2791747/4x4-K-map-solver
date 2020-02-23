#include <iostream>
#include<string>

using namespace std;

#define WORKZONE 0

struct group
{
    int no_of_box;
    string name;
    string  direction;
    int address[8][2];
};

int k[4][4];
int table[16][1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int combination = 0;
int no_of_grp = -1;
group g[80];

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
                    cout<<"Group 8 Column\n";
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
                    cout<<"Group 8 Column Vertical\n";
                    combination = combination + 1;
                }
            }
            if( i == 3 && j  == 0)
            {
                if(k[i][j] == 1 && k[i-1][j] == 1 && k[i-2][j] == 1 && k[i-3][j] == 1 && k[i][j+3] == 1 && k[i-1][j+3] == 1 && k[i-2][j+3] == 1 && k[i-3][j+3] == 1 )
                {
                    cout<<"Group 8 Row Horizontal\n";
                    combination = combination + 1;
                }
            }
            /* Group 4 Square*/
            if(j<=2 && i<=2)
            {
                if(k[i][j] == 1 && k[i][j+1]==1 && k[i+1][j] == 1 && k[i+1][j+1] == 1 )
                {
                    cout<<"Group 4 square\n";
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
                    cout<<"Group 4 Square Horizontal\n";
                    combination = combination + 1;
                }
            }
            if(i == 0 && j <= 2)
            {
                if(k[i][j] ==  1 && k[i][j+1] == 1 && k[i+3][j] == 1 && k[i+3][j+1] == 1)
                {
                    cout<<"Group 4 Square Vertical\n";
                    combination = combination + 1;
                }
            }
            if( i == 0 && j == 3 )
            {
                if(k[i][j] ==  1 && k[i+3][j]==1 && k[i][j-3] == 1 && k[i+3][j-3] == 1)
                {
                    cout<<"Group 4 Square four corners\n";
                    combination = combination + 1;
                }
            }
            /* Group 4 Rectangle*/
            if(i < 4 && j == 0)
            {
                if(k[i][j] == 1 && k[i][j+1]== 1 && k[i][j+2] == 1 && k[i][j+3] == 1)
                {
                    cout<<"Group 4 Rectangle Row\n";
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
                    cout<<"Group 4 Rectangle Column\n";
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
                    cout<<"Group 2 Row\n";
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
                    cout<<"Group 2 Row Horizontal\n";
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
                    cout<<"Group 2 Column\n";
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
                    cout<<"Group 2 Column Vertical\n";
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
                    cout<<"Group 1\n";
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

/*Tesring Function*/
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

void sort_grp()
{
    group temp;
    for(int i=0; i<=no_of_grp-1; i++)
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
                if(g[i].direction == "vertical")
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
                }
            }
            if(g[i].no_of_box == 8 && g[j].no_of_box == 4)
            {
                if(g[j].name == "square")
                {
                    if(g[j].direction == "none" && g[i].direction == "horizontal")
                    {
                        for(int l=0; l<3; l++)
                        {
                            if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+1][0] == g[j].address[1][0] && g[i].address[l+1][1] == g[j].address[1][1] && g[i].address[l+4][0] == g[j].address[2][0] && g[i].address[l+4][1] == g[j].address[2][1] && g[i].address[l+5][0] == g[j].address[3][0] && g[i].address[l+5][1] == g[j].address[3][1] )
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                    }
                    if(g[j].direction == "none" && g[i].direction == "vertical")
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
                        for(int l=0; l<3; l++)
                        {
                            if(g[i].address[l][0] == g[j].address[0][0] && g[i].address[l][1] == g[j].address[0][1] && g[i].address[l+1][0] == g[j].address[1][0] && g[i].address[l+1][1] == g[j].address[1][1] )
                            {
                                g[j].no_of_box = 0;
                            }
                        }
                    }
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
    cout<<combination<<"\n";
    sort_grp();
    groups();
    grp_selector();
    cout<<"\n Groups after selection \n";
    groups();
    expression();
    return 0;
}
