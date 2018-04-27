#include <iostream>
#include "PFAString.hpp"
#include <cstdlib>

class Trivial {
 public:
   Trivial() {};
};
PFAString::PFAString()
{
    arr = new std::string[100];
    caPacity = 100;              // caPacity and size are two different things
    siZe = 0;

}

PFAString::PFAString(int cap, std::string entered)
{
    arr = new std::string[cap];
    if (cap < 0)
    {
        caPacity = 0;
    }
    else
    {
      caPacity = cap;
      siZe = cap;
      for (int i =0; i < caPacity; i++)
      {
          arr[i] = entered;
      }
    }

}

PFAString::PFAString(const PFAString& PFAobj)
{
    arr = new std::string[100];
    caPacity = PFAobj.siZe;
    siZe = PFAobj.siZe;

    for(int i = 0; i < PFAobj.siZe; i++)
    {
        arr[i] = PFAobj.arr[i];

    }
}

PFAString::PFAString(PFAString&& PFAobj)

    // :arr(PFAobj.arr)
    // ,caPacity(PFAobj.caPacity)
    // ,siZe(PFAobj.siZe)
  {
    siZe = PFAobj.siZe;
    arr = PFAobj.arr;
    caPacity = PFAobj.caPacity;
    PFAobj.arr = nullptr;
  }


PFAString::~PFAString()
{
    if(arr != NULL)
    {
        delete []arr;
        arr = NULL;
    }
    else
        std::cout << "pointer is NULL....";
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
	siZe += 1;
	
	if ( caPacity == 0) {
		arr = new std::string[5];
		caPacity = 5;
	}
	if ( siZe > caPacity) {
		caPacity *= 2;
		std:: string* temp = new std::string[caPacity];
		for (int i = 0 ; i < siZe - 1; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	arr[(siZe -1)] = entered;
}
		
		
  /*if(siZe == caPacity)}
   * 
  {
    caPacity = caPacity * 2;
  }
  siZe += 1;
  arr[siZe - 1] = entered;
  * */
    // if(arr == nullptr)
    // {
    //   arr = new std::string[caPacity + 1];
    //   caPacity += 1;
    // }
    // else if(siZe = caPacity)
    // {
    //   std::string *arr_tm = new std::string[caPacity * 2];
    //   for (int i = 0;  i < caPacity; i++)
    //   {
    //     arr_tm[i] = arr[i];
    //   }
    //   caPacity = caPacity * 2;
    //   delete []arr;
    //   arr = arr_tm;
    // }
    // siZe += 1;
    // arr[siZe -1] = entered;


void PFAString::pop_back()
{ 
	if (siZe != 0) {
        arr[siZe-1].clear(); //erases contents of string
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
			  delete[] arr;
             arr = new std::string[des_size];
             
             for(int x = 0; x < des_size; x++)
             {
                 arr[x] = destin;
                 
             }
           
             siZe = des_size;
             caPacity = des_size;
         }
         else if (des_size < siZe)
         {
             siZe = des_size; //if out of scope strings will be deleted
             for(int x = 0; x < des_size; x++)
             {
                 arr[x] = destin;
                 
             }
         }
     }
     else
        siZe = 0;
 }

void PFAString::empty_array()
{
	if (siZe == 0) {
    throw Trivial();
}}

std::string& PFAString::operator [] (const int index)
{
    if(index < siZe && index >= 0)
    {
        return arr[index];
    }
    else
    {
        std::cout << std::endl << "Invalid Index" << std::endl;
        std::exit(1);
    }

} 
       // Needs to work as l-value
std::string& PFAString:: at(int i) {
	if (i < 0 || i >= siZe) {
		throw std::out_of_range("Its beyond range"); 
	}
	else {
		return arr[i];
	}
}

void PFAString::operator = (const PFAString& right)
{
    arr = new std::string[100];
    caPacity = right.siZe;
    siZe = right.siZe;

    for(int i = 0; i <right.siZe; i++)
    {
        arr[i] = right.arr[i];

    }
} //overload copy operator =
PFAString& PFAString::operator = (PFAString&& right)
{
    this -> siZe = right.size();
    this -> caPacity = right.capacity();
    this -> arr = right.arr;
    right.arr = nullptr;
    return *this;
}//overload move operator =

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
    /* if (!(left < right) && !(right < left))
     {
         return true;
     }
     else
     {
         return false;
     }

}*/

bool operator !=(const PFAString& left, const PFAString& right)
{

   if (left == right)
    return false;
   else
    return true;
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
            cur = false;
            break;
        }
        else if(left.arr[i] > right.arr[i])
        {
            meter = true;
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
        else
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
    else if (left == right)
        return true;
    else
        return false;
}

bool operator > (const PFAString& left, const PFAString& right)
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
          cur = false;
          break;
      }
      else if(left.arr[i] < right.arr[i])
      {
          meter = true;
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
      if(right.siZe >= left.siZe)
      {
          meter = false;
      }
      else
      {
          meter = true;
      }
  }
  return meter;

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
}

bool operator >= (const PFAString& left, const PFAString& right)
{
  if((left > right) == true)
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
