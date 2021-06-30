package sample;

import javafx.application.Application;
import javafx.geometry.Bounds;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Shape;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

import java.time.LocalDateTime;


public class Clock extends Application {
    /**
     * private variables
     *     private Pane root
     *     private LocalDateTime now = LocalDateTime.now()
     *     private int hours = now.getHour()%12
     *     private int minute = now.getMinute()
     *     private int seconds = now.getSecond()
     *     private final int clockCenterX = 250
     *     private final int clockCenterY = 250
     *     private final int clockRadius = 225
     *     private final int clockStrokeWidth = 5
     *     private int secondsHandLength = 200
     *     private int minuteHandLength = 180
     *     private int hourHandLength = 160
     */
    private Pane root;
    private LocalDateTime now = LocalDateTime.now();
    private int hours = now.getHour()%12;
    private int minute = now.getMinute();
    private int seconds = now.getSecond();
    private final int clockCenterX = 250;
    private final int clockCenterY = 250;
    private final int clockRadius = 225;
    private final int clockStrokeWidth = 5;
    private int secondsHandLength = 200;
    private int minuteHandLength = 180;
    private int hourHandLength = 160;

    /**
     * start method
     * Initializes pane, scene, and shows the stage
     * calls ClockHand(), ClockFrame(), ClockText() methods
     * @param primaryStage
     * @throws Exception
     */
    @Override
    public void start(Stage primaryStage) throws Exception{
        root = new Pane();
        ClockHand hands = new ClockHand();
        ClockFrame clock = new ClockFrame();
        ClockText text = new ClockText();
        Scene scene = new Scene(root,500,500);
        primaryStage.setTitle("Lab6");
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    /**
     * main method
     * @param args
     */
    public static void main(String[] args) {
        launch(args);
    }

    /**
     * Creates clock hands according to the current time.
     * private class ClockHand
     */
    private class ClockHand {
        /**
         * Method ClockHand()
         * Gets angle of the hands from current time given with LocalDateTime library
         * generate and adds clock hands to the root
         */
        public ClockHand(){
            double angleSeconds = (seconds - 15)*2*Math.PI/60;
            double secondsX2 = clockCenterX + secondsHandLength * Math.cos(angleSeconds);
            double secondsY2 = clockCenterY + secondsHandLength * Math.sin(angleSeconds);

            double angleMinutes = (minute - 15)*2*Math.PI/60;
            double minutesX = clockCenterX + minuteHandLength * Math.cos(angleMinutes);
            double minutesY = clockCenterY + minuteHandLength * Math.sin(angleMinutes);
            //Had to cast hours and minutes to double
            double angleHours = (((double)hours + (double)(minute)/60) - 3)*2*Math.PI/12;
            System.out.println((double)hours + (double)minute/60);
            double hourX = clockCenterX + hourHandLength * Math.cos(angleHours);
            double hourY = clockCenterY + hourHandLength * Math.sin(angleHours);

            Line Sec = new Line(clockCenterX,clockCenterY,secondsX2,secondsY2);
            Line Min = new Line(clockCenterX,clockCenterY,minutesX,minutesY);
            Line Hr = new Line(clockCenterX,clockCenterY,hourX,hourY);

            Sec.setStrokeWidth(2);
            Sec.setStroke(Color.DARKRED);

            Min.setStrokeWidth(4);
            Min.setStroke(Color.BLACK);

            Hr.setStrokeWidth(6);
            Hr.setStroke(Color.BLACK);

            root.getChildren().addAll(Sec,Min,Hr);


        }
    }

    /**
     * private class ClockText
     * Class for text used for the clock
     */
    private class ClockText{
        /**
         * method ClockText()
         * gets the width of the text (or text box),
         * and use it as a parameter (text x-width/2, y, "text")
         * generates and adds text to the root
         */
        public ClockText(){

            Font font = Font.font("Arial", 18);
            Text temp = new Text("CPSC1181");
            temp.setFont(font);

            Bounds bound = temp.getBoundsInLocal();
            Rectangle box = new Rectangle(bound.getMinX(),bound.getMinY(),bound.getWidth(),bound.getHeight());
            Shape intersection = Shape.intersect(temp,box);

            Bounds boundingBox = intersection.getBoundsInLocal();
            double width = boundingBox.getWidth();

            Text result = new Text(clockCenterX-width/2,100,"CPSC1181");
            result.setFont(font);
            result.setFill(Color.BROWN);

            root.getChildren().add(result);

        }
    }

    /**
     * private class ClockFrame
     * Generates frame of the clock and lines/circle within the circle frame
     */
    private class ClockFrame {
        /**
         * Generate frame of the clock with clockCenter X, Y, and radius
         * generate circles and lines with a for loop using following formula:
         * angle = (current second - 15) * 2 * Math.PI/60
         * current second - 15 because 0 degrees is at 15seconds mark or 3 on the clock
         * for the line:
         * x = startpoint + line length * cos(angle)
         * y = startpoint + line Length * sin(angle)
         *
         * per one line, you will need 2 sets of x and ys
         *
         * also sets width and color of all the elements included in the clock frame
         * and adds to the root
         */
        public ClockFrame() {
            Circle clockFrame = new Circle();
            clockFrame.setCenterX(clockCenterX);
            clockFrame.setCenterY(clockCenterY);
            clockFrame.setRadius(clockRadius);
            clockFrame.setFill(Color.TRANSPARENT);
            clockFrame.setStrokeWidth(clockStrokeWidth);
            clockFrame.setStroke(Color.LIGHTGRAY);

            int second = 0;
            double angle;
            double pointX1;
            double pointX2;
            double pointY1;
            double pointY2;

            for(int i = 0; i < 60; i++){
                angle = (second - 15) * 2 * Math.PI/60;
                if(i % 5 == 0){
                    pointX1 = clockCenterX + 190 * Math.cos(angle);
                    pointX2 = pointX1 + (20*Math.cos(angle));
                    pointY1 = clockCenterY + 190 * Math.sin(angle);
                    pointY2 = pointY1 + 20 * Math.sin(angle);

                    Line temp = new Line(pointX1,pointY1,pointX2,pointY2);
                    if(i == 0 || i == 15 || i == 30 || i == 45) {
                        temp.setStroke(Color.FIREBRICK);
                        temp.setStrokeWidth(5);
                    }else{
                        temp.setStroke(Color.ROSYBROWN);
                        temp.setStrokeWidth(2);
                    }
                    root.getChildren().add(temp);

                }
                else{
                    pointX1 = clockCenterX + 210 * Math.cos(angle);
                    pointY1 = clockCenterY + 210 * Math.sin(angle);
                    Circle tempCir = new Circle();
                    tempCir.setCenterX(pointX1);
                    tempCir.setCenterY(pointY1);
                    tempCir.setRadius(2);
                    tempCir.setFill(Color.BLACK);

                    root.getChildren().add(tempCir);

                }
                second += 1;
            }

            Circle middleCircle = new Circle();
            middleCircle.setRadius(3.5);
            middleCircle.setCenterX(clockCenterX);
            middleCircle.setCenterY(clockCenterY);
            middleCircle.setFill(Color.DARKRED);


            root.getChildren().add(middleCircle);
            root.getChildren().add(clockFrame);
        }
    }
}


