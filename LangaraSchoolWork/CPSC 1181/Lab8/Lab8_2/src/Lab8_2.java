import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.layout.GridPane;
import javafx.geometry.Pos;
import javafx.geometry.Insets;

import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;

import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

import java.util.Random;


public class Lab8_2 extends Application {
    private Text label1 = new Text("");

    private TextField numOfRotate;
    private TextField numOfCircles;
    private TextField duration;

    private Pane display;

    private final int WIDTH=800;
    private final int HEIGHT=600;


    @Override
    public void start(Stage primaryStage) {

        display = new Pane();
        display.setPrefWidth(WIDTH);
        display.setPrefHeight(HEIGHT);
        Rectangle clip = new Rectangle(0,0,WIDTH,HEIGHT);
        display.setClip(clip);

        VBox leftMenu = createLeftMenu();

        BorderPane root = new BorderPane();

        root.setCenter(display);
        root.setLeft(leftMenu);

        Scene scene = new Scene(root);
        primaryStage.setTitle("CPSC1181 Lab8B");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private VBox createLeftMenu(){

        numOfCircles = new TextField("10");
        numOfCircles.setPrefColumnCount(2);
        duration = new TextField("500");
        duration.setPrefColumnCount(3);

        GridPane gridPane= new GridPane();

        gridPane.add(new Text("Number of Circles: "),0,1);
        gridPane.add(numOfCircles,1,1);

        gridPane.add(new Text("Duration(ms) : "),0,2);
        gridPane.add(duration,1,2);
        gridPane.setPadding(new Insets(25,25,5,10));
        gridPane.setHgap(10);
        gridPane.setVgap(10);

        Button start = new Button("   Start    ");

        VBox leftMenu = new VBox(30,gridPane,start);
        leftMenu.setAlignment(Pos.TOP_CENTER);
        return leftMenu;

    }

    private class startButton implements EventHandler<ActionEvent>{

        @Override
        public void handle(ActionEvent event) {

            int circleValue = Integer.parseInt(numOfCircles.getText());
            int durationValue = Integer.parseInt(duration.getText());

            Random random = new Random();

            for(int i = 0; i < circleValue; i++){
                Circle temp = new Circle(random.nextInt(800),random.nextInt(600),random.nextInt(80));
                temp.setFill(Color.rgb(random.nextInt(256),random.nextInt(256),random.nextInt(256)));
            }

        }
    }


    public static void main(String[] args) {
        Application.launch(args);
    }
}
