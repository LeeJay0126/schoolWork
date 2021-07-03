
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;
public class E13_MoveCircleFX extends Application {
	private Pane root;
	private Ellipse circle;
	@Override
	public void start(Stage primaryStage) {
		root = new Pane();
		
		
		
	
		circle = new Ellipse(150,200,40,40);
		circle.setFill(Color.BLACK);
		
		root.getChildren().add(circle);
	
		Scene scene = new Scene(root, 500, 500);
		primaryStage.setTitle("Move Circle");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	
	
	

	public static void main(String[] args) {
		Application.launch(args);
	}
}
































/*
 * 		
 		Tree t1 = new Tree(50, 320, 60, 150);
		root.getChildren().addAll(t1.getAllNodes());

		Tree t2 = new Tree(150, 310, 40, 100);
		root.getChildren().addAll(t2.getAllNodes());
 */

/*
public Tree(int x, int y, int w, int h) {
	trunk = new Rectangle(x-w/6, y-2*h/3, w/3, 2*h/3);
	trunk.setFill(Color.SADDLEBROWN);
	
	leaves = new Ellipse(x,y-2*h/3,w/2,h/3);
	leaves.setFill(Color.rgb(30,120,80));
}
*/


