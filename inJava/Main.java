import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Day day = new Day();
        Month month = new Month();
        Year year = new Year();
        Brain brain = new Brain();
        Scanner scanner = new Scanner(System.in);
        String errorChatcher ="";
        Diffrance diffrance = new Diffrance();
        boolean running = true;
        while(running){
            
            menu();
            int option = scanner.nextInt();
            switch (option) {
                case 1:
                    calculateTo(day, month, year, brain, scanner, errorChatcher);
                    break;
                case 2:
                    diffrance.Diffrance();
                    break;
                case 3:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid input");
                    break;
            }
        }
        

    }
    public static void menu(){
        System.out.println();
        System.out.println("1.Calculate from a date using days or weeks");
        System.out.println("2.Calculate the diffrance between to dates");
        System.out.println("3.Exit");
        System.out.println("Option:");
    }
    public static void calculateTo(Day day,Month month , Year year, Brain brain,Scanner scanner, String errorChatcher){
            FirstQuestion();
            year.setScanerYear(scanner.nextInt());
            SecondQuestion();
            errorChatcher = scanner.nextLine();
            String localvarMonth = scanner.nextLine();
            month.setScanerMonth(localvarMonth);
            ThirdQuestion();
            wait(3000);
            day.setScanerDay(scanner.nextInt());
            WhatDayOfYearIAm(month, day, year, brain);
            Question(scanner, brain);
            calculate(day,month,year,brain);
            System.out.println("Year :"+year.getCalculatedYear());
            System.out.println("Month :" + month.getCalculatedMonth());
            day.setCalculatedDay(day.getCalculatedDay());
            System.out.println("Day :" + day.getCalculatedDay());
            wait(1000);


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
    public static  void WhatDayOfYearIAm(Month month, Day day,Year year ,Brain brain){
        int startDay;
        switch (month.getScanerMonth()) {
            case "January":
                startDay = 0;
                break;
            case "February":
                startDay = 30;
                break;
            case "March":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 59;
                } else {
                    startDay = 58;
                }
                break;
            case "April":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 90;
                } else {
                    startDay = 89;
                }
                break;
            case "May":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 120;
                } else {
                    startDay = 119;
                }
                break;
            case "June":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 151;
                } else {
                    startDay = 150;
                }
                break;
            case "July":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 181;
                } else {
                    startDay = 180;
                }
                break;
            case "August":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 212;
                } else {
                    startDay = 211;
                }
                break;
            case "September":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 243;
                } else {
                    startDay = 242;
                }
                break;
            case "Octomber":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 273;
                } else {
                    startDay = 272;
                }
                break;
            case "November":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 304;
                } else {
                    startDay = 303;
                }
                break;
            case "December":
                if (IsLeapYear(year.getScanerYear())) {
                    startDay = 335;
                } else {
                    startDay = 332;
                }
                break;
            default:
                startDay = -1;
                System.out.println("Wrong input");
                brain.running = false;
                break;

        }
        day.setCalculatedDay(startDay + day.getScanerDay());
        
    }
    public static void Question(Scanner scanner,Brain brain){
        System.out.println("What mejurment of time do you want to chose> 1 = days and 7 = weeks");
        int answer = scanner.nextInt();
        switch (answer) {
            case 1:
                System.out.println("How many days?");
                int units = scanner.nextInt();
                brain.setUnits(units);
                break;
            case 7:
                System.out.println("How many weeks?");
                int unitsw = scanner.nextInt();
                unitsw = unitsw * 7;
                brain.setUnits(unitsw);
                break;
            default:
                System.out.println("Wrong input");
                brain.running = false;
                break;
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
    public static void calculate(Day day,Month month,Year year,Brain brain){
        int totalDays = day.getCalculatedDay() + brain.getUnits();
        int totalYears = totalDays / 365;
        totalYears = year.getScanerYear() + totalYears;
        year.setCalculatedYear(totalYears);
        day.setCalculatedDay(totalDays%365);
        if(IsLeapYear(year.getCalculatedYear()-1) && day.getCalculatedDay() == 1){
            year.setCalculatedYear(year.getCalculatedYear()-1);
        }
        if(IsLeapYear(year.getCalculatedYear())){
            if(day.getCalculatedDay()>=1 && day.getCalculatedDay()<31){
                day.setCalculatedDay(day.getCalculatedDay()-1);
                month.setCalculatedMonth("January");
            }else if(day.getCalculatedDay()>=31 && day.getCalculatedDay()<60){
                day.setCalculatedDay(day.getCalculatedDay()-31);
                month.setCalculatedMonth("February");
            }else if(day.getCalculatedDay()>=60 && day.getCalculatedDay()<91){
                day.setCalculatedDay(day.getCalculatedDay()-60);
                month.setCalculatedMonth("March");
            }else if(day.getCalculatedDay()>=91 && day.getCalculatedDay()<121){
                day.setCalculatedDay(day.getCalculatedDay()-91);
                month.setCalculatedMonth("April");
            }else if(day.getCalculatedDay()>=121 && day.getCalculatedDay()<152){
                day.setCalculatedDay(day.getCalculatedDay()-121);
                month.setCalculatedMonth("May");
            }else if(day.getCalculatedDay()>=152 && day.getCalculatedDay()<182){
                day.setCalculatedDay(day.getCalculatedDay()-152);
                month.setCalculatedMonth("June");
            }else if(day.getCalculatedDay()>=182 && day.getCalculatedDay()<213){
                day.setCalculatedDay(day.getCalculatedDay()-182);
                month.setCalculatedMonth("July");
            }else if(day.getCalculatedDay()>=213 && day.getCalculatedDay()<244){
                day.setCalculatedDay(day.getCalculatedDay()-213);
                month.setCalculatedMonth("August");
            }else if(day.getCalculatedDay()>=244 && day.getCalculatedDay()<274){
                day.setCalculatedDay(day.getCalculatedDay()-244);
                month.setCalculatedMonth("September");
            }else if(day.getCalculatedDay() >=274 && day.getCalculatedDay()<305){
                day.setCalculatedDay(day.getCalculatedDay()-274);
                month.setCalculatedMonth("Ocomber");
            }else if(day.getCalculatedDay()>=305 && day.getCalculatedDay()<335){
                day.setCalculatedDay(day.getCalculatedDay()-305);
                month.setCalculatedMonth("November");
            }else if(day.getCalculatedDay()>335 && day.getCalculatedDay()<=366){
                day.setCalculatedDay(day.getCalculatedDay()-335);
                month.setCalculatedMonth("December");
            }
        }else{
           if(day.getCalculatedDay()>=1 && day.getCalculatedDay()<31){
            day.setCalculatedDay(day.getCalculatedDay()-1);
                month.setCalculatedMonth("January");
            }else if(day.getCalculatedDay()>=31 && day.getCalculatedDay()<=59){
                day.setCalculatedDay(day.getCalculatedDay()-31);
                month.setCalculatedMonth("February");
            }else if(day.getCalculatedDay()>=59 && day.getCalculatedDay()<=90){
                day.setCalculatedDay(day.getCalculatedDay()-59);
                month.setCalculatedMonth("March");
            }else if(day.getCalculatedDay()>=90 && day.getCalculatedDay()<=120){
                day.setCalculatedDay(day.getCalculatedDay()-90);
                month.setCalculatedMonth("April");
            }else if(day.getCalculatedDay()>=120 && day.getCalculatedDay()<=150){
                day.setCalculatedDay(day.getCalculatedDay()-120);
                month.setCalculatedMonth("May");
            }else if(day.getCalculatedDay()>=151 && day.getCalculatedDay()<=181){
                day.setCalculatedDay(day.getCalculatedDay()-151);
                month.setCalculatedMonth("June");
            }else if(day.getCalculatedDay()>=181 && day.getCalculatedDay()<=212){
                day.setCalculatedDay(day.getCalculatedDay()-181);
                month.setCalculatedMonth("July");
            }else if(day.getCalculatedDay()>=212 && day.getCalculatedDay()<=243){
                day.setCalculatedDay(day.getCalculatedDay()-212);
                month.setCalculatedMonth("August");
            }else if(day.getCalculatedDay()>=243 && day.getCalculatedDay()<=272){
                day.setCalculatedDay(day.getCalculatedDay()-243);
                month.setCalculatedMonth("September");
            }else if(day.getCalculatedDay() >=273 && day.getCalculatedDay()<=302){
                day.setCalculatedDay(day.getCalculatedDay()-273);
                month.setCalculatedMonth("Ocomber");
            }else if(day.getCalculatedDay()>=304 && day.getCalculatedDay()<=334){
                day.setCalculatedDay(day.getCalculatedDay()-304);
                month.setCalculatedMonth("November");
            }else if(day.getCalculatedDay()>334 && day.getCalculatedDay()<=365){
                day.setCalculatedDay(day.getCalculatedDay()-334);
                month.setCalculatedMonth("December");
            }
        }
    }
}
