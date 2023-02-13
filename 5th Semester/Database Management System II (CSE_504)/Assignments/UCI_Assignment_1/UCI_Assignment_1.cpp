// Here I predict a person need Cryosurgery Treatment or not
// Using Naive Bayes Classification Algorithm
// Attributes are used in this prediction "sex","age","Time","Number_of_Warts","Type","Area","Result_of_Treatment"


#include<bits/stdc++.h>
#define E 2.718281
#define PI 3.1416
#define TOTAL_DATA 90
#define YES 1
#define NO 0
#define MALE 1
#define FEMALE 2

using namespace std;

int num_yes = 0, num_no = 0;
float prob_yes, prob_no;

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


void clearArray(){
    age_yes_index = 0;
    age_no_index = 0;
    time_yes_index = 0;
    time_no_index = 0;
    warts_yes_index = 0;
    warts_no_index = 0;
    area_yes_index = 0;
    area_no_index = 0;
}


float stringToNumber(string str) {
    str.replace(str.find('"'), 1, "");
    str.replace(str.find('"'), 1, "");
    return atof(str.c_str());
}


void get_data_from_row(string line) {
    string str;
    stringstream s(line);

    int gender, type, result;
    float time, age, warts,area;

    // Breaking lines
    getline(s, str, ','); gender = (int) stringToNumber(str);
    getline(s, str, ','); age = stringToNumber(str);
    getline(s, str, ','); time = stringToNumber(str);
    getline(s, str, ','); warts = stringToNumber(str);
    getline(s, str, ','); type = (int) stringToNumber(str);
    getline(s, str, ','); area = stringToNumber(str);
    getline(s, str, ','); result = (int) stringToNumber(str);


    if(result == YES) {
        if(gender == MALE) male_yes++;
        else female_yes++;


        if(type == 1) type1_yes++;
        else if(type == 2) type2_yes++;
        else type3_yes++;

        age_yes[age_yes_index++] = age;
        time_yes[time_yes_index++] = time;
        warts_yes[warts_yes_index++] = warts;
        area_yes[area_yes_index++] = area;
        num_yes++;
    }
    else {
        if(gender == MALE) male_no++;
        else female_no++;


        if(type == 1) type1_no++;
        else if(type == 2) type2_no++;
        else type3_no++;

        age_no[age_no_index++] = age;
        time_no[time_no_index++] = time;
        warts_no[warts_no_index++] = warts;
        area_no[area_no_index++] = area;
        num_no++;
    }

}


void read_from_CSVFile(string filename, int roundNo) {
    // Open an data set file
    fstream fin;
    fin.open(filename, ios::in);
    string line;

    getline(fin, line);     // Ignoring heading
    int start = (roundNo-1)*9;
    for(int i=0 ; i<TOTAL_DATA ; i++) {
        if(i == start) {
            for(int j=0 ; j<9 ; j++) getline(fin, line);
            i = i+9;
            if(i >= TOTAL_DATA) break;
        }

        getline(fin, line);
        get_data_from_row(line);
    }
    fin.close();
}


float getMean(float arr[], int total_dataItem) {
    double sum = 0.0;
    for(int i=0 ; i<total_dataItem ; i++) sum += arr[i];

    return sum/total_dataItem;
}


float getSD(float arr[], float mean, int total_dataItem) {
    double sum = 0.0;

    for(int i=0 ; i<total_dataItem ; i++) sum += pow((arr[i]-mean), 2);

    return sqrt(sum/(total_dataItem-1));
}


void calculate_mean_and_SD() {
    mean_age_yes = getMean(age_yes, age_yes_index);
    mean_age_no = getMean(age_no, age_no_index);

    mean_time_yes = getMean(time_yes, time_yes_index);
    mean_time_no = getMean(time_no, time_no_index);

    mean_warts_yes = getMean(warts_yes, warts_yes_index);
    mean_warts_no = getMean(warts_no, warts_no_index);

    mean_area_yes = getMean(area_yes, area_yes_index);
    mean_area_no = getMean(area_no, area_no_index);


    SD_age_yes= getSD(age_yes, mean_age_yes, age_yes_index);
    SD_age_no = getSD(age_no, mean_age_no, age_no_index);

    SD_time_yes = getSD(time_yes, mean_time_yes, time_yes_index);
    SD_time_no = getSD(time_no, mean_time_no, time_no_index);

    SD_warts_yes = getSD(warts_yes, mean_warts_yes, warts_yes_index);
    SD_warts_no = getSD(warts_no, mean_warts_no, warts_no_index);

    SD_area_yes = getSD(area_yes, mean_area_yes, area_yes_index);
    SD_area_no = getSD(area_no, mean_area_no, area_no_index);
}


float getProb_for_numerical_data(float dataValue, float mean, float sd) {
    float power = - pow((dataValue-mean)/sd, 2) / 2;
    return pow(E, power) / (sd*sqrt(2*PI));
}


float get_prob(int total_mORf, int total_mANDf, int total_in_type, int total_all_type) {
    return ((float) total_mORf/total_mANDf) * ((float)total_in_type/total_all_type);
}


