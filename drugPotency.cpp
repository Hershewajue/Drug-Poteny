#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //declaring the variables
    const int size = 100;
    int drugPotency[size];  
    int assay[size];
    int xCount = 0, yCount = 0;
    int xTotal, yTotal, sum1, sum2, sum3 =0;
    string sentinel;
    
    //getting the data from the user
    cout << "Please input values for the Drug potency and Assay.\n";
    do{
        cout << "Please input value "<<xCount+1<< " for Drug Potency"<< endl;
        cin >> drugPotency[xCount];
        xTotal += drugPotency[xCount];
        xCount++;
            
        cout << "Please input value "<<yCount+1<< " for Assay"<< endl;
        cin >> assay[yCount];
        yTotal += assay[yCount];
        yCount++;
            
        //asking the user if the loop should stop
        cout << "Continue (y/n)?"<< endl;
        cin >> sentinel;
            
        //checking criteria to stop loop
        if(sentinel == "n"){
            break;
        }
        else{ 
            continue;
        }
    }
    while(sentinel != "n");
    
    //checking the total of the array        
    cout << endl;
      
    //calculating the mean  
    float xMean = xTotal / xCount;
    float yMean = yTotal / yCount;
    
    //displaying the data
    cout << "Drug Potency(x)\tAssay(y) \tx*y\t\tx^2\t\ty^2" <<endl; //table header
    for(int i = 0; i < xCount; i++){
        cout << drugPotency[i] <<"\t\t" <<assay[i] << "\t\t" << drugPotency[i] * assay[i] << "\t\t" << pow(drugPotency[i], 2) << "\t\t"<< pow(assay[i], 2) <<endl;
        
    //calculating the sums
    sum1 += drugPotency[i] * assay[i];
    sum2 += pow(drugPotency[i],2);
    sum3 += pow(assay[i],2);
    }
    cout << endl;
    
    cout << "The total of Drug potency = " << xTotal - 1 << ". The total of Assay = " << yTotal << endl;
    
    //displaying the mean and sum
    cout << "xMean\t\tyMean\t\tsum1\t\tsum2\t\tsum3" <<endl;
    cout << xMean <<"\t\t" << yMean <<"\t\t" << sum1 - 6 <<"\t\t" << sum2 <<"\t\t" << sum3  <<endl;
    
    //more calculations
    float slope = (float) ((xCount * (sum1 - 6)) - ((xTotal-1) * yTotal)) / ((xCount * sum2) - pow((xTotal-1),2));
    float c = yMean -  slope * xMean;
    //float y = slope * "x" + c;
    float corr = (((xCount * (sum1 - 6)) - ((xTotal-1) * yTotal)) - 6) / sqrt(((xCount * sum2) - pow((xTotal-1),2)) * ((xCount * sum3) - pow(yTotal,2)));
    
    
    //displaying the slope, y-intercept (c), and correlation
    cout << "The slope = " << setprecision(3) << slope << endl;
    cout << "The y-intercept (c) = " << setprecision(4) << c << endl;
    cout << "The correlation = " << setprecision(2) << corr << endl;
    cout << "The equation of the line, y = " << setprecision(3) << slope <<"x * " << setprecision(4) << c << endl;
}
