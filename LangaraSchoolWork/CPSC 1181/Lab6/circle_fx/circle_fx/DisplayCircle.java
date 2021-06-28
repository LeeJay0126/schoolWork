
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;
public class DisplayCircle extends Application {
	private Pane root;
	private Ellipse circle;
	@Override
	public void start(Stage primaryStage) {
		root = new Pane();
		
		CircleFX c = new CircleFX(200,200,50);
		
		
		root.getChildren().addAll(c.getAllNodes());
		c.setFill(Color.TRANSPARENT);
		c.setStroke(Color.RED);
		c.move(300,250);
	
		Scene scene = new Scene(root, 500, 500);
		primaryStage.setTitle("Move Circle");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	
	
	

	public static void main(String[] args) {
		Application.launch(args);
	}
}


