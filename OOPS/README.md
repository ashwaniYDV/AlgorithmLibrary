### Important QnA

```
1) Can static functions be virtual in C++? 
   OR 
   Can virtual functions be static in C++?

Ans.

No, because it doesn't make any sense in C++.
Virtual functions are invoked when you have a pointer/reference to an instance of a class. 
Static functions aren't tied to a particular instance, they're tied to a class. 
C++ doesn't have pointers-to-class, so there is no scenario in which you could invoke a static function virtually.

The static member function can't access non-static data members/functions of a class. 
The vPTR is non-static data member, hence a static member function can't access vPTR.

There is one difference between static function and not static (member) function.
That is static function doesn't have this pointer but member function have this pointer.
The virtual function is handled by vptr and vtable vptr is a pointer which initialized by constructor of a class 
and vptr is accessible by this pointer only because it is the member of that class 
and vptr points to vtable where the address of virtual function stored and it will call that function.
And you any static function doesn't have this pointer so that static functions are unable to access vptr.
Thats why any static function can't be virtual.
You can check it your class has at least one virtual function then class size will increase by 4 (size of pointer)
```
