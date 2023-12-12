#include<iostream>
using namespace std;

template<typename T>
class deque{
    int sizee=0,capacity=0;
    T*array;
    public:

    deque(){
        this->sizee=0;
        this->capacity=0;
        array=new T[capacity];
    }

    deque(int n){
        this->sizee=n;
        if(capacity==0) capacity=1;
        while(capacity<sizee)capacity*=2;
        this->capacity=capacity;
        array=new T[capacity];
        for(int i=0;i<n;i++)array[i]=T();
    }

     deque(int n,const T&value){
        this->sizee=n;
        if(capacity==0) capacity=1;
        while(capacity<sizee)capacity*=2;
        this->capacity=capacity;
        array=new T[capacity];
        for(int i=0;i<n;i++)array[i]=value;
    }

    int size(){
        return sizee;


    }

    int capacity1(){
        return capacity;
    }
    bool empty(){
        return sizee==0;
    }

    const T front(){
        if(sizee==0) return T();
        return array[0];
    }
    const T back(){
        if(sizee==0) return T();
        return array[sizee-1];
    }

    bool push_back(const T&value){
        if(sizee<capacity){
            array[sizee]=value;
            sizee++;
            this->sizee=sizee;
            return true;
        }
       else if(sizee==capacity) 
       {
        if(capacity==0) capacity=1;
       capacity*=2;
        T*array1=new T[capacity];
        int i=0;
        for(i=0;i<sizee;i++){
            array1[i]=array[i];
        }
        array1[i]=value;
        array=array1;
        sizee++;
        this->sizee=sizee;
        this->capacity=capacity;
        //delete array1;
        return true;
       }
       return false;



    }
    bool push_front(const T&value){
        if(sizee<capacity){
            for(int i=sizee;i>=0;i--){
                array[i]=array[i-1];
            }
            sizee++;
            this->sizee=sizee;
            array[0]=value;
            return true;
        }else{
            if(capacity==0) capacity=1;
            else{
                capacity*=2;
            }
            T*array1=new T[capacity];
            sizee++;
            for(int i=sizee;i>=1;i--){
                array1[i]=array[i-1];
            }
            array1[0]=value;
            array=array1;
            this->sizee=sizee;
            this->capacity=capacity;
            return true;

        }
        return false;

    }
    bool pop_back(){
        if(sizee==0) return false;
        sizee--;
        this->sizee=sizee;
        return true;

    }
    bool pop_front(){
        if(sizee==0) return false;
        for(int i=0;i<sizee-1;i++){
            array[i]=array[i+1];
        }
        sizee--;
        this->sizee=sizee;
        return true;



    }

    void resize(int n){
        if(n==0) return;

        if(n<=sizee){
            T *array1=new T[n];
            for(int i=0;i<n;i++){
                array1[i]=array[i];
            }
            array=array1;
            capacity=1;
            while(capacity<n) capacity*=2;
            this->capacity=capacity;
            this->sizee=n;
        }else{
             T *array1=new T[n];
            for(int i=0;i<n;i++){
                array1[i]=array[i];
            }
            for(int i=sizee;i<n;i++){
                array1[i]=T();
            }
            array=array1;
            capacity=1;
            while(capacity<n) capacity*=2;
            this->capacity=capacity;
            this->sizee=n;

        }
        return ;



    }

    void resize(int n,const T&value){


        if(n==0) return;

        if(n<=sizee){
            T *array1=new T[n];
            for(int i=0;i<n;i++){
                array1[i]=array[i];
            }
            array=array1;
            capacity=1;
            while(capacity<n) capacity*=2;
            this->capacity=capacity;
            this->sizee=n;
        }else{
             T *array1=new T[n];
            for(int i=0;i<n;i++){
                array1[i]=array[i];
            }
            for(int i=sizee;i<n;i++){
                array1[i]=value;
            }
            array=array1;
            capacity=1;
            while(capacity<n) capacity*=2;
            this->capacity=capacity;
            this->sizee=n;

        }
        return ;

    }
    void reserve(int n){
        if(n<=capacity) return;
        this->capacity=n;
        T*array1=new T[capacity];
        for(int i=0;i<sizee;i++){
            array1[i]=array[i];
        }
        array=array1;
        return;
    }

    void shrink_to_fit(){
        if(capacity==sizee) return;
        this->capacity=sizee;
         
        T*array1=new T[capacity];
        for(int i=0;i<sizee;i++){
            array1[i]=array[i];
        }
        array=array1;
        return;

    }

    T operator[](int n)const{
        if(n<0||n>=sizee) return T();
        return array[n];
    }

     void display(){
        for(int i=0;i<sizee;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }




};

int main(){

    

    deque<int>d1;
    d1.display();

     cout<<d1.size()<<endl;
    cout<<d1.capacity1()<<endl;
    cout<<d1.empty()<<endl;

    d1.push_back(3);
    d1.push_back(7);
    d1.push_back(8);

    d1.push_back(9);

    d1.push_back(1);

  //  cout<<d1.size()<<endl;

    d1.push_front(23);
    d1.push_front(24);
    d1.push_back(999);
    d1.push_front(11);


   // cout<<d1.size()<<endl;


  //  d1.display();

   // d1.pop_back();
   // d1.pop_front();

    d1.display();

    cout<<d1.size()<<endl;
    cout<<d1.capacity1()<<endl;
    d1.resize(12,12);
    d1.display();
   // cout<<d1.size()<<endl;
   // cout<<d1.capacity1()<<endl;


  // d1.display();
  // cout<<d1[6]<<endl;

   cout<<d1.size()<<endl;
   cout<<d1.capacity1()<<endl;
   d1.reserve(18);
   cout<<d1.capacity1()<<endl;
   d1.shrink_to_fit();
   cout<<d1.capacity1()<<endl;

   d1.push_back(1000);
   d1.push_front(10001);
   d1.display();
   d1.reserve(15);
   d1.display();
   cout<<d1.capacity1()<<endl;




 
    
    
    
    /*
    
    deque<int>d2(5);
    d2.display();
    cout<<d2.size()<<endl;
    cout<<d2.capacity1()<<endl;
    cout<<d2.empty()<<endl;

    cout<<d2.front()<<endl;
    
    cout<<d2.back()<<endl;
   

  


    
    

    deque<int>d3(7,8);
    d3.display();

     cout<<d3.size()<<endl;
    cout<<d3.capacity1()<<endl;
    cout<<d3.empty()<<endl;

     cout<<d3.front()<<endl;
    
    cout<<d3.back()<<endl;

    d3.push_back(89);
    d3.display();
    d3.push_back(90);
    d3.push_back(100);
    d3.display();

   */


   




}