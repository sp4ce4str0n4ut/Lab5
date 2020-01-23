#include <ostream>



template<class T>
class CustomIter {
private:
	std::ostream* pointer;
	
	int N;
    int n;
    
    const char* del;
    
	
public:
    CustomIter(std::ostream& stream, const char* del, int N): pointer(&stream), del(del), N(N) {
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

    ~CustomIter() = default;

};