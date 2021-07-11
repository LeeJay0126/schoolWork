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
    @Override
    public void start(Stage primaryStage) {
        Pane root = new Pane();
        circle = new Circle(-10,-10,1);// create a dummy line
        root.getChildren().add(circle);

        root.setOnMousePressed(new MousePressEventHandler());
        root.setOnMousePressed(new MousePressEventHandler2());

        Scene scene = new Scene(root, 300, 400);
        primaryStage.setTitle("Lines");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private class MousePressEventHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {
            Circle temp = new Circle(e.getX(),e.getY(),0);
            Scale scale = new Scale();
            scale
            double radius = Math.sqrt(Math.pow(Math.abs(circleX - e.getX()),2) + Math.pow(Math.abs(circleY - e.getY()),2));
            circle.setRadius(radius);
        }
    }

    private class MousePressEventHandler2 implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {
            double radius = Math.sqrt(Math.pow(Math.abs(circleX - e.getX()),2) + Math.pow(Math.abs(circleY - e.getY()),2));
            circle.setRadius(radius);
        }
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}
