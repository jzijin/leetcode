//https://blog.csdn.net/fitaotao/article/details/83789209
/*
线程是可执行代码的可分派单元。这个名称来源于“执行的线索”的概念。在基于线程的多任务的环境中，所有进程有至少一个线程，但是它们可以具有多个任务。这意味着单个程序可以并发执行两个或者多个任务。

简而言之，线程就是把一个进程分为很多片，每一片都可以是一个独立的流程。这已经明显不同于多进程了，进程是一个拷贝的流程，而线程只是把一条河流截成很 多条小溪。它没有拷贝这些额外的开销，但是仅仅是现存的一条河流，就被多线程技术几乎无开销地转成很多条小流程，它的伟大就在于它少之又少的系统开销。 
*/
/*
四.比较以及注意事项

1.看完前面，应该对多进程和多线程有个直观的认识。如果总结多进程和多线程的区别，你肯定能说，前者开销大，后者开销较小。确实，这就是最基本的区别。
2.线程函数的可重入性：
说到函数的可重入，和线程安全，我偷懒了，引用网上的一些总结。

线程安全：概念比较直观。一般说来，一个函数被称为线程安全的，当且仅当被多个并发线程反复调用时，它会一直产生正确的结果。

可重入：概念基本没有比较正式的完整解释，但是它比线程安全要求更严格。根据经验，所谓“重入”，常见的情况是，程序执行到某个函数foo()时，收到信 号，于是暂停目前正在执行的函数，转到信号处理函数，而这个信号处理函数的执行过程中，又恰恰也会进入到刚刚执行的函数foo()，这样便发生了所谓的重 入。此时如果foo()能够正确的运行，而且处理完成后，之前暂停的foo()也能够正确运行，则说明它是可重入的。
线程安全的条件：
要确保函数线程安全，主要需要考虑的是线程之间的共享变量。属于同一进程的不同线程会共享进程内存空间中的全局区和堆，而私有的线程空间则主要包括栈和寄 存器。因此，对于同一进程的不同线程来说，每个线程的局部变量都是私有的，而全局变量、局部静态变量、分配于堆的变量都是共享的。在对这些共享变量进行访 问时，如果要保证线程安全，则必须通过加锁的方式。
可重入的判断条件：

要确保函数可重入，需满足一下几个条件：
1、不在函数内部使用静态或全局数据 
2、不返回静态或全局数据，所有数据都由函数的调用者提供。 
3、使用本地数据，或者通过制作全局数据的本地拷贝来保护全局数据。
4、不调用不可重入函数。

可重入与线程安全并不等同，一般说来，可重入的函数一定是线程安全的，但反过来不一定成立。它们的关系可用下图来表示：

比如：strtok函数是既不可重入的，也不是线程安全的；加锁的strtok不是可重入的，但线程安全；而strtok_r既是可重入的，也是线程安全的。

如果我们的线程函数不是线程安全的，那在多线程调用的情况下，可能导致的后果是显而易见的——共享变量的值由于不同线程的访问，可能发生不可预料的变化，进而导致程序的错误，甚至崩溃。

3.关于IPC(进程间通信)

由于多进程要并发协调工作，进程间的同步，通信是在所难免的。

稍微列举一下linux常见的IPC.

linux下进程间通信的几种主要手段简介：

管道（Pipe）及有名管道（named pipe）：管道可用于具有亲缘关系进程间的通信，有名管道克服了管道没有名字的限制，因此，除具有管道所具有的功能外，它还允许无亲缘关系进程间的通信；
信号（Signal）：信号是比较复杂的通信方式，用于通知接受进程有某种事件发生，除了用于进程间通信外，进程还可以发送信号给进程本身；linux除 了支持Unix早期信号语义函数sigal外，还支持语义符合Posix.1标准的信号函数sigaction（实际上，该函数是基于BSD的，BSD为 了实现可靠信号机制，又能够统一对外接口，用sigaction函数重新实现了signal函数）；
报文（Message）队列（消息队列）：消息队列是消息的链接表，包括Posix消息队列system V消息队列。有足够权限的进程可以向队列中添加消息，被赋予读权限的进程则可以读走队列中的消息。消息队列克服了信号承载信息量少，管道只能承载无格式字 节流以及缓冲区大小受限等缺点。
共享内存：使得多个进程可以访问同一块内存空间，是最快的可用IPC形式。是针对其他通信机制运行效率较低而设计的。往往与其它通信机制，如信号量结合使用，来达到进程间的同步及互斥。
信号量（semaphore）：主要作为进程间以及同一进程不同线程之间的同步手段。
套接口（Socket）：更为一般的进程间通信机制，可用于不同机器之间的进程间通信。起初是由Unix系统的BSD分支开发出来的，但现在一般可以移植到其它类Unix系统上：Linux和System V的变种都支持套接字。
或许你会有疑问，那多线程间要通信，应该怎么做？前面已经说了，多数的多线程都是在同一个进程下的，它们共享该进程的全局变量，我们可以通过全局变量来实现线程间通信。如果是不同的进程下的2个线程间通信，直接参考进程间通信。
*/

