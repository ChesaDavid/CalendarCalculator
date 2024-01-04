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
        this.scanerMonth = scanerMonth;
        System.out.println("Chosed month :" + scanerMonth);
    }
    public void setCalculatedMonth(String calculatedMonth){
        this.calculatedMonth = calculatedMonth;
        
    }
}
