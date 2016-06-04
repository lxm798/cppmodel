#include<iostream>
namespace lxm {
    using std::cout;
    using std::endl;

    class Base1 {
        public:
            Base1 () {
                cout << "base default construct" << endl;
            }
    };

    class Base2 {
        public:
            Base2 () {
                cout << "base2 default construct" << endl;
            }
    };

    class Derived : public Base1, public Base2 {
        public:
            Derived(int i) : Base2() {
                cout << "derived construct with Base2 in the list" << endl;
            }
    };

    void test_derived_order() {
        cout << "===========start Derived test===========" << endl;
        Derived(1);
    }
}
