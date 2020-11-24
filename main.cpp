#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//Scopul lucrării: Studierea tehnicilor şi metodelor de utilizare a
//        instrucţiunilor de control a condiţiei şi a instrucţiunilor ciclice în
//        limbajul C pentru tabularea funcţiei.
//Sarcina (cоnform variantelor): Să se calculeze şi să se afişeze la
//ecran valorile argumentului x şi valorile funcţiei F, definită prin 3
//expresii date, pentru intervalul х1 ≤ x ≤ х2 şi pasul px de
//        incrementare a argumentului x. Valorile x1, x2, px și parametrii a,g
//b, c sunt date de intrare de tip real.

//Laboratoarele
void lab1(float x1, float x2, float px, float a, float b, float c);

void lab2();

void lab4();


//functii ajutatoare
int removeDuplicates(int arr[], int n);

//void sortDiagonal(int a[100][100], int M, int N);

int main() {

// lab1(10,20,0.4,2,6,7);
//    lab2();
    lab4();


    return 0;
}


//functii ajutatoare
int removeDuplicates(int arr[], int n) {
    // Return, if array is empty
    // or contains a single element
    if (n == 0 || n == 1)
        return n;

    int temp[n];

    // Start traversing elements
    int j = 0;
    for (int i = 0; i < n - 1; i++)

        // If current element is not equal
        // to next element then store that
        // current element
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];

    // Store the last element as whether
    // it is unique or repeated, it hasn't
    // stored previously
    temp[j++] = arr[n - 1];

    // Modify original array
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

void DisplayMainMenu() {
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Alocarea dinamică a memoriei pentru tablourile bidimensionale\n";
    cout << "2 - Introducerea elementelor tabloului de la tastatură\n";
    cout << "3 - Completarea tabloului cu valori aleatorii\n";
    cout << "4 - Sortarea elementelor tabloului\n";
    cout << "5 - Afișarea elementelor tabloului la ecran \n";
    cout << "6 - Eliberarea memoriei alocate pentru tablou \n";
    cout << "0 - Ieșire din program\n";
    cout << "Optiunea: ";
}

void sortDiagonal(int **a, int M, int N) {
    // Loop to find the ith minimum
    // element from the major diagonal
    for (int i = 0; i < M; i++) {
        int sm = a[i][i];
        int pos = i;

        // Loop to find the minimum
        // element from the unsorted matrix
        for (int j = i + 1; j < N; j++) {
            if (sm > a[j][j]) {
                sm = a[j][j];
                pos = j;
            }
        }

        // Swap to put the minimum
        // element at the beginning of
        // the major diagonal of matrix
        swap(a[i][i], a[pos][pos]);
    }

    // Loop to print the matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}


// function to sort each row of the matrix
void sortByRow(int **mat, int n) {
    for (int i = 0; i < n; i++)

        // sorting row number 'i'
        sort(mat[i], mat[i] + n);
}

// function to find transpose of the matrix
void transpose(int **mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)

            // swapping element at index (i, j)
            // by element at index (j, i)
            swap(mat[i][j], mat[j][i]);
}

// function to sort the matrix row-wise
// and column-wise
void sortMatRowAndColWise(int **mat,
                          int n) {
    // sort rows of mat[][]
    sortByRow(mat, n);

    // get transpose of mat[][]
    transpose(mat, n);

    // again sort rows of mat[][]
    sortByRow(mat, n);

    // again get transpose of mat[][]
    transpose(mat, n);
}


//laboratoarele, definirea
void lab1(float x1, float x2, float px,
          float a, float b, float c) {

    float rezoltatuFunctiei, x;

    cout << "Introduceti urmatorii parametri: ";
    cout << "a,b,c,x1,x2,px" << endl;
//    cin >> a >> b >> c >> x1 >> x2 >> px;

//gaseste primul numar din interval
    for (x1; x1 <= x2; x1 += px) {
        x = x1;
        if ((x > c + b) && (a != 0)) {
            rezoltatuFunctiei = sqrt(x + a + pow(b, 2)) / cos(x);

            cout << "\nx = " << x << ",x > c + b, deci F = " << rezoltatuFunctiei;
//            break;
        } else if ((x < c + b) && (a == 0)) {
            rezoltatuFunctiei = (log(a) + log(b)) / (a * x + pow(c, 2));
            cout << "\nx = " << x << ",x < c + b, deci F = " << rezoltatuFunctiei;

//            break;
        } else {
            rezoltatuFunctiei = (a + b + x) / pow(x, 2);
            cout << "\nx = " << x << ", x nu satisfacce primele 2 contidii, deci F = " << rezoltatuFunctiei;

//            break;
        }
    }
//    return rezoltatuFunctiei;

}

void lab2() {
    int arr[] = {-10, 23, 4, 5, -12, 1, -100, 1, 5, 4, 3, 4, 5, 6, 7, -100, -2, -3},
            max = -1000,
            currentElement,
            *positions = new int[sizeof(arr) / sizeof(arr[0])],
            positionCount = 0,
            coutAns = 0;
    vector<int> answers;


    for (int el : arr)
        if (el < 0 && el > max)max = el;

    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int arrCopy[sizeof(arr) / sizeof(arr[0])];

    copy(begin(arr), end(arr), begin(arrCopy));

    for (int i = 0; i < arraySize; i++) {

        if (answers.size() > 1) {
            cout << endl << currentElement << " Acest numar se gaseste pe urmatoarele pozitii:  ";

            for (auto el : answers) {
                cout << el << " ";
            }
        }

        currentElement = arr[i];
        positionCount = 0;
        coutAns = 0;
        answers.clear();


        for (int j = 0; j < arraySize; ++j) {
            if (currentElement == arr[j] && arrCopy[j] != -6969) {
                if (positionCount == 0) {
//                        cout << endl << currentElement << " Acest numar se gaseste pe urmatoarele pozitii:  ";
                    positionCount++;

                }
                arrCopy[j] = -6969;
//                    cout << " " << j;
                answers.push_back(j);
            }
        }
    }

    cout << endl << "Cel mai mare nr negativ este: " << max << endl;
}

void lab4() {
    int **matrix = NULL;
    int n = 0, m, option, choice = 0;


    do {
        system("cls");
        cout << endl;
        DisplayMainMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Introdu marimea matricei, respectiv n,m \n";
                cin >> n >> m;
                matrix = new int *[n];
                for (int i = 0; i < n; i++) {
                    matrix[i] = new int[m];
                }
                break;
            case 2:
                cout << "Introdu " << m << " numere in " << n << " randuri";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cin >> matrix[i][j];
                    }
                    cout << endl;
                }
                break;
            case 3:
                cout << "\nTabloul a fost completat cu succes";
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) {
                        matrix[i][j] = rand() % 100;
                    }
                break;
            case 4:
                if (n != m)
                    cout << "Poate fi sortat tabloul doar daca m = n,/n"
                            " adica nr de coloane = cu nr de randuri";
                else {
                    cout << "\nTabloul a fost sortat";
                    sortMatRowAndColWise(matrix, n);
                }
                break;
            case 5:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << matrix[i][j];
                        cout << " ";
                    }
                    cout << endl;
                }
                break;
            case 6:
                cout << "\n Memoria a fost eliberata";
                delete[] matrix;
                matrix = NULL;
                break;
            case 0:
                cout << "Ai iesit cu succes";
                break;
            default:
                break;
        }
    } while (choice != 0);


}