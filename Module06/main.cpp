#include <iostream>

class B {
    private :
        int a;
    public :
        int get_A()
        {
            return (a);
        }
};

int main() 
{
    B obj1;
    long a = reinterpret_cast<long>(&obj1);
    std::cout << "a = " << a <<  std::endl;
}