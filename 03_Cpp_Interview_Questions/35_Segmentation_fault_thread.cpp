#include<iostream>
#include<thread> 
#include<chrono> 

void worker(int *ptr)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    std::cout<<"Worker accessing ptr: "<<*ptr<<std::endl;//seg fault since main thread deletes heap memory pointed by ptr
}

int main(void)
{
    int *data = new int(42); 

    std::thread t1(worker,data);

    std::cout<<"Main thread deleting heap memory"<<std::endl; 
    delete data; 

    t1.join(); 
    return 0;
}

/* Valgrind output 
valgrind --tool=helgrind ./thread_segmentation_fault 
==13632== Helgrind, a thread error detector
==13632== Copyright (C) 2007-2017, and GNU GPL'd, by OpenWorks LLP et al.
==13632== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==13632== Command: ./thread_segmentation_fault
==13632== 
Main thread deleting heap memory
==13632== ---Thread-Announcement------------------------------------------
==13632== 
==13632== Thread #2 was created
==13632==    at 0x4C3FA23: clone (clone.S:76)
==13632==    by 0x4C3FBA2: __clone_internal_fallback (clone-internal.c:64)
==13632==    by 0x4C3FBA2: __clone_internal (clone-internal.c:109)
==13632==    by 0x4BB254F: create_thread (pthread_create.c:297)
==13632==    by 0x4BB31A4: pthread_create@@GLIBC_2.34 (pthread_create.c:836)
==13632==    by 0x4854975: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4956EB0: std::thread::_M_start_thread(std::unique_ptr<std::thread::_State, std::default_delete<std::thread::_State> >, void (*)()) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x109750: std::thread::thread<void (&)(int*), int*&, void>(void (&)(int*), int*&) (std_thread.h:164)
==13632==    by 0x1093AC: main (35_Segmentation_fault_thread.cpp:15)
==13632== 
==13632== ---Thread-Announcement------------------------------------------
==13632== 
==13632== Thread #1 is the program's root thread
==13632== 
==13632== ----------------------------------------------------------------
==13632== 
==13632== Possible data race during read of size 8 at 0x10D058 by thread #2
==13632== Locks held: none
==13632==    at 0x49C0C54: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C113B: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x109326: worker(int*) (35_Segmentation_fault_thread.cpp:8)
==13632==    by 0x10A191: void std::__invoke_impl<void, void (*)(int*), int*>(std::__invoke_other, void (*&&)(int*), int*&&) (invoke.h:61)
==13632==    by 0x10A0F2: std::__invoke_result<void (*)(int*), int*>::type std::__invoke<void (*)(int*), int*>(void (*&&)(int*), int*&&) (invoke.h:96)
==13632==    by 0x10A052: void std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==13632==    by 0x10A007: std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::operator()() (std_thread.h:299)
==13632==    by 0x109FE7: std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)(int*), int*> > >::_M_run() (std_thread.h:244)
==13632==    by 0x4956DB3: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x4854B7A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4BB2AA3: start_thread (pthread_create.c:447)
==13632==    by 0x4C3FA33: clone (clone.S:100)
==13632== 
==13632== This conflicts with a previous write of size 8 by thread #1
==13632== Locks held: none
==13632==    at 0x49C0D30: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C113B: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x1093C5: main (35_Segmentation_fault_thread.cpp:17)
==13632==  Address 0x10d058 is 24 bytes inside data symbol "_ZSt4cout@GLIBCXX_3.4"
==13632== 
==13632== ----------------------------------------------------------------
==13632== 
==13632== Possible data race during write of size 8 at 0x10D058 by thread #2
==13632== Locks held: none
==13632==    at 0x49C0D30: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C113B: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x109326: worker(int*) (35_Segmentation_fault_thread.cpp:8)
==13632==    by 0x10A191: void std::__invoke_impl<void, void (*)(int*), int*>(std::__invoke_other, void (*&&)(int*), int*&&) (invoke.h:61)
==13632==    by 0x10A0F2: std::__invoke_result<void (*)(int*), int*>::type std::__invoke<void (*)(int*), int*>(void (*&&)(int*), int*&&) (invoke.h:96)
==13632==    by 0x10A052: void std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==13632==    by 0x10A007: std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::operator()() (std_thread.h:299)
==13632==    by 0x109FE7: std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)(int*), int*> > >::_M_run() (std_thread.h:244)
==13632==    by 0x4956DB3: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x4854B7A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4BB2AA3: start_thread (pthread_create.c:447)
==13632==    by 0x4C3FA33: clone (clone.S:100)
==13632== 
==13632== This conflicts with a previous write of size 8 by thread #1
==13632== Locks held: none
==13632==    at 0x49C0D30: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C113B: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x1093C5: main (35_Segmentation_fault_thread.cpp:17)
==13632==  Address 0x10d058 is 24 bytes inside data symbol "_ZSt4cout@GLIBCXX_3.4"
==13632== 
==13632== ----------------------------------------------------------------
==13632== 
==13632== Possible data race during read of size 1 at 0x4AE5A58 by thread #2
==13632== Locks held: none
==13632==    at 0x49C1469: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x109339: worker(int*) (35_Segmentation_fault_thread.cpp:8)
==13632==    by 0x10A191: void std::__invoke_impl<void, void (*)(int*), int*>(std::__invoke_other, void (*&&)(int*), int*&&) (invoke.h:61)
==13632==    by 0x10A0F2: std::__invoke_result<void (*)(int*), int*>::type std::__invoke<void (*)(int*), int*>(void (*&&)(int*), int*&&) (invoke.h:96)
==13632==    by 0x10A052: void std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==13632==    by 0x10A007: std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::operator()() (std_thread.h:299)
==13632==    by 0x109FE7: std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)(int*), int*> > >::_M_run() (std_thread.h:244)
==13632==    by 0x4956DB3: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x4854B7A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4BB2AA3: start_thread (pthread_create.c:447)
==13632==    by 0x4C3FA33: clone (clone.S:100)
==13632== 
==13632== This conflicts with a previous write of size 1 by thread #1
==13632== Locks held: none
==13632==    at 0x494E8CF: std::ctype<char>::_M_widen_init() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C0A3F: std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x1093D7: main (35_Segmentation_fault_thread.cpp:17)
==13632==  Address 0x4ae5a58 is in the BSS segment of /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33
==13632== 
==13632== ----------------------------------------------------------------
==13632== 
==13632== Possible data race during read of size 1 at 0x4AE5A79 by thread #2
==13632== Locks held: none
==13632==    at 0x49C146F: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x109339: worker(int*) (35_Segmentation_fault_thread.cpp:8)
==13632==    by 0x10A191: void std::__invoke_impl<void, void (*)(int*), int*>(std::__invoke_other, void (*&&)(int*), int*&&) (invoke.h:61)
==13632==    by 0x10A0F2: std::__invoke_result<void (*)(int*), int*>::type std::__invoke<void (*)(int*), int*>(void (*&&)(int*), int*&&) (invoke.h:96)
==13632==    by 0x10A052: void std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==13632==    by 0x10A007: std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::operator()() (std_thread.h:299)
==13632==    by 0x109FE7: std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)(int*), int*> > >::_M_run() (std_thread.h:244)
==13632==    by 0x4956DB3: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x4854B7A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4BB2AA3: start_thread (pthread_create.c:447)
==13632==    by 0x4C3FA33: clone (clone.S:100)
==13632== 
==13632== This conflicts with a previous write of size 1 by thread #1
==13632== Locks held: none
==13632==    at 0x494E803: std::ctype<char>::_M_widen_init() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C0A3F: std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x1093D7: main (35_Segmentation_fault_thread.cpp:17)
==13632==  Address 0x4ae5a79 is in the BSS segment of /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33
==13632== 
==13632== ----------------------------------------------------------------
==13632== 
==13632== Possible data race during read of size 1 at 0x4AE5A58 by thread #2
==13632== Locks held: none
==13632==    at 0x49C0A0F: std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x10934B: worker(int*) (35_Segmentation_fault_thread.cpp:8)
==13632==    by 0x10A191: void std::__invoke_impl<void, void (*)(int*), int*>(std::__invoke_other, void (*&&)(int*), int*&&) (invoke.h:61)
==13632==    by 0x10A0F2: std::__invoke_result<void (*)(int*), int*>::type std::__invoke<void (*)(int*), int*>(void (*&&)(int*), int*&&) (invoke.h:96)
==13632==    by 0x10A052: void std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==13632==    by 0x10A007: std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::operator()() (std_thread.h:299)
==13632==    by 0x109FE7: std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)(int*), int*> > >::_M_run() (std_thread.h:244)
==13632==    by 0x4956DB3: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x4854B7A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4BB2AA3: start_thread (pthread_create.c:447)
==13632==    by 0x4C3FA33: clone (clone.S:100)
==13632== 
==13632== This conflicts with a previous write of size 1 by thread #1
==13632== Locks held: none
==13632==    at 0x494E8CF: std::ctype<char>::_M_widen_init() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C0A3F: std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x1093D7: main (35_Segmentation_fault_thread.cpp:17)
==13632==  Address 0x4ae5a58 is in the BSS segment of /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33
==13632== 
==13632== ----------------------------------------------------------------
==13632== 
==13632== Possible data race during read of size 1 at 0x4AE5A63 by thread #2
==13632== Locks held: none
==13632==    at 0x49C0A1A: std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x10934B: worker(int*) (35_Segmentation_fault_thread.cpp:8)
==13632==    by 0x10A191: void std::__invoke_impl<void, void (*)(int*), int*>(std::__invoke_other, void (*&&)(int*), int*&&) (invoke.h:61)
==13632==    by 0x10A0F2: std::__invoke_result<void (*)(int*), int*>::type std::__invoke<void (*)(int*), int*>(void (*&&)(int*), int*&&) (invoke.h:96)
==13632==    by 0x10A052: void std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==13632==    by 0x10A007: std::thread::_Invoker<std::tuple<void (*)(int*), int*> >::operator()() (std_thread.h:299)
==13632==    by 0x109FE7: std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)(int*), int*> > >::_M_run() (std_thread.h:244)
==13632==    by 0x4956DB3: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x4854B7A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==13632==    by 0x4BB2AA3: start_thread (pthread_create.c:447)
==13632==    by 0x4C3FA33: clone (clone.S:100)
==13632== 
==13632== This conflicts with a previous write of size 2 by thread #1
==13632== Locks held: none
==13632==    at 0x494E7EB: std::ctype<char>::_M_widen_init() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x49C0A3F: std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==13632==    by 0x1093D7: main (35_Segmentation_fault_thread.cpp:17)
==13632==  Address 0x4ae5a63 is in the BSS segment of /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33
==13632== 
Worker accessing ptr: 42
==13632== 
==13632== Use --history-level=approx or =none to gain increased speed, at
==13632== the cost of reduced accuracy of conflicting-access information
==13632== For lists of detected and suppressed errors, rerun with: -s
==13632== ERROR SUMMARY: 6 errors from 6 contexts (suppressed: 43 from 19)

*/