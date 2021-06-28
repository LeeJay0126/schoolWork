import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;

public class E1_EmptyFX extends Application{
	@Override
	public void start(Stage stage){
		Pane root = new Pane();
		root.setPrefSize(400,200);
		Scene scene = new Scene(root);
		stage.setScene(scene);

		stage.setTitle("Empty");
		
		stage.show();
	}
	

	public static void main(String[] args){
		launch(args);
	}
}