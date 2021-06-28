import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;

public class E4_RectanglesFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		Pane root = new Pane();
		
		Rectangle ground = new Rectangle(0, 300, 300, 100);
		ground.setFill(Color.DARKGREEN);
		Rectangle trunk = new Rectangle(140, 220, 20, 100);
		trunk.setFill(Color.SADDLEBROWN);
		
		root.getChildren().addAll(trunk, ground);
		
		Scene scene = new Scene(root, 300, 400);
		primaryStage.setTitle("FX Rectangles");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	

	public static void main(String[] args) {
		Application.launch(args);
	}
}