import javafx.animation.ScaleTransition;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import javafx.util.Duration;
 
public class ScaleFX extends Application {
 
  @Override
  public void start(Stage primaryStage) throws Exception {
    Rectangle rect = new Rectangle(100,100,50,50);    
    rect.setFill(Color.BLUE);  
 
    ScaleTransition scale= new ScaleTransition();
    scale.setDuration(Duration.millis(3000)); 
    
    //Set how much X should enlarge
    scale.setByX(3);
    //Set how much Y should
    scale.setByY(1.5);
 
    scale.setCycleCount(4);   
    scale.setAutoReverse(true);

    Group group = new Group(rect);
    scale.setNode(group); 
    
 
    Scene scene = new Scene(group, 600, 600);

    scale.play();

    primaryStage.setScene(scene);
    primaryStage.show();
  }
 
  public static void main(String[] args) {
    Application.launch(args);
  }
}