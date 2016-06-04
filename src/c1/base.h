#include <iostream>
namespace lxm {
    using std::cout;
    using std::endl;
    class B {
        private:
            int z;
    };
    class Base : public virtual B {
        public :
            virtual void f() {cout << "Base::f" << endl;  }
            virtual void g() {cout << "Base::g" << endl;}
            virtual void h() {cout << "Base::h" << endl;}
        private:
            virtual void j() {cout << "Base::j" << endl;}
    };

    class Base1: public virtual B {
        public :
            virtual void f() {cout << "Base1::f" << endl;}
            virtual void g() {cout << "Base1::g" << endl;}
            virtual void h() {cout << "Base1::h" << endl;}
    };
    class Derived : public Base, public Base1{
        public:
            virtual void f1() {cout << "Derived::f1" << endl;}
            /*
            virtual void f() {cout << "Derived::f" << endl;}
            virtual void g() {cout << "Derived::g" << endl;}
            virtual void h() {cout << "Derived::h" << endl;}
            */
    };

    void base_vptr() {
        typedef void(*Fun)(void);
        cout << "==============base_vptr()================" << endl;
        Base b;
        Fun pFun = NULL;

        cout << "vptr_addr:" <<  (int*)(&b) << endl;
        cout << "first func of vptr" << (int*)*(int*)(&b) << endl;

        pFun = (Fun)*((int*)*(int*)(&b));
        pFun();

        Derived derived;
        cout << "sizeof derived:" << sizeof(derived);
        cout << "derived vptr_addr:" << (int*)(&derived) << endl;
        cout << "derived first func of vptr" << (int*)*(int*)(&b) << endl;
        pFun = (Fun)*((int*)*(int*)(&derived));
        pFun();
        cout << "\n\n\n";
        cout << "derived second func of vptr" << (int*)*(int*)(&b) << endl;
        cout << (int*)(&derived) << "  " << (((int*)(&derived)) + 2) << endl;
        pFun = (Fun)*((int*)*((int*)(&derived) + 2));
        pFun();
        Base *bptr = &derived;
        Base1 *b1ptr = &derived;
        B *bbptr = &derived;
        cout << "Base pointer:" << bptr << "   Base1 pointer:" << b1ptr  << " B pointer" << bbptr<< endl;
        cout << "size of int:" << sizeof(int) << "sizeof int*" << sizeof(int*) << endl;

        cout << "call private method" << endl;
        pFun = (Fun)(*((int*)*(int*)(&derived) + 8));
        pFun();
    }
}
