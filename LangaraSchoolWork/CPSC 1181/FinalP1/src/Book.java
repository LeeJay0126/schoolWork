public abstract class Book implements Media {
    protected static final int WORDS_PER_MINUTE = 250;
    abstract int numPages();
    public int wordsPerPage(){
        return 300;
    }
    public int totalTime(){
        return numPages()*wordsPerPage()/WORDS_PER_MINUTE;
    }
    public String toString(){
        return "page book";
    }
}
