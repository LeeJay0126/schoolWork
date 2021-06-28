import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

public class E10_LineFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		Pane root = new Pane();

		Line mast = new Line(200, 50, 200, 200);
		mast.setStrokeWidth(5);
		mast.setStroke(Color.BROWN);

		root.getChildren().addAll(mast);
		
		Scene scene = new Scene(root, 400, 300);
		primaryStage.setTitle("FX More Shapes");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
	}	

}