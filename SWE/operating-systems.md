# Operating Systems

## Memory

- `Byte` is the smallest addressable unit of memory.
- The stack is the memory set aside as scratch space for a thread of execution. When a function is called, a block (also called *stack frame*) is reserved on the top of the stack for local variables and some bookkeeping data. When that function returns, the block becomes unused and can be used the next time a function is called. The stack is always reserved in a LIFO order; the most recently reserved block is always the next block to be freed. This makes it really simple to keep track of the stack; freeing a block from the stack is nothing more than adjusting one pointer.
- The heap is memory set aside for dynamic allocation. Unlike the stack, there's no enforced pattern to the allocation and deallocation of blocks from the heap; you can allocate a block at any time and free it at any time.
- Each thread gets a stack, while there's typically only one heap for the application (although it isn't uncommon to have multiple heaps for different types of allocation).
- The stack is attached to a thread, so when the thread exits the stack is reclaimed. The heap is typically allocated at application startup by the runtime, and is reclaimed when the application (technically process) exits.
- The size of the stack is set when a thread is created. The size of the heap is set on application startup, but can grow as space is needed (the allocator requests more memory from the operating system).
- The stack is faster because the access pattern makes it trivial to allocate and deallocate memory from it (a pointer/integer is simply incremented or decremented), while the heap has much more complex bookkeeping involved in an allocation or memory freeing. Also, each byte in the stack tends to be reused very frequently which means it tends to be mapped to the processor's cache, making it very fast.
- *Virtual memory* technique virtualizes the main storage available to a process or task, as a contiguous address space which is unique to each running process, or virtualizes the main storage available to all processes or tasks on the system as a contiguous global address space.
- [Virtual memory illustrated](http://en.wikipedia.org/wiki/File:Virtual_memory.svg)
- `x64` is 64 bit platform while `x86` is 32bit platform. Pointers are 64 bit vs 32 bit.
- 32 bit systems are limited to 4GB memory.

## Mutexes, Semaphores, Locks

- *Lock* is a generic term for an object that works like a key and allows the access to a target object only by one thread. Only the thread which owns the key can unlock the "door".
- *Monitor* is a *cross-thread* lock.
    - In Java every object is a monitor.
- Lock allows only one thread to enter the part that's locked and the lock is not shared with any other processes.
- Mutex and Semaphore are kernel resources that provide synchronization services.

#### Mutex

- Mutex is a *cross-process* lock, same as a lock but system wide.
- Mutex is a locking mechanism used to synchronize access to a resource.
- Mutex provides *mut*ual *ex*clusion, either producer or consumer can have the key (mutex) and proceed with their work.
- Java has no system-wide mutex support.

#### Semaphore

- Semaphore is signaling mechanism ("I am done, you can carry on" kind of signal).
- A particular lock that allows more than one thread to access the target object. It's like having more keys, so that many people can unlock the door.
- Semaphore is a **generalized mutex**; if upper bound is set to one (1) it's the same as a monitor.
- Does the same as a lock but allows `x` number of threads to enter.

## Processes

- A process has a self-contained execution environment. A process generally has a complete, private set of basic run-time resources; in particular, each process has its own memory space.
- Processes are often seen as synonymous with programs or applications. However, what the user sees as a single application may in fact be a set of cooperating processes. To facilitate communication between processes, most operating systems support Inter Process Communication (IPC) resources, such as *pipes* and *sockets*. IPC is used not just for communication between processes on the same system, but processes on different systems.
- Each process has it's own memory space, and addresses memory inside that space.
- Each process can contain many threads.
- Threads share the memory space of its parent process.
- Process resources:
    - Working directory
    - Environment variables
    - File handles
    - Sockets
    - Memory space

### IPC (Inter-Process Communication)

- Sharing data across multiple and commonly specialized processes.
- IPC methods:
    - File – record stored on disk, or a record synthesized on demand by a file server, which can be accessed by multiple processes.
    - Signal – system message sent from one process to another, not usually used to transfer data but instead used to remotely command the partnered process.
    - Socket – data stream sent over a network interface, either to a different process on the same computer or to another computer on the network.
    - Pipe – two-way data stream between two processes interfaced through standard input and output and read in one character at a time.
    - Named pipe – pipe implemented through a file on the file system instead of standard input and output.
    - Semaphore – A simple structure that synchronizes multiple processes acting on shared resources.
    - Shared memory – Multiple processes are given access to the same block of memory which creates a shared buffer for the processes to communicate with each other.

### Process Signaling

- Signals are a limited form of inter-process communication used in Unix, Unix-like, and other POSIX-compliant operating systems.
- A signal is an asynchronous notification sent to a process.
- If the process has previously registered a signal handler, that routine is executed. Otherwise, the default signal handler is executed.
- Some signals may be ignored by an application (like `SIGTERM`).
- The kernel can generate signals to notify processes of events.
- For example, `SIGPIPE` will be generated when a process writes to a pipe which has been closed by the reader.
- There are two signals which cannot be intercepted and handled: `SIGKILL` (terminate immediately, no cleanup) and `SIGSTOP`.
- Pressing `Ctrl+C` in the terminal sends `SIGINT` (interrupt) to the process; by default, this causes the process to terminate.
- `$ kill -9` will send a `SIGKILL`.
- Notable signals:
    - `SIGINT` (2) – Terminal interrupt
    - `SIGQUIT` (3) – Terminal quit signal
    - `SIGKILL` (9) – Kill (cannot be caught or ignored)
    - `SIGTERM` (15) – Termination
    - `SIGSTOP` (na) – Stop executing (cannot be caught or ignored)
- In the JVM we can register for `SIGTERM`/`SIGINT` by: `Runtime.getRuntime().addShutdownHook(new Thread(...));`

## Threads

- Threads are sometimes called lightweight processes. Both processes and threads provide an execution environment, but creating a new thread requires fewer resources than creating a new process.
- Threads exist within a process – every process has at least one. Threads share the process' resources, including memory and open files. This makes for efficient, but potentially problematic, communication.
- Thread creation is a costly operation, and resources need to be constructed and obtained for a new thread.
- Creating and tearing down threads isn't free: there'll be some CPU overhead each time we do so.
- There may be some moderate limit on the number of threads that can be created, determined by the resources that a thread needs to have allocated (if a process has 2GB of address space, and each thread has 512KB of stack, that means a maximum of a few thousands threads per process).
- Solution: use a threadpool.

## Thread Scheduler

- Responsible for sharing out the available CPUs in some way among the competing threads.
- On multiprocessor systems, there is generally some kind of scheduler per processor, which then need to be coordinated in some way.
- Most systems use priority-based round-robin scheduling to some extent:
    - A thread of higher priority (which is a function of base and local priorities) will preempt a thread of lower priority.
    - Otherwise, threads of equal priority will essentially take turns at getting an allocated slice or quantum of CPU.
- A thread can be in states:
    - `New` – created and waiting to create needed resources
    - `Runnable` – waiting for CPU allotment
    - `Waiting` – cannot continue, waiting for a resource like lock/IO/memory to be paged/sleep to finish/etc.
    - `Terminated` – finished by waiting to clear resources
- Each thread has a quantum, which is effectively how long it is allowed to keep hold of the CPU.
- Thread quanta are generally defined in terms of some number of clock ticks.
- A clock tick is typically 1ms under Linux.
- A quantum is usually a small number of clock ticks, between 10-200 clock ticks (i.e. 10-200 ms) under Linux.
- At key moments, the thread scheduler considers whether to switch the thread that is currently running on a CPU. These key moments are usually: periodically, if a thread ceases to be runnable, when some other attribute of the thread changes.
- At these decision points, the scheduler's job is essentially to decide, of all the runnable threads, which are the most appropriate to actually be running on the available CPUs.
- Priorities differ between OS, and can be partially set by the user.
- Great article on [CPU Clocks and Clock Interrupts, and Their Effects on Schedulers](http://accu.org/index.php/journals/2185).

### Context Switching

- This is the procedure that takes place when the system switches between threads running on the available CPUs.
- Every time the thread running on a CPU actually changes – often referred to as a context switch – there'll be some negative impact due to, e.g., the interruption of the instruction pipeline or the fact that the processor cache may no longer be relevant.
- Switching between threads of different processes will carry a higher cost, since the address-to-memory mappings must be changed, and the contents of the cache almost certainly will be irrelevant to the next process.
- Context switches appear to typically have a cost somewhere between 1 and 10 microseconds.
- A modest number of fast-case switches — e.g. a thousand per second per CPU will generally be much less than 1% of CPU usage for the context switch per se.
- A few slower-case switches in a second, but where each switched-in thread can do, say, a milliseconds or so of worth of real work (and ideally several milliseconds) once switched in, where the more memory addresses the thread accesses (or the more cache lines it hits), the more milliseconds we want it to run uninterrupted for.
- So the worst case is generally where we have several "juggling" threads which each time they are switched in only do a tiny amount of work (but do some work, thus hitting memory and contending with one another for resources) before context switching.
- The cause of excessive context switching comes from contention on shared resources, particularly synchronized locks:
    - Rarely, a single object very frequently synchronized on could become a bottleneck.
    - More frequently, a complex application has several different objects that are each synchronized on with moderate frequency, but overall, threads find it difficult to make progress because they keep hitting different contended locks at regular intervals.
- Solutions include holding on to locks for less time and (as part of this), reducing the "housekeeping" involved in managing a lock.

## Deadlocks, Livelocks, Starvation

- **Deadlock** describes a situation where two or more threads are blocked forever, waiting for each other.
- Deadlock is the phenomenon when, typically, two threads each hold an exclusive lock that the other thread needs in order to continue.
- In principle, there could actually be more threads and locks involved.
- Deadlock examples:
    - Locking on two different bank account with two threads, in an opposite order.
    - Two friends bowing to each other, and each one only gets up when the other one gets up.
- How to avoid – make locking order fixed (e.g: always lock on the smaller bank account first, sort by identity hash code, etc.).
- **Livelock** – A thread often acts in response to the action of another thread. If the other thread's action is also a response to the action of another thread, then livelock may result. As with deadlock, livelocked threads are unable to make further progress. However, the threads are not blocked – they are simply too busy responding to each other to resume work.
- This is comparable to two people attempting to pass each other in a corridor: Alphonse moves to his left to let Gaston pass, while Gaston moves to his right to let Alphonse pass. Seeing that they are still blocking each other, Alphonse moves to his right, while Gaston moves to his left. They're still blocking each other, so...
- Two thread can communicate with `wait();` and `notifyAll();` (see Java ITC)
- Livelock examples:
    - Two people passing in the corridor
    - Two threads trying to simultaneously avoid a deadlock
    - Husband and wife eating dinner with 1 spoon, and keep passing the spoon to the other spouse
- How to avoid live-locking – try to add some randomness.
- **Starvation** describes a situation where a thread is unable to gain regular access to shared resources and is unable to make progress. This happens when shared resources are made unavailable for long periods by "greedy" threads. For example, suppose an object provides a synchronized method that often takes a long time to return. If one thread invokes this method frequently, other threads that also need frequent synchronized access to the same object will often be blocked.

## Race Conditions

- A race condition occurs when 2 or more threads are able to access shared data and they try to change it at the same time. Because the thread scheduling algorithm can swap between threads at any point, you don't know the order at which the threads will attempt to access the shared data. Therefore, the result of the change in data is dependent on the thread scheduling algorithm, i.e. both threads are 'racing' to access/change the data.
- Often problems occur when one thread does a "check-then-act" (e.g. "check" if the value is X, and then "act" to do something that depends on the value being X) and another thread does something to the value in between the "check" and the "act".
- In order to prevent race conditions occurring, typically you would put a lock around the shared data to ensure that only one thread can access the data at a time.

## Sockets

- A socket is one endpoint of a two-way communication link between two programs running on the network, existing on the transport layer.
- You can send and receive things on a socket, you can bind and listen to a socket.
- A socket is specific to a protocol, machine, and port, and is addressed as such in the header of a packet.
- Socket types:
  - Datagram – Uses [UDP](https://en.wikipedia.org/wiki/User_Datagram_Protocol) for delivering packets. No guaranty for order and delivery.
  - Stream – Typically uses [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) or [SCTP](https://en.wikipedia.org/wiki/Stream_Control_Transmission_Protocol). Order and delivery of packages is guranteed.
  - Raw – No protocol specified on transport layer.
- System calls:
  - `bind` – Assigns a name to an unnamed socket.
  - `connect` – Establish a connection with a server.
  - `accept` – A connection from a client process is waited for by having the server execute the `accept` system call.
  - `send`, `sendto`, `recv` and `recvfrom` – Similar to the standard `read` and `write` system calls.
  - `close` – Close a socket.
