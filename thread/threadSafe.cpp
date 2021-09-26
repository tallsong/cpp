//线程安全
#include <iostream> // std::cout
#include <mutex>    // std::mutex
#include <pthread.h> // pthread_create
// g++  threadSafe.cpp -o threadSafe.out -lpthread -std=c++17
class SingleInstance
{

public:
    // 获取单实例对象
    static SingleInstance* GetInstance();

    //释放单实例，进程退出时调用
    static void deleteInstance();
	
    // 打印实例地址
    void Print();

private:
    // 将其构造和析构成为私有的, 禁止外部构造和析构
    SingleInstance();
    ~SingleInstance();

    // 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
    SingleInstance(const SingleInstance &signal);
    SingleInstance &operator=(const SingleInstance &signal);

private:
    // 唯一单实例对象指针
    static SingleInstance *m_SingleInstance;
    static std::mutex m_Mutex;
};

//初始化静态成员变量
SingleInstance *SingleInstance::m_SingleInstance{nullptr};
std::mutex SingleInstance::m_Mutex{};

SingleInstance* SingleInstance::GetInstance()
{

    //  这里使用了两个 if判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，
    //  避免每次调用 GetInstance的方法都加锁，锁的开销毕竟还是有点大的。
    if (m_SingleInstance == NULL) 
    {
        std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
        if (m_SingleInstance == NULL)
        {
            m_SingleInstance = new (std::nothrow) SingleInstance;
        }
    }

    return m_SingleInstance;
}

void SingleInstance::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
    if (m_SingleInstance)
    {
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}

void SingleInstance::Print()
{
	std::cout << "我的实例内存地址是:" << this << std::endl;
}

SingleInstance::SingleInstance()
{
    std::cout << "构造函数" << std::endl;
}

SingleInstance::~SingleInstance()
{
    std::cout << "析构函数" << std::endl;
}


// 线程函数
void *PrintHello(void *threadid)
{
    // 主线程与子线程分离，两者相互不干涉，子线程结束同时子线程的资源自动回收
    pthread_detach(pthread_self());

    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *)threadid);

    std::cout << "Hi, 我是线程 ID:[" << tid << "]" << std::endl;

    // 打印实例地址
    SingleInstance::GetInstance()->Print();

    pthread_exit(NULL);
}

#define NUM_THREADS 5 // 线程个数

int main(void)
{
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0}; // 用数组来保存i的值

    int ret = 0;
    int i = 0;

    std::cout << "main() : 开始 ... " << std::endl;

    for (i = 0; i < NUM_THREADS; i++)
    {
        std::cout << "main() : 创建线程:[" << i << "]" << std::endl;
        
		indexes[i] = i; //先保存i的值
		
        // 传入的时候必须强制转换为void* 类型，即无类型指针
        ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (ret)
        {
            std::cout << "Error:无法创建线程," << ret << std::endl;
            exit(-1);
        }
    }

    // 手动释放单实例的资源
    SingleInstance::deleteInstance();
    std::cout << "main() : 结束! " << std::endl;
	
    return 0;
}