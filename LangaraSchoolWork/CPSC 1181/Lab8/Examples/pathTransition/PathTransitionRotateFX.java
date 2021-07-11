import javafx.animation.PathTransition;
import javafx.animation.RotateTransition;
import javafx.animation.ParallelTransition;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;

import javafx.scene.shape.CubicCurveTo;
import javafx.scene.shape.MoveTo;
import javafx.scene.shape.Path;
import javafx.scene.text.Text;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

import javafx.geometry.Bounds;
import javafx.scene.shape.Shape;

import javafx.stage.Stage;
import javafx.util.Duration;

public class PathTransitionRotateFX extends Application {

    @Override
    public void start(Stage stage) {

        initUI(stage);
    }

    private void initUI(Stage stage) {

        Pane root = new Pane();



/*
        Circle circle = new Circle(30, 120, 30);
        circle.setFill(Color.CADETBLUE);*/
        Group circle = createCircle();
        RotateTransition rotate = new RotateTransition();
        rotate.setByAngle(720);
        rotate.setDuration(Duration.seconds(6));
        rotate.setDelay(Duration.seconds(2));
        rotate.setNode(circle);


        PathTransition pathtr = new PathTransition();

        Path path = new Path();
        path.getElements().add(new MoveTo(30, 120));
        path.getElements().add(new CubicCurveTo(180, 60, 250, 340, 420, 240));


        pathtr.setDuration(Duration.seconds(6));
        pathtr.setDelay(Duration.seconds(2));
        pathtr.setPath(path);
        pathtr.setNode(circle);

        ParallelTransition par = new ParallelTransition();
        par.getChildren().addAll(pathtr,rotate);
        par.play();

       /* par.setCycleCount(2);
        par.setAutoReverse(true);
        par.play();*/

        root.getChildren().addAll(path, circle);

        Scene scene = new Scene(root, 500, 400);

        stage.setTitle("PathTransition");
        stage.setScene(scene);
        stage.show();
    }

    private Group createCircle(){
        Circle circle = new Circle(30, 120, 30);
        circle.setFill(Color.CADETBLUE);

        Font font = Font.font("Times New Roman",40);
        Text tmp= new Text("A"); // create a temporary text
        tmp.setFont(font);
        Bounds bound = tmp.getBoundsInLocal();
        Rectangle box = new Rectangle(bound.getMinX(), bound.getMinY(), bound.getWidth(),
        bound.getHeight());
        Shape intersection = Shape.intersect(tmp, box);
        Bounds boundingBox = intersection.getBoundsInLocal();
        double width = boundingBox.getWidth(); // returns width of the 
        double height = boundingBox.getHeight(); // returns height of the 
        Text text = new Text(30-width/2, 120+height/2, "A");
        text.setFont(font);
        return new Group(circle,text);


    }

    public static void main(String[] args) {
        launch(args);
    }
}