/*
 * Abhinav Jonnada
 * b956d578
 * 1/31/2018
 * Program 5
 *
 */






#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "PFAString.hpp"

class Trivial {
 public:
   Trivial() {};
};

PFAString::PFAString()
{
    caPacity = 0;
    siZe = 0;
    arr = nullptr;
}
PFAString::PFAString(int cap, std::string entered)
{
    arr = new std::string[100];
    if(cap < 0)
    {
        caPacity = 0;
    }
    else
    {
        caPacity = cap;
        siZe = cap;
        for(int i = 0; i < caPacity; i++)
        {
            arr[i] = entered;
        }
    }
}
PFAString::PFAString(const PFAString& PFAobj)   //copy constructor
{
    arr = new std::string[PFAobj.siZe];
    caPacity = PFAobj.siZe;
    siZe = PFAobj.siZe;

    for(int x = 0; x < PFAobj.siZe; x++)
    {
        arr[x] = PFAobj.arr[x];
    }
}
PFAString::PFAString(PFAString&& PFAobj)    //move constructor
    :arr(PFAobj.arr)
    ,caPacity(PFAobj.caPacity)
    ,siZe(PFAobj.siZe)
    {
        PFAobj.arr = nullptr;
    }
PFAString::~PFAString()
{
    if(arr != nullptr)
    {
        delete []arr;
        arr = nullptr;
    }
    else
    {
        arr = nullptr;
    }

}
const int PFAString::capacity() const
{
  return caPacity;
}
const int PFAString::size() const
{
    return siZe;
}
void PFAString::push_back(std::string entered)
{
    if(arr == nullptr)
    {
        arr = new std::string[caPacity+1];
        caPacity += 1;
    }else if(siZe == caPacity)
    {
         std::string *arr_temp = new std::string[caPacity*2];
         for(int i = 0; i < caPacity; i++)
         {
             arr_temp[i] = arr[i];
         }
         caPacity = caPacity * 2;
         delete []arr;
         arr = arr_temp;
    }
    siZe += 1;
    arr[siZe - 1] = entered;
}
void PFAString::pop_back()
{
    if(siZe != 0)
    {
        arr[siZe - 1].clear();      //erases contents of string
        siZe -= 1;

    }
    else {
	  throw std::out_of_range ("Popping an empty array");
 }
}
void PFAString::resize(int des_size, std::string destin)
{
    if(des_size >= 0)
    {
        if(des_size > siZe)
        {
            for(int x = siZe; x < des_size; x++)
            {
                arr[x] = destin;
            }
            siZe = des_size;
            caPacity = des_size;
        }
        else if(des_size < siZe)
        {
            siZe = des_size;   //if out of scope strings will be deleted
        }
    }
    else
        siZe = 0;
}
void PFAString::empty_array()
{
    if (siZe == 0) {
    throw Trivial();
}
}
std::string& PFAString::operator [](const int index)
{
    if(index < siZe && index >= 0)
    {
        return arr[index];
    }
    else
    {
        std::cout << std::endl << "Invalid index" << std::endl;
        std::exit(1);
    }
}
std::string& PFAString:: at(int i) {
	if (i < 0 || i >= siZe) {
		throw std::out_of_range("Its beyond range");
	}
	else {
		return arr[i];
	}
}
//overload copy operator =
void PFAString::operator = (const PFAString& right)
{
    arr = new std::string[100];
    caPacity = right.siZe;
    siZe = right.siZe;

    for(int i = 0; i <right.siZe; i++)
    {
        arr[i] = right.arr[i];

    }
}
PFAString& PFAString::operator = (PFAString&& right)
{
    this -> siZe = right.size();
    this -> caPacity = right.capacity();
    this -> arr = right.arr;
    right.arr = nullptr;
    return *this;
}

bool operator ==(const PFAString& left, const PFAString& right)
{
    int size_up;
    bool meter;

    if (left.siZe < right.siZe)
        size_up = left.siZe;
    else
        size_up = right.siZe;

    for (int i = 0; i< size_up; i++)
    {
        if(left.arr[i] == right.arr[i])
        {
            meter = true;
        }
        else
        {
            meter = false;
        }
    }
    if(meter == true)
    {
        if(right.siZe == left.siZe)
        {
            meter = true;
        }
        else
        {
            meter = false;
        }
    }
    return meter;

}
bool operator !=(const PFAString& left, const PFAString& right)
{
    if (left == right)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool operator <(const PFAString& left, const PFAString& right)
{
    int size_up;
    bool meter;
    bool cur = false;

    if (left.siZe < right.siZe)
        size_up = left.siZe;
    else
        size_up = right.siZe;
    for (int i = 0; i< size_up; i++)
    {
        if(left.arr[i] == right.arr[i])
        {
            meter = false;
            cur = true;
            break;
        }
        else if(left.arr[i] > right.arr[i])
        {
            meter = false;
            cur = false;
            break;
        }
        else
        {
            meter = true;
            cur = false;
            break;
        }
    }
    if(meter == false && cur == true)
    {
        if(left.siZe >= right.siZe)
        {
            meter = false;
        }
        else if(left.siZe < right.siZe)
        {
            meter = true;
        }
    }
    return meter;

}
    /*min of two sizes
    loop o to size-1
    if left[i]< right[i]
    return true
    else if
        right[i]<left[i]
    exit loop
    eturn left.size < right.sze



}
*/
bool operator <=(const PFAString& left, const PFAString& right)
{
    if((left < right) == true)
    {
        return true;
    }
    else if(left == right)
        return true;
    else
        return false;
}
bool operator >(const PFAString& left, const PFAString& right)
{
    if((left < right) == false)
    {
        if((left == right) == false)
            return true;
        else
            return false;
    }
    else
        return false;
}

    // if((left < right) == false)
    // {
    //    if((left == right) == false)
    //    {
    //       return true;
    //     }
    //    else
    //    {
    //     return false;
    //   }
    // }
    // else
    //     return false;

bool operator >= (const PFAString& left, const PFAString& right)
{
  if((left < right) == false)
  {
      return true;
  }
  else if (left == right)
      return true;
  else
      return false;
  // if((left < right) == false)
  // {
  //     return true;
  // }
  // else if (left == right)
  // {
  //   return true;
  // }
  // else
  // {
  //     return false;
  // }
}
