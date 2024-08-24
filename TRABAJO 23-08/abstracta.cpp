#include <iostream>

using namespace std;

template <typename Type>
class CVector {
private:
    Type* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta);
    void Resize();

public:
    CVector(int delta = 10);
    ~CVector();
    void Insert(const Type& elem);
    void Print() const;
};

template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}

template <typename Type>
void CVector<Type>::Init(int delta) {
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

template <typename Type>
void CVector<Type>::Resize() {
    Type* pTemp = new Type[m_nMax + m_nDelta];

    for (int i = 0; i < m_nMax; ++i) {
        pTemp[i] = m_pVect[i];
    }

    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

template <typename Type>
void CVector<Type>::Insert(const Type& elem) {
    if (m_nCount == m_nMax) {
        Resize();
    }

    m_pVect[m_nCount++] = elem;
}

template <typename Type>
CVector<Type>::~CVector() {
    delete[] m_pVect;
}

template <typename Type>
void CVector<Type>::Print() const {
    for (int i = 0; i < m_nCount; ++i) {
        cout << m_pVect[i] << " ";
    }
    cout<< endl; 
}

int main() {
    CVector<int> vec(10);

    for (int i = 1; i <= 5; ++i) {
        vec.Insert(i * 10); 
    }

    vec.Print();

    return 0;
}
