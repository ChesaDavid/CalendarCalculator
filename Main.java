import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        boolean running = true;
        Day day = new Day();
        Month month = new Month();
        Year year = new Year();
        Brain brain = new Brain();
        Scanner scanner = new Scanner(System.in);
        while(running){
            FirstQuestion();
            int localvarYear = scanner.nextInt();
            year.setScanerYear(localvarYear);
            SecondQuestion();
            String localvarMonth = scanner.nextLine();
            month.setScanerMonth(localvarMonth);
            ThirdQuestion();
            int localvarDay = scanner.nextInt();
            day.setScanerDay(localvarDay);
            WhatDayOfYearIAm(month.getScanerMonth(),day.getScanerDay(),year.getScanerYear(),day);
            Question(scanner, running , brain);
            brain.calculate();
            System.out.println("Year :"+year.getCalculatedYear());
            System.out.println("Month :" + month.getCalculatedMonth());
            System.out.println("Day :" + day.getCalculatedDay());
            lastQuestion(running, scanner);
            wait(1000);
        }


    }
    public static void FirstQuestion(){

        System.out.println();
        System.out.println("From what year do you want to calculate?");
    }
    public static void SecondQuestion(){
        System.out.println();
        System.out.println("From what month do you want to calculate?");
    }
    public static void ThirdQuestion(){
        System.out.println();
        System.out.println("What day of the month?");
    }
    public static void ForthQuestion(){
        System.out.println();
        System.out.println("Do you want to leave (y/n)");


    }
    public static  void WhatDayOfYearIAm(String month , int day,int year, Day day2){
        int startDay ;
        switch (month) {
            case "January":
                startDay = 0;
                break;
            case "February":
                startDay = 30;
                break;
            case "March":
                if (IsLeapYear(year)) {
                    startDay = 59;
                } else {
                    startDay = 58;
                }
                break;
            case "April":
                if (IsLeapYear(year)) {
                    startDay = 90;
                } else {
                    startDay = 89;
                }
                break;
            case "May":
                if (IsLeapYear(year)) {
                    startDay = 120;
                } else {
                    startDay = 119;
                }
                break;
            case "June":
                if (IsLeapYear(year)) {
                    startDay = 151;
                } else {
                    startDay = 150;
                }
                break;
            case "July":
                if (IsLeapYear(year)) {
                    startDay = 181;
                } else {
                    startDay = 180;
                }
                break;
            case "August":
                if (IsLeapYear(year)) {
                    startDay = 212;
                } else {
                    startDay = 211;
                }
                break;
            case "September":
                if (IsLeapYear(year)) {
                    startDay = 243;
                } else {
                    startDay = 242;
                }
                break;
            case "October":
                if (IsLeapYear(year)) {
                    startDay = 273;
                } else {
                    startDay = 272;
                }
                break;
            case "November":
                if (IsLeapYear(year)) {
                    startDay = 304;
                } else {
                    startDay = 303;
                }
                break;
            case "December":
                if (IsLeapYear(year)) {
                    startDay = 335;
                } else {
                    startDay = 332;
                }
                break;
            default:
                startDay = -1;
                break;

        }
        day2.setCalculatedDay(day + startDay);
        
    }
    public static void Question(Scanner scanner,boolean running ,Brain brain){
        System.out.println("What majurment of time do you want to chose>(days / weeks)");
        String answer = scanner.nextLine();
        if(answer == "days"){
            System.out.println("How many days?");
            int units = scanner.nextInt();
            brain.setUnits(units);
        }
        else if (answer == "weeks") {
            System.out.println("How many weeks?");
            int units = scanner.nextInt();
            brain.setUnits(units*7);
        }else{
            System.out.println("Wrong input");
            running = false;
        }
    }
    public static boolean IsLeapYear(int year){
        if(year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
    public static void lastQuestion(boolean running,Scanner scanner){
        System.out.println("Do you wish to quit the program (y/n)?");
        String answer = scanner.nextLine();
        if(answer == "y"){
            running = false;
        }
    }
    public static void wait(int ms)
    {
        try
        {
            Thread.sleep(ms);
        }
        catch(InterruptedException ex)
        {
            Thread.currentThread().interrupt();
        }
    }
}
