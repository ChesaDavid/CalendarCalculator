public class Brain {
    public boolean running = true;
    private int units;
    public void setUnits(int units){
        this.units = units;
    }
    public void calculate(){
        Day day = new Day();
        int totalDays = day.getCalculatedDay() + units;
        int totalYears = totalDays / 365;
        Month month = new Month();
        Year year = new Year();
        year.setCalculatedYear(totalYears + year.getScanerYear());
        day.setCalculatedDay(totalDays%365);
        Main main = new Main();
        if(main.IsLeapYear(year.getCalculatedYear()-1) && day.getCalculatedDay() == 1){
            year.setCalculatedYear(year.getCalculatedYear()-1);
        }
        if(main.IsLeapYear(year.getCalculatedYear())){
            if(day.getCalculatedDay()>=1 && day.getCalculatedDay()<31){
                month.setCalculatedMonth("Junuary");
            }else if(day.getCalculatedDay()>=31 && day.getCalculatedDay()<60){
                month.setCalculatedMonth("February");
            }else if(day.getCalculatedDay()>=60 && day.getCalculatedDay()<91){
                month.setCalculatedMonth("March");
            }else if(day.getCalculatedDay()>=91 && day.getCalculatedDay()<121){
                month.setCalculatedMonth("April");
            }else if(day.getCalculatedDay()>=121 && day.getCalculatedDay()<152){
                month.setCalculatedMonth("May");
            }else if(day.getCalculatedDay()>=152 && day.getCalculatedDay()<182){
                month.setCalculatedMonth("June");
            }else if(day.getCalculatedDay()>=182 && day.getCalculatedDay()<213){
                month.setCalculatedMonth("July");
            }else if(day.getCalculatedDay()>=213 && day.getCalculatedDay()<244){
                month.setCalculatedMonth("August");
            }else if(day.getCalculatedDay()>=244 && day.getCalculatedDay()<274){
                month.setCalculatedMonth("September");
            }else if(day.getCalculatedDay() >=274 && day.getCalculatedDay()<305){
                month.setCalculatedMonth("Ocomber");
            }else if(day.getCalculatedDay()>=305 && day.getCalculatedDay()<335){
                month.setCalculatedMonth("November");
            }else if(day.getCalculatedDay()>335 && day.getCalculatedDay()<=366){
                month.setCalculatedMonth("December");
            }
        }else{
           if(day.getCalculatedDay()>=1 && day.getCalculatedDay()<31){
                month.setCalculatedMonth("Junuary");
            }else if(day.getCalculatedDay()>=31 && day.getCalculatedDay()<=59){
                month.setCalculatedMonth("February");
            }else if(day.getCalculatedDay()>=59 && day.getCalculatedDay()<=90){
                month.setCalculatedMonth("March");
            }else if(day.getCalculatedDay()>=90 && day.getCalculatedDay()<=120){
                month.setCalculatedMonth("April");
            }else if(day.getCalculatedDay()>=120 && day.getCalculatedDay()<=150){
                month.setCalculatedMonth("May");
            }else if(day.getCalculatedDay()>=151 && day.getCalculatedDay()<=181){
                month.setCalculatedMonth("June");
            }else if(day.getCalculatedDay()>=181 && day.getCalculatedDay()<=212){
                month.setCalculatedMonth("July");
            }else if(day.getCalculatedDay()>=212 && day.getCalculatedDay()<=243){
                month.setCalculatedMonth("August");
            }else if(day.getCalculatedDay()>=243 && day.getCalculatedDay()<=272){
                month.setCalculatedMonth("September");
            }else if(day.getCalculatedDay() >=273 && day.getCalculatedDay()<=302){
                month.setCalculatedMonth("Ocomber");
            }else if(day.getCalculatedDay()>=304 && day.getCalculatedDay()<=334){
                month.setCalculatedMonth("November");
            }else if(day.getCalculatedDay()>334 && day.getCalculatedDay()<=365){
                month.setCalculatedMonth("December");
            }
        }
    }
}
