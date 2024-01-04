public class Year {
    private int scanerYear;
    private int calculatedYear;
    public int getScanerYear(){
        return scanerYear;
    }
    public int getCalculatedYear(){
        return calculatedYear;
    }
    public void setScanerYear(int scanerYear){
        this.scanerYear = scanerYear;
        System.out.println("Chosed year :" + scanerYear);
    }
    public void setCalculatedYear(int calculatedYear){
        this.calculatedYear = calculatedYear;
    }

}
