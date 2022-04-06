#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#define TEST_CASE DOCTEST_TEST_CASE

#include "Matrix.hpp"
using namespace std;
using namespace zich;

static stringstream result;
static stringstream input ;
static vector<double> arr2 = {1,2,3,4,5,6,7,8,9,10,11,12};
static vector<double> arr = {1,2,3,4,5,6};



void create_correct_ans(vector<double> arr,int flag){
    if (flag == 2){
        result << "[" << arr[0] <<","<< arr[1]<< ","<< arr[2]<<","<< arr[3]<<","<< arr[4]<<","<< arr[5]<<"]\n";
        result << "[" << arr[6] <<","<< arr[7]<< ","<< arr[8]<<","<< arr[9]<<","<< arr[10]<<","<< arr[11]<<"]";
    }
     if (flag == 1){
        result << "[" << arr[0] <<","<< arr[1]<< ","<< arr[2]<<"]";      
    }
   } 
void make_input(vector<double> arr,int flag)
{
    switch (flag)
    {
        case 2:  
           input << "["<<arr[0]<<","<<arr[1]<<","<<arr[2]<<","<<arr[3]<<","<<arr[4]<<","<<arr[5]<<"]";
            break;

        case 1:  
              input <<"["<<arr[0]<<","<<arr[1]<<","<<arr[2]<<"]";
    
    }
}


TEST_CASE(" operator<<") {

    for (size_t i = 1; i <3 ; ++i)
    {
        stringstream out;
        int row = i ;
        int col = i*3 ;
        if(i == 2 ){
            Matrix mat{ arr2, row, col };
            out << mat;  
            create_correct_ans(arr2,i) ;
        }
        else {
             Matrix mat{ arr, row, col }; 
             out << mat;  
            create_correct_ans(arr,i) ;
        }
        CHECK(out.str() == result.str());
      
        }
    }

    TEST_CASE(" operator>>") {
    for (size_t i = 1; i < 3; ++i)
    {
        stringstream out;
        Matrix mat;
        if(i == 2 ){
           make_input(arr2,2);
            input >> mat;
            out << mat;  
             create_correct_ans(arr2, i);
        }
        if(i == 1 ){
           make_input(arr,1);
            input >> mat;
            out << mat;  
            create_correct_ans(arr2, i);
        }  
        
            CHECK(out.str() == result.str());
        }
    }
    
TEST_CASE(" operator* "){
        vector<double> arr_1 = { 1, 2, 3 , 4,5,6};
        vector<double> arr_2 = { 1,2,3,4 };
        vector<double> ans;
        int row1 = 2; int col1 = 3 ;
         int row2 = 2; int col2 = 2 ;  
        stringstream out;
            Matrix mat1{ arr_1, row1, col1 };
            Matrix mat2{ arr_2, row2, col2 };

            ans = { 19,12,15,19,26,33};
   
            Matrix mat_ans = mat1 * mat2;
            out << mat_ans;  

               
               
            create_correct_ans(ans,2);  //

    
            CHECK(out.str() == result.str());
        }
              

   
TEST_CASE("operator>"){
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool flag;
        vector<double> arr_1 = { 1, 2, 99};
        vector<double> arr_2 = { 1,2,2000 };
        double sum1 = 0;
        for (size_t i = 0; i <5; i++)
        {
            sum1 += arr_1[i];  
            sum1 += arr_2[i];  
        }
            Matrix mat1{ arr_1, 2, 3 };
            Matrix mat2{ arr_2, 2, 3 };
            flag = mat2 > mat1;  
            CHECK(flag==true);
        }
    }
       
TEST_CASE(" operator<=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool flag;
        vector<double> arr_1 = { 1, 2, 99};
        vector<double> arr_2 = { 1,2,99 };
        double sum1 = 0;
        for (size_t i = 0; i <5; i++)
        {
            sum1 += arr_1[i];  
            sum1 += arr_2[i]; 
        }
            Matrix mat1{ arr_1, 2, 3 };
            Matrix mat2{ arr_2, 2, 3 };
            flag = mat1 >= mat2;  
            CHECK(flag==true);
        }
    }
TEST_CASE("operator unari-")
{
       vector<double> arr_1 = { 1, 2, 99};
        vector<double> arr_negative = { -1, -2, -99};  
    stringstream out;
    {
        int row = 1;
        int col = 3;
        Matrix mat{ arr_1, row, col };
        out << -mat;  
        create_correct_ans(arr_negative, 1 ); /// updating reasult
        CHECK(out.str() == result.str());
    }
}


TEST_CASE("operator-")
{
    for (size_t i = 0; i < 7; ++i)
    {
        double seventy = 70 -i*10;
        double eighty= 80 -i*10;
          double ninty = 90 -i*10;
        vector<double> arr_1 = { seventy, eighty, ninty};
        vector<double> arr_2 = { 10,10,10 };
        vector<double> sum;
        for (size_t k = 0; k < 3; k++)
        {
            sum.push_back(arr_1[i] -arr2[i]);
        }
        stringstream out;
            Matrix mat1{ arr_1, 1, 3 };
            Matrix mat2{ arr_2, 1,3 };
            Matrix mat3 = mat1 - mat2;
            out << mat3; 
            create_correct_ans(sum,1);  
            CHECK(out.str() == result.str());
        }
    }


TEST_CASE("Bad input")
{
    vector<double> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    for (size_t j = 0; j < 10; ++j)  // check for all the 6 format
    {
        Matrix mat1{ arr, 12,1 };
        Matrix mat2{ arr, 1,12};
        Matrix mat3{ arr, 4,3 };
        Matrix mat4{ arr, 2,6};
        Matrix mat5{ arr, 6,2};
        Matrix mat_senior{ arr, 1, 3 };
        CHECK_THROWS(mat_senior * mat2);
        CHECK_THROWS(mat_senior * mat3);
        CHECK_THROWS(mat_senior * mat4);
        CHECK_THROWS(mat_senior * mat5);
        CHECK_THROWS(mat_senior * mat1);
    }
}

