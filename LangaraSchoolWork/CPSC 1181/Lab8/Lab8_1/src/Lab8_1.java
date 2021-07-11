import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.transform.Scale;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;

public class Lab8_1 extends Application {

    private Circle circle;
    private double circleX;
    private double circleY;
    private Pane root;
    private Line line;

    @Override
    public void start(Stage primaryStage) {
        root = new Pane();

        root.setOnMousePressed(new MousePressEventHandler());
        root.setOnMouseMoved(new MouseMoveEventHandler());
        root.setOnMousePressed(new MousePressEventHandler2());

        Scene scene = new Scene(root, 300, 400);
        primaryStage.setTitle("Lines");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private class MouseMoveEventHandler implements EventHandler<MouseEvent> {

        @Override
        public void handle(MouseEvent e) {
            line.setEndX(e.getX());
            line.setEndY(e.getY());

            double radius = Math.sqrt(Math.pow(Math.abs(circleX - e.getX()),2) + Math.pow(Math.abs(circleY - e.getY()),2));
            circle.setRadius(radius);

        }
    }

    private class MousePressEventHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {

            Circle circle = new Circle(e.getX(),e.getY(),0);
            circle.setFill(Color.TRANSPARENT);
            circle.setStroke(Color.RED);

            line = new Line();
            line.setStartX(e.getX());
            line.setEndX(e.getX());
            line.setStartY(e.getY());
            line.setEndY(e.getY());
            line.setStroke(Color.RED);

            root.getChildren().add(circle);
            root.getChildren().add(line);
        }
    }

    private class MousePressEventHandler2 implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {

            circle.setStroke(Color.BLUE);
            line.setStroke(Color.TRANSPARENT);

        }
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}
