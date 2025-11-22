#include <iostream>

int main()
{
    int *arr = new int[5];   // allocate space for 5 integers

    std::cout << "Writing inside bounds...\n";
    arr[0] = 10;
    arr[4] = 20;

    std::cout << "Now writing out of bounds...\n";
    arr[10] = 99;   // segmentation fault ->Invalid write 

    std::cout << arr[10] << "\n"; // segfault -> Invalid read

    delete[] arr;
    return 0;
}
/* Output from valgrind 
valgrind --track-origins=yes ./segfault
==3550== Memcheck, a memory error detector
==3550== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==3550== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==3550== Command: ./segfault
==3550== 
Writing inside bounds...
Now writing out of bounds...
==3550== Invalid write of size 4
==3550==    at 0x109215: main (34_Segmentation_fault.cpp:12)
==3550==  Address 0x4e1f0a8 is 20 bytes after a block of size 20 alloc'd
==3550==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==3550==    by 0x1091BE: main (34_Segmentation_fault.cpp:5)
==3550== 
==3550== Invalid read of size 4
==3550==    at 0x109223: main (34_Segmentation_fault.cpp:14)
==3550==  Address 0x4e1f0a8 is 20 bytes after a block of size 20 alloc'd
==3550==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==3550==    by 0x1091BE: main (34_Segmentation_fault.cpp:5)
==3550== 
99
==3550== 
==3550== HEAP SUMMARY:
==3550==     in use at exit: 0 bytes in 0 blocks
==3550==   total heap usage: 3 allocs, 3 frees, 74,772 bytes allocated
==3550== 
==3550== All heap blocks were freed -- no leaks are possible
==3550== 
==3550== For lists of detected and suppressed errors, rerun with: -s
==3550== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
*/