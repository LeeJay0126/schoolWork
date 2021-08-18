public class Novel extends Book{
    private int pages;
    public Novel(int pages){
        this.pages = pages;
    }
    public int numPages(){
        return this.pages;
    }
    public String toString(){
        return numPages()+"";
    }

}
