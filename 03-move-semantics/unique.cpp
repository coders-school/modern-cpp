#include <stdio.h>
#include <utility>

template <typename T>
class uniquePtr{
public:


    uniquePtr(T *t) {
        myPtr = t;
    }
    uniquePtr(const T* src) {
         myPtr = src; 
    }
    ~uniquePtr() {
        delete myPtr;
    }
    uniquePtr(uniquePtr&& src) {
        myPtr = src.myPtr;
        src.myPtr = nullptr;
    }
    uniquePtr(const uniquePtr& src) = delete;




    T* get() const noexcept {
        return myPtr;
    }
    void reset(T *ptr = nullptr) noexcept {
        delete myPtr;
        myPtr = ptr;
    }
    T& operator*() const {
        return *myPtr;
    }
    T* operator->() const noexcept {
        return myPtr;
    }
    
    uniquePtr<T>& operator=(uniquePtr<T>&& ptr) {
        reset(ptr.myPtr);
        ptr.myPtr = nullptr;
        return *this;
    }
    uniquePtr<T>& operator=(const uniquePtr<T>& ptr) = delete;

private:
    T* myPtr {};
};


int main()
{
    int a = 5;
    uniquePtr<int> a_ptr (new int (5));
    printf("ptr-value=%d\n", *a_ptr.get());
    a_ptr.reset(new int (10));
    printf("ptr-value=%d\n", *a_ptr.get());
    printf("ptr-value=%d\n", *a_ptr);
   // uniquePtr<int> b_ptr = a_ptr;
    //uniquePtr<int> b_ptr(a_ptr);
    uniquePtr<int> b_ptr(std::move(a_ptr));
    a_ptr = std::move(b_ptr);
    // b_ptr = a_ptr;
    printf("ptr-value=%d\n", *a_ptr.get()); 

    // printf("ptr-value=%d\n", *a_ptr.get()); 

    return 0;
}