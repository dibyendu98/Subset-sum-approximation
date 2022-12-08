#include <iostream>
#include<algorithm>
#include<vector>
#include <chrono>
#include<stdlib.h>

using namespace std::chrono;
using namespace std;

void display(vector<int> a)
{
   for (int i : a)cout << i << " ";

   cout << endl;
}


vector<int> Trim(vector<int>L,float d)
{
    int m = L.size();
    vector<int> newL;
    newL.push_back(L[0]);
    int last = newL[0];

    for(int i=1;i<m;i++)
    {
        if(L[i]>last*(1+d))
        {
            newL.push_back(L[i]);
            last = L[i];
        }
          

        
    }

    return newL;
}


int main() {

   // input
   srand((unsigned) time(0));
   int iteration = 10;

   int test = 1;
   while (iteration--)
   {

      cout << "Iteration : " << test << endl;

      vector<int> arr;

      int size, target;

      size = 10 * test;  // << ! GENERATING RANDOM SIZE >>  ####

      // cin>>size;

      target = rand() % 1000; // << GENERATING RANDOM TARGET SUM >> ###

      // cin>>target;

      for (int i = 0; i < size; i++)
      {
         int input = rand() % 1000;  // << GENERATING RANDOM NUMBERS >>  ###
         // int input;
         // cin>>input;

         arr.push_back(input);
      }



      sort(arr.begin(), arr.end());  // << SORTING THE LIST IN ASCENDING ORDER >>

      cout << "size :=> " << size << endl;
      cout << "Input Array :=>";
      // display(arr);
      cout << "Target Sum :=> " << target << endl;

      // << ALGORITHM LOGIC>>

      auto start = high_resolution_clock::now();

      vector<int>pre_list;
      vector<int>curr_list;

      pre_list.push_back(0);

     float e = 0.40;
     float approxans = e*target;

      for (int i = 0; i < size; i++)
      {
         

         curr_list = pre_list;
         int s = curr_list.size();
         
         // cout<<"Before trim "<<endl;

         // display(curr_list);
         for (int j = 0; j < s; j++)
         {
            curr_list.push_back(curr_list[j] + arr[i]);
         }


         curr_list = Trim(curr_list,(e/2*size*1.0));

         // cout<<"After Trim"<<endl;
         // display(curr_list);

         // << REMOVING ELEMENTS FROM THE LIST WHICH ARE GREATER THAN THE TARGET SUM >>



         pre_list.clear();
         for (int j = 0; j < curr_list.size(); j++)
         {
            if (curr_list[j] <= target)
               pre_list.push_back(curr_list[j]);
         }

         curr_list.clear();


      }
      auto stop = high_resolution_clock::now();
      int out = *max_element(pre_list.begin(), pre_list.end()); //  << RETURING THR LARGET ELEMENT IN THE LIST  >>
   
      if (out == approxans)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;

      cout << "Output:" << out << endl;
      

      auto duration = duration_cast<microseconds>(stop - start);

      cout << "Time taken by function: "
           << (duration.count() / 1000000.0) << " seconds" << endl;

    test++;


   }

   return 0;
}