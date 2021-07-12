import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.shape.Line;


public class Lab8_1 extends Application {
    private Line line;
    private Pane root;
    private Circle selected = null;

    @Override
    public void start(Stage primaryStage) {
        root = new Pane();
        line = new Line(-10,-10,-10,-10);// create a dummy line
        root.getChildren().add(line);

        root.setOnMousePressed(new EventHandlers());

        Scene scene = new Scene(root, 300, 400);
        primaryStage.setTitle("Lab8_1");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private class EventHandlers implements EventHandler<MouseEvent>{

        @Override
        public void handle(MouseEvent e) {

            Circle circle = new Circle(e.getX(),e.getY(),0);
            selected = circle;
            selected.requestFocus();
            circle.setFill(Color.TRANSPARENT);

            line.setStartX(e.getX());
            line.setEndX(e.getX());
            line.setStartY(e.getY());
            line.setEndY(e.getY());

            root.setOnMouseDragged(new MouseMoveEventHandler());
            root.setOnMouseClicked(new MouseClickEventHandler());

            root.getChildren().add(circle);

        }
    }





    private class MouseClickEventHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {

            line.setStroke(Color.TRANSPARENT);
            selected.setStroke(Color.BLUE);
            e.consume();
        }
    }

    private class MouseMoveEventHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {
            line.setEndX(e.getX());
            line.setEndY(e.getY());

            selected.setStroke(Color.RED);
            line.setStroke(Color.RED);

            double radius = Math.sqrt(Math.pow(Math.abs(selected.getCenterX() - e.getX()),2) + Math.pow(Math.abs(selected.getCenterY()-e.getY()),2));
            selected.setRadius(radius);


        }
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}
