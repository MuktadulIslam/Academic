// Using Naive Bayes Classification Algorithm


#include<bits/stdc++.h>
#define TOTAL_DATA 90
#define YES 1
#define NO 0
#define MALE 1
#define FEMALE 2

using namespace std;

int male_yes = 0, male_no = 0;
int female_yes = 0, female_no = 0;
float prob_male_no, prob_male_yes;
float prob_female_no, prob_female_yes;

int type1_yes = 0, type1_no = 0;
int type2_yes = 0, type2_no = 0;
int type3_yes = 0, type3_no = 0;
float prob_type1_no, prob_type1_yes;
float prob_type2_no, prob_type2_yes;
float prob_type3_no, prob_type3_yes;

float age_no[TOTAL_DATA] = {0}, age_yes[TOTAL_DATA] = {0};
int age_yes_index = 0, age_no_index = 0;
float prob_age_no, prob_age_yes;
float mean_age_no, mean_age_yes;
float SD_age_no, SD_age_yes;

float time_no[TOTAL_DATA] = {0}, time_yes[TOTAL_DATA] = {0};
int time_yes_index = 0, time_no_index = 0;
float prob_time_no, prob_time_yes;
float mean_time_no, mean_time_yes;
float SD_time_no, SD_time_yes;

float warts_no[TOTAL_DATA] = {0}, warts_yes[TOTAL_DATA] = {0};
int warts_yes_index = 0, warts_no_index = 0;
float prob_warts_no, prob_warts_yes;
float mean_warts_no, mean_warts_yes;
float SD_warts_no, SD_warts_yes;

float area_no[TOTAL_DATA] = {0}, area_yes[TOTAL_DATA] = {0};
int area_yes_index = 0, area_no_index = 0;
float prob_area_no, prob_area_yes;
float mean_area_no, mean_area_yes;
float SD_area_no, SD_area_yes;


float stringToNumber(string str) {
    str.replace(str.find('"'), 1, "");
    str.replace(str.find('"'), 1, "");
    return atof(str.c_str());
}

void get_data_from_row(string line) {
    string str;
    stringstream s(line);

    int sex, type, result;
    float time, age, warts,area;

    // Breaking lines
    getline(s, str, ',');
    sex = (int) stringToNumber(str);

    getline(s, str, ',');
    age = stringToNumber(str);

    getline(s, str, ',');
    time = stringToNumber(str);

    getline(s, str, ',');
    warts = stringToNumber(str);

    getline(s, str, ',');
    type = (int) stringToNumber(str);

    getline(s, str, ',');
    area = stringToNumber(str);

    getline(s, str, ',');
    result = (int) stringToNumber(str);

    //cout << "sex = " << sex << "   age= " << age << "   time= " << time << "   warts= " << warts;
    //cout << "   type= " << type << "   area" << area << "   result= " << result << endl;

    if(result == YES) {
        if(sex == MALE) male_yes++;
        else female_yes++;


        if(type == 1) type1_yes++;
        else if(type == 2) type2_yes++;
        else type3_yes++;

        age_yes[age_yes_index++] = age;
        time_yes[time_yes_index++] = time;
        warts_yes[warts_yes_index++] = warts;
        area_yes[area_yes_index++] = area;
    }
    else {
        if(sex == MALE) male_no++;
        else female_no++;


        if(type == 1) type1_no++;
        else if(type == 2) type2_no++;
        else type3_no++;

        age_no[age_no_index++] = age;
        time_no[time_no_index++] = time;
        warts_no[warts_no_index++] = warts;
        area_no[area_no_index++] = area;
    }

}

void read_from_CSVFile(string filename) {
    fstream fin;

    // Open an data set file
    fin.open(filename, ios::in);
    string line, word, temp;


    //int lineNumber = 0;
    getline(fin, line);     // Ignoring heading
    while (getline(fin, line)) {
        //cout << lineNumber << endl;
        get_data_from_row(line);
        //lineNumber++;
    }
}


float getMean(float arr[]) {
    double sum = 0.0;
    int i = 0;
    for(i=0 ; arr[i] != 0 ; i++) sum += arr[i];

    return sum/i;
}


void calculate_mean_and_SD() {
    mean_age_yes = getMean(age_yes);
    mean_age_no = getMean(age_no);

    mean_time_yes = getMean(time_yes);
    mean_time_no = getMean(time_no);

    mean_warts_yes = getMean(warts_yes);
    mean_warts_no = getMean(warts_no);

    mean_area_yes = getMean(area_yes);
    mean_area_no = getMean(area_no);

    /*cout << "mean_age_no= "<< mean_age_no << "    mean_age_yes= " << mean_age_yes << endl;
    cout << "mean_time_no= "<< mean_time_no << "    mean_time_yes= " << mean_time_yes << endl;
    cout << "mean_warts_no= "<< mean_warts_no << "    mean_warts_yes= " << mean_warts_yes << endl;
    cout << "mean_area_no= "<< mean_area_no << "    mean_area_yes= " << mean_area_yes << endl;*/
}




int main(void) {
    read_from_CSVFile("Cryotherapy.csv");
    calculate_mean_and_SD();



    // Output
    /*cout << "male_yes = " << male_yes << "    male_no= " <<male_no << endl;
    cout << "female_yes = " << female_yes << "    female_no= " <<female_no << endl;
    cout << "type1_yes= " << type1_yes << "    type2_yes= " << type2_yes << "    type3_yes= " << type3_yes << endl;
    cout << "type1_no= " << type1_no << "    type2_no= " << type2_no << "    type3_no= " << type3_no << endl;


    int i,j;
    cout << age_yes[0] << endl;
    for(i=0 ; age_yes[i] != 0 ; i++);
    for(j=0 ; age_no[j] != 0 ; j++);
    cout << "Age = " <<  i+j << endl;

    for(i=0 ; time_yes[i] != 0 ; i++);
    for(j=0 ; time_no[j] != 0 ; j++);
    cout << "Time = " <<  i+j << endl;

    for(i=0 ; warts_yes[i] != 0 ; i++);
    for(j=0 ; warts_no[j] != 0 ; j++);
    cout << "Warts = " <<  i+j << endl;

    for(i=0 ; area_yes[i] != 0 ; i++);
    for(j=0 ; area_no[j] != 0 ; j++);
    cout << "Area = " <<  i+j << endl;*/
}
