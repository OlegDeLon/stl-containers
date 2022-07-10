
#include "../s21_list.h"

TEST(ListConstruct, test1) {
  s21::list<int> mylist;
  std::list<int> list;
  ASSERT_TRUE(mylist.empty() == list.empty());
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.max_size() == list.max_size());
}

TEST(ListConstruct, test2) {
  s21::list<int> mylist(4);
  std::list<int> list(4);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test3) {
  s21::list<int> mylist(15, 8);
  std::list<int> list(15, 8);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test4) {
  s21::list<int> mylist({2, 456, 8});
  std::list<int> list = {2, 456, 8};
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test5) {
  s21::list<double> mylist({7.8, 4.56, 0.7, 10.12});
  std::list<double> list = {7.8, 4.56, 0.7, 10.12};
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test6) {
  s21::list<char> mylist({'s', 'n', 'a', 'p', 'e'});
  std::list<char> list = {'s', 'n', 'a', 'p', 'e'};
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test7) {
  s21::list<std::string> mylist({"the", "Boy", "Who", "Lived"});
  std::list<std::string> list = {"the", "Boy", "Who", "Lived"};
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test8) {
  s21::list<std::string> mylist2({"the", "Boy", "Who", "Lived"});
  s21::list<std::string> mylist(mylist2);
  std::list<std::string> list2 = {"the", "Boy", "Who", "Lived"};
  std::list<std::string> list(list2);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, tes9) {
  s21::list<std::string> mylist2({"the", "Boy", "Who", "Lived"});
  s21::list<std::string> mylist = mylist2;
  std::list<std::string> list2 = {"the", "Boy", "Who", "Lived"};
  std::list<std::string> list = list2;
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test10) {
  s21::list<int> mylist2({85, 356, 3, 165});
  s21::list<int> mylist = mylist2;
  std::list<int> list2 = {85, 356, 3, 165};
  std::list<int> list = list2;
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListConstruct, test11) {
  s21::list<int> mylist2({85, 356, 3, 165});
  s21::list<int> mylist;
  mylist = std::move(mylist2);
  std::list<int> list2 = {85, 356, 3, 165};
  std::list<int> list;
  list = std::move(list2);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListPush, test1) {
  s21::list<int> mylist(4);
  mylist.push_back(12);
  std::list<int> list(4);
  list.push_back(12);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListPush, test2) {
  s21::list<int> mylist;
  mylist.push_back(9);
  std::list<int> list;
  list.push_back(9);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListPush, test3) {
  s21::list<int> mylist({17, 83, 932, 9, 124});
  mylist.push_back(-8);
  std::list<int> list = {17, 83, 932, 9, 124};
  list.push_back(-8);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListPush, test4) {
  s21::list<int> mylist({17, 83, 932, 9, 124});
  mylist.push_front(-152);
  std::list<int> list = {17, 83, 932, 9, 124};
  list.push_front(-152);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListPush, test5) {
  s21::list<int> mylist;
  mylist.push_front(-1);
  std::list<int> list;
  list.push_front(-1);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListPush, test6) {
  s21::list<int> mylist(2, 83);
  mylist.push_front(92);
  std::list<int> list(2, 83);
  list.push_front(92);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListPop, test1) {
  s21::list<int> mylist(2, 83);
  mylist.pop_front();
  std::list<int> list(2, 83);
  list.pop_front();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListPop, test2) {
  s21::list<int> mylist({17, 83, 932, 9, 124});
  mylist.pop_front();
  std::list<int> list = {17, 83, 932, 9, 124};
  list.pop_front();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListPop, test3) {
  s21::list<std::string> mylist{"Serpensortia", "Vipera", "Evanescо"};
  std::list<std::string> list = {"Serpensortia", "Vipera", "Evanescо"};
  mylist.pop_back();
  list.pop_back();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListSwap, test1) {
  s21::list<int> mylist2({85, 356, 3, 165});
  s21::list<int> mylist;
  std::list<int> list2 = {85, 356, 3, 165};
  std::list<int> list;
  mylist.swap(mylist2);
  list.swap(list2);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListSwap, test2) {
  s21::list<std::string> mylist{"Lumos", "Maxima", "Nox"};
  std::list<std::string> list{"Lumos", "Maxima", "Nox"};
  s21::list<std::string> mylist2;
  std::list<std::string> list2;
  mylist.swap(mylist2);
  list.swap(list2);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.empty() == list.empty());
}

