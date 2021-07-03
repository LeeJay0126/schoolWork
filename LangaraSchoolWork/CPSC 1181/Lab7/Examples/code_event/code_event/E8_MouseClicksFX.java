import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;
import java.util.Random;

public class E8_MouseClicksFX extends Application {
	private Pane root;
	
	@Override
	public void start(Stage primaryStage) {

		root = new Pane();

		root.setOnMouseClicked(new ClickEventHandler());
		
		Scene scene = new Scene(root, 300, 400);
		primaryStage.setTitle("Clicks for Circles");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	private class ClickEventHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			Ellipse newCircle = new Ellipse(e.getX(),e.getY(),10,10);
			root.getChildren().add(newCircle);
		}	
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


