// CS-132 HW 13-7 TestScores Class
// KIT WONG
// 4-18-2015
// used 20 min

#include<iostream>
using namespace std;

class TestScores{
    double score1;
    double score2;
    double score3;
    public:
    TestScores(double s1 = 0.0, double s2 = 0.0, double s3 = 0.0){
        score1 = s1;
        score2 = s2;
        score3 = s3;
    }
    double getScore1(){
        return score1;
    }
    double getScore2(){
        return score2;
    }
    double getScore3(){
        return score3;
    }
    void setScore1(double s1){
        score1 = s1;
    }
    void setScore2(double s2){
        score2 = s2;
    }
    void setScore3(double s3){
        score3 = s3;
    }
    double averageScore(){
        return (score1+score2+score3)/3;
    }
};

int main(){
    TestScores x(9.0,7.0,8.0);
    cout << "Average score: " << x.averageScore() << endl;
    return 0;
}
