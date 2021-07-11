import javafx.animation.ParallelTransition;
import javafx.animation.SequentialTransition;
import javafx.animation.RotateTransition;
import javafx.animation.ScaleTransition;
import javafx.animation.TranslateTransition;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import javafx.util.Duration;


public class SequentialFX extends Application {

    @Override
    public void start(Stage stage) {

        Rectangle rect = new Rectangle(100,100,50,50);   
        rect.setFill(Color.BLUE);  
        RotateTransition rotate = new RotateTransition();
        rotate.setDuration(Duration.millis(2000)); 
        rotate.setByAngle(270);
        rotate.setCycleCount(4);   
        rotate.setAutoReverse(true);
        rotate.setNode(rect); 

        TranslateTransition translate = new TranslateTransition();
        translate.setDuration(Duration.millis(1500)); 
        translate.setByX(300);
        translate.setByY(100);
        translate.setCycleCount(4);   
        translate.setAutoReverse(true);
        translate.setNode(rect); 

        ScaleTransition scale= new ScaleTransition();
        scale.setDuration(Duration.millis(3000)); 
        scale.setByX(3);
        scale.setByY(1.5);
        scale.setCycleCount(4);   
        scale.setAutoReverse(true);
        scale.setNode(rect); 



        SequentialTransition seq = new SequentialTransition();
        seq.getChildren().addAll(rotate, translate, scale);
        seq.play();
       
        Group group = new Group(rect);
        Scene scene = new Scene(group, 600, 600);

        stage.setTitle("SequentialTransition");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}