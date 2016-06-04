#include <iostream>
namespace lxm {
    using std::cout;
    using std::endl;
    class C {
        public:
            int z;
    };
    class NoneVBase : public virtual C {
        public :
            void f() {cout << "NoneVBase::f" << endl;  }
            void g() {cout << "NoneVBase::g" << endl;}
            void h() {cout << "NoneVBase::h" << endl;}
            int p;
        private:
            void j() {cout << "NoneVBase::j" << endl;}
    };

    class NoneVBase1: public virtual C {
        public :
            void f() {cout << "NoneVBase1::f" << endl;}
            void g() {cout << "NoneVBase1::g" << endl;}
            void h() {cout << "NoneVBase1::h" << endl;}
    };
    class Deri : public NoneVBase, public NoneVBase1{
        public:
            void f1() {cout << "Deri::f1" << endl;}
            /*
            void f() {cout << "Deri::f" << endl;}
            void g() {cout << "Deri::g" << endl;}
            void h() {cout << "Deri::h" << endl;}
            */
    };

    void none_virtual_method_test() {
        cout << "============none_virtual_method_test=================" << endl;
        Deri derived;
        cout << "sizeof int:" << sizeof(int) << endl;
        cout << "size:" << sizeof(derived) << endl;
        typedef void(*Fun)(void);
        cout << "derived ptr:" << &derived << "   p ptr:" << &(derived.p) << endl;
        cout << "derived ptr:" << &derived << "   z ptr:" << &(derived.z) << endl;
        C * c = &derived;
        cout << "derived ptr:" << &derived << "   C ptr:" << c << endl;
        NoneVBase * nvBase = &derived;
        cout << "derived ptr:" << &derived << "   Base ptr:" << nvBase << endl;
        NoneVBase1 * nvBase1 = &derived;
        cout << "derived ptr:" << &derived << "   Base1 ptr:" << nvBase1 << endl;

        cout << "derived first ptr content:" << (*(uint64_t*)&derived) << endl;

        int ** pVtab = (int**)&derived;

        typedef void (Deri::*fptr)(void);
        fptr f =&NoneVBase::f;
        void * ppp = (void *)&f;
        cout << "ppp " << ppp << endl;
        Fun func=(Fun) pVtab[0][0];
        func();
    }
}
