import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.text.FontWeight;


public class E7_FontFX extends Application {
	
	@Override
	public void start(Stage primaryStage) {

		Pane root = new Pane();
		
		Text t1 = new Text(25, 75, "Filled");
		t1.setFont(Font.font(48));
		t1.setFill(Color.STEELBLUE);
		
		Text t2 = new Text(25, 175, "Bold Outline");
		Font font = Font.font("Times New Roman", FontWeight.BOLD ,48);
		t2.setFont(font);
		t2.setFill(Color.TRANSPARENT);
		t2.setStroke(Color.BLACK);
		
		root.getChildren().addAll(t1, t2);
		
		Scene scene = new Scene(root, 400, 200);
		primaryStage.setTitle("FX Text");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}