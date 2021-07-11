
import javafx.application.Application;
import javafx.animation.AnimationTimer;

import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;
import java.util.ArrayList;
import java.util.Random;
import javafx.collections.ObservableList;
public class DisplayCircle extends Application {
	private Pane root;
	//private CircleAnimateFX c;
	private ArrayList<CircleAnimateFX> circles;
	private Random rand;
	@Override
	public void start(Stage primaryStage) {
		root = new Pane();
		circles = new ArrayList<CircleAnimateFX>();
		rand = new Random();
		
		for(int i=1; i<=200; i++){
			addCircle();

		}
		
		CircleAnimation animation = new CircleAnimation();
		animation.start();
	
		Scene scene = new Scene(root, 500, 500);
		primaryStage.setTitle("Move Circle");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	private void addCircle(){
		CircleAnimateFX c = new CircleAnimateFX(200+rand.nextInt(30),200+rand.nextInt(30),+rand.nextInt(50));
		root.getChildren().addAll(c.getAllNodes());
		c.setFill(Color.TRANSPARENT);
		//c.setStroke(Color.RED);
		circles.add(c);

	}

	private class CircleAnimation extends AnimationTimer {
		private double pix=0.6;
		private int count=0;

		@Override
		public void handle(long arg0) {
			count++;
			if(count%3==0){
				count=0;
			}else
				return;
			int g=30;
			for(CircleAnimateFX c: circles){
				c.changeRadius(pix);
				c.setStroke(Color.rgb(250, g++, 50));
			}
			addCircle();
			CircleAnimateFX tmp = circles.get(0);
			circles.remove(0);
			ObservableList<Node> list = root.getChildren();
			int index = list.indexOf(tmp.getAllNodes()[0]);
			list.remove(index);
			//System.out.println(index);

			
		}
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}


