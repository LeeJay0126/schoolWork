import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.text.Text;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class E2_EventMultiButtonsFX extends Application {
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

		
		IncListener listener = new IncListener();
		// bind both buttons to a single listener
		incButton.setOnAction(listener); 
		decButton.setOnAction(listener);
			
		
		Scene scene = new Scene(root, 200, 100);

		primaryStage.setScene(scene);
		primaryStage.show();
		
	}
	
	private class IncListener implements EventHandler<ActionEvent> {

		@Override
		public void handle(ActionEvent e) {
			if(e.getSource()==incButton) // gets source of the event
				val+=1;
			else
				val-=1;
			valueText.setText(val+"");
		}
		
	}
	
	public static void main(String[] args) {
		launch(args);
	}	
	
}