TEST(ListErase, test1) {
  s21::list<int> mylist({85, 356, 3, 165});
  std::list<int> list = {85, 356, 3, 165};
  s21::list<int>::iterator it_m = ++mylist.begin();
  std::list<int>::iterator it_l = ++list.begin();
  mylist.erase(it_m);
  list.erase(it_l);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListErase, test2) {
  s21::list<std::string> mylist{"Engorgio", "Reducio"};
  std::list<std::string> list{"Engorgio", "Reducio"};
  s21::list<std::string>::iterator it_m = mylist.begin();
  std::list<std::string>::iterator it_l = list.begin();
  mylist.erase(it_m);
  list.erase(it_l);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListErase, test3) {
  s21::list<double> mylist({8.5, 35.6, 3, 1.65});
  std::list<double> list = {8.5, 35.6, 3, 1.65};
  s21::list<double>::iterator it_m = --mylist.end();
  std::list<double>::iterator it_l = --list.end();
  mylist.erase(it_m);
  list.erase(it_l);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListInsert, test1) {
  s21::list<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::list<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  mylist.insert(it_m, -842);
  list.insert(it_l, -842);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListInsert, test2) {
  s21::list<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::list<int>::iterator it_m = ++mylist.begin();
  std::list<int>::iterator it_l = ++list.begin();
  mylist.insert(it_m, -842);
  list.insert(it_l, -842);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListInsert, test3) {
  s21::list<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::list<int>::iterator it_m = mylist.end();
  std::list<int>::iterator it_l = list.end();
  mylist.insert(it_m, -842);
  list.insert(it_l, -842);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListInsert, test4) {
  s21::list<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::list<int>::iterator it_m = --mylist.end();
  std::list<int>::iterator it_l = --list.end();
  mylist.insert(it_m, -82);
  list.insert(it_l, -82);
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListInsert, test5) {
  s21::list<std::string> mylist{"Stupefy", "Prior Incantato"};
  std::list<std::string> list{"Stupefy", "Prior Incantato"};
  s21::list<std::string>::iterator it_m = mylist.begin();
  std::list<std::string>::iterator it_l = list.begin();
  mylist.insert(it_m, "Expelliarmus");
  list.insert(it_l, "Expelliarmus");
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListSort, test1) {
  s21::list<int> mylist{85, 356, 3, 165};
  std::list<int> list = {85, 356, 3, 165};
  mylist.sort();
  list.sort();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

TEST(ListSort, test2) {
  s21::list<int> mylist{17, 83, 932, 9, 124};
  std::list<int> list = {17, 83, 932, 9, 124};
  mylist.sort();
  list.sort();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListSort, test3) {
  s21::list<std::string> mylist{"Serpensortia", "Vipera", "Evanescо"};
  std::list<std::string> list = {"Serpensortia", "Vipera", "Evanescо"};
  mylist.sort();
  list.sort();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}
TEST(ListUnique, test1) {
  s21::list<int> mylist{85, 85, 356, 3, 3, 165};
  std::list<int> list = {85, 85, 356, 3, 3, 165};
  mylist.unique();
  list.unique();
  ASSERT_TRUE(mylist.size() == list.size());
  ASSERT_TRUE(mylist.back() == list.back());
  ASSERT_TRUE(mylist.front() == list.front());
}

// TEST(ListUnique, test2) {
//   s21::list<int> mylist{85, 85, 356, 3, 3, 165};
//   std::list<int> list = {85, 85, 356, 3, 3, 165};
//   mylist.unique();
//   list.unique();
//   s21::list<int>::iterator it_m = mylist.begin();
//   std::list<int>::iterator it_l = list.begin();
//   while (it_m != mylist.end()) {
//     ASSERT_TRUE(*it_m == *it_l);
//     ++it_l;
//     ++it_m;
//   }
//   ASSERT_TRUE(mylist.size() == list.size());
// }

// TEST(ListUnique, test3) {
//   s21::list<int> mylist{17, 17, 17, 17, 83, 932, 9, 9, 9, 124};
//   std::list<int> list{17, 17, 17, 17, 83, 932, 9, 9, 9, 124};
//   mylist.unique();
//   list.unique();
//   s21::list<int>::iterator it_m = mylist.begin();
//   std::list<int>::iterator it_l = list.begin();
//   while (it_m != mylist.end()) {
//     ASSERT_TRUE(*it_m == *it_l);
//     ++it_l;
//     ++it_m;
//   }
//   ASSERT_TRUE(mylist.size() == list.size());
// }

// TEST(ListUnique, test4) {
//   s21::list<char> mylist{'l', 'o', 'o', 'o', 'c', 'k', 'h', 'a', 'r', 't'};
//   std::list<char> list = {'l', 'o', 'o', 'o', 'c', 'k', 'h', 'a', 'r', 't'};
//   mylist.unique();
//   list.unique();
//   s21::list<char>::iterator it_m = mylist.begin();
//   std::list<char>::iterator it_l = list.begin();
//   while (it_m != mylist.end()) {
//     ASSERT_TRUE(*it_m == *it_l);
//     ++it_l;
//     ++it_m;
//   }
//   ASSERT_TRUE(mylist.size() == list.size());
// }

TEST(ListSplice, test1) {
  s21::list<int> mylist{85, 356, 3, 165};
  std::list<int> list = {85, 356, 3, 165};
  s21::list<int> mylist2{1, 3, 25};
  std::list<int> list2 = {1, 3, 25};
  s21::list<int>::const_iterator itm = mylist.cbegin();
  std::list<int>::const_iterator itl = list.cbegin();
  mylist.splice(itm, mylist2);
  list.splice(itl, list2);
  s21::list<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}

TEST(ListSplice, test2) {
  s21::list<int> mylist{85, 356, 42, 165};
  std::list<int> list = {85, 356, 42, 165};
  s21::list<int> mylist2{1, 3, 2};
  std::list<int> list2 = {1, 3, 2};
  s21::list<int>::const_iterator itm = mylist.cend();
  std::list<int>::const_iterator itl = list.cend();
  --itm;
  --itl;
  mylist.splice(itm, mylist2);
  list.splice(itl, list2);
  s21::list<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}
TEST(ListSplice, test3) {
  s21::list<char> mylist{'l', 'o', 'c', 'k', 'h', 'a', 'r', 't'};
  std::list<char> list = {'l', 'o', 'c', 'k', 'h', 'a', 'r', 't'};
  s21::list<char> mylist2{'g', 'i', 'l', 'd', 'e', 'r', 'o', 'y'};
  std::list<char> list2 = {'g', 'i', 'l', 'd', 'e', 'r', 'o', 'y'};
  s21::list<char>::const_iterator itm = mylist.cbegin();
  std::list<char>::const_iterator itl = list.cbegin();
  mylist.splice(itm, mylist2);
  list.splice(itl, list2);
  s21::list<char>::iterator it_m = mylist.begin();
  std::list<char>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}

TEST(ListReverse, test1) {
  s21::list<int> mylist{85, 356, 3, 165};
  std::list<int> list = {85, 356, 3, 165};
  mylist.reverse();
  list.reverse();
  s21::list<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}

TEST(ListReverse, test2) {
  s21::list<int> mylist{17, 83, 932, 9, 124};
  std::list<int> list = {17, 83, 932, 9, 124};
  mylist.reverse();
  list.reverse();
  s21::list<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}
TEST(ListReverse, test3) {
  s21::list<std::string> mylist{"Serpensortia", "Vipera", "Evanescо"};
  std::list<std::string> list = {"Serpensortia", "Vipera", "Evanescо"};
  mylist.reverse();
  list.reverse();
  s21::list<std::string>::iterator it_m = mylist.begin();
  std::list<std::string>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}

TEST(ListMerge, test1) {
  s21::list<int> mylist{2, 3, 32, 165};
  std::list<int> list = {2, 3, 32, 165};
  s21::list<int> mylist2{1, 8, 25};
  std::list<int> list2 = {1, 8, 25};
  mylist.merge(mylist2);
  list.merge(list2);
  s21::list<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}

TEST(ListMerge, test2) {
  s21::list<double> mylist{2.3, 4.3, 8.32, 10.165};
  std::list<double> list = {2.3, 4.3, 8.32, 10.165};
  s21::list<double> mylist2{11.1, 15.9, 25.9, 73.5, 134.0};
  std::list<double> list2 = {11.1, 15.9, 25.9, 73.5, 134.0};
  mylist.merge(mylist2);
  list.merge(list2);
  s21::list<double>::iterator it_m = mylist.begin();
  std::list<double>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == list.size());
}

