public class PictureBook extends Novel{
    private MusicAlbum album = new MusicAlbum(20);
    public PictureBook(){
        super(120);
    }
    public int numPages(){
        return album.totalTime();
    }
    public int wordsPerPage(){
        return 100;
    }
    public String toString(){
        return "with pictures";
    }
}
