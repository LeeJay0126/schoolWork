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
    boolean flag = false;

    /**
     * start method (somewhat like a main method in regular java)
     * implements main event handler
     * sets scene and shows scene
     * @param primaryStage
     */
    @Override
    public void start(Stage primaryStage) {
        root = new Pane();
        line = new Line(-10,-10,-10,-10);// create a dummy line
        root.getChildren().add(line);

        root.setOnMouseClicked(new EventHandlers());

        Scene scene = new Scene(root, 300, 400);
        primaryStage.setTitle("Lab8_1");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * main event handler method
     * Creates Circle circle on click
     *
     * One problem, setOnMousePressed which is my second onclick function works, but at the same time it triggers mainhandler function
     * at the same time because they are both on click function and they seem to be invoked at the same time.
     * Only way to make it work like shown in the demo is to click to create the circle, move the mouse, press to save the circle and drag your mouse
     * to the location you want to create your next circle (because second onclick button is a press)
     * Tried to work around this problem but failed to do so, so if you could, please wriite how I can fix this problem in the grading section
     *
     * Upon clicking anywhere on the pane, eventhandler will set mouse clicked location as x and y value of the circle/line.
     * It will create a circle with that x and y value with radius of 0
     * private Circle variable selected will be the Circle circle (new circle made), giving other event handlers access to the circle.
     * calls setOnMousePressed/ setOnMouseMoved event handlers
     *
     */
    private class EventHandlers implements EventHandler<MouseEvent>{

        @Override
        public void handle(MouseEvent e) {

            if(flag == false){
                flag = true;

                Circle circle = new Circle(e.getX(),e.getY(),0);
                selected = circle;
                selected.requestFocus();
                circle.setFill(Color.TRANSPARENT);


                line.setStartX(e.getX());
                line.setEndX(e.getX());
                line.setStartY(e.getY());
                line.setEndY(e.getY());

                root.setOnMouseMoved(new MouseMoveEventHandler());
                root.setOnMousePressed(new MouseClickEventHandler());

                root.getChildren().add(selected);
            }else {
                flag = false;
            }

        }
    }


    /**
     * Second onclick method.
     * Will set line stroke to transparent and set rim/ stroke color of the circle to blue up on pressing the mouse (without releasing)
     */
    private class MouseClickEventHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {

            line.setStroke(Color.TRANSPARENT);
            selected.setStroke(Color.BLUE);

            e.consume();
        }
    }

    /**
     * Event handler for mouse movement
     * sets line end x and end y to current mouse cursor.
     * sets radius relavant to the circle's original x and y value to the current mouse cursor position
     */
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
