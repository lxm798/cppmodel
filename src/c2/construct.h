#include<iostream>
namespace lxm {
    using std::cout;
    using std::endl;

    class First {
        public:
            First() {
                cout << "first default construct" << endl;
            }
    };

    class Second{
        public:
            Second() {
                cout << "second default construct" << endl;
            }
    };

    class Third {
        public:
            Third() {
                cout << "third default construct" << endl;
            }
    };

    class Aggr {
        public:
            Aggr():_second(), num(0) {
                cout << "i:" << num << endl;
                _second = Second();
            }
            Aggr(int i):_second(), num(i) {
                cout << "i:" << num << endl;
            }
        private:
            First _fist;
            Second _second;
            Third _third;
            int num;
    };

    void test_construct_order() {
        cout << "start default" << endl;
        Aggr();
        cout << "start construct with int" << endl;
        Aggr();
    }
}
