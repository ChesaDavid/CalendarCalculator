import java.util.Scanner;

public class CalendarCalculator {


    public static void main(String[] args) {
        
        while(running){
            System.out.println("Hello World and welcome to a calendar calculator");
            Day inputDay = new Day();
            int day = 
            inputDay.setScanerDay();
            boolean running = true;
            Scanner scanner = new Scanner(System.in);
            int year = 0;
            String month = "zero";
            int day = 0;
            int dayOfYear =0;
            String answer = "Zero";
            String errorCatcher ="";
            FirstQuestion(year,scanner,errorCatcher);
            SecondQuestion(month,scanner,errorCatcher);
            ThirdQuestion(day,scanner,errorCatcher);
            WhatDayOfYearIAm(month,day,year,dayOfYear);
            System.out.println(dayOfYear);
            wait(1000);
            ForthQuestion(answer,scanner,running,errorCatcher);
        }


    }
    public static void FirstQuestion(int year ,Scanner scanner,String errorCatcher){

        System.out.println();
        System.out.println("From what year do you want to calculate?");
        year = scanner.nextInt();
        errorCatcher = scanner.nextLine();
    }
    public static void SecondQuestion(String month,Scanner scanner,String errorCatcher){
        System.out.println();
        System.out.println("From what month do you want to calculate?");
        month = scanner.nextLine();
        errorCatcher = scanner.nextLine();
    }
    public static void ThirdQuestion(int day,Scanner scanner,String errorCatcher){

        System.out.println();
        System.out.println("What day of the month?");
         day = scanner.nextInt();
        errorCatcher = scanner.nextLine();
    }
    public static void ForthQuestion(String answer,Scanner scanner,boolean running,String errorCatcher){
        System.out.println();
        System.out.println("Do you want to leave (y/n)");
        answer = scanner.nextLine();
        errorCatcher = scanner.nextLine();

    }
    public static  void WhatDayOfYearIAm(String month , int day,int year,int  totalDays){
        int startDay ;
        switch (month) {
            case "January":
                startDay = 1;
                break;
            case "February":
                startDay = 31;
                break;
            case "March":
                if (IsLeapYear(year)) {
                    startDay = 60;
                } else {
                    startDay = 59;
                }
                break;
            case "April":
                if (IsLeapYear(year)) {
                    startDay = 91;
                } else {
                    startDay = 90;
                }
                break;
            case "May":
                if (IsLeapYear(year)) {
                    startDay = 121;
                } else {
                    startDay = 120;
                }
                break;
            case "June":
                if (IsLeapYear(year)) {
                    startDay = 152;
                } else {
                    startDay = 151;
                }
                break;
            case "July":
                if (IsLeapYear(year)) {
                    startDay = 182;
                } else {
                    startDay = 181;
                }
                break;
            case "August":
                if (IsLeapYear(year)) {
                    startDay = 213;
                } else {
                    startDay = 212;
                }
                break;
            case "September":
                if (IsLeapYear(year)) {
                    startDay = 244;
                } else {
                    startDay = 243;
                }
                break;
            case "October":
                if (IsLeapYear(year)) {
                    startDay = 274;
                } else {
                    startDay = 273;
                }
                break;
            case "November":
                if (IsLeapYear(year)) {
                    startDay = 305;
                } else {
                    startDay = 304;
                }
                break;
            case "December":
                if (IsLeapYear(year)) {
                    startDay = 335;
                } else {
                    startDay = 334;
                }
                break;
            default:
                startDay = -1;
                break;

        }
        totalDays = startDay + day;
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