TEST(ListEmplase, test1) {
  s21::list<int> mylist{2, 3, 32, 165};
  mylist.emplace_back(5, 18);
  s21::list<int> mylist2{2, 3, 32, 165, 5, 18};
  s21::list<int>::iterator it_m = mylist.begin();
  s21::list<int>::iterator it_2 = mylist2.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_2);
    ++it_2;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == mylist2.size());
}
TEST(ListEmplase, test2) {
  s21::list<int> mylist{2, 3, 32, 165};
  mylist.emplace_front(5, 18);
  s21::list<int> mylist2{18, 5, 2, 3, 32, 165};
  s21::list<int>::iterator it_m = mylist.begin();
  s21::list<int>::iterator it_2 = mylist2.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_2);
    ++it_2;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == mylist2.size());
}
TEST(ListEmplase, test3) {
  s21::list<int> mylist{2, 3, 32, 165};
  s21::list<int>::const_iterator it = mylist.cbegin();
  ++it;
  mylist.emplace(it, 5, 18);
  s21::list<int> mylist2{2, 5, 18, 3, 32, 165};
  s21::list<int>::iterator it_m = mylist.begin();
  s21::list<int>::iterator it_2 = mylist2.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_2);
    ++it_2;
    ++it_m;
  }
  ASSERT_TRUE(mylist.size() == mylist2.size());
}
