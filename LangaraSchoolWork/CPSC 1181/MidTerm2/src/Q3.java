
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.util.ArrayList;

//--------------------------------
// Remove all nodes from drawPane 
// drawPane.getChildren().clear();
//--------------------------------

public class Q3 extends Application {

    private int height=500;
    private int width=500;
    private ArrayList<Point> points;
    private BorderPane root;
    private Pane drawPane;

    @Override
    public void start(Stage stage) {
        points = new ArrayList<Point> ();
        root = new BorderPane();
        drawPane = new Pane();
        drawPane.setPrefWidth(width);
        drawPane.setPrefHeight(height);
        root.setCenter(drawPane);
        createLMenu();

        root.setOnMouseClicked(new MouseClickEventHandler());

        Scene scene = new Scene(root);
        stage.setTitle("Q3");
        stage.setScene(scene);
        stage.show();
    }

    private void createLMenu(){
        Button button = new Button("Remove");
        VBox leftBox = new VBox(20);
        leftBox.setMargin(button, new Insets(20,20,10,20));
        removeButton buttonEvent = new removeButton();
        button.setOnAction(buttonEvent);
        leftBox.getChildren().add(button);
        root.setLeft(leftBox);
    }

    private class removeButton implements EventHandler<ActionEvent>{

        @Override
        public void handle(ActionEvent event) {
            points.remove(points.size()-1);
            drawPane.getChildren().clear();
            for(int i = 0; i < points.size();i++){
                Line line = new Line();
                line.setStartX(width/2);
                line.setStartY(height/2);
                line.setEndX(points.get(i).getX());
                line.setEndY(points.get(i).getY());
                drawPane.getChildren().add(line);
            }
        }
    }

    private class MouseClickEventHandler implements EventHandler<MouseEvent>{

        @Override
        public void handle(MouseEvent event) {
            Point point = new Point(event.getX(),event.getY());
            points.add(point);
            Line line = new Line();
            line.setStartX(width/2);
            line.setStartY(height/2);
            line.setEndX(point.getX());
            line.setEndY(point.getY());
            drawPane.getChildren().add(line);
        }
    }



    public static void main(String[] args) {
        Application.launch(args);
    }
}


class Point{
    private double x;
    private double y;
    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    public String toString(){
        return "[x= "+ x + ", y= "+ y +"]";
    }
}