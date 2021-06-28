import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;

public class E13_BoatFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		Pane root = new Pane();
		
		Line mast = new Line(200, 50, 200, 200);
		mast.setStrokeWidth(5);
		mast.setStroke(Color.BROWN);
			
		double[] sailPoints = {205,55 , 205,195 , 275,195};
		Polygon sail = new Polygon(sailPoints);
		sail.setFill(Color.BISQUE);
		
		Arc hull = new Arc(200,200,100,50,180,180);
	    hull.setFill(Color.BROWN);
		
		root.getChildren().addAll(mast, sail, hull);
		
		Scene scene = new Scene(root, 400, 300);
		primaryStage.setTitle("FX More Shapes");
		primaryStage.setScene(scene);
		primaryStage.show();
	}	

	public static void main(String[] args) {
		Application.launch(args);
	}

}