import java.util.Scanner;

public class Diffrance {
    public void Diffrance(){
        int January = 31;
        int February = 28;
        int March = 31;
        int April = 30;
        int May = 31;
        int June = 30;
        int July = 31;
        int August =31;
        int September = 30;
        int Octomber = 31;
        int November =30;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Write using numbers");
        System.out.println("First date:" + "  day/month/year exemple(31.12.2023)");
        System.out.println("Day:");
        int firstDay = scanner.nextInt();
        System.out.println("Month:");
        int firstMonth = scanner.nextInt();
        System.out.println("Year: ");
        int firstYear = scanner.nextInt();
        System.out.println("Your first date is: "+ firstDay + "."+firstMonth+"."+firstYear);
        System.out.println("Second date:" + "  day/month/year exemple(31.12.2023)");
        System.out.println("Day:");
        int secondDay = scanner.nextInt();
        System.out.println("Month:");
        int secondMonth = scanner.nextInt();
        System.out.println("Year: ");
        int secondYear = scanner.nextInt();
        System.out.println("Your second date is: "+ secondDay + "."+secondMonth+"."+secondYear);
        switch (Greatest(firstMonth, firstYear, secondYear, secondMonth, firstDay, secondDay)) {
            case 1:
                int yearGap = firstYear - secondYear;
                switch (Greatest(firstMonth, 0, 0, secondMonth, firstDay, secondDay)) {
                    case 4:
                        System.out.println("The diffrance is of: " + yearGap + " year/s and " + DiffranceMonth(secondMonth, firstMonth, secondDay, firstDay, January, February, March, 
                                                April, May, June, July, August, September, Octomber, November) + " day/s");
                        break;
                    case 3:
                         System.out.println("The diffrance is of: " + yearGap + " year/s and " + DiffranceMonth(firstMonth, secondMonth, firstDay, secondDay, January, February, March, 
                                 April, May, June, July, August, September, Octomber, November) + " day/s");
                        break;
                    case 5:
                         System.out.println("The diffrance is of: " + yearGap + " year/s and " + (firstDay- secondDay) + " day/s");
                        break;
                    case 6:
                        System.out.println("The diffrance is of: " + yearGap + " year/s and " + (secondDay- firstDay) + " day/s");
                        break;
                    default:
                        break;
                }   
                break;
            case 2:
                int yearGap1 = secondYear - firstYear;
                switch (Greatest(firstMonth, 0, 0, secondMonth, firstDay, secondDay)) {
                    case 4:
                        System.out.println("The diffrance is of: " + yearGap1 + " year/s and " + DiffranceMonth(secondMonth, firstMonth, secondDay, firstDay, January, February, March, 
                                                April, May, June, July, August, September, Octomber, November) + " day/s");
                        break;
                    case 3:
                         System.out.println("The diffrance is of: " + yearGap1 + " year/s and " + DiffranceMonth(firstMonth, secondMonth, firstDay, secondDay, January, February, March, 
                                 April, May, June, July, August, September, Octomber, November) + " day/s");
                        break;
                    case 5:
                         System.out.println("The diffrance is of: " + yearGap1 + " year/s and " + (firstDay- secondDay) + " day/s");
                        break;
                    case 6:
                        System.out.println("The diffrance is of: " + yearGap1 + " year/s and " + (secondDay- firstDay) + " day/s");
                        break;
                    default:
                        break;
                }                                                                          
                break;
            case 3:
               System.out.println("The diffrance is of: "+ DiffranceMonth(firstMonth,secondMonth,firstDay,secondDay,January,February,March,April,
                     May,June,July,August,September,Octomber,November)+ " days");
                break;
            case 4:
                System.out.println("The diffrance is of: "+ DiffranceMonth(secondMonth,firstMonth,secondDay,firstDay,January,February,March,April,
                                    May,June,July,August,September,Octomber,November) + " days");
                break;
            case 5:
                 int diffrance5 = firstDay - secondDay;
                 System.out.println("The diffrance is of: " + diffrance5 + " days");
                break;
            case 6:
                int diffrance6 = secondDay - firstDay;
                System.out.println("The diffrance is of: " + diffrance6 + " days");
                break;
            default:
                break;
        }
    }
    public static int Greatest(int firstMonth,int firstYear,int secondYear,int secondMonth,int firstDay,int secondDay){
        if(secondYear > firstYear){
            return 2;
        }
        else if(firstYear > secondYear){
            return 1;
        }else{
            if(secondMonth > firstMonth){
                return 4;
            }else if(firstMonth>secondMonth){
                return 3;
            }else{
                if(firstDay > secondDay){
                    return 5;
                }else if(secondDay > firstDay){
                    return 6;
                }else{
                    System.out.println("They are the same dates");
                    return 0; 
                }
            }
        }
    }
    public static int DiffranceMonth(int GraterMonth, int SmallerMonth,int GraterDayM, int SmallerDayM,int January,int February
                ,int March,int April,int May,int June,int July,int August,int September,int Octomber,int November){
        int diffrance = GraterDayM;
        int diffranceLocal = GraterMonth - SmallerMonth;
        switch (SmallerMonth) {
            case 1:
                switch (diffranceLocal) {
                    case 1:
                        diffrance += January-SmallerDayM;
                        break;
                    case 2:
                        diffrance += January-SmallerDayM + February;
                        break;
                    case 3:
                        diffrance += January-SmallerDayM + February +March;
                        break;
                    case 4:
                        diffrance += January-SmallerDayM + February +March +April;
                        break;
                    case 5:
                        diffrance += January-SmallerDayM + February +March +April + May;
                        break;
                    case 6:
                        diffrance += January-SmallerDayM + February +March +April + May+June;
                        break;
                    case 7:
                        diffrance += January-SmallerDayM + February +March +April + May+June + July;
                    break;
                    case 8:
                        diffrance += January-SmallerDayM + February +March +April + May+June + July+August;
                        break;
                    case 9:
                        diffrance += January-SmallerDayM + February +March +April + May+June + July+August + September;
                        break;
                    case 10:
                        diffrance += January-SmallerDayM + February +March +April + May+June + July+August + September + Octomber;
                        break;
                    case 11:
                        diffrance += January-SmallerDayM + February +March +April + May+June + July+August + September + Octomber+November;
                        break;
                    default:
                        break;
                }
                break;
            case 2:
            switch (diffranceLocal) {
                case 1:
                    diffrance += February-SmallerDayM;
                    break;
                case 2:
                    diffrance += February-SmallerDayM + March;
                    break;
                case 3:
                    diffrance += February-SmallerDayM + April +March;
                    break;
                case 4:
                    diffrance += February-SmallerDayM + May +March +April;
                    break;
                case 5:
                    diffrance += February-SmallerDayM + June +March +April + May;
                    break;
                case 6:
                    diffrance += February-SmallerDayM + July +March +April + May+June;
                    break;
                case 7:
                    diffrance += February-SmallerDayM + August +March +April + May+June + July;
                break;
                case 8:
                    diffrance += February-SmallerDayM + September +March +April + May+June + July+August;
                    break;
                case 9:
                    diffrance += February-SmallerDayM + Octomber +March +April + May+June + July+August + September;
                    break;
                case 10:
                    diffrance += February-SmallerDayM + November +March +April + May+June + July+August + September + Octomber;
                    break;
                default:
                    break;
            }
                break;
            case 3:
            switch (diffranceLocal) {
                case 1:
                    diffrance += March-SmallerDayM;
                    break;
                case 2:
                    diffrance += March-SmallerDayM + April;
                    break;
                case 3:
                    diffrance += March-SmallerDayM + May +April;
                    break;
                case 4:
                    diffrance += March-SmallerDayM + May +June +April;
                    break;
                case 5:
                    diffrance += March-SmallerDayM + July +June +April + May;
                    break;
                case 6:
                    diffrance += March-SmallerDayM + August +July +April + May+June;
                    break;
                case 7:
                    diffrance += March-SmallerDayM + August +September +April + May+June + July;
                break;
                case 8:
                    diffrance += March-SmallerDayM + September +Octomber +April + May+June + July+August;
                    break;
                case 9:
                    diffrance += March-SmallerDayM + November +Octomber +April + May+June + July+August + September;
                    break;
                default:
                    break;
            }
                break;
            case 4:
            switch (diffranceLocal) {
                case 1:
                    diffrance += April-SmallerDayM;
                    break;
                case 2:
                    diffrance += April-SmallerDayM + May;
                    break;
                case 3:
                    diffrance += April-SmallerDayM + May +June;
                    break;
                case 4:
                    diffrance += April-SmallerDayM + May +June +July;
                    break;
                case 5:
                    diffrance += April-SmallerDayM + June +July +August + May;
                    break;
                case 6:
                    diffrance += April-SmallerDayM + September +August +July + May+June;
                    break;
                case 7:
                    diffrance += April-SmallerDayM + Octomber +September +August + May+June + July;
                break;
                case 8:
                    diffrance += April-SmallerDayM + November +Octomber +September + May+June + July+August;
                    break;
            }
                break;
            case 5:
            switch (diffranceLocal) {
                case 1:
                    diffrance += May-SmallerDayM;
                    break;
                case 2:
                    diffrance += May-SmallerDayM + June;
                    break;
                case 3:
                    diffrance += May-SmallerDayM + June +July;
                    break;
                case 4:
                    diffrance += May-SmallerDayM + June +July +August;
                    break;
                case 5:
                   diffrance += May-SmallerDayM + June +July +August +September;
                    break;
                case 6:
                    diffrance += May-SmallerDayM + September +July +August + Octomber+June;
                    break;
                case 7:
                    diffrance += May-SmallerDayM + August +September +Octomber + November+June + July;
                break;
            }
                break;
            case 6:
            switch (diffranceLocal) {
                case 1:
                    diffrance += June-SmallerDayM;
                    break;
                case 2:
                    diffrance += June-SmallerDayM + July;
                    break;
                case 3:
                    diffrance += June-SmallerDayM +  July+August;
                    break;
                case 4:
                    diffrance += June-SmallerDayM + July +August +September;
                    break;
                case 5:
                    diffrance += June-SmallerDayM + July +August +September + Octomber;
                    break;
                case 6:
                    diffrance += June-SmallerDayM + July +August +September + Octomber+November;
                    break;
                default:
                    break;
            }
                break;
            case 7:
            switch (diffranceLocal) {
                case 1:
                    diffrance += July-SmallerDayM;
                    break;
                case 2:
                    diffrance += July-SmallerDayM + August;
                    break;
                case 3:
                    diffrance += July-SmallerDayM + August +September;
                    break;
                case 4:
                    diffrance += July-SmallerDayM + August +September +Octomber;
                    break;
                case 5:
                    diffrance += July-SmallerDayM + August +September +Octomber + November;
                    break;
                default:
                    break;
            }
                break;
            case 8:
            switch (diffranceLocal) {
                case 1:
                    diffrance += August-SmallerDayM;
                    break;
                case 2:
                    diffrance += August-SmallerDayM + September;
                    break;
                case 3:
                    diffrance += August-SmallerDayM + September +Octomber;
                    break;
                case 4:
                    diffrance += August-SmallerDayM + September +Octomber +November;
                    break;
                default:
                    break;
            }
                break;
            case 9:
            switch (diffranceLocal) {
                case 1:
                    diffrance += September-SmallerDayM;
                    break;
                case 2:
                    diffrance += September-SmallerDayM + Octomber;
                    break;
                case 3:
                    diffrance += September-SmallerDayM + Octomber +November;
                    break;
                default:
                    break;
            }
                break;
            case 10:
            switch (diffranceLocal) {
                case 1:
                    diffrance += Octomber-SmallerDayM;
                    break;
                case 2:
                    diffrance += Octomber-SmallerDayM + November;
                    break;
                default:
                    break;
            }
                break;
            case 11:
                diffrance += November-SmallerDayM;
                break;
        }
        return diffrance;
    }
}