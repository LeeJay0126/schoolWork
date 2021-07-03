import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.Group;

public class GroupFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		Line mast = new Line(200, 50, 200, 200);
		mast.setStrokeWidth(5);
		mast.setStroke(Color.BROWN);
			
		double[] sailPoints = {205,55 , 205,195 , 275,195};
		Polygon sail = new Polygon(sailPoints);
		sail.setFill(Color.BISQUE);
		Arc hull = new Arc(200,200,100,50,180,180);
	    hull.setFill(Color.BROWN);
	    Group boat = new Group(mast, sail, hull);
		
		Scene scene = new Scene	(boat,400,500);
		primaryStage.setTitle("FX Group");
		primaryStage.setScene(scene);
		primaryStage.show();
		
		// now We can apply to all nodes
		boat.setTranslateX(100);
		boat.setTranslateY(50);
		boat.setOpacity(0.2);
	}	

}