// https://www.cnblogs.com/fah936861121/articles/8043187.html
// https://www.cnblogs.com/fuchongjundream/p/3829508.html


// 进程是资源分配的基本单位，线程是调度的基本单位。
//进程是资源分配的最小单位，线程是运行的最小单位

但是线程切换是有代价的，因此如果采用多进程，那么就需要将线程所隶属的该进程所需要的内存进行切换，这时间代价是很多的。而线程切换代价就很少，线程是可以共享内存的。所以采用多线程在切换上花费的比多进程少得多。但是，线程切换还是需要时间消耗的，所以采用一个拥有两个线程的进程执行所需要的时间比一个线程的进程执行两次所需要的时间要多一些。即采用多线程不会提高程序的执行速度，反而会降低速度，但是对于用户来说，可以减少用户的响应时间。上述结果只是针对单CPU，如果对于多CPU或者CPU采用超线程技术的话，采用多线程技术还是会提高程序的执行速度的。因为单线程只会映射到一个CPU上，而多线程会映射到多个CPU上，超线程技术本质是多线程硬件化，所以也会加快程序的执行速度。


这里有一个生活实例可能更好地去理解多线程：回去看你女朋友做饭，正常的话她都会把洗好的菜（肉）先放到锅里煮，然后一边洗别的菜或处理别的事情，如：洗碗、收拾桌台准备开饭，人还是一个人，但她同时做几件事情，这样就可以大大地提高效率。总的一句话就是：CPU还是要花同样多的时间去完成所有的事情，但多线程可以让CPU掺插地同时做多件事情，在视觉上让用户觉得计算机在同时帮他处理多件事情，更好地改善用户体验。

    了解了多线程的好处以后，就要了解应该在什么样的情况下使用多线程技术。因为并不是说所有情况下用多线程都是好事，因为多线程的情况下，CPU还要花时间去维护，CPU处理各线程的请求时在线程间的切换也要花时间，所以一般情况下是可以不用多线程的，用了有时反而会得不偿失。大多情况下，要用到多线程的主要是需要处理大量的IO操作时或处理的情况需要花大量的时间等等，比如：读写文件、视频图像的采集、处理、显示、保存等。

https://blog.csdn.net/educast/article/details/13766373