float get_provability(int gender, int type, int result, float time, float age, float warts, float area) {
    float provability, prob_age, prob_time, prob_warts, prob_area;

    if(result == YES) {
        int gender_yes = male_yes+female_yes;
        int type_yes = type1_yes+type2_yes+type3_yes;

        // Getting Provability for numberical value
        prob_age = getProb_for_numerical_data(age, mean_age_yes, SD_age_yes);
        prob_time = getProb_for_numerical_data(time, mean_time_yes, SD_time_yes);
        prob_warts = getProb_for_numerical_data(warts, mean_warts_yes, SD_area_yes);
        prob_area = getProb_for_numerical_data(area, mean_area_yes, SD_area_yes);


        // Getting Provability for categorical value
        if(gender == MALE) {
            if(type == 1) provability = get_prob(male_yes, gender_yes, type1_yes, type_yes);
            else if(type == 2) provability = get_prob(male_yes, gender_yes, type2_yes, type_yes);
            else provability = get_prob(male_yes, gender_yes, type3_yes, type_yes);
        }

        else {
            if(type == 1) provability = get_prob(female_yes, gender_yes, type1_yes, type_yes);
            else if(type == 2) provability = get_prob(female_yes, gender_yes, type2_yes, type_yes);
            else provability = get_prob(female_yes, gender_yes, type3_yes, type_yes);
        }

        return provability*prob_age*prob_area*prob_time*prob_warts;
    }

    else {
        int gender_no = male_no+female_no;
        int type_no = type1_no+type2_no+type3_no;

        // Getting Provability for numberical value
        prob_age = getProb_for_numerical_data(age, mean_age_no, SD_age_no);
        prob_time = getProb_for_numerical_data(time, mean_time_no, SD_time_no);
        prob_warts = getProb_for_numerical_data(warts, mean_warts_no, SD_area_no);
        prob_area = getProb_for_numerical_data(area, mean_area_no, SD_area_no);

        // Getting Provability for categorical value
        if(gender == MALE) {
            if(type == 1) provability = get_prob(male_no, gender_no, type1_no, type_no);
            else if(type == 2) provability = get_prob(male_no, gender_no, type2_no, type_no);
            else provability = get_prob(male_no, gender_no, type3_no, type_no);
        }

        else {
            if(type == 1) provability = get_prob(female_no, gender_no, type1_no, type_no);
            else if(type == 2) provability = get_prob(female_no, gender_no, type2_no, type_no);
            else provability = get_prob(female_no, gender_no, type3_no, type_no);
        }

        return provability*prob_age*prob_area*prob_time*prob_warts;
    }

}


float getAccuracy(int roundNo, string filename) {
    // For Training
    read_from_CSVFile(filename, roundNo);
    calculate_mean_and_SD();

    // For Testing
    int true_positive = 0, false_positive = 0;
    int true_negative = 0, false_negative = 0;

    int gender, type, result;
    float time, age, warts,area;
    int start = (roundNo-1)*9;
    string line;

    // Open an data set file
    fstream fin;
    fin.open(filename, ios::in);

    getline(fin, line);     // Ignoring heading
    for(int i=0 ; i<TOTAL_DATA ; i++) {
        if(i == start) {
            for(int j=0 ; j<9 ; j++) {

                getline(fin, line);
                string str;
                stringstream s(line);

                // Breaking lines
                getline(s, str, ','); gender = (int) stringToNumber(str);
                getline(s, str, ','); age = stringToNumber(str);
                getline(s, str, ','); time = stringToNumber(str);
                getline(s, str, ','); warts = stringToNumber(str);
                getline(s, str, ','); type = (int) stringToNumber(str);
                getline(s, str, ','); area = stringToNumber(str);
                getline(s, str, ','); result = (int) stringToNumber(str);


                float prob_yes = get_provability(gender, type, YES, time, age, warts, area);
                float prob_no = get_provability(gender, type, NO, time, age, warts, area);

                if(prob_yes > prob_no) {
                    if(result == YES) true_positive++;
                    else false_positive++;
                }
                else {
                    if(result == NO) true_negative++;
                    else false_negative++;
                }
            }
            break;
        }
        getline(fin, line);
    }
    fin.close();

    //cout << "true_positive= " << true_positive << "  true_negative= " << true_negative << endl;
    //cout << "false_positive= " << false_positive << "  false_negative= " << false_negative << endl;

    return (float) (true_positive+true_negative) / (true_negative+true_positive+false_negative+false_positive);
}



int main(void) {

    float total_accuracy, sumOF_accuracy = 0.0, accuracy;

    for(int i=0 ; i<10 ; i++) {

        accuracy = getAccuracy(i+1, "Cryotherapy.csv") * 100;
        cout << "Accuracy for round-" << i+1 << "=  " << accuracy << endl;
        sumOF_accuracy += accuracy;
        clearArray();
    }

    total_accuracy = (float)sumOF_accuracy/10 ;
    cout << endl << endl<< "Total accuracy = " << total_accuracy;
}

