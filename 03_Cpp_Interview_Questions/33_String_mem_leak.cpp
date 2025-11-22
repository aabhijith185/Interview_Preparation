#include<iostream> 
#include<cstring> 

using namespace std;
class String 
{
private:    
    char *data; 
public : 
    String() : data(new char[1])
    {
        data[0] = '\0';
    }

    String(char *str)
    {
        data = new char[strlen(str)+1]; 
        strcpy(data,str);
    }
    //Shallow copy 
    String(const String& str)
    {
        data = str.data; 
    }
    
    char& operator[](int index)
    {
        return data[index];
    }

    void print()
    {
        cout<<"Data: | "<<data<<" Address: |"<<static_cast<void*>(data)<<endl;
    }
    ~String()
    {
        cout<<"Calling destructor"<<endl;
        delete[] data;
    }
}; 

int main(void)
{
    char *str = "Hii How are you"; 
    String s1(str); 
    s1.print();
    String s2(s1);  
    s2.print();
    s2[2] = 'o';
    
    cout<<"After modifying"<<endl;//both s1 and s2 changes 
    s1.print(); //Hio How are you
    s2.print(); //Hio How are you

    return 0;
}
/* Valgrind output 

valgrind --leak-check=full --show-leak-kinds=all ./string_mem_leak 
==29285== Memcheck, a memory error detector
==29285== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==29285== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==29285== Command: ./string_mem_leak
==29285== 
Data: | Hii How are you Address: |0x4e1f080
Data: | Hii How are you Address: |0x4e1f080
After modifying
Data: | Hio How are you Address: |0x4e1f080
Data: | Hio How are you Address: |0x4e1f080
Calling destructor
Calling destructor
==29285== Invalid free() / delete / delete[] / realloc()
==29285==    at 0x484BFA4: operator delete[](void*) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29285==    by 0x1094ED: String::~String() (33_String_mem_leak.cpp:38)
==29285==    by 0x109321: main (33_String_mem_leak.cpp:56)
==29285==  Address 0x4e1f080 is 0 bytes inside a block of size 16 free'd
==29285==    at 0x484BFA4: operator delete[](void*) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29285==    by 0x1094ED: String::~String() (33_String_mem_leak.cpp:38)
==29285==    by 0x109315: main (33_String_mem_leak.cpp:56)
==29285==  Block was alloc'd at
==29285==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29285==    by 0x1093B3: String::String(char*) (33_String_mem_leak.cpp:17)
==29285==    by 0x109282: main (33_String_mem_leak.cpp:45)
==29285== 
==29285== 
==29285== HEAP SUMMARY:
==29285==     in use at exit: 0 bytes in 0 blocks
==29285==   total heap usage: 3 allocs, 4 frees, 74,768 bytes allocated
==29285== 
==29285== All heap blocks were freed -- no leaks are possible
==29285== 
==29285== For lists of detected and suppressed errors, rerun with: -s
==29285== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/