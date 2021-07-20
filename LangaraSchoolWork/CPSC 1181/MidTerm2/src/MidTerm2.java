import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Line;

public class MidTerm2 extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    private Pane display;
    private final int WIDTH = 800;
    private final int HEIGHT = 800;
    private final int PointX = 400;
    private final int PointY = 400;
    private Line[] array = new Line[100];
    private Button button;
    private int count = 0;

    @Override
    public void start(Stage primaryStage) {
        display = new Pane();
        display.setPrefWidth(WIDTH);
        display.setPrefHeight(HEIGHT);

        display.setOnMouseClicked(new clickHandler());
        removeButton();
        HBox hbox = new HBox(button,display);
        Scene scene = new Scene(hbox,1000,800);
        primaryStage.setTitle("Question 15");
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public void removeButton(){

        button = new Button("Remove");
        buttonHandler buttons = new buttonHandler();
        button.setOnAction(buttons);

    }

    private class buttonHandler implements EventHandler<ActionEvent>{

        @Override
        public void handle(ActionEvent event) {

            array[array.length-1].setStroke(Color.TRANSPARENT);
            count --;

        }
    }

    private class clickHandler implements EventHandler<MouseEvent> {


        @Override
        public void handle(MouseEvent event) {
            Line line = new Line();
                line.setEndX(event.getX());
                line.setStartX(PointX);
                line.setStartY(PointY);
                line.setEndY(event.getY());

                array[count] = line;
                count++;
                display.getChildren().add(line);


        }
    }
}
