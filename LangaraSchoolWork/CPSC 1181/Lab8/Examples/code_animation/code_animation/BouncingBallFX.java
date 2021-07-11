import java.util.Random;

import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;

public class BouncingBallFX extends Application {
	private BallAnimation animation;
	private Ellipse ball;
	private double xVelocity = 3;
	private double yVelocity = 5;

	
	@Override
	public void start(Stage primaryStage) {
		Pane root = new Pane();
		
		Rectangle background = new Rectangle(0, 0, 500, 500);
		background.setFill(Color.BLACK);
	
		ball = new Ellipse(250,250,50,50);
		ball.setFill(Color.WHITE);
		
		animation = new BallAnimation();
		animation.start();
		
		root.getChildren().addAll(background, ball);
		Scene scene = new Scene(root, 500, 500);
		primaryStage.setTitle("FX Bouncing Ball");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	private class BallAnimation extends AnimationTimer {
		
		private int countDownColorChange = 120; 
		@Override
		public void handle(long arg0) {

			double x = ball.getCenterX();
			double y = ball.getCenterY();

			
			if (x + xVelocity > 450 || x + xVelocity < 50) {
				xVelocity *= -1;
			} 
			
			if (y + yVelocity > 450 || y + yVelocity < 50) {
				yVelocity *= -1;
			} 
			
			x += xVelocity;
			y += yVelocity;
			
			ball.setCenterX(x);
			ball.setCenterY(y);
			
			countDownColorChange--;
			if (countDownColorChange ==0) {
			 	ball.setFill(randomColor());
			 	countDownColorChange=120;
			}
			
		}
	}

	private Color randomColor() {
		Random r = new Random();
		return Color.rgb(r.nextInt(256), r.nextInt(256), r.nextInt(256));
	}
	
	public static void main(String[] args) {
		Application.launch(args);
	}
}
