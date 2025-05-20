#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
 
// 共享缓冲区
std::queue<int> buffer;
// 最大缓冲区大小
const unsigned int BUFFER_SIZE = 10;
 
// 互斥锁和条件变量
std::mutex mtx;
std::condition_variable cv_producer;
std::condition_variable cv_consumer;
 
// 生产者线程函数
void producer(int id) {
    int product = 0;
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
 
        // 等待缓冲区有空位
        cv_producer.wait(lock, []() { return buffer.size() < BUFFER_SIZE; });
 
        // 生产数据并放入缓冲区
        product++;
        buffer.push(product);
        std::cout << "Producer " << id << " produced: " << product << std::endl;
 
        // 通知消费者有数据可取
        cv_consumer.notify_all();
 
        // 释放锁，生产间隔一段时间（模拟生产过程）
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
 
// 消费者线程函数
void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
 
        // 等待缓冲区有数据
        cv_consumer.wait(lock, []() { return !buffer.empty(); });
 
        // 消费数据
        int consumed_product = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << id << " consumed: " << consumed_product << std::endl;
 
        // 通知生产者缓冲区有空位
        cv_producer.notify_all();
 
        // 释放锁，消费间隔一段时间（模拟消费过程）
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}
 
int main() {
    // 创建生产者和消费者线程
    std::thread producer1(producer, 1);
    //std::thread producer2(producer, 2);
    std::thread consumer1(consumer, 1);
    //std::thread consumer2(consumer, 2);
 
    // 让主线程等待生产者和消费者线程（通常不会结束）
    producer1.join();
    //producer2.join();
    consumer1.join();
    //consumer2.join();
 
    return 0;
}
