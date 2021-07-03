import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.control.Button;
import javafx.geometry.Pos;

public class HBoxFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		
		Button b1 = new Button("one");
		Button b2 = new Button("two");
		Button b3 = new Button("three");
		HBox hbox = new HBox(10); // margin between elements
    	hbox.getChildren().addAll(b1,b2,b3);
		BorderPane borderPane = new BorderPane();
		borderPane.setTop(hbox);

		borderPane.setLeft(new Button("left"));
		borderPane.setCenter(new Button("center"));
		borderPane.setRight(new Button("right"));
		borderPane.setBottom(new Button("bottom"));

		Scene scene = new Scene(borderPane);
		primaryStage.setTitle("");
		primaryStage.setScene(scene);
		primaryStage.show();
	}	

}