import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.text.Text;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class E3_EventMultiButtons2FX extends Application {
	private Button incButton;
	private Button decButton;
	private Text valueText;
	private int val =0;
	

	@Override
	public void start(Stage primaryStage) {

		valueText = new Text(95,20,""+val);
		incButton = new Button("Increment");
		incButton.setLayoutX(5);
		incButton.setLayoutY(60);
		decButton = new Button("Decrement");
		decButton.setLayoutX(105);
		decButton.setLayoutY(60);		


		Pane root = new Pane(valueText,incButton,decButton);

		
		IncListener inclistener = new IncListener();
		DecListener declistener = new DecListener();
		incButton.setOnAction(inclistener); 
		decButton.setOnAction(declistener);
		//------------------------------------------
		// Note that you can also create ananymous objects for listeners
		// incButton.setOnAction(new IncListener()); 
		// decButton.setOnAction(new DecListener());
		//------------------------------------------
			
		
		Scene scene = new Scene(root, 200, 100);

		primaryStage.setScene(scene);
		primaryStage.show();
		
	}
	
	private class IncListener implements EventHandler<ActionEvent> {
		@Override
		public void handle(ActionEvent e) {
			valueText.setText(++val+"");
		}
	}
	private class DecListener implements EventHandler<ActionEvent> {
		@Override
		public void handle(ActionEvent e) {
			valueText.setText(--val+"");
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}	
	
}
