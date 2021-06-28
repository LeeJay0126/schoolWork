package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.shape.Line;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class Main extends Application {

    private Pane root;

    @Override
    public void start(Stage primaryStage) throws Exception {
        root = new Pane();
        ClockFrame clock = new ClockFrame();
        Scene scene = new Scene(root, 500, 500);
        primaryStage.setTitle("Lab6");
        primaryStage.setScene(scene);
        primaryStage.show();


    }


    public static void main(String[] args) {
        launch(args);
    }

    private class ClockFrame {

        private final int clockCenterX = 250;
        private final int clockCenterY = 250;
        private final int clockRadius = 225;
        private final int clockStrokeWidth = 5;

        public ClockFrame() {
            Circle clockFrame = new Circle();
            clockFrame.setCenterX(clockCenterX);
            clockFrame.setCenterY(clockCenterY);
            clockFrame.setRadius(clockRadius);
            clockFrame.setFill(Color.TRANSPARENT);
            clockFrame.setStrokeWidth(clockStrokeWidth);
            clockFrame.setStroke(Color.LIGHTGRAY);

            Line Twelve = new Line(250,40,250,60);
            Line Three = new Line(460,250, 440, 250);
            Line Six = new Line(250, 460,250,440);
            Line Nine = new Line(40,250,60,250);



            root.getChildren().addAll(clockFrame, Twelve, Three, Six, Nine);
        }
    }
}



