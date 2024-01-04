public class Day {
    private int  scanerDay;
    private int calculatedDay;

    public void setScanerDay(int scanerDay){
        if(scanerDay < 1 || scanerDay > 31){
            this.scanerDay = -1;
        }
        else{
            this.scanerDay = scanerDay;
        }
    }
    public void setCalculatedDay(int calculatedDay){
        this.calculatedDay = calculatedDay;
    }
    public int getScanerDay(){
        return scanerDay;
    }
    public int getCalculatedDay(){
        return calculatedDay;
    }
}