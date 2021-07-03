import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.layout.HBox;
import javafx.scene.control.Button;

public class VBoxFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		
		Button b1 = new Button("one");
		Button b2 = new Button("two");
		Button b3 = new Button("three");
		VBox vbox = new VBox(); 
    	vbox.getChildren().addAll(b1,b2,b3);
		BorderPane borderPane = new BorderPane();
		borderPane.setLeft(vbox);
		borderPane.setCenter(new Button("center"));

		Scene scene = new Scene(borderPane);
		primaryStage.setTitle("");
		primaryStage.setScene(scene);
		primaryStage.show();
	}	

}