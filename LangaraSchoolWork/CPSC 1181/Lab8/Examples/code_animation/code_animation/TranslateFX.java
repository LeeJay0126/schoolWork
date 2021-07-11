import javafx.animation.TranslateTransition;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.layout.Pane;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import javafx.util.Duration;
 
public class TranslateFX extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
      
        Rectangle rect = new Rectangle(100,100,50,50);   
        rect.setFill(Color.BLUE);  

        TranslateTransition translate = new TranslateTransition();
        translate.setDuration(Duration.millis(1500)); 
  
        translate.setByX(300);
        translate.setByY(100);
        translate.setCycleCount(4);   
     //   translate.setAutoReverse(true);

        Group group = new Group(rect);

        translate.setNode(group); 
     
        Scene scene = new Scene(group, 600, 600);

        translate.play();
    
        primaryStage.setScene(scene);
        primaryStage.show();

    }
    public static void main(String[] args) {
        Application.launch(args);
    }
}