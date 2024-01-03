public class Day {
    private int  scanerDay;
    public void setScanerDay(int scanerDay){
        if(scanerDay < 1 || scanerDay > 31){
            this.scanerDay = -1;
        }
        else{
            this.scanerDay = scanerDay;
        }
    }
    public int getScanerDay(){
        return scanerDay;
    }
}