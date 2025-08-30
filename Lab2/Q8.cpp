#include <iostream>

using namespace std;

int main(){
    int days, times;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "Enter number of readings per day: ";
    cin >> times;

    float** temps = new float*[days];
    for (int d = 0; d < days; d++){
        temps[d] = new float[times];
        cout << "Enter " << times << " readings for day " << d+1 << ": ";
        for(int t = 0; t < times; t++){
            cin >> temps[d][t];
        }
    }

    float* avgDay = new float[days];
    for (int d = 0; d < days; d++){
        float sum = 0;
        for (int t = 0; t < times; t++){
            sum += temps[d][t];
        }
        
        avgDay[d] = sum / times;
        cout << "Average for day " << d+1 << ": " << avgDay[d] << endl;
    }

    int hottest = 0, coldest = 0;
    for (int d = 1; d < days; d++){
        if(avgDay[d] > avgDay[hottest]) hottest = d;
        if(avgDay[d] < avgDay[coldest]) coldest = d;
    }

    cout << "Hottest day: Day " << hottest + 1 << " with avg " << avgDay[hottest] << endl;
    cout << "Coldest day: Day " << coldest + 1 << " with avg " << avgDay[coldest] << endl;

    for (int d = 0; d < days; d++){
        delete[] temps[d];
    }
    
    delete[] temps;
    delete[] avgDay;
}
