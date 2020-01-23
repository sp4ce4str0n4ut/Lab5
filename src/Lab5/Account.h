#include <map>
#include <set>
#include<iostream>
#include <string>


namespace std {
    template<class T> struct hash;
    template <>
    struct hash<Account> {
        size_t operator()(Account user) const {
            return hash<string>()(user.get_name()) ^ hash<size_t >()(user.get_id());
        }
    };
}

class Account
{
public:
    Account() : get_name(), ID() {}
	
    Account(std::string name, size_t id) : name(std::move(name)), ID(id) {}

    Account(Account&& other) : name(std::move(other.name)), ID(other.ID) {}

    Account& operator=(const Account& other) {
        if (this == &other)
            return *this;
        name = other.name;
        ID = other.ID;
        return *this;
    }

    Account& operator=(Account&& other) {
        if (this == &other)
            return *this;
        name = std::move(other.name);
        ID = other.ID;
        return *this;
    }

    bool operator==(const Account& other) {
        return ID == other.get_id();
    }

    bool operator>(const Account& other) {
        return ID > other.get_id();
    }

    bool operator<(const Account& other) {
        return ID < other.get_id();
    }
    
    std::string get_name() const 
    {
        return name; 
    }

    size_t get_id() const
    {
        return ID;
    }

private:
    std::string name;
    size_t ID;
};


