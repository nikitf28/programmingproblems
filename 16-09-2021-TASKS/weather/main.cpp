#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double mean(vector<double> &x){
    double sum = 0;
    for (int i = 0; i < x.size(); i++){
        sum += x[i];
    }
    return sum * 1.0 / x.size();
}

void multiply(vector<double> &x, vector<double> &y, vector<double> &result){
    for (int i = 0; i < x.size(); i++){
        result[i] = x[i] * y[i];
    }
}

void regretion(vector<double> &x, vector<double> &y, double &k, double &b){
    double mx = mean(x);
    double my = mean(y);
    vector<double> result1, result2;
    result1.resize(x.size());
    result2.resize(x.size());
    multiply(x, y, result1);
    multiply(x, x, result2);
    double mxy = mean(result1);
    double mxx = mean(result2);
    k = (mx * my - mxy) / (mx*mx - mxx);
    b = my - k * mx;
}

struct yearWeatherInfo {
    int tempSum = 0;
    int tempSumWinter = 0;
    int tempSumSummer = 0;
    int ammountOfDays = 0;
    int ammountOfSummerDays = 0;
    int ammountOfWinterDays = 0;
    double avg = 0;
    double avgSummer = 0;
    double avgWinter = 0;
    double reg;
    double regW;
    double regS;
};


bool isNumeric(string num){
    if (num.length() == 0){
        return false;
    }
    for (int i = 0; i < num.length(); i++){
        if (!(num[i] >= '0' && num[i] <= '9' || num[i] == '-')){
            return false;
        }
    }
    return true;
}

void splitter(string data, vector<int> &output){
    string newData = "";
    for (int i = 0; i < data.length(); i++){
        if (data[i] != ' '){
            newData += data[i];
        }
        else{
            //cout <<newData <<endl;
            if (isNumeric(newData)){
                output.push_back(stoi(newData));
            }
            newData = "";
        }
    }

    if (isNumeric(newData)){
        output.push_back(stoi(newData));
    }

}

int main(int argc, char* argv[]) {
    vector<yearWeatherInfo> tempSum;
    tempSum.resize(3000);
    ifstream fin;
    fin.open(argv[1]);
    int i = 0;
    while (!fin.eof()){
        i++;
        string inputData = "";
        getline(fin, inputData);
        if (inputData == "SUB"){
            break;
        }
        if (inputData.length() == 0){
            //cout <<"NO DATA " <<i <<endl;
            continue;
        }
        //cout <<"Line " <<i <<endl;

        vector<int> parsedData;
        splitter(inputData, parsedData);
        //cout <<inputData <<" " <<inputData.length()  <<"   BLAAAAAAAAAAAAAAAAAA " <<parsedData.size() <<endl;
        if (parsedData.size() < 7){
            continue;
        }
        int year = parsedData[1];
        int month = parsedData[2];
        int temperature = parsedData[7];
        if (temperature == 9999){
            continue;
        }
        if (year > 0 and year < 3000){
            tempSum[year].tempSum += temperature;
            tempSum[year].ammountOfDays += 1;
            if (month == 12 || month == 1 || month == 2){
                tempSum[year].tempSumWinter += temperature;
                tempSum[year].ammountOfWinterDays += 1;
            }
            if (month >= 6 && month <= 8){
                tempSum[year].tempSumSummer += temperature;
                tempSum[year].ammountOfSummerDays += 1;
            }
        }
    }
    fin.close();
    ofstream fout;
    fout.open(argv[2]);
    for (int i = 0; i < tempSum.size(); i++){
        if (tempSum[i].ammountOfDays > 330){
            tempSum[i].avg =  tempSum[i].tempSum * 1.0 / tempSum[i].ammountOfDays / 10;
            tempSum[i].avgWinter = tempSum[i].tempSumWinter * 1.0 / tempSum[i].ammountOfWinterDays / 10;
            tempSum[i].avgSummer = tempSum[i].tempSumSummer * 1.0 / tempSum[i].ammountOfSummerDays / 10;
            //cout <<i <<" " <<tempSum[i].avg <<endl;
            //fout <<i <<", " <<tempSum[i].avg <<", " <<tempSum[i].avgWinter <<", " <<tempSum[i].avgSummer <<"," <<endl;
        }
    }

    vector<double> years, general, summer, winter;
    for (int i = 0; i < tempSum.size(); i++){
        if (tempSum[i].ammountOfDays > 330){
            years.push_back(i);
            general.push_back(tempSum[i].avg);
            summer.push_back(tempSum[i].avgSummer);
            winter.push_back(tempSum[i].avgWinter);
        }
    }
    double kG, bG, kW, kS, bW, bS;
    regretion(years, general, kG, bG);
    regretion(years, summer, kS, bS);
    regretion(years, winter, kW, bW);
    //cout <<kG <<" " <<bG <<endl <<kS <<" " <<bS <<endl <<kW <<" " <<bW <<endl;

    for (int i = 0; i < tempSum.size(); i++){
        if (tempSum[i].ammountOfDays > 330){
            tempSum[i].reg = i * kG + bG;
            tempSum[i].regW = i * kW + bW;
            tempSum[i].regS = i * kS + bS;
            fout <<i <<", " <<tempSum[i].avg <<", " <<tempSum[i].reg <<", " <<tempSum[i].avgWinter <<", " <<tempSum[i].regW <<", " <<tempSum[i].avgSummer <<", " <<tempSum[i].regS <<"," <<endl;

        }
    }

    fout.close();
}
