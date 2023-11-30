#include <vector>
#include <cstdlib>
#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;

class qqueue {
public:
	qqueue(int NI, int NO, int capacity):NI(NI),NO(NO),capacity(capacity){}

    void aa(int it) {
        for (int itime = 0; itime < it; itime++) {
            Sleep(1000);

            ni = rand() % NI;
            insertPackets(ni, lost);
            
            no = rand() % NO;
            removePackets(no);

            NofPackets[itime] = queue.size();
        }
    }

    double avg() {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += NofPackets[i];
        }
        double avg = sum / 10;
        return avg;
    }
    
    int mmax() {
        int max = 0;
        for (int i = 0; i < 10; i++) {
            if (max < NofPackets[i]) max = NofPackets[i];
        }
        return max;
    }
    
    double fullness() {
        double sum = 0, fullness = 0;
        for (int i = 0; i < 10; i++) {
            sum += NofPackets[i];
        }
        fullness = sum / capacity * 100;
        return fullness;
    }
  
    double loss_rate() {
        return lost;
    }

    vector<int> insertPackets(int k, int& lost) {
        if (capacity < queue.size() + k) {
            lost += queue.size() + k - capacity;
            k = capacity - queue.size();
        }
        for (int i = 0; i < k; i++) {
            queue.push_back(rand() % 20);
        }
        return queue;
    }

    vector<int> removePackets(int n) {
        for (int i = 0; i < n; i++) {
            if (queue.size() != 0) {
                queue.erase(queue.begin());
            }
        }
        return queue;
    }

private:
	vector <int> queue;
	int NofPackets[10];
    int NI, NO, capacity, ni, no, lost = 0;	
};


int main() {
    int NI = 30, capacity = 100;
    int NO = 5, NO1 = 10, NO2 = 30, NO3 = 50, NO4 = 80;
    qqueue Q(NI, NO, capacity);
    qqueue Q1(NI, NO1, capacity);    
    qqueue Q2(NI, NO2, capacity);    
    qqueue Q3(NI, NO3, capacity);    
    qqueue Q4(NI, NO4, capacity);    

    Q.aa(10);
    int max = Q.mmax();
    double avg = Q.avg();
    double fullness = Q.fullness();
    double loss_rate = Q.loss_rate();
    cout << "max = " << max << " avg = " << avg << endl;
    cout << "fullness = " << fullness << " loss_rate = " << loss_rate << endl;

    Q1.aa(10);
    int max1 = Q1.mmax();
    double avg1 = Q1.avg();
    double fullness1 = Q1.fullness();
    double loss_rate1 = Q1.loss_rate();
    cout << "max1 = " << max1 << " avg1 = " << avg1 << endl;
    cout << "fullness1 = " << fullness1 << " loss_rate1 = " << loss_rate1 << endl;

    Q2.aa(10);
    int max2 = Q2.mmax();
    double avg2 = Q2.avg();
    double fullness2 = Q2.fullness();
    double loss_rate2 = Q2.loss_rate();
    cout << "max2 = " << max2 << " avg2 = " << avg2 << endl;
    cout << "fullness2 = " << fullness2 << " loss_rate2 = " << loss_rate2 << endl;

    Q3.aa(10);
    int max3 = Q3.mmax();
    double avg3 = Q3.avg();
    double fullness3 = Q3.fullness();
    double loss_rate3 = Q3.loss_rate();
    cout << "max3 = " << max3 << " avg3 = " << avg3 << endl;
    cout << "fullness3 = " << fullness3 << " loss_rate3 = " << loss_rate3 << endl;

    Q4.aa(10);
    int max4 = Q4.mmax();
    double avg4 = Q4.avg();
    double fullness4 = Q4.fullness();
    double loss_rate4 = Q4.loss_rate();
    cout << "max4 = " << max4 << " avg4 = " << avg4 << endl;
    cout << "fullness4 = " << fullness4 << " loss_rate4 = " << loss_rate4 << endl;

    ofstream outputFile("analysis.txt");
    if (outputFile.is_open()) {
        outputFile << NO / NI << " " << fullness << " " << NO1 / NI << " " << fullness1 << " " << NO2 / NI << " " << fullness2 << " " << NO3 / NI << " " << fullness3 << " " << NO4 / NI << " " << fullness4 << endl;
        outputFile.close();
    }
    else {
        cout << "file open error";
    }
    return 33;
}