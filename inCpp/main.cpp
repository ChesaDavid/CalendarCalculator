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
        dayOfYear = 31;
    }
    if(calendar.getReadMonth()=="March"){
        dayOfYear = 60;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="April"){
        dayOfYear = 91;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="May"){
        dayOfYear = 121;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="June"){
        dayOfYear = 152;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="July"){
        dayOfYear = 182;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="August"){
        dayOfYear = 213;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="September"){
        dayOfYear = 244;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="Octomber"){
        dayOfYear = 274;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="November"){
        dayOfYear = 305;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    if(calendar.getReadMonth()=="December"){
        dayOfYear = 334;
        if(isLeapYear()){
            dayOfYear++;
        }
    }
    calendar.setBrainRead(dayOfYear+calendar.getReadDay());
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
        calendar.setBrainRead(calendar.getBrainRead());
        calendar.setResultYear(calendar.getReadYear() + calendar.getBrainRead()/366);
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
        calendar.setResultYear(calendar.getReadYear() + (calendar.getBrainRead()/365));
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
int firstYear,firstDay,firstMonth,secondYear,secondDay,secondMonth;
int diffranceMonth(int graterM,int smallarM,int graterD,int smallarD){
    int diffranceOf = 0;
    int diffranceMonth = graterM - smallarM;
    int January = 31;
    int February = 28;
    int March = 31;
    int April = 30;
    int May = 31;
    int June = 30;
    int July = 31;
    int August = 31;
    int September = 30;
    int Octomber = 31;
    int November = 30;
    switch (smallarM)
    {
    case 1:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=January-smallarD+graterD;
                break;
            case 2:
                diffranceOf=January-smallarD+February+graterD;
                break;
            case 3:
                diffranceOf=January-smallarD+February+March+graterD;
                break;
            case 4:
                diffranceOf=January-smallarD+February+March+April+graterD;
                break;
            case 5:
                diffranceOf=January-smallarD+February+March+April+May+graterD;
                break;
            case 6:
                diffranceOf=January-smallarD+February+March+April+May+June+graterD;
                break;
            case 7:
                diffranceOf=January-smallarD+February+March+April+May+June+July+graterD;
                break;
            case 8:
                diffranceOf=January-smallarD+February+March+April+May+June+July+August+graterD;
                break;
            case 9:
                diffranceOf=January-smallarD+February+March+April+May+June+July+August+September+graterD;
                break;
            case 10:
                diffranceOf=January-smallarD+February+March+April+May+June+July+August+September+Octomber+graterD;
                break;
            case 11:
                diffranceOf=January-smallarD+February+March+April+May+June+July+August+September+Octomber+November+graterD;
                break;
        }
        break;
    case 2:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=February-smallarD+graterD;
                break;
            case 2:
                diffranceOf=February-smallarD+March+graterD;
                break;
            case 3:
                diffranceOf=February-smallarD+April+March+graterD;
                break;
            case 4:
                diffranceOf=February-smallarD+May+March+April+graterD;
                break;
            case 5:
                diffranceOf=February-smallarD+June+March+April+May+graterD;
                break;
            case 6:
                diffranceOf=February-smallarD+July+March+April+May+June+graterD;
                break;
            case 7:
                diffranceOf=February-smallarD+August+March+April+May+June+July+graterD;
                break;
            case 8:
                diffranceOf=February-smallarD+September+March+April+May+June+July+August+graterD;
                break;
            case 9:
                diffranceOf=February-smallarD+Octomber+March+April+May+June+July+August+September+graterD;
                break;
            case 10:
                diffranceOf=February-smallarD+November+March+April+May+June+July+August+September+Octomber+graterD;
                break;
        }
        break;
    case 3:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=March-smallarD+graterD;
                break;
            case 2:
                diffranceOf=March-smallarD+April+graterD;
                break;
            case 3:
                diffranceOf=March-smallarD+April+May+graterD;
                break;
            case 4:
                diffranceOf=March-smallarD+May+June+April+graterD;
                break;
            case 5:
                diffranceOf=March-smallarD+June+July+April+May+graterD;
                break;
            case 6:
                diffranceOf=March-smallarD+July+August+April+May+June+graterD;
                break;
            case 7:
                diffranceOf=March-smallarD+August+September+April+May+June+July+graterD;
                break;
            case 8:
                diffranceOf=March-smallarD+September+Octomber+April+May+June+July+August+graterD;
                break;
            case 9:
                diffranceOf=March-smallarD+Octomber+November+April+May+June+July+August+September+graterD;
                break;
        }
        break;
    case 4:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=April-smallarD+graterD;
                break;
            case 2:
                diffranceOf=April-smallarD+May+graterD;
                break;
            case 3:
                diffranceOf=April-smallarD+June+May+graterD;
                break;
            case 4:
                diffranceOf=April-smallarD+May+June+July+graterD;
                break;
            case 5:
                diffranceOf=April-smallarD+June+July+August+May+graterD;
                break;
            case 6:
                diffranceOf=April-smallarD+July+August+September+May+June+graterD;
                break;
            case 7:
                diffranceOf=April-smallarD+August+September+Octomber+May+June+July+graterD;
                break;
            case 8:
                diffranceOf=April-smallarD+September+Octomber+November+May+June+July+August+graterD;
                break;
        }
        break;
    case 5:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=May-smallarD+graterD;
                break;
            case 2:
                diffranceOf=May-smallarD+June+graterD;
                break;
            case 3:
                diffranceOf=May-smallarD+June+July+graterD;
                break;
            case 4:
                diffranceOf=May-smallarD+August+June+July+graterD;
                break;
            case 5:
                diffranceOf=May-smallarD+June+July+August+September+graterD;
                break;
            case 6:
                diffranceOf=May-smallarD+July+August+September+Octomber+June+graterD;
                break;
            case 7:
                diffranceOf=May-smallarD+August+September+Octomber+November+June+July+graterD;
                break;
        }
        break;
    case 6:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=June-smallarD+graterD;
                break;
            case 2:
                diffranceOf=June-smallarD+July+graterD;
                break;
            case 3:
                diffranceOf=June-smallarD+August+July+graterD;
                break;
            case 4:
                diffranceOf=June-smallarD+August+September+July+graterD;
                break;
            case 5:
                diffranceOf=June-smallarD+Octomber+July+August+September+graterD;
                break;
            case 6:
                diffranceOf=June-smallarD+July+August+September+Octomber+November+graterD;
                break;
        }
        break;
    case 7:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=July-smallarD+graterD;
                break;
            case 2:
                diffranceOf=July-smallarD+August+graterD;
                break;
            case 3:
                diffranceOf=July-smallarD+August+September+graterD;
                break;
            case 4:
                diffranceOf=July-smallarD+August+September+Octomber+graterD;
                break;
            case 5:
                diffranceOf=July-smallarD+Octomber+November+August+September+graterD;
                break;
        }
        break;
    case 8:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=August-smallarD+graterD;
                break;
            case 2:
                diffranceOf=August-smallarD+September+graterD;
                break;
            case 3:
                diffranceOf=August-smallarD+Octomber+September+graterD;
                break;
            case 4:
                diffranceOf=August-smallarD+November+September+Octomber+graterD;
                break;
        }
        break;
    case 9:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=September-smallarD+graterD;
                break;
            case 2:
                diffranceOf=September-smallarD+Octomber+graterD;
                break;
            case 3:
                diffranceOf=September-smallarD+Octomber+November+graterD;
                break;
        }
        break;
    case 10:
        switch (diffranceMonth)
        {
            case 1:
                diffranceOf=Octomber-smallarD+graterD;
                break;
            case 2:
                diffranceOf=Octomber-smallarD+November+graterD;
                break;
        }
        break;
    case 11:
        diffranceMonth=November=smallarD+graterD;
        break;
    }
    return diffranceMonth;
}
void secondChoice(){
    cout<<"The function does not take in consideration the lap year"<<endl;
    cout<<"First date (exemple 31.12.2023)"<<endl;
    cout<<"Day:";
    cin>>firstDay;
    cout<<endl;
    cout<<"Month:";
    cin>>firstMonth;
    cout<<endl;
    cout<<"Year:";
    cin>>firstYear;
    cout<<endl;
    cout<<"Second date (exemple 30.12.2023)"<<endl;
    cout<<"Day:";
    cin>>secondDay;
    cout<<endl;
    cout<<"Month:";
    cin>>secondMonth;
    cout<<endl;
    cout<<"Year:";
    cin>>secondYear;
    cout<<endl;
    if(firstYear-secondYear<0){
        if(firstMonth-secondMonth<0){
            cout<<"The diffrance is of "<<secondYear-firstYear<<" year/s"<<endl;
            cout<<"And "<<diffranceMonth(secondMonth,firstMonth,secondDay,firstDay)<<" day/s"<<endl;
        }else if(firstMonth-secondMonth>0){
            cout<<"The diffrance is of "<<secondYear-firstYear<<" year/s"<<endl;
            cout<<"And "<<diffranceMonth(firstMonth,secondMonth,firstDay,secondDay)<<" day/s"<<endl;
        }else{
            if(firstDay-secondDay<=0){
                cout<<"The diffrance is of "<<secondYear-firstYear<<" year/s"<<endl;
                cout<<"And "<<secondDay-firstDay<<" day/s"<<endl;
            }else{
                cout<<"The diffrance is of "<<secondYear-firstYear<<" year/s"<<endl;
                cout<<"And "<<firstDay-secondDay<<" day/s"<<endl;
            }   
        }
    }else if(firstYear-secondYear>0){
        if(firstMonth-secondMonth<0){
            cout<<"The diffrance is of "<<firstYear-secondYear<<" year/s"<<endl;
            cout<<"And "<<diffranceMonth(secondMonth,firstMonth,secondDay,firstDay)<<" day/s"<<endl;
        }else if(firstMonth-secondMonth>0){
            cout<<"The diffrance is of "<<firstYear-secondYear<<" year/s"<<endl;
            cout<<"And "<<diffranceMonth(firstMonth,secondMonth,firstDay,secondDay)<<" day/s"<<endl;
        }else{
            if(firstDay-secondDay<=0){
                cout<<"The diffrance is of "<<firstYear-secondYear<<" year/s"<<endl;
                cout<<"And "<<secondDay-firstDay<<" day/s"<<endl;
            }else{
                cout<<"The diffrance is of "<<firstYear-secondYear<<" year/s"<<endl;
                cout<<"And "<<firstDay-secondDay<<" day/s"<<endl;
            }   
        }
    }else{
        if(firstMonth-secondMonth<0){
            cout<<"The diffrance is of "<<diffranceMonth(secondMonth,firstMonth,secondDay,firstDay)<<" day/s"<<endl;
        }else if(firstMonth-secondMonth>0){
            cout<<"The diffrance is of "<<diffranceMonth(firstMonth,secondMonth,firstDay,secondDay)<<" day/s"<<endl;
        }else{
            if(firstDay-secondDay<0){
                cout<<"The diffrance is of "<<secondDay-firstDay<<" day/s"<<endl;
            }else if(firstDay-secondDay>0){
                cout<<"The diffrance is of "<<firstDay-secondDay<<" day/s"<<endl;
            }else{
                cout<<"The dates are similar"<<endl;
            }
        }
    }
    
    
}
int main(){
    
    while (running)
    {cout<<endl;
        cout<<"Menu"<<endl;
        cout<<"1.Calculate from a date"<<endl;
        cout<<"2.Calculate the diffrance between two dates"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<endl;
        int decision;
        cin>>decision;
        if(decision == 1){
            Qustion1();
            validation1();
            Qustion2();
            validation2();
            Qustion3();
            validation3();
            option1();
            Show();
        }
        else if(decision == 2){
            secondChoice();
        }
        else if(decision == 3){
            running = false;
        }else{
            cout<<" Invalid input";
        }
        }
}