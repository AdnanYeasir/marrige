//Adnan Yeasir

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int man)
{
    int mp[3][3] = {{0, 2, 1}, // man preference 
                    {0, 2, 1},
                    {1, 2, 0}};
    int wp[3][3] = {{2, 1, 0},   //woman preference
                    {0, 1, 2},
                    {2, 0, 1}};
    int i;
    
    for (i = 0; i < man; i++) 
    {

        if (q[i] == q[man]) // basically row test
            return false; // cant repeat woman
    }
    for (i = 0; i < man; i++)
    //q[i] = cw
    // q[man]= nw
    // i = cm
    // man = nm
    {
        if ((mp[man][q[i]] < mp[man][q[man]]) && (wp[q[i]][man] < wp[q[i]][i]))// we are checking if the current man preferes the new woman to his partner and if the new woman prefers the current man to her partner.
         //     nm/cw    likes more       nm/nw        cw/nm   likes more        cw/cm
            return false; // if so we reject
        if ((wp[q[man]][i] < wp[q[man]][man]) && (mp[i][q[man]] < mp[i][q[i]]))  // if the new man preferes the current woman over his partner and if the current woman prefers the new man to her parter
         //   nw/cm      likes more nw/nm         cm/nw like more     cm/cw   
            return false; // if so we reject     
    }
    return true; // else we don't reject
}

void backtrack(int &c)
{
    c--;         // go back a man
    if (c == -1) // we have found all the solution
    {
        cout << " No more solutions" << endl;
        exit(0);
    }
}

void print(int q[])
{
    static int solution = 1;
    cout << "Solution # " << solution++ << endl;
    for (int i = 0; i < 3; i++)
        cout << "man " << i << " is sexually attracted to woman " << q[i] << endl; // please don't take points away
    cout << endl;
}

int main()
{
    int q[3] = {0}; // we set everything to 0 so we start with first male
    int man = 0;
    q[0] = 0;

    while (man >= 0) // while man is not -1 we increment man to look for stable couple
    {
        man++;

        if (man == 3) // found the power couples
        {
            print(q); // we print it
            backtrack(man); // backtrack to find the other possible solutions
        }
        else
        {
            q[man] = -1; // reset
        }

        while (man >= 0)  // we do the same thing but for woman instead
        {
            q[man]++;

            if (q[man] == 3)
            {
                backtrack(man);
            }
            else
            {
                if (ok(q, man)) // if the ok function is true we follow the code 
                break; 
                
            }
        }
    }
}
