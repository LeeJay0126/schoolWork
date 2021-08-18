public class MusicAlbum implements Media{
    private int numTracks;
    public MusicAlbum(int numTracks){
        this.numTracks = numTracks;
    }
    public int totalTime(){
        return this.numTracks * 4;
    }
    public String toString(){
        return "album";
    }
}
