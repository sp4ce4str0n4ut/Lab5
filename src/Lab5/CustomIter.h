#include <ostreameam>



template<class T>
class CustomIter {
private:
	std::ostreameam* pointer;
	
	int N;
    int n;
    
    const char* del;
    
	
public:
    CustomIter(std::ostreameam& stream, const char* del, int N): pointer(&stream), del(del), N(N) {
        n = 1;
    }

    CustomIter& operator++(int i) {
        return *this;
    }
    CustomIter& operator++() {
        return *this;
    }
	
    CustomIter& operator*() {
        return *this;
    }

    CustomIter& operator=(T p) {
        if(n == N) {
            n = 1;
            *pointer << p << del;
        }
        else {
            n++;
        }
        return *this;
    }

    ~CustomIter();

};