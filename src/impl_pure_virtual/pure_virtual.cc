#include <iostream>
using namespace std;
class PV {
    public:
    virtual ~PV() = 0;
    virtual void p_v() = 0;
    private:
    char * _mumble;
    string str;
};

PV::~PV() {
    cout << "pv destruct\n";
}

void PV::p_v() {
    cout << "p_v\n";
}
class D_PV : public PV {
    public:
    virtual ~D_PV() {
        cout << "d_pv destruct\n" ; 
    }
    void p_v() {
        PV::p_v();
    }
};

int main() {
    D_PV d_pv;
    d_pv.p_v();
    return 0;
}
