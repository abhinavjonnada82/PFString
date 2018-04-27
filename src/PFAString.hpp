/*
 * Abhinav Jonnada
 * b956d578
 * 1/31/2018
 * Program 5
 *
 */



#ifndef PFASTRING_HPP
#define PFASTRING_HPP

#include <string>

class PFAString {
public:
    PFAString(); //Default constructor
    PFAString(int capa, std::string entered = std::string());   //Constructor that sets capacity and initializes all elements to a specific string    // If no string is provided, then a null string will be used. This is a single constructor (no overloads for this case)
    PFAString(const PFAString& PFAobj);//Copy Constructor            // 1st type only (Refer to list of vector constructors on cplusplus.com)
    PFAString(PFAString&& PFAobj);//Move Constructor            // 1st type only
    ~PFAString();//Destructor
    const int capacity() const;// function capacity
    const int size() const; //function size
    void push_back(std::string entered);// function push_back          // Places a string at the back of the array, l-value version only
    void pop_back();//function pop_back           // Destroys the string at the back of the array
    void resize(int des_size = 0, std::string destin = std::string());//function resize             // Grows or shrinks array accordingly, must behave like vector resize() function
    void empty_array(); //function empty_array        // Sets the size to zero
    std::string& operator [] (const int index);        // Needs to work as l-value
    std::string& at(int i);
    void operator = (const PFAString& right); //overload copy operator =
    PFAString& operator = (PFAString&& right);//overload move operator =
    friend bool operator ==(const PFAString& left, const PFAString& right);
    friend bool operator !=(const PFAString& left, const PFAString& right);
    friend bool operator <(const PFAString& left, const PFAString& right);
    friend bool operator <=(const PFAString& left, const PFAString& right);
    friend bool operator >(const PFAString& left, const PFAString& right);
    friend bool operator >=(const PFAString& left, const PFAString& right);

private:
    std::string *arr;
    int caPacity;               // Capacity and size are two different things
    int siZe;
};

#endif
