import javafx.animation.RotateTransition;
import javafx.application.Application;
import javafx.scene.paint.Color;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.scene.shape.Rectangle;
 
public class RotateFX extends Application {
 
  @Override
  public void start(Stage primaryStage) {
    Rectangle rect = new Rectangle(100,100,50,50);   
    rect.setFill(Color.BLUE);  

    RotateTransition rotate = new RotateTransition();
    rotate.setDuration(Duration.millis(2000)); 
  
    rotate.setByAngle(270);
    rotate.setCycleCount(4);   
   // rotate.setAutoReverse(true);

    Group group = new Group(rect);
    rotate.setNode(group); 
 
    Scene scene = new Scene(group, 600, 600);
    rotate.play();

    primaryStage.setScene(scene);
    primaryStage.show();
  }
 
  public static void main(String[] args) {
    Application.launch(args);
  }
}