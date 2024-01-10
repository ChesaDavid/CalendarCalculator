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


int readDayC,readYearC,resultDayC,resultYearC;
string readMonthC,resultMonthC;
Calendar calendar = Calendar();
void Qustion1(){
    cout<<"From what year do you want to start de calculation\n";
    cout<<"Write year: ";
    cin>>readYearC;
    calendar.setReadYear(readYearC);
}
int dayOfYear= 0;
void dayOfYearNow(){
    if(calendar.getReadMonth()=="January"){
        dayOfYear = 0;
    }
    if(calendar.getReadMonth()=="February"){
        dayOfYear = 30;
    }
    if(calendar.getReadMonth()=="March"){
        dayOfYear = 59;
    }
    if(calendar.getReadMonth()=="April"){
        dayOfYear = 90;
    }
    if(calendar.getReadMonth()=="May"){
        dayOfYear = 120;
    }
    if(calendar.getReadMonth()=="June"){
        dayOfYear = 151;
    }
    if(calendar.getReadMonth()=="July"){
        dayOfYear = 181;
    }
    if(calendar.getReadMonth()=="August"){
        dayOfYear = 212;
    }
    if(calendar.getReadMonth()=="September"){
        dayOfYear = 244;
    }
    if(calendar.getReadMonth()=="Octomber"){
        dayOfYear = 274;
    }
    if(calendar.getReadMonth()=="November"){
        dayOfYear = 305;
    }
    if(calendar.getReadMonth()=="December"){
        dayOfYear = 334;
    }
}
void Qustion2(){
    cout<<"From what month of the year do you want to start de calculation\n";
    cout<<"Write month: ";
    cin>>readMonthC;
    calendar.setReadMonth(readMonthC);
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
    dayOfYearNow();
    
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

void calculate(){
    if(isLeapYear()){
        calendar.setResultYear(calendar.getBrainRead()/366);
        calendar.setResultDay((calendar.getBrainRead()+dayOfYear+calendar.getReadDay())%366);
        if(calendar.getResultDay()>=1 && calendar.getResultDay()<31){
            calendar.setResultMonth("January");
            calendar.setResultDay(calendar.getResultDay()-0);
        }
        else if(calendar.getResultDay()>=31 && calendar.getResultDay() < 61){
            calendar.setResultMonth("February");
            calendar.setResultDay(calendar.getResultDay()-30);
        }
        else if(calendar.getResultDay() >=61 && calendar.getResultDay() < 93){
            calendar.setResultMonth("March");
            calendar.setResultDay(calendar.getResultDay()-60);
        }
        else if(calendar.getResultDay()>=93 && calendar.getResultDay() <124){
            calendar.setResultMonth("April");
            calendar.setResultDay(calendar.getResultDay()-92);
        }
        else if(calendar.getResultDay()>=124 && calendar.getResultDay()<156){
            calendar.setResultMonth("May");
            calendar.setResultDay(calendar.getResultDay()-123);
        }
        else if(calendar.getResultDay()>=156 && calendar.getResultDay()<187){
            calendar.setResultMonth("June");
            calendar.setResultDay(calendar.getResultDay()-155);
        }
        else if(calendar.getResultDay() >=187 && calendar.getResultDay() <219){
            calendar.setResultMonth("July");
            calendar.setResultDay(calendar.getResultDay()-186);
        }
        else if(calendar.getResultDay()>=219 && calendar.getResultDay() < 241){
            calendar.setResultMonth("August");
            calendar.setResultDay(calendar.getResultDay()-218);
        }
        else if(calendar.getResultDay()>=241 && calendar.getResultDay()<272){
            calendar.setResultMonth("September");
            calendar.setResultDay(calendar.getResultDay()-240);
        }
        else if(calendar.getResultDay()>=272 && calendar.getResultDay()<306){
            calendar.setResultMonth("Octomber");
            calendar.setResultDay(calendar.getResultDay()-271);
        }
        else if(calendar.getResultDay()>=306 && calendar.getResultDay()<336){
            calendar.setResultMonth("November");
            calendar.setResultDay(calendar.getResultDay()-305);
        }
        else if(calendar.getResultDay()>=336 && calendar.getResultDay()<367){
            calendar.setResultMonth("December");
            calendar.setResultDay(calendar.getResultDay()-335);
        }
    }
    else{
        calendar.setResultDay(calendar.getBrainRead()%365);
        calendar.setResultDay(calendar.getBrainRead()%365);
        if(calendar.getResultDay()>=1 && calendar.getResultDay()<31){
            calendar.setResultMonth("January");
            calendar.setResultDay(calendar.getResultDay()-0);
        }
        else if(calendar.getResultDay()>=31 && calendar.getResultDay() < 60){
            calendar.setResultMonth("February");
            calendar.setResultDay(calendar.getResultDay()-30);
        }
        else if(calendar.getResultDay() >=60 && calendar.getResultDay() < 92){
            calendar.setResultMonth("March");
            calendar.setResultDay(calendar.getResultDay()-59);
        }
        else if(calendar.getResultDay()>=92 && calendar.getResultDay() <123){
            calendar.setResultMonth("April");
            calendar.setResultDay(calendar.getResultDay()-91);
        }
        else if(calendar.getResultDay()>=123 && calendar.getResultDay()<155){
            calendar.setResultMonth("May");
            calendar.setResultDay(calendar.getResultDay()-122);
        }
        else if(calendar.getResultDay()>=155 && calendar.getResultDay()<186){
            calendar.setResultMonth("June");
            calendar.setResultDay(calendar.getResultDay()-154);
        }
        else if(calendar.getResultDay() >=186 && calendar.getResultDay() <218){
            calendar.setResultMonth("July");
            calendar.setResultDay(calendar.getResultDay()-185);
        }
        else if(calendar.getResultDay()>=218 && calendar.getResultDay() < 240){
            calendar.setResultMonth("August");
            calendar.setResultDay(calendar.getResultDay()-217);
        }
        else if(calendar.getResultDay()>=240 && calendar.getResultDay()<271){
            calendar.setResultMonth("September");
            calendar.setResultDay(calendar.getResultDay()-239);
        }
        else if(calendar.getResultDay()>=271 && calendar.getResultDay()<305){
            calendar.setResultMonth("Octomber");
            calendar.setResultDay(calendar.getResultDay()-270);
        }
        else if(calendar.getResultDay()>=305 && calendar.getResultDay()<335){
            calendar.setResultMonth("November");
            calendar.setResultDay(calendar.getResultDay()-304);
        }
        else if(calendar.getResultDay()>=335 && calendar.getResultDay()<366){
            calendar.setResultMonth("December");
            calendar.setResultDay(calendar.getResultDay()-334);
        }
    }
    

}
void Show(){
    cout<<"And the calculations say that will be on: \n";
    cout<<"Day   |   Month   | Year    \n";
    cout<<calendar.getResultDay()<<"     "<<calendar.getResulMonth()<<"     "<<calendar.getResulYear()<<endl;
}
void decision(){
    bool stop = true;
    while(stop){
        cout<<"Do you want to continue calculating? (y/n)?\n";
        char answer;
        cin>>answer;
        if(answer == 'y'){
            stop = false;
        }
        else if (answer == 'n'){
            stop = false;
            running = false;
        }
        else{
            cout<<"Wrong input \n";
        }
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
        Show();
        decision();
    }
    
    
}