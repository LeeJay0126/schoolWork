import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;

public class E10_DragLineFX extends Application {
	private Line line;
	
	@Override
	public void start(Stage primaryStage) {
		Pane root = new Pane();
		line = new Line(-10,-10,-10,-10);// create a dummy line
		root.getChildren().add(line);
		
		root.setOnMousePressed(new MousePressEventHandler());
		root.setOnMouseDragged(new MouseDragEventHandler());
		
		Scene scene = new Scene(root, 300, 400);
		primaryStage.setTitle("Lines");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	private class MousePressEventHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			line.setStartX(e.getX());
			line.setEndX(e.getX());
			line.setStartY(e.getY());
			line.setEndY(e.getY());
		}
	}	
	
	private class MouseDragEventHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			line.setEndX(e.getX());
			line.setEndY(e.getY());
		}
	}	

	public static void main(String[] args) {
		Application.launch(args);
	}
}

