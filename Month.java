public class Month {
    private String scanerMonth;
    private String calculatedMonth;
    public String getScanerMonth(){
        return scanerMonth;
    }
    public String getCalculatedMonth(){
        return calculatedMonth;
    }
    public void setScanerMonth(String scanerMonth){
        boolean validMonth = false;
        switch (scanerMonth) {
            case "January","February","March","April","May","June","July","August","September","Octomber","Noveber","December"->validMonth = true;
            default->validMonth = false;
        }
        if(validMonth){
            this.scanerMonth = scanerMonth;
        }
        else{
            this.scanerMonth = "Error";
        }
    }
    public void setCalculatedMonth(String calculatedMonth){
        this.calculatedMonth = calculatedMonth;
    }
}
