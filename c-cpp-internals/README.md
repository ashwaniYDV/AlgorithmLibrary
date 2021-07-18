### How does free know how much to free?
* https://stackoverflow.com/questions/1518711/how-does-free-know-how-much-to-free
* malloc takes size and returns a pointer to the start location of memory you requested (slightly more based on the os page size)
* free takes only a pointer and somehow it can tell exactly how much memory that pointer was allocated and free that much exactly. 
* turns out one implementation at least is to store metadata about the allocation in a fixed header right before the pointer.
* So free technically walks back X bytes to read the header, find out how much memory it needs to free and calls mmap to remove the virtual memory mapping’s essentially for that process. 
