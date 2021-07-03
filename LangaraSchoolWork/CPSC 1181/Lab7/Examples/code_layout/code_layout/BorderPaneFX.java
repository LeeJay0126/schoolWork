import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.control.Button;
import javafx.geometry.Pos;

public class BorderPaneFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		
		Button top = new Button("top");
		Button bottom = new Button("bottom");
		Button left = new Button("left");
		Button center = new Button("center");
		Button right = new Button("right");

		BorderPane borderPane = new BorderPane();
		borderPane.setTop(top);
		borderPane.setBottom(bottom);
		borderPane.setLeft(left);
		borderPane.setCenter(center);
		borderPane.setRight(right);

		BorderPane.setAlignment(top, Pos.TOP_CENTER);
		BorderPane.setAlignment(bottom, Pos.BOTTOM_RIGHT);


		Scene scene = new Scene(borderPane);
		primaryStage.setTitle("FX BorderPane");
		primaryStage.setScene(scene);
		primaryStage.show();
	}	

}