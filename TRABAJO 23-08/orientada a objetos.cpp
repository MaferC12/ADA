#include <iostream>
using namespace std;

class CVector {
private:
    int* m_pVect;   
    int m_nCount;   
    int m_nMax; 
    int m_nDelta;   

    void Init(int delta); 
    void Resize();        

public:
    CVector(int delta = 10); 
    ~CVector();              
    void Insert(int elem);   
    void Print();            
};

CVector::CVector(int delta) {
    Init(delta);
}

void CVector::Init(int delta) {
    m_pVect = nullptr;  
    m_nCount = 0;       
    m_nMax = 0;         
    m_nDelta = delta;   
}

void CVector::Resize() {
    int* pTemp = new int[m_nMax + m_nDelta];

    for (int i = 0; i < m_nMax; ++i) {
        pTemp[i] = m_pVect[i];
    }

    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem;
}

CVector::~CVector() {
    delete[] m_pVect;
}

void CVector::Print() {
    for (int i = 0; i < m_nCount; ++i) {
        cout << m_pVect[i] << " ";
    }
    cout << endl;
}

int main() {
    CVector vec(10); 
    for (int i = 1; i <= 3; ++i) {
        vec.Insert(i * 10); 
    }
   

    vec.Print(); 

    return 0;
}
