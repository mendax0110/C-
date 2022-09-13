/*forked and rewritten by me
 *original code by: Yiyou(Gerry) Chen / gerry99@ucla.edu
 */

/*include the header files*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<int, int> now, pre;
double mat[1002][1002];
double value;
char symbol;

/*function for reading the input*/
void READ()
{
    /*read the number of nodes*/
    cout << "Please give the number of loops you wish to run: ";
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        /*read the number of items in one loop*/
        cout << endl << "Please give the number of items in loop(top to down order)" << i << ":";
        cin >> m;

        /*give all the items in the loop*/
        cout << endl << "Please give all the items in the loop" << i << "(U for battery, R for Resistor left-right order, :| is positive Battery, and |: is negative. EXAMPLE: U -5 R 2):";

        /*read the items*/
        for(int j = 1; j <= m; ++j)
        {
            cin >> symbol >> value;

            if(symbol == 'U')
            {
                mat[i][n + 1] += value;
            }
            else if(symbol == 'R')
            {
                mat[i][i] -= value;
            }
        }
    }
    
    
    for(int i = 1; i < n; ++i)
    {
        mat[i][n + 1] -= mat[n][n + 1];
        mat[i][n] += mat[n][n];
    }

    for(int i = 1; i < n; ++i)
    {
        mat[n][i] = 1;
    }

    mat[n][n] = -1; mat[n][n + 1] = 0;
    for(int i = 1; i <= n; ++i)
    {
        now[i] = i;
        pre[i] = i;
    }
}

/*function for the gauss elimination*/
void GAUSS()
{
    for(int i = 1; i <= n; ++i)
    {
        double maxt = -1;
        int rowt    = 0;

        for(int j = i; j <= n; ++j)
        {
            if(abs(mat[j][j]) > maxt)
            {
                maxt = abs(mat[j][j]);
                rowt = j;
            }
        }

        now[pre[i]] = rowt;
        now[pre[rowt]] = i;
        swap(pre[i], pre[rowt]);

        for(int j = 1; j <= n + 1; ++j)
        {
            swap(mat[i][j], mat[rowt][j]);
        }

        double scale = mat[i][i];
        for(int j = 1; j <= n + 1; ++j)
        {
            mat[i][j] /= scale;
        }

        for(int j = 1; j <= n; ++j)
        {
            if(j == i) continue;
            double time = mat[j][i];
            for(int k = 1; k <= n + 1; ++k)
            {
                mat[j][k] -= time * mat[i][k];
            }
        }
    }
}

/*function for printing the result*/
void PRINT_OUTPUT()
{
    /*print the result*/
    cout << "Currents in the loops are (- does mean going from right to left): " << endl;

    for(int i = 1; i < n; ++i)
    {   
        /*print the current in the loop*/
        cout << "The current in loop" << i << ": " << -mat[now[i]][n + 1] << 'A' << endl;
    }

    cout << "The current in the loop" << n << ": " << mat[n][n + 1] << 'A' << endl;
}

/*main function*/
int main()
{
    READ();
    GAUSS();
    PRINT_OUTPUT();
    exit(0);
}