/*

五状态模型：
运行态：
    进程正在执行。
就绪态
    进程做好了准备。只要有机会就开始执行
阻塞/等待态：
    进程在某些时间发生前不能执行，如I/O操作完成前。
新建态：
    刚刚创建的进程，操作系统还未把它加入可执行进程组，它通常是进程控制块已经创建但还未加载到内存中的新进程
退出态：
    操作系统从可执行进程组中释放出的进程，要么它自身已停止，要么它因某种原因被取消 。


操作系统控制计算机内部的事件，为处理器执行进程进行调度和分派，给进程分配资源，并响应用户程序的基本
服务请求。因此，我们可以把操作系统视为管理系统资源的实体。

内存表用于跟踪内存和外存。内存的某些部分为操作系统保留，剩余部分共进程使用，外村中保存的进程使用某种虚存或简单的交换机制。
3.3.2 进程控制结构
    操作系统在管理和控制进程时，首先要知道进程的位置，其次要知道进程的属性（如进程ID、进程状态）
    进程位置：进程的物理表示是什么？属性集称为进程控制块。程序、数据、栈和属性的集合称为进程映像。

    进程控制块信息分为三类：
    进程标识信息 每个进程都分配了一个唯一的数字标识符，进程标识符可以简单的表示为主进程表中的一个索引
    进程状态信息 由处理器寄存器的内容组成。运行一个进程时，进程的信息一定会出现在寄存器中。
    进程控制信息 操作系统控制和协调各种活动进程所需的额外信息。

    进程控制块的作用 ：进程控制快时操作系统中最重要的数据结构。每个进程控制块都包含操作系统所需进程的所有信息
3.4 进程控制
3.4.1 执行模式
    用户模式：用户程序通常在该模式下运行；特权模式称为系统模式、控制模式、或内核模式。内核模式指的是操作系统的内核，他时操作系统中重要的功能成分
3.4.2 进程创建
    1、为新进程分批额一个唯一的进程标识符
    2、为进程分配空间
    3、初始化进程控制块
    4、设置正确的链接。
    5、创建或者扩充其他数据结构
3.4.3 进程切换
    何时切换进程？ 进程切换可在操作系统从当前正运行进程中获得控制权的任何时刻发生

    系统中断。
        时钟中断
        I/O中断：操作系统确定是否已发生I/O活动
        内存失效：处理器遇到一个引用不再内存中的字的虚存地址时，操作系统就必须从外村中把包含这一引用的内存块调入内存。
    陷阱，操作系统则确定错误或异常条件是否致命。
        系统调用激活
        出现中断时，处理器会
            1、将程序计数器设置为中断处理程序的开始地址
            2、从用户模式切换到内核模式，以便中断处理代码包含特权指令
        处理器将中断进程的上下文保存到已中断程序的进程控制块中。保存那些内容？？？
        包含中断处理程序可能改变的所有信息，以及回复被中断程序时所需要的所有信息。因此，必须保存称为处理器状态信息的进曾控制快部分，包含程序计数器，其他处理器寄存器和栈信息

        进程状态的改变。完整的进程切换步骤如下：
        1、保存处理器的上下文，包括程序计数器和其他寄存器
        2、更新但概念处于运行态的进程的进程控制块，包含把进程的转台改变为零一状态
        3、把改进程的进程控制块移到相应的队列
        4、选择另一个进程执行
        5、 更新所选进程控制块，包含把进程的状态改为运行态。
        6、更新内存管理数据结构
        7、载入程序计数器和其他寄存器先前的值，将处理器的上下文恢复为所选进程上次退出运行态时的上下文
    
3.5 操作系统的执行
3.5.1 无进程内核：传统且通用的一种方法是在所有进程外部执行操作系统内核
3.5.2 在用户进程内运行：
    较小计算机的操作系统通常采用另一种方法，即在用户进程的上下文中执行所有操作系统软件
3.5.3 基于进程的操作系统
    把操作系统作为一组系统进程来实现。类似于其他方法，该软件是在内核对模式下运行的内核的一部分。

3.6 UNIX SVR4 进程管理
3.6.1 进程状态
    只有在进程准备从内核模式切换到用户模式时才可能发生抢占，进程在内核模式下运行时不会被强占。
3.6.2 进程描述
    用户及上下文：包含用户程序的基本元素，它可直接由已编辑的目标文件生成。
    寄存器上下文：进程为运行时，处理器状态信息保存在寄存器上下文区域中
    系统级上下文 包含操作系统管理进程所需的其余信息，它由静态部分和动态部分组成
    静态部分的大小在进程的声明周期内固定不变，动态部分的大小在进程的声明周期内可变
3.6.3 进程控制
    UNIX的进程创建是由内核系统调用fork() 实现的。一个进程发出fork() 请求时
    操作系统执行如下功能：
    1、在进程表中为新进程分配一个空项
    2、为子进程分配一个唯一标识符
    3、复制父进程的进程映像，但共享内存除外
    4、增加父进程所拥有文件的计数器，反映另一个进程现在也拥有这下文件的事实
    5、将子进程设置为就绪态
    6、把子进程的ID号返回给父进程，将0值返回给子进程
3.7 小结：
    现代操作系统中最基本的构建是进程，操作系统的基本功能就是创建、管理和终止进程。
    当进程处于活跃状态时，操作系统不惜设法使每个进程都分配到处理器执行时间，并协调它们的活动、管理有冲突的请求、给进程分配系统资源。



第四章 线程
4.1进程和线程
    进程具有如下两个特点
        资源所有权
        调度/执行
    为区分这两个特点，我们通常将分派的单位称为线程或轻量级进程，而拥有资源所有权的单位称为进程。
4.1.1 多线程
    多线程是指操作系统在单个进程内执行多个并发执行路径的能力。每个进程中仅执行单个线程的传统方法
称为单线程方法（single-threaded approach）
    在单线程进程模型中（无明确的线程概念），进程的表示包括进程控制块
和用户地址空间，以及在进程执行中管理调用/返回行为的用户栈和内容栈。进程正运行时，
处理器寄存器由该进程控制；进程为运行时，将保存这些处理器寄存器中的内容。在多线程换环境中，
进程仍然只有一个与之关联的进程控制块和用户地址空间，但每个线程现在会有许多单独的栈和一个单独
的控制块，控制块中包含寄存器值、优先级和其他与线程相关的状态信息。
    因此，进程中的线程共享进程状态和资源，所有线程都驻留在同一块地址空间中，并可访问相同的数据。
当某个线程改变了内存中的一个数据项时，其他线程在访问这一数据项时会看到这一变化。

TODO: 线程的优点：
    1、在已有进程中创建一个新线程的时间，远少于创建一个全新进程的时间。
    2、终止线程要比终止进程所花的时间少。
    3、同一进程内线程间切换的时间，要少于进程间切换的时间
    4、线程提高了不同执行程序间通信的效率。在多数操作系统中，独立进程间通信需要内核介入
    以提供保护和通信所需的机制。但是，由于同一进程中的多个线程共享内存和文件，因此他们无需调用内核就可以互相通信。

    因此，若将一个应用程序或函数实现为一组相关联的执行单元，则用一组线程要比用一组分离的进程更有效。
    单用户多处理系统中使用线程的4个例子：
    1、前台和后台工作：一个线程显示菜单，另一线程执行用户命令
    2、异步处理：程序中的异步元素可用线程来实现。
    3、执行速度：多线程进程在计算一批数据时，可通过设备读取下一批数据。这样即使一个线程
    在读取数据时被I/O操作阻塞，另一个线程仍然可以继续运行。
    4、模块化程序结构：涉及多种活动或多种输入/输出源和目的的程序，更容易使用线程来设计和实现。

    进程的终止会使得进程中的所有线程都终止。

4.1.2 线程的功能
    线程状态 
        派生：派生一个新进程时，同时也会为该进程派生一个线程。
        阻塞：线程需要等待一个时间时会被阻塞（保存线程的用户寄存器、程序计数器和栈指针），处理器转而执行另一个就绪线程
        接触阻塞：
        结束：一个线程完成后，会释放其寄存器上下文和栈
    
    线程同步：一个进程中的所有线程共享同一个地址空间和诸如打开的文件之类的其他资源。
    一个线程对资源的任何修改都会影响同一进程中其他线程的环境，因此需要同步分钟线程的活动，
    以便他们互不干扰且不破坏数据结构。

4.2 线程分类
4.2.1 用户级和内核级线程
    用户级线程 在纯ULT软件中，管理线程的所有工作都由应用程序完成，内核意识不到线程的存在。

4.3 多核和多进程
4.3.1 多核系统上的软件性能：
    加速比 = 在单个处理器上执行程序的时间/在N个并行处理器上执行程序的时间

4.4 Windows8的进程和线程管理
    应用程序： 有一个或多个进程组成。每个进程提供执行程序多需要的资源。
        每个进程都以一个称为主线程的单线程开始，但它可由任何一个线程创建其他线程。
    线程：是进程中可被调度执行的实体。一个进程的所有线程共享其虚拟内存空间和系统资源。
    作业对象：允许将一组线程当作一个单元来管理。
    线程池：是一个工作线程集，它可代表应用程序有效地执行异步回调。
    纤程：是必须由应用程序调度的一个可执行单元。每个线程可以调度多个纤程。
    用户模式调度 是应用程序用于安排自己的线程的一种轻量级机制。
4.4.2 Windows进程
    重要特点：
        Windows进程作为对象实现。
        一个进程可被创建为一个新进程，或一个已有进程的副本。
        一个可执行的进程可包含一个或多个线程。
        进程对象和线程对象都内置有同步能力。
    
4.4.3 进程对象和线程对象

4.4.4 多线程
    由于不同进程的线程可并发执行（看起来同时执行），因此Windows支持进程间的并发性
    一个含有多线程的进程在实现并发时，不需要使用多进程的开销。同一个进程中的线程可通过它们的公共地址交换信息，
    并访问进程中的共享资源。不同进程中的线程可通过在两个进程间建立的共享内存交换信息。

4.4.5 线程状态
    就绪态、备用态、运行态、等待态、过渡态、终止态
4.4.6 对操作系统子系统的支持

4.5 Solaris 的线程和SMP管理
4.6 Linux的进程和线程管理
4.6.1 Linux 任务
    Linux中的进程或任务由一个task_struct数据结构表示，
4.6.2 Linux线程
    老版本的Linux内核不支持多线程。多线程应用程序需要一组用户级程序库来编写，
    以便将所有线程映射到一个单独的内核级进程中，最著名的是pthread库。现代Linux
    提供一种不区分进程和线程的解决方案，将用户级线程映射到内核级进程。组成一个
    用户级的多个用户级线程则映射到共享同一个组ID的多个Linux内核级进程上。

        在了Linux中通过复制当前进程的属性可创建一个新进程。新进程创建后，可以共享资源，如文件、信号处理程序
    和虚存。两个进程共享相同的虚存时，可将它们视为一个进程中的线程。然而没有给线程单独定义数据结构，因此Linux
    中的进程和线程没有区别。Linux用clone()命令代替通常的fork()命令来创建进程。传统的fork()系统调用在Linux上
    是用所有克隆标志清零的clone()系统调用实现的。
4.6.3 Linux命名空间
    Linux中和每个进程相关联的是一组命名空间。命名空间可使一个进程拥有与其他命名空间下的其他进程不同的系统视图。




*/