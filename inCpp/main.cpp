#include <iostream>

using namespace std;
bool running = true;
class Calendar{
    private:
        int resultDay;
        int readYear;
        int readDay;
        int resultYear;
        string readMonth;
        string resultMonth;
        int brainRead;
        int brainResult;
    public:
        void setReadDay(int readDayC){
            readDay = readDayC;
        }
        void setResultDay(int resultDayC){
            resultDay = resultDayC;
        }
        int getReadDay(){
            return readDay;
        }
        int getResultDay(){
            return resultDay;
        }
        void setReadMonth(string readMonthC){
            readMonth = readMonthC;
        }
        void setResultMonth(string resultMonthC){
            resultMonth = resultMonthC;
        }
        string getReadMonth(){
            return readMonth;
        }
        string getResulMonth(){
            return resultMonth;
        }
        void setReadYear(int readYearC){
            readYear = readYearC;
        }
        void setResultYear(int resultYearC){
            resultYear = resultYearC;
        }
        int getResulYear(){
            return resultYear;
        }
        int getReadYear(){
            return readYear;
        }
        int getBrainRead(){
            return brainRead;
        }
        void setBrainRead(int brainReadC){
            brainRead = brainReadC;
        }
        int getBrainResult(){
            return brainResult;
        }
        void setBrainResult(int brainResultC){
            brainResult = brainResultC;
        }
};
Calendar calendar = Calendar();
int readDayC,readYearC,resultDayC,resultYearC;
string readMonthC,resultMonthC;
void Qustion1(){
    cout<<"From what year do you want to start de calculation\n";
    cout<<"Write year: ";
    cin>>readYearC;
    calendar.setReadYear(readYearC);
}
void Qustion2(){
    cout<<"From what month of the year do you want to start de calculation\n";
    cout<<"Write month: ";
    cin>>readMonthC;
    calendar.setReadMonth(readMonthC);
}
void Qustion3(){
    cout<<"From what day of the month do you want to start de calculation\n";
    cout<<"Write day: ";
    cin>>readDayC;
    calendar.setReadDay(readDayC);    
}
void validation1(){
    cout<<"The year you chose to start the calculatin is :"<<calendar.getReadYear()<<endl;
    bool goodanswer = true;
    while(goodanswer){
        cout <<" Do you like to continue or set another year? (y/n)\n";
        char answer;
        cin>>answer;
        if(answer == 'n'){
            goodanswer = false;
        }
        else{
            Qustion1();
        }
    }
    
}
void validation2(){
    cout<<"The month you chose to start the calculatin is :"<<calendar.getReadMonth()<<endl;
    bool goodanswer = true;
    while(goodanswer){
        cout <<" Do you like to continue or set another month? (y/n)\n";
        char answer;
        cin>>answer;
        if(answer == 'n'){
            goodanswer = false;
        }
        else{
            Qustion2();     
        }
    }
    
}
void validation3(){
    cout<<"The day you chose to start the calculatin is :"<<calendar.getReadDay()<<endl;
    bool goodanswer = true;
    while(goodanswer){
        cout <<" Do you like to continue or set another day? (y/n)\n";
        char answer;
        cin>>answer;
        if(answer == 'n'){
            goodanswer = false;
        }
        else{
            Qustion3();
        }
    }
    
}
int totalDays;
int plusDAYS;
void PlusHowMuchW(){
    cout<<"How many weeks?\n";
    cin>>plusDAYS;
    plusDAYS = plusDAYS * 7;
    calendar.setBrainRead(plusDAYS + calendar.getReadDay());
}
void PlusHowMuchD(){
    cout<<"How many days?\n";
    cin>>plusDAYS;
    calendar.setBrainRead(plusDAYS + calendar.getReadDay());
}
void option1(){
    bool loop = true;
    while (loop)
    {
        cout<<"Do you want to calculate in days or weeks(d/w)?\n";
        char answer;
        cin>>answer;
        if(answer == 'd'){
            PlusHowMuchD();
            loop = false;
        }
        else if(answer == 'w'){
            PlusHowMuchW();
            loop = false;
        }
        else {
            cout<<"Wrong input!\n";
            continue;
        }
    }

}
bool isLeapYear(){
    if(calendar.getReadYear()%4 == 0){
        if(calendar.getReadYear()%100==0){
            if(calendar.getReadYear()%400 == 0){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}
void calculate(){
    if(isLeapYear()){
        calendar.setResultYear(calendar.getBrainRead()/366);
        calendar.setResultDay(calendar.getBrainRead()%366);
    }
    else{
        calendar.setResultDay(calendar.getBrainRead()%365);
        calendar.setResultDay(calendar.getBrainRead()%365);
    }
    

}
int main(){
    
    while (running)
    {
        Qustion1();
        validation1();
        Qustion2();
        validation2();
        Qustion3();
        validation3();
        option1();
        running = false;
    }
    
    
}