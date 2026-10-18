// auto_ptr5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class auto_ptr5 {
    T* m_ptr{};

public:
    auto_ptr5(T* ptr = nullptr) {
        m_ptr = ptr;
    }

    ~auto_ptr5() {
        delete m_ptr;
    }


    auto_ptr5(const auto_ptr5&) = delete;

    auto_ptr5(auto_ptr5&& a) noexcept{
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }


    auto_ptr5& operator=(auto_ptr5& a) = delete;

    auto_ptr5& operator=(auto_ptr5&& a) noexcept {
        if (&a == this) return *this;

        delete m_ptr ;

        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }

};

class Resource {

public:
    Resource() {
        std::cout << "Resource acquired\n";
    }

    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

auto_ptr5<Resource> generateResource() {

    auto_ptr5<Resource> res(new Resource);
    return res;
}

int main()
{

    auto_ptr5<Resource> mainres;
    mainres = generateResource();
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
