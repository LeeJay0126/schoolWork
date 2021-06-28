import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;

public class E8_TreesFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		Pane root = new Pane();
		Rectangle ground = new Rectangle(0, 300, 300, 100);
		ground.setFill(Color.DARKGREEN);
		root.getChildren().add(ground);
	
		Tree t1 = new Tree(50, 320);
		root.getChildren().addAll(t1.getAllNodes());

		Tree t2 = new Tree(150, 335);
		root.getChildren().addAll(t2.getAllNodes());	

		Scene scene = new Scene(root, 300, 400);
		primaryStage.setTitle("FX Trees");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}

class Tree {
	private Rectangle trunk;
	private Ellipse leaves;
	private final int WTRUNK = 20;
	private final int HTRUNK = 100;
	private final int WLEAVES = 40;
	private final int HLEAVES = 60;

	
	public Tree(int x, int y) {
		trunk = new Rectangle(x-WTRUNK/2, y-HTRUNK, WTRUNK, HTRUNK);
		trunk.setFill(Color.SADDLEBROWN);
		
		leaves = new Ellipse(x,y-HTRUNK,WLEAVES,HLEAVES);
		leaves.setFill(Color.rgb(30,120,80));
		
	}
	
	public Node[] getAllNodes() {
		return new Node[] {trunk, leaves};
	}
}