
#include "../s21_queue.h"

TEST(QueueConstruct, test1) {
  s21::queue<int> myqueue;
  std::queue<int> queue;
  ASSERT_TRUE(myqueue.empty() == queue.empty());
  ASSERT_TRUE(myqueue.size() == queue.size());
}

TEST(QueueConstruct, test2) {
  s21::queue<int> myqueue{2, 456, 8};
  std::queue<int> queue;
  queue.push(2);
  queue.push(456);
  queue.push(8);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  ASSERT_TRUE(myqueue.front() == queue.front());
}

TEST(QueueConstruct, test3) {
  s21::queue<double> myqueue{7.8, 4.56, 0.7, 10.12};
  std::queue<double> queue;
  queue.push(7.8);
  queue.push(4.56);
  queue.push(0.7);
  queue.push(10.12);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  ASSERT_TRUE(myqueue.front() == queue.front());
}

TEST(QueueConstruct, test4) {
  s21::queue<std::string> myqueue2{"the", "Boy", "Who", "Lived"};
  s21::queue<std::string> myqueue(myqueue2);
  std::queue<std::string> queue2;
  queue2.push("the");
  queue2.push("Boy");
  queue2.push("Who");
  queue2.push("Lived");
  std::queue<std::string> queue(queue2);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  ASSERT_TRUE(myqueue.front() == queue.front());
}

TEST(QueueConstruct, tes5) {
  s21::queue<std::string> myqueue2{"the", "Boy", "Who", "Lived"};
  s21::queue<std::string> myqueue(myqueue2);
  std::queue<std::string> queue2;
  queue2.push("the");
  queue2.push("Boy");
  queue2.push("Who");
  queue2.push("Lived");
  std::queue<std::string> queue = queue2;
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  ASSERT_TRUE(myqueue.front() == queue.front());
}

TEST(QueueConstruct, test6) {
  s21::queue<int> myqueue2{85, 356, 3, 156};
  s21::queue<int> myqueue(myqueue2);
  std::queue<int> queue2;
  queue2.push(85);
  queue2.push(356);
  queue2.push(3);
  queue2.push(156);
  std::queue<int> queue = queue2;
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  ASSERT_TRUE(myqueue.front() == queue.front());
  ASSERT_TRUE(myqueue2.size() == queue2.size());
  ASSERT_TRUE(myqueue2.back() == queue2.back());
  ASSERT_TRUE(myqueue2.front() == queue2.front());
}
TEST(QueueConstruct, test7) {
  s21::queue<int> myqueue2{85, 356, 3, 156};
  s21::queue<int> myqueue;
  myqueue = std::move(myqueue2);
  std::queue<int> queue2;
  queue2.push(85);
  queue2.push(356);
  queue2.push(3);
  queue2.push(156);
  std::queue<int> queue;
  queue = std::move(queue2);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  ASSERT_TRUE(myqueue.front() == queue.front());
  ASSERT_TRUE(myqueue2.size() == queue2.size());
  ASSERT_TRUE(myqueue2.empty() == queue2.empty());
}

TEST(ListPopPush, test1) {
  s21::queue<int> myqueue;
  myqueue.push(12);
  std::queue<int> queue;
  queue.push(12);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  while (myqueue.empty() == 0) {
    ASSERT_TRUE(myqueue.front() == queue.front());
    myqueue.pop();
    queue.pop();
  }
}

TEST(ListPopPush, test2) {
  s21::queue<int> myqueue;
  myqueue.push(9);
  myqueue.push(12);
  std::queue<int> queue;
  queue.push(9);
  queue.push(12);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  while (myqueue.empty() == 0) {
    ASSERT_TRUE(myqueue.front() == queue.front());
    myqueue.pop();
    queue.pop();
  }
}
TEST(ListPopPush, test3) {
  s21::queue<int> myqueue{83};
  myqueue.push(932);
  myqueue.push(-8);
  std::queue<int> queue;
  queue.push(83);
  queue.push(932);
  queue.push(-8);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  while (myqueue.empty() == 0) {
    ASSERT_TRUE(myqueue.front() == queue.front());
    myqueue.pop();
    queue.pop();
  }
}

TEST(ListSwapp, test1) {
  s21::queue<int> myqueue2{85, 356, 3, 165};
  s21::queue<int> myqueue;
  std::queue<int> queue2;
  queue2.push(85);
  queue2.push(356);
  queue2.push(3);
  queue2.push(165);
  std::queue<int> queue;
  myqueue.swap(myqueue2);
  queue.swap(queue2);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.back() == queue.back());
  while (myqueue.empty() == 0) {
    ASSERT_TRUE(myqueue.front() == queue.front());
    myqueue.pop();
    queue.pop();
  }
}
TEST(ListSwapp, test2) {
  s21::queue<std::string> myqueue{"Lumos", "Maxima", "Nox"};
  std::queue<std::string> queue;
  s21::queue<std::string> myqueue2;
  queue.push("Lumos");
  queue.push("Maxima");
  queue.push("Nox");
  std::queue<std::string> queue2;
  myqueue.swap(myqueue2);
  queue.swap(queue2);
  ASSERT_TRUE(myqueue.size() == queue.size());
  ASSERT_TRUE(myqueue.empty() == queue.empty());
}

TEST(ListEmplasee, test1) {
  s21::queue<int> myqueue{2, 3, 32, 165};
  myqueue.emplace_back(5, 18);
  s21::queue<int> myqueue2{2, 3, 32, 165, 5, 18};
  ASSERT_TRUE(myqueue.size() == myqueue2.size());
  while (myqueue.empty() == 0) {
    ASSERT_TRUE(myqueue.front() == myqueue2.front());
    myqueue.pop();
    myqueue2.pop();
  }
}
