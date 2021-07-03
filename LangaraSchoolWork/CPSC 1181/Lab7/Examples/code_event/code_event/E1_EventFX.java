import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class E1_EventFX extends Application {
	private Button button;
	

	@Override
	public void start(Stage primaryStage) {
		button = new Button("click me");
		button.setLayoutX(50);
		button.setLayoutY(60);

		Pane root = new Pane();
		root.getChildren().addAll(button);

		
		ClickListener listener = new ClickListener();
		
		//button.setOnAction(listener);
			
		
		Scene scene = new Scene(root, 250, 150);

		primaryStage.setTitle("First FX Listener");
		primaryStage.setScene(scene);
		primaryStage.show();
		
	}
	
	private class ClickListener implements EventHandler<ActionEvent> {

		@Override
		public void handle(ActionEvent e) {
			System.out.println("Just clicked!");
		}
		
	}
	
	public static void main(String[] args) {
		launch(args);
	}	
	
}
