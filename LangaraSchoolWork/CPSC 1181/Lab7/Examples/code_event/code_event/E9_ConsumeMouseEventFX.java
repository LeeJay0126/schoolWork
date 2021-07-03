import java.util.Random;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;

public class E9_ConsumeMouseEventFX extends Application {
	private Pane root;
	private Rectangle background;
	private Ellipse centerCircle;
	@Override
	public void start(Stage primaryStage) {
		root = new Pane();
		
		background = new Rectangle(0, 0, 300, 400);
		background.setFill(Color.WHITE);
		
		root.setOnMouseClicked(new BGClickEventHandler());
	
		centerCircle = new Ellipse(150,200,40,40);
		centerCircle.setFill(Color.BLACK);
		centerCircle.setOnMouseClicked(new CircleClickEventHandler());	
		
		root.getChildren().addAll(background, centerCircle);
	
		Scene scene = new Scene(root, 300, 400);
		primaryStage.setTitle("Clicks for Colors");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	
	
	private class BGClickEventHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			background.setFill(randomColor());
		}
	}	
	
	private class CircleClickEventHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			centerCircle.setFill(randomColor());
			e.consume();
		}
	}

	private static Color randomColor() {
		Random r = new Random();
		return Color.rgb(r.nextInt(256), r.nextInt(256), r.nextInt(256));
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


