#include <iostream>
using namespace std;

struct Vector {
    int* m_pVect;   
    int m_nCount;   
    int m_nMax;     
    int m_nDelta;   
};

void Resize(Vector* pThis) {
    
    int* pTemp = new int[pThis->m_nMax + pThis->m_nDelta];

   
    for (int i = 0; i < pThis->m_nMax; ++i) {
        pTemp[i] = pThis->m_pVect[i];
    }

    
    delete[] pThis->m_pVect;

    
    pThis->m_pVect = pTemp;

    
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax) { 
        Resize(pThis); 
    }
    pThis->m_pVect[pThis->m_nCount++] = elem; 
}

int main() {
    
    Vector vec;
    vec.m_pVect = NULL; 
    vec.m_nCount = 0;   
    vec.m_nMax = 0;     
    vec.m_nDelta = 10;  

    
    Insert(&vec, 10);
    Insert(&vec, 20);
    Insert(&vec, 30);

    
    for (int i = 0; i < vec.m_nCount; ++i) {
        cout << vec.m_pVect[i] << " ";
    }

    
    delete[] vec.m_pVect;

    return 0;
}
