

#include <future>
#include <iostream>
#include <functional>
#include <thread>

using namespace std;
template<typename iterator>
void par(iterator iter1, iterator iter2, const std::function<void(int&)>& func) {

  auto size = distance(iter1, iter2);

  if (size <= 1) {
    return;
  }

  iterator middle = iter1;
  std::advance(middle, size / 2);

  thread first_thread(
    [&middle,&iter2,&func]() { for_each(middle, iter2, func); });


  for_each(iter1, middle, func);


  first_thread.join();
   

}
int main() {

  std::vector<int> vec1;

  for (int i = 0; i < 10; i++) {
    vec1.push_back(i);
  }
  auto lamda = [](int& a) { ++a; };

  for (auto& temp : vec1) {
    cout << temp << endl;
  }
  cout << endl;

  par(vec1.begin(), vec1.end(), lamda);

 

 for (auto& temp : vec1) {
  
     cout << temp << endl;
 }

}

