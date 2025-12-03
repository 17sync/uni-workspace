#include <iostream>
using namespace std;

int main ()
{

    //Declaration of two arrays (given in question)
    int a[] = {2, 4, 7, 9, 1, 2, 4, 65};
    int b[] = {6, 7, 1, 4, 5, 13, 20, 11};
    
    //Declaration of variables storing lengths of the arrays
    int alen = sizeof(a)/4;
    int blen = sizeof(b)/4;

    //Sorting array a in ascending order
    for (int i=0; i < alen-1; i++) {
        for (int j=0; j < alen-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    //Sorting array b in ascending order
    for (int i=0; i<blen-1; i++) {
        for (int j=0; j<blen-i-1; j++) {
            if (b[j] > b[j+1]) {
                int temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    //Removing duplicates from array a
    int uniA = 0;
    for (int i=0; i<alen; i++) {
        if (i==0 || a[i]!=a[i-1]) {
            a[uniA++] = a[i];
        }
    }

    //Removing duplicates from array b
    int uniB = 0;
    for (int i=0; i<blen; i++) {
        if (i == 0 || b[i] != b[i-1]) {
            b[uniB++] = b[i];
        }
    }

    //Displaying array a and b after arranging in ascending order and removing duplicates
    cout<<"array a after sorting and removing duplicates: ";
    for (int i=0; i<alen; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\narray b after sorting and removing duplicates: ";
    for (int i=0; i<alen; i++){
        cout<<b[i]<<" ";
    }

    //Merging array a and b into array c
    int c[uniA+uniB];
    int i = 0, j = 0, k = 0;

    while (i<uniA && j<uniB) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else if (b[j] < a[i]) {
            c[k++] = b[j++];
        } else {
            c[k++] = a[i++];
            j++;
        }
    }
    while (i<uniA) {
        c[k++] = a[i++];
    }
    while (j<uniB) {
        c[k++] = b[j++];
    }

    //Displaying array c
    cout<<"\narray a and b merged into array c: ";
    for (int i = 0; i < k; i++) {
        cout<<c[i]<<" ";
    }
    cout<<endl;

}