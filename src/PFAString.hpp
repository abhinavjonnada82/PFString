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
    PFAString ();
    PFAString (int cap, std::string specific = std::string());   // If no string is provided, then a null string will be used. This is a single constructor (no overloads for this case)
    PFAString (const PFAString &PFAitm);         // Copy Constructor -- 1st type only (Refer to list of vector constructors on cplusplus.com)
    PFAString(PFAString&& PFAitm);                     // 1st type only
    ~PFAString ();                               // Destructor
    const int capacity () const;             // Returns vector capacity
    const int size () const;                  // Returns vector size
    void push_back (std::string specific);       // Places a string at the back of the array
    void pop_back ();                            // Destroys the string at the back of the array
    void resize (int get_size = 0, std::string spec_string = "");            // Grows or shrinks array accordingly
    void empty_array ();                         // Sets the size to zero
    std::string& operator [] (const int index);        // Needs to work as l-value
    std::string& at(int i);
    void operator = (const PFAString &PFAitm);
    PFAString& operator = (PFAString&& PFAitm);
    friend bool operator == (const PFAString& left, const PFAString& right);
    friend bool operator != (const PFAString& left, const PFAString& right);
    friend bool operator < (const PFAString& left, const PFAString& right);
    friend bool operator <= (const PFAString& left, const PFAString& right);
    friend bool operator > (const PFAString& left, const PFAString& right);
    friend bool operator >= (const PFAString& left, const PFAString& right);
private:
    std::string *arr;
    int caPacity;               // Capacity and size are two different things
    int siZe;
};

#endif
