    #include <iostream>  
    #include <vector>  
    using namespace std;  
    int main()   
    {  
      vector<int> vec;    
      vec.push_back(1);   
      vec.push_back(2);   
      vec.push_back(3);  
      vec.push_back(4);   
      vec.push_back(5);  
      vec.push_back(6);   
      vec.push_back(7);   
      vec.push_back(8);  
      vec.push_back(9);   
      vec.push_back(101);  
      for (int i = 0; i < vec.size(); i++)  
      {  
        cout << vec[i] << " ";   
      }  
      return 0;   
    }  