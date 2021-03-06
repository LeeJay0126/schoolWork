import javafx.animation.ScaleTransition;
import javafx.animation.SequentialTransition;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.shape.Circle;
import javafx.scene.transform.Scale;
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

import javafx.util.Duration;
import java.util.Random;


public class Lab8_2 extends Application {
    private Text label1 = new Text("");

    private TextField numOfCircles;
    private TextField duration;

    private Pane display;

    private final int WIDTH=800;
    private final int HEIGHT=600;
    private Random random = new Random();

    /**
     * start method (works as main method in regular java)
     * @param primaryStage
     */
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

    /**
     * Creates a Vbox for the left side of the pane
     * connect start button to startbutton event handler
     * set padding allignment for the vbox
     * @return VBox leftMenu
     */
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

        startButton startB = new startButton();
        start.setOnAction(startB);

        VBox leftMenu = new VBox(30,gridPane,start);
        leftMenu.setAlignment(Pos.TOP_CENTER);
        return leftMenu;

    }

    /**
     * method randomColor()
     * returns random color (rbg)
     * @return Color
     */
    private Color randomColor(){
        return Color.rgb(random.nextInt(256),random.nextInt(256),random.nextInt(256));
    }

    /**
     * method createCircle
     * returns a circle with random x and y value
     * radius is set to a random integer
     * @return Circle
     */
    private Circle createCircle(){
        int radius = random.nextInt(60) +30;
        return new Circle(random.nextInt(WIDTH-100)+100,random.nextInt(HEIGHT-100)+100,radius);
    }

    /**
     * method startButton implementing EventHandler
     * gets values from text box, parse them into integer
     * using the values, determing how long the cycle of SequentialTransition will last
     * and also the number of random circles that will be generated
     */
    private class startButton implements EventHandler<ActionEvent>{

        @Override
        public void handle(ActionEvent event) {

            int circleValue = Integer.parseInt(numOfCircles.getText());
            int durationValue = Integer.parseInt(duration.getText());

            Circle circleArray[] = new Circle[circleValue];
            ScaleTransition scaleTr = new ScaleTransition();
            SequentialTransition sequence = new SequentialTransition();

            for(int i = 0; i < circleValue; i++){
                Color tempColor = randomColor();
                Circle temp = createCircle();
                temp.setFill(tempColor);
                circleArray[i] = temp;
                display.getChildren().add(temp);

                scaleTr= new ScaleTransition(Duration.millis(durationValue),temp);
                scaleTr.setFromX(1);
                scaleTr.setFromY(1);
                scaleTr.setToX(0.001);
                scaleTr.setToY(0.001);
                scaleTr.setCycleCount(3);
                scaleTr.setAutoReverse(true);

                sequence.getChildren().add(scaleTr);

            }

            sequence.play();



        }
    }

    /**
     * main method
     * @param args
     */
    public static void main(String[] args) {
        Application.launch(args);
    }
}
