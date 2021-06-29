package sample;

import javafx.application.Application;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

import java.time.LocalDateTime;


public class Main extends Application {

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

    @Override
    public void start(Stage primaryStage) throws Exception{
        root = new Pane();
        ClockHand hands = new ClockHand();
        ClockFrame clock = new ClockFrame();
        Scene scene = new Scene(root,500,500);
        primaryStage.setTitle("Lab6");
        primaryStage.setScene(scene);
        primaryStage.show();

    }


    public static void main(String[] args) {
        launch(args);
    }

    private class ClockHand {
        public ClockHand(){
            double angleSeconds = (seconds - 15)*2*Math.PI/60;
            double secondsX2 = clockCenterX + secondsHandLength * Math.cos(angleSeconds);
            double secondsY2 = clockCenterY + secondsHandLength * Math.sin(angleSeconds);

            double angleMinutes = (minute - 15)*2*Math.PI/60;
            double minutesX = clockCenterX + minuteHandLength * Math.cos(angleMinutes);
            double minutesY = clockCenterY + minuteHandLength * Math.sin(angleMinutes);

            double angleHours = (hours - 3)*2*Math.PI/12;
            double hourX = clockCenterX + hourHandLength * Math.cos(angleHours);
            double hourY = clockCenterY + hourHandLength * Math.sin(angleHours);

            Line Sec = new Line(clockCenterX,clockCenterY,secondsX2,secondsY2);
            Line Min = new Line(clockCenterX,clockCenterY,minutesX,minutesY);
            Line Hr = new Line(clockCenterX,clockCenterY,hourX,hourY);

            Sec.setStrokeWidth(2);
            Sec.setStroke(Color.DARKRED);

            Min.setStrokeWidth(4);
            Min.setStroke(Color.PALEGOLDENROD);

            Hr.setStrokeWidth(6);
            Hr.setStroke(Color.PALEGOLDENROD);

            root.getChildren().addAll(Sec,Min,Hr);


        }
    }

    private class ClockFrame {



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
                    second += 1;

                }
                else{
                    pointX1 = clockCenterX + 210 * Math.cos(angle);
                    pointY1 = clockCenterY + 210 * Math.sin(angle);
                    Circle tempCir = new Circle();
                    tempCir.setCenterX(pointX1);
                    tempCir.setCenterY(pointY1);
                    tempCir.setRadius(3);
                    tempCir.setFill(Color.BLACK);

                    root.getChildren().add(tempCir);
                    second += 1;

                }
            }

            Circle middleCircle = new Circle();
            middleCircle.setRadius(7);
            middleCircle.setCenterX(clockCenterX);
            middleCircle.setCenterY(clockCenterY);
            middleCircle.setFill(Color.DARKRED);

            root.getChildren().add(middleCircle);
            root.getChildren().add(clockFrame);
        }
    }
}


//    int length = 20;
//            double angle = 0;
//            double secondsX2 = 0;
//            double secondsY2=0;
//            int second = 0;
//
//            for(int i = 0; i < 12; i++){
////                angle = (second - 15)*2*Math.PI/60;
////                secondsX2 = clockCenterX + clockStripeLength * Math.cos(angle);
////                secondsY2 = clockCenterY + clockStripeLength * Math.sin(angle);
////                Line temp = new Line(clockCenterX, clockCenterY, secondsX2, secondsY2);
////                root.getChildren().add(temp);
////                second += 5;
//            }
