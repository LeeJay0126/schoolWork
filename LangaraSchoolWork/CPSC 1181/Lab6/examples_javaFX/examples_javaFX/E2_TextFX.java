import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;


public class E2_TextFX extends Application{
	@Override
	public void start(Stage stage){
		// first create a Text
		Text text1 = new Text(100,50,"first line");
		//then add to the root at creation time
		Pane root = new Pane(text1);

		root.setPrefSize(400,200);
		Scene scene = new Scene(root);

		//or, create a Text
        Text text2 = new Text(100,100,"second line");
        //added to the root 
        root.getChildren().add(text2);

		stage.setScene(scene);
		stage.setTitle("Empty");
		stage.show();
	}
	

	public static void main(String[] args){
		launch(args);
	}
}