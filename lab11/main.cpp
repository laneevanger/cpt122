#include <iostream>
#include <vector>

using std::vector;

int main (void)
{
    //merge
    /*
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    int newArray[6] = {};
    int arrsize = 6;

    int a1Count = 0;
    int a2Count = 0;

    for(int i = 0; i < 6; i++)
    {
        if(array1[a1Count] < array2[a2Count] && a1Count < 3)
        {
            newArray[i] = array1[a1Count];
            a1Count++;
        }
        if(array1[a1Count] > array2[a2Count] && a2Count < 3)
        {
            newArray[i] = array2[a2Count];
            a2Count++; 
        }
    }
    */

    //merge but 1 array
    int array1[] = {5, 4, 3, 2, 1};
    int arrsize = 5;



    for(int i = 0; i < arrsize; i++)
    {
        std::cout << array1[i] << std::endl;
    }
}

vector<int> sortThatShit(vector<int> theArray, int size)
{
    int leftarrindex = size / 2;
    int rightarrindex = size / 2 + 1;

    vector<int> leftarr = leftarr = sortThatShit(theArray, size / 2);
    vector<int> rightarr = rightarr = sortThatShit(theArray, size / 2 + 1);

    
    if(leftarrindex == rightarrindex)
    {
        return leftarr;
    }
    else
    {
        if(leftarr[0] < rightarr[size / 2 + 1])
        {
            leftarr.insert(leftarr.end(), rightarr.begin(), rightarr.end());
            return leftarr;
        }
        else
        {
            rightarr.insert(rightarr.end(), leftarr.begin(), leftarr.end());
            return rightarr;
        }
    }

}