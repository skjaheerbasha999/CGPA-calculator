// standard templete library 

// about void function 

#include <bits/stdc++.h>
using namespace std;

void print(){
    cout << "sjb";
}
int sum(int a , int b) {
    return a+b;
}
int main(){
    print();                // *output is : sjb
    int s = sum(1,5);
    cout << s;              // *output is : 6 
    return 0;
}

// STL 

// it divided into 4 parts 
/*   1.algorithm 
     2.containers
     3.functions
     4.iterators  */

// pair     
void explainpair() {
    pair<int , int> p = {1,2};      // store two values like {a,b}
    cout << p.first << " " << p.second;   // *output : 1 2

    pair<int, pair<int,int>> q = {1,{2,3}};     // it stores  three values like {a,{b,c}}
    cout << q.first << " " << q.second.first << " " << q.second.second;   // *output : 1 2 3 

    pair <int,int> arr[] = {{1,2},{3,5},{6,7}};  // array pairs
    cout << arr[1].second;                  // *output : 5 
}

//vector    
void explainvectors() {
    vector<int> a;         // a -> {}
    a.push_back(1);        // {} -> {1}
    a.emplace_back(2);     // {1} -> {1,2}

    vector<pair<int,int> a; // pair vector a -> {}
    a.push_back({1,2});        // {} -> {1,2}
    a.emplace_back(1,2);     // {1,2} ->(1,2) it takes as input

    vector<int> a(5,100);    //    {100, 100, 100, 100, 100}
    vector<int> a(5);        // it takes {0, 0, 0, 0, 0} or any garbage value 

    vector<int> a1(3,2);   //  { 2, 2, 2 }
    vector<int> a2(a1);    // {2, 2, 2}

    vector<int>::iterator it = a.begin();   // it access to  the memory. input is {2, 3, 4, 5,7}
    it++;
    cout << *(it) << " ";     // *output is : 3

    it = it + 2;
    cout << *(it) << " ";      // *output : 4

    vector<int>::iterator it = a.end();
    it--;
    cout << *(it) << " ";      // *output is : 7

    cout << a[0] << " " << a.at(0);
    cout << a.back() << " "; 

    for(vector<int>::iterator it = a.begin(); it != a.end(); it++){
        cout << *(it) << " ";                                          // *output : 2, 3, 4, 5, 7
    }
 
    for( auto it = a.begin(); it != a.end(); it++){     // auto = vector<int>::iterator 
        cout << *(it)  << " ";                          // *output : 2, 3, 4, 5, 7
    }

    for(auto it : v ){          // integer data type
        cout << it << " ";      // 2, 3, 4, 5, 7
    }

    a.erase(a.begin()+1);    // *output : 2, 4, 5, 7
    a.erase(a.begin()+2,a.begin()+4);    // *output : 2, 3, 7   range: 4,5 , [start, end)

    //insert function

    vector<int>v(2,100);  // {100,100}
    v.insert(v.begin(), 200); // {200, 100, 100}
    v.insert(v.begin()+1,2,30); // {200, 30, 30, 100, 100}

    vector<int> copy(2, 50);
    v.insert(v.begin(),copy.begin(),copy.end());  // {50, 50, 200, 30, 30, 100, 100}

    // a = {2, 3, 4}  b = {6, 7, 8}
    cout << a.size();   // size : 3
    a.pop_back();       // ans : {2, 3}
    a.clear();          // clear all
    a.empty(); 
    a.swap(a);    // a = {6, 7, 8} b = {2, 3, 4}
}
    //list
    
    void explainlist(){
        list<int> ls;       // { }
        ls.push_back(2);     //{2}
        ls.emplace_back(4);  //{2,4}
        ls.push_front(5);    //{5, 2, 4}
        ls.emplace_front();  
        
        //rest of functions are simillar to vectors
    }
    // DQ

    void explaindeque(){
        deque<int> dq;   // {}
        dq.push_back(1); // {1}
        dq.emplace_back(4);//{1, 4}
        dq.push_front(2); //{2,1,4}
        dq.emplace_back(3); //{3, 2, 1, 4}

        dq.pop_back();   //{3, 2, 1}
        dq.pop_front();  //{4,1}

        dq.back();
        dq.front();

        //rest of functions are simillar to vectors

    }
   
    //stack
    
    void explainstack(){   // 0(1)
        stack<int> st;
        st.push(1);  // {1}
        st.push(2);  // {2, 1}
        st.push(3);  // {3, 2, 1}
        st.push(4);  // {4, 3, 2, 1}
        st.emplace(5);//{5, 4, 3, 2, 1}

        cout << st.top();  // prints 5  "st[2] is invalied"

        st.pop();  // {4, 3, 2, 1}
        cout << st.top(); // 4
        cout << st.size(); // 4
        cout << st.empty();  
        stack<int>st1,st2;
        st1.swap(st2);

    }

    //Queue

    void explainqueue(){
        queue<int> q;
        q.push(1);   // {1}
        q.push(2);   // {1,2}
        q.emplace(4); //{1,2,4}

        q.back() += 5;
        cout << q.back();  // prints 9
        cout << q.front(); // 1

        q.pop(); //{2,9}
        cout << q.front(); // 2

        // size swap empty are same as stack
    }
    
    //priority_queue
    
    void explainpq(){     // max element set at the top
        priority_queue<int>pq;

        pq.push(5);  //{5}                   // 0(logn)
        pq.push(2);  // {5, 2}
        pq.push(8);  // {8, 5, 2}
        pq.emplace(10); // (10, 8, 5, 2)
        cout << pq.top(); // prints 10        //0(1)

        pq.pop(); // {8, 5, 2}
        cout << pq.top(); // prints 8         //0(logn)

        // size swap empty are same as others

        //minimum heap

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(5);  //{5}
        pq.push(2);  // {2, 5}
        pq.push(8);  // {2, 5, 8}
        pq.emplace(10); // (2, 5, 8, 10)

        cout << pq.top(); // prints 2
    }
     
    // set
       
    void explainset(){                // 0(logn)     // sort, unique
        set<int>st;   
        st.insert(1);  // {1}
        st.emplace(2); //{1,2}
        st.insert(2);  // {1,2}
        st.insert(4);  //{1,2,4}
        st.insert(3);  //{1,2,3,4}
      
        // functionality of insert in vector 
        // can be used also, that only increases
        // efficiency

        // begin(),end(), rbegin(),rend(),size(),
        // empty(),swap() are same as those of above 

        auto it = st.find(3);

        auto it = st.find(6);   // st.end() 

        st.erase(4);  // {1,2,3} -> it takes logarthmic time to erase

        int cnt = st.count(1);   // if 1 exict = 1; or 0;

        auto it = st.find(3);
        st.erase(it);           // it take constant time 

        auto it1 = st.find(2);
        auto it2 = st.find(4);
        st.erase(it1,it2);      // {1,4}

        // lower_bound() and upper_bound() functions works in the same way
        // as in vector it does.

        auto it = st.lower_bound(2);  
        auto it = st.upper_bound(3);
     
    }

    // multiset

    void explainmultisets(){     // sort

        // everthing same as set
        // only stores duplicate elements also 

        multiset<int> ms;
        ms.insert(1);  // {1}
        ms.insert(1);  // {1,1}
        ms.insert(1);  //{1,1,1}

        ms.erase(1);  // all 1's erased

        int cnt = ms.count(1);

        // only a single one erased 
        ms.erase(ms.find(1));

        ms.erase(ms.find(1), ms.find(1)+2);   

        // rest all functions are same as set
            
    }

    void explainUset(){
        unordered set<int> st;

        // lower_bound and upper_bound function 
        // does not works, rest all function are same 
        // as above, it does not stores in any 
        // particular order it has a better complexity
        // than set in most cases, except some when collision happens

    }

    // maps

     viod explainmap(){
        map<int,int> mp;               // map<int(key),int(value)> mp
        map<int, pair<int, int> mp;
        map<pair<int,int> ,int> mp;

        mp[1] = 2;          // {1,2}
        mp.emplace({3,1});  // {3,1}
        mp.insert({2,4});   // {2,4}

        mpp[{2,3}] = 10;    //{{2,3},10}
        // {
        //     {1,2}
        //     {2,4}
        //     {3,1}
        // }

        for(auto it : mp){
            cout << it.first << " " << it.second << end;    //  1 2  \n  2 4 \n 3 1  // sorted order of key
        }

        cout << map[1];   // 2
        cout << map[5];   // 0

        auto it = mp.find(3);      //{3,1}
        cout << *(it).second;      // 1

        auto it = map.find(5);    // mp.end()

        // syntax
        auto it = mp.lower_bound(2);

        auto it = mp.upper_bound(3);

        //erase, swap, sixe, empty, are same as above 

     }

     // multimap  0(logn)
     
     void explainMultimap(){
        //everthing same as map, only it can store multiple keys
        // only mpp[key] cannot be used here
     }

     // unorderedmap  0(1)

     void explainunorderedmap(){
        //same as set and unordered_set difference
     }

    // algorithm

    bool comp(pair<int, int> p1, pair<int, int> p2){
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        if(p1.first > p2.first) return true;
        else return false ;
    }
    vector<int> v;
    int a1[3];
    int n = 0;
    void explainextra(){

        sort(a1, a1+n);

        sort(v.begin(),v.end());

        sort(a1+2,a1+4);

        sort(v.begin(), v.end(), greater<int>);     //desending order

        pair<int, int> a[] = {{1, 2}, {2,1}, {4,1}};
        //sort it according to second element 
        // it second element is same, then sort
        // it according to sirst element but in desecnding

        sort(a, a+n, comp) ;     // boolean function  // {{4, 1}, {2, 1}, {1, 2}}

        int num = 6;
        int cnt = __builtin_popcount();   // no of ones in binary format :2

        long long num = 1234567899;
        int cnt = __builtin_popcountll();   

        string s = "123";

        do {
            cout<< s << endl;
        }
        while(next_permutation(s.begin(),s.end()));     // prints all permutations
         
        int maxi = *max_element(v.begin(), v.end());      // max in an array

        int min = *min_element(a1, a1+n);       // min element
    
   


    }













