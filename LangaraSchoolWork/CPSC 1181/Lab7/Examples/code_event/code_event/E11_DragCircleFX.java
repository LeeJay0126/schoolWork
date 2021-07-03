 import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.Cursor;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;

public class E11_DragCircleFX extends Application {
	private Pane root;
	private Scene scene;
	private Ellipse selected=null;
	@Override
	public void start(Stage primaryStage) {
		root = new Pane();

		root.setOnMouseClicked(new ClickEventHandler());
		
		scene = new Scene(root, 400, 300);
		primaryStage.setTitle("Click & Drag");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	private class ClickEventHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			Ellipse newCircle = new Ellipse(e.getX(),e.getY(),10,10);
			newCircle.setOnMouseDragged(new Dragged());
			newCircle.setOnMousePressed(new Pressed());
			newCircle.setOnMouseClicked(new Clicked());
			newCircle.setOnMouseEntered(new MouseEntered());
			newCircle.setOnMouseExited(new MouseExited());

			root.getChildren().add(newCircle);
		}
	}	

	
	
	private class Pressed implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			if(e.getSource() instanceof Ellipse){
				selected = (Ellipse)e.getSource();
				
				// You do not need the next line here
				// Just added to show that an item can request focus
         		selected.requestFocus();
         		
			}
			
		}

	}
	private class Dragged implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
				selected.setCenterX(e.getX());
				selected.setCenterY(e.getY());
			
		}
	}

	private class Clicked implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			// we need this to stop passing the click event to parent node
			e.consume(); 
		}
	}

	private class MouseEntered implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			scene.setCursor(Cursor.CROSSHAIR);
			
		}
	}	

	private class MouseExited implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent e) {
			scene.setCursor(Cursor.DEFAULT);
			
		}
	}	

	public static void main(String[] args) {
		Application.launch(args);
	}
}


